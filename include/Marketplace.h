#ifndef MARKETPLACE_H
#define MARKETPLACE_H

#include "BuyerSellerAdmin.h"
#include "ListingMessageReview.h"
#include <vector>
#include <string>
using namespace std;

// CLASS: Marketplace
// - Central controller / facade
// - AGGREGATION: holds pointers to Users and Listings
//   (they exist independently outside Marketplace)
// - Uses arrays of objects (Assignment 1 - Req 6)
class Marketplace {
private:
    string platformName;
    const string VERSION;           // Constant data member

    vector<Listing*>  listings;     // Aggregation: Marketplace references Listings
    vector<Message*>  messages;     // Aggregation: Marketplace references Messages
    vector<Review*>   reviews;      // Aggregation: Marketplace references Reviews
    vector<User*>     users;        // Aggregation: Marketplace references Users

    static int totalTransactions;   // Static (Req 4): counts completed sales

public:
    Marketplace();
    Marketplace(const string& name);
    ~Marketplace();

    // Listing Management
    void addListing(Listing* l);
    void removeListing(int listingID);
    void approveListing(int listingID);
    void searchListings(const string& keyword) const;
    void filterByPrice(double minP, double maxP) const;
    void filterByYear(int minYear, int maxYear) const;
    void filterByMileage(int maxMileage) const;
    void showAllListings() const;

    // User Management
    void registerUser(User* u);
    User* findUserByEmail(const string& email) const;
    void showAllUsers() const;

    // Messaging
    void sendMessage(const string& from, const string& to, const string& msg);
    void showMessagesFor(const string& email) const;

    // Reviews
    void addReview(Review* r);
    void showReviewsFor(const string& sellerEmail) const;
    double getSellerAverageRating(const string& sellerEmail) const;

    // Static
    static void incrementTransactions();
    static int  getTotalTransactions();

    void showStats() const;
};

#endif
