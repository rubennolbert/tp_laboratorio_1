#ifndef CONTROLLER_H_
#define CONTROLLER_H_


int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, int* flagA, int* flagB);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger, int* flagA, int* flagB);
int controller_addPassenger(LinkedList* pArrayListPassenger, int* flagA, int* flagB);
int controller_editPassenger(LinkedList* pArrayListPassenger, int* flagA, int* flagB);
int controller_removePassenger(LinkedList* pArrayListPassenger, int* flagA, int* flagB);
int controller_ListPassenger(LinkedList* pArrayListPassenger, int* flagA, int* flagB);
int controller_sortPassenger(LinkedList* pArrayListPassenger, int* flagA, int* flagB);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger, int* flagA, int* flagB, int* flagC);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger, int* flagA, int* flagB, int* flagC);


#endif /* CONTROLLER_H_*/
