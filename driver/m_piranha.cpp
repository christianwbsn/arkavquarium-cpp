#include "../src/Piranha.hpp"
#include <iostream>
using namespace std;

int main() {
	Piranha pir1;
	Piranha pir2;
	pir2 = pir1;

	pir1.eatFood();
	cout << "Food eaten" << endl;
	pir1.extractCoin(1);
	cout << "Coin extracted" << endl;
	
	return 0;
}
