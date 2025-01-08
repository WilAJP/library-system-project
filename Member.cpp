/********************************************************************/
/* Author:          Wilfred Jimenez                                 */
/* Creation Date:   December 21, 2024                               */
/* Last Edited:     January 7, 2024                                 */
/* Filename:        Member.cpp                                      */
/* Purpose:                                                         */
/*      This file contains the implementation of the Member class.  */
/*      It includes constructors, getters, and setters for          */
/*      managing member information such as ID, name, email, and    */
/*      phone number.                                               */
/********************************************************************/
#include "Member.h"

//method definitions 

////////////////////////////////////////////////////////
//  Function name:  Member (Default Constructor)
//  Description:    Creates a Member object with default values
//                  for memberId, firstName, lastName, email, and phone.
//  Parameters:     None
//  
//  Return Value:   None
////////////////////////////////////////////////////////
Member::Member() : memberId(""), firstName(""), lastName(""), email(""), phone("") {};

////////////////////////////////////////////////////////
//  Function name:  Member (Parameterized Constructor)
//  Description:    Creates a Member object with specified values
//                  for memberId, firstName, lastName, email, and phone.
//  Parameters:     memId - Member ID
//                  memFirstName - Member's first name
//                  memLastName - Member's last name
//                  memEmail - Member's email address
//                  memPhone - Member's phone number
//  
//  Return Value:   None
////////////////////////////////////////////////////////
Member::Member(std::string memId, std::string memFirstName, std::string memLastName, std::string memEmail, std::string memPhone)
      : memberId(memId), firstName(memFirstName), lastName(memLastName), email(memEmail), phone(memPhone) {};

//getters

////////////////////////////////////////////////////////
//  Function name:  getMemberId
//  Description:    Retrieves the Member ID.
//  Parameters:     None
//  
//  Return Value:   string - member ID
////////////////////////////////////////////////////////
std::string Member::getMemberId() const
{
    return memberId; 
}


////////////////////////////////////////////////////////
//  Function name:  getFirstName
//  Description:    Retrieves the Member's first name.
//  Parameters:     None
//  
//  Return Value:   string - first name of member
////////////////////////////////////////////////////////
std::string Member::getFirstName() const
{
    return firstName; 
}

////////////////////////////////////////////////////////
//  Function name:  getLastName
//  Description:    Retrieves the Member's last name.
//  Parameters:     None
//  
//  Return Value:   string - last name of member
////////////////////////////////////////////////////////
std::string Member::getLastName() const
{
    return lastName;
}

////////////////////////////////////////////////////////
//  Function name:  getEmail
//  Description:    Retrieves the Member's email address.
//  Parameters:     None
//  
//  Return Value:   string - email address of member
////////////////////////////////////////////////////////
std::string Member::getEmail() const
{
    return email; 
}

////////////////////////////////////////////////////////
//  Function name:  getPhone
//  Description:    Retrieves the Member's phone number.
//  Parameters:     None
//  
//  Return Value:   string - phone number
////////////////////////////////////////////////////////
std::string Member::getPhone() const
{
    return phone; 
}

//setters

////////////////////////////////////////////////////////
//  Function name:  setMemberId
//  Description:    Updates the Member ID.
//  Parameters:     memId - New Member ID as a string
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void Member::setMemberId(std::string memId)
{
    memberId = memId; 
}

////////////////////////////////////////////////////////
//  Function name:  setFirstName
//  Description:    Updates the Member's first name.
//  Parameters:     memFirstName - New first name as a string
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void Member::setFirstName(std::string memFirstName)
{
    firstName = memFirstName; 
}

////////////////////////////////////////////////////////
//  Function name:  setLastName
//  Description:    Updates the Member's last name.
//  Parameters:     memLastName - New last name as a string
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void Member::setLastName(std::string memLastName)
{
    lastName = memLastName;
}

////////////////////////////////////////////////////////
//  Function name:  setEmail
//  Description:    Updates the Member's email address.
//  Parameters:     memEmail - New email address as a string
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void Member::setEmail(std::string memEmail)
{
    email = memEmail; 
}

////////////////////////////////////////////////////////
//  Function name:  setPhone
//  Description:    Updates the Member's phone number.
//  Parameters:     memPhone - New phone number as a string
//  
//  Return Value:   None
////////////////////////////////////////////////////////
void Member::setPhone(std::string memPhone)
{
    phone = memPhone; 
}