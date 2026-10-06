#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Car
{
    string make;
    int year;
    int cylinders;

    char makeCharacter;
    int yearPart;


};

int getMakeChoice()
{
    int makeChoice;

    while (true)
    {
        cout << "Please select the make of your car:" << endl;
        cout << "1. Ford" << endl;
        cout << "2. Nissan" << endl;
        cout << "3. Volvo" << endl;
        cout << "4. Jaguar" << endl;
        cout << "5. Quit" << endl;

        cin >> makeChoice;

        if (cin.fail())
        {
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Discard invalid input

            cout << "Invalid input. Please enter a number." << endl;
        }
        else if (makeChoice >= 1 && makeChoice <= 5)
        {
            return makeChoice;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void setCarMake(Car& car, int makeChoice)
{
    if (makeChoice == 1)
    {
        car.make = "Ford";
		car.makeCharacter = 'F';   
    }
    else if (makeChoice == 2)
    {
        car.make = "Nissan";
		car.makeCharacter = 'N';
    }
    else if (makeChoice == 3)
    {
        car.make = "Volvo";
		car.makeCharacter = 'V';
    }
    else if (makeChoice == 4)
    {
        car.make = "Jaguar";
		car.makeCharacter = 'J';
    }
    else if (makeChoice == 5)
    {
        cout << "Exiting program." << endl;
        cout << "Goodbye!" << endl;
        return;
    }
}

void getCarYear(Car& car)
{
    while (true)
    {
        cout << "Please enter the year of your car (1995-2015): " << endl;
        cin >> car.year;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');

            cout << "Invalid input. Please enter a number." << endl;
        }
        else if (car.year >= 1995 && car.year <= 2015)
        {
			car.yearPart = car.year % 100; // Store the last two digits of the year
            cout << "Year accepted." << endl;
            break;
        }
        else
        {
            cout << "Invalid year. Please try again." << endl;
        }
    }
}

void getCarCylinders(Car& car, int makeChoice)
{
    int cylinderChoice;

    if (makeChoice == 1)
    {
        while (true)
        {
            cout << "Please select the number of cylinders:" << endl;
            cout << "1. 6 cylinders" << endl;
            cout << "2. 8 cylinders" << endl;

            cin >> cylinderChoice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');

                cout << "Invalid input. Please enter a number." << endl;
            }
            else if (cylinderChoice == 1)
            {
                car.cylinders = 6;
                break;
            }
            else if (cylinderChoice == 2)
            {
                car.cylinders = 8;
                break;
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
    else if (makeChoice == 2)
    {
        while (true)
        {
            cout << "Please select the number of cylinders:" << endl;
            cout << "1. 4 cylinders" << endl;
            cout << "2. 6 cylinders" << endl;

            cin >> cylinderChoice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');

                cout << "Invalid input. Please enter a number." << endl;
            }
            else if (cylinderChoice == 1)
            {
                car.cylinders = 4;
                break;
            }
            else if (cylinderChoice == 2)
            {
                car.cylinders = 6;
                break;
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
    else if (makeChoice == 3)
    {
        while (true)
        {
            cout << "Please select the number of cylinders:" << endl;
            cout << "1. 15 cylinders" << endl;
            cout << "2. 20 cylinders" << endl;

            cin >> cylinderChoice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');

                cout << "Invalid input. Please enter a number." << endl;
            }
            else if (cylinderChoice == 1)
            {
                car.cylinders = 15;
                break;
            }
            else if (cylinderChoice == 2)
            {
                car.cylinders = 20;
                break;
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
    else if (makeChoice == 4)
    {
        while (true)
        {
            cout << "Please select the number of cylinders:" << endl;
            cout << "1. 6 cylinders" << endl;
            cout << "2. 12 cylinders" << endl;

            cin >> cylinderChoice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');

                cout << "Invalid input. Please enter a number." << endl;
            }
            else if (cylinderChoice == 1)
            {
                car.cylinders = 6;
                break;
            }
            else if (cylinderChoice == 2)
            {
                car.cylinders = 12;
                break;
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
}

void displayCarDetails(Car& car)
{
    cout << endl;
    cout << "Your car details:" << endl;
    cout << "Make: " << car.make << endl;
    cout << "Year: " << car.year << endl;
    cout << "Cylinders: " << car.cylinders << endl;


    cout << endl;
    cout << "Air Filter Model Number: ";
    cout << car.makeCharacter;
    cout << setfill('0') << setw(2) << car.yearPart;
    cout << setw(2) << car.cylinders;
	cout << "Goodbye" << endl;
    cout << endl;
}

int main()
{
    Car car;

    int makeChoice = getMakeChoice();

    setCarMake(car, makeChoice);

    if (makeChoice == 5)
    {
        return 0;
    }

    getCarYear(car);

    getCarCylinders(car, makeChoice);

	displayCarDetails(car);

    return 0;
}