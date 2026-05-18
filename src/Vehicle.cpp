#include "Vehicle.h"
#include <iostream>
#include <algorithm>
using namespace std;
//Comments are written to explain concepts due to the requirement of assignment
// VEHICLE Implementation
int Vehicle::totalVehicles = 0;

Vehicle::Vehicle()
    : brand(""), model(""), year(0), price(0.0), mileage(0), vehicleType("Vehicle") {
    totalVehicles++;
}

Vehicle::Vehicle(const string& b, const string& m, int y,
                 double p, int mi, const string& t)
    : brand(b), model(m), year(y), price(p), mileage(mi), vehicleType(t) {
    totalVehicles++;
}

Vehicle::Vehicle(const Vehicle& other)
    : brand(other.brand), model(other.model), year(other.year),
      price(other.price), mileage(other.mileage), vehicleType(other.vehicleType) {
    totalVehicles++;
}

Vehicle::~Vehicle() { totalVehicles--; }

void Vehicle::setBrand(const string& b)  { brand = b; }
void Vehicle::setModel(const string& m)  { model = m; }
void Vehicle::setYear(int y)             { year = y; }
void Vehicle::setPrice(double p)         { price = p; }
void Vehicle::setMileage(int mi)         { mileage = mi; }

string Vehicle::getBrand()  const { return brand; }
string Vehicle::getModel()  const { return model; }
int    Vehicle::getYear()   const { return year; }
double Vehicle::getPrice()  const { return price; }
int    Vehicle::getMileage()const { return mileage; }
string Vehicle::getType()   const { return vehicleType; }

int Vehicle::getTotalVehicles() { return totalVehicles; }

bool Vehicle::matchesSearch(const string& kw) const {
    string keyword = kw;
    transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
    string b = brand, m = model;
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    transform(m.begin(), m.end(), m.begin(), ::tolower);
    return b.find(keyword) != string::npos || m.find(keyword) != string::npos;
}

bool Vehicle::operator==(const Vehicle& other) const {
    return price == other.price;
}

bool Vehicle::operator<(const Vehicle& other) const {
    return price < other.price;
}

// Friend function implementation
string combineVehicleInfo(const Vehicle& v1, const Vehicle& v2) {
    // Friend accesses private/protected members directly
    return v1.brand + " " + v1.model + " vs " + v2.brand + " " + v2.model;
}


// CAR Implementation
Car::Car()
    : Vehicle("", "", 0, 0.0, 0, "Car"),
      numDoors(4), fuelType("Petrol"), transmission("Manual"), isAutomatic(false) {}

Car::Car(const string& b, const string& m, int y, double p, int mi,
         int doors, const string& fuel, const string& trans)
    : Vehicle(b, m, y, p, mi, "Car"),
      numDoors(doors), fuelType(fuel), transmission(trans),
      isAutomatic(trans == "Automatic") {}

Car::Car(const Car& other)
    : Vehicle(other), numDoors(other.numDoors), fuelType(other.fuelType),
      transmission(other.transmission), isAutomatic(other.isAutomatic) {}

void Car::setNumDoors(int d)             { numDoors = d; }
void Car::setFuelType(const string& f)   { fuelType = f; }
void Car::setTransmission(const string& t){ transmission = t; }
int    Car::getNumDoors()     const { return numDoors; }
string Car::getFuelType()     const { return fuelType; }
string Car::getTransmission() const { return transmission; }

// Polymorphic displayDetails for Car
void Car::displayDetails() const {
    cout << "--- CAR ---\n"
         << "  Brand       : " << brand        << "\n"
         << "  Model       : " << model        << "\n"
         << "  Year        : " << year         << "\n"
         << "  Price (PKR) : " << price        << "\n"
         << "  Mileage     : " << mileage      << " km\n"
         << "  Doors       : " << numDoors     << "\n"
         << "  Fuel        : " << fuelType     << "\n"
         << "  Transmission: " << transmission << "\n";
}

double Car::calculateInsurance() const {
    // Basic formula: 2% of price + age factor
    int age = 2025 - year;
    return price * 0.02 + age * 500;
}

bool Car::matchesSearch(const string& kw) const {
    if (Vehicle::matchesSearch(kw)) return true;
    string keyword = kw;
    transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
    string f = fuelType;
    transform(f.begin(), f.end(), f.begin(), ::tolower);
    return f.find(keyword) != string::npos;
}


// BIKE Implementation
Bike::Bike()
    : Vehicle("", "", 0, 0.0, 0, "Bike"),
      engineCC(125), bikeType("Standard"), hasABS(false) {}

Bike::Bike(const string& b, const string& m, int y, double p,
           int mi, int cc, const string& bt)
    : Vehicle(b, m, y, p, mi, "Bike"),
      engineCC(cc), bikeType(bt), hasABS(false) {}

Bike::Bike(const Bike& other)
    : Vehicle(other), engineCC(other.engineCC),
      bikeType(other.bikeType), hasABS(other.hasABS) {}

void Bike::setEngineCC(int cc)           { engineCC = cc; }
void Bike::setBikeType(const string& bt) { bikeType = bt; }
int    Bike::getEngineCC() const         { return engineCC; }
string Bike::getBikeType() const         { return bikeType; }

// Polymorphic displayDetails for Bike
void Bike::displayDetails() const {
    cout << "--- BIKE ---\n"
         << "  Brand      : " << brand    << "\n"
         << "  Model      : " << model    << "\n"
         << "  Year       : " << year     << "\n"
         << "  Price(PKR) : " << price    << "\n"
         << "  Mileage    : " << mileage  << " km\n"
         << "  Engine CC  : " << engineCC << "cc\n"
         << "  Type       : " << bikeType << "\n"
         << "  ABS        : " << (hasABS ? "Yes" : "No") << "\n";
}

double Bike::calculateInsurance() const {
    return price * 0.015 + (2025 - year) * 300;
}

bool Bike::matchesSearch(const string& kw) const {
    if (Vehicle::matchesSearch(kw)) return true;
    string keyword = kw;
    transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
    string bt = bikeType;
    transform(bt.begin(), bt.end(), bt.begin(), ::tolower);
    return bt.find(keyword) != string::npos;
}
