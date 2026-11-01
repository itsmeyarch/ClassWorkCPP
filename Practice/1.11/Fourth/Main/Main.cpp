#include <iostream>
#include <typeinfo>
#include "Vehicle.h"
#include "Car.h"
#include "Bicycle.h"

int main()
{
    Car car;
    Bicycle bicycle;

    Vehicle* vehicles[2];

    vehicles[0] = &car;
    vehicles[1] = &bicycle;

    for (int i = 0; i < 2; i++) {
        if (typeid(*vehicles[i]) == typeid(car)) {
            std::cout << "Car\n";
        }
        else {
            std::cout << "Bicycle\n";
        }
    }
}
