README - CPSC 486 Assignment 2

Name:	Matt Short
Class:	CPSC 486
Email:	darkhelmet125@csu.fullerton.edu
Language:	C/C++
Tools:	OpenGL, GLFW, Xcode 5

Implemented features:
	'q' quit the program
	Up arrow moves camera forward	//unsure as to why this should be implemented
	Down arrow moves camera backwards	//unsure as to why this should be implemented
	

Unimplemented features:
	-v: not implemented
	-h: not implemented
	

Notes:
Assignment compiles with 1 warning.
Warnings:
	-'gluLookat' is deprecated as of 10.9, use GLKMatrix4MakeLookAt
I tried to implement the GLKMatrix4 functions from the GLKit.framework and it broke my program so it was not included.
There is a slight glitch where occassionally squares will not bounce off of walls but move along them. After some distance they bounce off correctly and it functions as normal.
The program also stutters a bit so it's not as smooth as it should be.