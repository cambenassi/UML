/**********************************************************************
 *                                                  
 *  PS4b: StringSound implementation and SFML audio output 
 **********************************************************************/

Name: Cameron Benassi

Hours to complete assignment : 2.5

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes, I did complete the whole assignment successfully. All parts, including
input, output and correct implementation are present.


/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  
 **********************************************************************/
Yes, I attempted to change the sound depending on the command line arguments,
specifically to a harp. If the user runns the program with the command line argument
"harp" (./KSGuitarSim harp), then the pitch of the sound will be shifted up, causing 
a harp sound versus the original guitar sound.

/**********************************************************************
 *  Did you implement exseptions to check your StringSound 
 *	implementation?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
Yes, I implemented a std::bad_alloc if the init vector is empty.


/**********************************************************************
 *  Did you implement lambda expression?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
Yes, I added one in the StringSound(std::vector<sf::Int16> init) constructor,
where it uses std::for_each and pushes each value of init into _cb.


/**********************************************************************
 *  Did your code pass cpplint?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
Yes it does, I followed the procedures it gave me, along with fixing
the errors it threw about whitespace, include rules, and header names.

/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
none


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
none

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/