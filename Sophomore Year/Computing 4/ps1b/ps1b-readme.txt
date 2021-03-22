/**********************************************************************
 *  Linear Feedback Shift Register (part B) ps1b-readme.txt template
 **********************************************************************/

Name: Cameron Benassi

Hours to complete assignment: 3 hrs
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

The purpose of this assignment was to incorperate the FibLFSR code into
an image encryption program. Using the pseudo-random results of the FibLFSR
generate function, I XOR'd each pixel's color with the results, creating
a jumbled, yet recoverable new photo. This process is reversable if the same
seed is given, but the pictures are reversed.


/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/

none



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/

none

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

The biggest issues I had with my development of this program came from 
properly including all of the necessary SFML libraries in my Makefile,
but once that was taken care of, there were no major road blocks.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/