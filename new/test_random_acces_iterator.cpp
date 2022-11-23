// #include"random_acces_iterator.hpp"
#include<iterator>
#include<vector>
#include<iostream>
#include"vector.hpp"
#include"iterator_traits_and_reverse.hpp"
#include<ostream>
int main()
{
    std::string st_str;
    std::vector<int> a;
    std::vector<int>::iterator st_ri;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);

    st_ri = a.begin();
    for ( st_ri = a.begin(); st_ri != a.end(); st_ri++)
    {
        st_str += ft::to_string(*st_ri) + "\n";
    }
    for ( st_ri = a.end(); st_ri != a.begin(); st_ri--)
    {
        st_str += ft::to_string(*st_ri) + "\n";
    }
    // st_str += ft::to_string (*--st_ri.base()) + "\n";
    st_str += *(st_ri -2);
    st_str += *(st_ri +1);
    
    st_str += st_ri == st_ri;
    st_str += st_ri +1 != st_ri;
    st_str += st_ri  != st_ri;
    st_str += st_ri  == st_ri - 1;

    st_str += st_ri >= st_ri;
    st_str += st_ri +1 <= st_ri;
    st_str += st_ri  > st_ri;
    st_str += st_ri  < st_ri - 1;
    
    std::string ft_str;
    ft::vector<int> b;
    ft::vector<int>::iterator ft_ri;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);
    ft_ri = b.begin();
    for ( ft_ri = b.begin(); ft_ri != b.end(); ft_ri++)
    {
        ft_str += ft::to_string(*ft_ri) + "\n";
    }
    for ( ft_ri = b.end(); ft_ri != b.begin(); ft_ri--)
    {
        ft_str += ft::to_string(*ft_ri) + "\n";
    }
    
    ft_str += *(ft_ri -2);
    ft_str += *(ft_ri +1);
 
    ft_str += ft_ri == ft_ri;
    ft_str += ft_ri +1 != ft_ri;
    ft_str += ft_ri  != ft_ri;
    ft_str += ft_ri  == ft_ri - 1;

    ft_str += ft_ri >= ft_ri;
    ft_str += ft_ri +1 <= ft_ri;
    ft_str += ft_ri  > ft_ri;
    ft_str += ft_ri  < ft_ri - 1;

    std::cout << &ft_ri << "\n";
    // std::cout << ft_ri << "\n";
    std::cout << bool(ft_str == st_str) ;
}