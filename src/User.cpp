#include "User.h"
#include <iostream>
using namespace std;
//Comments are written to explain concepts due to the requirement of assignment
// Static member initialization
int User::totalUsers = 0;

// Default constructor
User::User() : name("Unknown"), email(""), phone(""), password(""), role("User") {
    totalUsers++;
}

// Parameterized constructor
User::User(const string& n, const string& e,
           const string& p, const string& pw, const string& r)
    : name(n), email(e), phone(p), password(pw), role(r) {
    totalUsers++;
}

// Copy constructor
User::User(const User& other)
    : name(other.name), email(other.email), phone(other.phone),
      password(other.password), role(other.role) {
    totalUsers++;
}

User::~User() {
    totalUsers--;
}

// Setters
void User::setName(const string& n)   { name = n; }
void User::setEmail(const string& e)  { email = e; }
void User::setPhone(const string& p)  { phone = p; }
void User::setPassword(const string& pw) { password = pw; }

// Getters
string User::getName()  const { return name; }
string User::getEmail() const { return email; }
string User::getPhone() const { return phone; }
string User::getRole()  const { return role; }

// Static functions
int  User::getTotalUsers()   { return totalUsers; }
void User::resetUserCount()  { totalUsers = 0; }

void User::login() const {
    cout << "[LOGIN]  " << name << " (" << role << ") logged in.\n";
}

void User::logout() const {
    cout << "[LOGOUT] " << name << " (" << role << ") logged out.\n";
}

// Operator == : compare by email
bool User::operator==(const User& other) const {
    return email == other.email;
}
