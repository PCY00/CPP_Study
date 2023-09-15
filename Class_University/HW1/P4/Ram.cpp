#include <iostream>
#include "Ram.h"

using namespace std;

Ram::Ram() {
	this->size = 100 * 1024;
	for (int i = 0; i < size; i++) {
		this->mem[i] = 0;
	}
}
Ram::~Ram() {
	cout << "메모리 제거됨" << '\n';
}
char Ram::read(int address) {
	return this->mem[address - 1];
}
void Ram::write(int address, char value) {
	this->mem[address - 1] = value;
}