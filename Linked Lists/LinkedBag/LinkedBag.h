//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
    @file LinkedBag.h 
    Listing 4-3 */
#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node
   int itemCount;           // Current count of bag items
   
   // Returns either a pointer to the node containing a given entry
   // or the null pointer if the entry is not in the bag.
   Node<ItemType>* getPointerTo(const ItemType& target) const;
    int getRecursively(Node<ItemType>* node); // wrapper functiont to recursively get size of bag
   
public:
   LinkedBag(); // default constructor
   LinkedBag(ItemType entries[], int entryCount); // constructor with params; create bag with given array
   LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
   virtual ~LinkedBag();                       // Destructor should be virtual
   int getCurrentSize() const; // iteratively get size of the bag
   bool isEmpty() const; // determine if bag is empty
   void deleteSecondNode(); // delete second node in bag
   bool add(const ItemType& newEntry); // add node to the end of a bga
   bool remove(const ItemType& anEntry); // remove a specified node
   void clear(); // empty the bag
   int getCurrentSizeRecursive(); // use recursion to get the size of the bag
   bool contains(const ItemType& anEntry) const; // func to determine if certain thing is present in a bag
   int getFrequencyOf(const ItemType& anEntry) const; // determine how many times a given item coems up in a bag
   std::vector<ItemType> toVector() const; // ...
   ItemType removeRandom(); // remove random node from bag
}; // end LinkedBag

// commented out because the terminal was throwing redefinition erros
#include "LinkedBag.cpp"
#endif
