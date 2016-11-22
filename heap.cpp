/*
Author: Brandon Woodard
ID: 3082
Date: 11/5/2016
Title: Heap.cpp
Abstract: C++ program called heap.cpp to determine if a sequence of numbers is a heap or not
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// function which checks if a heap is maxHeap or not
bool isMaxHeap(int heap[], int size)
{
	// loop over the heap
	for (int i = size - 1; i > 0; i--)
	{
		int parent = (i - 1) / 2;

		// check if the current node "i" has a greater value that it's "parent"
		if (heap[parent] < heap[i])
			return false; // if so, false
	}
	return true; // otherwise true
}

// move "current" up on the heap at it's proper heap location
void siftUp(int heap[], int size, int current)
{
	int i = current;

	// loop over the entire heap
	while (i > 0)
	{
		// get the parent value
		int parent = (i - 1) / 2;

		// if parent value is smaller
		if (heap[parent] < heap[i])
		{
			// swap the current value and parent value
			int temp = heap[parent];
			heap[parent] = heap[i];
			heap[i] = temp;
		}

		// loop again at the parent index
		i = parent; 
	}
}

// move "current" down on the heap at it's proper heap location
void siftDown(int heap[], int size, int current)
{
	int i = current;

	// begin at current downwrds till end
	while (i < size)
	{
		// get the lchild and rchild
		int lchild = (2 * i) + 1;
		int rchild = lchild + 1;

		if (lchild >= size && rchild >= size) // if both lchild and rchild are out of bounds
		{
			// siftDown ends
			return; 
		}
		else if (rchild >= size) // only rchild is out of bounds
		{
			if (heap[lchild] > heap[i]) // if lchild value is greater
			{
				// swap lchild and current "i" values
				int temp = heap[lchild];
				heap[lchild] = heap[i];
				heap[i] = temp;
			}
			return; // end of siftDown, no more values left
		}
		else // both lchild and rchild are within bounds
		{
			if (heap[lchild] <= heap[i] && heap[rchild] <= heap[i]) // if values are in place
			{
				return; // end
			}
			else if (heap[lchild] > heap[rchild]) // if lchild is bigger value
			{
				// swap lchild and i
				int temp = heap[lchild];
				heap[lchild] = heap[i];
				heap[i] = temp;

				i = lchild;
			}
			else // rchild is the bigger value
			{
				// swap rchild and i
				int temp = heap[rchild];
				heap[rchild] = heap[i];
				heap[i] = temp;

				i = rchild;
			}
		}
	}
}

void printHeap(int heap[], int size)
{
	// loop over the full "size" of the heap
	for (int i = 0; i < size; i++)
		cout << heap[i] << " ";
	cout << endl;
}

int main()
{
	const int MAXSIZE = 500;
	int heap[MAXSIZE];
	int choice;
	int temp;
	int size;
	string input;

	// ask for user
	cout << "Enter numbers: ";
	getline(cin, input); // read in all input 

	// parse the input
	stringstream ss(input);
	size = 0;
	while (ss.good())
	{
		ss >> heap[size]; // parse the numbers one by one, and store them on array
		size++; // increment size as we go along
	}


	// check if this is a max heap
	if (isMaxHeap(heap, size))
	{
		cout << "This is a heap." << endl;
	}
	else
	{
		cout << "This is NOT a heap." << endl;

		// if not a max heap, perfroms siftUp over all indexes ensuring maxHeap
		for (int i = size - 1; i > 0; i--)
		{
			siftUp(heap, size, i);
		}

		// print the constructred maxHeap
		cout << "Heap constructed: ";
		printHeap(heap, size);
	}

	// Menu
	do
	{
		cout << "1. Insert a number" << endl;
		cout << "2. Delete the max" << endl;
		cout << "3. Quit" << endl;
		cin >> choice;

		if (choice == 1)
		{
			// ask for user input
			cout << "Enter a number: ";
			cin >> temp;

			// store the number at end of array
			heap[size] = temp;

			// increment size
			size++;

			// siftUp this newly added value to it's proper location on array
			siftUp(heap, size, size - 1);

			// print the updated heap
			cout << "Updated heap: ";
			printHeap(heap, size);
		}
		else if (choice == 2)
		{
			// value at last index is placed at index 0
			heap[0] = heap[size - 1];

			// decrement size
			size--;

			// siftDown the value now added at index 0
			siftDown(heap, size, 0);

			// print the updated heap
			cout << "Updated heap: ";
			printHeap(heap, size);
		}
		else if (choice == 3)
		{
			//  exit program choice
			cout << "Bye" << endl;
		}
		else
		{
			// invalid choice
			cout << "Wrong choice" << endl;
		}	

	} while (choice != 3); // keep repeating until user choses choice 3 to stop

	return 0;
}
