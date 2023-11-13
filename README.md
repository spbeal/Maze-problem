# Maze-problem

Data types: Dynamic 2D Array, queue, struct for indexes, strings, char** array, int, bool.

main.cpp
Set up a while loop to keep program running until user says to quit
Call a function to the functionality in maze.cpp

maze.h
Cell Class 
Struct for queue
Struct for indexes
Initialize front/rear to NULL
Contains Enqueue, Dequeue, isEmpty, and clear entire queue, 
Contains prototypes of functions to handle input, initialize arrays, and traverse the maze. 

maze.cpp
Based on user input open selected file
Grab first line of input for length and width of maze/array
Initialize a char 2D array dynamically for maze

Put the values of the chosen txt file into the maze array
Pass maze array into a function to traverse the array
Initialize a bool 2D array dynamically for visited cells
Iterate through the maze array Enqueuing all cells with the value ‘S’. 
Initialize a struct variable for Indexes(x,y) of our current cell.

REPEAT:
Dequeue, and make it our current cell. (stored as indexes)
Mark our current cell in our bool array of visited cells to 1. 
Pass the maze array, visited array, and index of the current cell into a bool function to Enqueue all adjacent cells. Account for walls, and stay inside the size of the array. 
Return whether an adjacent cell is our goal ‘G’. If so, return, print out the maze path, and declare whether it was traversable. 
REPEAT (while queue is not empty)
