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
    template< class Key,    class T,    class Compare = std::less<Key>,    class Allocator = std::allocator<std::pair<const Key, T>>> class map //bak!!!!!!!!!!!!!!!!!!!!!!!!1
    {
        typedef Key     key_type;
        typedef T       mapped_type;
        typedef std::pair<key_type, mapped_type> value_type;                            //bak!!!!!!!!!!!!!!!!!!!!!!!!1
        typedef Compare     key_compare;

        // 		class value_compare : ft::binary_function<value_type, value_type, bool>
        // {
        // 	friend class map<key_type, mapped_type, key_compare, Alloc>;
        
        // 	protected:
        // 		Compare comp;
        // 		value_compare (Compare c) : comp(c) {}
        // 	public:
        // 		/* 
        // 		** Result type, first argument type and second argument type are
        // 		** stocked int binary_function.
        // 		*/
        // 		/*
        // 		** @brief Call the compare function to compare
        // 		** "x" and "y".
        // 		**
        // 		** @param x,y values to compare.
        // 		** @return boolean from comparison function.
        // 		*/
        // 		bool operator() (const value_type& x, const value_type& y) const
        // 		{ return (comp(x.first, y.first)); }
        // };

        typedef Alloc  allocator_type;
        typedef typename allocator_type::reference   reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer     pointer;
        typedef typename allocator_type::const_pointer const_pointer;
    	typedef typename std::Binary_search_tree<value_type, key_compare>::iterator iterator;               //bak!!!!!!!!!!!!!!!!!!!!!!!!1
	    typedef typename std::Binary_search_tree<value_type, key_compare>::const_iterator const_iterator;   //bak!!!!!!!!!!!!!!!!!!!!!!!!1
	    typedef typename ft::reverse_iterator<iterator>    reverse_iterator;
	    typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
	    typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
	    typedef size_t size_type;


    };
} // namespace ft


// make_pair and pair

// adım 1) pair -> make_pair
        // yapıldı
// adım 2) map classını oluştururken paire ve bir tane compare fonksiyonuna bu fonksiyonda std::less tabikide yeniden yazıcaz fonksiyonu ihtiyacımız var
        // bu aşamada sadece less fonksiyonu yetmiyor bir taneda binary search algoritması gerekiyor
// adım 3)  sonra düşüncez şuanlık ihtiyacımız bu yönde 


// şimdi ilk genel map yapısını oluşturucaz daha sonra pair dahada sonra less i yapıcaz
