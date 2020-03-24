//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */

//#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>
#include <stdlib.h> // rand

// CONSTRUCTOR FUNCTION
template<class ItemType>
LinkedBag<ItemType>::LinkedBag():headPtr(nullptr), itemCount(0)
{
}  // end default constructor

// creates a bag from a given array of entries CONSRTRUCTOR FUNCTION WITH PARAMETERS
template<class ItemType>
LinkedBag<ItemType>::LinkedBag(ItemType entries[], int entryCount):headPtr(nullptr), itemCount(0)
{
    for(int i = 0; i < entryCount; i++)
    {
        add(entries[i]); // call the add function to add entries to the bag
    }
    itemCount = entryCount;
} // end constructor

// CONSTRUCTOR FUNCTION WITH PARAMS
template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
   Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
              
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();

         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty


// add new node to the end of the linked chain
template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
    Node<ItemType>* newNodePtr = new Node<ItemType>(); // create new node
    newNodePtr->setItem(newEntry); // insert the entry
    newNodePtr->setNext(nullptr); // set to nullPtr because it is the final node in the linked list
    
    // if the current node does not have an head pointer node, then the newly created one is the head node
    if(headPtr == nullptr)
    {
        headPtr = newNodePtr;
    }
    // IS THIS PART EVEN NEEDED
    else if (headPtr->getNext() == nullptr)
    {
        headPtr->setNext(newNodePtr);
    }
    // if there were nodes created before the current node
    else
    {
        // create a new node that will be used to traverse through the linked list
        Node<ItemType>* tempNode = new Node<ItemType>();
        // start off with the node pointing to the head node
        tempNode = headPtr;
        // go through the linked list until get to the last node
        while(tempNode->getNext() != nullptr)
        {
            tempNode = tempNode->getNext(); // increment the pivot node; move through the list
        }
        tempNode->setNext(newNodePtr); // once you at the end, point to the newly created pointer
    }
    itemCount++;
    return true;
} // end add method

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
   Node<ItemType>* curPtr = headPtr;
   int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
   {
		bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  // end while
   
   return bagContents;
}  // end toVector

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr
   
	itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
   int counter = 0;
   Node<ItemType>* curPtr = headPtr;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      curPtr = curPtr->getNext();
   } // end while
   
	return frequency;
}  // end getFrequencyOf


//ALTERNATE 1
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getFrequencyOf(anEntry) > 0;
} 


// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& target) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   
   while (!found && (curPtr != nullptr))
   {
      if (target == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while
   
   return curPtr;
} // end getPointerTo

// function to delete the second node of the list
template <class ItemType>
void LinkedBag<ItemType>::deleteSecondNode()
{
    Node<ItemType>* toDelete = nullptr; // set node reference to second node
    
    // make sure that there is a second node
    if (headPtr->getNext() != nullptr) {
        toDelete = headPtr->getNext();
        // toDelete->setItem(toDelete->getItem());
        headPtr->setNext(toDelete->getNext()); // make sure that the first node is not pointing to the second node. Make sure that the first node is now pointing to the third node, or the node to which the second one was pointing to
        toDelete->setNext(nullptr); // make sure that the node you want to delete is not pointing to another node
        delete toDelete;
        toDelete = nullptr; // prevent memory leak
        itemCount--;
    }
    else
    {
        toDelete = nullptr;
    }
} // end deleteSecondNode

// function to recursively get the size of the bag
template<class ItemType>
int LinkedBag<ItemType>::getCurrentSizeRecursive()
{
    int numberNodes = getRecursively(headPtr);
    
    return numberNodes;
}
// wrapper function
// uses recursion to count nodes and get size of list
template<class ItemType>
int LinkedBag<ItemType>::getRecursively(Node<ItemType>* node)
{
    if (headPtr == nullptr) {
        return 0;
    }
    else {
        headPtr = headPtr->getNext();
        return 1 + getRecursively(headPtr);
    }
} // end getCurrentSizeRecursive

// returns the number of nodes in the chain iteratively
template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
    int counter = 0;
    if (headPtr != nullptr)
    {
        Node<ItemType>* pivot = headPtr;
        while (pivot != nullptr)
        {
            counter++;
            pivot = pivot->getNext();
        }
    }
    
    return counter;
} // end getCurrentSize

