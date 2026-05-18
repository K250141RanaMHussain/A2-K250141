#include "Marketplace.h"
#include <iostream>
#include <algorithm>
using namespace std;
//Comments are written to explain concepts due to the requirement of assignment
int Marketplace::totalTransactions = 0;

Marketplace::Marketplace()
    : platformName("PakWheels-Clone"), VERSION("1.0.0") {}

Marketplace::Marketplace(const string& name)
    : platformName(name), VERSION("1.0.0") {}

Marketplace::~Marketplace() {
    // Aggregation: we don't delete users/listings
}

// Listing Management
void Marketplace::addListing(Listing* l) {
    listings.push_back(l);
    cout << "[MARKETPLACE] Listing #" << l->getListingID() << " submitted. Awaiting approval.\n";
}

void Marketplace::removeListing(int id) {
    auto it = find_if(listings.begin(), listings.end(),
        [id](const Listing* l){ return l->getListingID() == id; });
    if (it != listings.end()) {
        listings.erase(it);
        cout << "[MARKETPLACE] Listing #" << id << " removed.\n";
    } else {
        cout << "[MARKETPLACE] Listing #" << id << " not found.\n";
    }
}

void Marketplace::approveListing(int id) {
    for (auto* l : listings) {
        if (l->getListingID() == id) {
            l->approve();
            cout << "[MARKETPLACE] Listing #" << id << " approved.\n";
            return;
        }
    }
    cout << "[MARKETPLACE] Listing #" << id << " not found.\n";
}

void Marketplace::searchListings(const string& keyword) const {
    cout << "\n[SEARCH] Results for \"" << keyword << "\":\n";
    bool found = false;
    for (const auto* l : listings) {
        if (l->getIsApproved() && l->getVehicle() &&
            l->getVehicle()->matchesSearch(keyword)) {
            l->displayDetails();
            found = true;
        }
    }
    if (!found) cout << "  No listings matched.\n";
}

void Marketplace::filterByPrice(double minP, double maxP) const {
    cout << "\n[FILTER] Price: PKR " << minP << " - " << maxP << "\n";
    for (const auto* l : listings) {
        if (!l->getIsApproved() || !l->getVehicle()) continue;
        double p = l->getVehicle()->getPrice();
        if (p >= minP && p <= maxP) l->displayDetails();
    }
}

void Marketplace::filterByYear(int minY, int maxY) const {
    cout << "\n[FILTER] Year: " << minY << " - " << maxY << "\n";
    for (const auto* l : listings) {
        if (!l->getIsApproved() || !l->getVehicle()) continue;
        int y = l->getVehicle()->getYear();
        if (y >= minY && y <= maxY) l->displayDetails();
    }
}

void Marketplace::filterByMileage(int maxMileage) const {
    cout << "\n[FILTER] Mileage <= " << maxMileage << " km\n";
    for (const auto* l : listings) {
        if (!l->getIsApproved() || !l->getVehicle()) continue;
        if (l->getVehicle()->getMileage() <= maxMileage) l->displayDetails();
    }
}

void Marketplace::showAllListings() const {
    cout << "\n===== ALL LISTINGS (" << listings.size() << ") =====\n";
    for (const auto* l : listings) l->displayDetails();
}

// User Management
void Marketplace::registerUser(User* u) {
    users.push_back(u);
    cout << "[MARKETPLACE] " << u->getRole() << " '" << u->getName() << "' registered.\n";
}

User* Marketplace::findUserByEmail(const string& email) const {
    for (auto* u : users)
        if (u->getEmail() == email) return u;
    return nullptr;
}

void Marketplace::showAllUsers() const {
    cout << "\n===== REGISTERED USERS (" << users.size() << ") =====\n";
    for (const auto* u : users) u->displayDetails();
}

// Messaging
void Marketplace::sendMessage(const string& from, const string& to, const string& msg) {
    Message* m = new Message(from, to, msg);
    messages.push_back(m);
    cout << "[MSG SENT] " << from << " -> " << to << "\n";
}

void Marketplace::showMessagesFor(const string& email) const {
    cout << "\n[INBOX] Messages for " << email << ":\n";
    for (const auto* m : messages)
        if (m->getReceiver() == email) m->displayDetails();
}

// Reviews (Aggregation: reviews exist independently) 
void Marketplace::addReview(Review* r) {
    reviews.push_back(r);
    cout << "[REVIEW] Review added for seller " << r->getSellerEmail() << ".\n";
}

void Marketplace::showReviewsFor(const string& sellerEmail) const {
    cout << "\n[REVIEWS] For seller: " << sellerEmail << "\n";
    for (const auto* r : reviews)
        if (r->getSellerEmail() == sellerEmail) r->displayDetails();
}

double Marketplace::getSellerAverageRating(const string& sellerEmail) const {
    double sum = 0; int count = 0;
    for (const auto* r : reviews) {
        if (r->getSellerEmail() == sellerEmail) { sum += r->getRating(); count++; }
    }
    return count > 0 ? sum / count : 0.0;
}

// Static 
void Marketplace::incrementTransactions() { totalTransactions++; }
int  Marketplace::getTotalTransactions()  { return totalTransactions; }

void Marketplace::showStats() const {
    cout << "\n===== MARKETPLACE STATS =====\n"
         << "  Platform      : " << platformName          << " v" << VERSION << "\n"
         << "  Total Users   : " << User::getTotalUsers()           << "\n"
         << "  Total Vehicles: " << Vehicle::getTotalVehicles()     << "\n"
         << "  Total Listings: " << listings.size()                 << "\n"
         << "  Total Messages: " << messages.size()                 << "\n"
         << "  Total Reviews : " << reviews.size()                  << "\n"
         << "  Transactions  : " << totalTransactions               << "\n"
         << "=================================\n";
}
