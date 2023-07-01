#ifndef INTLIST_H
#define INTlIST_H

#include "intlistiterator.h"

/*****************************************************************************
* INTLIST CLASS
*_________________________________________________
* This program defines the functions and
* constructors for the IntList Class
*_________________________________________________
* INPUT:
*  "intList.h": The function and constructor
*	declarations for the IntList class
*
* OUTPUT:
*  None
******************************************************************************/
class IntList
{
public:
/*****************************************************************************
* CONSTRUCTOR INTLIST
*________________________________________________
* This constructor constructs an IntList object
* with a head and tail, each containing a value
* of zero
****************************************************************************/
    IntList();
/*****************************************************************************
* COPY CONSTRUCTOR INTLIST
*________________________________________________
* This is a copy constructor.
****************************************************************************/
    IntList(const IntList &cpy);
/*****************************************************************************
* DESTRUCTOR INTLIST
*________________________________________________
* This destructs an IntList object and deltes the
* head and tail pointers
****************************************************************************/
    ~IntList();
/*****************************************************************************
* FUNCTION DISPLAY
*________________________________________________
* This Function prints the values of each object
* in an IntList object
****************************************************************************/
    void display() const;
/*****************************************************************************
* FUNCTION DISPLAY
*________________________________________________
* This Function adds an IntNode object to the
* front of an IntList, after the head pointer.
****************************************************************************/
    void push_front(int value);  // CALC the value in the new intNode object
/*****************************************************************************
* FUNCTION POP_FRONT
*________________________________________________
* This Function removes an IntNode object from the
* front of an IntList, after the head pointer.
****************************************************************************/
    void pop_front();
/*****************************************************************************
* FUNCTION PUSH_BACK
*________________________________________________
* This function inserts a data value (within a new node)
* at the back end of the list.
****************************************************************************/
    void push_back(int value);
/*****************************************************************************
* FUNCTION FRONT
*________________________________________________
* This function returns the data in the head of the linked list.
****************************************************************************/
    int front() const;
/*****************************************************************************
* FUNCTION BACK
*________________________________________________
* This function returns the data in the tail of the linked list.
****************************************************************************/
    int back() const;
/*****************************************************************************
* FUNCTION LENGTH
*________________________________________________
*  This function recursively determines the length of the list.
****************************************************************************/
    int length() const;
/*****************************************************************************
* FUNCTION SUM
*________________________________________________
*  This function recursively determines the sum of all of the elements in the
* list.
****************************************************************************/
    int sum() const;
/*****************************************************************************
* FUNCTION REVERSEDISPLAY
*________________________________________________
* This function recursively displays the contents of the list in reverse order.
****************************************************************************/
    void reverseDisplay() const;
/*****************************************************************************
* FUNCTION BEGIN
*________________________________________________
* This function returns an iterator at the beginning of the linked list.
****************************************************************************/
    IntListIterator begin();
/*****************************************************************************
* FUNCTION END
*________________________________________________
* This function returns an iterator one element past the last element of the
* linked list.
****************************************************************************/
    IntListIterator end();
/*****************************************************************************
* FUNCTION SELECT_SORT
*________________________________________________
* This function sorts the list into ascending order
* using the selection sort algorithm.
****************************************************************************/
    void select_sort();
/*****************************************************************************
* FUNCTION INSERT_SORTED
*________________________________________________
* This function assumes the values in the list are
* in sorted (ascending) order and inserts the data
* into the appropriate position in the list (so that
* the values will still be in ascending order after insertion).
****************************************************************************/
    void insert_sorted(int value);
/*****************************************************************************
* FUNCTION REMOVE_DUPLICATES
*________________________________________________
* This function removes all values
* (actually removes the nodes that contain the value)
* that are duplicates of a value that already exists in the list.
****************************************************************************/
    void remove_duplicates();
/*****************************************************************************
* FUNCTION CLEAR
*________________________________________________
* This function clears the list.
****************************************************************************/
    void clear();
/*****************************************************************************
* FUNCTION CLEAR
*________________________________________________
* This function returns true if the list is empty.
****************************************************************************/
    bool empty() const;
/*****************************************************************************
* OVERLOADED ASSIGNMENT OPERATOR
*________________________________________________
* This is overloads the assignment operator.
****************************************************************************/
    IntList & operator=(const IntList &rhs);
/*****************************************************************************
* OVERLOADED INSERTIONS OPERATOR
*________________________________________________
* This is overloads the insertion operator.
****************************************************************************/
    friend ostream & operator<<(ostream &out, const IntList &rhs);
private:
/*****************************************************************************
* FUNCTION FINDLENGTH
*________________________________________________
*  This function recursively determines the length of the list.
****************************************************************************/
    int findLength(IntNode* head) const;
/*****************************************************************************
* FUNCTION FINDSUM
*________________________________________________
*  This function recursively determines the sum of all of the elements in the
* list.
****************************************************************************/
    int findSum(IntNode* head) const;
/*****************************************************************************
* FUNCTION REVERSEDISPLAY
*________________________________________________
* This function recursively displays the contents of the list in reverse order.
****************************************************************************/
    void findReverseDisplay(IntNode* head) const;

    IntNode* head; // PROC the pointer to the first IntNode
    IntNode* tail; // PROC the pointer to the last IntNode

};

#endif
