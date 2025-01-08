//documentation
#ifndef TRANSACTIONMANAGEMENT_H
#define TRANSACTIONMANAGEMENT_H

#include <vector>
#include <string>
#include "Transaction.h"
#include "BookManagement.h"
#include "MemberManagement.h"

class TransactionManagement 
{
    public:
        void issueBook(const std::string& memberID, const std::string& isbn, const std::string& issuedDate,
            BookManagement& bookManager, MemberManagement& memberManager);
        void returnBook(const std::string& memberID, const std::string& isbn, const std::string& returnDate,
            BookManagement& bookManager);
        void searchIssuedBookByISBN(const std::string& isbn) const;
        void searchIssuedBookByMember(const std::string& memberID) const;

    private:
        std::vector<Transaction> transactions;
};

#endif

