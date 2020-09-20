/* Program Name: OOP 3200 - Lab 1 - WorkTicket
 * Authors: Ryan Clayson and Daniel Hinbest
 * Date: September 20, 2020
 * Description: A project to create and display a work ticket using the WorkTicket class
 */

#include <iostream>
#include<stdexcept>
#include<sstream>
#include<iomanip>
#include "MyConsoleInput.h"
#include "MyconsoleInput.cpp"

// class declaration 
class WorkTicket
{
//start of private
private:
//private data members
	int ticketNumber;
	std::string clientID;
	int ticketDay;
	int ticketMonth;
	int ticketYear;
	std::string issueDescription; 

//start of public
public:
	//Default constructor. If paramaters aren't declared, the ticket takes in these default parameters
	WorkTicket(int ticketNumber = 0, std::string clientID = "", int ticketDay = 1, int ticketMonth = 1,
				  int ticketYear = 2000, std::string issueDescription = "");
	
	//All Accessors Declarations. "Getters"
	int GetTicketNumber();
	std::string GetClientID();
	int GetTicketDay();
	int GetTicketMonth();
	int GetTicketYear();
	std::string GetIssueDescription();
	void ShowWorkTicket() const;

	//All mutators/ "Setters"
	void SetTicketNumber(int ticketNumber);
	void SetClientID(std::string clientID);
	void SetTicketDay(int ticketDay);
	void SetTicketMonth(int ticketMonth);
	void SetTicketYear(int ticketYear);
	void SetIssueDescription(std::string issueDescription);
	bool SetWorkTicket(int number, std::string id, int day, int month, int year, std::string description);
	
	// end of public	
};// end of class

//Constructor Definition
WorkTicket::WorkTicket(int number, std::string id, int day, int month, int year, std::string description)
{
	//Assigning the parameters to attributes of the class
	SetTicketNumber(ticketNumber);
	SetClientID(clientID);
	SetTicketMonth(month);
	SetTicketDay(day);
	SetTicketYear(year);
	SetIssueDescription(description);
}

bool WorkTicket::SetWorkTicket(int number, std::string id, int day, int month, int year, std::string description)
{
	//Constant Variables
	const int DAYS = 31;
	const int MONTHS = 12;
	const int YEAR_MINIMUM = 2000;
	const int YEAR_MAXIMUM = 2099;

	//Variable for returning a boolean value
	bool returnValue;

	//range validation
	if (ticketNumber < 0 || month < 1 || month > MONTHS
	|| day < 1 || day > DAYS || year < YEAR_MINIMUM || year > YEAR_MAXIMUM)
		returnValue = false;
	else if (clientID.length() < 1 || description.length() < 1)
		returnValue = false;
	else
	{
		ticketNumber = number;
		clientID = id;
		ticketDay = day;
		ticketMonth = month;
		ticketYear = year;
		issueDescription = description;
		return true;
	}
	

	return returnValue;
}

//Accessor to display the work ticket to the user
void WorkTicket::ShowWorkTicket() const
{
	std::cout << "\nTicket Number: " << ticketNumber
		<< "\nClient ID: " << clientID
		<< "\nDate: " << ticketDay << "/" << ticketMonth << "/" << ticketYear
		<< "\nDescription:\n\t" << issueDescription << std::endl;
}

int main()
{
	//Array declaration for WorkTicket class
	WorkTicket arr[3];

	//Variable declaration
	int numberInput, dayInput, monthInput, yearInput;
	std::string idInput, descriptionInput;

	//Prompt for user input
	std::cout << "Please enter the following information when prompted." << std::endl;

	//Loop to go through input for all elements in the array
	for (int i = 0; i < 3; i++)
	{
		try
		{
			std::cout << "\nEnter ticket number: ";
			numberInput = ConsoleInput::ReadInteger();
			arr[i].SetTicketNumber(numberInput);

			std::cout << "\nEnter Client ID: ";
			std::cin >> idInput;
			arr[i].SetClientID(idInput);

			std::cout << "\nEnter Date: ";
			std::cout << "\n\tDay: ";
			std::cin >> dayInput;
			std::cout << "\tMonth: ";
			std::cin >> monthInput;
			std::cout << "\tYear: ";
			std::cin >> yearInput;

			arr[i].SetTicketDay(dayInput);
			arr[i].SetTicketMonth(monthInput);
			arr[i].SetTicketYear(yearInput);

			std::cout << "\nEnter Descriptive Issue: ";
			std::cin >> descriptionInput;
			arr[i].SetIssueDescription(descriptionInput);
		}
		catch (const std::exception& ex)
		{
			std::cerr << ex.what(); 
		}
	}
	std::cout << std::endl;

	//For loop to output all the WorkTicket array elements to the console
	std::cout << "Following information was received." << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Ticket Number: " << arr[i].GetTicketNumber() << std::endl;
		std::cout << "Client ID: " << arr[i].GetClientID() << std::endl;
		std::cout << "Date: " << arr[i].GetTicketDay() << " / " << arr[i].GetTicketMonth()
			<< " / " << arr[i].GetTicketYear() << std::endl;
		std::cout << "Description: " << arr[i].GetIssueDescription() << std::endl << std::endl;
	}
}

