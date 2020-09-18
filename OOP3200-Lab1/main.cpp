/* Program Name: OOP 3200 - Lab 1 - WorkTicket
 * Authors: Ryan Clayson and Daniel Hinbest
 * Date: September 20, 2020
 * Description: A project to create and display a work ticket using the WorkTicket class
 */

#include <string>
#include <iostream>
#include<stdexcept>
#include<sstream>
#include<iomanip>
//TODO: Fix all accessor and mutator names
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

	//start of public
public:
	//Default constructor. If paramaters aren't declared, the ticket takes in these default parameters
	WorkTicket() : ticketNumber(0), clientID(""), ticketDay(1), ticketMonth(1),
				   ticketYear(2000), issueDescription("") {};
	
	WorkTicket(int number, std::string id, int day, int month, int year, std::string description);
	
	//Mutator Method. Sets attributes of the object to the parameters if valid. 
	bool SetWorkTicket(int ticketNumber, std::string id, int day, int month, int year, std::string description); 
	
	//Accessor
	void ShowWorkTicket();
	
	//Sets and Gets for all the attributes
	
	//ticketNumber
	void SetticketNumber(int number);
	int GetticketNumber() { return ticketNumber; }

	//clientID
	void SetclientID(std::string id);
	std::string GetclientID() { return clientID; }

	//ticketDay
	void SetticketDay(int day);
	int GetticketDay() { return ticketDay; }

	//ticketMonth
	void SetticketMonth(int month);
	int GetticketMonth() { return ticketMonth; }

	//ticketYear
	void SetticketYear(int year);
	int GetticketYear() { return ticketYear; }

	//issueDescription
	void SetissueDescription(std::string description);
	std::string GetissueDescription() { return issueDescription; }

	// end of class
};

//Constructor Definition
WorkTicket::WorkTicket(int number, std::string id, int day, int month, int year, std::string description)
{
	SetticketNumber(number);
	SetclientID(id);
	SetticketDay(day);
	SetticketMonth(month);
	SetticketYear(year);
	SetissueDescription(description);
}
WorkTicket::WorkTicket(int number, std::string id, int day, int month, int year, std::string description)
{
	const int MAX_DAY = 31;
	const int MAX_MONTH = 12;
	const int MAX_YEAR = 2099;
	const int MIN_YEAR = 2000;
	bool valid = true;

	if (ticketNumber < 0 || day <1 || day > MAX_DAY || month <1 || month > MAX_MONTH || year < MIN_YEAR || year > MAX_YEAR)
		valid = false;
	else if (clientID.length() < 1 || description.length() < 1)
		valid = false;
	else
	{
		ticketNumber = number;
		clientID = id;
		ticketDay = day;
		ticketMonth = month;
		ticketYear = year;
		issueDescription = description;
	}
	//return valid;
}


//Class definiton section
//SetWorkTicket - Sets all the attributes in the class
bool WorkTicket::SetWorkTicket(int ticketNumber, std::string id, int day, int month, int year, std::string description)
{
	bool returnValue;
	ticketNumber++;
	clientID = ticketYear + ticketMonth + ticketYear + ticketNumber;
	std::getline(std::cin, issueDescription);

	if (issueDescription.length() < 1)
		returnValue = false;
	else
		returnValue = true;
	return returnValue;
}

//ShowWorkTicket - Outputs ticket information to the screen
void WorkTicket::ShowWorkTicket() //Display all attributes
{
	std::cout << "Ticket Number: " << GetticketNumber << std::endl
		<< "Client ID: " << GetclientID << std::endl
		<< "Ticket Date: " << GetticketDay << GetticketMonth << GetticketYear << std::endl
		<< "Issue Description: " << "\n\t" << GetissueDescription << std::endl;
	
}

int main()
{
	//Constant variable declaration
	const int NUMBER_OF_TICKETS = 3;
	//WorkTicket class declaration
	WorkTicket ticket[NUMBER_OF_TICKETS];

	//Input loop
	for (int i = 0; i <= NUMBER_OF_TICKETS; i++)
	{
		std::cout << "Enter the description of your issue ";
		ticket[i].SetWorkTicket(i + 1);
	}

	//Output loop
	for (int i = 0; i <= NUMBER_OF_TICKETS; i++)
		ticket[1].ShowWorkTicket();
}
