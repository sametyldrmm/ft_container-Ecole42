#ifndef STACK_HPP
#define STACK_HPP
#include<deque>

template<class T,class Container = std::deque<T>> 
class stack
{
private:
    container_type	Container;
    value_type	Container::value_type;
    size_type	Container::size_type;
    reference	Container::reference;
    const_reference	Container::const_reference;
public:
    stack()
    {
    }
    ~stack();
};

#endif