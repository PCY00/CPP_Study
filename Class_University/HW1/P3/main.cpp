#include <iostream>
#include <string>

using namespace std;

class Integer {
public:
	Integer() : Integer(1) { }
	Integer(int r) {
		this->num = r;
	}
	Integer(string r) {
		this->num = stoi(r);
	}

	void set(int index) {
		this->num = index;
	}
	int get() {
		return this->num;
	}
	bool isEven() {
		return true;
	}
private:
	int num;
};

int main() {
	cout << "20191546 박찬영" << '\n' << '\n';
	Integer n(30);
	cout << n.get() << ' ';
	n.set(50);
	cout << n.get() << ' ';

	Integer m("300");
	cout << m.get() << ' ';
	cout << m.isEven();
	return 0;
}