#include "../src/LinkedList.hpp"
#include <iostream>
using namespace std;

int main(){
    LinkedList<int> L1;
    int a = 4;
    cout<< L1.isEmpty() << endl;
    L1.add(a);
    L1.add(2);
    L1.add(3);
    L1.add(4);
    L1.add(5);
    L1.add(6);
    L1.add(4);
    cout << "Data pertama: " << L1.getFirst().data << endl;
    cout << "Apakah kosong: " << L1.isEmpty() << endl;
    cout << "Posisi angka 3: " << L1.find(3) << endl;
    cout << "Isi index ke 3: " << L1.get(3) << endl;
    cout << "Ukurannya: " << L1.getSize() << endl;
    L1.printList();
    return 0;
}
