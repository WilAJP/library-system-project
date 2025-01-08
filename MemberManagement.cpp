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
#include <ctime>
#include <cstdlib>

//defaul constructor 
MemberManagement::MemberManagement() = default;
//parametarized constructor
MemberManagement::MemberManagement(std::vector<Member> mem) : memb(mem) {}; 

//documentation
bool MemberManagement::isMembEmpty() const
{
    if (memb.empty())
    {
        std::cout << "\nThere are no Members in the system. Please add a member and try again.\n"; 
        return true; 
    }
    return false; 
}

//documentation, add a function that checks for duplicate member id. 
std::string MemberManagement::generateMemberId()
{
    // Seed the random number generator with the current time
    srand(time(0));
    std::string tempMemberId{};

    for (int i = 0; i < 6; i++) 
    {
        int randomNumber = rand() % 10; //random number between 0-9
        tempMemberId += std::to_string(randomNumber); //turn random num into string and append to member id. 
    }
    return tempMemberId;    //return 6 "digit" id
}

//documentation
void MemberManagement::addMember()
{
    std::string tempMemId{}; 
    std::string tempFirstName{}; 
    std::string tempLastName{};
    std::string tempEmail{}; 
    std::string tempPhone{}; 

    tempMemId = generateMemberId(); 

    std::cin.ignore(); 
    std::cout << "\nPlease enter first name: ";
    getline(std::cin, tempFirstName); 

    std::cout << "Please enter last name: ";
    getline(std::cin, tempLastName);

    std::cout << "Please enter email: "; 
    getline(std::cin, tempEmail); 

    std::cout << "Please enter phone number: "; 
    getline(std::cin, tempPhone); 

    //push member object to the back of the vector. 
    memb.emplace_back(tempMemId, tempFirstName, tempLastName, tempEmail, tempPhone); 

}

void MemberManagement::deleteMember()
{
    std::string tempId{}; 

    //check if memb container is empty, if true, return. if false continue. 
    if (isMembEmpty())
    {
        return; 
    }

    std::cin.ignore(); 
    std::cout << "\nPlease enter member id: ";
    getline(std::cin, tempId); 

    //look for object with matching member id within memb container and if found, delete it. 
    for (auto it = memb.begin(); it != memb.end(); it++)
    {
        if (it->getMemberId() == tempId)
        {
            //delete object at the index of current iterator. 
            memb.erase(it);
            std::cout << "Member Successfully Deleted.\n";
            return;
        }
    }

    std::cout << "No matching member ID found, please try again.\n"; 
    return; 
}

void MemberManagement::searchMember() const
{
    
}

void MemberManagement::displayAllMembers() const
{
    if (isMembEmpty())
    {
        return; 
    }
    
    std::cout << "\n"; 

    for (const auto& member : memb)
    {
        std::cout << "Member ID: " << member.getMemberId()
            << "\nFirst Name: " << member.getFirstName()
            << "\nLast Name: " << member.getLastName()
            << "\nEmail: " << member.getEmail()
            << "\nPhone Number: " << member.getPhone() << std::endl; 
    }
}

