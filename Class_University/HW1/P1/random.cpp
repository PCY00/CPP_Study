#include <iostream>
#include <cstdlib>
#include <ctime>
#include "random.h"

using namespace std;

random::random() {
	srand((unsigned)time(0));
}

int random::next() {
	return rand();
}

int random::nextInRange(int a, int b) {
	return rand() % (b - a + 1) + a;
}