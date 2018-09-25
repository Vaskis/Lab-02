# Lab-02

# Notes:

I worked with several classmates and the TA to accomplish this assignment.

# Below is the Lab 02 assignment
The linear linked list is one of several ways to organize and store sequential data and is used frequently in computer programming.  In this lab you will work with class LLList, which implements a linear linked implementation of a sequence of doubles.  This implementation of the LLList structure stores a single pointer containing the address of the first Node of a linear linked list of Nodes in each LLList object.  Download the following files from Lab Resources for today's lab:  Node.h, Node.cpp, LinkedList.h, LinkedList.cpp, ListProcessor.cpp. 

Study the implementation of the Node and LLList methods. 

Lab Assignment
The LLList class would be easier to use if a method that reports the size of a LLList was available. Add a size method to the LLList class.
          Modify the main() routine in ListProcessor to thoroughly test the size method.

Add a double sum()  method to the LLList class.   sum()   returns the sum of the doubles stored in the linked storage structure of a LLList class object.  In order to perform this task you will need to traverse the linked list of the object.  For hints on how to write this function look at the print method in the LLList class.  
          Modify the main() routine in ListProcessor to thoroughly test the sum method.
 

Your next task is to create a new insertion method in the LLList class.  This method will insert its parameter value into a new Node object inserted as the last Node in the linked list.  The signature for this method will be void insertAsLast(double x).  There are two groups of cases you should consider when writing this method.  
          This LLList object is empty:  A new Node containing  x  will be the only Node in the linked list.

          This LLList object has one or more Nodes in its linked list:  The code must traverse to the current last Node of the linked list and insert a new Node containing  x  following this Node.  The new Node is then the last Node in the linked list.

          Modify the main() routine in ListProcessor to thoroughly test the insertAsLast method.


Turn In:
Upload all your modified files:  ListProcessor.cpp, LinkedList.h, and LinkedList.cpp into Github and submit github link in wyocourses
