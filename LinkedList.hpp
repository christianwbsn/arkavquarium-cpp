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
private:
	node<T>* first;
    node<T>* last;
public:
    // Constructor LinkedList
    LinkedList<T>(){
        first = NULL;
        last = NULL;
    };

    node<T> getFirst(){
        return *first; 
    }
    node<T> getLast(){
        return *last; 
    }
    // Mengembalikan nilai True jika linked list kosong dan false jika sebaliknya
    bool isEmpty(){
        return first == NULL;
    }
    // Method ini mengembalikan indeks dimana elemen berada pada linked list dan -1 jika tidak ada
    int find(T element){
        node<T>* curr = first;
        int count = 0;
        bool found = false;
        while(!found && curr != NULL){
            if( curr->data == element ){
                found = true;
            } else {
                curr = curr->next;
            }
            count++;
        }
        if(curr->data == element){
            return count-1; 
        } else {
            return -1;
        }
    }
    // Method ini menambahkan elemen sebagai elemen paling belakang pada LinkedList
    void add(T element){
        if(!first) {
			first = new node<T>;
			first->data = element;
			first->next = NULL;
			last = first;
		} else {
			if(last == first) {
				last = new node<T>;
				last->data = element;
				last->next = NULL;
				first->next = last;
			} else {
				node<T>* insdata = new node<T>;
				insdata->data = element;
				insdata->next = NULL;
				last->next = insdata;
				last = insdata; 
			}
		}
	}
    // Method ini membuang elemen dengan identitas demikian
    void remove(T& element){
        node<T>* prec = NULL;
        node<T>* curr = first;
        node<T>* next;
        while(curr != NULL){
            next = curr->next;
            if(curr->data == element){
                if(prec == NULL){
                    first = next;
                } else {
                    prec->next = next;
                }
            } else {
                prec = curr;
            }
            curr = next;
        }
    }
    // Method ini mengembalikan elemen dengan tipe T pada indeks ke-i.
    T get(int index){
		if(index == 0) {
			// Get the first element
			return this->first->data;
		} else {
			// Get the index'th element
			node<T>* curr = this->first;
			for(int i = 0; i < index; ++i) {
				curr = curr->next;
			}
			return curr->data;
		}
    }
    
    void printList(){
        node<T>* curr=this->first;
        while(curr != NULL){
            cout << curr->data << endl;
            curr = curr->next;
        }
    }
};

#endif