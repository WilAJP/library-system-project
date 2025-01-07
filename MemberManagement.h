/********************************************************************/
/* Author:          Wilfred Jimenez                                 */
/* Creation Date:   December 22, 2024                               */
/* Last Edited:     December 24, 2024                               */
/* Filename:        Member.cpp                                      */
/* Purpose:                                                         */

/********************************************************************/
#ifndef MEMBERMANAGEMENT_H
#define MEMBERMANAGEMENT_H

#include <vector>
#include <string>
#include "Member.h"

class MemberManagement
{
    public:
        MemberManagement(); 
        MemberManagement(std::vector<Member> mem); 

        void addMember(); 
        void deleteMember(); 
        void searchMember() const; 
        void displayAllMembers() const; 

    private: 
        std::vector<Member> memb; 
        bool isMembEmpty() const; 
        bool isDuplicate() const; 
        int generateMemberId(); 
};

#endif