#include <iostream>
#include <string>

using namespace std;

class Person {
	string name;
	string tel;
public:
	Person();
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};

Person::Person() {

}

void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}

int main() {
	cout << "이름과 전화번호를 입력해 주세요" << '\n';
	Person *p = new Person [3];
	string findName;
	for (int i = 0; i < 3; i++) {
		string name, pn;
		cout << "사람 " << i + 1 << ">> ";
		cin >> name >> pn;
		p[i].set(name, pn);
	}
	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < 3; i++) {
		cout << ' ' << p[i].getName();
	}
	cout << '\n';
	while (1) {
		cout << "전화번호를 검색합니다. 이름을 입력하세요>>";
		cin >> findName;
		for (int i = 0; i < 3; i++) {
			if (findName == p[i].getName()) {
				cout << "전화번호는 " << p[i].getTel();
				delete[] p;
				return 0;
			}
			else {
				cout << "이름을 정확히 기재해 주세요." << '\n';
				break;
			}
		}
	}
}