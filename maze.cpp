
#include "maze.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Initalize Array
bool Cells::OpenFile()
{
string input = "";

std::cout << "Which maze would you like to traverse? ";
getline(cin, input);
if (input == "quit") return 0;
if (input.empty())
{

}
else
{
    std::ifstream myFile;
    myFile.open(input);

    if (!myFile) cerr << "No input file at: " << input << endl;
    else
    {
        char** maze = InitalizeArray(myFile); // pass in ifstream
        myFile.close();
        int traversable = TraverseMaze(maze);
        if (traversable == 1) cout << "It is traversable" << endl;
        else std::cout << "Not traversable" << endl;
    }
}
return 1;
}

char** Cells::InitalizeArray(ifstream& myFile)
{
    int i = 0, j = 0;
    int sizes[2] = { 0, 0 };
    std::string temp = "";
    std::string curr = "";

    // grab first line for length/width
    getline(myFile, temp, '\n');
    temp += ' ';

    for (int t = 0; t < temp.length(); t++)
    {
        if (temp[t] != ' ')
        {
            curr += temp[i];
        }
        else
        {
            sizes[j] = stoi(curr);
            j++;
            curr = "";
        }
        i++;
    }

    ROWS = sizes[0];
    COLS = sizes[1];

    // INITALIZE 2D array
    char** maze = new char* [ROWS];
    for (i = 0; i < ROWS; i++)
    {
        maze[i] = new char[COLS];
    }

    i = 0;
    while (getline(myFile, temp, '\n') && i < ROWS)
    {
        for (j = 0; j < COLS; j++)
        {
            maze[i][j] = temp[j];
        }
        i++;
    }
    // print maze out
    //for (i = 0; i < ROWS; i++) {
    //    for (j = 0; j < COLS; j++)
    //    {
    //        std::cout << maze[i][j] << " ";
    //    }
    //    std::cout << endl;
    //}
    return maze;
}

bool Cells::TraverseMaze(char** maze)
{
    int currLoc[2] = { 0, 0 };
    // Visualize the maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
        {
            std::cout << maze[i][j] << " ";
            if (maze[i][j] == 'S') {
                currLoc[0] = i;
                currLoc[1] = j;
            }
        }
        std::cout << endl;
    }
    
    int i = currLoc[0];
    int j = currLoc[1];
    
    while (maze[i][j] != 'G') // || i < ROWS
    {
        std::cout << "Before: " << maze[i][j] << endl;
        std::cout << "Before: " << maze[i][++j] << endl;

        Enqueue(maze[i][++j]);
        Print();
        maze[i][j] = 'G';
        return 0;
    }
    //for (int i = currLoc[i]; i < ROWS; i++) {
    //    for (int j = currLoc[j]; j < COLS; j++)
    //    {

    //        std::cout << maze[i][j] << " ";
    //    }
    //    std::cout << endl;
    //}

    return 1;
}
// delete array for next. 
//for (i = 0; i < ROWS; i++)
//    delete[] maze[i];
//delete[] maze;

// . empty space (legal to move)
// # a wall (illegal to move)
// S starting posotion
// G final position (goal)
// *  Make some symbol mark already visited

// Put north south east west into queue, only if it is not a wall
// Traverse the array at the start to find S, then go from there. 
// Go until you find G.



void Cells::Enqueue(char a)
{
    QueueNodePtr n = new QueueNode;
    n->info = a;
    n->next = NULL;

    if (rear == NULL) front = rear = n;

    else {
        rear->next = n;
        rear = n;
    }
}

void Cells::Dequeue()
{
    if (front == NULL) {
        printf("Queue is empty");
    }
    else {
        QueueNode* temp = front;
        front = front->next;
        temp->next = NULL;

        if (front == NULL) rear = NULL;

        delete temp;
    }
}

void Cells::Print()
{
    QueueNodePtr p = front;
    int i = 0;
    while (p != NULL)
    {
        std::cout << "Element " << i << ": " << p->info << std::endl;
        p = p->next;
        i++;
    }
}
