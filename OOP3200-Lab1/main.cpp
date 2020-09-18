/* Program Name: OOP 3200 - Lab 1 - WorkTicket
 * Authors: Ryan Clayson and Daniel Hinbest
 * Date: September 20, 2020
 * Description: A project to create and display a work ticket using the WorkTicket class
 */

#include <string>
#include <iostream>

// class declaration 
class WorkTicket
{
	//private data members
private:
	int ticketNumber;
	std::string clientID;
	int ticketDay;
	int ticketMonth;
	int ticketYear;
	std::string issueDescription; //Could be public as well

	//Declaration for Constructor
public:
	WorkTicket();
	WorkTicket(int number, int day, int month, int year);
	bool SetWorkTicket(int id); //I think
	void ShowWorkTicket();
	
};

//Constructors - default
WorkTicket::WorkTicket()
{
	ticketNumber = 0;
	int ticketDay = 1;
	int ticketMonth = 1;
	int ticketYear = 2000;
	//std:string clientID = ""
}

//Constructors - parameterized
WorkTicket::WorkTicket(int number, int day, int month, int year)
{
	ticketNumber = number;
	ticketDay = day;
	ticketMonth = month;
	ticketYear = year;
}

//Class definiton section
/* A mutator method to set all the attributes of the object to the parameters as
long as the parameters are valid. ALL of the parameters must be valid in order for ANY of the
attributes to change. Validation rules are explained above for work ticket number and date. Client
number and Description must be at least one character long. If no problems are detected, return
TRUE. Otherwise return FALSE.
*/
bool WorkTicket::SetWorkTicket(int ticket)
{
	ticketNumber++;
	clientID = ticketYear + ticketMonth + ticketYear + ticketNumber;
	std::getline(std::cin, issueDescription);

	return true;
}

void WorkTicket::ShowWorkTicket() //Display all attributes
{
	
}

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
