/*
/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

//Name: Cameron Benassi
//Hours to complete assignment: ~2 Hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.

 **********************************************************************/
In this assignment, we were asked to implement a LFSR on a given seed,
and with given bits to swap. With my program, I programmed a constructor
that deals with invalid arguments, along with member functions that perform
the shift itself.

/**********************************************************************
 *  Explain the representation you used for the register bits 
 *  (how it works, and why you selected it)
  **********************************************************************/
Personally, I used a string variable, but treated it as a binary number. 
I did this by accessing the 15th element for the least signifigant bit, 
and visa-versa. 

 
/**********************************************************************
 * Discuss what's being tested in your two additional Boost unit tests
  **********************************************************************/
For my custom tests, I decided to test what would happen if you fed my 
constructor invalid arguments. These invalid arguments include ones that
are too short, ones that are too long, or ones that contain letters. 


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
None


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
Trying to understand how Boost worked, but the website taught me how to 
use it


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/