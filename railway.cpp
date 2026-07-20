#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>


using namespace std;
class Ticket {
public:
    string name;

    Ticket(string n) : name(n) {}
};
class Train : public Ticket {
public:
    string source;
    string destination;
    int totalSeats;
    int availableSeats;

    Train(string n, string src, string dest, int seats)
        : Ticket(n), source(src), destination(dest), totalSeats(seats), availableSeats(seats) {}
};
class Passenger : public Ticket {
public:
    int age;
    string gender;
    int seatNumber;
    string phoneNumber;
    Train* bookedTrain;  
    Passenger() : Ticket(""), age(0), gender(""), seatNumber(0), phoneNumber(""), bookedTrain(nullptr) {}
    Passenger(string n, int a, string g, int seat, string phone, Train* train)
        : Ticket(n), age(a), gender(g), seatNumber(seat), phoneNumber(phone), bookedTrain(train) {}
};
int displayMenu() {
    int choice;
    cout << "\n\nRailway Management System" << endl;
    cout << "1. View Available Trains" << endl;
    cout << "2. Book a Ticket" << endl;
    cout << "3. View Booked Tickets" << endl;
    cout << "4. Search Your Ticket" << endl;
    cout << "5. Cancel a Booking" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}
void displayAvailableTrains(const Train trains[], int numTrains) {
    cout << "Available Trains:" << endl;
    cout << "-----------------" << endl;
    cout << "Train No\tTrain Name\t\t Source\t\tDestination\t\tAvailable Seats" << endl;
    for (int i = 0; i < numTrains; ++i) {
        cout << i + 1 << "\t\t" << trains[i].name << "\t" << trains[i].source << "\t" << trains[i].destination << "\t\t" << trains[i].availableSeats << endl;
    }
}
void displayBookedTickets(const Passenger* passengers, int numPassengers) {
    cout << "Booked Tickets:" << endl;
    cout << "-----------------" << endl;
    cout << "Seat No\t Name\tAge\tGender\tPhone Number\tTrain Name" << endl;
    for (int i = 0; i < numPassengers; ++i) {
        cout << passengers[i].seatNumber << "\t" << passengers[i].name << "\t" << passengers[i].age << "\t" << passengers[i].gender << "\t" << passengers[i].phoneNumber << "\t" << passengers[i].bookedTrain->name << endl;
    }
}
void writePassengerToFile(const Passenger& passenger) {
    const string outputFileName = "new_passenger_records.txt"; 
    ofstream outputFile(outputFileName, ios::app);
    if (!outputFile) {
        cerr << "Error opening the file." << endl;
        return;
    }
    outputFile << passenger.seatNumber << "," << passenger.name << "," << passenger.age << "," << passenger.gender << "," << passenger.phoneNumber << "," << passenger.bookedTrain->name << endl;
    outputFile.close();
}
void readPassengersFromFile(Passenger* passengers, int& numPassengers, Train trains[], int numTrains) {
    const string inputFileName = "new_passenger_records.txt"; 
    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        return;
    }
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        int seat;
        string name, gender, phone, trainName;
        int age;
        ss >> seat;
        ss.ignore();
        getline(ss, name, ',');
        ss >> age;
        ss.ignore();
        getline(ss, gender, ',');
        getline(ss, phone, ',');
        getline(ss, trainName, ',');      
        Train* bookedTrain = nullptr;
        for (int i = 0; i < numTrains; ++i) {
            if (trains[i].name == trainName) {
                bookedTrain = &trains[i];
                break;
            }
        }
        if (bookedTrain != nullptr) {
            passengers[numPassengers++] = Passenger(name, age, gender, seat, phone, bookedTrain);
        }
    }
    inputFile.close();
}

bool emailExists(string email)
{
    ifstream file("users.txt");
    string mail, pass;

    while (file >> mail >> pass)
    {
        if ( mail == email)
        {
            return true;
        }
    }

    return false;
}


bool registerUser()
{
    string email,password;

    cout << "\n===== User Registration =====\n";

    cout << "Enter Email: ";
    cin >> email;

    if(emailExists(email))
    {
       cout << "Email already exists!\n";
       return false;
    }

    cout << "Enter Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);

    file << email << " " << password << endl;

    file.close();

    cout << "Registration Successful!\n";
    return true;

}

bool loginUser()
{
    string useremail, userpassword;
    string email,password;

    cout << "\n========== User Login ==========\n";

    cout << "Username: ";
    cin >> useremail;

    cout << "Password: ";
    cin >> userpassword;

    ifstream file("users.txt");

    while (file >> email >> password)
    {
        if (useremail == email && userpassword == password)
        {
            cout << "\nLogin Successful!\n";
            return true;
        }
    }

    cout << "\nInvalid Username or Password!\n";

    return false;
}

