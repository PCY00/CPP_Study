

#include <iostream>
using namespace std;

// 추상 클래스 Vehicle 정의
class Vehicle {
public:
    virtual void move() { } // 순수 가상 함수
};

// Car 클래스 정의
class Car : public Vehicle {
public:
    virtual void move() override {
        cout << "Drive" << endl;
    }
};

// Bike 클래스 정의
class Bike : public Vehicle {
public:
    virtual void move() override {
        cout << "Ride" << endl;
    }
};

// Boat 클래스 정의
class Boat : public Vehicle {
public:
    virtual void move(){
        cout << "Sail" << endl;
    }
};

int main() {
    Car car;
    Bike bike;
    Boat boat;

    car.move();
    bike.move();
    boat.move();

    return 0;
}
