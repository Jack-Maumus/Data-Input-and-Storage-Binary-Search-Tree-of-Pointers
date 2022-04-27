/**
 * This method read a set of vehicle values from a text file and
 *  prints them to an outfile in readable form.
 *
 *  routine: vehicleInput
 *
 *  return type: 
 *
 *  parameters:
 *
 *  @author Jack Maumus
 *  @since 3/27/22
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Utilities.h" 
#include "VehicleStruct.h"
#include "BST.h"

int main(void) {
	
	struct Treenode* tree = NULL;
	vehicle *Vehicle;
	int vehicleType;
	int count = 0;

	printf("Opening TestInput.txt...\n");
	FILE* inFile = 	fopen("./TestInput.txt", "r");
	printf("Opening out.txt...\n");
	FILE* outFile = fopen("out.txt", "w");
	printf("Reorganizing TestInput.txt to out.txt in a more readable form...\n");
	
	//inserting root of the tree
	vehicleType = FindVehicleType(inFile);
	Vehicle = (vehicle*) malloc(sizeof(vehicle*));
	Vehicle = InputVehicle(inFile, vehicleType);
	tree = NewNode(Vehicle);
	count++;

	vehicleType = FindVehicleType(inFile);
	while (!feof(inFile)) {
		//inserting additional nodes to BST
		Vehicle = InputVehicle(inFile, vehicleType);
		InsertNode(tree, Vehicle);
		vehicleType = FindVehicleType(inFile);
		count++;
		if (count == 500) break;
	}
	
	//Prints vehicle's in ascending year order
	InorderTraversal(outFile, tree);
		
	printf("Input file read and reorganized in out.txt\n");
	printf("Closing input and output files and deallocating memory...\n");
	
	//frees allocated memory associated with the BST
	FreeNode(tree);

	fclose(inFile);
	fclose(outFile);

	return 0;
}
