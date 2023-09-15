#include <iostream>
#include "SelectableRandom.h"

using namespace std;

int main() {
	cout << "20191546 박찬영" << '\n' << '\n';
	SelectableRandom r;
	cout << ".. 0에서 " << RAND_MAX << "까지의 랜덤 짝수 정수 10개--" << '\n';
	for (int i = 0; i < 10; i++) {
		int n = r.even_number();
		cout << n << ' ';
	}
	cout << '\n' << '\n' << "--2에서 " << "9 까지의 랜덤 홀수 정수 10개 -- " << '\n';
	for (int i = 0; i < 10; i++) {
		int n = r.odd_number(2, 9);
		cout << n << ' ';
	}
	cout << '\n';
	return 0;
}