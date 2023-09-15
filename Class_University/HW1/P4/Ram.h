#ifndef RAM_H
#define RAM_H

class Ram {
public:
	Ram();
	~Ram();
	char read(int address);
	void write(int address, char value);
private:
	char mem[100 * 1024];
	int size;
};

#endif