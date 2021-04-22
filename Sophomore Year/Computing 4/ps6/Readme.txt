/**********************************************************************
 *  readme.txt template                                                   
 *  PS6 Kronos 
 **********************************************************************/

Name: Cameron Benassi


Hours to complete assignment:   3


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
The only parts of this assignment which are not working are the date/time
calculations, and the failure message. I know that the server startup
messages are working because I checked them manually on device1.log


/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
startup("server started") - detects if a server startup message has been printed
success("oejs.AbstractConnector:Started SelectChannelConnector") - checks if startup was successful
date("([0-9]{2}):([0-9]{2}):([0-9]{2})") - checks the time of startup & completion


/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
My approach for solving this problem was to run a while loop that would
iterate through the file, line by line, scanning each regex until one is 
matched. When matched, the program would see if it was a startup, startup 
success, or startup failure, then print this information to another file.



/**********************************************************************
 *  Did you use lambda expression? If yes describe there.
 **********************************************************************/
No




/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
None


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
none


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/