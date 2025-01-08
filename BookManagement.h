/********************************************************************/
/* Author:          Wilfred Jimenez                                 */
/* Creation Date:   December 18, 2024                               */
/* Last Edited:     December 20, 2024                               */
/* Filename:        BookManagement.h                                */
/* Purpose:                                                         */
/*      This header file defines the BookManagement class, which    */
/*      provides functionality to manage a collection of books in   */
/*      the library system. It includes methods for adding,         */
/*      deleting, searching, and displaying books, along with a     */
/*      helper method to check if the library is empty.             */
/********************************************************************/
#ifndef BOOKMANAGEMENT_H
#define BOOKMANAGEMENT_H

#include <vector>
#include "Book.h"
#include <string>

using namespace std;

class BookManagement
{
    public:
        BookManagement(); 
        BookManagement(vector<Book> lib); 

        void addBook(); 
        void deleteBook(); 
        void searchBook() const; 
        void displayAllBooks() const; 


    private:
        vector<Book> library;       //collection of Book objects, stored in a vector
        bool isLibraryEmpty() const; 

}; 


#endif 