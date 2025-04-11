#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include "ParkingLot.h"
using namespace std;

int main() {
    ParkingLot parkingLot(10);

    bool continueParking = true;

    while (continueParking && parkingLot.getCount() < 10) {
        int choice;
        cout << "Enter the type of vehicle(1 for Car, 2 for Bus , 3 for Motorbike, 0 to stop) :";
        cin >> choice;

        if (choice == 0) {
            continueParking = false;
            continue;
        }
        
        int id = parkingLot.getCount() + 1;
        Vehicle * vehicle = nullptr;

        switch (choice) {
            case 1:
            vehicle = new Car(id);
            break;

            case 2:
            vehicle = new Bus(id);
            break;

            case 3:
            vehicle = new Motorbike(id);
            break;

            default:
            cout << "Invalid Choice. Please try again! " << endl;
            continue;
        }

        bool parked = parkingLot.parkVehicle(vehicle);

        if (parked) {
            cout << "Vehicle with ID " << id << "parked successfully." << endl;
        } else {
            delete vehicle;
        }
    }

    bool continueUnparking = true;
    
    while(continueUnparking && parkingLot.getCount() > 0) {
        int id;
        cout << "Enter the id of vehicle to unpark: (0 for stop!) ";
        cin >> id;

        if (id == 0) {
            continueUnparking = false;
            continue;
        }

        bool unparked = parkingLot.unparkVehicle(id);

        if (unparked) {
            cout << "Vehicle with ID" << id << "unparked successfully." << endl;
        }

    }
    return 0;
}