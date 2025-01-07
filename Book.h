/********************************************************************/
/* Author:          Wilfred Jimenez                                 */
/* Creation Date:   December 7, 2024                                */
/* Last Edited:     December 8, 2024                                */      
/* Filename:        Book.h                                          */
/* Purpose:                                                         */
/*      This header file defines the book class, with data such as  */
/*      ISBN, title, author, and available copies. It also provides */
/*      methods for accessing and modifything this data.            */
/********************************************************************/

#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std; 

class Book
{
    //method declarations
    public:
        //default constructor, used to create a Book object with default values when no initial data is provided.
        Book(); 
        //parameterized constructor for when initializing all attributes at the time of creation.
        Book(string isbn, string title, string author, int total, int available); 

        //getters
        string getISBN() const;     //const after a method to not modify the object.
        string getTitle() const;    //if the const was like this: const string getTitle();, then this method would return a 
        string getAuthor() const;   //const string but could still modify the object. 
        int getTotalCopies() const; 
        int getAvailableCopies() const; 

        //setters 
        void setISBN(string isbn);
        void setTitle(string titl);
        void setAuthor(string auth);
        void setTotalCopies(int total);
        void setAvailableCopies(int available);


    private: 
        string ISBN; 
        string title; 
        string author; 
        int totalCopies; 
        int availableCopies; 
};


#endif