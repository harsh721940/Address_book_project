#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fp;

    fp = fopen("Addressbook.csv", "w");

    if(fp == NULL)
    {
        printf("Unable to Open File\n");
        return;
    }

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp,"%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fp);
}

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fp;

    fp = fopen("Addressbook.csv", "r");

    if(fp == NULL)
    {
        return;
    }

    while(fscanf(fp,
                 "%49[^,],%19[^,],%49[^\n]\n",
                 addressBook->contacts[addressBook->contactCount].name,
                 addressBook->contacts[addressBook->contactCount].phone,
                 addressBook->contacts[addressBook->contactCount].email) == 3)
    {
        addressBook->contactCount++;
    }

    fclose(fp);
}