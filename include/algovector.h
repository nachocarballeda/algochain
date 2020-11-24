// Self implementation of
// the algoVector Class in C++

#ifndef _ALGOVECTOR_H_
#define _ALGOVECTOR_H_

template <class T>
class  algoVector
{
public:

    typedef T * iterator;

    algoVector();
    algoVector(unsigned int size);
    algoVector(unsigned int size, const T & initial);
    algoVector(const algoVector<T> & v);      
    ~algoVector();

    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    iterator begin();
    iterator end();
    T & front();
    T & back();
    void push_back(const T & value); 
    void pop_back();  

    void reserve(unsigned int capacity);   
    void resize(unsigned int size);   

    T & operator[](unsigned int index);  
    algoVector<T> & operator=(const algoVector<T> &);
    void clear();
private:
    unsigned int my_size;
    unsigned int my_capacity;
    T * buffer;
};

#include "../src/algovector.cpp"

#endif //_ALGOVECTOR_H_
