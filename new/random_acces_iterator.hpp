#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits_and_reverse.hpp"
#include"utils.hpp"
namespace ft
{
    //  Random-access iterators are one of the five main types of iterators present in C++ Standard Library others being:
    //  1) Input iterator
    //  2) Output iterator
    //  3) Forward iterator
    //  4) Bidirectional iterator

    // Class Declaretion
    template <typename It, typename Container>
    class random_access_iterator
    {
        // Public Member Types (same as pointers)
    public:
        typedef It iterator_type;
        typedef typename iterator_traits<It>::iterator_category iterator_category;
        typedef typename iterator_traits<It>::value_type value_type;
        typedef typename iterator_traits<It>::pointer pointer;
        typedef typename iterator_traits<It>::reference reference;
        typedef typename iterator_traits<It>::difference_type difference_type;

    protected:
        It _ptr;

        // Constructors
    public:
        random_access_iterator() : _ptr(iterator_type()) {}
        explicit random_access_iterator(iterator_type const &it) : _ptr(it){}
        
        template <typename Iter>
        random_access_iterator(
            const random_access_iterator<Iter, typename enable_if<is_same<Iter,
            typename Container::pointer>::value,Container>::type> &it)
            : _ptr(it.base()){}

        ~random_access_iterator() {}
        random_access_iterator &operator=(random_access_iterator const &rhs)
        {
            if (this != &rhs)
                _ptr = rhs._ptr;
            return *this;
        }
        template<bool Cond, class T = void> struct enable_if {};
        template<class T> struct enable_if<true, T> { typedef T type; };

        // Public Member Functions
    public:
        const iterator_type &base() const { return _ptr; }
        reference operator*(){    return *_ptr;}
        pointer operator->(){    return _ptr;}
  
        random_access_iterator &operator++(){    ++_ptr;    return *this;}
        random_access_iterator operator++(int){    return random_access_iterator(_ptr++);}
        random_access_iterator &operator--(){    --_ptr;    return *this;}
        random_access_iterator operator--(int){    return random_access_iterator(_ptr--);}
  
        random_access_iterator operator+(difference_type n){    return random_access_iterator(_ptr + n);}
        random_access_iterator operator-(difference_type n){    return random_access_iterator(_ptr - n);}
  
        random_access_iterator &operator+=(difference_type n)
        {    _ptr += n;    return *this;}
        random_access_iterator &operator-=(difference_type n)
        {    _ptr -= n;    return *this;}
  
        reference operator[](difference_type n){    return *(_ptr + n);}
    };

    // Comparing operators
    template <typename ItL, typename ItR, typename Container>
    inline bool operator==(const random_access_iterator<ItL, Container> &lhs,const random_access_iterator<ItR, Container> &rhs)
    {    return lhs.base() == rhs.base();}

    template <typename It, typename Container>
    inline bool operator==(const random_access_iterator<It, Container> &lhs,const random_access_iterator<It, Container> &rhs)
    {    return lhs.base() == rhs.base();}

    template <typename ItL, typename ItR, typename Container>
    inline bool operator!=(const random_access_iterator<ItL, Container> &lhs,const random_access_iterator<ItR, Container> &rhs)
    {    return lhs.base() != rhs.base();}

    template <typename It, typename Container>
    inline bool operator!=(const random_access_iterator<It, Container> &lhs,const random_access_iterator<It, Container> &rhs)
    {    return lhs.base() != rhs.base();}

    template <typename ItL, typename ItR, typename Container>
    inline bool operator<(const random_access_iterator<ItL, Container> &lhs,const random_access_iterator<ItR, Container> &rhs)
    {    return lhs.base() < rhs.base();}

    template <typename It, typename Container>
    inline bool operator<(const random_access_iterator<It, Container> &lhs,const random_access_iterator<It, Container> &rhs)
    {    return lhs.base() < rhs.base();}

    template <typename ItL, typename ItR, typename Container>
    inline bool operator<=(const random_access_iterator<ItL, Container> &lhs,const random_access_iterator<ItR, Container> &rhs)
    {    return lhs.base() <= rhs.base();}

    template <typename It, typename Container>
    inline bool operator<=(const random_access_iterator<It, Container> &lhs,const random_access_iterator<It, Container> &rhs)
    {    return lhs.base() <= rhs.base();}

    template <typename ItL, typename ItR, typename Container>
    inline bool operator>(const random_access_iterator<ItL, Container> &lhs,const random_access_iterator<ItR, Container> &rhs)
    {    return lhs.base() > rhs.base();}

    template <typename It, typename Container>
    inline bool operator>(const random_access_iterator<It, Container> &lhs,const random_access_iterator<It, Container> &rhs)
    {    return lhs.base() > rhs.base();}

    template <typename ItL, typename ItR, typename Container>
    inline bool operator>=(const random_access_iterator<ItL, Container> &lhs,const random_access_iterator<ItR, Container> &rhs)
    {    return lhs.base() >= rhs.base();}

    template <typename It, typename Container>
    inline bool operator>=(const random_access_iterator<It, Container> &lhs,const random_access_iterator<It, Container> &rhs)
    {    return lhs.base() >= rhs.base();}

    // Adding and Substraction Between Iterators
    template <typename ItL, typename ItR, typename Container>
    inline typename random_access_iterator<ItL, Container>::difference_type
    operator-(const random_access_iterator<ItL, Container> &lhs,const random_access_iterator<ItR, Container> &rhs)
    {    return lhs.base() - rhs.base();}

    template <typename It, typename Container>
    inline typename random_access_iterator<It, Container>::difference_type
    operator-(const random_access_iterator<It, Container> &lhs,const random_access_iterator<It, Container> &rhs)
    {    return lhs.base() - rhs.base();}

    template <typename It, typename Container>
    inline random_access_iterator<It, Container>
    operator+(typename random_access_iterator<It, Container>::difference_type n,const random_access_iterator<It, Container> &it)
    {    return random_access_iterator<It, Container>(it.base() + n);}


    
} // namespace ft

#endif