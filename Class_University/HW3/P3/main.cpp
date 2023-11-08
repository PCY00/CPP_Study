
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Vehicle {
protected:
    Vehicle* next;
    int* num;

public:
    Vehicle() {
        next = nullptr;
        num = nullptr;
    }

    virtual ~Vehicle() {
        delete[] num;
    }

    virtual void getType() {
        cout << "Vehicle" << endl;
    }

    Vehicle* add(Vehicle* p) {
        this->next = p;
        return p;
    }

    Vehicle* getNext() {
        return next;
    }
};

class Car : public Vehicle {
public:
    Car() {
        num = new int[4];
        for (int i = 0; i < 4; i++) {
            num[i] = rand() % 10;
        }
    }

    virtual void getType() {
        cout << "Car" << endl;
    }

    ~Car() {
        cout << num[0] << num[1] << num[2] << num[3] << " Car 소멸" << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike() {
        num = new int[4];
        for (int i = 0; i < 4; i++) {
            num[i] = rand() % 10;
        }
    }

    virtual void getType() {
        cout << "Bike" << endl;
    }

    ~Bike() {
        cout << num[0] << num[1] << num[2] << num[3] << " Bike 소멸" << endl;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    int numVehicles = rand() % 6 + 5;
    cout << numVehicles << "개 생성" << endl;

    Vehicle* head = nullptr;
    Vehicle* tail = nullptr;

    for (int i = 0; i < numVehicles; i++) {
        Vehicle* vehicle;
        if (rand() % 2 == 0) {
            vehicle = new Car();
        }
        else {
            vehicle = new Bike();
        }

        if (tail == nullptr) {
            head = vehicle;
            tail = vehicle;
        }
        else {
            tail = tail->add(vehicle);
        }
    }

    Vehicle* current = head;
    int index = 0;

    while (current != nullptr) {
        current->getType();
        current = current->getNext();
        index++;
    }

    // 추가된 부분: 교통수단 소멸시 번호판 출력
    current = head;
    while (current != nullptr) {
        current->~Vehicle();
        current = current->getNext();
    }

    return 0;
}
