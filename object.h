#pragma once
//lang::CwC

/**
 * Represents the top node in a class hierarchy.
 */
class Object
{
	public:
		
		/**
		 * Default Constructor for Object. Represents an empty object with no data.
		 */
		Object();

		/**
		 * Destructor for Object.
		 */
		~Object();

		/**
		 * Computes and stores a hash code for this object.
		 * 
		 * @return the hash code
		 */
		size_t hash();

		/**
		 * Computes a hash code for this object.
		 * Virtual so child classes can more uniquely compute a code.
		 * 
		 * @return size_t the new hash code
		 */
		virtual size_t hash_me_();

		/**
		 * Determines if this object is equal to the given one.
		 * Virtual so child classes can control their own equality.
		 * 
		 * @return bool true if equal
		 */
		virtual bool equals(Object* other);
};