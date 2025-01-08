/********************************************************************/
/* Author:          Wilfred Jimenez                                 */
/* Creation Date:   December 21, 2024                               */
/* Last Edited:     December 21, 2024                               */
/* Filename:        Member.cpp                                       */
/* Purpose:                                                         */

/********************************************************************/
#include "Member.h"

//method definitions 

//documentation
//default constructor 
Member::Member() : memberId(""), firstName(""), lastName(""), email(""), phone("") {};

//documentation
//parametarized constructor
Member::Member(std::string memId, std::string memFirstName, std::string memLastName, std::string memEmail, std::string memPhone)
      : memberId(memId), firstName(memFirstName), lastName(memLastName), email(memEmail), phone(memEmail) {};

//getters

//documentation
std::string Member::getMemberId() const
{
    return memberId; 
}

//documenation
std::string Member::getFirstName() const
{
    return firstName; 
}

//documenation
std::string Member::getLastName() const
{
    return lastName;
}

//documenation
std::string Member::getEmail() const
{
    return email; 
}

//documenation
std::string Member::getPhone() const
{
    return phone; 
}

//setters

//documentation
void Member::setMemberId(std::string memId)
{
    memberId = memId; 
}

//documentation
void Member::setFirstName(std::string memFirstName)
{
    firstName = memFirstName; 
}

//documentation
void Member::setLastName(std::string memLastName)
{
    lastName = memLastName;
}

//documentation
void Member::setEmail(std::string memEmail)
{
    email = memEmail; 
}

//documentation
void Member::setPhone(std::string memPhone)
{
    phone = memPhone; 
}