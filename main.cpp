// CS 121 main.cpp
// Assignment 4
// Samuel Beal

#include <iostream>
#include "maze.h"

using namespace std;

int main()
{
    Cells s;
    bool loop = true;

    while (loop)
    {
        loop = s.OpenFile();
    }
    return 0;
}

