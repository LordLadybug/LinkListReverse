// LinkListReverse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// One node equals a struct containing an integer named val and a pointer to the next node
//Reverses list in place

#include <iostream>

struct LinkNode {
    int val;
    LinkNode* ToNextNode;
};

void ListReverser(LinkNode* Node1, LinkNode* Node2);

int main()
{
    //Defining a sample linked list to work with
    LinkNode Root;
    Root.val = 1;
    LinkNode Also;
    Also.val = 2;
    Root.ToNextNode = &Also;
    LinkNode Additionally;
    Additionally.val = 3;
    Also.ToNextNode = &Additionally;
    LinkNode Moreover;
    Moreover.val = 4;
    Additionally.ToNextNode = &Moreover;
    LinkNode Next;
    Next.val = 5;
    Moreover.ToNextNode = &Next;
    LinkNode Last;
    Last.val = 6;
    Next.ToNextNode = &Last;
    Last.ToNextNode = NULL;

    LinkNode* Node1 = &Root; //Uses pointer to Root so that it can be passed into function by reference
    //Reversing the linked list
    if (Root.ToNextNode == NULL)
    {
        std::cout << Root.val; //in the event that the list has just one node, print it and exit the program
        return 0;
    }
    else
    {
        ListReverser(Node1, Node1->ToNextNode);
        Root.ToNextNode = NULL; //after all other pointers are reversed, make sure root points to NULL
    }

    //TESTING:
    Node1 = &Last;  //used to print out the linked list when it is finally reversed
    while (Node1->ToNextNode != NULL)
    {
        std::cout << Node1->val << "\t";
        Node1 = Node1->ToNextNode;
    }
    std::cout << Node1->val << std::endl;   //prints out final member of now reversed linked list
}

void ListReverser(LinkNode* Node1, LinkNode* Node2)
{
    //takes a consecutive pair of nodes in the linked list, presumably starting with the root node
    if (Node2->ToNextNode != NULL)
    {
        //to run when not on last pair of nodes
        ListReverser(Node2, Node2->ToNextNode);
    }
        Node2->ToNextNode = Node1;
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
