#include<iostream>
#include<vector>
#include"vector.hpp"

int main()
{
    std::vector<int> std;
    ft::vector<int> ft;

    std.push_back(1);
    std.push_back(2);
    std.push_back(3);

    ft.push_back(1);
    ft.push_back(2);
    ft.push_back(3);

    std::cout << ft[0] << ft[1] << ft[2] << ft[3] <<"\n";
    std::cout << std[0] << std[1] << std[2] << std[3] << "\n";

    std::cout << ft.at(0) << ft.at(1) << ft.at(2) << "\n";
    std::cout << std.at(0) << std.at(1) << std.at(2) << "\n";
    try
    {
        std::cout << ft.at(4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::cout << std.at(4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << ft.front() << ft.back() << ft.data() << "\n";
    std::cout << std.front() << std.back() << std.data() << "\n";
    system("leaks ./a.out");
}

