// LinkListReverse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// One node equals a struct containing an integer named val and a pointer to the next node
//Prints out reversed linked list

#include <iostream>

struct LinkNode {
    int val;
    LinkNode* ToNextNode;
};

void ListReverser(LinkNode Node1, LinkNode Node2);

int main()
{
    std::cout << "Hello World!\n";
    //Defining a sample linked list to work with
    LinkNode Root;
    Root.val = 2;
    LinkNode Also;
    Also.val = 4;
    Root.ToNextNode = &Also;
    LinkNode Additionally;
    Additionally.val = 6;
    Also.ToNextNode = &Additionally;
    LinkNode Moreover;
    Moreover.val = 8;
    Additionally.ToNextNode = &Moreover;
    LinkNode Next;
    Next.val = 10;
    Moreover.ToNextNode = &Next;
    LinkNode Last;
    Last.val = 12;
    Next.ToNextNode = &Last;
    Last.ToNextNode = NULL;

    //Generating the first pair of nodes to be plugged into our function:
    LinkNode Node1 = Root;
    LinkNode Node2;
    if (Node1.ToNextNode != NULL)
    {
        Node2 = *Node1.ToNextNode;  //Only does this if there is more than one node in the list
    }
    else
    {
        std::cout << Node1.val; //in the event that the list has just one node, print it and exit the program
        return 0;
    }
    ListReverser(Node1, Node2);
}

void ListReverser(LinkNode Node1, LinkNode Node2)
{
    if (Node2.ToNextNode == NULL)
    {
        std::cout << Node2.val << "\t" << Node1.val << "\t";
        Node1.ToNextNode = NULL;
    }
    else
    {
        ListReverser(Node2, *Node2.ToNextNode);
        std::cout << Node1.val << "\t";
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
