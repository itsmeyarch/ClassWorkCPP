#include <iostream>
#include <typeinfo>
#include "Vehicle.h"
#include "Car.h"

void CheckVehicle(Vehicle& vehicle) {
    try {
        Car& car =
            dynamic_cast<Car&>(vehicle);
        car.drive();
    }
    catch (const std::bad_cast& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
}

int main()
{
    Car car;
    Vehicle vehicle;

    CheckVehicle(car);
    CheckVehicle(vehicle);
}
