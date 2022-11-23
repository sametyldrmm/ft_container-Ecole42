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
    std::cout <<"ft "<<ft.empty()  <<"\n"<<ft.max_size() <<"\n"<< ft.size() << "\n";
    std::cout <<"std "<<std.empty()<<"\n" <<std.max_size() <<"\n"<< std.size() << "\n";

    ft.reserve(100);
    std.reserve(100);

    std::cout <<"ft "<< "\n"<< ft.empty()  <<"\n"<<ft.max_size() <<"\n"<< ft.size() << "\n";
    std::cout <<"std "<< "\n"<<std.empty()<<"\n" <<std.max_size() <<"\n"<< std.size() << "\n";
    system("leaks ./a.out");
}

