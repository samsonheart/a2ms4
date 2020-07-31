//==============================================
// Name:          Samson Kaphengst
// Student Number: 128270154
// Email:          bkaphengst@myseneca.ca
// Section:        NKK
// Date:           
//==============================================
// Assignment:     2
// Milestone:      1
//==============================================


//--------------------------------
// Structure Types
//--------------------------------
#ifndef CONTACTS_H_
#define CONTACTS_H_

// Structure type Name declaration (Milestone 1)
struct Name
{
    char firstName[31];
    // char middleInitial[5]; // <- NO! Must accommodate 6 character + null terminator byte = 7
    char middleInitial[8];
    char lastName[10];
};

// Structure type Address declaration (Milestone 1)
struct Address
{
    int streetNumber;
    char street[41];
    int apartmentNumber;
    char postalCode[15];
    char city[41];
};

// Structure type Numbers declaration (Milestone 1)
struct Numbers
{
    char cell[11];
    char home[11];
    char business[11];
};

// Structure type Contact declaration (Milestone 3)
struct Contact
{
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};

//--------------------------------
// Function Prototypes
//--------------------------------

void getName(struct Name*);

void getAddress(struct Address*);


void getNumbers(struct Numbers*);

void getContact(struct Contact*);

// ----------------------------------------------------------------------------
// DO NOT remove the below line (closing of the "safeguard" condition)
#endif // !CONTACTS_H_