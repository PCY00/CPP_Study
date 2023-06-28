/*
 참조함수에서 함수내에 선언된 지역변수를 리턴하는 경우 오류를 보여주는 예
*/

#include <iostream>
#include <string>

using namespace std;

string version1(const string& s1, const string& s2);
//부수 효과
const string & version2(string& s1, const string& s2);
//나쁜 설계
const string& version3(string& s1, const string& s2);

int main(void) {
	string input;
	string copy;
	string result;

	cout << "문자열을 입력하시오: ";
	getline(cin, input);
	copy = input;
	cout << "입려간 문자열: " << input << '\n';
	result = version1(input, "***");
	cout << "바뀐 문자열: " << result << '\n';
	cout << "원래 문자열: " << input << '\n';

	result = version2(input, "###");
	cout << "바뀐 문자열: " << result << '\n';
	cout << "원래 문자열: " << input << '\n';

	//여기는 실행이 잘 안됨
	cout << "원래문자열 재설정\n";
	input = copy;
	//여기서 오류 발생
	//더 이상 사용되지 않는 메모리를 참조하려 시도하기 때문에
	result = version3(input, "@@@");
	cout << "바뀐 문자열: " << result << '\n';
	cout << "원래 문자열: " << input << '\n';

	return 0;
}

string version1(const string& s1, const string& s2) {
	string temp;
	temp = s2 + s1 + s2;
	return temp;
}

const string& version2(string& s1, const string& s2) {
	s1 = s2 + s1 + s2;
	return s1;
}

//하면 안되는 코드 -> 지역 변수를 리턴
const string& version3(string& s1, const string& s2) {
	string temp;

	temp = s2 + s1 + s2;
	
	return temp;
}
