#include "ListingMessageReview.h"
#include <iostream>
#include <ctime>
using namespace std;
//Comments are written to explain concepts due to the requirement of assignment
// ============================================================
// LISTING Implementation
// ============================================================
int Listing::listingCounter = 0;

Listing::Listing()
    : listingID(++listingCounter), sellerEmail(""), isApproved(false),
      status("Pending"), PLATFORM_TAG("PakWheels-Clone"), vehicle(nullptr) {}

Listing::Listing(const string& sel, Vehicle* v)
    : listingID(++listingCounter), sellerEmail(sel), isApproved(false),
      status("Pending"), PLATFORM_TAG("PakWheels-Clone"), vehicle(v) {}

Listing::Listing(const Listing& other)
    : listingID(++listingCounter), sellerEmail(other.sellerEmail),
      isApproved(other.isApproved), status(other.status),
      PLATFORM_TAG(other.PLATFORM_TAG), vehicle(other.vehicle) {}

// NOTE: Listing does NOT delete vehicle in destructor because in a real
// marketplace the vehicle data may be shared/aggregated. For full composition,
// uncomment the delete below if Listing is the sole owner.
Listing::~Listing() {
    // delete vehicle;  // Uncomment for strict composition ownership
}

void Listing::setStatus(const string& s) { status = s; }
void Listing::approve() { isApproved = true; status = "Active"; }
void Listing::reject()  { isApproved = false; status = "Rejected"; }
void Listing::markAsSold() { status = "Sold"; }

int    Listing::getListingID()   const { return listingID; }
string Listing::getSellerEmail() const { return sellerEmail; }
bool   Listing::getIsApproved()  const { return isApproved; }
string Listing::getStatus()      const { return status; }
Vehicle* Listing::getVehicle()   const { return vehicle; }
int    Listing::getListingCounter()    { return listingCounter; }

void Listing::displayDetails() const {
    cout << "===== LISTING #" << listingID << " =====\n"
         << "  Platform : " << PLATFORM_TAG  << "\n"
         << "  Seller   : " << sellerEmail   << "\n"
         << "  Status   : " << status        << "\n"
         << "  Approved : " << (isApproved ? "Yes" : "No") << "\n";
    if (vehicle) vehicle->displayDetails();
    cout << "========================\n";
}

// Operator +: concatenate two listing summaries
string Listing::operator+(const Listing& other) const {
    return "Listing#" + to_string(listingID) +
           " + Listing#" + to_string(other.listingID);
}


// ============================================================
// MESSAGE Implementation
// ============================================================
int Message::msgCounter = 0;

static string currentTimestamp() {
    time_t t = time(nullptr);
    string ts = ctime(&t);
    if (!ts.empty() && ts.back() == '\n') ts.pop_back();
    return ts;
}

Message::Message()
    : messageID(++msgCounter), senderEmail(""), receiverEmail(""),
      content(""), timestamp(currentTimestamp()) {}

Message::Message(const string& from, const string& to, const string& body)
    : messageID(++msgCounter), senderEmail(from), receiverEmail(to),
      content(body), timestamp(currentTimestamp()) {}

Message::Message(const Message& other)
    : messageID(++msgCounter), senderEmail(other.senderEmail),
      receiverEmail(other.receiverEmail), content(other.content),
      timestamp(other.timestamp) {}

string Message::getSender()    const { return senderEmail; }
string Message::getReceiver()  const { return receiverEmail; }
string Message::getContent()   const { return content; }
string Message::getTimestamp() const { return timestamp; }
int    Message::getID()        const { return messageID; }

void Message::displayDetails() const {
    cout << "[MSG #" << messageID << "] "
         << senderEmail << " -> " << receiverEmail
         << " | " << timestamp << "\n"
         << "  Content: " << content << "\n";
}

void Message::markAsRead() const {
    cout << "[MSG #" << messageID << "] Marked as read.\n";
}


// ============================================================
// REVIEW Implementation
// ============================================================
int Review::reviewCounter = 0;

Review::Review()
    : reviewID(++reviewCounter), buyerEmail(""), sellerEmail(""),
      rating(0), comment(""), date("N/A") {}

Review::Review(const string& buyer, const string& seller,
               int r, const string& c)
    : reviewID(++reviewCounter), buyerEmail(buyer), sellerEmail(seller),
      rating(r), comment(c), date(currentTimestamp()) {}

Review::Review(const Review& other)
    : reviewID(++reviewCounter), buyerEmail(other.buyerEmail),
      sellerEmail(other.sellerEmail), rating(other.rating),
      comment(other.comment), date(other.date) {}

int    Review::getRating()      const { return rating; }
string Review::getBuyerEmail()  const { return buyerEmail; }
string Review::getSellerEmail() const { return sellerEmail; }
string Review::getComment()     const { return comment; }

void Review::displayDetails() const {
    cout << "[REVIEW #" << reviewID << "] "
         << buyerEmail << " -> Seller: " << sellerEmail << "\n"
         << "  Rating : " << rating << "/5\n"
         << "  Comment: " << comment << "\n"
         << "  Date   : " << date   << "\n";
}
