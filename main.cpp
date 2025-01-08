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
#include <limits>
#include "Book.h"
#include "BookManagement.h"
#include "Member.h"
#include "MemberManagement.h"
#include "SearchMethods.h"
#include "Transaction.h"
#include "TransactionManagement.h"

using namespace std;

void displayMenu();
void manageBooks(BookManagement& bookManager);
void manageMembers(MemberManagement& memberManager);
void memberSearchMenu(MemberManagement& memberManager);
void manageTransactions(BookManagement& bookManager, MemberManagement& memberManager, TransactionManagement& transactionManager);
void reportInfo();

int main()
{
    BookManagement bookManager; 
    MemberManagement memberManager; 
    TransactionManagement transactionManager; 

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
            manageMembers(memberManager);
            break;

        case 3:
            manageTransactions(bookManager, memberManager, transactionManager);
            break;

        case 4:
            //reportInfo();
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
//  Function name:  manageBooks
//  Description:    Displays the Book Management menu and allows 
//                  the user to perform actions such as adding, 
//                  deleting, searching, and displaying books.
//  Parameters:     bookManager - Reference to the BookManagement object
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
//  Function name:  manageMembers
//  Description:    Displays the Member Management menu and allows 
//                  the user to perform actions such as adding, 
//                  deleting, searching, and displaying members.
//  Parameters:     memberManager - Reference to the MemberManagement object
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
            memberSearchMenu(memberManager);
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

////////////////////////////////////////////////////////
//  Function name:  memberSearchMenu
//  Description:    Displays the Member Search menu and allows the 
//                  user to search for members using various criteria 
//                  like ID, name, email, or phone number.
//  Parameters:     memberManager - Reference to the MemberManagement object
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void memberSearchMenu(MemberManagement& memberManager)
{
    while (true)
    {
        cout << endl;
        cout << "========= Member Search =========" << endl;
        cout << "1. By Member ID" << endl;
        cout << "2. By Last Name" << endl;
        cout << "3. By Email" << endl;
        cout << "4. By Phone Number" << endl;
        cout << "5. Back" << endl;
        cout << "Enter choice: ";

        int tempChoice{ 0 };
        cin >> tempChoice;

        std::string searchKey; 

        switch (tempChoice)
        {
        case 1:
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter Member ID: ";
            getline(std::cin, searchKey);
            SearchByMemberID strategy;
            memberManager.searchMember(searchKey, strategy);
            break;
        }
        case 2:
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter Name: ";
            getline(std::cin, searchKey);
            SearchByName strategy;
            memberManager.searchMember(searchKey, strategy);
            break;
        }
        case 3:
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter Email: ";
            getline(std::cin, searchKey);
            SearchByEmail strategy;
            memberManager.searchMember(searchKey, strategy);
            break;
        }
        case 4:
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter Phone Number: ";
            getline(std::cin, searchKey);
            SearchByPhone strategy;
            memberManager.searchMember(searchKey, strategy);
            break;
        }
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
void manageTransactions(BookManagement& bookManager, MemberManagement& memberManager, TransactionManagement& transactionManager) {
    while (true) {
        std::cout << "\n========= Transactions =========" << std::endl;
        std::cout << "1. Issue Book to Member" << std::endl;
        std::cout << "2. Return Book" << std::endl;
        std::cout << "3. Search Issued Book by ISBN" << std::endl;
        std::cout << "4. Search Issued Book by Member" << std::endl;
        std::cout << "5. Back" << std::endl;
        std::cout << "Enter choice: ";

        int tempChoice{ 0 };
        std::cin >> tempChoice;

        // Clear the input buffer
        if (std::cin.fail()) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid choice.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear newline

        std::string memberID, isbn, date;

        switch (tempChoice) {
        case 1:
            std::cout << "Enter Member ID: ";
            std::getline(std::cin, memberID);
            std::cout << "Enter ISBN: ";
            std::getline(std::cin, isbn);
            std::cout << "Enter Issued Date (YYYY-MM-DD): ";
            std::getline(std::cin, date);
            transactionManager.issueBook(memberID, isbn, date, bookManager, memberManager);
            break;

        case 2:
            std::cout << "Enter Member ID: ";
            std::getline(std::cin, memberID);
            std::cout << "Enter ISBN: ";
            std::getline(std::cin, isbn);
            std::cout << "Enter Return Date (YYYY-MM-DD): ";
            std::getline(std::cin, date);
            transactionManager.returnBook(memberID, isbn, date, bookManager);
            break;

        case 3:
            std::cout << "Enter ISBN: ";
            std::getline(std::cin, isbn);
            transactionManager.searchIssuedBookByISBN(isbn);
            break;

        case 4:
            std::cout << "Enter Member ID: ";
            std::getline(std::cin, memberID);
            transactionManager.searchIssuedBookByMember(memberID);
            break;

        case 5:
            return; // Exit the menu

        default:
            std::cout << "Invalid choice, try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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