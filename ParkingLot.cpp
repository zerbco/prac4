#include "ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int capacity) : maxCapacity(capacity), currentCount(0) {
    vehicles.reserve(capacity);
}

int ParkingLot::getCount() const{
    return currentCount;
}

bool ParkingLot::parkVehicle(Vehicle*vehicle) {
    if (currentCount >= maxCapacity){
        std::cout << "The lot is full" << std::endl;
        return false;
    }

    vehicles.push_back(vehicle);
    currentCount++;
    return true;
}

bool ParkingLot::unparkVehicle(int id) {
    for (auto it = vehicles.begin (); it != vehicles.end(); ++it) {
        if ((*it)->getID() == id) {
            delete *it;
            vehicles.erase(it);
            currentCount--;
            return true;
        }
    }

    std::cout << "Vehicle not in the lot" << std::endl;

    return false;
}

int ParkingLot::countOverstayingVehicles(int maxParkingDuration) const {
    int count = 0;
    for (const auto& vehicle : vehicles) {
        if (vehicle -> getParkingDuration() > maxParkingDuration) {
            count++;
        }
    }
    return count;
}

ParkingLot::~ParkingLot() {
    for (auto& vehicle : vehicles) {
        delete vehicle;
    }
}