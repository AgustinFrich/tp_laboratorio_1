#include "LinkedList.h"
#include "Employee.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

int controller_addEmployee(LinkedList* pArrayListEmployee);

int controller_editEmployee(LinkedList* pArrayListEmployee);

int controller_removeEmployee(LinkedList* pArrayListEmployee);

int controller_ListEmployee(LinkedList* pArrayListEmployee);

int controller_sortEmployee(LinkedList* pArrayListEmployee);

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

Employee* controller_searchByID(LinkedList* pArrayListEmployee, int id);

int controller_saveMaxIDWhileLoad(char*path, LinkedList* pArrayListEmployee);

int controller_saveMaxIDWhileAdding(char*path, Employee* empleado);

int controller_readMaxID(char * path, int * id);
