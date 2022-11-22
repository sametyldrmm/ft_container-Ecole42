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
    // typedef typename allocator_type::difference_type difference_type;

    typedef ft::random_access_iterator<pointer, vector> iterator;
    typedef ft::random_access_iterator<const_pointer, vector> const_iterator;
    typedef ft::reverse_iterator<iterator> reverse_iterator;
    typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef typename ft::iterator_traits<iterator>::difference_type    difference_type;  
			
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
    // void clear()
	// {
	// 	size_type save_size = this->size();
	// 	for (size_type i = 0; i < save_size; i++)
	// 	{
	// 		_end--;
	// 		_alloc.destroy(_end);
	// 	}
	// }

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

public: // construct vecotr
        explicit vector (const allocator_type& alloc = allocator_type())
        :_alloc(alloc), _start(nullptr), _end(nullptr), _end_capacity(nullptr){}

        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
        : _alloc(alloc), _start(nullptr), _end(nullptr), _end_capacity(nullptr)
        {
			_start = _alloc.allocate( n );
			_end_capacity = _start + n;
			_end = _start;
			while (n--)
			{
				_alloc.construct(_end, val);
				_end++;
			}
        }
        template <class InputIterator>
        vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type(),
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
         :_alloc(alloc)
        {
            bool is_valid;
            // unutma !!!!!! error handling
            difference_type n = std::distance(first, last);
		    _start = _alloc.allocate( n );
		    _end_capacity = _start + n;
		    _end = _start;
		    while (n--)
		    {
		    	_alloc.construct(_end, *first++);
		    	_end++;
		    }
        }
        vector (const vector& x) :_alloc(x._alloc),_start(nullptr),_end(nullptr),_end_capacity(nullptr)
        {
            //insert gelicek
        }
        ~vector()
        {	
            this->clear();
			_alloc.deallocate(_start, this->capacity());
        }
