#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << '\n';
	string s;
	srand((unsigned)time(0));
	while (1) {
		cout << ">>";
		getline(cin, s, '\n');
		// 길이 안에서의 변경 자리 랜덤
		int n = (rand() % s.length()) - 1;
		//소문자 알파벳 랜덤
		char m = (rand() % 26) + 97;

		if (s == "exit") {
			return 0;
		}

		//글자가 아닌 빈칸을 바꿀 경우
		if (s[n] == ' ' && s[0]) {
			s[n + 1] = m;
		}
		else if (s[n] == ' ' && s[s.length() - 1]) {
			s[n - 1] = m;
		}
		else {
			s[n] = m;
		}
		cout << s << '\n';
	}
	return 0;
}