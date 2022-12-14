#pragma once

# include <iostream>
# include <iterator>
# include <memory>
# include <vector>
# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include "random_acces_iterator.hpp"
#include "utils.hpp"
namespace ft
{

template < typename T, typename Allocator = std::allocator<T> >
class vector
{
public:
    typedef T           value_type;
    typedef Allocator   allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef typename allocator_type::size_type size_type;
    typedef typename allocator_type::difference_type difference_type;

    typedef ft::random_access_iterator<pointer, vector> iterator;
    typedef ft::random_access_iterator<const_pointer, vector> const_iterator;
    typedef ft::reverse_iterator<iterator> reverse_iterator;
    typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			
private:
	allocator_type  _alloc;
	pointer         _start;
	pointer         _end;
	pointer         _end_capacity;
public://   Capacity
    bool empty() const {return(_start - _end == 0);}
    size_type size() const{return(_end - _start);}
    size_type max_size() const{return(_alloc.max_size());}
    size_type capacity() const{return(_end_capacity - _start);}
    void reserve(size_type new_cap )
    {
        if (new_cap > this->max_size())
			throw (std::length_error("vector::reserve"));
        else if(new_cap > this->size())
        {
            pointer prev_start = _start;
			pointer prev_end = _end;
			size_type prev_size = this->size();
			size_type prev_capacity = this->capacity();
			
			_start = _alloc.allocate( new_cap );
			_end_capacity = _start + new_cap;
			_end = _start;
			while (prev_start != prev_end)
			{
				_alloc.construct(_end, *prev_start);
				_end++;
				prev_start++;
			}
			_alloc.deallocate(prev_start - prev_size, prev_capacity);
        }
    }
private: //utils

	void checkRange(const size_type& n) const
	{
		if (n >= this->size())
			throw (std::out_of_range("vector::checkRange: n (which is "
					+ ft::to_string(n) + ") >= this->size() (which is "
					+ ft::to_string(this->size()) + ")"));
	}
public://Element access
    reference at (size_type n) {
		checkRange(n);
		return ((*this)[n]);
	}
	const_reference at (size_type n) const {
		checkRange(n);
		return ((*this)[n]);
	}
    reference front () { return (*_start); }
	const_reference front () const { return (*_start); }
	reference back () { return (*(_end - 1));} 
	const_reference back () const { return (*(_end - 1)); }
    pointer data(){    return _start;}
    const_pointer data() const{    return _start;}
public: //iterator
    iterator begin(){return (_start);   }
    const_iterator begin() const {return (_start);}
    
    iterator end()
    {
    	if (this->empty())
			return (this->begin());
	    return (_end);
    }
    const_iterator end() const
    {
    	if (this->empty())
			return (this->begin());
	    return (_end);
    }
    
    reverse_iterator rbegin() {return (reverse_iterator(this->end())); }
    const_reverse_iterator rbegin() const {return (reverse_iterator(this->end())); }
    
    reverse_iterator rend() { return (reverse_iterator(this->begin())); }
    const_reverse_iterator rend() const { return (reverse_iterator(this->begin())); }

public:
        explicit vector (const allocator_type& alloc = allocator_type())
        {
            this->_alloc = alloc;
            this->_start = nullptr;
            this->_end = nullptr;
            this->_end_capacity = nullptr;
            // std::cout << "max_size="<< _alloc.max_size() << "\n";
        }
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){}
        template <class InputIterator>
        vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type()){}
        vector (const vector& x){}
        ~vector(){}
public:
    void copy_and_update_allocate() // inserte uygun yap??l??rsa rahatlatabilir fazla parametre g??z ????karmaz evlat
    {
        pointer tmp_start;
        pointer tmp_end;
        pointer tmp_end_capacity;
        size_t size = this->_end_capacity - this->_start;
        if(this->_alloc.max_size() < this->_end_capacity - this->_start)
            ;//error
        if(size == 0)
        {
            // this->_alloc
        }
        else
        {
        }
    }
//??imdi sadece push_back yap??caz ilk kontrol gerekiyor
    void push_back(value_type const &a)
    { 
        // memory leak
        _start = _alloc.allocate( 4 );
		_end_capacity = _start + 4;
		
        _end = _start;
        _alloc.construct(_end,1);
        _end++;
        
        _alloc.construct(_end,2);
        _end++;
        
        _alloc.construct(_end,3);
        _end++;
        
        _alloc.construct(_end,4);
        _end++;
        // std::cout << *(_start + 2);
    }
};


// ??imdi nas??l yap??caz bir d??????nelim 3 t??r insert var
// bu yazaca????m??z copy fonksiyonu ona uygun olursa bizim i??in iyi olur diye d??????n??yorum
// push_backin tek versiyonu olmas?? bu dedi??imin bo?? bir ??ey oldu??unu g??steriyor olabilir
// ve inserti yapmak i??in iterator kullanmal??y??z en az??ndan iterator?? yapmal??y??z gibi duruyor
// iterator??n neyini yap??caz bilmiyorum
// bu bir problem
// kafamdaki yap?? ??u ??ekilde

// push_back i??in sonuna kadar kopyalay??p fazladan 1 yer vermem yeterli o son yeri push_backtede doldurabilirim

// iterator insert (iterator position, const value_type& val);
// void insert (iterator position, size_type n, const value_type& val);
// template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);
    // insertte olay biraz daha farkl??
    // burada 3 t??r insert g??r??yoruz mant??klar?? ayn?? olsada biraz farkl??lar
    // burada yap??lmas?? gereken ??ey ise ??u
    // yeni gelen de??er yada de??erlerin boyutunu bul
        // boyutunu olu??tururken elindeki de??erlerin say??s?? + yeni say??lar??n say??s?? kadar yer a??
            // istenilen yere kadar kopyala 
            // yeni verilen say??lar?? s??ras??yla kopyala
            // eskiden kald??????n yerden itibaren sonuna kadar kopyala

            //EXAMPLE    
            // 10 say??l??k vectorum var insertle 3.konuma 5 say?? gelecek
                // 5say??y?? nas??l bulabiliriz 
                    // e??er tek say?? ise direk bilicem
                    // e??er dizi ise size muhtemelen verir
                    // e??er iterator ise iterator fark?? bana say??y??y verir
            // 15 say??l??k yer a??t??m
            // ilk 3 say??m?? kopyalad??m
                // ??KT??MALLER 3 adet
                    //TEK SAYI 1->iktimal
                        // say??y?? direk ekle
                    //B??RDEN FAZLA SAYI 2-iktimal
                        // 1) D??Z?? 
                        // 2) ??TERATOR aral??????
                    // yeni say??lar??m?? kopyalad??m
            // eski 4.say??dan itibaren 10.say??ya kadar kopyalad??m
    // bu durumlara bakarak bize laz??m olan fonksiyonlar??n parametrelerini i??imize yarayacak ??ekilde koyabiliriz diye d??????n??yorum 
    // yada ayn?? ada sahip birden fazla fonksiyon yapabiliriz kendi t??rlerine itaat eden

// yeni ak??l etmem ??zerine farketti??im bir ??ey ilk ??nce capacityy fonksiyonlar?? yazmam daha mant??kl?? galiba :(
// deneyim her??eydir bilgi ve deneyim inan??lmaz iki karkde??tir unutmucaks??n %1 in g??c??n?? dedi??ini hat??rla
// bu %1 olay??na inanmasam intihar ederdim hatta o kadarki ben buna tap??cak kadar inan??yorum

} // namespace ft
