/********************************************************************/
/* Author:          Wilfred Jimenez                                 */
/* Creation Date:   December 6, 2024                                */
/* Last Edited:     January 4, 2025                                 */
/* Filename:        main.cpp                                        */
/* Purpose:                                                         */
/*      This program is a simple libray management system. It       */
/*      allows to manage books, members, transactions and display   */
/*      information.                                                */
/********************************************************************/
#include <iostream>
#include "Book.h"
#include "BookManagement.h"
#include "Member.h"
#include "MemberManagement.h"

using namespace std;

void displayMenu();
void manageBooks(BookManagement& bookManager);
void manageMembers(MemberManagement& memberManger);
void memberSearchMenu();
void manageTransactions();
void reportInfo();

int main()
{
    BookManagement bookManager; 
    MemberManagement memberManger; 

    bool condition = true;
    while (condition)
    {
        displayMenu();

        int choice{ 0 };
        cin >> choice;

        switch (choice)
        {
        case 1:
            manageBooks(bookManager);
            break;

        case 2:
            manageMembers(memberManger);
            break;

        case 3:
            manageTransactions();
            break;

        case 4:
            reportInfo();
            break;

        case 5:
            cout << "Exiting program" << endl;
            condition = false;
            break;

        default:
            cout << "Invalid choice, try again. \n";
            //prevents infinite loop when inputting a char instead of int.
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }

    }

    return 0;
}

////////////////////////////////////////////////////////
//  Function name:  displayMenu
//  Description:    Displays the main menu options
//  Parameters:     None
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void displayMenu()
{
    cout << endl;
    cout << "========= Library Management System =========" << endl;
    cout << "1. Book Management" << endl;
    cout << "2. Member Management" << endl;
    cout << "3. Transaction Management" << endl;
    cout << "4. Information Report" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter choice: ";
}

////////////////////////////////////////////////////////
//  Function name:  displayMenu
//  Description:    Displays the Book management menu options
//  Parameters:     None
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void manageBooks(BookManagement& bookManager)
{
    while (true)
    {
        cout << endl; 
        cout << "========= Book Management =========" << endl;
        cout << "1. Add a Book " << endl;
        cout << "2. Delete a Book " << endl;
        cout << "3. Search for a Book" << endl;
        cout << "4. Display All Books" << endl;
        cout << "5. Back" << endl;
        cout << "Enter choice: ";

        int tempChoice{ 0 };
        cin >> tempChoice;

        switch (tempChoice)
        {
        case 1:
            bookManager.addBook(); 
            break;

        case 2:
            bookManager.deleteBook(); 
            break;

        case 3:
            bookManager.searchBook(); 
            break;

        case 4:
            bookManager.displayAllBooks(); 
            break;

        case 5:
            return;
            break;

        default:
            cout << "Invalid choice, try again. \n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    }
}
////////////////////////////////////////////////////////
//  Function name:  displayMenu
//  Description:    Displays the members menu options
//  Parameters:     None
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void manageMembers(MemberManagement& memberManager)
{
    while (true)
    {
        cout << endl;
        cout << "========= Member Management =========" << endl;
        cout << "1. Add a Member "  << endl;
        cout << "2. Delete a Member " << endl;
        cout << "3. Search for a Member" << endl;
        cout << "4. Display All Members" << endl;
        cout << "5. Back" << endl;
        cout << "Enter choice: ";

        int tempChoice{ 0 };
        cin >> tempChoice;

        switch (tempChoice)
        {
        case 1:
            memberManager.addMember(); 
            break;

        case 2:
            memberManager.deleteMember(); 
            break;

        case 3:

            break;

        case 4:
            memberManager.displayAllMembers(); 
            break;

        case 5:
            return;
            break;

        default:
            cout << "Invalid choice, try again. \n";
            //prevents infinite loop when inputting a char instead of int.
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    }
}

void memberSearchMenu()
{
    while (true)
    {
        cout << endl;
        cout << "========= Member Search =========" << endl;
        cout << "1. By Member ID" << endl;
        cout << "2. By Name" << endl;
        cout << "3. By Email" << endl;
        cout << "4. By Phone Number" << endl;
        cout << "5. Back" << endl;
        cout << "Enter choice: ";

        int tempChoice{ 0 };
        cin >> tempChoice;

        switch (tempChoice)
        {
        case 1:
            
            break;

        case 2:
            
            break;

        case 3:

            break;

        case 4:
            
            break;

        case 5:
            return;
            break;

        default:
            cout << "Invalid choice, try again. \n";
            //prevents infinite loop when inputting a char instead of int.
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

////////////////////////////////////////////////////////
//  Function name:  manageTransactions
//  Description:    Displays the transactions menu options
//  Parameters:     None
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void manageTransactions()
{
    while (true)
    {
        cout << endl;
        cout << "========= Transactions =========" << endl;
        cout << "1. Issue Book to Member " << endl;
        cout << "2. Return Book" << endl;
        cout << "3. Search Issued Book" << endl;
        cout << "4. Back" << endl;
        cout << "Enter choice: ";

        int tempChoice{ 0 };
        cin >> tempChoice;

        switch (tempChoice)
        {
        case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:
            return;
            break;

        default:
            cout << "Invalid choice, try again. \n";
            //prevents infinite loop when inputting a char instead of int.
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    }
}

////////////////////////////////////////////////////////
//  Function name:  reportInfo
//  Description:    Displays the report menu
//  Parameters:     None
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void reportInfo()
{
    while (true)
    {
        cout << endl;
        cout << "========= Report =========" << endl;
        cout << "1. Display All Issued Books " << endl;
        cout << "2. Display Overdue Books" << endl;
        cout << "3. Back" << endl;
        cout << "Enter choice: ";

        int tempChoice{0};
        cin >> tempChoice;

        switch (tempChoice)
        {
        case 1:

            break;

        case 2:

            break;

        case 3:
            return;
            break;

        default:
            cout << "Invalid choice, try again. \n"; 
            //prevents infinite loop when inputting a char instead of int.
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    }
}