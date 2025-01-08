/********************************************************************/
/* Author:          Wilfred Jimenez                                 */
/* Creation Date:   January 2, 2024                                 */
/* Last Edited:     January 7, 2025                                 */
/* Filename:        SearchMethods.h                                 */
/* Purpose:                                                         */
/*      This file defines various search methods for finding        */
/*      member data. Each method is a subclass of SearchStrategy    */
/*      and provides specific logic for searching by ID, name,      */
/*      email, or phone number.                                     */
/********************************************************************/
#ifndef SEARCHMETHODS_H
#define SEARCHMETHODS_H

#include "SearchStrategy.h"

////////////////////////////////////////////////////////
//  Class name:     SearchByMemberID
//  Method name:    matches
//  Description:    Checks if the member's ID matches the provided value.
//  Parameters:     member - The Member object to search
//                  value - The ID to match
//  
//  Return Value:   bool - true if the member's ID matches the value,
//                  otherwise false
////////////////////////////////////////////////////////
class SearchByMemberID : public SearchStrategy
{
    public:
        bool matches(const Member& member, const std::string& value) const override
        {
            return member.getMemberId() == value; 
        }
};

////////////////////////////////////////////////////////
//  Class name:     SearchByName
//  Method name:    matches
//  Description:    Checks if the member's last name matches the provided value.
//  Parameters:     member - The Member object to search
//                  value - The last name to match
//  
//  Return Value:   bool - true if the member's last name matches the value,
//                  otherwise false
////////////////////////////////////////////////////////
class SearchByName : public SearchStrategy
{
public:
    bool matches(const Member& member, const std::string& value) const override
    {
        return member.getLastName() == value;
    }
};

////////////////////////////////////////////////////////
//  Class name:     SearchByEmail
//  Method name:    matches
//  Description:    Checks if the member's email matches the provided value.
//  Parameters:     member - The Member object to search
//                  value - The email to match
//  
//  Return Value:   bool - true if the member's email matches the value,
//                  otherwise false
////////////////////////////////////////////////////////
class SearchByEmail : public SearchStrategy
{
public:
    bool matches(const Member& member, const std::string& value) const override
    {
        return member.getEmail() == value;
    }
};

////////////////////////////////////////////////////////
//  Class name:     SearchByPhone
//  Method name:    matches
//  Description:    Checks if the member's phone number matches the provided value.
//  Parameters:     member - The Member object to search
//                  value - The phone number to match
//  
//  Return Value:   bool - true if the member's phone number matches the value,
//                  otherwise false
////////////////////////////////////////////////////////
class SearchByPhone : public SearchStrategy
{
public:
    bool matches(const Member& member, const std::string& value) const override
    {
        return member.getPhone() == value;
    }
};

#endif
