//============================================================
// Assignment- 05
// Name- Raisa Zaman
// Date- 2/13/2020
// Last edited- 4:30 PM
// Title: Assignment 05: Implementing a queue using circular array
// Description:
//    This C++ console application loads a columne of letters and does the proper function that goes 
// with that letter and prints out the results of each functions. 
//
//==========================================================

#include <iostream>
#include <fstream>
#include <iomanip>  

using namespace std;
int SIZE = 10; 
class CircularArrayQueue

{

private:

	int num1;
	int num2;
	int arr[10];

public:
	CircularArrayQueue();// Initilize the variable member functions
	void enqueue(int rear); // put elements into the queue.
	int dequeue(); // print the value returned by the call(or a message)
	void displayQueue(); // print valid values in queue.
	int front(); // print out the element at the front of the queue.
	bool isEmpty(); // print out “Queue is Empty” message(or a message)
	bool isFull(); // Print out “Queue is Full” message(or a message)
	int countQ(); // print out “Number of elements in queue is: nn”

};

CircularArrayQueue :: CircularArrayQueue()
{
	num1 = -1;
	num2 = -1;
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = -1; 
	}
}

void CircularArrayQueue::enqueue(int rear)
{
	if (isFull())// if the full function returns true the array is full. 
	{
		cout << "Queue is Full"; // Print out array is full to let the user know nothing can be added. 
	}
	else// other cases
	{
		if (num1 == -1)// other case is the array is empty 
		{
			num1 = num2 = 0;// the front and the back are now move to the zero position in the array.
			arr[num2] = rear;// the back gets the element and places it in the front array 
		}
		else if (num2 == SIZE - 1 && num1 != 0)// If the array had some space left in the front of it and the back has reached the end
		{
			num2 = 0;// make the back be equal to the front of the array 
			arr[num2] = rear; // now we can start filling up the front spaces that were deleted using deque
		}
		else
		{
			num2++; // if the array is not full in the back 
			arr[num2] = rear; // we keep adding elements in the back 
		}
	}
}

int  CircularArrayQueue::dequeue()
{
	int front = 0; // Declare a variable to store the new front and returns it at the end.
	if (isEmpty()) // Checks if the array is empty
	{
		cout << "Queue is Empty." << endl << endl;  // Print out a message about how the array is empty for the user to read.
		return NULL;
	}
	else if (num1 == num2) // if the front is equal to the rear end of the array 
	{
		num1 = -1; // make the front of the array -1 
		num2 = -1; // make the rear of the array -1
		return front = arr[num1]; // return the new front of the array 
	}
	else // other case
	{
		if (num1 == SIZE - 1) // if the front is equal to size minus one 
			num1 = 0; // make front equal to zero 
		else // other case
			num1 = num1 + 1; // make front increment by one and thats the new front and old front is deleted
		return front = arr[num1]; // return the new front of the array 
	}
}

void CircularArrayQueue::displayQueue()
{
	int numf = num1;// declare variable and equal to first
	int numl = num2; // declare variable and equal to last
	if (isEmpty()) // Checks if the array is empty
	{
		cout << "Queue is Empty"; // Print out a message about how the array is empty for the user to read. 
	}
	if (numf <= numl) // if the first elements index is smaller than or equal to the last elements index
	{
		while (numf <= numl) // while the first elements index is smaller than or equal to the last elements index
		{
			cout << arr[numf] << "  "; // print the elements until it reaches the last elements index
			numf++; // move the first element index every time you go through the while loop.
		}
	}
	else // other cases
	{
		while (numf <= SIZE - 1) // If the front of the element is smaller than the size minus one
		{
			cout << arr[numf] << "  "; // print the elements until it reaches the end of the array
			numf++; // move the first element index every time you go through the while loop.
		}
		numf = 0; // initilize the front variable you declared to 0th position
		while (numf <= numl) // while the first elements index is smaller than or equal to the last elements index
		{
			cout << arr[numf] << "  "; // print the elements until it reaches the last elements index
			numf++; // move the first element index every time you go through the while loop.
		}
	}
}

int CircularArrayQueue::front()
{
	if (isEmpty()) // Make sure the array is not empty
	{
		cout << "Queue is Empty"; // Print out a message about how the array is empty for the user to read.   
		return NULL; // The function stops
	}
	return arr[num1]; // The array returns the first element in the array 
}

bool CircularArrayQueue::isEmpty()
{
	if (num1 == -1 || num2 == -1) // checks if the front is equal to -1, which is the initial position 
	{
		return true; // return true and exit the function 
	}
	return false; // return false and exit the function 
}


bool CircularArrayQueue::isFull()
{
	if (num1 == 0 && num2 == SIZE - 1 || num1 == num2 + 1) // check if the front is equal to 0 and last is equal to size minus one which is the standard case. 
		// or first is equal to last plus one 
	{
		return true; // return true and exit the function 
    }
	return false; // return false and exit the function 
}

