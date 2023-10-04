#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Book {
	char* title;
	int price;
public:
	Book(const char* title, int price);
	~Book();
	void set(const char* title, int price);
	void show() { cout << title << ' ' << price << "원" << '\n'; }
};

Book::Book(const char* title, int price) {
	this->price = price;
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
}

Book::~Book() {
	if (title) {
		delete[] title;
	}
}

void Book::set(const char* title, int price) {
	this->price = price;
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
}

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
	return 0;
}