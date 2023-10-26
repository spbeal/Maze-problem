#pragma once
#include <iostream>
#include <fstream>

class Cells
{
public:

	Cells()
	{
		front = NULL;
		rear = NULL;
	}
	bool OpenFile();

private:
// Struct for representing index in maze 
	struct Index {
		int row, col;
		Index(int x, int y)
		{
			row = x;
			col = y;
		}
		Index()
		{
			row = 0;
			col = 0;
		}
	};

	struct QueueNode
	{
		Index index;
		QueueNode* next;
	};
	typedef QueueNode* QueueNodePtr;

	QueueNodePtr front;
	QueueNodePtr rear;

	int ROWS = 0;
	int COLS = 0;

	// Queue Functions 
	void Enqueue(Index a);
	Index Dequeue();
	void ClearQueue();
	bool IsEmpty();
	// Maze functions
	char** InitalizeArray(std::ifstream & myFile);
	bool Adjacent(Index curr, char** maze, bool** visited);
	bool TraverseMaze(char** maze);
};