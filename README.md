# Maze-problem

<div className=''>

Data types: Dynamic 2D Array, queue, struct for indexes, strings, char** array, int, bool.

<p>--main.cpp </p>
<p>Set up a while loop to keep program running until user says to quit</p>
<p>Call a function to the functionality in maze.cpp</p>

<p>--maze.h </p>
<p> Cell Class  </p>
<p>Struct for queue</p>
<p>Struct for indexes</p>
<p>Initialize front/rear to NULL</p>
<p>Contains Enqueue, Dequeue, isEmpty, and clear entire queue, </p>
<p>Contains prototypes of functions to handle input, initialize arrays, and traverse the maze. </p>

<p>--maze.cpp </p>
<p>Based on user input open selected file</p>
<p>Grab first line of input for length and width of maze/array</p>
<p>Initialize a char 2D array dynamically for maze</p>

<p>Put the values of the chosen txt file into the maze array</p>
<p>Pass maze array into a function to traverse the array</p>
<p>Initialize a bool 2D array dynamically for visited cells</p>
<p>Iterate through the maze array Enqueuing all cells with the value ‘S’. </p>
<p>Initialize a struct variable for Indexes(x,y) of our current cell.</p>

<p>REPEAT:</p>
<p>Dequeue, and make it our current cell. (stored as indexes)</p>
<p>Mark our current cell in our bool array of visited cells to 1. </p>
<p>Pass the maze array, visited array, and index of the current cell into a bool function to Enqueue all adjacent cells. Account for walls, and stay inside the size of the array. </p>
<p>Return whether an adjacent cell is our goal ‘G’. If so, return, print out the maze path, and declare whether it was traversable. </p>
<p>REPEAT (while queue is not empty)</p>

</div>
