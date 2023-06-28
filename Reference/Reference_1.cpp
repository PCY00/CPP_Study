#include <iostream>

using namespace std;

//#define SQUARE(X) X*X
//inline double square(double x) { return x * x; }

int main(void) {
	int rats = 101;
	int& rodents = rats;

	cout << "rats = " << rats << ", rodents = " << rodents << '\n';
	//참조자가 변경이 될까?
  int b = 50;
  rodents = b;
	cout << "rats = " << rats << ", rodents = " << rodents << '\n';

	cout << "rats의 주소 : " << &rats << ", rodents의 주소 = " << &rodents << ", b의 주소 = " << &b << '\n';
	return 0;
}
//결론 한번 누군가를 참조하면 참조의 대상을 바꿀수 없음.
