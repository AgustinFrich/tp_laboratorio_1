/*
 * Employees.h
 *
 *  Created on: 2 may. 2021
 *      Author: Agus
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} Employee;


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
 *
 */
int InitEmployees(Employee* list, int len);

/** brief To find the first free space in the array that is Empty.
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - index of the first free space if Ok.
 *
 */
int FindFreeSpace(Employee* list, int len);

/** brief To enter a new employee and its data to an array of employees.
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return int Return (-2) if Error [Invalid length or NULL pointer] -
 * (-1) if the array of employees is full - (0) if Ok.
 *
 */
int InputNewEmployee(Employee* list, int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 *
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int AddEmployee(Employee* list, int len, int id, char name[], char lastName[],
				float salary, int sector, int index);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int Employee ID
 *
 * \return Return employee index position or
 * (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int FindEmployeeById(Employee* list, int len, int id);

/** brief To remove an employee entering its id to an array of employees.
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return int Return (-3) if Error [Invalid length or NULL pointer] -
 * (-2) if the array of employees is full - (-1) if the id could not be found - (0) if Ok.
 *
 */
int RemoveEmployee(Employee* list, int len);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int Employee ID
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int RemoveEmployeeByID(Employee* list, int len, int id);

/** \brief To modify the name, last name, salary or sector of one employee into an array of employees.
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return int Return (-3) if Error [Invalid length or NULL pointer] -
 * (-2) if the array of employees is empty - (-1) if the user cancels the modification - (0) if Ok
 *
 */
int ModifyEmployee(Employee* list, int len);

/** \brief print the content of employees array
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer or employees not found] - (0) if Ok
 *
 */
int PrintEmployees(Employee* list, int length);

/** \brief print the data of one Employee
 *
 * \param employee Employee* Pointer to an employee
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer or employee not found] - (0) if Ok
 *
 */
int PrintOneEmployee(Employee* employee);

/** \brief Sort the elements in the array of employees, the argument order
 * indicate UP or DOWN order
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int SortEmployees(Employee* list, int len, int order);

/** \brief Sort the elements in the array of employees by its sector, the argument order
 * indicate UP or DOWN order
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 *
 * \return void
 *
 */
void SortBySector(Employee* list, int len, int order);

/** \brief Sort the elements in the array of employees by its last name, the argument order
 * indicate UP or DOWN order
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 *
 * \return void
 *
 */
void SortByLastName(Employee* list, int len, int order);

/** \brief Sort the elements in the array of employees by its ID
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return void
 *
 */
void SortByID(Employee* list, int len);

/** \brief Calculates the total amount of money of the salaries and the average salary
 * of the employees in an employee array
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param total float* Pointer for the total money of the salaries
 * \param average float* Pointer for the average value for salary
 *
 * \return int Return (-0) if Error [NULL pointer] - (1) if Ok
 *
 */
int CalculateTotalAndAverage(Employee* list, int len, float* total, float* average);

/** \brief Shows by console the total of the salaries, the average salary and the employees that
 * have a salary higher than the average.
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer] -
 * (0) if the array of employees is empty - (1) if Ok
 *
 */
int ShowTotalAndAverage(Employee* list, int len);

#endif /* ARRAYEMPLOYEES_H_ */
