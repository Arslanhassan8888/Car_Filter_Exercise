#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Structure used to store all the information about the user's car
struct Car
{
    string make;
    int year;
    int cylinders;

    // These values are used to create the air filter model number
    char makeCharacter;
    int yearPart;
};


// Displays the make menu and returns the user's choice
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

        // Check if the user entered something that is not a number
        if (cin.fail())
        {
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Remove the invalid input

            cout << "Invalid input. Please enter a number." << endl;
        }
        // Accept choices from 1 to 5
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


// Sets the make of the car and the first character of the filter model
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
        cout << "QUITTING" << endl;
        cout << "Goodbye!" << endl;
        return;
    }
}


// Asks the user for the year and checks that it is between 1995 and 2015
void getCarYear(Car& car)
{
    while (true)
    {
        cout << "Please enter the year of your car (1995-2015): " << endl;
        cin >> car.year;

        // Handle letters or other invalid input
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');

            cout << "Invalid input. Please enter a number." << endl;
        }
        else if (car.year >= 1995 && car.year <= 2015)
        {
            // Keep only the last two digits of the year
            // Example: 2007 % 100 gives 7, which will later display as 07
            car.yearPart = car.year % 100;

            cout << "Year accepted." << endl;
            break;
        }
        else
        {
            cout << "Invalid year. Please try again." << endl;
        }
    }
}


// Displays the correct cylinder options depending on the make of car
void getCarCylinders(Car& car, int makeChoice)
{
    int cylinderChoice;

    // Ford can have 6 or 8 cylinders
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

    // Nissan can have 4 or 6 cylinders
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

    // Volvo can have 15 or 20 cylinders
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

    // Jaguar can have 6 or 12 cylinders
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


// Displays the selected car information and recommended filter model
void displayCarDetails(Car& car)
{
    cout << endl;
    cout << "Your car details:" << endl;
    cout << "Make: " << car.make << endl;
    cout << "Year: " << car.year << endl;
    cout << "Cylinders: " << car.cylinders << endl;

    cout << endl;
    cout << "Air Filter Model Number: ";

    // First character = first letter of make
    cout << car.makeCharacter;

    // Next two characters = last two digits of year
    // setw(2) and setfill('0') add a leading zero when needed
    cout << setfill('0') << setw(2) << car.yearPart;

    // Last two characters = number of cylinders
    cout << setw(2) << car.cylinders << endl;

    cout << "Goodbye!" << endl;
}


// Main function controls the order of the program
int main()
{
    Car car;

    // Step 1: Ask for the make
    int makeChoice = getMakeChoice();

    // Store the selected make
    setCarMake(car, makeChoice);

    // Stop the program if Quit was selected
    if (makeChoice == 5)
    {
        return 0;
    }

    // Step 2: Ask for the year last, as required by the specification
    getCarYear(car);

    // Step 3: Ask for the number of cylinders
    getCarCylinders(car, makeChoice);

    // Display the car details and recommended filter model
    displayCarDetails(car);

    return 0;
}
