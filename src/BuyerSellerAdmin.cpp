#include "BuyerSellerAdmin.h"
#include <iostream>
#include <algorithm>
using namespace std;
//Comments are written to explain concepts due to the requirement of assignment
// BUYER Implementation
Buyer::Buyer() : User("", "", "", "", "Buyer"), preferredBrand("Any"), budget(0.0) {}

Buyer::Buyer(const string& n, const string& e, const string& p,
             const string& pw, const string& brand, double b)
    : User(n, e, p, pw, "Buyer"), preferredBrand(brand), budget(b) {}

Buyer::Buyer(const Buyer& other)
    : User(other), favoriteListingIDs(other.favoriteListingIDs),
      preferredBrand(other.preferredBrand), budget(other.budget) {}

void Buyer::setBudget(double b)               { budget = b; }
void Buyer::setPreferredBrand(const string& b){ preferredBrand = b; }
double Buyer::getBudget() const               { return budget; }
string Buyer::getPreferredBrand() const       { return preferredBrand; }

void Buyer::saveFavorite(int id) {
    favoriteListingIDs.push_back(id);
    cout << "[BUYER] Listing #" << id << " saved to favourites.\n";
}

void Buyer::removeFavorite(int id) {
    favoriteListingIDs.erase(
        remove(favoriteListingIDs.begin(), favoriteListingIDs.end(), id),
        favoriteListingIDs.end());
    cout << "[BUYER] Listing #" << id << " removed from favourites.\n";
}

void Buyer::showFavorites() const {
    cout << "[BUYER] " << name << "'s Favourites: ";
    for (int id : favoriteListingIDs) cout << "#" << id << " ";
    cout << "\n";
}

void Buyer::displayDetails() const {
    cout << "=== BUYER ===\n"
         << "  Name   : " << name << "\n"
         << "  Email  : " << email << "\n"
         << "  Phone  : " << phone << "\n"
         << "  Budget : PKR " << budget << "\n"
         << "  Prefers: " << preferredBrand << "\n";
}

void Buyer::sendMessage(const string& recipient, const string& msg) const {
    cout << "[MSG] Buyer " << name << " -> " << recipient << ": " << msg << "\n";
}


// SELLER Implementation
int Seller::totalSellers = 0;

Seller::Seller()
    : User("", "", "", "", "Seller"), businessName("N/A"), rating(0.0), totalSales(0) {
    totalSellers++;
}

Seller::Seller(const string& n, const string& e, const string& p,
               const string& pw, const string& bn)
    : User(n, e, p, pw, "Seller"), businessName(bn), rating(0.0), totalSales(0) {
    totalSellers++;
}

Seller::Seller(const Seller& other)
    : User(other), activeListingIDs(other.activeListingIDs),
      businessName(other.businessName), rating(other.rating), totalSales(other.totalSales) {
    totalSellers++;
}

void Seller::setBusinessName(const string& bn) { businessName = bn; }
void Seller::setRating(double r)               { rating = r; }
string Seller::getBusinessName() const         { return businessName; }
double Seller::getRating() const               { return rating; }
int    Seller::getTotalSales() const           { return totalSales; }
int    Seller::getTotalSellers()               { return totalSellers; }
void   Seller::incrementSales()                { totalSales++; }

void Seller::addListing(int id) {
    activeListingIDs.push_back(id);
    cout << "[SELLER] Listing #" << id << " added.\n";
}

void Seller::removeListing(int id) {
    activeListingIDs.erase(
        remove(activeListingIDs.begin(), activeListingIDs.end(), id),
        activeListingIDs.end());
    cout << "[SELLER] Listing #" << id << " removed.\n";
}

void Seller::showListings() const {
    cout << "[SELLER] " << name << "'s Active Listings: ";
    for (int id : activeListingIDs) cout << "#" << id << " ";
    cout << "\n";
}

void Seller::displayDetails() const {
    cout << "=== SELLER ===\n"
         << "  Name    : " << name << "\n"
         << "  Email   : " << email << "\n"
         << "  Business: " << businessName << "\n"
         << "  Rating  : " << rating << "/5\n"
         << "  Sales   : " << totalSales << "\n";
}

void Seller::sendMessage(const string& recipient, const string& msg) const {
    cout << "[MSG] Seller " << name << " -> " << recipient << ": " << msg << "\n";
}


// ADMIN Implementation
Admin::Admin()
    : User("", "", "", "", "Admin"), adminLevel(1), department("General") {}

Admin::Admin(const string& n, const string& e, const string& p,
             const string& pw, int level, const string& dept)
    : User(n, e, p, pw, "Admin"), adminLevel(level), department(dept) {}

Admin::Admin(const Admin& other)
    : User(other), adminLevel(other.adminLevel), department(other.department) {}

void Admin::setAdminLevel(int l)             { adminLevel = l; }
void Admin::setDepartment(const string& d)   { department = d; }
int    Admin::getAdminLevel() const          { return adminLevel; }
string Admin::getDepartment() const          { return department; }

void Admin::approveListing(int id) const {
    cout << "[ADMIN] Listing #" << id << " APPROVED by " << name << ".\n";
}

void Admin::removeListing(int id) const {
    cout << "[ADMIN] Listing #" << id << " REMOVED by " << name << ".\n";
}

void Admin::banUser(const string& userEmail) const {
    cout << "[ADMIN] User " << userEmail << " has been BANNED by " << name << ".\n";
}

void Admin::generateReport() const {
    cout << "[ADMIN] Report generated by " << name
         << " | Total Users: " << User::getTotalUsers() << "\n";
}

void Admin::displayDetails() const {
    cout << "=== ADMIN ===\n"
         << "  Name      : " << name << "\n"
         << "  Email     : " << email << "\n"
         << "  Level     : " << adminLevel << "\n"
         << "  Department: " << department << "\n";
}

void Admin::sendMessage(const string& recipient, const string& msg) const {
    cout << "[MSG] Admin " << name << " -> " << recipient << ": " << msg << "\n";
}
