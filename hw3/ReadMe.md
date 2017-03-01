# ReadMe for COMP 15 HW3
## ISIS Course Roster and Waitlists

Every assignment you submit you will include a ReadMe file. The name
could be ReadMe, readme, Read-me.txt, readME, ReadMe.md (the “.md”
stands for “markdown,” which allows lightweight formatting) or almost
anything you like that has the word read followed by the word me. Exact
spelling is not important, the contents are.

The purpose of the ReadMe file is the same as the little paper insert
you get in a new appliance -- to give the reader an introduction and
overview of the product.

Your ReadMe file for the assignments **must** include:

1.  The purpose of your program

	This program allows students who are majoring in a subject to go directly in to the class roster, and those that are 
not majors will go onto a waitlist. Additionally, if the class is at a defined capacity, major students will be placed onto 
a waitlist of their own. For the implementation of this program this program used a set, queues and a class.  

2.  List of files with one/or two-line summary

	Queue.cpp/h : Queue.cpp and Queue.h are queue implementations that are used to model students, 
		      in waitlists. Queues are used by IsisCourse.cpp/h.
	
	IsisCourse.cpp/h : IsisCourse.cpp and IsisCourse.h are classes that deal with distributing students into 
			   their respective classes and assigning them to the respective waitlists.  

	Set.cpp/h: The Set.cpp and Set.h model the class in which waitlisted students are put into. 

	Student.h: Student.h is a struct that holds 2 variables for a student. A bool of whether or not the 
		   student is majoring in comp sci, and a string of his name.

3.  How to compile it (saying "use included Makefile" is ok)

	Use included Makefile. 

4.  Outline of data structure (depending on the assignment)

	The main data structure used in this assignment was queues that were used to model students, 
		      in waitlists. Queues are used by IsisCourse.cpp/h.

5.  Outline of algorithm (depending on the assignment)
	
	The algorith included a cooperation of a set, a queue, a class, and a struct. The set modeled the clash in which
waitlisted students are put into, the queue modeled students in and out of these waitlists, the class kept the ernollement 
statuses up to date and assigned the students to their required class or waitlist, and finally the struct hold the details of each student. 


6.  A list of people who materially helped you on the assignment. If
    you worked with a friend and you shared ideas, you need to 
    list that person, e.g., "Josh Whedon helped me on this assignment".
    You do not need to list TAs, or professors, but you may feel free
    to do so.
	
	No one. 

The ReadMe file shows the reader, in a quick glance, what the program is
about and gives a general idea of how it works. For short programs the
readme file will be short, for more complicated programs the readme file
will be longer.

Use outline form rather than long discursive paragraphs. A ReadMe file
is an overview.

There is no correct readme format; within these guidelines, devise your
own style.
