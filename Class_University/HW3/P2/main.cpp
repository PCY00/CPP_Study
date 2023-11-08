
#include <iostream>

using namespace std;

class Animal {
public:
	virtual void speak() { }
};

class Dog : public Animal {
	virtual void speak() { cout << "Bark" << '\n'; }
};

class Cat : public Animal{
	virtual void speak() { cout << "Meow" << '\n'; }
};

int main() {
	Animal* animal;
	
	Dog dog;
	Cat cat;

	animal = &dog;
	animal->speak();

	animal = &cat;
	animal->speak();

	return 0;
}