#include <iostream>
#include "random.h"

using namespace std;

int main() {
	cout << "20191546 박찬영" << '\n' << '\n';
	random r;
	cout << ".. 0에서 " << RAND_MAX << "까지의 랜덤 정수 10개--" << '\n';
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << '\n' << '\n' << "--2에서 " << "4 까지의 랜덤 정수 10개 -- " << '\n';
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
	cout << '\n';
	return 0;
}