int CircularArrayQueue::countQ()
{
	int numf = num1;// declare variable and equal to first
	int numl = num2; // declare variable and equal to last
	int count = 0; 
	if (isEmpty()) // Checks if the array is empty
	{
		return NULL; // The functions ends 
	}
	if (numf <= numl) // if the first elements index is smaller than or equal to the last elements index
	{
		while (numf <= numl) // while the first elements index is smaller than or equal to the last elements index
		{
			numf++; // move the first element index every time you go through the while loop.
			count++;// counts the number of elements so increases by one after every loop. 
		}
	}
	else // other cases
	{
		while (numf <= SIZE - 1) // If the front of the element is smaller than the size minus one
		{
			numf++; // move the first element index every time you go through the while loop.
			count++;// counts the number of elements and increases by one after every loop. 
		}
		numf = 0; // initilize the front variable you declared to 0th position
		while (numf <= numl) // while the first elements index is smaller than or equal to the last elements index
		{
			numf++; // move the first element index every time you go through the while loop.
			count++;// counts the number of elements and increases by one after every loop. 
		}
	}
	return count;// returns the count with the number of elements in the array. 
}



int main()
{

	CircularArrayQueue myque;
	ifstream new_file;
	new_file.open("CircularArrayQueue.data");
	if (!new_file)
	{
		cout << "File CircularArrayQueue.data Can't be opened" << endl <<endl;
	}

	else
	{
		cout << "File CircularArrayQueue.data successfully opened." << endl << endl;
		char letter;
		int number;
		int lineNum = 0; 
		cout << left << setw(20) << "Step" << left << setw(20) << "Action" << endl;
		while (new_file >> letter >> number)
		{
			if (letter == 'e')
			{
				lineNum++;
				if (myque.isFull())
				{
					cout << left << setw(20) << lineNum << left << setw(20) << "enqueue() called. Queue is Full" << endl << endl;
				}
				else
				{
					cout << left << setw(20) << lineNum << left << setw(20) << "enqueue() called with value " << number << ". Status: Inserted value " << number << endl << endl;
					myque.enqueue(number);
				}

			}

			if (letter == 'd')
			{
				lineNum++;
				if (myque.isEmpty())
				{
					cout << left << setw(20) << lineNum << left << setw(20) << "dequeue() called. Queue is Empty" << endl << endl;
				}
				
				else
				{ 
				cout << left << setw(20) << lineNum << left << setw(20) << "dequeue() called. deleting from front of the queue, the new front is: " << myque.dequeue() << endl << endl;
				}
			}

			if (letter == 'p')
			{
				lineNum++;
				if (myque.isEmpty())
				{
					cout << left << setw(20) << lineNum  << left << setw(20) << "displayQueue() called. Queue is Empty" << endl << endl;
				}
				else
				{
					cout << left << setw(20) << lineNum << left << setw(20) << "displayQueue() called. Values in queue = ";
					myque.displayQueue();
					cout << endl << endl;
				}
			}

			if (letter == 'f')
			{
				lineNum++;
				if (myque.isEmpty())
				{
					cout << left << setw(20) << lineNum << left << setw(20) << "front() called. Queue is Empty" << endl << endl;
				}
				else
				{
					cout << left << setw(20) << lineNum << left << setw(20) <<"front() called. Front of the queue is: "<<myque.front() << endl << endl;
				}
			}

			if (letter == 't')
			{
				bool c = myque.isEmpty();
				lineNum++;
				if (c)
				{
					cout << left << setw(20) << lineNum << left << setw(20) << "isEmpty() called. Queue is Empty" << endl << endl;
				}
				else
				{
					cout << left << setw(20) << lineNum << left << setw(20) << "isEmpty() called. Queue is not Empty" << endl << endl;
				}
			}

			if (letter == 'l')
			{
				bool c = myque.isFull();
				lineNum++;
				if (c)
				{
					cout << left << setw(20) << lineNum << left << setw(20) << "isFull() called. Queue is Full" << endl << endl;
				}
				else
				{
					cout << left << setw(20) << lineNum << left << setw(20) << "isFull() called. Queue is not Full" << endl << endl;
				}
			}

			if (letter == 'c')
			{
				lineNum++;
				if (myque.isEmpty())
				{
					cout << left << setw(20) << lineNum << left << setw(20) << "countQ() called. Queue is Empty" << endl << endl;
				}
				else
				{
					cout << left << setw(20) << lineNum << left << setw(20) <<"countQ() called. Number of elements in queue = " <<myque.countQ() << endl << endl;
				}
			}

			if (letter == 'x')
			{
				lineNum++;
				cout << left << setw(20) << lineNum << left << setw(20) << "Exit the program. " << endl << endl;
				break;
			}

		}

	}

	new_file.close();

	return 0;

}