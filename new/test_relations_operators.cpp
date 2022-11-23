#include"random_acces_iterator.hpp"
#include<iterator>
#include<vector>
#include<iostream>
#include"vector.hpp"
#include"iterator_traits_and_reverse.hpp"
#include<ostream>

int main()
{
    std::string st_str;
    std::vector<int> std ;
    std::vector<int> std2 ;
    for (size_t i = 0; i < 10; i++)
    {
        std.push_back(i);
        if ( i < 5)
            std2.push_back(i);
    }
    st_str += bool(std == std2) + "\n";
    st_str += bool(std <= std2) + "\n";
    st_str += bool(std >= std2) + "\n";
    st_str += bool(std < std2) + "\n";
    st_str += bool(std > std2) + "\n";
    
    size_t temp = int(std2.size());
    st_str += temp  == std2.size();
    std::swap(std,std2);
    st_str += std2.size()  == temp;



    std::string ft_str;
    ft::vector<int> ftd ;
    ft::vector<int> ftd2 ;
    for (size_t i = 0; i < 10; i++)
    {
        ftd.push_back(i);
        if(i < 5)
            ftd2.push_back(i);
    }
    
    ft_str += bool(std == std2) + "\n";
    ft_str += bool(std <= std2) + "\n";
    ft_str += bool(std >= std2) + "\n";
    ft_str += bool(std > std2) + "\n";
    ft_str += bool(std < std2) + "\n";
    
    size_t temp2 = ftd2.size();
    ft_str += temp2 == ftd2.size() ;
    ft::swap(ftd,ftd2);
    ft_str += ftd2.size() == temp2 ;

    std::cout << bool(ft_str == st_str) << "\n";
}