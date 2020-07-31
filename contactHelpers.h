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

/*--------------------------------------------------------------------
Description: This header file modularizes general helper functions to
             help reduce redundant coding for common repetitive tasks. 
---------------------------------------------------------------------*/

// HINT: 
// You will most likely want to include this header file
// in other files of the project since it provides general 
// helper functions that can be used throughout.


//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+
#include "contacts.h"

// Clear the standard input buffer
void clearKeyboard(void);

// pause:
// Put function prototype below:
void pause(void);

// getInt:
// Put function prototype below:
int getInt(void);
int getInt2(void);
// getIntInRange:
// Put function prototype below:
int getIntInRange(int, int);

// yes:
// Put function prototype below:
int yes(void);

// menu:
// Put function prototype below:
int menu(void);

// ContactManagerSystem:
// Put function prototype below:
void contactManagerSystem(void);


// Generic function to get a ten-digit phone number:
// getTenDigitPhone:
void getTenDigitPhone(char[]);

// findContactIndex:
int findContactIndex(const struct Contact[], int, const char[]);

// displayContactHeader:
void displayContactHeader(void);

// displayContactFooter:
void displayContactFooter(int);

// displayContact:
void displayContact(const struct Contact*);

// displayContacts:
void displayContacts(const struct Contact[], int);

// searchContacts:
void searchContacts(const struct Contact[], int);

// addContact:
void addContact(struct Contact[], int);

// updateContact:
void updateContact(struct Contact[], int);

// deleteContact:
void deleteContact(struct Contact[], int);

// sortContacts:
void sortContacts(struct Contact[], int);