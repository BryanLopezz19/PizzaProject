// Bryan Lopez and Ryan Lu
// 6/4/2022
// Project 5
// This program will take a pizza order from the user.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const double TAX_RATE = 0.0795;
// the tax that will be used on the entire price of the pizza
const double PER_TOPPING = 1.25;
// price per topping the user selects will be added on to total price
const double DISCOUNT = 2.00;
//this will discount the user $2.00 if their name matches

void welcome(string& firstName, string& onwerO, string& onwerT);
// this function will print a welcome message and ask the user to enter their name

void convertInputLower(string& firstName, string& owner1, string& owner2);
// this function will convert the names of the user and owners names to lower case

void menu();
// this function will print a menu

void pizzaSize(int& size, double& price);
// this function will recieve a value of size and price of pizza

string crustChoice(char& crust);
// this function will ask the user what type of crust they want

string toppings(char& topppings, int& numberOfToppings);
// this function will return the toppings and keep count of toppings entered

bool discount(string& firstName, string& ownerO, string& ownerT);
// this function will return true if the name input matches with the owners of the pizzaera

void totalD(string firstName, string ownerO, string ownerT, double& price, int numberOfToppings, double& totalTax, double& totalDue);
// this function will calculate the ammount the user has to pay

void receipt(int pizza, string crust, string toppings, double tax, double pizzaPrice, double totalPizzaPrice);
// this function will print to the user their order and ammount to pay and also the wait time

int main()
{
	string firstName;
	string ownerOne, ownerTwo, crustOutput, topping = "Cheese ";
	char crust, toppingChoice;
	int size;
	int count(0);
	double price, tax, ammountDue;

	welcome(firstName, ownerOne, ownerTwo);
	convertInputLower(firstName, ownerOne, ownerTwo);
	menu();
	pizzaSize(size, price);
	crustOutput = crustChoice(crust);
	string toppingList = toppings(toppingChoice, count);
	totalD(firstName, ownerOne, ownerTwo, price, count, tax, ammountDue);
	discount(firstName, ownerOne, ownerTwo);
	receipt(size, crustOutput, toppingList, tax, price, ammountDue);
}

void welcome(string& firstName, string& onwerO, string& onwerT)
{
	onwerO = "Ryan";
	onwerT = "Bryan";
	cout << "Welcome to " << onwerO << " and " << onwerT << "'s Pizzeria\n";
	cout << "Enter your first name: ";
	cin >> firstName;
}

void convertInputLower(string& firstName, string& ownerO, string& ownerT)
{
	//for loop to read through first name
	for (int i = 0; i < firstName.length(); i++)
	{
		//name entered will be in lower case
		firstName[i] = tolower(firstName[i]);
	}

	//for loop to read through first owner
	for (int i = 0; i < ownerO.length(); i++)
	{
		//owner one's name will be in lower case
		ownerO[i] = tolower(ownerO[i]);
	}

	//for loop to read through second owner
	for (int i = 0; i < ownerT.length(); i++)
	{
		//owner two's name will be in lower case
		ownerT[i] = tolower(ownerT[i]);
	}
}


void menu()
{
	cout << "Pizza Size(inches)     Cost\n";
	cout << "         10             $10.99\n";
	cout << "         12             $12.99\n";
	cout << "         14            $14.99\n";
	cout << "         16            $16.99\n";
}

void pizzaSize(int& size, double& price)
{
	cout << "What size pizza would you like?\n10, 12, 14, or 16 (enter the number only): ";
	cin >> size;

	if (size == 10)
	{
		price = 10.99;
	}
	else if (size == 12)
	{
		price = 12.99;
	}
	else if (size == 14)
	{
		price = 14.99;
	}
	else if (size == 16)
	{
		price = 16.99;
	}
	else
	{
		cout << "Size unavailable, you will get a 12 inch.\n";
		size = 12;
		price = 12.99;
	}
}

string crustChoice(char& crust)
{
	string crustOutput;
	cout << "What type of crust do you want?\n(H) Hand-tossed, (T) Thin-crust, or (D) Deep-dish (enter H, T, or D): ";
	cin >> crust;
	switch (crust)
	{
	case 'h':
	case 'H':
		crustOutput = "Hand-tossed crust";
		break;
	case 't':
	case 'T':
		crustOutput = "Thin-crust";
		break;
	case 'd':
	case 'D':
		crustOutput = "Deep-dish crust";
		break;
	default:
		cout << "crust unavailable, you will get Hand-tossed.\n";
		crustOutput = "Hand-tossed crust";
		break;
	}
	return crustOutput;
}

string toppings(char& topppings, int& numberOfToppings)
{
	string topping = "Cheese ";
	cout << "All pizzas come with cheese.\nAdditional toppings are $1.25 each, choose from:\nPepperoni, Sausage, Onion, Mushroom\n";
	cout << "Do you want Pepperoni? (Y/N): ";
	cin >> topppings;
	if (topppings == 'y' || topppings == 'Y')
	{
		topping += "Pepperoni ";
		numberOfToppings++;
	}

	cout << "Do you want Sausage? (Y/N): ";
	cin >> topppings;
	if (topppings == 'y' || topppings == 'Y')
	{
		topping += "Sausage ";
		numberOfToppings++;
	}

	cout << "Do you want Onion? (Y/N): ";
	cin >> topppings;
	if (topppings == 'y' || topppings == 'Y')
	{
		topping += "Onion ";
		numberOfToppings++;
	}

	cout << "Do you want Mushroom? (Y/N): ";
	cin >> topppings;
	if (topppings == 'y' || topppings == 'Y')
	{
		topping += "Mushroom ";
		numberOfToppings++;
	}
	return topping;
}

bool discount(string& firstName, string& ownerO, string& ownerT)
{
	if (firstName == ownerO || firstName == ownerT)
	{
		// if the name entered matchers either of the owners name return true
		return true;
	}
	else
	{
		return false;
	}
}

void totalD(string firstName, string ownerO, string ownerT, double& price, int numberOfToppings, double& totalTax, double& totalDue)
{
	//call discount function to check if valid for a discount
	if (discount(firstName, ownerO, ownerT))
	{
		cout << "\nCool name! You get a $2.00 discount on your pizza!";
		price = price + (numberOfToppings * PER_TOPPING);
		totalTax = price * TAX_RATE;
		totalDue = price - DISCOUNT;
	}
	//no discount is implemented
	else
	{
		price = price + (numberOfToppings * PER_TOPPING);
		totalTax = price * TAX_RATE;
		totalDue = price + totalTax;
	}
}

void receipt(int size, string crust, string toppings, double tax, double pizzaPrice, double totalPizzaPrice)
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << endl;
	cout << "Your order is as follows:\n";
	cout << size << "-inch pizza \n";
	cout << crust << endl;
	cout << toppings << endl;
	cout << "The cost of your order is: $" << pizzaPrice << endl;
	cout << "The tax is: $" << tax << endl;
	cout << "The total due is: $" << totalPizzaPrice << endl;
	cout << "Your order will be ready for pickup in 30 minutes.";
}
