#ifndef EXP_H
#define EXP_H

class Exp {
public:
	Exp();
	Exp(int a);
	Exp(int a, int b);
	int getValue();
	int getBase();
	int getExp();
	bool equals(Exp a);
private:
	int base;
	int exp;
	int value;
};

#endif