/* Program Name: OOP 3200 - Lab 1 - WorkTicket
 * Authors: Ryan Clayson and Daniel Hinbest
 * Date: September 20, 2020
 * Description: A project to create and display a work ticket using the WorkTicket class
 */

#include "WorkTicket.cpp"

int main()
{
	//Constant variable declaration
	const int NUMBER_OF_TICKETS = 3;

	//WorkTicket class declaration
    WorkTicket ticket[NUMBER_OF_TICKETS];

	//Input loop
	for (int i = 0; i <= NUMBER_OF_TICKETS; i++)
		ticket[1].SetWorkTicket(i + 1);

	//Output loop
	for (int i = 0; i <= NUMBER_OF_TICKETS; i++)
		ticket[1].ShowWorkTicket();
}
