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
    std::vector<int>::reverse_iterator st_ri;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);

    st_ri = a.rbegin();
    for ( st_ri = a.rbegin(); st_ri != a.rend(); st_ri++)
    {
        st_str += ft::to_string(*st_ri) + "\n";
    }
    for ( st_ri = a.rend(); st_ri != a.rbegin(); st_ri--)
    {
        st_str += ft::to_string(*st_ri) + "\n";
    }
    st_str += ft::to_string (*--st_ri.base()) + "\n";
    st_str += *(st_ri -2);
    st_str += *(st_ri +1);
    
    st_str += st_ri == st_ri;
    st_str += st_ri +1 != st_ri;
    st_str += st_ri  != st_ri;
    st_str += st_ri  != st_ri - 1;

    st_str += st_ri >= st_ri;
    st_str += st_ri +1 <= st_ri;
    st_str += st_ri  > st_ri;
    st_str += st_ri  < st_ri - 1;
    
    std::string ft_str;
    ft::vector<int> b;
    ft::vector<int>::reverse_iterator ft_ri;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);
    ft_ri = b.rbegin();
    for ( ft_ri = b.rbegin(); ft_ri != b.rend(); ft_ri++)
    {
        ft_str += ft::to_string(*ft_ri) + "\n";
    }
    for ( ft_ri = b.rend(); ft_ri != b.rbegin(); ft_ri--)
    {
        ft_str += ft::to_string(*ft_ri) + "\n";
    }
    
    ft_str += ft::to_string(*--ft_ri.base()) + "\n";
    ft_str += *(ft_ri -2);
    ft_str += *(ft_ri +1);
 
    ft_str += ft_ri == ft_ri;
    ft_str += ft_ri +1 != ft_ri;
    ft_str += ft_ri  != ft_ri;
    ft_str += ft_ri  != ft_ri - 1;

    ft_str += ft_ri >= ft_ri;
    ft_str += ft_ri +1 <= ft_ri;
    ft_str += ft_ri  > ft_ri;
    ft_str += ft_ri  < ft_ri - 1;
    
    std::cout << bool(ft_str == st_str) ;
}