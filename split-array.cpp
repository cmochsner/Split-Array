//Program by Christina Ochsner

#include <iostream>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

//for testing
void print(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void split(int *arr, int size)
{
	//split array if it's size is greater than 1
	if (size > 1)
	{
		//intialize sizes of left array and right array
		int midL = size / 2;
		int midR = size / 2;

		//if size is odd, put extra element into the right array
		if (size % 2 == 1)
		{
			midR++;
		}

		//create left and right arrays
		int *left = new int[midL];
		int *right = new int[midR];

		//copy over elements
		for (int i=0; i < midL; i++)
		{
			left[i] = arr[i];
		}

		for (int j = 0; j < midR; j++)
		{
			right[j] = arr[j+midL];
		}

		//split right and left arrays
		split(left, midL);
		split(right, midR);

		delete[] left;
		delete[] right;
	}
	
	//output bye bye if split recursion is complete or not needed
	cout << "bye bye" << endl;
}

int main()
{
	int n=0;
	cout << "Welcome to the Split Recursion program! Enter -1 to exit." << endl;

	while (n != -1)
	{
		cout << "Enter the size of the array you'd like to split: ";
		cin >> n;
		cout << endl;

		//catch input if it does not equal a proper array size
		if (n < 0)
		{
			//if the array size is invalid
			while (n < -1)
			{
				cout << "Invalid size entered. Try again: ";
				cin >> n;
				cout << endl;
			}
			//if the user has entered the input to exit
			if (n == -1)
			{
				cout << "Exiting..." << endl;
				return 0;
			}
		}

		//create array based on user's inputted size
		int *arr = new int[n];

		//initialize the array with random elements
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % 100;
		}

		//start timer
		high_resolution_clock::time_point start = high_resolution_clock::now();

		//start splitting
		split(arr, n);

		//stop timer
		high_resolution_clock::time_point stop = high_resolution_clock::now();
		//calculate total runtime
		duration<double> timer = duration_cast<duration<double>>(stop - start);

		//output the total time to split array
		cout << "\nThe runtime to split this array was " << timer.count() << " seconds.\n" << endl;
		
		//delete the arr
		delete [] arr;
	}
	
	//system("pause");
	return 0;
}
