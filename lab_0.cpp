#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstdio>

struct Friend
{
    char Surname[32];
    char Name[32];
    char Middle_name[32];
    char Birthdate[32];
    char Address[64];
    char Num_phone[16];
} Friends[100];

int Friend_count = 0;

void printFriend()
{
    if (Friend_count == 0)
    {
        std::cout << "You hadn't friend :(\n";
    } else {
        std::cout << "Friend list\n";
        for (int i = 0; i < Friend_count; i++)
        {
            std::cout << i + 1 << ". " << "FIO: " << Friends[i].Surname << " " << Friends[i].Name << " " << Friends[i].Middle_name << ", Birthdate: " << Friends[i].Birthdate << ", Adress: " << Friends[i].Address << ", Phone number: " << Friends[i].Num_phone << ".\n"; 
        }
    }
}

void addFriend()
{
    std::cout << "Enter friend's Surname: ";
    std::cin >> Friends[Friend_count].Surname;
    std::cout << "Enter friend's Name: ";
    std::cin >> Friends[Friend_count].Name;
    std::cout << "Enter friend's Middle_name: ";
    std::cin >> Friends[Friend_count].Middle_name;
    std::cout << "Enter friend's Birthdate (dd.mm.yyyy): ";
    std::cin >> Friends[Friend_count].Birthdate;
    std::cout << "Enter friend's Address: ";
    std::cin >> Friends[Friend_count].Address;
    std::cout << "Enter friend's Phone: ";
    std::cin >> Friends[Friend_count].Num_phone;
    Friend_count++;
}

void deleteFriend()
{
    int id;
    std::cout << "Enter id of friend to delete: ";
    std::cin >> id;
    id--;
    
    if (id < 0 || id >= Friend_count)
    {
        std::cout << "\nInvalid id\n";
        return;
    }

    for (int i = id; i < Friend_count - 1; i++)
    {
        Friends[i] = Friends[i + 1];
    }
    Friend_count--;
    std::cout << "The deletion was successful!\n";
}

void getFriendInMonth()
{
    int Month;
    std::cout << "Enter birth month: ";
    std::cin >> Month;
    for (int i = 0; i < Friend_count; i++)
    {
        int fMonth;
        std::sscanf (Friends[i].Birthdate, "%*d.%d.%*d", &fMonth);
        if (fMonth == Month)
        {
            std::cout << "\n" <<Friends[i].Surname << " " << Friends[i].Name << " " << Friends[i].Middle_name << ", " << Friends[i].Birthdate << ", " << Friends[i].Address << ", " << Friends[i].Num_phone << ".\n";
        }
    }
}

int main()
{
    int choice;
    do
    {
        std:: cout << "\n1. Print friends\n";
        std:: cout << "2. Add friend\n";
        std:: cout << "3. Delete friend\n";
        std:: cout << "4. Get friends by birth month\n";
        std:: cout << "5. Exit\n\n";
        std:: cout << "Enter choice: ";
        std:: cin >> choice;
        switch (choice) 
        {
            case 1:
            printFriend();
            break;
            case 2:
            addFriend();
            break;
            case 3:
            deleteFriend();
            break;
            case 4:
            getFriendInMonth();
            break;
        }

        if (choice <= 0 || choice >= 6)
        {
            std::cout << "\nIncorrect command!\n";
        }  
    } while (choice != 5);
}

//compilirui cherez gcc name.cpp -o name -lstdc++
