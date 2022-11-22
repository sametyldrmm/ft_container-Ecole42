// // #include<iostream>
// // #include<vector>
// // #include"vector.hpp"
// // int main()
// // {
// //     std::vector<int> a;
// //     std::vector<int>::iterator it;
// //     a.push_back(12);
// //     a.push_back(22);
// //     a.push_back(32);
// //     a.push_back(42);
// //     a.push_back(52);
// //     for(it = a.begin();it != a.end();it++)
// //         std::cout << *it << "  "<< it - a.begin() <<std::endl;
    

// // }

// #include <iostream>
// #include <memory>
// using namespace std;
// int main()
// {
 
//     // allocator for integer values
//     allocator<int> myAllocator;
 
//     // allocate space for five ints
//     int* arr = myAllocator.allocate(5);
 
//     // construct arr[0] and arr[3]
//     // myAllocator.construct(arr, 100); // no longer allowed in C++20
//     arr[0] = 100; // do this instead
//     arr[3] = 10;
 
//     cout << arr[3] << endl;
//     cout << arr[0] << endl;
 
//     // deallocate space for five ints
//     myAllocator.deallocate(arr, 5);
 
//     return 0;
// }
#include<iostream>
// #include"vector.hpp"
#include<vector>
int main()
{
    // std::vector<int> a;
    // a.push_back(12);
    // a.push_back(12);
    // a.push_back(12);
    // a.push_back(12);
    // a.push_back(12);
    // std::vector<int> b;

    // b.insert(b.begin(),a.begin(),a.end());
    // std::cout << b.capacity() << "\n"; 
    // b.push_back(122);
    // std::cout << b.capacity() << "\n";
    // b.push_back(122);
    // b.push_back(122);
    // b.push_back(122);
    // b.push_back(122);
    // b.push_back(122);

    // std::cout << b.capacity() << "\n";
    // std::cout << b.size() << "\n";
    // // a.pri();

    std::vector<int> first;
    std::vector<int> second;
    std::vector<int> third;

    first.assign (7,100);             // 7 ints with a value of 100
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << first[i] << "\n";
    }

    first.assign (3,300);             // 7 ints with a value of 100

    for (size_t i = 0; i < 10; i++)
    {
        std::cout << first[i] << "\n";
    }
    std::cout << first.size();
}
