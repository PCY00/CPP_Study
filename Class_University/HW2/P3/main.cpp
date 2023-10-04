#include <iostream>

using namespace std;

char& find(char a[], char c, bool& success);

int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M을 발견할 수 없다" << '\n';
		return 0;
	}
	loc = 'm';
	cout << s << '\n';
}

char& find(char a[], char c, bool& success) {
	int i = 0;
	while (1) {
		if (a[i] == c) {
			success = true;
			return *(a+i);
		}
		i++;
	}
	success = false;
	return *(a+i);
}