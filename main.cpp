/******************************************************************************
9.7 Binary Search String

This program sorts an array of strings and searches it for a user-inputted 
value using binary search
*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

void selectionSort(string [], int);
void displayData(string [], int);
int binarySearch(string [], int, string);

int main(){
   const int SIZE = 28;
   string searchValue;
   int foundAt;
   char searchAgain;
   
   string name[SIZE] = 
   {"Collins, Bill",  "Smith, Bart",  "Michalski, Joe", "Griffin, Jim",
    "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill", 
    "Allison, Jeff",  "Moreno, Juan", "Wolfe, Bill",    "Whitman, Jean",
    "Moretti, Bella", "Wu, Eric",     "Patel, Renee",   "Harrison, Rose",
    "Smith, Cathy",   "Conroy, Pat",  "Kelly, Sean",    "Holland, Beth",
    "Reignard, Archaimbaud", "Dymott, Kalliste", "Salazar, Jaquelin", "Allaker, Gratiana", 
    "Gilsthorpe, Hortense", "Croser, Ozzy", "Kuzemka, Maureene", "Monks, Anderson"};
	
   // Sorts the array alphabetically (A-Z)
   selectionSort(name, SIZE);

   // Displays the sorted array
   cout << "\nAlphabetically ordered array of names: \n";
   displayData(name, SIZE);

   // Loops to allow user to repeatedly search for names
   do{
      cout << "\nPlease enter a name (i.e. 'Last, First') to search for: ";
      getline(cin, searchValue);

      foundAt = binarySearch(name, SIZE, searchValue);

      // Displays the search result
      if (foundAt == -1){
         cout << endl << searchValue << " was not found\n";
      } else {
         cout << endl << searchValue << " was found at position " << foundAt << ". \n";
      }

      cout << "\nSearch for another name (y/n)? ";
      cin  >> searchAgain;

      // Clears out the input
      cin.ignore();
   } while (tolower(searchAgain) == 'y');
   
   return 0;
}

// binarySearch ---------------------------------------------------------------                          
// This function performs a binary search on a string array      
// with size elements whose values are stored in alphabetical    
// order. The array is searched for the string stored in the     
// value parameter. If the number is found, its array subscript  
// is returned. Otherwise, -1 is returned.                       

int binarySearch(string array[], int size, string value){
	int   first = 0,            // First array element
		   last = size - 1,      // Last array element
		   middle,               // Midpoint of search
		   position = -1;        // Position of search value
	bool found = false;         // Flag to indicate if the value was found 

	while (!found && first <= last){
		middle = (first + last) / 2;      // Calculate midpoint

		if ((array[middle]) == value)     // If value is found there
		{
			found = true;
			position = middle;
		}
		else if ((array[middle]) > value) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;            // If value is in upper half
	}
	return position;
}

// selectionSort --------------------------------------------------------------                              
// This function sorts a string array in alphabetical order.
void selectionSort(string array[], int SIZE){
   int minIndex;
   string minValue;

   for (int start = 0; start < (SIZE - 1); start++)
   {
      minIndex = start;
      minValue = array[start];
      for (int index = start + 1; index < SIZE; index++)
      {
         if (array[index] < minValue)
         {
            minValue = array[index];
            minIndex = index;
         }
      }
      swap(array[minIndex], array[start]);
   }
}

// swap -----------------------------------------------------------------------
// This function swaps the contents of string variables a and b in memory.
void swap(string &a, string &b)
{
   string temp = a;
   a = b;
   b = temp;
}

// displayData ----------------------------------------------------------------                    
// This function displays the values in the array
void displayData(string array[], int size){
   for (int i =0; i<size; i++){
      cout << i<<": " << array[i] << " \n";
   }
}