// removes a random node from the linked list and returns its type
template<class ItemType>
ItemType LinkedBag<ItemType>::removeRandom()
{
    ItemType removedItem;
    // if there's no node
    if (headPtr == nullptr)
    {
        return 0;
    }
    // if there's only one node
    else if (headPtr->getNext() == nullptr)
    {
        removedItem = headPtr->getItem();
        delete headPtr;
        headPtr = nullptr;
        itemCount--;
        return removedItem;
    }
    // if there are multiple nodes
    else
    {
        // generate a random number
        int numberNodes = getCurrentSize();
        int randNode = rand() % numberNodes;
        
        // if the very first node is chosen
        if (randNode == 0)
        {
            // create node to point to node that will be deleted
            Node<ItemType>* nodeToDeletePtr = headPtr;
            // point the headptr to the second node since the first is getting deleted
            headPtr = headPtr->getNext();
            
            // save the item located in the node that is getting deleted
            removedItem = nodeToDeletePtr->getItem();
            
            // Return node to the system
            nodeToDeletePtr->setNext(nullptr);
            delete nodeToDeletePtr;
            nodeToDeletePtr = nullptr;
            
            // decrement
            itemCount--;
            
            // return the item that has been removed
            return removedItem;
        }
        // if the second node is chosen
        else if (randNode ==  1) {
            Node<ItemType>* tempNode = headPtr->getNext();
            removedItem = tempNode->getItem();
            headPtr->setNext(tempNode->getNext());
            tempNode->setNext(nullptr);
            delete tempNode;
            tempNode = nullptr;
            itemCount--;
            return removedItem;
        }
        // if the last node is chosen
        // numberNodes - 1 because randNode will generate numbers from 0 to (# nodes - 1) since it uses mod
        // need a different condition for the last one because the second to last will need to point to nullptr
        else if (randNode == numberNodes - 1 && randNode != 1)
        {
            // only go up to the second to last node
            for(int i = 0; i < randNode - 2; i++)
            {
                // get the headPtr to point to the second to last node
                headPtr = headPtr->getNext();
                // create a new node and have it point to the last node
                Node<ItemType>* nodeToDeletePtr = headPtr->getNext();
                // will be deleting last node so set to nullptr because this will now be the new last node
                headPtr->setNext(nullptr);
                
                // save the item located in the node getting deleted
                removedItem = nodeToDeletePtr->getItem();
                
                // Return node to the system
                nodeToDeletePtr->setNext(nullptr);
                delete nodeToDeletePtr;
                nodeToDeletePtr = nullptr;
                
                itemCount--;
                
                return removedItem;
            }
        }
        else
        {
            for(int i = 0; i < randNode - 2; i++)
            {
                // set headPtr to the next node
                headPtr = headPtr->getNext(); // will eventually end up pointing to the node we want to delete
                // create a new node that will be deleted
                Node<ItemType>* nodeToDeletePtr = headPtr->getNext();
                // point the headptr to the next node since there is one getting deleted
                headPtr->setNext(nodeToDeletePtr->getNext());
                
                // save the item
                removedItem = nodeToDeletePtr->getItem();
                
                // Return node to the system
                nodeToDeletePtr->setNext(nullptr);
                delete nodeToDeletePtr;
                nodeToDeletePtr = nullptr;
                
                itemCount--;
                
                return removedItem;
            }
        }
        return removedItem;
    }
    
} // end removeRandom


template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
   Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());
      
      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
   } // end if
   
    return canRemoveItem;
}  // end remove
