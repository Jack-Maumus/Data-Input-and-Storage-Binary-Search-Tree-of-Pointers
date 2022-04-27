/**
 *Provides vehicle struct and functions; use found in VehicleStruct.h
 *
 *@author Jack Maumus
 *@since 4-19-22
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Utilities.h"
#include "VehicleStruct.h"

vehicle* InputVehicle(FILE* inFile, int type) {
	vehicle *temp = (vehicle*) malloc(sizeof(vehicle));
	char *stringTemp = (char*) malloc(sizeof(char*) * 51);
	int len = 0;

	//vehicle's make
	InputString(inFile, stringTemp);
	len = strlen(stringTemp) + 1;
	temp->vehicleMake = (char*) malloc(sizeof(char*) * len);
	strcpy(temp->vehicleMake, stringTemp);

	//vehicle's model
	InputString(inFile, stringTemp);
	len = strlen(stringTemp) + 1;
	temp->vehicleModel = (char*) malloc(sizeof(char*) * len);
	strcpy(temp->vehicleModel, stringTemp);

	//vehicle's year
	temp->vehicleYear = InputInteger(inFile);

	//vehicle's VIN
	InputString(inFile, temp->vehicleVIN);

	switch (type) {
		case CAR :
			//car's number of doors
			temp->type.car.vehicleNumDoors = InputInteger(inFile);
			//car's rear configuration
			InputString(inFile, stringTemp);
			len = strlen(stringTemp) + 1;
			temp->type.car.carRearConfig = (char*) malloc(sizeof(char*) * len);
			strcpy(temp->type.car.carRearConfig, stringTemp);

			temp->vehicleType = CAR;
			break;
		case TRUCK : 
			//truck's number of years
			temp->type.truck.vehicleNumDoors = InputInteger(inFile);
			//truck's tow limit
			temp->type.truck.truckTowLimit = InputFloat(inFile);

			temp->vehicleType = TRUCK;
			break;
		case BOAT :
			//boat's motor type
			InputString(inFile, stringTemp);
			len = strlen(stringTemp) + 1;
			temp->type.boat.boatMotorType = (char*) malloc(sizeof(char*) * len);
			strcpy(temp->type.boat.boatMotorType, stringTemp);

			temp->vehicleType = BOAT;
			break;
	}

	return temp;
}

/*void OutputInfo(FILE* outFile, vehicle *Vehicle[], int pos) {
	vehicle *temp = NULL;

	for (int i = 0; i < pos; i++) {
		temp = Vehicle[i];
		fprintf(outFile, "%d %S %S\nVIN: %s\n", temp->vehicleYear, temp->vehicleMake, temp->vehicleModel, temp->vehicleVIN);

		if (temp->vehicleType == BOAT) {
			fprintf(outFile, "Motor: %s\n\n", temp->type.boat.boatMotorType);
		} else if (temp->vehicleType == CAR) {
			fprintf(outFile, "Doors: %d\nRear Configuration: %s\n\n", temp->type.car.vehicleNumDoors, temp->type.car.carRearConfig);
		} else {
			fprintf(outFile, "Doors: %d\nMax Towing Capacity: %.1f\n\n", temp->type.truck.vehicleNumDoors, temp->type.truck.truckTowLimit);
		}
	}
	return;
}*/

int FindVehicleType (FILE* inFile) {
	char buf[MAXSTRINGINPUT];
	int vehicle = 0;
	InputString(inFile, buf);
	if (! strcmp(buf, "truck")) {
		vehicle = TRUCK;
	} else if (! strcmp(buf, "boat")) {
		vehicle = BOAT;
	} else {
		vehicle = CAR;
	}
	return vehicle;
}

/*void VehicleBubbleSort(vehicle *Vehicle[], int pos) {
	for (int i = 0; i < pos - 1; i ++) {
		for (int j = 0; j < pos - i - 1; j++) {
			if (VehicleCmp(Vehicle[j], Vehicle[j+1])) {
				SwapVehicles(j, j+1, Vehicle);
			}
		}
	}
	return;
}*/

void FreeVehicle(vehicle *veh) {
	free(veh->vehicleMake);
	free(veh->vehicleModel);
	if (veh->vehicleType == BOAT) free(veh->type.boat.boatMotorType);
	if (veh->vehicleType == CAR) free(veh->type.car.carRearConfig);
	return;
}



