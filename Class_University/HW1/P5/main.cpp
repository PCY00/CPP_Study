#include <iostream>
#include "Exp.h"

using namespace std;

int main() {
	cout << "20191546 박찬영" << '\n' << '\n';
	Exp a(3, 2);
	Exp b(9);
	Exp c;

	cout << a.getValue() << ' ' << b.getValue() << ' ' << c.getValue() << '\n';
	cout << "a의 베이스" << a.getBase() << ",지수 " << a.getExp() << '\n';

	if (a.equals(b)) {
		cout << "same" << '\n';
	}
	else {
		cout << "not same" << '\n';
	}
	return 0;
}