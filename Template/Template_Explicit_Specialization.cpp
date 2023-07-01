/*
명시적 특수화 예제
구조체를 교환하는 세가지 형식의 함수 원형을 비교한 예제

C++에서는 하나의 구조체를 다른 하나의 구조체에 대입이 가능하기 때문에  void Swap(Any& a, Any& b); 에서도 그냥 넣으면 잘 돌아가지만 
상황에 따라서 구조체에서 name은 변경하고 싶지 않고 다른 나머지만 바꿀 경우 명시적으로 template <> void Swap<job>(job& j1, job& j2);
를 사용한다고 적어줘야 된다. 
(template <> void Swap<job>(job& j1, job& j2); 을 주석처리 하고 실행해 봐라 그러면 name도 포함한 구조체 전부가 바뀐다)

여기서 <job>은 생략이 가능하다 -> 함수 전달인자의 데이터형이 알려주기 때문
*/
#include <iostream>

using namespace std;

template <class Any>
void Swap(Any& a, Any& b);

struct job {
	char name[40];
	double salary;
	int floor;
};

//명시적 특수화
template <> void Swap<job>(job& j1, job& j2);
void Show(job& j);

int main(void) {
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i, j = " << i << ", " << j << "\n";
	cout << "컴파일러가 생성한 int형 교환기를 사용한다면\n";
	Swap(i, j);
	cout << "이제 i, j = " << i << ", " << j << "\n";

	job sue = { "Susan Yaffee", 73000.60, 7 };
	job sidney = { "Sidney Taffee", 78060.72, 9 };
	cout << "job 교환 전: \n";
	Show(sue);
	Show(sidney);
	Swap(sue, sidney);
	cout << "job 교환 후\n";
	Show(sue);
	Show(sidney);

	return 0;
}

template <class Any>
void Swap(Any& a, Any& b) {
	Any temp;
	
	temp = a;
	a = b;
	b = temp;
}

template <> void Swap<job>(job& j1, job& j2) {
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;

	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;

}

void Show(job& j) {
	cout << j.name << ": (" << j.floor << "층에 거주) "
		<< "$" << j.salary << '\n';
}
