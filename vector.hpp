#pragma once
#include<iostream>
# include <iterator>
#include <memory>
#include<vector>

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
        explicit vector (const allocator_type& alloc = allocator_type()){}
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){}
        template <class InputIterator>         
        vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type()){}
        vector (const vector& x){}
        ~vector(){}
};
