#include <iostream>
#include "LinkedList.hpp"
using namespace std;

int main(){
    LinkedList<int> L1;
    int a = 1;
    cout<< L1.isEmpty() << endl;
    L1.add(1);
    L1.add(2);
    L1.add(3);
    L1.add(4);
    L1.add(5);
    L1.add(6);
    L1.add(4);
    L1.remove(a);
    cout << "Bener gak ya " << L1.getFirst().data << endl;
    cout << L1.isEmpty() << endl;
    cout << "Posisi angka 3: " << L1.find(3) << endl;
    cout << "Isi index ke 3: " << L1.get(3) << endl;
    L1.printList();
    return 0;
}