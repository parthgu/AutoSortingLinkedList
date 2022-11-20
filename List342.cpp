// #include <iostream>
// #include <fstream>
// #include "Child.h"
// #include "List342.h"

// using namespace std;

// template <class ItemType>
// List342<ItemType>::List342()
// {
//     this->head = NULL;
// }

// template <class ItemType>
// List342<ItemType>::~List342()
// {
// }

// // class methods

// template <class ItemType>
// bool List342<ItemType>::BuildList(string fileName)
// {
//     ifstream inFile;

//     inFile.open(fileName);
//     if (inFile.is_open())
//     {
//         while (!inFile.eof())
//         {
//             string firstName;
//             string lastName;
//             int age;
//             inFile >> firstName;
//             inFile >> lastName;
//             inFile >> age;
//             Child *toAdd = new Child(firstName, lastName, age);
//             if (!(this->Insert(toAdd)))
//             {
//                 delete toAdd;
//             }
//         }
//         inFile.close();
//     }
//     else
//     {
//         cout << "File: " << fileName << " not found" << endl;
//         return false;
//     }
//     return true;
// }

// template <class ItemType>
// bool List342<ItemType>::Insert(ItemType *obj)
// {
//     Node<ItemType> *toInsert = new Node<ItemType>();
//     toInsert->value = obj;

//     if (this->head == NULL)
//     {
//         this->head = toInsert;
//         return true;
//     }
//     if (*(this->head->value) == *obj)
//         return false;
//     if (*(this->head->value) > *obj)
//     {
//         toInsert->next = this->head;
//         this->head = toInsert;
//         return true;
//     }

//     Node<ItemType> *cur = this->head;
//     while (cur->next != NULL && *(cur->next->value) <= *obj)
//     {
//         if (*(cur->next->value) == *obj)
//             return false;
//         cur = cur->next;
//     }
//     toInsert->next = cur->next;
//     cur->next = toInsert;
//     return true;
// }

// template <class ItemType>
// bool List342<ItemType>::Remove(ItemType target, ItemType &result)
// {
//     Node<ItemType> *temp;
//     if (this->head == NULL)
//         return false;
//     if (*(this->head->value) == target)
//     {
//         temp = this->head;
//         this->head = this->head->next;
//         result = *(this->head->value);
//         delete temp;
//         temp = NULL;
//         return true;
//     }
//     Node<ItemType> *pNode = this->head;
//     while ((pNode->next != NULL) && *(pNode->next->value) < target)
//     {
//         pNode = pNode->next;
//     }
//     if (pNode->next == NULL)
//         return false;
//     else if (*(pNode->next->value) == target)
//     {
//         result = *(pNode->next->value);
//         temp = pNode->next;
//         pNode->next = pNode->next->next;
//         delete temp;
//         temp = NULL;
//         return true;
//     }
//     return false;
// }

// template <class ItemType>
// bool List342<ItemType>::Peek(ItemType target, ItemType &result) const
// {
//     Node<ItemType> *temp;
//     if (this->head == NULL)
//         return false;
//     if (*(this->head->value) == target)
//     {
//         result = *(this->head->value);
//         return true;
//     }
//     Node<ItemType> *pNode = this->head;
//     while ((pNode->next != NULL) && *(pNode->next->value) < target)
//     {
//         pNode = pNode->next;
//     }
//     if (pNode->next == NULL)
//         return false;
//     else if (*(pNode->next->value) == target)
//     {
//         result = *(pNode->next->value);
//         return true;
//     }
//     return false;
// }

// template <class ItemType>
// bool List342<ItemType>::isEmpty() const
// {
//     return (this->head == NULL);
// }

// template <class ItemType>
// void List342<ItemType>::DeleteList()
// {
//     while (this->head != NULL)
//     {
//         Node<ItemType> *temp = this->head->next;
//         delete this->head;
//         this->head = temp;
//     }
// }

// template <class ItemType>
// bool List342<ItemType>::Merge(List342<ItemType> &list1)
// {
//     if (this == &list1)
//     {
//         return true;
//     }
//     Node<ItemType> *cur = list1.head;
//     if (cur == NULL)
//     {
//         return true;
//     }
//     while (cur != NULL)
//     {
//         this->Insert(cur->value);
//         cur = cur->next;
//     }
//     list1.DeleteList();
//     return true;
// }

// // operator overloads
// template <class ItemType>
// List342<ItemType> List342<ItemType>::operator+(const List342<ItemType> &other)
// {
//     List342<ItemType> result;
//     Node<ItemType> *cur = this->head;
//     while (cur != NULL)
//     {
//         result.Insert(cur->value);
//         cur = cur->next;
//     }
//     cur = other.head;
//     while (cur != NULL)
//     {
//         result.Insert(cur->value);
//         cur = cur->next;
//     }
//     delete cur;
//     return result;
// }

// template <class ItemType>
// List342<ItemType> List342<ItemType>::operator+=(const List342<ItemType> &other)
// {
//     *this = *this + other;
//     return *this;
// }

// template <class ItemType>
// bool List342<ItemType>::operator==(const List342<ItemType> &other)
// {
//     Node<ItemType> *cur1 = this->head;
//     Node<ItemType> *cur2 = other.head;
//     while (cur1 != NULL && cur2 != NULL)
//     {
//         if (*(cur1->value) != *(cur2->value))
//         {
//             return false;
//         }
//         cur1 = cur1->next;
//         cur2 = cur2->next;
//     }
//     if (cur1 == NULL && cur2 == NULL)
//     {
//         return true;
//     }
//     return false;
// }

// template <class ItemType>
// bool List342<ItemType>::operator!=(const List342<ItemType> &other)
// {
//     return !this == other;
// }

// template <class ItemType>
// void List342<ItemType>::operator=(const List342<ItemType> &other)
// {
//     Node<ItemType> *sNode, *dNode, *insNode;
//     if (this == &other)
//         return;
//     this->DeleteList();
//     if (other.head == NULL)
//         return;
//     dNode = new Node<ItemType>;
//     (dNode->value) = (other.head->value);
//     this->head = dNode;
//     sNode = other.head->next;
//     while (sNode != NULL)
//     {
//         insNode = new Node<ItemType>;
//         (insNode->value) = (sNode->value);
//         dNode->next = insNode;
//         dNode = dNode->next;
//         sNode = sNode->next;
//     }
// }
