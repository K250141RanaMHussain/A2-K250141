/*
  ============================================================
  CAR MARKETPLACE SYSTEM
 
  OOP Concepts Demonstrated:
   A1: Classes, Constructors, Constants, Static, Composition,
       Aggregation, Arrays of Objects, Functionality
   A2: Inheritance, Polymorphism, Abstraction, Operator
       Overloading, Friend Functions
  ============================================================
 */
//Comments are written to explain concepts due to the requirement of assignment
#include <iostream>
#include "Marketplace.h"
#include "BuyerSellerAdmin.h"
#include "Vehicle.h"
#include "ListingMessageReview.h"
using namespace std;

// Demonstrates Polymorphism:
// Takes a base-class pointer, calls virtual displayDetails()
void showVehicleInfo(const Vehicle* v) {
    v->displayDetails();  // Resolves to Car::displayDetails or Bike::displayDetails
}

void showUserInfo(const User* u) {
    u->displayDetails();  // Resolves to Buyer/Seller/Admin::displayDetails
}

int main() {
    cout << "========================================\n";
    cout << "    CAR MARKETPLACE SYSTEM (OOP Demo)   \n";
    cout << "========================================\n\n";

    // 1. Create Marketplace 
    Marketplace market("PakWheels-Clone");

    // 2. Create Users (Inheritance hierarchy) 
    Buyer   buyer1("Ali Khan",    "ali@email.com",    "0300-1111111", "pass123", "Toyota", 3000000.0);
    Buyer   buyer2("Sara Malik",  "sara@email.com",   "0301-2222222", "pass456", "Honda",  1500000.0);
    Seller  seller1("Usman Autos","usman@email.com",  "0321-3333333", "sell789", "Usman Motors");
    Seller  seller2("Raza Cars",  "raza@email.com",   "0322-4444444", "sell000", "Raza AutoDeals");
    Admin   admin1("Admin Zara",  "admin@pakwheels.com","0333-9999999","admin1", 2, "Operations");

    // Register users
    market.registerUser(&buyer1);
    market.registerUser(&buyer2);
    market.registerUser(&seller1);
    market.registerUser(&seller2);
    market.registerUser(&admin1);

    // 3. Polymorphic display
    cout << "\n--- Polymorphic displayDetails() ---\n";
    showUserInfo(&buyer1);
    showUserInfo(&seller1);
    showUserInfo(&admin1);

    // 4. Create Vehicles (Inheritance: Car, Bike from Vehicle)
    Car* car1  = new Car("Toyota",  "Corolla",  2022, 3200000, 15000, 4, "Petrol",  "Automatic");
    Car* car2  = new Car("Honda",   "Civic",    2021, 4100000, 25000, 4, "Petrol",  "Automatic");
    Car* car3  = new Car("Suzuki",  "Alto",     2020, 1800000, 40000, 4, "Petrol",  "Manual");
    Bike* bike1= new Bike("Yamaha", "YZF-R1",   2023, 850000,  5000, 1000, "Sport");
    Bike* bike2= new Bike("Honda",  "CG 125",   2022, 200000,  8000, 125,  "Standard");

    // Polymorphic vehicle display
    cout << "\n--- Polymorphic Vehicle Display ---\n";
    showVehicleInfo(car1);
    showVehicleInfo(bike1);

    //5. Insurance calculation (Polymorphism via virtual function)
    cout << "\n--- Insurance Estimates ---\n";
    Vehicle* vehicles[] = { car1, car2, car3, bike1, bike2 };  // Array of objects (Req 6)
    for (int i = 0; i < 5; i++) {
        cout << vehicles[i]->getBrand() << " " << vehicles[i]->getModel()
             << " Insurance: PKR " << vehicles[i]->calculateInsurance() << "\n";
    }

    //6. Create Listings (Composition: Listing owns Vehicle ptr)
    Listing* l1 = new Listing("usman@email.com", car1);
    Listing* l2 = new Listing("usman@email.com", car2);
    Listing* l3 = new Listing("raza@email.com",  car3);
    Listing* l4 = new Listing("raza@email.com",  bike1);
    Listing* l5 = new Listing("usman@email.com", bike2);

    market.addListing(l1);
    market.addListing(l2);
    market.addListing(l3);
    market.addListing(l4);
    market.addListing(l5);

    seller1.addListing(l1->getListingID());
    seller1.addListing(l2->getListingID());
    seller2.addListing(l3->getListingID());

    // 7. Admin approves listings
    cout << "\n--- Admin Approving Listings ---\n";
    admin1.approveListing(l1->getListingID());
    admin1.approveListing(l2->getListingID());
    admin1.approveListing(l3->getListingID());
    admin1.approveListing(l4->getListingID());
    market.approveListing(l1->getListingID());
    market.approveListing(l2->getListingID());
    market.approveListing(l3->getListingID());
    market.approveListing(l4->getListingID());

    // 8. Search & Filter
    cout << "\n--- Searching Listings ---\n";
    market.searchListings("Toyota");
    market.searchListings("Honda");
    market.filterByPrice(1500000, 3500000);
    market.filterByYear(2021, 2023);
    market.filterByMileage(20000);

    // 9. Buyer saves favourites
    cout << "\n--- Buyer Favourites ---\n";
    buyer1.saveFavorite(l1->getListingID());
    buyer1.saveFavorite(l2->getListingID());
    buyer1.showFavorites();

    buyer2.saveFavorite(l3->getListingID());
    buyer2.showFavorites();

    // 10. Messaging (Buyer -> Seller)
    cout << "\n--- Messaging ---\n";
    buyer1.sendMessage("usman@email.com", "Is the Toyota Corolla still available?");
    buyer2.sendMessage("raza@email.com",  "What is the lowest price for the Alto?");
    market.sendMessage("ali@email.com",   "usman@email.com", "I'm interested in the Civic too.");
    market.showMessagesFor("usman@email.com");

    // 11. Reviews (Aggregation: Review exists independently)
    cout << "\n--- Reviews ---\n";
    Review* r1 = new Review("ali@email.com",  "usman@email.com", 5, "Excellent service!");
    Review* r2 = new Review("sara@email.com", "usman@email.com", 4, "Good experience.");
    Review* r3 = new Review("ali@email.com",  "raza@email.com",  3, "Average, could be better.");
    market.addReview(r1);
    market.addReview(r2);
    market.addReview(r3);
    market.showReviewsFor("usman@email.com");
    cout << "Usman avg rating: "
         << market.getSellerAverageRating("usman@email.com") << "/5\n";

    // 12. Operator Overloading 
    cout << "\n--- Operator Overloading ---\n";
    // == on User (compare by email)
    Buyer buyer3 = buyer1;   // Copy constructor
    if (buyer1 == buyer3)
        cout << "[==] buyer1 and buyer3 have the same email.\n";

    // == on Vehicle (compare by price)
    Car car4 = *car1;
    if (*car1 == car4)
        cout << "[==] car1 and car4 have the same price.\n";

    // < on Vehicle
    if (*car3 < *car1)
        cout << "[<] Suzuki Alto is cheaper than Toyota Corolla.\n";

    // + on Listing
    cout << "[+] Combined: " << (*l1 + *l2) << "\n";

    // 13. Friend Function
    cout << "\n--- Friend Function ---\n";
    cout << combineVehicleInfo(*car1, *bike1) << "\n";

    // 14. Static Members
    cout << "\n--- Static Members ---\n";
    cout << "Total Users   : " << User::getTotalUsers()           << "\n";
    cout << "Total Sellers : " << Seller::getTotalSellers()       << "\n";
    cout << "Total Vehicles: " << Vehicle::getTotalVehicles()     << "\n";
    cout << "Total Listings: " << Listing::getListingCounter()    << "\n";

    // 15. Final Stats
    market.showStats();

    // 16. Admin actions
    cout << "\n--- Admin Actions ---\n";
    admin1.login();
    admin1.removeListing(l5->getListingID());
    admin1.banUser("spammer@email.com");
    admin1.generateReport();
    admin1.logout();

    // ---- Cleanup ----
    delete l1; delete l2; delete l3; delete l4; delete l5;
    delete car1; delete car2; delete car3; delete bike1; delete bike2;
    delete r1; delete r2; delete r3;

    cout << "\n[DONE] Program completed successfully.\n";
    return 0;
}
