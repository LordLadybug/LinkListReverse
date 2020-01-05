// LinkListReverse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// One node equals a struct containing an integer named val and a pointer to the next node
//Prints out reversed linked list

#include <iostream>

struct LinkNode {
    int val;
    LinkNode* ToNextNode;
};

int main()
{
    std::cout << "Hello World!\n";
    //Defining a sample linked list to work with
    LinkNode Root;
    Root.val = 1;
    LinkNode Next;
    Next.val = 2;
    Root.ToNextNode = &Next;
    LinkNode Last;
    Last.val = 3;
    Next.ToNextNode = &Last;
    Last.ToNextNode = NULL;

    //Traverse once to get count of number of nodes
    LinkNode CurrentNode = Root;
    unsigned int NodeCounter = 0;
    while (CurrentNode.ToNextNode != NULL)
    {
        NodeCounter++;
        CurrentNode = *CurrentNode.ToNextNode;
    }
    std::cout << NodeCounter << std::endl;
    
    //Traverse through entire list to last node specified by NodeCounter, print val and then keep travelling to earlier members of list and keep printing
    for (int i = NodeCounter; i >= 0; i--)
    {
        CurrentNode = Root; //Reset value of CurrentNode to Root for next set of loops
        for (int j = 0; j < i; j++)
        {
            CurrentNode = *CurrentNode.ToNextNode;
        }
        std::cout << CurrentNode.val << "\t";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
