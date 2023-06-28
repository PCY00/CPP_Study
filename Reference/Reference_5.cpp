/*
 ostream, ofstream 클래스 참조 사용해보기
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream& os, double fo, const double fe[], int n);
const int LIMIT = 5;

int main(void) {
	ofstream fout;
	const char* fn = "ep-data.txt";
	fout.open(fn);
	if (!fout.is_open()) {
		cout << fn << " 파일을 열 수 없습니다. 끝.\n";
		exit(EXIT_FAILURE);
	}
	double objective;
	cout << "대물렌즈 초첨거리를 "
		"mm 단위로 입력하시오: ";
	cin >> objective;
	double eps[LIMIT];
	cout << LIMIT << "가지 대안렌즈의 초점거리를 "
		"mm 단위로 입력하십시오:\n";
	for (int i = 0; i < LIMIT; i++) {
		cout << "대안렌즈 #" << i + 1 << ": ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);
	file_it(cout, objective, eps, LIMIT);
	cout << "종료\n";

	return 0;
}

void file_it(ostream& os, double fo, const double fe[], int n) {
	//정보를 저장하는 데 필요한 데이터형의 장식적 이름
	ios_base::fmtflags initial;
	//소숫점 고정
	initial = os.setf(ios_base::fixed); // 초기 포맷팅 상태 저장
	os.precision(0);
	os << "대물렌즈의 초점거리: " << fo << " mm\n";
	//뒤따르는 숫자들이 0인 경우에도 뒤에 붙은 소수점을 표시하는 모드로 객체를 설정
	os.setf(ios::showpoint);
	//소수점의 오른쪽에 표시할 숫자들의 개수를 지정
	os.precision(1);
	//필드의 대여폭을 설정
	os.width(17);
	os << "대물렌즈의 초점거리";
	os.width(15);
	os << "확대배율" << '\n';
	for (int i = 0; i < n; i++) {
		os.width(17);
		os << fe[i];
		os.width(15);
		os << int(fo / fe[i] + 0.5) << '\n';
	}

	os.setf(initial);	//초기 포맷팅 상태 복원
}
