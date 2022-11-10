#pragma once

# include <iostream>
# include <iterator>
# include <memory>
# include <vector>
# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>

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
			
			_start = _alloc.allocate( n );
			_end_capacity = _start + n;
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
    void copy_and_update_allocate() // inserte uygun yapılırsa rahatlatabilir fazla parametre göz çıkarmaz evlat
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
//şimdi sadece push_back yapıcaz ilk kontrol gerekiyor
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


// şimdi nasıl yapıcaz bir düşünelim 3 tür insert var
// bu yazacağımız copy fonksiyonu ona uygun olursa bizim için iyi olur diye düşünüyorum
// push_backin tek versiyonu olması bu dediğimin boş bir şey olduğunu gösteriyor olabilir
// ve inserti yapmak için iterator kullanmalıyız en azından iteratorı yapmalıyız gibi duruyor
// iteratorın neyini yapıcaz bilmiyorum
// bu bir problem
// kafamdaki yapı şu şekilde

// push_back için sonuna kadar kopyalayıp fazladan 1 yer vermem yeterli o son yeri push_backtede doldurabilirim

// iterator insert (iterator position, const value_type& val);
// void insert (iterator position, size_type n, const value_type& val);
// template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);
    // insertte olay biraz daha farklı
    // burada 3 tür insert görüyoruz mantıkları aynı olsada biraz farklılar
    // burada yapılması gereken şey ise şu
    // yeni gelen değer yada değerlerin boyutunu bul
        // boyutunu oluştururken elindeki değerlerin sayısı + yeni sayıların sayısı kadar yer aç
            // istenilen yere kadar kopyala 
            // yeni verilen sayıları sırasıyla kopyala
            // eskiden kaldığın yerden itibaren sonuna kadar kopyala

            //EXAMPLE    
            // 10 sayılık vectorum var insertle 3.konuma 5 sayı gelecek
                // 5sayıyı nasıl bulabiliriz 
                    // eğer tek sayı ise direk bilicem
                    // eğer dizi ise size muhtemelen verir
                    // eğer iterator ise iterator farkı bana sayıyıy verir
            // 15 sayılık yer açtım
            // ilk 3 sayımı kopyaladım
                // İKTİMALLER 3 adet
                    //TEK SAYI 1->iktimal
                        // sayıyı direk ekle
                    //BİRDEN FAZLA SAYI 2-iktimal
                        // 1) DİZİ 
                        // 2) İTERATOR aralığı
                    // yeni sayılarımı kopyaladım
            // eski 4.sayıdan itibaren 10.sayıya kadar kopyaladım
    // bu durumlara bakarak bize lazım olan fonksiyonların parametrelerini işimize yarayacak şekilde koyabiliriz diye düşünüyorum 
    // yada aynı ada sahip birden fazla fonksiyon yapabiliriz kendi türlerine itaat eden

// yeni akıl etmem üzerine farkettiğim bir şey ilk önce capacityy fonksiyonları yazmam daha mantıklı galiba :(
// deneyim herşeydir bilgi ve deneyim inanılmaz iki karkdeştir unutmucaksın %1 in gücünü dediğini hatırla
// bu %1 olayına inanmasam intihar ederdim hatta o kadarki ben buna tapıcak kadar inanıyorum

