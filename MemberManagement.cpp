/********************************************************************/
/* Author:          Wilfred Jimenez                                 */
/* Creation Date:   December 22, 2024                               */
/* Last Edited:     December 24, 2024                               */
/* Filename:        Member.cpp                                      */
/* Purpose:                                                         */

/********************************************************************/
#include "MemberManagement.h"
#include <iostream>
#include <string>
#include <vector>

//defaul constructor 
MemberManagement::MemberManagement() = default;
//parametarized constructor
MemberManagement::MemberManagement(std::vector<Member> mem) : memb(mem) {}; 

//documentation
bool MemberManagement::isMembEmpty() const
{
    if (memb.empty())
    {
        std::cout << "There are no Members in the system. Please add a member and try again.\n"; 
        return true; 
    }
    return false; 
}

//documentation
void MemberManagement::addMember()
{
    std::string tempName{ " " }; 
    std::string tempEmail{ " " }; 
    std::string tempPhone{ " " }; 

    std::cin.ignore(); 
    std::cout << "Please enter name: ";
    getline(std::cin, tempName); 

    std::cout << "Please Enter Email: "; 
    getline(std::cin, tempEmail); 
}

