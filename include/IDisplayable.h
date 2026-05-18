#ifndef IDISPLAYABLE_H
#define IDISPLAYABLE_H

// Abstract Interface: IDisplayable
// Forces all derived classes to implement displayDetails()
// Demonstrates Abstraction (Assignment 2 - Req 3)
class IDisplayable {
public:
    virtual void displayDetails() const = 0;  // Pure virtual function
    virtual ~IDisplayable() {}
};

#endif
