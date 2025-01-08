//documentation 
#include "TransactionManagement.h"
#include <iostream>

void TransactionManagement::issueBook(const std::string& memberID, const std::string& isbn, const std::string& issuedDate,
    BookManagement& bookManager, MemberManagement& memberManager)
{
    //check if both isbn and member id are in system, if not return
    if (!bookManager.isBookAvailable(isbn)) 
    {
        return;
    }
    if (!memberManager.isMemberValid(memberID)) 
    {
        return;
    }

    transactions.emplace_back(memberID, isbn, issuedDate, "");
    bookManager.updateBookAvailability(isbn, -1);
    std::cout << "Book issued successfully.\n";
}

//documentation
void TransactionManagement::returnBook(const std::string& memberID, const std::string& isbn,
    const std::string& returnDate, BookManagement& bookManager) 
{
    for (auto& transaction : transactions) 
    {   //if memberId, and isbn match as well as return date is blank. 
        if (transaction.getMemberId() == memberID && transaction.getIsbn() == isbn && transaction.getReturnDate().empty()) 
        {
            transaction.setReturnDate(returnDate);
            bookManager.updateBookAvailability(isbn, 1);    //add one to avaible copies. 
            std::cout << "Book returned successfully.\n";
            return;
        }
    }
    std::cout << "No active transaction found for Member ID " << memberID << " and ISBN " << isbn << ".\n";
}

//documentation
void TransactionManagement::searchIssuedBookByISBN(const std::string& isbn) const 
{
    bool found = false;
    for (const auto& transaction : transactions) 
    {
        if (transaction.getIsbn() == isbn && transaction.getReturnDate().empty()) 
        {
            transaction.display();
            found = true;
        }
    }
    if (!found) 
    {
        std::cout << "No active transactions found for ISBN " << isbn << ".\n";
    }
}

//documentation
void TransactionManagement::searchIssuedBookByMember(const std::string& memberID) const 
{
    bool found = false;
    for (const auto& transaction : transactions) 
    {
        if (transaction.getMemberId() == memberID && transaction.getReturnDate().empty()) 
        {
            transaction.display();
            found = true;
        }
    }
    if (!found) 
    {
        std::cout << "No active transactions found for Member ID " << memberID << ".\n";
    }
}
