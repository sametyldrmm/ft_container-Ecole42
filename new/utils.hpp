#ifndef UTILS_HPP
# define UTILS_HPP

#include<iostream>
#include<string>
#include<sstream>
#include<stdio.h>

namespace ft {
template <typename T>
std::string to_string(T n)
{
    /* Stream used to convert */
    std::ostringstream ss;
    ss << n;
    return (ss.str());
}

    template <bool B, typename T = void>
    struct enable_if
    {
    };

    template <typename T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    struct true_type
    {
        static const bool value = true;
        typedef true_type type;
    };

    struct false_type
    {
        static const bool value = false;
        typedef false_type type;
    };

    template <typename>
    struct is_integral : public false_type
    {
    };

    template <>
    struct is_integral<bool> : public true_type
    {
    };

    template <>
    struct is_integral<char> : public true_type
    {
    };

    template <>
    struct is_integral<signed char> : public true_type
    {
    };

    template <>
    struct is_integral<short int> : public true_type
    {
    };

    template <>
    struct is_integral<int> : public true_type
    {
    };

    template <>
    struct is_integral<long int> : public true_type
    {
    };

    template <>
    struct is_integral<unsigned char> : public true_type
    {
    };

    template <>
    struct is_integral<unsigned short int> : public true_type
    {
    };

    template <>
    struct is_integral<unsigned int> : public true_type
    {
    };

    template <>
    struct is_integral<unsigned long int> : public true_type
    {
    };

    template <typename T, typename U>
    struct is_same : public false_type
    {
    };

    template <typename T>
    struct is_same<T, T> : public true_type
    {
    };
    template <class InputIterator1, class InputIterator2>
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                        InputIterator2 first2, InputIterator2 last2)
        {
            while (first1 != last1)
            {
                if (first2 == last2 || *first2 < *first1) return false;
                else if (*first1 < *first2) return true;
                ++first1;
                ++first2;
            }
            return (first2 != last2);
        }


}
#endif