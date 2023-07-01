/*******************************************************************************
* AUTHOR       : Dillon Welsh
* ASSIGNMENT7  : Recursion
* CLASS        : CS 3A
* SECTION      : 71206
* DUE DATE     : 10/28/2020
*******************************************************************************/

#include "intlist.h"

/*******************************************************************************
* INTLIST CLASS
*_______________________________________________________________________________
* This program defines the functions and
* constructors for the IntList Class
*_______________________________________________________________________________
* INPUT:
*  "intList.h": The function and constructor
*	declarations for the IntList class
*
* OUTPUT:
*  None
*******************************************************************************/

/*******************************************************************************
* CONSTRUCTOR INTLIST
*_______________________________________________________________________________
* This constructor constructs an IntList object
* with a head and tail, each containing a value
* of zero
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

IntList::IntList()
{
    head = nullptr;
    tail = nullptr;
}

/*******************************************************************************
* DESTRUCTOR INTLIST
*_______________________________________________________________________________
* This destructs an IntList object and deltes the
* head and tail pointers
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

IntList::~IntList()
{
    IntNode* temp = head;
    IntNode* curr = nullptr;

    //deallocate the memory
    //reallocated to the list.
    while(temp != nullptr)
    {
        curr = temp;
        temp = temp->next;
        delete curr;
    }

    head = nullptr;
    tail = nullptr;
}

/*******************************************************************************
* FUNCTION DISPLAY
*_______________________________________________________________________________
* This Function prints the values of each object
* in an IntList object
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

void IntList::display() const
{
    IntNode * temp = head;

    //display the elements of the list.
    while(temp != nullptr)
    {
        cout << temp->data;
        //checks if this is the last pointer
        if (temp->next != NULL) cout << " ";
        temp = temp->next;
    }
}

/*******************************************************************************
* FUNCTION FRONT
*_______________________________________________________________________________
* This function returns the data in the head of the linked list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* int
*******************************************************************************/

int IntList::front() const
{
    return head->data;
}

/*******************************************************************************
* FUNCTION BACK
*_______________________________________________________________________________
* This function returns the data in the tail of the linked list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* int
*******************************************************************************/

int IntList::back() const
{
    return tail->data;
}

/*******************************************************************************
* FUNCTION LENGTH
*_______________________________________________________________________________
* This function recursively determines the length of the list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* int
*******************************************************************************/

int IntList::length() const
{
    findLength(head);
}

/*******************************************************************************
* FUNCTION FINDLENGTH
*_______________________________________________________________________________
* This function recursively determines the length of the list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* IntNode*
*
* POST-CONDITIONS
* int
*******************************************************************************/

int IntList::findLength(IntNode* head) const
{
    // Base case
    if (head == nullptr) return 0;

    // count is 1 + count of remaining list
    return 1 + findLength(head->next);
}

/*******************************************************************************
* FUNCTION SUM
*_______________________________________________________________________________
* This function recursively determines the sum of all of the elements in the
* list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* none
*
* POST-CONDITIONS
* int
*******************************************************************************/

int IntList::sum() const
{
    findSum(head);
}

/*******************************************************************************
* FUNCTION FINDSUM
*_______________________________________________________________________________
* This function recursively determines the sum of all of the elements in the
* list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* IntNode*
*
* POST-CONDITIONS
* int
*******************************************************************************/

int IntList::findSum(IntNode* head) const
{
    // Base case
    if (head == nullptr) return 0;

    // sum is head data + head data of remaining list
    //cout << head->data << endl;
    return head->data + findSum(head->next);
}

/*******************************************************************************
* FUNCTION REVERSEDISPLAY
*_______________________________________________________________________________
* This function recursively displays the contents of the list in reverse order.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* void
*******************************************************************************/

void IntList::reverseDisplay() const
{
    findReverseDisplay(head);
}

/*******************************************************************************
* FUNCTION REVERSEDISPLAY
*_______________________________________________________________________________
* This function recursively displays the contents of the list in reverse order.
*_______________________________________________________________________________
* PRE-CONDITIONS
* IntNode*
*
* POST-CONDITIONS
* void
*******************************************************************************/

void IntList::findReverseDisplay(IntNode *head) const
{
    // Base case
    if (head == NULL)
    return;

    // print the list after head node
    findReverseDisplay(head->next);

    // After everything else is printed, print head
    cout << head->data << " ";
}

/*******************************************************************************
* FUNCTION BEGIN
*_______________________________________________________________________________
* This function returns an iterator at the beginning of the linked list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* IntListIterator
*******************************************************************************/

IntListIterator IntList::begin()
{
    return head;
}

/*******************************************************************************
* FUNCTION END
*_______________________________________________________________________________
* This function returns an iterator one element past the last element of the
* linked list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* IntListIterator
*******************************************************************************/

IntListIterator IntList::end()
{
    return tail->next;
}

/*******************************************************************************
* FUNCTION PUSH_FRONT
*_______________________________________________________________________________
* This Function removes an IntNode object from the
* front of an IntList, after the head pointer.
*_______________________________________________________________________________
* PRE-CONDITIONS
* int value
*
* POST-CONDITIONS
* None
*******************************************************************************/

void IntList::push_front(int value)
{
    IntNode *n_node = new IntNode(value);
    n_node->next = nullptr;

    //Insert the node at the front of the list.
    if(head == nullptr)
    {
        head = n_node;
        tail = head;
    }
    else
    {
        n_node->next = head;
        head = n_node;
    }
}

