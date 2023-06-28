/*
스왑을 할때 참조와 포인터는 바뀌지만  변수 전달은 바뀌지 않음을 실험함
이유는 참조와 포인터는 실제 메모리 주소에 접근하여 값을 변경하고, 변수만 전달하는 함수는 함수 안에서만 스왑이 일어나고 함수 밖으로 돌아오면
다시 원래 상태로 돌아감
*/

#include <iostream>

using namespace std;

void swapr(int& a, int& b);
void swapp(int* p, int* q);
void swapv(int a, int b);

int main(void) {
	int wallet1 = 3000;
	int wallet2 = 3500;

	cout << "현재 지갑 1 = " << wallet1 << "원, " << "지갑 2 = " << wallet2 << "원\n";

	cout << "참조를 이용하여 내용들을 교환: ";
	swapr(wallet1, wallet2);
	cout << "지갑 1 = " << wallet1 << ", 지갑 2 = " << wallet2 << "원\n\n";

	cout << "현재 지갑 1 = " << wallet1 << "원, " << "지갑 2 = " << wallet2 << "원\n";
	cout << "포인터를 이용하여 내용들을 교환: ";
	swapp(&wallet1, &wallet2);
	cout << "지갑 1 = " << wallet1 << ", 지갑 2 = " << wallet2 << "원\n\n";

	cout << "현재 지갑 1 = " << wallet1 << "원, " << "지갑 2 = " << wallet2 << "원\n";
	cout << "변수를 이용하여 내용들을 교환: ";
	swapv(wallet1, wallet2);
	cout << "지갑 1 = " << wallet1 << ", 지갑 2 = " << wallet2 << "원\n\n";
	return 0;
}

void swapr(int& a, int& b) {
	int temp;

	temp = a;
	a = b; 
	b = temp;
}

void swapp(int* p, int* q) {
	int temp;

	temp = *p;
	*p = *q;
	*q = temp;
}

void swapv(int a, int b) {
	int temp;

	temp = a;
	a = b;
	b = temp;
}
