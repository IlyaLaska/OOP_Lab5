//
// Created by illya on 11/14/2018.
//

#ifndef OOP_LAB4_LIST_H
#define OOP_LAB4_LIST_H

#include <string>

#include "macros.h"

//#include <stdexcept>

//#include <iostream>
//using namespace std;

struct amountList {
    std::string name{};
    int amount = 0;
};

struct priceList {
    std::string name{};
    int price = 0;
};

struct selectionList {
    std::string name{};
    bool flag = false;
};

//template <class T>
//class List {
//private:
//public:
//    int length = 0;
//    int size = 0;
//    T* list = new T[length];
//    List() = default;
//    explicit List(int length);
//    const T operator[](int pos) const;
//    T& operator[](int pos);
//    void push(T value);
//
//};
//
//template<class T>
//List<T>::List(int length) {
//    this->length = length;
//    this->list = new T[length];
//}
//
//
//template<class T>
//const T List<T>::operator[](int pos) const {
////    cout << "[] operator called!" << endl;
//    if(pos < 0) {
//        throw std::out_of_range("Keep your dirty hands off of negative indexes, git!");
//    } else if(pos >= length) {
//        throw std::out_of_range("Keep your dirty hands off of excessively large indexes, git!");
//    }
//    return this->list[pos];
//}
//
//template<class T>
//T& List<T>::operator[](int pos) {
////    cout << "[] operator called!" << endl;
//    if(pos < 0) {
////        std::cout << "Keep your dirty hands off of negative elements, git!" << std::endl;
//        throw std::out_of_range("Keep your dirty hands off of negative elements, git!");
////        T temp = T{};
////        cout << temp << endl;
////        return temp;
//    } else if(pos >= length) {
//        int newLength = pos+length;
//        T* newList = new T[newLength];
//        for (int i = 0; i < length; ++i) {
//            newList[i] = list[i];
//        }
////        for (int j = length; j < newLength; ++j) {
////            newList[j] = T{};
////        }
//        this->length = newLength;
//        this->list = newList;
//    }
//    if(size <= pos) {
//        size = pos+1;
//    }
//    return this->list[pos];
//}
//
//template<class T>
//void List<T>::push(T value) {
//    if(size >= length) {
//        int newLength = length*2;
//        T* newList = new T[newLength];
//        for (int i = 0; i < length; ++i) {
//            newList[i] = list[i];
//        }
//        this->length = newLength;
//        this->list = newList;
//
//    }
//    list[size] = value;
//    size++;
//}
//

#endif //OOP_LAB4_LIST_H

