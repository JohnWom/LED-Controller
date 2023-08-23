//
// Created by johnw on 8/22/2023.
//

#ifndef RESPONDER_VECTOR_H
#define RESPONDER_VECTOR_H

/*
 * Light implementation of std::vector for use in the responder
*/

template <typename T>
class vector {
    // pointer to the address of the vector
    T* arr;

    // capacity is the maximum number of elements that can currently be
    // stored in the vector
    int capacity;

    // current is the current number of elements in the vector
    int current;

public:
    vector();
    ~vector();

    void push(T data);
    void push(T data, int index);

    T operator[](int index);    // enables use of subscripting
    T get(int index);
    T pop();

    int size();
    int getCapacity();

};


#endif //RESPONDER_VECTOR_H
