/**********************************************************************
 *  ps5-readme 
 *  Recursive Graphics (Triangle Fractal)                       
 **********************************************************************/

Your name: Cameron Benassi

Hours to complete assignment: 3

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
In this assignment, we were tasked with using recursion to draw a set of
triangles. With each iteration of the fTree function, 3 more triangles were
added onto each existing triangle, resulting in a fractal like pattern.


 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
In this assignment, the sf::VertexArray was critical in Triangle creation.
This data structure was used to store all of the points for each trinagle,
along with color data.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
My code is structured around the Triangle class, which stores various 
information about each trinagle. This includes coordinates, colors, 
etc. Recursion is heavily used in my fTree function as well, with it being
crucial to how it is ran.

For example: fTree runs until int depth == 0
fTree(triangleVec, window, depth, length);


 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/
I learned that recursion can be very useful to problems where I normally
would not think of using it. If it was not required, I probably would have
used another form of implementation for my code, but because of the requirements,
I like to believe that my code is more efficent because of it.


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
none


/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/
none


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/