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
    
    // I dont understand
    std::size_t     size_type; 
    std::ptrdiff_t  difference_type;
    
public:
    vector()
    {
        Allocator b;
        std::cout << sizeof(allocator_type) << "\n" << sizeof(value_type) << "\n";
        pointer *s;
        std::cout << &s;
    }
    ~vector()
    {
    }
};
