// #include <iostream>
// using namespace std;

// template<typename T>
#pragma once
class Nodo{
    public:
        T data;
        Nodo* next;
        Nodo(const T& val, Nodo* pNext = NULL):data(val),next(pNext){}
};