#include <iostream>
#include <unistd.h>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include "ParkingLot.h"
using namespace std;

int main() {
    ParkingLot parkingLot(10);

    for (int i = 0 ; i < 5; ++i) {
        Vehicle* car = new Car(i + 1);
        if (!parkingLot.parkVehicle(car)) {
            delete car;
            break;
        } 
        sleep(1);
    }

    for (int i = 0; i < 3; ++i) {
        Vehicle *bus = new Bus(i + 6);
        if (!parkingLot.parkVehicle(bus)) {
            delete bus;
            break;
        }
        sleep(1);
    }

    for (int i = 0; i < 2; i++) {
        Vehicle *bike = new Motorbike(i + 9);
        if (!parkingLot.parkVehicle(bike)) {
            delete bike;
            break;
        }
        sleep(1);
    }

    cout << "Waiting for 16 seconds.." << endl;
    sleep(16);

    int overstayingVehicles = parkingLot.countOverstayingVehicles(15);
    cout << "Number of vehicles that have overstayed for more than 15 seconds: " << overstayingVehicles << endl;

    return 0;
}