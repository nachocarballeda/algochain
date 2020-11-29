// Self implementation of
// the algoVector Class in C++

#ifndef _ALGOVECTOR_H_
#define _ALGOVECTOR_H_

template <class T>
class algoVector
{
public:
    typedef T *iterator;

    algoVector();
    algoVector(unsigned int size);
    algoVector(unsigned int size, const T &initial);
    algoVector(const algoVector<T> &v);
    ~algoVector();

    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    iterator begin();
    iterator end();
    T &front();
    T &back();
    void push_back(const T &value);
    void pop_back();

    void reserve(unsigned int capacity);
    void resize(unsigned int size);

    T &operator[](unsigned int index);
    algoVector<T> &operator=(const algoVector<T> &);
    void clear();

private:
    unsigned int my_size;
    unsigned int my_capacity;
    T *buffer;
};

template <class T>
algoVector<T>::algoVector()
{
    my_capacity = 0;
    my_size = 0;
    buffer = 0;
}

template <class T>
algoVector<T>::algoVector(const algoVector<T> &v)
{
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_size];
    for (unsigned int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];
}

template <class T>
algoVector<T>::algoVector(unsigned int size)
{
    my_capacity = size;
    my_size = size;
    buffer = new T[size];
}

template <class T>
algoVector<T>::algoVector(unsigned int size, const T &initial)
{
    my_size = size;
    my_capacity = size;
    buffer = new T[size];
    for (unsigned int i = 0; i < size; i++)
        buffer[i] = initial;
    //T();
}

template <class T>
algoVector<T> &algoVector<T>::operator=(const algoVector<T> &v)
{
    delete[] buffer;
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_size];
    for (unsigned int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];
    return *this;
}

template <class T>
typename algoVector<T>::iterator algoVector<T>::begin()
{
    return buffer;
}

template <class T>
typename algoVector<T>::iterator algoVector<T>::end()
{
    return buffer + size();
}

template <class T>
T &algoVector<T>::front()
{
    return buffer[0];
}

template <class T>
T &algoVector<T>::back()
{
    return buffer[my_size - 1];
}

template <class T>
void algoVector<T>::push_back(const T &v)
{
    if (my_size >= my_capacity)
        reserve(my_capacity + 5);
    buffer[my_size++] = v;
}

template <class T>
void algoVector<T>::pop_back()
{
    my_size--;
}

template <class T>
void algoVector<T>::reserve(unsigned int capacity)
{
    if (buffer == 0)
    {
        my_size = 0;
        my_capacity = 0;
    }
    T *Newbuffer = new T[capacity];
    //assert(Newbuffer);
    unsigned int l_Size = capacity < my_size ? capacity : my_size;
    //copy (buffer, buffer + l_Size, Newbuffer);

    for (unsigned int i = 0; i < l_Size; i++)
        Newbuffer[i] = buffer[i];

    my_capacity = capacity;
    delete[] buffer;
    buffer = Newbuffer;
}

template <class T>
unsigned int algoVector<T>::size() const //
{
    return my_size;
}

template <class T>
bool algoVector<T>::empty() const //
{
    return (buffer == 0);
}

template <class T>
void algoVector<T>::resize(unsigned int size)
{
    reserve(size);
    my_size = size;
}

template <class T>
T &algoVector<T>::operator[](unsigned int index)
{
    return buffer[index];
}

template <class T>
unsigned int algoVector<T>::capacity() const
{
    return my_capacity;
}

template <class T>
algoVector<T>::~algoVector()
{
    delete[] buffer;
}
template <class T>
void algoVector<T>::clear()
{
    my_capacity = 0;
    my_size = 0;
    buffer = 0;
}

#endif //_ALGOVECTOR_H_
