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


#include "contacts.h"
#include "contactHelpers.h"

void getName(struct Name* name)
{
    int i = 1;


    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]%*c", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");


    if (yes())

    {

        printf("Please enter the contact's middle initial(s): ");
        scanf(" %15[^\n]s\n", name->middleInitial);
        name->middleInitial[ 7] = '\0';
        clearKeyboard();
        
    }
    if (i == 1) {
        printf("Please enter the contact's last name: ");
        scanf(" %10[^\n]s\n", name->lastName);

        clearKeyboard();

    }
	
	
}


void getAddress(struct Address* address)
{
    
   
   
        printf("Please enter the contact's street number: ");
      
     if (getInt() < 0) 
    {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        getInt();
    }

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", address->street);

    printf("Do you want to enter an apartment number? (y or n): ");

    if (yes() == 1)
    {
        
            printf("Please enter the contact's apartment number: ");
            if (getInt() < 0) 
            
            {

           printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
           scanf("%d%*c", &address->apartmentNumber);
            };   
	 }

    printf("Please enter the contact's postal code: ");
    scanf("%30[^\n]%*c", address->postalCode);

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
}



void getNumbers(struct Numbers* numbers)
{
    char yesNo;

        printf("Please enter the contact's cell phone number: ");
      
        getInt2(numbers->cell);

        
        
        
        
     
    

    printf("Do you want to enter a home phone number? (y or n): ");
 
    if (yes())
    {
        printf("Please enter the contact's home phone number: ");
        getInt2(numbers->home);
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    scanf("%c%*c", &yesNo);

    if (yesNo == 'y' || yesNo == 'Y')
    {
        printf("Please enter the contact's business phone number: ");
        getInt2(numbers->business);
    }
}


void getContact(struct Contact* contact) {
 
	getName(&(*contact).name);
    getAddress(&(*contact).address);
    getNumbers(&(*contact).numbers);
}
	


void getContact(struct Contact* contact) {
 
	getName(&(*contact).name);
    getAddress(&(*contact).address);
    getNumbers(&(*contact).numbers);
}
	
