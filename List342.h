#pragma once
#include <iostream>
#include <fstream>
#include "Child.h"

using namespace std;

template <class ItemType>
struct Node
{
    ItemType *value;
    Node *next;
};

template <class ItemType>
class List342
{
public:
    // constructor/destructor
    List342()
    {
        this->head = NULL;
    }
    ~List342()
    {
    }

    // class methods

    /**
     * BuildList(string)
     *
     * Adds unique items in file in ascending order to a List holding Child class objects
     * File must be formatted for Child class inputs
     * Returns true after successful build
     */
    bool BuildList(string fileName)
    {
        ifstream inFile;

        inFile.open(fileName);
        if (inFile.is_open())
        {
            while (!inFile.eof())
            {
                string firstName;
                string lastName;
                int age;
                inFile >> firstName;
                inFile >> lastName;
                inFile >> age;
                Child *toAdd = new Child(firstName, lastName, age);
                if (!(this->Insert(toAdd)))
                {
                    delete toAdd;
                }
            }
            inFile.close();
        }
        else
        {
            cout << "File: " << fileName << " not found" << endl;
            return false;
        }
        return true;
    }

    /**
     * Insert(Object)
     *
     * Inserts the object to the list in ascending order if it is unique
     * Returns true if object added to the list
     * Returns false if object already in list
     */
    bool Insert(ItemType *obj)
    {
        Node<ItemType> *toInsert = new Node<ItemType>();
        toInsert->value = obj;

        if (this->head == NULL)
        {
            this->head = toInsert;
            return true;
        }
        if (*(this->head->value) == *obj)
            return false;
        if (*(this->head->value) > *obj)
        {
            toInsert->next = this->head;
            this->head = toInsert;
            return true;
        }

        Node<ItemType> *cur = this->head;
        while (cur->next != NULL && *(cur->next->value) <= *obj)
        {
            if (*(cur->next->value) == *obj)
                return false;
            cur = cur->next;
        }
        toInsert->next = cur->next;
        cur->next = toInsert;
        return true;
    }

    /**
     * Remove(target, result)
     *
     * Returns true and removes object if target is found in list, false if not found in list
     * Result is modifyed to the object found in list
     */
    bool Remove(ItemType target, ItemType &result)
    {
        Node<ItemType> *temp;
        if (this->head == NULL)
            return false;
        if (*(this->head->value) == target)
        {
            temp = this->head;
            this->head = this->head->next;
            result = *(this->head->value);
            delete temp;
            temp = NULL;
            return true;
        }
        Node<ItemType> *pNode = this->head;
        while ((pNode->next != NULL) && *(pNode->next->value) < target)
        {
            pNode = pNode->next;
        }
        if (pNode->next == NULL)
            return false;
        else if (*(pNode->next->value) == target)
        {
            result = *(pNode->next->value);
            temp = pNode->next;
            pNode->next = pNode->next->next;
            delete temp;
            temp = NULL;
            return true;
        }
        return false;
    }

    /**
     * Peek(target, result)
     *
     * Returns true if object found in list, false if not found in list
     */
    bool Peek(ItemType target, ItemType &result) const
    {
        Node<ItemType> *temp;
        if (this->head == NULL)
            return false;
        if (*(this->head->value) == target)
        {
            result = *(this->head->value);
            return true;
        }
        Node<ItemType> *pNode = this->head;
        while ((pNode->next != NULL) && *(pNode->next->value) < target)
        {
            pNode = pNode->next;
        }
        if (pNode->next == NULL)
            return false;
        else if (*(pNode->next->value) == target)
        {
            result = *(pNode->next->value);
            return true;
        }
        return false;
    }

    /**
     * isEmpty()
     *
     * Returns true if list is empty, false if list contains at least one object
     */
    bool isEmpty() const
    {
        return (this->head == NULL);
    }

    /**
     * DeleteList()
     *
     * Removes all objects from list and deallocates memory
     */
    void DeleteList()
    {
        while (this->head != NULL)
        {
            Node<ItemType> *temp = this->head->next;
            delete this->head;
            this->head = temp;
        }
    }

    /**
     * Merge(other list)
     *
     * Merges other list with list calling this method, only adding unique values
     * Other list is emptied
     */
    bool Merge(List342<ItemType> &list1)
    {
        if (this == &list1)
        {
            return true;
        }
        Node<ItemType> *cur = list1.head;
        if (cur == NULL)
        {
            return true;
        }
        while (cur != NULL)
        {
            this->Insert(cur->value);
            cur = cur->next;
        }
        list1.DeleteList();
        return true;
    }

    // operator overloads

    /**
     * + overload
     *
     * Adds contents of list calling mehtod, with other list and returns a new list with contents of both
     * Duplicate values are not added more than once in list
     */
    List342<ItemType> operator+(const List342<ItemType> &other)
    {
        List342<ItemType> result;
        Node<ItemType> *cur = this->head;
        while (cur != NULL)
        {
            result.Insert(cur->value);
            cur = cur->next;
        }
        cur = other.head;
        while (cur != NULL)
        {
            result.Insert(cur->value);
            cur = cur->next;
        }
        delete cur;
        return result;
    }

    /**
     * += overload
     *
     * Adds other list to list calling method
     * Does not add duplicate objects
     */
    List342<ItemType> operator+=(const List342<ItemType> &other)
    {
        *this = *this + other;
        return *this;
    }

    /**
     * << overload
     *
     * Prints to console the value of each node in list with no spaces
     */
    friend ostream &operator<<(ostream &outStream, const List342<ItemType> &theList)
    {
        Node<ItemType> *cur;
        cur = theList.head;
        while (cur != NULL)
        {
            outStream << *cur->value;
            cur = cur->next;
        }
        return outStream;
    }

    /**
     * == overload
     *
     * Returns true if each node in each list are equivilant, false otherwise
     */
    bool operator==(const List342<ItemType> &other)
    {
        Node<ItemType> *cur1 = this->head;
        Node<ItemType> *cur2 = other.head;
        while (cur1 != NULL && cur2 != NULL)
        {
            if (*(cur1->value) != *(cur2->value))
            {
                return false;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        if (cur1 == NULL && cur2 == NULL)
        {
            return true;
        }
        return false;
    }

    /**
     * != overload
     *
     * Returns false if each node in list are equivilant, true otherwise
     */
    bool operator!=(const List342<ItemType> &other)
    {
        return !this == other;
    }

    /**
     * = overload
     *
     * Assigns list calling method with values of other list
     */
    void operator=(const List342<ItemType> &other)
    {
        Node<ItemType> *sNode, *dNode, *insNode;
        if (this == &other)
            return;
        this->DeleteList();
        if (other.head == NULL)
            return;
        dNode = new Node<ItemType>;
        (dNode->value) = (other.head->value);
        this->head = dNode;
        sNode = other.head->next;
        while (sNode != NULL)
        {
            insNode = new Node<ItemType>;
            (insNode->value) = (sNode->value);
            dNode->next = insNode;
            dNode = dNode->next;
            sNode = sNode->next;
        }
    }

private:
    Node<ItemType> *head;
};