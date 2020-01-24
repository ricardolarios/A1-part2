Here we created an interface for a standard first in, first out queue. 
It will be able to accept as input anything that inherits from the Object class, created in the object.h file.

# Tests

The tests that we wrote include some standard tests checking the size and whether adding and removing
elements from the Queue produce the expected result. We also test if it will work with instances
of both the Object and String classes (that implement from object.h and string.h).