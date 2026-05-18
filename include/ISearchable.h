#ifndef ISEARCHABLE_H
#define ISEARCHABLE_H

#include <string>
using namespace std;

// Abstract Interface: ISearchable
// Forces derived classes to implement search functionality
// Demonstrates Abstraction (Assignment 2 - Req 3)
class ISearchable {
public:
    virtual bool matchesSearch(const string& keyword) const = 0;  // Pure virtual
    virtual ~ISearchable() {}
};

#endif
