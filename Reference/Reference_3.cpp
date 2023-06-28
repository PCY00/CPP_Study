/*
  구조체에 대한 참조
*/
#include <iostream>

using namespace std;

struct sysop {
	char name[26];
	char quote[64];
	int used;
};

//참조를 리턴하는 함수
//앞에 const가 붙은 이유 -> sysop 구조체 자체가 const라는 것을 의미하는 것은 아니고 단지 그 구조체를 변경하는 데 리턴값을 직접 사용할 수 없다는 것을 의미한다.
//따라서 const를 생략하면 짧지만 더 모호해 보이는 코드가 작성되고, 모호한 코드는 모호한 에러를 일으킬 기회가 높기때문에 const사용
const sysop& use(sysop& sysopref);

int main(void) {
	//참고 : 어떤 시스템에서는 아래 두 구조체의 선언에 static 키워드를 사용해야만 초기화를 할 수 있다.
	sysop looper = {
		"Rick \"Fortran\" Looper",
		"I'm a goto kind of guy.",
		0
	};

	use(looper);
	cout << "Looper: " << looper.used << "번 사용\n";
	sysop copycat;
	copycat = use(looper);
	cout << "Looper: " << looper.used << "번 사용\n";
	cout << "Copycat: " << copycat.used << "번 사용\n";
	cout << "use(looper): " << use(looper).used << "번 사용\n";
	return 0;
}

//sysopref를 불러오지만 실제론 looper가 수정됨 (참조)
//또한 함수가 사라질때 사용되는 임시 변수를 리턴하지마라 -> 지역변수같은거
const sysop& use(sysop& sysopref) {
	cout << sysopref.name << " says:\n";
	cout << sysopref.quote << '\n';
	sysopref.used++;
	return sysopref;
}
