//documentation
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction
{
    public:
        //parameterized constructor, no default constructor because there will always be parameters. 
        Transaction(std::string memberId, std::string isbn, std::string issuedDate, std::string returnDate); 

        //setters
        void setReturnDate(std::string retDate); 

        //getters
        std::string getMemberId() const; 
        std::string getIsbn() const; 
        std::string getIssuedDate() const; 
        std::string getReturnDate() const; 

        void display() const; 

    private:
        std::string memberId; 
        std::string isbn; 
        std::string issuedDate; 
        std::string returnDate; 

};

#endif 