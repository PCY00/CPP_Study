/*
템플릿 오버로딩
교환하는 함수
*/
#include <iostream>

using namespace std;

template <class Any>
void Swap(Any& a, Any& b);

template <class Any>
void Swap(Any a[], Any b[], int c);

void Show(int a[]);
const int Lim = 8;

int main(void) {
	int i = 10, j = 20;
	cout << "i, j = " << i << ", " << j << '\n';
	cout << "컴퍼일러가 생성한 int형 교환기를 사용하면\n";
	Swap(i, j);
	cout << "이제 i, j = " << i << ", " << j << '\n';

	int d1[Lim] = { 0,7,0,4,1,7,7,6 };
	int d2[Lim] = { 0,6,2,0,1,9,6,9 };
	cout << "원본 배열\n";
	Show(d1);
	Show(d2);
	//템플렛 오버로딩된 함수
	Swap(d1, d2, Lim);
	cout << "교환된 배열:\n";
	Show(d1);
	Show(d2);

	return 0;
}

template <class Any>
void Swap(Any& a, Any& b) {
	Any temp;

	temp = a;
	a = b;
	b = temp;
}

template <class Any>
void Swap(Any a[], Any b[], int c) {
	Any temp;
	for (int i = 0; i < c; i++) {
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void Show(int a[]) {
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";
	for (int i = 4; i < Lim; i++) {
		cout << a[i];
	}
	cout << '\n';
}
