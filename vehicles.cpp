#include <iostream>

enum class MovementType {
    Surface,
    Air,
    Floating
};

class Vehicle {
public:
    Vehicle():
        num_wheels(0),
        needs_registration(false),
        is_civillian(true),
        movement_type(MovementType::Surface) {
        std::cout << "Creating Vehicle.." << std::endl;
    }

    ~Vehicle() {
        std::cout << "Deleting Vehicle.." << std::endl;
    }

    virtual void description() { // can be overrided
        std::cout << "This is vehicle with " << num_wheels
            << " wheels" << std::endl;
    }

protected:
    int num_wheels;
    bool needs_registration;
    bool is_civillian;
    MovementType movement_type;
};

class Bike: public Vehicle {
public:
    Bike() {
        std::cout << "Creating Bike.." << std::endl;
        num_wheels = 2;
    }

    ~Bike() {
        std::cout << "Deleting Bike.." << std::endl;
    }
};

class Car: public Vehicle {
public:
    Car(int num_seats = 5):
        num_seats(num_seats) {
        std::cout << "Creating Car.." << std::endl;
        num_wheels = 4;
        needs_registration = true;
    }

    virtual void description() override { // overrides
        std::cout << "This is car with " << num_wheels <<
            " wheels and " << num_seats << " seats" <<
                std::endl;
    }

    ~Car() {
        std::cout << "Deleting Car.." << std::endl;
    }

protected:
    int num_seats;
};

class Truck: public Car {
public:
    Truck(int cargo, int seats): Car(seats), cargo_load(cargo) {
        std::cout << "Creating Truck.." << std::endl;
        num_wheels = 6;
    }

    virtual void description() override final { // no more overrides
        std::cout << "This is truck with " << num_wheels <<
            " wheels and " << num_seats << " seats and " <<
            cargo_load << " cargo" <<
                std::endl;
    }

    ~Truck() {
        std::cout << "Deleting Truck.." << std::endl;
    }

protected:
    int cargo_load;
};

int main() {
    /*
    Bike b;
    b.description();

    Car c;
    c.description();

    Truck t;
    t.description();
    */

    auto vehicles = new Vehicle*[5];

    Bike b;
    Car c(4);
    Truck t(5000, 3);

    vehicles[0] = &b;
    vehicles[1] = &c;
    vehicles[2] = &t;

    for (auto i = 0; i < 3; i++) {
        std::cout << "Item #" << i << ":\n";
        vehicles[i]->description();
    }

}
