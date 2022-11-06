#pragma once
#include<iostream>
# include <iterator>
#include <memory>
#include<vector>
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
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::size_type size_type;
    typedef typename allocator_type::difference_type difference_type;
private:
	allocator_type  _alloc;
	pointer         _start;
	pointer         _end;
	pointer         _end_capacity;
public:
        explicit vector (const allocator_type& alloc = allocator_type())
        {
            this->_alloc = alloc;
            this->_start = nullptr;
            this->_end = nullptr;
            this->_end_capacity = nullptr;
        }
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){}
        template <class InputIterator>         
        vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type()){}
        vector (const vector& x){}
        ~vector(){}

public:
    void push_back(value_type const &a)
    {
        _start = _alloc.allocate( 4 );
		_end_capacity = _start + 4;
		_end = _start;
        
        _alloc.construct(_end,1);
        _end++;
        _alloc.construct(_end,2);
        _end++;
        _alloc.construct(_end,3);
        std::cout << *(_start + 2);
    }
};
