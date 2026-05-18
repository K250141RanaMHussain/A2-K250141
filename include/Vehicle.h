#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "IDisplayable.h"
#include "ISearchable.h"
using namespace std;

// CLASS: Vehicle (Abstract Base  Inheritance, Polymorphism)
// Derived by: Car, Bike (Assignment 2 - Req 1)
class Vehicle : public IDisplayable, public ISearchable {
protected:
    string brand;
    string model;
    int    year;
    double price;
    int    mileage;
    const string vehicleType;   // Constant member (Assignment 1 - Req 3)

    static int totalVehicles;   // Static: counts all Vehicle objects (Req 4)

public:
    Vehicle();
    Vehicle(const string& brand, const string& model,
            int year, double price, int mileage, const string& type);
    Vehicle(const Vehicle& other);
    virtual ~Vehicle();

    // Setters
    void setBrand(const string& b);
    void setModel(const string& m);
    void setYear(int y);
    void setPrice(double p);
    void setMileage(int mi);

    // Getters
    string getBrand()  const;
    string getModel()  const;
    int    getYear()   const;
    double getPrice()  const;
    int    getMileage()const;
    string getType()   const;

    // Static
    static int getTotalVehicles();

    // Pure virtual Polymorphism (displayDetails differs per type)
    virtual void displayDetails() const = 0;
    virtual bool matchesSearch(const string& keyword) const override;
    virtual double calculateInsurance() const = 0;  // Pure virtual

    // Operator overloading: compare vehicles by price (Assignment 2 - Req 4)
    bool operator==(const Vehicle& other) const;
    bool operator<(const Vehicle& other) const;

    // Friend function: combine two vehicle descriptions (Req 5)
    friend string combineVehicleInfo(const Vehicle& v1, const Vehicle& v2);
};


// CLASS: Car (Derived from Vehicle)
class Car : public Vehicle {
private:
    int    numDoors;
    string fuelType;
    string transmission;
    bool   isAutomatic;

public:
    Car();
    Car(const string& brand, const string& model, int year,
        double price, int mileage, int doors,
        const string& fuel, const string& trans);
    Car(const Car& other);

    void setNumDoors(int d);
    void setFuelType(const string& f);
    void setTransmission(const string& t);
    int    getNumDoors()     const;
    string getFuelType()     const;
    string getTransmission() const;

    void displayDetails()        const override;
    double calculateInsurance()  const override;
    bool matchesSearch(const string& keyword) const override;
};


// CLASS: Bike (Derived from Vehicle)
class Bike : public Vehicle {
private:
    int    engineCC;
    string bikeType;    // Sport, Cruiser, Off-road
    bool   hasABS;

public:
    Bike();
    Bike(const string& brand, const string& model, int year,
         double price, int mileage, int cc, const string& bType);
    Bike(const Bike& other);

    void setEngineCC(int cc);
    void setBikeType(const string& bt);
    int    getEngineCC() const;
    string getBikeType() const;

    void displayDetails()        const override;
    double calculateInsurance()  const override;
    bool matchesSearch(const string& keyword) const override;
};

#endif
