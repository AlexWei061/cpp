#ifndef __GIRAFFE_H__
#define __GIRAFFE_H__

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class giraffe
{
private:
    /*walk length*/
    /*myVector each time increase space length*/
    #define WALK_LENGTH 64;
 
public:
    /*default constructor*/
    giraffe():array(0), theSize(0), theCapacity(0){    }
    giraffe(const T& t, unsigned int n):array(0), theSize(0), theCapacity(0){
        while(n--){
            push_back(t);
        }
    }
 
    /*copy constructor*/
    giraffe(const giraffe<T>& other):array(0),theSize(0),theCapacity(0){
        *this = other;
    }
 
    /*= operator*/
    giraffe<T>& operator = (giraffe<T>& other){
        if(this == &other)
            return *this;
        clear();
        theSize = other.size();
        theCapacity = other.capacity();
        array = new T[theCapacity];
        for(unsigned int i = 0 ; i < theSize; ++i)
        {
            array[i] = other[i];
        }
        return *this;
    }
 
    /*destructor*/
    ~giraffe(){
        clear();
    }
 
    /*the pos must be less than myVector.size();*/
    T& operator[](unsigned int pos){
        assert(pos < theSize);
        return array[pos];
    }
 
    /*element theSize*/
    unsigned int size(){
        return theSize;
    }
 
    /*alloc theSize*/
    unsigned int capacity(){
        return theCapacity;
    }
    
    /*is  empty*/
    bool empty(){
        return theSize == 0;
    }
 
    /*clear myVector*/
    void clear(){
        deallocator(array);
        array = 0;
        theSize = 0;
        theCapacity = 0;
    }
 
    /*adds an element in the back of myVector*/  
    void push_back(const T& t){
        insert_after(theSize - 1, t);
    }
 
    /*adds an element int the front of myVector*/
    void push_front(const T& t){
        insert_before(0, t);
    }
 
    /*inserts an element after the pos*/
    /*the pos must be in [0,theSize);*/
    void insert_after(int pos, const T& t){
        insert_before(pos + 1, t);
    }
 
    /*inserts an element before the pos*/
    /*the pos must be less than the myVector.size()*/
    void insert_before(int pos, const T& t){
        if(theSize == theCapacity){
            T* oldArray = array;
            theCapacity += WALK_LENGTH;
            array = allocator(theCapacity);
            /*memcpy(array,oldArray,theSize*sizeof(T)):*/
            for(unsigned int i = 0 ; i < theSize; ++i){
                array[i] = oldArray[i];
            }
            deallocator(oldArray);
        }
 
        for(int i = (int)theSize++; i > pos; --i){
            array[i] = array[i - 1];
        }
        array[pos] = t;
    }
 
    /*erases an element in the pos;*/
    /*pos must be in [0,theSize);*/
    void erase(unsigned int pos){
        if(pos < theSize){
            --theSize;
            for(unsigned int i = pos; i < theSize; ++i){
                array[i] = array[i + 1];
            }
        }
    }
 
private:
    T*  allocator(unsigned int size){
        return new T[size];
    }
 
    void deallocator(T* arr){
        if(arr)
            delete[] arr;
    }
private:
    T*                array;
    unsigned int    theSize;
    unsigned int    theCapacity;
};
 
void printfgiraffe(giraffe<int>& giraffe_array1){
    for(unsigned int i = 0 ; i < giraffe_array1.size(); ++i){
        cout << giraffe_array1[i] << ",";
    }
    cout << "alloc size = " << giraffe_array1.capacity() << ",size = " << giraffe_array1.size() << endl;
}
#endif
