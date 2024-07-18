#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class representing an element of the linked list
class Node
{
public:
    int data;   // Data held by the node
    Node *next; // Pointer to the next node

    // Default constructor initializing data to -1 and next to NULL
    Node()
    {
        data = -1;
        next = NULL;
    }

    // Parameterized constructor to initialize the node with a specific value
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Definition of the MyLinkedList class to manage the linked list
class MyLinkedList
{
    Node *head; // Pointer to the head (first node) of the list
    int length; // Keeps track of the number of elements in the list

public:
    // Constructor initializing the linked list to be empty
    MyLinkedList()
    {
        head = NULL;
        length = 0;
    }

    // Method to get the value of the node at a specific index
    int get(int index)
    {
        // If the index is out of bounds, return -1
        if (index < 0 || index >= length)
            return -1;

        // Traverse the list to reach the specified index
        Node *curr = head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        // Return the data of the node at the specified index
        return curr->data;
    }

    // Method to add a node with a specific value at the head of the list
    void addAtHead(int val)
    {
        Node *newNode = new Node(val); // Create a new node
        newNode->next = head;          // Link the new node to the current head
        head = newNode;                // Update head to be the new node
        length++;                      // Increment the length of the list
    }

    // Method to add a node with a specific value at the tail of the list
    void addAtTail(int val)
    {
        Node *newNode = new Node(val); // Create a new node
        // If the list is empty, set head to the new node
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            // Otherwise, traverse to the end of the list
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            // Link the last node to the new node
            curr->next = newNode;
        }
        length++; // Increment the length of the list
    }

    // Method to add a node with a specific value at a given index
    void addAtIndex(int index, int val)
    {
        // If the index is out of bounds, do nothing
        if (index < 0 || index > length)
            return;

        // If the index is 0, add the node at the head
        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        // Create a new node
        Node *newNode = new Node(val);
        Node *curr = head;

        // Traverse to the node just before the specified index
        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        }

        // Link the new node in the correct position
        newNode->next = curr->next;
        curr->next = newNode;
        length++; // Increment the length of the list
    }

    // Method to delete a node at a specific index
    void deleteAtIndex(int index)
    {
        // If the index is out of bounds, do nothing
        if (index < 0 || index >= length)
            return;

        Node *curr = head;

        // If the index is 0, update head and delete the first node
        if (index == 0)
        {
            deleteAtHead();
            return;
        }

        // Otherwise, traverse to the node just before the specified index
        Node *prev = NULL;
        for (int i = 0; i < index; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        // Link the previous node to the next node, and delete the current node
        prev->next = curr->next;
        delete curr;

        length--; // Decrement the length of the list
    }

    // Method to delete the node at the head of the list
    void deleteAtHead()
    {
        // If the list is empty, do nothing
        if (length == 0)
            return;

        Node *temp = head; // Store the current head in a temporary variable
        head = head->next; // Update head to the next node
        delete temp;       // Delete the old head node
        length--;          // Decrement the length of the list
    }

    // Method to print the elements of the linked list
    void printList()
    {
        Node *curr = head; // Start from the head
        // Traverse the list and print each node's data
        while (curr != NULL)
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl; // Indicate the end of the list
    }
};

// Main function to demonstrate the functionality of MyLinkedList
int main()
{
    MyLinkedList linkedList;     // Create a new linked list
    linkedList.addAtHead(1);     // Add 1 at the head
    linkedList.addAtTail(3);     // Add 3 at the tail
    linkedList.addAtIndex(1, 2); // Add 2 at index 1 (list becomes 1->2->3)
    linkedList.printList();      // Print the list (1 -> 2 -> 3 -> NULL)

    cout << linkedList.get(1) << endl; // Print value at index 1 (2)

    linkedList.deleteAtIndex(1); // Delete node at index 1 (list becomes 1->3)
    linkedList.printList();      // Print the list (1 -> 3 -> NULL)

    cout << linkedList.get(1) << endl; // Print value at index 1 (3)

    linkedList.deleteAtHead(); // Delete the head node (list becomes 3)
    linkedList.printList();    // Print the list (3 -> NULL)

    return 0; // Exit the program
}