public:
//şimdi sadece push_back yapıcaz ilk kontrol gerekiyor
    void push_back(value_type const &a)
    {
		if (_end == _end_capacity)
		{
			int next_capacity = (this->size() > 0) ? (int)(this->size() * 2) : 1;
			this->reserve(next_capacity);
		}
		_alloc.construct(_end, val);
		_end++;
    }

    void assign (size_type n, const value_type& val)
    {
        this->clear();
	    if (n == 0)
	    	return ;
	    if (size_type(_end_capacity - _start) >= n)
	    {
	    	while (n)
	    	{
	    		_alloc.construct(_end++ , val);
	    		n--;
	    	}
	    }
	    else
	    {
	    	_alloc.deallocate(_start, this->capacity());
	    	_start = _alloc.allocate( n );
	    	_end = _start;
	    	_end_capacity = _start + n;
	    	while (n)
	    	{
	    		_alloc.construct(_end++, val);
	    		n--;
	    	}
	    }
    }

    template <class InputIterator>  void assign (InputIterator first, InputIterator last)
    {
        this->clear();
		size_type dist = std::distance(first, last);
		if (size_type(_end_capacity - _start) >= dist)
		{
			for(; first != last; first++, _end++)
				_alloc.construct(_end, *first);
		}
		else
		{
			pointer new_start = pointer();
			pointer new_end = pointer();
			pointer new_end_capacity = pointer();
			new_start = _alloc.allocate(dist);
			new_end = new_start;
			new_end_capacity = new_start + dist;
			for(; first != last ; first++, new_end++)
				_alloc.construct(new_end, *first);
			
			_alloc.deallocate(_start, this->capacity());
			_start = new_start;
			_end = new_end;
			_end_capacity = new_end_capacity;
		}
    }

    // single element (1)	
    iterator insert (iterator position, const value_type& val)
    {
    	size_type pos_len = position - _start;
		if (size_type(_end_capacity - _end) >= this->size() + 1)
		{
			for (size_type i = 0; i < pos_len; i++)
				_alloc.construct(_end - i, *(_end - i - 1));
			_end++;
			_alloc.construct(position, val);
		}
		else
		{
			pointer new_start = pointer();
			pointer new_end = pointer();
			pointer new_end_capacity = pointer();
			int next_capacity = (this->size() * 2 > 0) ? this->size() * 2 : 1; 
			new_start = _alloc.allocate( next_capacity );
			new_end = new_start + this->size() + 1;
			new_end_capacity = new_start + next_capacity;
			for (size_type i = 0; i < pos_len; i++)
				_alloc.construct(new_start + i, *(_start + i));
			_alloc.construct(new_start + pos_len, val);
			for (size_type j = 0; j < this->size() - pos_len; j++)
				_alloc.construct(new_end - j - 1, *(_end - j - 1));
			for (size_type l = 0; l < this->size(); l++)
				_alloc.destroy(_start + l);
			if (_start)
				_alloc.deallocate(_start, this->capacity());

			_start = new_start;
			_end = new_end;
			_end_capacity = new_end_capacity;
		}
		return (iterator(_start + pos_len));
    }
    void insert (iterator position, size_type n, const value_type& val)
    {
        if (n == 0)
	    	return ;
	    if (n > this->max_size())
	    	throw (std::length_error("vector::insert (fill)"));
	    size_type pos_len = position - _start;
	    if (size_type(_end_capacity - _end) >= n)
	    {
	    	for (size_type i = 0; i < this->size() - pos_len; i++)
	    		_alloc.construct(_end - i + (n - 1), *(_end - i - 1));
	    	_end += n;
	    	while (n)
	    	{
	    		_alloc.construct(position) + (n - 1), val);
	    		n--;
	    	}
	    }
	    else
	    {
	    	pointer new_start = pointer();
	    	pointer new_end = pointer();
	    	pointer new_end_capacity = pointer();
    
	    	int next_capacity = (this->capacity() > 0) ? (int)(this->size() * 2) : 1;
	    	new_start = _alloc.allocate(next_capacity);
	    	new_end_capacity = new_start + next_capacity;
	    	if (size_type(new_end_capacity - new_start) < this->size() + n)
	    	{
	    		if (new_start)
	    			_alloc.deallocate(new_start, new_start - new_end_capacity);
	    		next_capacity = this->size() + n;
	    		new_start = _alloc.allocate(next_capacity);
	    		new_end = new_start + this->size() + n;
	    		new_end_capacity = new_start + next_capacity;
	    	}
	    	new_end = new_start + this->size() + n;
	    	for (int i = 0; i < (position) - _start); i++)
	    		_alloc.construct(new_start + i, *(_start + i));
	    	for (size_type k = 0; k < n; k++)
	    		_alloc.construct(new_start + pos_len + k, val);
	    	for (size_type j = 0; j < (this->size() - pos_len); j++)
	    		_alloc.construct(new_end - j - 1, *(_end - j - 1));
	    	for (size_type u = 0; u < this->size(); u++)
	    		_alloc.destroy(_start + u);
	    	_alloc.deallocate(_start, this->capacity());
	    	_start = new_start;
	    	_end = new_end;
	    	_end_capacity = new_end_capacity;
	    }
    }


    template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last)
    {
				size_type dist = std::distance(first, last);
				if (size_type(_end_capacity - _end) >= dist)
				{
					for(size_type i = 0; i < this->size() - (position - _start); i++)
						_alloc.construct(_end - i + (dist - 1), *(_end - i - 1));
					_end += dist;
					for (; first != last); first++, position++)
						_alloc.construct(position, *first);
				}
				else
				{
					pointer new_start = pointer();
					pointer new_end = pointer();
					pointer new_end_capacity = pointer();

					new_start = _alloc.allocate( this->size() * 2 );
					new_end = new_start + this->size() + dist;
					new_end_capacity = new_start + ( this->size() * 2 );

					if (size_type(new_end_capacity - new_start) < this->size() + dist)
					{
						if (new_start)
							_alloc.deallocate(new_start, new_end_capacity - new_start);
						new_start = _alloc.allocate (this->size() + dist);
						new_end = new_start + this->size() + dist;
						new_end_capacity = new_end;
					}

					for (int i = 0; i < position - _start; i++)
						_alloc.construct(new_start + i, *(_start + i));
					for (int j = 0; first != last; first++, j++)
						_alloc.construct(new_start + (position - _start) + j, *first);
					for (size_type k = 0; k < this->size() - (position - _start); k++)
                        _alloc.construct(new_start + (*(&position) - _start) + dist + k, *(position + k));

					for (size_type l = 0; l < this->size(); l++)
						_alloc.destroy(_start + l);
					_alloc.deallocate(_start, this->capacity());

					_start = new_start;
					_end = new_end;
					_end_capacity = new_end_capacity;
				}
    }
    
    iterator erase (iterator position);iterator erase (iterator first, iterator last)
    {
        pointer p_pos = position;
		_alloc.destroy(position);
		if (position + 1 == _end)
			_alloc.destroy(position);
		else
		{
			for (int i = 0; i < _end - position - 1; i++)
			{
				_alloc.construct(position + i, *(position + i + 1));
				_alloc.destroy(position + i + 1);
			}
		}
		_end -= 1;
		return (iterator(p_pos));
    }

    void swap (vector& x)
    {
        if (x == *this)
		    return;
			
		pointer save_start = x._start;
		pointer save_end = x._end;
		pointer save_end_capacity = x._end_capacity;
		allocator_type save_alloc = x._alloc;

		x._start = this->_start;
		x._end = this->_end;
		x._end_capacity = this->_end_capacity;
		x._alloc = this->_alloc;

	    this->_start = save_start;
	    this->_end = save_end;
	    this->_end_capacity = save_end_capacity;
	    this->_alloc = save_alloc;
    }
    void clear()
    {
        size_type size = this->size();
		for (size_type i = 0; i < size; i++)
		{
			_end--;
			_alloc.destroy(_end);
		}
    }
    //operator
    	template <class T, class Alloc>
		bool operator== (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
		{
			if (lhs.size() != rhs.size())
				return (false);
			typename ft::vector<T>::const_iterator first1 = lhs.begin();
			typename ft::vector<T>::const_iterator first2 = rhs.begin();
			while (first1 != lhs.end())
			{
				if (first2 == rhs.end() || *first1 != *first2)
					return (false);
				++first1;
				++first2;
			}
			return (true);
		}

        template <class T, class Alloc>
		bool operator!= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
		{
			return (!(lhs == rhs));
		}

        template <class T, class Alloc>
		bool operator<  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		} // dikkat

        template <class T, class Alloc>
		bool operator<= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
		{
			return (!(rhs < lhs));
		}

        template <class T, class Alloc>
		bool operator>  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
		{
			return (rhs < lhs);
		}

        template <class T, class Alloc>
		bool operator>= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
		{
			return (!(lhs < rhs));
		}

        template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>&y)
		{
			x.swap(y);
		}
        
        allocator_type get_allocator() const
        {
            return _alloc;
        }
};

}
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

