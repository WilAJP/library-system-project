/********************************************************************/
/* Author:          Wilfred Jimenez                                 */
/* Creation Date:   December 22, 2024                               */
/* Last Edited:     December 24, 2024                               */
/* Filename:        MemberManagement.h                              */
/* Purpose:                                                         */
/*      This file defines the MemberManagement class. It provides   */
/*      functionalities for managing members, including adding,     */
/*      deleting, searching, and displaying members. It also        */
/*      contains utility methods for member ID generation and       */
/*      checking for duplicates.                                    */
/********************************************************************/
#ifndef MEMBERMANAGEMENT_H
#define MEMBERMANAGEMENT_H

#include <vector>
#include <string>
#include "Member.h"
#include "SearchMethods.h"

class MemberManagement
{
    public:
        MemberManagement(); 
        MemberManagement(std::vector<Member> mem); 

        void addMember(); 
        void deleteMember(); 
        void searchMember(const std::string& value, const SearchStrategy& strategy) const; 
        void displayAllMembers() const; 
        bool isMemberValid(const std::string& memberID) const;

    private: 
        std::vector<Member> memberList; 
        bool isMembEmpty() const; 
        //bool isDuplicate() const; 
        std::string generateMemberId(); 
};

#endif