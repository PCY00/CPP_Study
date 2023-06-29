/*
함수 템플릿을 사용하는 이유:
데이터형을 바꾸는 과정을 자동화하여 시간을 절약하고 코드의 신뢰성을 높여준다.
템플릿 사용 예시
template <class ???> | template <typename ???>
class와 typename은 오래된 키워드와 최신 키워드의 차이일 뿐 다른건 없다.
*/
#include <iostream>
using namespace std;

//함수 템플릿 원형
template <class Any>
void Swap(Any& a, Any& b);

int main(void) {
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << ", " << j << '\n';
	cout << "컴파일러가 생성한 int형 교환기를 사용하면\n";
	Swap(i, j);
	cout << "이제 i, j = " << i << ", " << j << '\n';

	double x = 24.5;
	double y = 81.7;
	cout << "x, y = " << x << ", " << y << '\n';
	cout << "컴파일러가 생성한 double형 교환기를 사용하면\n";
	Swap(x, y);
	cout << "이제 x, y = " << x << ", " << y << '\n';

	return 0;
}

//함수 템플릿 정의
template<class Any>
void Swap(Any& a, Any& b) {
	Any temp;

	temp = a;
	a = b;
	b = temp;
}
