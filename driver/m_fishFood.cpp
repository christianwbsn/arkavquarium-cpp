#include "../src/FishFood.hpp"
#include <iostream>
using namespace std;

int main() {
	FishFood food1; cout << "Food 1 constructor called" << endl;
	FishFood food2; cout << "Food 2 constructor called" << endl;
	FishFood food3(100.0, 100.0); cout << "Food 3 constructor called" << endl;
	food2 = food3;
	cout << endl;

	cout << "Food 1 X Position: " << food1.getXPos() << endl;
	cout << "Food 1 Y Position: " << food1.getYPos() << endl;
	food1.move(100);
	cout << "Food 1 moved" << endl;
	cout << "Food 1 X Position: " << food1.getXPos() << endl;
	cout << "Food 1 Y Position: " << food1.getYPos() << endl;
	cout << endl;
	
	cout << "Food 2 X Position: " << food2.getXPos() << endl;
	cout << "Food 2 Y Position: " << food2.getYPos() << endl;
	food2.move(100);
	cout << "Food 2 moved" << endl;
	cout << "Food 2 X Position: " << food2.getXPos() << endl;
	cout << "Food 2 Y Position: " << food2.getYPos() << endl;
	cout << endl;
	
	cout << "Food 3 X Position: " << food3.getXPos() << endl;
	cout << "Food 3 Y Position: " << food3.getYPos() << endl;
	food3.move(100);
	cout << "Food 3 moved" << endl;
	cout << "Food 3 X Position: " << food3.getXPos() << endl;
	cout << "Food 3 Y Position: " << food3.getYPos() << endl;
	cout << endl;
	
	return 0;
}
