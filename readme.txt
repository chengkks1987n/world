world

c++ version for the project 4 in MIT open course 6.001-spring-2005 SICP.

TODO:
	. finish Room test;
	. complete the destructor of some class; 
	. alternative, change the pointer to smart-pointer; 
	  use factory to create object, so thate all the object are
	  created on the heap, not the stack.
	. design and implementation the class Exit.

what should the header file include? the class interface or just the declaration
(just "class XXX;") ? 
I think the second way is better. in this way ,you put the declaration and implemetation in the same file(CPP file). it's more clear, and easy to change the code.
when you change the interface or implementation of a class, you don't need to compile the other source files depenend on this class. you just compile the only one source file. 
referance to the class Exit.



