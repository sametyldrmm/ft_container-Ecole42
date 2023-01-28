#include<iterator>
#include<vector>
#include"vector.hpp"
#include<ostream>

    // inserttt push_back pop_back erase clear assign done
int main()
{
    ft::vector<int> a;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);

    ft::vector<int>::iterator b;
    b = a.end();
    b -= 2;
    a.insert(b,-99); // single element insert
    b = a.end();
    a.insert(b,-99); // single element insert
    
    b = a.end();
    a.insert(b,50,10);

    ft::vector<int> den;
    den.insert(den.begin(),40,-66);

    a.insert(a.begin() + 2,den.begin()+1,den.end()-1);
    ft::vector<int>::iterator it;
    
    a.erase(a.begin()+2);
    a.erase(a.begin()+5,a.begin()+8);
    
    {
        ft::vector<int> first;
        ft::vector<int> second;
        ft::vector<int> third;

        first.assign (7,100);             // 7 ints with a value of 100

        ft::vector<int>::iterator it;
        it = first.begin()+1;

        second.assign (it,first.end()-1); // the 5 central values of first

        int myints[] = {1776,7,4};
        third.assign (myints,myints+3);   // assigning from array.

        std::cout << "Size of first: " << int (first.size()) << '\n';
        std::cout << "Size of second: " << int (second.size()) << '\n';
        std::cout << "Size of third: " << int (third.size()) << '\n';
    }

    for ( it = a.begin(); it != a.end(); it++)
    {
        std::cout << *it << "\n";
    }
    a.clear();
    if(a.begin() != a.end())
    {
        for ( it = a.begin(); it != a.end(); it++)
        {
            std::cout <<"clear sonrasi" << *it << "\n";
        }
    }
    else
    {
        std::cout << "clear başarılı";
    }
}