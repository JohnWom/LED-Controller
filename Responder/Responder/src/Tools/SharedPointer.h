//
// Created by johnw on 8/22/2023.
//

#ifndef RESPONDER_SHAREDPOINTER_H
#define RESPONDER_SHAREDPOINTER_H

/*
 * Light Implementation of std::shared_pointer for use in responder
*/

template <typename T>
class SharedPointer
{
public:
    SharedPointer();
    SharedPointer(T* ptr);

    SharedPointer(const SharedPointer &obj);            // Copy Constructor
    SharedPointer& operator=(const SharedPointer &obj); // Copy Assignment

    T* operator->() const;
    T& operator*() const;
    T* get();

    unsigned int get_count() const;

    SharedPointer(SharedPointer && dyingObj);            // Move Constructor
    SharedPointer& operator=(SharedPointer && dyingObj); // Move assignment

    ~SharedPointer();

private:
    void __cleanup__();
    T* ptr;
    unsigned int* refCount;
};


#endif //RESPONDER_SHAREDPOINTER_H
