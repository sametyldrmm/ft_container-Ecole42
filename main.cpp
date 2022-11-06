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
#include"vector.hpp"
int main()
{
    vector<char> a;
    // a.pri();
}