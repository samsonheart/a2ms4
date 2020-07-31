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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <string.h>

#include "contactHelpers.h"

#define MAXCONTACTS 5
// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:



//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 1 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
	while (getchar() != '\n');

}

// pause: Empty function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	printf("\n");
}


// getInt: Empty function definition goes here:
int getInt(void)
{
	int value;
	char check;
	scanf("%d%c", &value, &check);


	while (check != '\n') {
		clearKeyboard();


		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf("%d%c", &value, &check);




	}
	return value;
}
int getInt2(){

	int value;
	char check;
	scanf("%d%c", &value, &check);


	while (check != '\n') {
		clearKeyboard();


		printf("Enter a 10-digit phone number: ");
		scanf("%d%c", &value, &check);




	}
	return value;






}
// getIntInRange: Empty function definition goes here:
int getIntInRange(int low, int high){
int LowHigh, LoopExit = 0;


do {
	LowHigh = getInt();
	if (LowHigh < low || LowHigh > high)
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", low, high);
	else
		LoopExit = 1;
} while (LoopExit != 1);


return LowHigh;
}


// yes: Empty function definition goes here:
int yes(void) {
	int send;
	char yes, check;


	scanf(" %c%c", &yes, &check);


	while (check != '\n' && (yes != 'y' || yes != 'Y' || yes != 'n' || yes != 'N')) {
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");


		scanf(" %c%c", &yes, &check);
	}


	if (yes == 'y' || yes == 'Y')
		send = 1;
	else
		send = 0;
	return send;
}




// menu: Empty function definition goes here:
int menu(void) {
	int option;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	do {
		option = getInt();
		if (option > 6 || option < 0) {
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
		}
	} while (option > 6 || option < 0);
	return option;
}


// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
	struct Contact contacts[MAXCONTACTS] =
	{ { { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
 {
	 { "Maggie", "R.", "Greene" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },
 {
	 { "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	{ "7051112222", "7052223333", "7053334444" } },
 {
	 { "Sasha",{ '\0' }, "Williams" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } },
	};
	int option;
	int yn = 0;
	while (yn == 0) {
		option = menu();
		switch (option)
		{
		case 1:
			displayContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 2:
			addContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 3:
			updateContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 4:
			deleteContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 5:
			searchContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 6:
			sortContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			yn = yes();
			printf("\n");
			if (yn)printf("Contact Management System: terminated\n");
			break;
		default:
			break;
		}
	}
}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[]) {
	scanf("%s", telNum);
	clearKeyboard();
	while (strlen(telNum) != 10) {
		printf("Enter a 10-digit phone number: ");
		scanf("%s", telNum);
		clearKeyboard();
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char number[]) {
	int i;
	for (i = 0; i < size; i++)
	{
		if (strcmp(contacts[i].numbers.cell, number) == 0) {
			return i;
		}
	}
	return -1;
}

// displayContactHeader:
void displayContactHeader(void) {
	printf("\n");
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter:
void displayContactFooter(int total) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", total);
}

// displayContact:
void displayContact(const struct Contact* contact) {
	printf(" %s ", contact->name.firstName);
	if (strlen(contact->name.middleInitial) != 0) printf("%s ", contact->name.middleInitial);
	printf("%s\n", contact->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0) printf("Apt# %d, ", contact->address.apartmentNumber);
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size) {
	int i;
	int count = 0;
	displayContactHeader();
	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) != 0)
		{
			displayContact(&contacts[i]);
			count++;
		}
	}
	displayContactFooter(count);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size) {
	char cellnumb[11];
	int foundIndex;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellnumb);
	foundIndex = findContactIndex(contacts, sizeof(contacts), cellnumb);
	if (foundIndex == -1) {
		printf("*** Contact	NOT FOUND ***\n");
	}
	else {
		printf("\n");
		displayContact(&contacts[foundIndex]);
		printf("\n");
	}
}

// addContact:
void addContact(struct Contact contacts[], int size) {
	int i;
	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) == 0) {
			break;
		}
	}
	if (i == size) printf("\n*** ERROR: The contact list is full! ***\n");
	else {
		printf("\n");
		getContact(&contacts[i]);
		printf("--- New contact added! ---\n");
	}
}

// updateContact:
void updateContact(struct Contact contacts[], int size) {
	char phoneNumb[11];
	int foundIndex;
	int yn;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(phoneNumb);
	foundIndex = findContactIndex(contacts, sizeof(contacts), phoneNumb);
	if (foundIndex == -1) printf("*** Contact NOT FOUND ***\n");
	else {
		printf("\nContact found:\n");
		displayContact(&contacts[foundIndex]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		yn = yes();
		if (yn == 1) getName(&contacts[foundIndex].name);
		printf("Do you want to update the address? (y or n): ");
		yn = yes();
		if (yn == 1) getAddress(&contacts[foundIndex].address);
		printf("Do you want to update the numbers? (y or n): ");
		yn = yes();
		if (yn == 1) getNumbers(&contacts[foundIndex].numbers);
		printf("--- Contact Updated! ---\n");
	}
}

// deleteContact:
void deleteContact(struct Contact contacts[], int size) {
	char phoneNumb[11];
	int foundIndex;
	int yn;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(phoneNumb);
	foundIndex = findContactIndex(contacts, sizeof(contacts), phoneNumb);
	if (foundIndex == -1) printf("*** Contact NOT FOUND ***\n");
	else {
		printf("\nContact found:\n");
		displayContact(&contacts[foundIndex]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		yn = yes();
		if (yn == 1)
		{
			contacts[foundIndex].numbers.business[0] = '\0';
			contacts[foundIndex].numbers.cell[0] = '\0';
			contacts[foundIndex].numbers.home[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
	}
}

// sortContacts:
void sortContacts(struct Contact contact[], int size) {
	int i;
	int j;
	struct Contact temp;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (strlen(contact[i].numbers.cell) != 0 && strlen(contact[j].numbers.cell) != 0) {
				if (strcmp(contact[i].numbers.cell, contact[j].numbers.cell) > 0) {
					temp = contact[i];
					contact[i] = contact[j];
					contact[j] = temp;
				}
			}
		}
	}
	printf("\n--- Contacts sorted! ---\n");
}