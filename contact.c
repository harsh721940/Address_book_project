#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact.h"
#include "file.h"
#include "populate.h"

void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;

    // Uncomment if sir wants dummy data
    // populateAddressBook(addressBook);

    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook);
    exit(EXIT_SUCCESS);
}

void createContact(AddressBook *addressBook)
{
    if(addressBook->contactCount >= MAX_CONTACTS)
    {
        printf("Address Book Full\n");
        return;
    }

    printf("Enter Name : ");
    scanf(" %[^\n]",
          addressBook->contacts[addressBook->contactCount].name);

    printf("Enter Phone : ");
    scanf("%s",
          addressBook->contacts[addressBook->contactCount].phone);

    printf("Enter Email : ");
    scanf("%s",
          addressBook->contacts[addressBook->contactCount].email);

    addressBook->contactCount++;

    printf("Contact Added Successfully\n");
}

void searchContact(AddressBook *addressBook)
{
    int choice;
    char key[50];

    printf("\n1. Search by Name\n");
    printf("2. Search by Phone\n");
    printf("3. Search by Email\n");
    printf("4. Exit\n");

    printf("Enter your choice : ");
    scanf("%d",&choice);

    if(choice == 4)
        return;

    printf("Enter Search Key : ");
    scanf(" %[^\n]", key);

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if((choice == 1 &&
            strcmp(addressBook->contacts[i].name,key) == 0) ||

           (choice == 2 &&
            strcmp(addressBook->contacts[i].phone,key) == 0) ||

           (choice == 3 &&
            strcmp(addressBook->contacts[i].email,key) == 0))
        {
            printf("\nName  : %s\n",
                   addressBook->contacts[i].name);

            printf("Phone : %s\n",
                   addressBook->contacts[i].phone);

            printf("Email : %s\n",
                   addressBook->contacts[i].email);

            return;
        }
    }

    printf("Contact Not Found\n");
}

void editContact(AddressBook *addressBook)
{
    char name[50];
    int choice;

    printf("Enter Search Name : ");
    scanf(" %[^\n]", name);

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].name,name) == 0)
        {
            printf("\n1. Edit Name\n");
            printf("2. Edit Phone\n");
            printf("3. Edit Email\n");
            printf("4. Exit\n");

            printf("Enter Choice : ");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1:
                    printf("Enter New Name : ");
                    scanf(" %[^\n]",
                          addressBook->contacts[i].name);
                    break;

                case 2:
                    printf("Enter New Phone : ");
                    scanf("%s",
                          addressBook->contacts[i].phone);
                    break;

                case 3:
                    printf("Enter New Email : ");
                    scanf("%s",
                          addressBook->contacts[i].email);
                    break;

                case 4:
                    return;

                default:
                    printf("Invalid Choice\n");
                    return;
            }

            printf("Contact Updated Successfully\n");
            return;
        }
    }

    printf("Contact Not Found\n");
}

void deleteContact(AddressBook *addressBook)
{
    char name[50];

    printf("Enter Name to Delete : ");
    scanf(" %[^\n]", name);

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].name,name) == 0)
        {
            for(int j = i;
                j < addressBook->contactCount - 1;
                j++)
            {
                addressBook->contacts[j] =
                addressBook->contacts[j + 1];
            }

            addressBook->contactCount--;

            printf("Contact Deleted Successfully\n");
            return;
        }
    }

    printf("Contact Not Found\n");
}

void listContacts(AddressBook *addressBook)
{
    if(addressBook->contactCount == 0)
    {
        printf("No Contacts Found\n");
        return;
    }

    printf("\nContacts List\n\n");

    printf("\n--------------------------------------------------------------------------------\n");
    printf("| %-5s | %-20s | %-15s | %-30s |\n",
        "S.No", "Name", "Phone", "Email");
    printf("--------------------------------------------------------------------------------\n");

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        printf("| %-5d | %-20s | %-15s | %-30s |\n",
            i + 1,
            addressBook->contacts[i].name,
            addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
    }

    printf("--------------------------------------------------------------------------------\n");
}