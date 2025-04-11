#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
using namespace std;
int main() {
    int totalVehicles;

    cout << "Enter the number of vehicles: ";
    cin >> totalVehicles;

    vector<Vehicle*> vehicles;

    for (int i = 0; i < totalVehicles; ++i) {
    int vehicleTypes;
    cout << "Enter vehicle type(1 for Car, 2 for Bus , 3 for Motorbike) : ";
    cin >> vehicleTypes;
    
    Vehicle * vehicle = nullptr;

    switch (vehicleTypes){
        case 1: 
        vehicle = new Car(i + 1);
        break;

        case 2:
        vehicle = new Bus(i + 1);
        break;

        case 3: 
        vehicle = new Motorbike(i + 1);
        break;

        default:
        cout << "Invalid vehicle type. Default set to car." << endl;
        vehicle = new Car(i + 1);
        }
        vehicles.push_back(vehicle);
    }

    cout << "\nParking Durations: " << endl;
    for (int i = 0; i < totalVehicles; ++i) {
        cout << "Vehicle " << vehicles[i]->getID() << " - Duration: " << vehicles[i]->getParkingDuration() << "seconds" << endl;
    }    

    for (auto& vehicle : vehicles) {
        delete vehicle;
    }
    
    return 0;
}