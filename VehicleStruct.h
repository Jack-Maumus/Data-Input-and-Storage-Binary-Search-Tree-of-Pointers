/**
 *Provides a vehicle structure and useful vehicle functions
 *
 *
 *@author Jack Maumus
 *@since 4-19-22
 */

//type of vehicle
enum VehicleType {CAR, TRUCK, BOAT};

//Used for union; a boat's unique attributes
typedef struct boat {
	char *boatMotorType;
} Boat_s;

//Used for union; a car's unique attributes
typedef struct car {
	int vehicleNumDoors;
	char *carRearConfig;
} Car_s;

//Used for union; a truck's unique attributes
typedef struct truck {
	int vehicleNumDoors;
	float truckTowLimit;
} Truck_s;


//the vehicle structure containing information for year, VIN number, type, make, model
//and the unique attributes for the vehicle type through a union 
typedef struct vehicle_s {
	char vehicleVIN[17];
	int vehicleYear;
	int vehicleType;
	char *vehicleMake;
	char *vehicleModel;
	union VehicleTypeStruct {
		Boat_s boat;
		Car_s car;
		Truck_s truck;
	} type;
} vehicle;

//Takes information from an input file and stores it into the Vehicle variable
vehicle* InputVehicle(FILE* inFile, int type);

//Determines whether the vehicle is of enum BOAT, CAR, or TRUCK
int FindVehicleType (FILE* inFile);

//deallocates all the allocated attributes in a vehicle object
void FreeVehicle(vehicle *veh);
