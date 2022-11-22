#include<iostream>
#include<vector>

int main()
{
    std::vector<int> a;
    std::vector<int> b;
    std::cout << "empty=" << a.empty() << "\n\n";
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(40000000);
    a.push_back(7);
    a.push_back(7);
    a.push_back(7);
    a.push_back(7);
    a.push_back(7);
    a.push_back(7);
    a.push_back(7);
    a.push_back(7);
    std::cout << "empty=" << a.empty() << "\n";
    std::cout <<"size=" << a.size() << "\n";
    std::cout <<"capasity=" << a.capacity() << "\n";
    std::cout << "max_size" << a.max_size() << "\n";

    b.push_back(1231231233);
    b.push_back(1231231233);
    b.push_back(1231231233);
    b.push_back(1231231233);
    b.push_back(1231231233);
    b.push_back(1231231233);
    b.push_back(1231231233);
    b.push_back(1231231233);
    b.push_back(1231231233);
    b.reserve(3);
    // b.push_back(123);
    // b.push_back(123);
    // b.push_back(123);
    // b.push_back(123);
    // b.push_back(123);
    // b.push_back(123);
    
    std::cout << b.capacity() << "\n";
    std::cout << b.size() << "\n";
    
    
    
    
    // b.push_back(99);
    // b.push_back(99);
    // b.push_back(99);
    // b.push_back(99);
    

    // a.insert(a.begin() + 1,b.begin(),b.end());
    // a.insert(a.begin()+2,3);
    // a.insert(a.begin()+6,40,444);
    // std::vector<int>::iterator it;
    // for ( it = a.begin(); it != a.end(); it++)
    // {
    //     std::cout<< *it<< "\n";
    // }

// iterator insert (iterator position, const value_type& val);
// void insert (iterator position, size_type n, const value_type& val);
// template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);
}