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

int main()
{
	//Array declaration for WorkTicket class
	WorkTicket workTicketArr[3];

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
			workTicketArr[i].SetTicketNumber(numberInput);

			std::cout << "\nEnter Client ID: ";
			std::cin >> idInput;
			workTicketArr[i].SetClientID(idInput);

			std::cout << "\nEnter Date: ";
			std::cout << "\n\tDay: ";
			std::cin >> dayInput;
			workTicketArr[i].SetTicketDay(dayInput);

			std::cout << "\tMonth: ";
			std::cin >> monthInput;
			workTicketArr[i].SetTicketMonth(monthInput);

			std::cout << "\tYear: ";
			std::cin >> yearInput;			
			workTicketArr[i].SetTicketYear(yearInput);

			std::cout << "\nEnter Descriptive Issue: ";
			std::cin >> descriptionInput;
			workTicketArr[i].SetIssueDescription(descriptionInput);
		}
		catch (std::exception& ex)
		{
			std::cerr << ex.what();
		}
	}
	std::cout << std::endl;

	//For loop to output all the WorkTicket array elements to the console
	std::cout << "Following information was received." << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Ticket Number: " << workTicketArr[i].GetTicketNumber() << std::endl;
		std::cout << "Client ID: " << workTicketArr[i].GetClientID() << std::endl;
		std::cout << "Date: " << workTicketArr[i].GetTicketDay() << " / " << workTicketArr[i].GetTicketMonth()
			<< " / " << workTicketArr[i].GetTicketYear() << std::endl;
		std::cout << "Description: " << workTicketArr[i].GetIssueDescription() << std::endl << std::endl;
	}
}
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
		else
		{
			//Throw the exception
			throw std::invalid_argument("Ticket Number must be a positive whole number. Please try again.");
		}
	}
	catch (std::invalid_argument& ex)
	{
		std::cerr << ex.what();
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
		else
		{
			//Throw the exception
			throw std::invalid_argument("Please enter client ID using alpha-numeric.");
		}
	}
	catch (std::invalid_argument& ex)
	{
		std::cerr << ex.what();
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
		else
		{
			//Throw the exception
			throw std::invalid_argument("Invalid Day. Please enter a day between 1 and 31");
		}
	}
	catch (std::invalid_argument& ex)
	{
		std::cerr << ex.what();
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
		else
		{
			//Throw the exception
			throw std::invalid_argument("Invalid Month. Please enter month between 1 and 12");
		}
	}
	catch (std::invalid_argument& ex)
	{
		std::cerr << ex.what();
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
		else
		{
			//Throw the exception
			throw std::invalid_argument("Invalid Year. Please enter year between 2000 and 2099.");
		}
	}
	catch (std::invalid_argument& ex)
	{
		std::cerr << ex.what();
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
		else
		{
			//Throw the exception
			throw std::invalid_argument("Please enter descriptive issue.");
		}
	}
	catch (std::invalid_argument& ex)
	{
		std::cerr << ex.what();
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
