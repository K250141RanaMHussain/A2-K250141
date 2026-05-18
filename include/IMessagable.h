#ifndef IMESSAGABLE_H
#define IMESSAGABLE_H

#include <string>
using namespace std;

// Abstract Interface: IMessagable
// Ensures all messaging-capable entities implement sendMessage()
// Demonstrates Abstraction (Assignment 2 - Req 3)
class IMessagable {
public:
    virtual void sendMessage(const string& recipient, const string& msg) const = 0;
    virtual ~IMessagable() {}
};

#endif
