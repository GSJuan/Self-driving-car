// AUTHOR: Juan García Santos
// DATE: 04/10/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AI
// PRACTICE Nº: 1
// Compilation: make
// Execution: ./simulation
//clase vector que acepta indices negativos

#include "cell.h"

#include <vector>
#include <cassert>
#include <iostream>
#include <iomanip>

#pragma once

template<class T>
class Vector {

private:

int index_zero = 0;
std::vector<T> vector;


public:

Vector() {
    index_zero = -1;
    vector.resize(2);
}

Vector(int min, int max) {
    assert (min < max);
    index_zero = min;
    int sz = max - min;
    vector.resize(sz);
}

Vector(const Vector<T>& r_vec){
    index_zero = r_vec.GetLowerLimit();
    vector = r_vec.vector;
}

~Vector() {}

T& operator[](int index) {

    if((index >= GetLowerLimit()) && (index < GetUpperLimit()))
        return vector[index - index_zero];
    else 
        throw std::exception();
}


T& operator[](int index) const {
    try {
        assert(index >= GetLowerLimit());
        assert(index <= GetUpperLimit());
        return vector[index - index_zero];
    }
    catch(...){
        throw std::exception();
    }
}

void resize(int sz) {
    vector.resize(sz);
}

inline std::vector<T>& GetVector(){
    return vector;
}
inline int GetUpperLimit() const {
    return index_zero + vector.size();
}

inline int GetLowerLimit() const {
    return index_zero;
}

inline void SetLowerLimit(int min) {
    index_zero = min;
}

inline int GetSize() const {
    return GetUpperLimit() - GetLowerLimit();
}

};