int main() {

    // Login Register Functionality Implementation

    int option;

    while (true)
    {
        cout << "\n=========== Railway Login System ===========" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter choice: ";
        cin >> option;

        if (option == 1)
        {
            if(registerUser())
            {
                break;
            }
        }
        else if (option == 2)
        {
            if(loginUser())
            {
                break;
            }
        }
        else if (option == 3)
        {
            cout << "Thank you for using the Railway Management System. Goodbye!" << endl;   
            return 0;
        }
        else
        {
          cout << "Invalid Choice!" << endl;
        }
    }
    

    // RailConnect System Implementation
    
    const int maxTrains = 3;
    const int maxPassengers = 100;
    Train trains[maxTrains] = {
        Train("Indian Railways  ", "Amritsar", "Delhi    ", 100),
        Train("Rajdhani Express", "Amritsar", "Bareilly", 150),
        Train("Humsafar Express", "Amritsar", "Chennai ", 80)
    };
    Passenger* passengers = new Passenger[maxPassengers];
    int numPassengers = 0;
    readPassengersFromFile(passengers, numPassengers, trains, maxTrains);
    while (true) {
        int choice = displayMenu();
        switch (choice) {
            case 1:
                displayAvailableTrains(trains, maxTrains);
                break;
            case 2: {
                displayAvailableTrains(trains, maxTrains);
                int trainChoice;
                cout << "Enter the number of the train you want to book: ";
                cin >> trainChoice;
                if (trainChoice >= 1 && trainChoice <= maxTrains) {
                    Train& selectedTrain = trains[trainChoice - 1];
                    if (selectedTrain.availableSeats > 0) {
                        string name, gender, phone;
                        int age;
                        cout << "Enter your name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter your age: ";
                        cin >> age;
                        cout << "Enter your gender: ";
                        cin.ignore();
                        getline(cin, gender);
                        cout << "Enter your phone number: ";
                        cin.ignore();
                        getline(cin, phone);
                        int seatNumber = 0;
                        for (int i = 0; i < maxPassengers; ++i) {
                            if (passengers[i].bookedTrain == &selectedTrain && passengers[i].seatNumber > seatNumber) {
                                seatNumber = passengers[i].seatNumber;
                            }
                        }
                        seatNumber++;
                        if (seatNumber <= selectedTrain.totalSeats) {
                            cout << "Ticket booked successfully for train " << selectedTrain.name << " - Seat No: " << seatNumber << endl;
                            selectedTrain.availableSeats--;

                            passengers[numPassengers++] = Passenger(name, age, gender, seatNumber, phone, &selectedTrain);

                            writePassengerToFile(passengers[numPassengers - 1]);
                        } else {
                            cout << "Sorry, no seats available on this train." << endl;
                        }
                    } else {
                        cout << "Sorry, no seats available on this train." << endl;
                    }
                } else {
                    cout << "Invalid train selection. Please try again." << endl;
                }
                break;
            }
            case 3:
                displayBookedTickets(passengers, numPassengers);
                break;
            case 4: {
                string searchName;
                cout << "Enter your name to search for your booked ticket: ";
                cin.ignore();
                getline(cin, searchName);
                cout << "Matching Tickets for Passenger: " << searchName << endl;
                cout << "---------------------------------" << endl;
                cout << "Seat No\tPassenger Name\tAge\tGender\tPhone Number\tTrain Name" << endl;
                bool found = false;
                for (int i = 0; i < numPassengers; ++i) {
                    if (passengers[i].name == searchName) {
                        cout << passengers[i].seatNumber << "\t" << passengers[i].name << "\t" << passengers[i].age << "\t" << passengers[i].gender << "\t" << passengers[i].phoneNumber << "\t" << passengers[i].bookedTrain->name << endl;
                        found = true;
                    }
                }
                if (!found) {
                    cout << "No matching tickets found for passenger: " << searchName << endl;
                }
                break;
            }
            case 5: {
                string cancelName;
                cin.ignore();
                cout << "Enter your name to cancel your booked ticket: ";
                getline(cin, cancelName);
                bool canceled = false;
                for (int i = 0; i < numPassengers; ++i) {
                    if (passengers[i].name == cancelName) {
                        Train& bookedTrain = *passengers[i].bookedTrain;
                        bookedTrain.availableSeats++;
                            for (int j = i; j < numPassengers - 1; ++j) {
                            passengers[j] = passengers[j + 1];
                        }
                        numPassengers--;                      
                        ofstream outputFile("new_passenger_records.txt");
                        for (int j = 0; j < numPassengers; ++j) {
                            outputFile << passengers[j].seatNumber << "," << passengers[j].name << "," << passengers[j].age << "," << passengers[j].gender << "," << passengers[j].phoneNumber << "," << passengers[j].bookedTrain->name << endl;
                        }
                        outputFile.close();

                        cout << "Ticket canceled successfully for passenger: " << cancelName << endl;
                        canceled = true;
                        break;
                    }
                }
                if (!canceled) {
                    cout << "No booking found for passenger: " << cancelName << ". Please enter a valid name." << endl;
                }
                break;
            }
            case 6:
                cout << "Thank you for using the Railway Management System. Goodbye!" << endl;                
                delete[] passengers;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    return 0;
}
