#pragma once
#include <iostream>

using namespace std;

class Child
{
public:
    // constructor/destructor
    Child();
    Child(string firstName, string lastName, int age);
    ~Child();

    // getters/setters

    /**
     * getFirstName()
     *
     * returns string of child first name
     */
    string getFirstName() const;

    /**
     * getLastName()
     *
     * returns string of child last name
     */
    string getLastName() const;

    /**
     * getAge()
     *
     * returns integer of child age
     */
    int getAge() const;

    /**
     * setFirstName(string)
     *
     * sets the child first name to string passed to method
     */
    void setFirstName(const string &newFirstName);

    /**
     * setLastName(string)
     *
     * sets the child last name to string passed to method
     */
    void setLastName(const string &newLastName);

    /**
     * setAge(int)
     *
     * sets the child age to int passed to method
     */
    void setAge(const int &newAge);

    // operator overloads

    /**
     * == overload
     *
     * Returns true if other child first name, last name, and age are equal to child calling method, false otherwise
     */
    bool operator==(const Child &other);

    /**
     * != overload
     *
     * Returns false if other child first name, last name, and age are equal to child calling method, true otherwise
     */
    bool operator!=(const Child &other);

    /**
     * << overload
     *
     * prints to console first name, last name, and age without spaces
     */
    friend ostream &operator<<(ostream &outStream, const Child &theChild);

    /**
     * Comparative operators
     *
     * The Child class compares names alphabetically by last name first; first name second; and then age.
     * A child is considered a duplicate if all three fields (firstName, lastName, age) are equivalent.
     */
    bool operator<=(const Child &other);
    bool operator>=(const Child &other);
    bool operator<(const Child &other);
    bool operator>(const Child &other);

private:
    string firstName;
    string lastName;
    string fullname; // lastName + firstName
    int age;
};