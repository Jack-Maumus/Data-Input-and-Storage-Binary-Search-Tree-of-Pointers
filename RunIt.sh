#!/bin/csh
gcc -Wall -o Prog7 vehicleInput.c Utilities.c BST.c VehicleStruct.c
Prog7 < TestInput.txt
