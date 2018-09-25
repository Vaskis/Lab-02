// LinkedList.cpp

// tom bailey   0745  5 oct 2010
// Definition of methods for the List class.

#include "LinkedList.h"

#include <utility>


List::List()
	: first_(NULL)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}

const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}

// Jag has ordered us to do this, all hail Jag!
// This code would not compile and we never used it anyway
/*
bool List::operator==(const List &rhs){
  
	if(this.size() == 0 && rhs.size() == 0){return true;}//both empty
    if(this.size() != rhs.size()){return false;}//sizes not the same

    Node * lptr = this->next_;
    Node * rptr = rhs->next_;
		Double lEntry = lptr->entry_;
    Double rEntry = rptr->entry_;
		while (lptr != NULL && rptr != NULL)
		{
      if(lEntry != rEntry){
        return false;
      }
      lptr = lptr->next_;
      rptr = rptr->next_;
      lEntry = lptr->entry_;
      rEntry = rptr->entry_;
		}
	
  	return true;

}
*/


bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);
}


double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Jeremiah Vaskis Functions with assistance from classmates and TA

// Each Node has a pointer to itself called "first_"
// a double data entry called "entry_"
// and a pointer address component that points to the next Node if there is a next Node called "next_"
// If there is no next Node then it's pointer address' value is NULL (the last Node in the list)

// Returns the size of the Linked List (Number of Nodes in the chain)
double List::size() {
	// Initialize count as one
	double count = 1;
	// Check if the Node does not exists
	if (!empty()) {
		// ptr is a pointer to an object called Node, setting ptr to the first pointer-component in the list
		// which is the first Node's pointer-component (if it is NULL then thats the only Node)
		Node * ptr = first_->next_;
		
		while (ptr != NULL)
		{
			// Sets the pointer "ptr"'s value to what the next Node's pointer-component value is
			ptr = ptr->next_;
			// Increment the count to tally how many Nodes there are
			count = count + 1;
		}
	}
	else {
		count = 0; // If there is no Node or it is "empty" then return 0
	}
	return count;
};

// Sums the stored "entry_" values of all of the Nodes in a list
double List::sum() {

	double sum;
	// Check to see if the Node empty or non-existant?
	if (!empty()) {
		// ptr is a pointer to an object called Node, setting ptr to the first address in the list
		// which is the first Node's pointer-component (if it is NULL then thats the only Node)
		Node * ptr = first_->next_;

		// sets sum to the first entry (before it checks if it is the only Node in the list)
		sum = first_->entry_;

		while (ptr != NULL)
		{
			// adds the next Node's entry to the sum
			sum = sum + ptr->entry_;
			// Indexes the ptr to be to the next Node
			ptr = ptr->next_;
		}
	}
	else {
		sum = 0;
	}

	return sum;
};

void List::insertAsLast(double x) {
	if (!empty()) {
		// ptr is a pointer to an object called Node
		// this pointer is only to the first Node object, it is NOT the
		// first Node's pointer-component (which would lead to the next Node if there was one)
		Node * ptr = first_;

		// Looks to see if the next Node's pointer-component value is NULL
		// If it IS NOT NULL then it changes ptr's value to that address value
		// Key thing is it LOOKS AHEAD before it does anything
		while (ptr->next_ != NULL)
		{
			// Assigns ptr to the next Node's pointer-address value
			ptr = ptr -> next_;
		}

		// Once it has found the last Node (the Node with a NULL pointer-component)
		// it overwrites the pointer-component value of NULL with the object-pointer of a newly made Node
		// (which has NULL as its pointer component).
		ptr->next_= new Node(x, NULL);
	}
	else {
		// If there is no Node, then it creates one with the given double value
		first_ = new Node(x, NULL);
	}
	return;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}
