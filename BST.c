/**
 *
 *
 *@author Jack Maumus
 *@since 4-19-22
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "VehicleStruct.h"
#include "BST.h"

struct Treenode {
	vehicle *veh;
	struct Treenode* left;
	struct Treenode* right;
};

struct Treenode* NewNode(vehicle *Vehicle) {
	struct Treenode *temp;
	temp = (struct Treenode*) malloc(sizeof(struct Treenode*));
	temp->veh = Vehicle;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct Treenode* InsertNode(struct Treenode* root, vehicle *Vehicle) {

	if (root==NULL) {
		return NewNode(Vehicle);
	} else {
		int rootYear = root->veh->vehicleYear;
		int newYear = Vehicle->vehicleYear;
		if (newYear > rootYear) {
			root->right = InsertNode(root->right, Vehicle);
		} else {
			root->left = InsertNode(root->left, Vehicle);
		}
	}
	return root;
}

void InorderTraversal(FILE* outFile, struct Treenode* root) {
	if (root!=NULL) {
		InorderTraversal(outFile, root->left);
		OutputInfo(outFile, root->veh);
		InorderTraversal(outFile, root->right);
	}
	return;
}

void FreeNode(struct Treenode* root) {
	if (root!=NULL) {
		FreeNode(root->left);
		FreeNode(root->right);
		FreeVehicle(root->veh);
		free(root);
	}
	return;
}

void OutputInfo(FILE* outFile, vehicle *veh) {
	fprintf(outFile, "%d %s %s\nVIN: %s\n", veh->vehicleYear, veh->vehicleMake, veh->vehicleModel, veh->vehicleVIN);

	if (veh->vehicleType == BOAT) {
		fprintf(outFile, "Motor: %s\n\n", veh->type.boat.boatMotorType);
	} else if (veh->vehicleType == CAR) {
		fprintf(outFile, "Doors: %d\nRear Configuration: %s\n\n", veh->type.car.vehicleNumDoors, veh->type.car.carRearConfig);
	} else {
		fprintf(outFile, "Doors: %d\nMax Towing Limit: %.1f\n\n", veh->type.truck.vehicleNumDoors, veh->type.truck.truckTowLimit);
	}
	return;
}


