//
// Created by johnw on 8/22/2023.
//

#include "vector.h"

template <typename T>
vector<T>::vector():
    arr(new T[1]),
    capacity(1),
    current(0)
{}

template <typename T>
vector<T>::~vector() {
    delete [] arr;
}

template <typename T>
void vector<T>::push(T data) {
    // if the vector is full, make it bigger
    if (current == capacity) {
        T* temp = new T[2 * capacity];

        for (int i=0; i<capacity; i++) {
            temp[i] = arr[i];
        }

        delete [] arr;
        capacity *= 2;
        arr = temp;
    }

    // add the new data
    arr[current] = data;
    current++;
}

template <typename T>
void vector<T>::push(T data, int index) {
    // If it's added to the end, insert it normally
    if (index >= current)
        push(data);
    else // just rewrite current array spot
        arr[index] = data;
}

template <typename T>
T vector<T>::operator[](int index) {
    return get(index);  // Keep it DRY
}


template <typename T>
T vector<T>::get(int index) {
    if (index < current)
        return arr[index];
}

template <typename T>
T vector<T>::pop() {
    // return and remove the last element
    return get(current);
}

template <typename T>
int vector<T>::size() {
    return current;
}

template <typename T>
int vector<T>::getCapacity() {
    return capacity;
}