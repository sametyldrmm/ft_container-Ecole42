
# include <iostream>
# include <iterator>
# include <memory>
# include <vector>
# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include "random_acces_iterator.hpp"
# include "utils.hpp"
# include "iterator_traits_and_reverse.hpp"
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
    public: //constructor
        explicit vector (const allocator_type& alloc = allocator_type())
        :_alloc(alloc), _start(nullptr), _end(nullptr), _end_capacity(nullptr){}
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
public: //iterator
    iterator begin(){return (iterator(_start));   }
    const_iterator begin() const {return (const_iterator(_start));}
    
    iterator end()
    {
    	if (this->empty())
			return (this->begin());
	    return (iterator(_end));
    }
    const_iterator end() const
    {
    	if (this->empty())
			return (this->begin());
	    return (const_iterator(_end));
    }
    
    reverse_iterator rbegin() {return (reverse_iterator(this->end())); }
    const_reverse_iterator rbegin() const {return (const_reverse_iterator(this->end())); }
    
    reverse_iterator rend() { return (reverse_iterator(this->begin())); }
    const_reverse_iterator rend() const { return (const_reverse_iterator(this->begin())); }

public://Element access
    reference at (size_type n) {
		if (n >= this->size())
			throw (std::out_of_range("vector::checkRange: n (which is "
					+ ft::to_string(n) + ") >= this->size() (which is "
					+ ft::to_string(this->size()) + ")"));
		return ((*this)[n]);
	}
	const_reference at (size_type n) const {
		if (n >= this->size())
			throw (std::out_of_range("vector::checkRange: n (which is "
					+ ft::to_string(n) + ") >= this->size() (which is "
					+ ft::to_string(this->size()) + ")"));
		return (const_reference((*this)[n]));
	}
    reference front () { return (*_start); }
	const_reference front () const { return (const_reference(*_start)); }
	reference back () { return (*(_end - 1));} 
	const_reference back () const { return (const_reference(*(_end - 1))); }
    pointer data(){    return _start;}
    const_pointer data() const{    return const_pointer(_start);}

    public: //modiffiers
        void push_back(value_type const &a)
    {
		if (_end == _end_capacity)
		{
			int next_capacity = (this->size() > 0) ? (int)(this->size() * 2) : 1;
			this->reserve(next_capacity);
		}
		_alloc.construct(_end, a);
		_end++;
    }
	
	void pop_back()
	{
		_alloc.destroy(&this->back());
		_end--;
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

    public: // get_alloc swap relations_operator
    allocator_type get_allocator() const
    {
        return _alloc;
    }
	reference operator[] (size_type n) { return (*(_start + n)); }
	const_reference operator[] (size_type n) const { return (const_reference(*(_start + n))); }

    };
    template <class U, class Alloc>
	bool operator== (const ft::vector<U, Alloc>& lhs, const ft::vector<U, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::vector<U>::const_iterator first1 = lhs.begin();
		typename ft::vector<U>::const_iterator first2 = rhs.begin();
		while (first1 != lhs.end())
		{
			if (first2 == rhs.end() || *first1 != *first2)
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}
    template <class U, class Alloc>
	bool operator<  (const vector<U, Alloc>& lhs, const vector<U, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	} 
    template <class U, class Alloc>
	bool operator<= (const vector<U, Alloc>& lhs, const vector<U, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}
    template <class U, class Alloc>
	bool operator>  (const vector<U, Alloc>& lhs, const vector<U, Alloc>& rhs)
	{
		return (rhs < lhs);
	}
    template <class U, class Alloc>
	bool operator>= (const vector<U, Alloc>& lhs, const vector<U, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
    template <class u, class Alloc_>
	bool operator!= (const ft::vector<u, Alloc_>& lhs, const ft::vector<u, Alloc_>& rhs)
	{
			return (!(lhs == rhs));
	}
    template <class U, class Alloc>
	void swap (vector<U,Alloc>& x, vector<U,Alloc>&y)
	{
		x.swap(y);
	}
} // namespace ft


// adım 1 ) class yapısını oluştur
// adım 2 ) boş vektör construct oluştur
// adım 3 ) capacity fonklarını ekle bu fonksiyonları daha sonrasında kullanacağız
// adım 4 ) push_back ve pop_back ekle
// adım 5 ) kontrol amaçlı [] ekle
// adım 6 ) testlerini gerçekleştir
// adım 7 ) element acces fonksiyonlarını koduna ekle gerekli olursa utils.hpp yap ve gerekli fonkları ekle
// adım 8 ) iterator_traits ekle ve reverse_iterator ekle
//              şimdi bunu yapma şeklimiz şudur typedef ile belirttikten sonra gider dosyamızı oluştururuz
//              sitelerdeki bilgilere göre dosyamızı doldururuz
//              yani    adım 1 ) vector dosyasında vector klasına ihtiyacı olan şeyleri ver
//                      adım 2 ) iterator_traits structlarını oluştur bunlar bilgi bloklarımız olucak
//                      adım 3 ) reverse_iterator clasını oluştur
//                      adım 4 ) iterator_traits klasındaki bilgileri gerçek std::iteratorden al
//                      adım 5 ) constructları oluştur
//                      adım 6 ) anlaki bu bir adresdir sadece deneme amaçlı ++ ve -- ve '=' operatorunu işlevlerini oluştur
//                      adım 7 ) şimdi vectore dön ve oluşturman gereken iterator fonklarını oluştur
//                      adım 8 ) basic şeylerle deneye deneye tüm it fonklarını yaz
// adım 9 ) random_acces_iterator ekle bununda mantığı aynı sadece 4 farklı işlev bloğuna ayırmışlar mantık aynı kodlar benzer
//          testlerii yap
// adım 10 ) get_alloc yap swap yap realations_operators leri yap
// adım 11 ) 