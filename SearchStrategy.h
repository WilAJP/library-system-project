/********************************************************************/
/* Author:          Wilfred Jimenez                                 */
/* Creation Date:   December 29, 2024                               */
/* Last Edited:     January 7, 2025                                 */
/* Filename:        SearchStrategy.h                                */
/* Purpose:                                                         */
/*      This file defines the SearchStrategy class, which provides  */
/*      a base for creating different search methods to find        */
/*      member data. It includes a virtual function for custom      */
/*      search logic and a virtual destructor.                      */
/********************************************************************/
#ifndef SEARCHSTRATEGY_H
#define SEARCHSTRATEGY_H

#include <string>
#include "Member.h"

class SearchStrategy
{
    public:
        //purely virtual function, makes this an abstract class, meaning that every derived class has to provide its own logic. 
        //no objects can be made out of this class. 
        virtual bool matches(const Member& member, const std::string& value) const = 0; 
        virtual ~SearchStrategy() = default;    //virtual destructor 
    private: 
};

#endif