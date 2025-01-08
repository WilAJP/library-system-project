/********************************************************************/
/* Author:          Wilfred Jimenez                                 */
/* Creation Date:   December 22, 2024                               */
/* Last Edited:     January 7, 2025                                 */
/* Filename:        MemberManagement.cpp                            */
/* Purpose:                                                         */
/*      This file contains the implementation of the                */
/*      MemberManagement class. It provides methods for managing    */
/*      member-related data, including adding, deleting, searching, */
/*      and displaying members, as well as utility methods for ID   */
/*      generation and duplicate checks.                            */
/********************************************************************/
#include "MemberManagement.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

////////////////////////////////////////////////////////
//  Function name:  MemberManagement (Default Constructor)
//  Description:    Creates a MemberManagement object with default values.
//  Parameters:     None
//  
//  Return Value:   None
////////////////////////////////////////////////////////
MemberManagement::MemberManagement() = default;

////////////////////////////////////////////////////////
//  Function name:  MemberManagement (Parameterized Constructor)
//  Description:    Creates a MemberManagement object with an initialized 
//                  member list.
//  Parameters:     mem - Vector of Member objects
//  
//  Return Value:   None
////////////////////////////////////////////////////////
MemberManagement::MemberManagement(std::vector<Member> mem) : memberList(mem) {}; 

////////////////////////////////////////////////////////
//  Function name:  isMembEmpty
//  Description:    Checks if the member list is empty and displays 
//                  a message if it is.
//  Parameters:     None
//  
//  Return Value:   bool - true if member list is empty, otherwise false
////////////////////////////////////////////////////////
bool MemberManagement::isMembEmpty() const
{
    if (memberList.empty())
    {
        std::cout << "\nThere are no Members in the system. Please add a member and try again.\n"; 
        return true; 
    }
    return false; 
}

////////////////////////////////////////////////////////
//  Function name:  generateMemberId
//  Description:    Generates a random 6-digit member ID.
//  Parameters:     None
//  
//  Return Value:   string - A 6-character string representing the member ID
////////////////////////////////////////////////////////
//add a function that checks for duplicate member id. 
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


////////////////////////////////////////////////////////
//  Function name:  addMember
//  Description:    Prompts the user to enter member details and adds 
//                  a new member to the member list.
//  Parameters:     None
//  
//  Return Value:   None
////////////////////////////////////////////////////////
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
    memberList.emplace_back(tempMemId, tempFirstName, tempLastName, tempEmail, tempPhone); 

}

////////////////////////////////////////////////////////
//  Function name:  deleteMember
//  Description:    Prompts the user to enter a member ID and removes 
//                  the member with the matching ID from the member list. 
//                  Displays appropriate messages if no match is found 
//                  or the list is empty.
//  Parameters:     None
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void MemberManagement::deleteMember()
{
    std::string tempId{}; 

    //check if memberList container is empty, if true, return. if false continue. 
    if (isMembEmpty())
    {
        return; 
    }

    std::cin.ignore(); 
    std::cout << "\nPlease enter member id: ";
    getline(std::cin, tempId); 

    //look for object with matching member id within memberList container and if found, delete it. 
    for (auto it = memberList.begin(); it != memberList.end(); it++)
    {
        if (it->getMemberId() == tempId)
        {
            //delete object at the index of current iterator. 
            memberList.erase(it);
            std::cout << "Member Successfully Deleted.\n";
            return;
        }
    }

    std::cout << "No matching member ID found, please try again.\n"; 
    return; 
}

////////////////////////////////////////////////////////
//  Function name:  searchMember
//  Description:    Searches the member list using the given value and strategy, 
//                  and displays matching members.
//  Parameters:     value - Search string
//                  strategy - Search strategy to match members
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void MemberManagement::searchMember(const std::string& value, const SearchStrategy& strategy) const
{
    bool found = false; 

    for (const auto& member : memberList)
    {
        if (strategy.matches(member, value))
        {
            std::cout << "\nMember Found:\n"
                << "ID: " << member.getMemberId()
                << "\nName: " << member.getFirstName() << " " << member.getLastName()
                << "\nEmail: " << member.getEmail()
                << "\nPhone: " << member.getPhone() << "\n"; 
            found = true; 
        }
    }

    if (!found)
    {
        std::cout << "No member matching search criteria found, please try again\n"; 
    }
}

////////////////////////////////////////////////////////
//  Function name:  displayAllMembers
//  Description:    Displays details of all members in the member list.
//  Parameters:     None
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void MemberManagement::displayAllMembers() const
{
    if (isMembEmpty())
    {
        return; 
    }
    
    std::cout << "\n"; 

    for (const auto& member : memberList)
    {
        std::cout << "Member ID: " << member.getMemberId()
            << "\nFirst Name: " << member.getFirstName()
            << "\nLast Name: " << member.getLastName()
            << "\nEmail: " << member.getEmail()
            << "\nPhone Number: " << member.getPhone() << "\n"
            << "-------------------------------------- \n";
    }
}

//documenation
bool MemberManagement::isMemberValid(const std::string& memberID) const 
{
    for (const auto& member : memberList) 
    {
        if (member.getMemberId() == memberID) 
        {
            return true;
        }
    }
    std::cout << "Member ID " << memberID << " does not exist.\n";
    return false;
}


