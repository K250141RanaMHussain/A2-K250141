#ifndef USER_H
#define USER_H

#include <string>
#include "IDisplayable.h"
#include "IMessagable.h"
using namespace std;

// CLASS: User (Abstract Base Class)
// - Base for Buyer, Seller, Admin (Inheritance - Assignment 2)
// - Has static member to track total users (Assignment 1 - Req 4)
class User : public IDisplayable, public IMessagable {
protected:
    string name;
    string email;
    string phone;
    string password;
    const string role;       // Constant data member (Assignment 1 - Req 3)

    static int totalUsers;   // Static: tracks count across all User objects (Req 4)

public:
    // Default constructor
    User();

    // Parameterized constructor
    User(const string& name, const string& email,
         const string& phone, const string& password, const string& role);

    // Copy constructor
    User(const User& other);

    virtual ~User();

    // Setters & Getters
    void setName(const string& n);
    void setEmail(const string& e);
    void setPhone(const string& p);
    void setPassword(const string& pw);

    string getName()     const;
    string getEmail()    const;
    string getPhone()    const;
    string getRole()     const;

    // Static member function — explains why static:
    // totalUsers belongs to the class, not any one instance.
    static int getTotalUsers();
    static void resetUserCount();

    // Pure virtual forces subclasses to implement (Polymorphism)
    virtual void displayDetails() const = 0;
    virtual void sendMessage(const string& recipient, const string& msg) const = 0;
    virtual void login() const;
    virtual void logout() const;

    // Operator overloading: compare two users by email (Assignment 2 - Req 4)
    bool operator==(const User& other) const;
};

#endif
