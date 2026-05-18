# Car Marketplace System – OOP Assignment 2

##  Student Information
- Name: Rana Muhammad Hussain  
- Student ID: K250141  

---

# 1. Assignment Overview

This assignmnet is a C++ Object-Oriented Programming implementation of a **Car Marketplace System**, inspired by platforms like PakWheels.

It simulates a real-world system where:
- Buyers search and save vehicles
- Sellers create listings
- Admins moderate the platform
- Users communicate via messaging
- Reviews and ratings are managed

The goal is to apply **advanced OOP concepts in a structured real-world system design**.

###  Screenshot
![Marketplace Output](screenshots/output.png)

# 2. Project Structure

- `src/` → All implementation (.cpp files)  
- `include/` → Header files (.h interfaces and class definitions)  
- `screenshots/` → Output images + UML diagram  

---

#  3. Object-Oriented Programming Concepts

##  3.1 Inheritance

###  Implementation
- User → Buyer, Seller, Admin  
- Vehicle → Car, Bike  

###  Reasoning
Inheritance is used to avoid duplication of common attributes like name, email, brand, price, etc.  
It also allows specialization of behavior for each role.


## 3.2 Polymorphism

###  Reasoning
Polymorphism allows the same function call to behave differently depending on object type:

Car → shows car details
Bike → shows bike details
User → shows role-specific details

This makes the system flexible and extensible.

###  Screenshot
![Inheritance & Role Hierarchy](screenshots/polymorphic.png)

## 3.3 Abstraction
###  Implementation
Interfaces used:

IDisplayable
IMessagable
ISearchable
###  Reasoning
Abstraction hides internal implementation details and only exposes essential functionality.
It ensures a clean and maintainable architecture.

## 3.4 Operator Overloading
###  Implementation

###  Reasoning
Operator overloading improves readability by allowing natural comparisons:

Vehicles compared by price
Users compared by identity (email)
Listings combined logically

## 3.5 Friend Function
###  Reasoning
Friend functions are used when direct access to private data is needed for comparison without exposing it publicly

#  4. System Features
## Search Functionality
Users can search vehicles by brand or model.
###  Screenshot
![Search Function](screenshots/searching.png)

## Messaging System
Buyers and sellers can communicate via messages.
###  Screenshot
![Message Function](screenshots/messaging.png)
## Listings & Marketplace
Marketplace manages listings, approvals, and filtering.


## Reviews System
Buyers can leave ratings and comments for sellers.

## UML Class Diagram
Shows relationships between all classes including:

Inheritance
Aggregation
Composition
###  Screenshot
![UML](screenshots/UML.png)

# 5. Design Reasoning
The system is designed with a real-world mindset:

Each class represents a real entity
Responsibilities are separated properly
OOP principles are used to ensure scalability
Composition is used for Listing → Vehicle relationship
Aggregation is used for marketplace ownership model

This results in:

Clean architecture
Reusable components
Maintainable codebase

# 6. How to Run
g++ src/*.cpp -I include -o marketplace
./marketplace.exe

# 7. Conclusion
This project successfully demonstrates advanced Object-Oriented Programming concepts including:

Inheritance
Polymorphism
Abstraction
Operator Overloading
Friend Functions

It simulates a real-world marketplace system with modular and extensible design.

