#pragma once                                                                     
//lang::CwC                                                                  
#include "object.h"                                                             

/**
 * The String class represents a collection of c++ characters.
 * @Immutable
 */
class String : public Object
{
public:

    /**
     * Default Constructor for String. Represents an empty collection of characters.
     */
    String() {}

    /**
     * Constructor for String. Represents the given collection of characters.
     * 
     * @param s the collection of characters
     */
    String(char* s);

    /**
     * Constructor for String. Represents the given collection of characters.
     * 
     * @param s the collection of characters
     */
    String(const char* s);

    /**
     * Destructor for String.
     */
    ~String();

    /**
     * Determines if this string is equal to the given object.
     * 
     * @param other the other object
     * 
     * @return bool true if equal
     */
    bool equals(Object* other);

    /**
     * Compares this string to the given one lexicographically.
     * 
     * @param other the other string
     * 
     * @return int < 0 if this string comes before other, 0 if they are equivalent,
     *             > 0 if other comes before this string
     */
    int compare(String* other);

    /**
     * Concatenates the given string to the end of this string.
     * 
     * @param other the other string
     * 
     * @return String* the new string
     */
    String* concat(String* other);

    /**
     * Returns the length of this string's character sequence (excluding '\0')
     * 
     * @return size_t the length of the character sequence
     */
    size_t size();

    /**
     * Computes a hash code for this string.
     * 
     * @return size_t the hash code
     */
    size_t hash_me_();
};
