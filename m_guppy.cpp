#include "Guppy.hpp"
#include <iostream>
using namespace std;

int main() {
	Guppy gup1;
	Guppy gup2;
	gup2 = gup1;

	cout << "Initial Size: " << gup1.getSize() << endl;
	cout << "Coin Time: " << gup1.getCoinTime() << endl;
	gup1.setCoinTime(2.0);
	cout << "Coin Time changed to: " << gup1.getCoinTime() << endl;
	cout << "Coin Value: " << gup1.getCoinValue() << endl;
	gup1.eatFood();
	cout << "Food eaten" << endl;
	gup1.grow();
	cout << "Guppy grew" << endl;
	gup1.extractCoin();
	cout << "Coin extracted" << endl;
	
	return 0;
}
