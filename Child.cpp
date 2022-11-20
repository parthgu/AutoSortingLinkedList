#include <iostream>
#include "Child.h"

using namespace std;

// constructor/destructor
Child::Child()
{
}

Child::Child(string firstName, string lastName, int age)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->fullname = lastName + firstName;
    this->age = age;
}

Child::~Child()
{
}

// getters/setters

/**
 * getFirstName()
 *
 * returns string of child first name
 */
string Child::getFirstName() const
{
    return this->firstName;
}

/**
 * getLastName()
 *
 * returns string of child last name
 */
string Child::getLastName() const
{
    return this->lastName;
}

/**
 * getAge()
 *
 * returns integer of child age
 */
int Child::getAge() const
{
    return this->age;
}

/**
 * setFirstName(string)
 *
 * sets the child first name to string passed to method
 */
void Child::setFirstName(const string &newFirstName)
{
    this->firstName = newFirstName;
}

/**
 * setLastName(string)
 *
 * sets the child last name to string passed to method
 */
void Child::setLastName(const string &newLastName)
{
    this->lastName = newLastName;
}

/**
 * setAge(int)
 *
 * sets the child age to int passed to method
 */
void Child::setAge(const int &newAge)
{
    this->age = newAge;
}

// operator overloads

/**
 * == overload
 *
 * Returns true if other child first name, last name, and age are equal to child calling method, false otherwise
 */
bool Child::operator==(const Child &other)
{
    return ((this->firstName == other.firstName) &&
            (this->lastName == other.lastName) &&
            (this->age == other.age));
}

/**
 * != overload
 *
 * Returns false if other child first name, last name, and age are equal to child calling method, true otherwise
 */
bool Child::operator!=(const Child &other)
{
    return !((this->firstName == other.firstName) &&
             (this->lastName == other.lastName) &&
             (this->age == other.age));
}

/**
 * << overload
 *
 * prints to console first name, last name, and age without spaces
 */
ostream &operator<<(ostream &outStream, const Child &theChild)
{
    outStream << theChild.firstName << theChild.lastName << theChild.age;
    return outStream;
}

/**
 * Comparative operators
 *
 * The Child class compares names alphabetically by last name first; first name second; and then age.
 * A child is considered a duplicate if all three fields (firstName, lastName, age) are equivalent.
 */
bool Child::operator<=(const Child &other)
{
    if (this->fullname < other.fullname)
    {
        return true;
    }
    if (this->fullname == other.fullname)
    {
        if (this->age <= other.age)
        {
            return true;
        }
        return false;
    }
    return false;
}

bool Child::operator>=(const Child &other)
{
    if (this->fullname > other.fullname)
    {
        return true;
    }
    if (this->fullname == other.fullname)
    {
        if (this->age >= other.age)
        {
            return true;
        }
        return false;
    }
    return false;
}

bool Child::operator<(const Child &other)
{
    return !(*this >= other);
}

bool Child::operator>(const Child &other)
{
    return !(*this <= other);
}
