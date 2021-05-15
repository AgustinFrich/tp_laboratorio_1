/*
 * Menu.h
 *
 *  Created on: 2 may. 2021
 *      Author: Agus
 */

#ifndef MENU_H_
#define MENU_H_

#include "ArrayEmployees.h"

/** brief Allows to switch by console between the diferent options into a main menu
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return void
 *
 */
void SwitchMenuPrincipal(Employee* list, int len);

/** brief Allows to switch by console between the different options into a lists menu
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return void
 *
 */
void SwitchMenuListados(Employee* list, int len);

/** brief Allows to switch by console between the different options of the Sort Employees function
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 * \return void
 *
 */
void SwitchSortEmployees(Employee* list, int len);

#endif /* MENU_H_ */
