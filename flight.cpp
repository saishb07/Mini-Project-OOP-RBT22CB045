//RBT22CB045 , RBT22CB065.
#include<fstream>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Base class
class Flight {
protected:
    int flightNumber;
    string destination;
    float distance;
public:
    
    // Parameterized constructor
    Flight(int number, const string& dest, float dist) : flightNumber(number), destination(dest), distance(dist) {
        cout << "Flight " << flightNumber << " to " << destination << " created.\n";
        fstream file("C:\\Users\\Saish\\OneDrive\\Desktop\\Programming\\Air.txt",ios::app);
        file << "Flight Number: " << flightNumber << "\nDestination: " << destination << "\nDistance: " << distance << " miles\n";
        file.close();
    }

    // Destructor
    ~Flight() {
        cout << "Flight " << flightNumber << " file destroyed.\n";
    }
    
};

// Derived class
class Passenger : public Flight {
private:
    int passengerCount;
public:
    
    // Parameterized constructor
    Passenger(int number, const string& dest, float dist, int count) : Flight(number, dest, dist), passengerCount(count) {
        cout << "Passenger details added for Flight " << flightNumber << ".\n";
        fstream file("C:\\Users\\Saish\\OneDrive\\Desktop\\Programming\\Air.txt",ios::app);
        file << "Passenger Count: " << passengerCount << "\n----------------\n";
        file.close();
    }

    // Destructor
    ~Passenger() {
        cout << "Passenger details for Flight " << flightNumber << " deleted.\n";
    }
    
    //display filght details
    void display() const {
        cout << "Flight Number: " << flightNumber << "\nDestination: " << destination << "\nDistance: " << distance << " miles\n";
    }
    // Display passenger details
    void displayPassenger() const {
        display();
        cout << "Passenger Count: " << passengerCount << "\n";
    }
    
};

int main() {
    vector<Passenger> flights; // Vector to store flights with passenger details
    int choice;
    
    do {
        cout << "\nMenu:\n1. Add Flight\n2. Display All Flights\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int number, count;
                float dist;
                string dest;

                cout << "Enter Flight Number: ";
                cin >> number;

                cout << "Enter Destination: ";
                cin >> dest;

                cout << "Enter Distance: ";
                cin >> dist;

                cout << "Enter Passenger Count: ";
                cin >> count;

                flights.emplace_back(number, dest, dist, count);
                break;
            }
            case 2: {
                if (flights.empty()) {
                    cout << "No flights available.\n";
                } 
                else {
                    cout << "\nFlight Details:\n";
                    for (const auto& flight : flights) {
                        flight.displayPassenger();
                        cout << "--------------------------\n";
                    }
                }
                break;
            }
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 3);
    

    return 0;
}
