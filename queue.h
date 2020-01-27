#pragma once
//lang::CwC
#include "object.h"

/**
 * The Queue class represents a collection of elements to be held in order for processing.
 * Elements are processed on a "first in, first out" basis.
 */
class Queue : public Object
{
	public:

		/**
		 * Default constructor for Queue. Represents an empty list
		 * of elements to be processed.
		 */
		Queue();

		/**
		 * Destructor for Queue.
		 */
		~Queue();

		/**
		 * Constructor for Queue. Represents a list with a given maximum
		 * possible size.
		 * 
		 * @param max_size the maximum possible number of elements this queue can hold
		 */
		Queue(size_t max_size);

		/**
		 * Adds the given object to the queue if possible.
		 * 
		 * @param new_value the object to add
		 * 
		 * @return bool true if successful
		 */
		bool enqueue(Object* new_value);

		/**
		 * Removes the next element to be processed.
		 * 
		 * @return Object* the next element
		 */
		Object* dequeue();

		/**
		 * Calculate the number of elements currently in this queue.
		 * 
		 * @return size_t the number of elements
		 */
		size_t size();

		/**
		 * Returns the maximum capacity of this queue.
		 * 
		 * @return size_t the maximum capacity.
		 */
		size_t max_size();

		/**
		 * Clears this queue of all elements.
		 * 
		 * @return void
		 */
		void clear();

		/**
		 * Determines if this queue has no elements in waiting.
		 * 
		 * @return bool true if there are no elements
		 */
		bool is_empty();

		/**
		 * Determines if this queue has the maximum number of possible elements.
		 * 
		 * @return bool true if the number of elements is the same as maximum capacity
		 */
		bool is_full();

		/**
		 * Computes a hash code for this queue.
		 * 
		 * @return size_t the hash code
		 */
		size_t hash_me_();

		/**
		 * Determines if this queue is equal to the given object.
		 * 
		 * @return bool true if equal
		 */
		bool equals(Object* other);

		/**
		*  Shows the next item in the Queue, but does not remove it.
		*
		*  @return the next object in the queue
		*/
		Object* peek();
};