//Mutator function - Sets the ticket number
void WorkTicket::SetTicketNumber(int number)
{
	//Try/Catch for exception handling
	try
	{
		//If number is greater than 0, set the ticketNumber
		if (number > 0) 
		{
			ticketNumber = number;
		}
	}		
	catch(std::invalid_argument)
	{
		//Throw the exception
		throw std::invalid_argument("Ticket Number must be a positive whole number. Please try again.");
	}
	
}

//Mutator method - Sets the client ID
void WorkTicket::SetClientID(std::string id)
{
	//Try/Catch for exception handling
	try
	{
		//If number is greater than 0, set the clientID
		if (id.length() > 0)
		{
			clientID = id;
		}
	}
	catch (std::invalid_argument)
	{
		//Throw the exception
		throw std::invalid_argument("Please enter client ID using alpha-numeric.");
	}
}

//Mutator method - Sets the day attribute
void WorkTicket::SetTicketDay(int day)
{
	//Try/Catch for exception handling
	try
	{
		//If number is greater than 0, set the ticketDay
		if (day >= 1 && day <= 31)
		{
			ticketDay = day;
		}
	}
	catch (std::invalid_argument)
	{
		//Throw the exception
		throw std::invalid_argument("Invalid Day. Please enter a day between 1 and 31");
	}
}

//Mutator method - Sets the month attribute
void WorkTicket::SetTicketMonth(int month)
{
	//Try/Catch for exception handling
	try
	{
		//If number is greater than 0, set the ticketMonth
		if (month >= 1 && month <= 12)
		{
			ticketMonth = month;
		}
	}
	catch (std::invalid_argument)
	{
		//Throw the exception
		throw std::invalid_argument("Invalid Month. Please enter month between 1 and 12");
	}
}

//Mutator method - Sets the year attribute
void WorkTicket::SetTicketYear(int year)
{
	//Try/Catch for exception handling
	try
	{
		//If number is greater than 0, set the ticketYear
		if (year <= 2099 && year >= 2000)
		{
			ticketYear = year;
		}
	}
	catch (std::invalid_argument)
	{
		//Throw the exception
		throw std::invalid_argument("Invalid Year. Please enter year between 2000 and 2099.");
	}
}

//Mutator method - Sets the description
void WorkTicket::SetIssueDescription(std::string description)
{
	//Try/Catch for exception handling
	try
	{
		//If number is greater than 0, set the issueDescription
		if (description.length() > 0)
		{
			issueDescription = description;
		}
	}
	catch (std::invalid_argument)
	{
		//Throw the exception
		throw std::invalid_argument("Please enter descriptive issue.");
	}
}

//Accessor method - returns the ticket number
int WorkTicket::GetTicketNumber()
{
	return ticketNumber;
}

//Accessor method - returns the client ID
std::string WorkTicket::GetClientID()
{
	return clientID;
}

//Accessor method - returns the ticket day
int WorkTicket::GetTicketDay()
{
	return ticketDay;
}

//Accessor method - returns the ticket month
int WorkTicket::GetTicketMonth()
{
	return ticketMonth;
}

//Accessor method - returns the ticket year
int WorkTicket::GetTicketYear()
{
	return ticketYear;
}

//Accessor method - returns the issue description
std::string WorkTicket::GetIssueDescription()
{
	return issueDescription;
}

