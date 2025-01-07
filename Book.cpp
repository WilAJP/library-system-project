/********************************************************************/
/* Author:          Wilfred Jimenez                                 */
/* Creation Date:   December 7, 2024                                */
/* Last Edited:     December 8, 2024                                */
/* Filename:        Book.cpp                                        */
/* Purpose:                                                         */
/*      This file implements the Book class defined in Book.h. It   */
/*      provides constructors for creating Book objects and methods */
/*      for accessing and modifying the attributes of a book, such  */
/*      as ISBN, title, author, total copies, and available copies. */
/********************************************************************/
#include "Book.h"

using namespace std; 

//method definitions

////////////////////////////////////////////////////////
//  Function name:  Book (Default Constructor)
//  Description:    Creates a Book object with default values 
//                  for ISBN, title, author, total copies, 
//                  and available copies.
//  Parameters:     None
//  
//  Return Value:   None
////////////////////////////////////////////////////////
//default constructor, used to create a Book object with default values when no initial data is provided.
//Ex: Book myBook;, myBook.setTitle("The Grinch"); 
//AND when creating data structures of that object. Ex: Book library[10]; Creates 10 `Book` objects with default values
Book::Book() : ISBN(""), title(""), author(""), totalCopies(0), availableCopies(0) {}; 

////////////////////////////////////////////////////////
//  Function name:  Book (Parameterized Constructor)
//  Description:    Creates a Book object with specified values 
//                  for ISBN, title, author, total copies, and 
//                  available copies.
//  Parameters:     
//      string isbn         - The ISBN of the book.
//      string title        - The title of the book.
//      string author       - The author of the book.
//      int total           - Total number of copies of the book.
//      int available       - Number of available copies of the book.
//  
//  Return Value:   None
////////////////////////////////////////////////////////
//parameterized constructor for when initializing all attributes at the time of creation.
//Ex: Book myBook("978-3-16-148410-0", "C++ Programming", "John Doe", 5, 3);
Book::Book(string isbn, string title, string author, int total, int available)
    : ISBN(isbn), title(title), author(author), totalCopies(total), availableCopies(available) {};


////////////////////////////////////////////////////////
//  Function name:  getISBN
//  Description:    Retrieves the ISBN of the book.
//  Parameters:     None
//  
//  Return Value:   string - The ISBN of the book.
////////////////////////////////////////////////////////
string Book::getISBN() const
{
    return ISBN; 
}

////////////////////////////////////////////////////////
//  Function name:  getTitle
//  Description:    Retrieves the title of the book.
//  Parameters:     None
//  
//  Return Value:   string - The title of the book.
////////////////////////////////////////////////////////
string Book::getTitle() const
{
    return title;
}


////////////////////////////////////////////////////////
//  Function name:  getAuthor
//  Description:    Retrieves the author of the book.
//  Parameters:     None
//  
//  Return Value:   string - The author of the book.
////////////////////////////////////////////////////////
string Book::getAuthor() const
{
    return author;
}

////////////////////////////////////////////////////////
//  Function name:  getTotalCopies
//  Description:    Retrieves the total number of copies of the book.
//  Parameters:     None
//  
//  Return Value:   int - The total number of copies of the book.
////////////////////////////////////////////////////////
int Book::getTotalCopies() const
{
    return totalCopies; 
}

////////////////////////////////////////////////////////
//  Function name:  getAvailableCopies
//  Description:    Retrieves the number of available copies of the book.
//  Parameters:     None
//  
//  Return Value:   int - The number of available copies of the book.
////////////////////////////////////////////////////////
int Book::getAvailableCopies() const
{
    return availableCopies; 
}

////////////////////////////////////////////////////////
//  Function name:  setISBN
//  Description:    Sets the ISBN of the book.
//  Parameters:     
//      string isbn - The new ISBN to set.
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void Book::setISBN(string isbn)
{
    ISBN = isbn; 
}

////////////////////////////////////////////////////////
//  Function name:  setTitle
//  Description:    Sets the title of the book.
//  Parameters:     
//      string titl - The new title to set.
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void Book::setTitle(string titl)
{
    title = titl; 
}

////////////////////////////////////////////////////////
//  Function name:  setAuthor
//  Description:    Sets the author of the book.
//  Parameters:     
//      string auth - The new author to set.
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void Book::setAuthor(string auth)
{
    author = auth; 
}

////////////////////////////////////////////////////////
//  Function name:  setTotalCopies
//  Description:    Sets the total number of copies of the book.
//  Parameters:     
//      int total - The new total number of copies to set.
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void Book::setTotalCopies(int total)
{
    totalCopies = total; 
}

////////////////////////////////////////////////////////
//  Function name:  setAvailableCopies
//  Description:    Sets the number of available copies of the book.
//  Parameters:     
//      int available - The new number of available copies to set.
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void Book::setAvailableCopies(int available)
{
    availableCopies = available; 
}