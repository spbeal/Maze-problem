
#include "maze.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Initalize Array
bool Cells::OpenFile()
{
    // User input to choose which maze to traverse
    string input = "";
    std::cout << "Which maze would you like to traverse? ";
    getline(cin, input);
    if (input == "quit") return 0;
    if (input.empty())
    {

    }
    else
    {
        // Open user selected file,
        std::ifstream myFile;
        myFile.open(input);

        if (!myFile) cerr << "No input file at: " << input << endl;
        else
        {
            // Initalize array with chosen maze
            char** maze = InitalizeArray(myFile);
            myFile.close();
            // Traverse maze
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

    // grab size of maze
    getline(myFile, temp, '\n');
    temp += ' ';
    // handle first line of input 
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

    // INITALIZE 2D array dynamically
    char** maze = new char* [ROWS];
    for (i = 0; i < ROWS; i++)
    {
        maze[i] = new char[COLS];
    }

    i = 0; // Load maze into array 
    while (getline(myFile, temp, '\n') && i < ROWS)
    {
        for (j = 0; j < COLS; j++)
        {
            maze[i][j] = temp[j];
        }
        i++;
    }
    return maze;
}

bool Cells::TraverseMaze(char** maze)
{
    Index curr;
    ClearQueue(); // for traversing multiple times per compile

    // Acquire locations of 'S'
    // Initailize a 2D array of bools for visited
    bool** visited = new bool* [ROWS];
    for (int i = 0; i < ROWS; i++)
    {
        visited[i] = new bool[COLS];

        for (int j = 0; j < COLS; j++)
        {
            visited[i][j] = 0;

            if (maze[i][j] == 'S') {
                // multiple starting points
                curr = Index(i, j);
                Enqueue(curr);
            }
        }
    }

    do
    {
        // Dequeue to current cell, declare it visited, 
        // Then enqueue adjacent cells
        curr = Dequeue();
        visited[curr.row][curr.col] = 1;
        bool goal = Adjacent(curr, maze, visited);
        // Check for 'G'
        if (goal == 1) 
            return 1;

    } while (IsEmpty() != 1);

    return 0;
}

bool Cells::Adjacent(Index curr, char ** maze, bool** visited)
{
    // Use ROWS and COLS to properly enqueue
    int x = curr.row;
    int y = curr.col;

    // up
    if ((x - 1) >= 0 && maze[x - 1][y] != '#' && visited[x - 1][y] != 1)
    {
        Enqueue(Index(x - 1, y));
        if (maze[x - 1][y] == 'G') return 1;
    }
    // down
    if ((x + 1) < ROWS && maze[x + 1][y] != '#' && visited[x + 1][y] != 1)
    {
        Enqueue(Index(x + 1, y));
        if (maze[x + 1][y] == 'G') return 1;
    }
    // left
    if (y - 1 >= 0 && maze[x][y - 1] != '#' && visited[x][y-1] != 1)
    {
        Enqueue(Index(x, y - 1));
        if (maze[x][y - 1] == 'G') return 1;
    }
    // right
    if (y + 1 < COLS && maze[x][y + 1] != '#' && visited[x][y+1] != 1)
    {
        Enqueue(Index(x, y + 1));
        if (maze[x][y + 1] == 'G') return 1;
    }
    return 0;
}

// Queue functions 
void Cells::Enqueue(Index a)
{
    QueueNodePtr n = new QueueNode;
    n->index = a;
    n->next = NULL;

    if (rear == NULL) front = rear = n;
    else {
        rear->next = n;
        rear = n;
    }
}

Cells::Index Cells::Dequeue()
{
    if (front == NULL) {
        cerr << "Queue is empty";
        exit(1);
    }
    else {
        QueueNodePtr temp = front;
        int a = front->index.row;
        int b = front->index.col;

        front = front->next;
        temp->next = NULL;

        if (front == NULL) rear = NULL;

        delete temp;
        return Index(a, b);
    }
}

void Cells::ClearQueue()
{
    if (front == NULL);
    else
    {
        while (IsEmpty() != 1)
        {
            QueueNodePtr temp = front;
            front = front->next;
            temp->next = NULL;
            
            if (front == NULL) rear = NULL;

            delete temp;
        }
    }
}

bool Cells::IsEmpty()
{
    QueueNodePtr p = front;
    if (p == NULL) return 1;
    else return 0;
}