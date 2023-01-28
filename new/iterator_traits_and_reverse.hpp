#ifndef ITERATOR_TRAITS_AND_REVERSE_HPP
#define ITERATOR_TRAITS_AND_REVERSE_HPP

# include <iterator>
# include <cstddef> 

namespace ft
{
    template <typename Iter>
    struct iterator_traits
    {
        typedef typename Iter::value_type value_type;
        typedef typename Iter::pointer pointer;
        typedef typename Iter::reference reference;
        typedef typename Iter::difference_type difference_type;
        typedef typename Iter::iterator_category iterator_category;
    };

    template <typename T>
    struct iterator_traits<T *>
    {
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        typedef std::ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <typename T>
    struct iterator_traits<const T *>
    {
        typedef T value_type;
        typedef const T *pointer;
        typedef const T &reference;
        typedef std::ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;
    };

    // Class Decloration
    template <typename It>
    class reverse_iterator
        : public std::iterator< // Inherits from std::iterator
              typename iterator_traits<It>::iterator_category, typename iterator_traits<It>::value_type,
              typename iterator_traits<It>::difference_type, typename iterator_traits<It>::pointer,
              typename iterator_traits<It>::reference>
    {
        // Public Member Types
    public:
        typedef It iterator_type;
        typedef typename iterator_traits<It>::iterator_category iterator_category;
        typedef typename iterator_traits<It>::value_type value_type;
        typedef typename iterator_traits<It>::difference_type difference_type;
        typedef typename iterator_traits<It>::pointer pointer;
        typedef typename iterator_traits<It>::reference reference;

    protected:
        It _current;
        // Constructors
    public:
        reverse_iterator() : _current() {}
        reverse_iterator(const reverse_iterator &rhs) : _current(rhs._current) {}
        reverse_iterator(iterator_type it) : _current(it) {}
        template <typename Iter>
        reverse_iterator(const reverse_iterator<Iter> &rev_it) : _current(rev_it.base()) {}
        ~reverse_iterator() {}
        reverse_iterator &operator=(reverse_iterator const &rhs)
        {
            if (this != &rhs)
                _current = rhs._current;
            return *this;
        }

        // Public Member Functions
    public:
        iterator_type base() const
        {
            return _current;
        }
        reference operator*() const
        {
            It tmp = _current;
            return *--tmp;
        }
        pointer operator->() const { return &(operator*()); }
        reference operator[](difference_type n) const { return (base()[-n - 1]); }
        reverse_iterator operator+(difference_type n) const { return reverse_iterator(base() - n); }
        // Pre increment
        reverse_iterator &operator++()
        {
            --_current;
            return *this;
        }
        // Post increment
        reverse_iterator operator++(int) { return reverse_iterator(_current--); }
        reverse_iterator operator-(difference_type n) const { return reverse_iterator(base() + n); }
        // Pre decrement
        reverse_iterator &operator--()
        {
            ++_current;
            return *this;
        }
        // Post decrement
        reverse_iterator operator--(int) { return reverse_iterator(_current++); }
        reverse_iterator &operator+=(difference_type n)
        {
            _current -= n;
            return *this;
        }
        reverse_iterator &operator-=(difference_type n)
        {
            _current += n;
            return *this;
        }
    }; // End of reverse_iterator class

    template <typename Iterator>
    inline bool operator==(const reverse_iterator<Iterator> &lhs,const reverse_iterator<Iterator> &rhs)
    {    return lhs.base() == rhs.base();}

    template <typename ItL, typename ItR>
    inline bool operator==(const reverse_iterator<ItL> &lhs,const reverse_iterator<ItR> &rhs)
    {    return lhs.base() == rhs.base();}

    template <typename Iterator>
    inline bool operator!=( const reverse_iterator<Iterator> &lhs,const reverse_iterator<Iterator> &rhs)
    {    return lhs.base() != rhs.base();}

    template <typename ItL, typename ItR>
    inline bool operator!=(const reverse_iterator<ItL> &lhs,const reverse_iterator<ItR> &rhs)
    {    return lhs.base() != rhs.base();}

    template <typename Iterator>
    inline bool operator<( const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {    return lhs.base() > rhs.base();}

    template <typename ItL, typename ItR>
    inline bool operator<(const reverse_iterator<ItL> &lhs,const reverse_iterator<ItR> &rhs)
    {    return lhs.base() > rhs.base();}

    template <typename Iterator>
    inline bool operator<=(const reverse_iterator<Iterator> &lhs,const reverse_iterator<Iterator> &rhs)
    {    return lhs.base() >= rhs.base();}

    template <typename ItL, typename ItR>
    inline bool operator<=(const reverse_iterator<ItL> &lhs,const reverse_iterator<ItR> &rhs)
    {    return lhs.base() >= rhs.base();}

    template <typename Iterator>
    inline bool operator>(const reverse_iterator<Iterator> &lhs,const reverse_iterator<Iterator> &rhs)
    {    return lhs.base() < rhs.base();}

    template <typename ItL, typename ItR>
    inline bool operator>(const reverse_iterator<ItL> &lhs,const reverse_iterator<ItR> &rhs)
    {    return lhs.base() < rhs.base();}

    template <typename Iterator>
    inline bool operator>=(const reverse_iterator<Iterator> &lhs,const reverse_iterator<Iterator> &rhs)
    {    return lhs.base() <= rhs.base();}

    template <typename ItL, typename ItR>
    inline bool operator>=(const reverse_iterator<ItL> &lhs,const reverse_iterator<ItR> &rhs)
    {    return lhs.base() <= rhs.base();}

    template <typename Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,const reverse_iterator<Iterator> &rev_it)
    {    return reverse_iterator<Iterator>(rev_it.base() - n);}

    template <typename Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs,const reverse_iterator<Iterator> &rhs)
    {    return rhs.base() - lhs.base();}

    template <typename ItL, typename ItR>
    typename reverse_iterator<ItL>::difference_type operator-(const reverse_iterator<ItL> &lhs,const reverse_iterator<ItR> &rhs)
    {    return rhs.base() - lhs.base();}

    // iterator template<class InputIterator> typename ft::iterator_traits<InputIterator>::difference_type > distance (InputIterator first, InputIterator last)
    //     {
    //         typename ft::iterator_traits<InputIterator>::difference_type rtn = 0;
    //         while (first != last)
    //         {
    //             first++;
    //             rtn++;
    //         }
    //         return (rtn);
    //     }
}

#endif