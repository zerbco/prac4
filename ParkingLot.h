#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <vector>
#include "Vehicle.h"

class ParkingLot {
    private:
    std::vector<Vehicle*> vehicles;
    int maxCapacity;
    int currentCount;

    public:
    ParkingLot(int capacity);
    int getCount() const;

    bool parkVehicle(Vehicle*vehicle);

    bool unparkVehicle(int id);

    int countOverstayingVehicles(int maxParkingDuration) const;

    ~ParkingLot();
};

#endif