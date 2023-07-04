/*
함수 오버로딩의 간단한 ex)
문자와 숫자를 하나씩 늘려가며 출력
*/
#include <iostream>
using namespace std;

unsigned long left(unsigned long num, unsigned ct);
char* left(const char* str, int n = 1);

int main(void) {
	const char* trip = "Hawaii!!";
	unsigned long n = 12345678;
	int i;
	char* temp;
	for (i = 1; i < 10; i++) {
		cout << left(n, i) << '\n';
		temp = left(trip, i);
		cout << temp << '\n';
		delete[] temp;
	}
	return 0;
}

unsigned long left(unsigned long num, unsigned ct) {
	unsigned digits = 1;
	unsigned long n = num;
	if (ct == 0 || num == 0) {
		return 0;
	}
	while (n /= 10) {
		digits++;
	}
	if (digits > ct) {
		ct = digits - ct;
		while (ct--) {
			num /= 10;
		}
		return num;
	}
	else {
		return num;
	}
}

char* left(const char* str, int n) {
	if (n < 0) {
		n = 0;
	}
	char* p = new char[n + 1];
	int i;
	for (i = 0; i < n && str[i]; i++) {
		p[i] = str[i];
	}
	while (i <= n) {
		p[i++] = '\0';
	}
	return p;
}
