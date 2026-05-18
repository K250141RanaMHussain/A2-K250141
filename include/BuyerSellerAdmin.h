#ifndef BUYER_H
#define BUYER_H

#include "User.h"
#include <vector>
using namespace std;

// CLASS: Buyer  (Derived from User Inheritance, Req 1)
class Buyer : public User {
private:
    vector<int> favoriteListingIDs;  // IDs of saved favourite listings
    string preferredBrand;
    double budget;

public:
    Buyer();
    Buyer(const string& name, const string& email,
          const string& phone, const string& password,
          const string& preferredBrand, double budget);
    Buyer(const Buyer& other);

    void setBudget(double b);
    void setPreferredBrand(const string& brand);
    double getBudget() const;
    string getPreferredBrand() const;

    void saveFavorite(int listingID);
    void removeFavorite(int listingID);
    void showFavorites() const;

    // Overridden virtual functions (Polymorphism)
    void displayDetails() const override;
    void sendMessage(const string& recipient, const string& msg) const override;
};

#endif


// FILE: Seller.h
// CLASS: Seller (Derived from User — Inheritance, Req 1)
#ifndef SELLER_H
#define SELLER_H

#include "User.h"
#include <vector>

class Seller : public User {
private:
    vector<int> activeListingIDs;
    string businessName;
    double rating;              // Aggregation: rating comes from reviews
    int totalSales;

    static int totalSellers;   // Static: tracks seller count (Req 4)

public:
    Seller();
    Seller(const string& name, const string& email,
           const string& phone, const string& password,
           const string& businessName);
    Seller(const Seller& other);

    void setBusinessName(const string& bn);
    void setRating(double r);
    string getBusinessName() const;
    double getRating() const;
    int    getTotalSales() const;

    static int getTotalSellers();   // Static function (Req 4)

    void addListing(int listingID);
    void removeListing(int listingID);
    void showListings() const;
    void incrementSales();

    void displayDetails() const override;
    void sendMessage(const string& recipient, const string& msg) const override;
};

#endif


// FILE: Admin.h
// CLASS: Admin (Derived from User Inheritance, Req 1)
#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User {
private:
    int adminLevel;
    string department;

public:
    Admin();
    Admin(const string& name, const string& email,
          const string& phone, const string& password,
          int level, const string& dept);
    Admin(const Admin& other);

    void setAdminLevel(int level);
    void setDepartment(const string& dept);
    int    getAdminLevel() const;
    string getDepartment() const;

    void approveListing(int listingID) const;
    void removeListing(int listingID) const;
    void banUser(const string& userEmail) const;
    void generateReport() const;

    void displayDetails() const override;
    void sendMessage(const string& recipient, const string& msg) const override;
};

#endif
