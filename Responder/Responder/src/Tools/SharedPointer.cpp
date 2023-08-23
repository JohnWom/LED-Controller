//
// Created by johnw on 8/22/2023.
//

#include "SharedPointer.h"

template <typename T>
SharedPointer<T>::SharedPointer():
    ptr(nullptr),
    refCount(new unsigned int(0))
    {}


template <typename T>
SharedPointer<T>::SharedPointer(T *ptr):
    ptr(ptr),
    refCount(new unsigned int(0))
    {}


template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer &obj) {
    this->ptr = obj.ptr;            // share the pointer
    this->refCount = obj.refCount;  // share the refCount
    if (nullptr != obj.ptr) {
        (*this->refCount)++;        // increment the refCount
    }
}


template <typename T>
SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer<T> &obj) {
    this->ptr = obj.ptr;
    this->refCount = obj.refCount;
    if (nullptr != obj.ptr) {
        (*this->refCount)++;
    }
}


template <typename T>
T* SharedPointer<T>::operator->() const {
    return this->ptr;
}


template <typename T>
T& SharedPointer<T>::operator*() const {
    return this->ptr;
}


template <typename T>
T *SharedPointer<T>::get() {
    return this->ptr;
}


template <typename T>
unsigned int SharedPointer<T>::get_count() const {
    return *refCount;
}


template <typename T>
SharedPointer<T>::SharedPointer(SharedPointer &&dyingObj) {
    this->ptr = dyingObj.ptr;
    this->refCount = dyingObj.refCount;

    dyingObj.ptr = dyingObj.refCount = nullptr; // clean the dying object
}


template <typename T>
SharedPointer<T> &SharedPointer<T>::operator=(SharedPointer &&dyingObj) {
    __cleanup__();

    this->ptr = dyingObj.ptr;
    this->refCount = dyingObj.refCount;

    dyingObj.ptr = dyingObj.refCount = nullptr; // clean the dying object
}


template <typename T>
SharedPointer<T>::~SharedPointer() {
    __cleanup__();
}


template <typename T>
void SharedPointer<T>::__cleanup__() {
    (*refCount)--;
    if (*refCount == 0) {
        if (nullptr != ptr)
            delete ptr;
        delete refCount;
    }
}