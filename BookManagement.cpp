/********************************************************************/
/* Author:          Wilfred Jimenez                                 */
/* Creation Date:   December 18, 2024                               */
/* Last Edited:     December 21, 2024                               */
/* Filename:        BookManagement.cpp                              */
/* Purpose:                                                         */
/*      This file implements the BookManagement class defined in    */
/*      BookManagement.h. It provides methods for adding, deleting, */
/*      searching, and displaying books in the library, as well as  */
/*      a helper method to check if the library is empty.           */
/********************************************************************/
#include "BookManagement.h"
#include <iostream>
#include <string>


//default constructor, handles when no parameters are passed in.
BookManagement::BookManagement() = default; 

//paramatized constructor, handles paremeters
BookManagement::BookManagement(vector<Book> lib) : library(lib) {}; 

////////////////////////////////////////////////////////
//  Function name:  isLibraryEmpty
//  Description:    Checks if the library is empty and 
//                  displays a message if it is.
//  Parameters:     None
//  
//  Return Value:   bool - True if the library is empty,
//                         False otherwise.
////////////////////////////////////////////////////////
bool BookManagement::isLibraryEmpty() const
{
    if (library.empty())
    {
        std::cout << "\nNo books in the library. Please add a book and try again\n";
        return true; 
    }
    return false; 
}

////////////////////////////////////////////////////////
//  Function name:  addBook
//  Description:    Adds a new book to the library by 
//                  prompting the user for ISBN, title, 
//                  author, and the number of total copies.
//                  Checks for duplicate ISBNs.
//  Parameters:     None
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void BookManagement::addBook()
{
    std::string isbn{ " " }; 
    std::string title{ " " }; 
    std::string author{ " " };
    int total{ 0 }; 

    std::cin.ignore();              
    std::cout << "\nEnter ISBN: "; 
    getline(std::cin, isbn); 

    //Should be seperate helped funciton
    //check for ISBN duplicate edge case. 
    if (!library.empty())
    {
        for (const auto& book : library)
        {
            if (book.getISBN() == isbn)
            {
                std::cout << "\nDuplicate ISBN, Please try again\n";
                return; 
            }
        }
    }
    
    std::cout << "Enter Title: "; 
    getline(std::cin, title);

    std::cout << "Enter Author: ";
    getline(std::cin, author);

    std::cout << "Enter Amount to be Added: ";       
    std::cin >> total; 

    library.emplace_back(isbn, title, author, total, total);    //take notes on why emplace and not push_back
    std::cout << "Book Added Succesfully" << std::endl; 

}

////////////////////////////////////////////////////////
//  Function name:  deleteBook
//  Description:    Deletes a book from the library by 
//                  searching for the provided ISBN. If 
//                  found, the book is removed; otherwise, 
//                  a message is displayed.
//  Parameters:     None
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void BookManagement::deleteBook()
{
    //check if library is empty
    if (isLibraryEmpty())
    {
        return;
    }
    std::string isbn{ " " }; 

    std::cin.ignore();        //clear the newline character from last input
    std::cout << "Enter ISBN: "; 
    getline(std::cin, isbn); 

    //Iterators allows you to access individual objects within a container, allowing you to modify each object. 
    //iterator is abbriviated to "it", "it" is the most common naming convention for a simple loop. 
    //can get more especific like "bookIt" if used in more complex system. 
    for (auto it = library.begin(); it != library.end(); it++)
    {
        if (it->getISBN() == isbn) 
        {
            //delete object at the index of current iterator 
            library.erase(it); 
            std::cout << "Book Successfully Deleted \n"; 
            return; 
        }
    }

}

////////////////////////////////////////////////////////
//  Function name:  searchBook
//  Description:    Searches for a book in the library by 
//                  ISBN and displays its details if found. 
//                  If the library is empty or the book is 
//                  not found, displays an appropriate message.
//  Parameters:     None
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void BookManagement::searchBook() const  //const because we are only displaying. 
{
    //check if library is empty
    if (isLibraryEmpty())
    {
        return; 
    }

    std::string isbn{ " " };

    std::cin.ignore();        //clear the newline character from last input
    std::cout << "Enter ISBN: ";
    getline(std::cin, isbn);
 
    //using a ranged based loop here because we do not need to modify anything. 
    for (const auto& book : library)
    {
        if (book.getISBN() == isbn)
        {   
            std::cout << "\nBook Found: \n"
                 << "Title: " << book.getTitle() << "\n"
                 << "Author: " << book.getAuthor() << "\n"
                 << "Total Copies: " << book.getTotalCopies() << "\n" 
                 << "Available Copies: " << book.getAvailableCopies() << "\n"; 
        }
        else
        {
            std::cout << "Book Not Found, try again \n";
        }
    }
    
}

////////////////////////////////////////////////////////
//  Function name:  displayAllBooks
//  Description:    Displays the details of all books in the 
//                  library, including ISBN, title, author, 
//                  total copies, and available copies. 
//  Parameters:     None
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void BookManagement::displayAllBooks() const
{
    //check if library is empty
    if (isLibraryEmpty())
    {
        return;
    }

    std::cout << "\n"; //add new line for space between input and output

    for (const auto& book : library)    //ranged based for loop since no modification is needed. 
    {
        std::cout << "ISBN: " << book.getISBN() << "\n"
            << "Title: " << book.getTitle() << "\n"
            << "Author: " << book.getAuthor() << "\n"
            << "Total Copies: " << book.getTotalCopies() << "\n"
            << "Available Copies: " << book.getAvailableCopies() << "\n"
            << "-------------------------------------- \n"; 
    }
}