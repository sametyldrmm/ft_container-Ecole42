#include"pair_utils.hpp"

#include<iostream>

int main()
{
    ft::pair<int ,int> a(33,3);
    ft::pair<ft::pair<int ,int>,int> b(a,5);
    std::cout << b.second << "\n";   
}
