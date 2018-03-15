//  File: LinkedList.hpp

#ifndef __LINKEDLIST__HPP
#define __LINKEDLIST__HPP

#include <iostream>
using namespace std;

template<class T>
struct node {
	node<T>* next;
	T data;
};

template<class T>
class LinkedList{
public:
	node<T>* first;
    node<T>* last;

    // Constructor LinkedList
    LinkedList<T>();
    // Mengembalikan nilai True jika linked list kosong dan false jika sebaliknya
    bool isEmpty();
    // Method ini mengembalikan indeks dimana elemen berada pada linked list dan -1 jika tidak ada
    int find(T element);
    // Method ini menambahkan elemen sebagai elemen paling belakang pada LinkedList
    void add(T element);
    // Method ini membuang elemen dengan identitas demikian
    void remove(T& element);
    // Method ini mengembalikan elemen dengan tipe T pada indeks ke-i.
    T get(int index);
};

#endif