#include <iostream>
#include "SelectableRandom.h"
#include <cstdlib>
#include <ctime>

using namespace std;

SelectableRandom::SelectableRandom(){ srand((unsigned)time(0)); }
int SelectableRandom::base() { return rand(); }
int SelectableRandom::odd_number() {
	int random = rand();
	if (random == 0 || random % 2 == 0) {
		return random + 1;
	}
	return random;
}
int SelectableRandom::even_number() {
	int random = rand();
	if (random % 2 != 0) {
		return random - 1;
	}
	return random;
}

int SelectableRandom::odd_number(int a, int b) {
	int random =  rand() % (b - a + 1) + a;
	if (random == 0 || random % 2 == 0) {
		return random + 1;
	}
	return random;
}
int SelectableRandom::even_number(int a, int b) {
	int random = rand() % (b - a + 1) + a;
	if (random % 2 != 0) {
		return random - 1;
	}
	return random;
}