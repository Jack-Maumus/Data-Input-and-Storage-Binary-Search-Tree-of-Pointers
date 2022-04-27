/**
 * Utility functions intended to clean up code for vehiclesInput.c
 * Functions also provide basic utility in other projects
 *
 * @author Jack Maumus
 * @since 4-13-22
 *
 */

#define MAXSTRINGINPUT 50
#define VINSIZE 17

//Removes the trailing white space of the string parameter
int RemoveEndingWhiteSpace(char TheString[]);

//Takes the next line of input of a file and returns it as an integer
int InputInteger(FILE* inFile);

//Takes the next line of input of a file and returns it as a float
float InputFloat(FILE* inFile);

//Takes the next line of input, removes the trailing white space, and stores it in InputString;
//Returns the length of the string from the file input
int InputString (FILE* inFile, char InputString[]);

//Swaps string at element1 and string at element2 in the string array strArray
void SwapElements(int element1, int element2, char** strArray);

//Sorts charArray using BubbleSort
void BubbleSort(char** charArray, int size);