/*******************************************************************************
* FUNCTION POP_FRONT
*_______________________________________________________________________________
* This Function removes an IntNode object from the
* front of an IntList, after the head pointer.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

void IntList::pop_front()
{
    if(head == tail && head != nullptr)
    {
        head = nullptr;
        delete tail;
        tail = nullptr;
    }
    else if(head != nullptr)
    {
        IntNode * temp = head;
        head = head->next;
        delete temp;
    }
}

/*******************************************************************************
* FUNCTION PUSH_BACK
*_______________________________________________________________________________
* This function inserts a data value (within a new node)
* at the back end of the list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* int value
*
* POST-CONDITIONS
* None
*******************************************************************************/

void IntList::push_back(int value)
{
    IntNode* n_node = new IntNode(value);
    n_node->next = nullptr;

    //Insert the node at the back of the list.
    if(tail == NULL)
    {
        tail = n_node;
        head = tail;
    }
    else
    {
        tail->next = n_node;
        tail = n_node;
    }
}

/*******************************************************************************
* FUNCTION SELECT_SORT
*_______________________________________________________________________________
* This function sorts the list into ascending order
* using the selection sort algorithm.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

void IntList::select_sort()
{
    IntNode* temp = head,
    * min_node, * curr_node;

    //If the list is not empty then, perform the selection sort.
    if(head != nullptr)
    {
        while(temp->next != nullptr)
        {
            min_node = temp;
            curr_node = temp->next;

            while(curr_node != nullptr)
            {
                if(curr_node->data < min_node->data) min_node = curr_node;
                curr_node = curr_node->next;
            }

            int temp_swap = min_node->data;
            min_node->data = temp->data;
            temp->data = temp_swap;
            temp = temp->next;
        }
    }
}

/*******************************************************************************
* FUNCTION INSERT_SORT
*_______________________________________________________________________________
* This function assumes the values in the list are
* in sorted (ascending) order and inserts the data
* into the appropriate position in the list (so that
* the values will still be in ascending order after insertion).
*_______________________________________________________________________________
* PRE-CONDITIONS
* int value
*
* POST-CONDITIONS
* None
*******************************************************************************/

void IntList::insert_sorted(int value)
{
    IntNode* n_node = new IntNode(value);
    IntNode* curr = head;
    IntNode* prev = nullptr;

    //find the correct postion to insert the node.

    while(curr != nullptr && curr->data < n_node->data)
    {
        prev = curr;
        curr = curr->next;
    }

    //Insert the node
    if(prev == nullptr)
    {
        n_node->next = curr;
        head = n_node;
    }
    else
    {
        prev->next = n_node;
        n_node->next = curr;
    }

    if(curr == nullptr) tail = n_node;
}

/*******************************************************************************
* FUNCTION REMOVE_DUPLICATES
*_______________________________________________________________________________
* This function removes all values
* (actually removes the nodes that contain the value)
* that are duplicates of a value that already exists in the list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

void IntList::remove_duplicates()
{
    IntNode* i_node = head;

    if(i_node != nullptr)
    {
        while(i_node ->next != nullptr)
        {
            IntNode * j_node = i_node -> next;
            IntNode * temp = i_node;
            while(j_node != nullptr)
            {
                if(j_node->data == i_node->data) temp->next = j_node->next;
                else temp = j_node;
                j_node = j_node->next;
            }
            i_node = i_node->next;
            if(i_node == nullptr) break;
        }
    }
}

/*******************************************************************************
* FUNCTION CLEAR
*_______________________________________________________________________________
* This function clears the list.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

void IntList::clear()
{
    //clear the list.
    IntNode* temp = head;
    IntNode* curr;

    while(temp != nullptr)
    {
        curr = temp;
        temp = temp->next;
        delete curr;
    }
}

/*******************************************************************************
* FUNCTION EMPTY
*_______________________________________________________________________________
* This function returns true if the list is empty.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* bool
*******************************************************************************/

bool IntList::empty() const
{
    if(head == nullptr) return true;
    else return false;
}

/*******************************************************************************
* COPY CONSTRUCTOR
*_______________________________________________________________________________
* This is a copy constructor.
*_______________________________________________________________________________
* PRE-CONDITIONS
* const IntList &cpy
*
* POST-CONDITIONS
* IntList
*******************************************************************************/

IntList::IntList(const IntList &cpy)
{
    head=0;
    tail=0;

    if(!cpy.empty())
    {
        IntNode* temp = cpy.head;
        while(temp!=0)
        {
            push_back(temp->data);
            temp = temp->next;
        }
    }
//    IntNode* temp = cpy.head;
//    while(temp != nullptr)
//    {
//        push_back(temp->data);
//    }
}

/*******************************************************************************
* OVERLOADED ASSIGNMENT OPERATOR
*_______________________________________________________________________________
* This is overloads the assignment operator.
*_______________________________________________________________________________
* PRE-CONDITIONS
* const IntList &rhs
*
* POST-CONDITIONS
* IntList &
*******************************************************************************/

IntList & IntList::operator=(const IntList &rhs)
{
    if(this == &rhs) return  *this;
    else if(rhs.empty())
    {
        head = 0;
        tail = 0;
    }
    else
    {
        clear();
        IntNode* temp = rhs.head;
        while(temp!=0)
        {
            push_back(temp->data);
            temp=temp->next;
        }
    }
    return *this;
//    IntNode* temp = rhs.head;
//    while(temp != nullptr) push_back(temp->data);
//    return *this;
}

/*******************************************************************************
* OVERLOADED INSERTIONS OPERATOR
*_______________________________________________________________________________
* This is overloads the insertion operator.
*_______________________________________________________________________________
* PRE-CONDITIONS
* ostream &out
* const IntList &rhs
*
* POST-CONDITIONS
* ostream &
*******************************************************************************/

ostream & operator<<(ostream &out, const IntList &rhs)
{
    IntNode* temp = rhs.head;
    while(temp != NULL)
    {
        out << temp->data << " ";
        temp = temp->next;
    }
    return out;
}
