/********************************************************************/
/* Author:          Wilfred Jimenez                                 */
/* Creation Date:   December 21, 2024                               */
/* Last Edited:     December 21, 2024                               */
/* Filename:        Member.h                                        */
/* Purpose:                                                         */

/********************************************************************/
#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member
{
    public:
        //default constructor
        Member(); 
        //parameterized constructor
        Member(std::string memberId, std::string firstName, std::string lastName, std::string email, std::string phone);

        //getters
        std::string getMemberId() const; 
        std::string getFirstName() const; 
        std::string getLastName() const;
        std::string getEmail() const; 
        std::string getPhone() const; 

        //setters
        void setMemberId(std::string memId); 
        void setFirstName(std::string memFirstName); 
        void setLastName(std::string memLastName);
        void setEmail(std::string memEmail); 
        void setPhone(std::string memPhone); 

    private:
        std::string memberId; 
        std::string firstName;
        std::string lastName; 
        std::string email; 
        std::string phone; 
};


#endif 