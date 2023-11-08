#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"

using namespace std;
int main() {
    srand(static_cast<unsigned>(time(0)));

    int numShapes = rand() % 6 + 5; // Randomly generate 5 to 10 shapes
    std::cout << numShapes << "개 도형 생성" << std::endl;

    Shape* head = nullptr;
    Shape* tail = nullptr;

    for (int i = 0; i < numShapes; i++) {
        Shape* shape;

        if (rand() % 3 == 0) {
            shape = new Circle();
        }
        else if (rand() % 3 == 1) {
            shape = new Line();
        }
        else {
            shape = new Rect();
        }

        if (tail == nullptr) {
            head = shape;
            tail = shape;
        }
        else {
            tail = tail->add(shape);
        }
    }

    Shape* current = head;
    int index = 0;

    while (current != nullptr) {
        std::cout << index << "번째 도형: ";
        current->paint();
        current = current->getNext();
        index++;
    }

    return 0;
}