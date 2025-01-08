//documentation
#include "Transaction.h"
#include <iostream>

//method definitions

//documentation
Transaction::Transaction(std::string memId, std::string bookIsbn, std::string issDate, std::string retDate)
    : memberId(memId), isbn(bookIsbn), issuedDate(issDate), returnDate(retDate) {}; 

void Transaction::setReturnDate(std::string retDate)
{
    returnDate = retDate;
}

//documentation
std::string Transaction::getMemberId() const
{
    return memberId; 
}

//documenation
std::string Transaction::getIsbn() const
{
    return isbn; 
}

//documentation
std::string Transaction::getIssuedDate() const
{
    return issuedDate; 
}

//documentation
std::string Transaction::getReturnDate() const
{
    return returnDate; 
}

//documentation
void Transaction::display() const
{
    std::cout << "\nTransaction Details:"
        << "\nMember ID: " << memberId
        << "\nISBN: " << isbn
        << "\nIssued Date: " << issuedDate
        << "\nReturn Date: " << (returnDate.empty() ? "Not Returned" : returnDate)
        << "\n--------------------------------------";
}