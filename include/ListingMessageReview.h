#ifndef LISTING_H
#define LISTING_H

#include <string>
#include "Vehicle.h"
#include "IDisplayable.h"
using namespace std;

// CLASS: Listing
// COMPOSITION with Vehicle (Listing owns a Vehicle object)
// Assignment 1 - Req 5 (Composition)
class Listing : public IDisplayable {
private:
    int    listingID;
    string sellerEmail;
    bool   isApproved;
    string status;              // "Active", "Sold", "Pending"
    const string PLATFORM_TAG; // Constant member (Req 3)

    Vehicle* vehicle;           // COMPOSITION: Listing owns the vehicle

    static int listingCounter;  // Static counter for auto-ID generation (Req 4)
    // Why static: each listing needs a unique ID; counter must persist across instances.

public:
    Listing();
    Listing(const string& sellerEmail, Vehicle* v);
    Listing(const Listing& other);
    ~Listing();

    void setStatus(const string& s);
    void approve();
    void reject();

    int    getListingID()   const;
    string getSellerEmail() const;
    bool   getIsApproved()  const;
    string getStatus()      const;
    Vehicle* getVehicle()   const;

    static int getListingCounter();

    void displayDetails() const override;
    void markAsSold();

    // Operator +: merge two listing descriptions (Assignment 2 - Req 4)
    string operator+(const Listing& other) const;

    // Friend: allow Admin to access private listing fields directly
    friend class Admin;
};

#endif

// FILE: Message.h
// CLASS: Message (standalone value object)
#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "IDisplayable.h"
using namespace std;

class Message : public IDisplayable {
private:
    int    messageID;
    string senderEmail;
    string receiverEmail;
    string content;
    string timestamp;

    static int msgCounter;

public:
    Message();
    Message(const string& from, const string& to, const string& content);
    Message(const Message& other);

    string getSender()   const;
    string getReceiver() const;
    string getContent()  const;
    string getTimestamp()const;
    int    getID()       const;

    void displayDetails() const override;
    void markAsRead() const;
};

#endif


// ============================================================
// FILE: Review.h
// CLASS: Review (AGGREGATION with Seller — Seller doesn't own reviews)
// Assignment 1 - Req 5 (Aggregation)
// ============================================================
#ifndef REVIEW_H
#define REVIEW_H

#include <string>
#include "IDisplayable.h"
using namespace std;

class Review : public IDisplayable {
private:
    int    reviewID;
    string buyerEmail;
    string sellerEmail;
    int    rating;      
    string comment;
    string date;

    static int reviewCounter;

public:
    Review();
    Review(const string& buyer, const string& seller, int rating, const string& comment);
    Review(const Review& other);

    int    getRating()      const;
    string getBuyerEmail()  const;
    string getSellerEmail() const;
    string getComment()     const;

    void displayDetails() const override;

    // Friend: Seller can access review details directly
    friend class Seller;
};

#endif
