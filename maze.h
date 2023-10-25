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
	struct QueueNode
	{
		char info;
		QueueNode* next;
	};
	typedef QueueNode* QueueNodePtr;

	QueueNodePtr front;
	QueueNodePtr rear;

	int ROWS;
	int COLS;

	void Enqueue(char a);
	void Dequeue();
	void Print();


	char** InitalizeArray(std::ifstream & myFile);
	bool TraverseMaze(char** maze);
};