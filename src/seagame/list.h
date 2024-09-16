#pragma once


#ifndef _LIST_HPP
#define _LIST_HPP

#include <iostream>
#include <vector>

namespace seagame
{

template <class T>
class List
{
public:
    List(std::initializer_list<T> arr)
    {
        if (!arr.size())
        {
            _len = 0;
            _ptr = nullptr;
            return;
        }

        _len = arr.size();
        _ptr = new T[_len];
        std::copy(arr.begin(), arr.end(), _ptr);

    }

    List() : List({}) 
    {    }

    ~List()
    {
        delete [] _ptr;
        _ptr = nullptr;
        _len = 0;

    }

    List(const List<T> &other)
    {
        // TODO:
    }

private:
    T *_ptr;
    std::size_t _len;

    constexpr float COEF_OF_INC = 1.5;

};

} // namespace seagame


#endif // _LIST_HPP