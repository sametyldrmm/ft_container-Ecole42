
# include <iostream>
# include <iterator>
# include <memory>
# include <vector>
# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
// # include "random_acces_iterator.hpp"
// #include "utils.hpp"

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
    
    
    }
} // namespace ft
