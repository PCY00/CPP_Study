#include <iostream>
#include "Exp.h"

using namespace std;

Exp::Exp():Exp(1){ }
Exp::Exp(int a) {
	this->base = a;
	this->exp = 1;
	this->value = 1;
}
Exp::Exp(int a, int b) {
	this->base = a;
	this->exp = b;
	this->value = 1;
}
int Exp::getValue() {
	for (int i = 0; i < this->exp; i++) {
		this->value *= this->base;
	}
	return this->value;
}
int Exp::getBase() {
	return this->base;
}
int Exp::getExp() {
	return this->exp;
}
bool Exp::equals(Exp a) {
	if (this->value == a.value) {
		return true;
	}
	return false;
}