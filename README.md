# 🚆 RailConnect - Railway Reservation Management System

A **console-based Railway Reservation Management System** developed in **C++** using **Object-Oriented Programming (OOP)** concepts and **file handling**. This project allows users to view available trains, book tickets, search reservations, view booked tickets, and cancel bookings while storing passenger data in a text file.

---

## 📌 Features

* View available trains
* Book railway tickets
* Display all booked tickets
* Search tickets by passenger name
* Cancel booked tickets
* Store passenger records using file handling
* Load saved records automatically when the program starts

---

## 🛠️ Technologies Used

* **Language:** C++
* **Concepts:**

  * Classes and Objects
  * Inheritance
  * Constructors
  * Pointers
  * Arrays
  * File Handling (`ifstream`, `ofstream`)
  * String Streams (`stringstream`)

---

## 📂 Project Structure

```text
RailConnect/
│── main.cpp
│── new_passenger_records.txt
└── README.md
```

---

## 🚀 How to Run

1. Clone the repository:

```bash
git clone https://github.com/Sourabh108-Coder/RailConnect
```

2. Open the project in your preferred C++ IDE or editor.

3. Compile the program:

```bash
g++ main.cpp -o RailConnect
```

4. Run the executable:

```bash
./RailConnect
```

> On Windows:

```bash
RailConnect.exe
```

---

## 📋 Menu

```text
Railway Management System

1. View Available Trains
2. Book a Ticket
3. View Booked Tickets
4. Search Your Ticket
5. Cancel a Booking
6. Exit
```

---

## 💾 Data Storage

Passenger information is stored in:

```text
new_passenger_records.txt
```

Each record contains:

```text
Seat Number, Name, Age, Gender, Phone Number, Train Name
```

The program loads existing records automatically at startup.

---

## 📚 Object-Oriented Design

### Ticket

Base class that stores the common `name` attribute.

### Train

Derived from `Ticket` and stores:

* Train name
* Source
* Destination
* Total seats
* Available seats

### Passenger

Derived from `Ticket` and stores:

* Passenger name
* Age
* Gender
* Phone number
* Seat number
* Pointer to the booked train

---

## ⚠️ Current Limitations

* Passenger search is based only on name.
* Duplicate passenger names are not uniquely identified.
* Train information is hard-coded.
* Available seats are not recalculated from saved bookings when the program starts.
* Basic input validation only.

These can be improved in future versions.

---

## 🔮 Future Improvements
* Unique booking ID or PNR generation
* Train management (Add, Edit, Delete)
* Admin dashboard
* Better input validation
* Improved seat allocation
* Date and time of travel
* Fare calculation
* Database integration (MySQL/SQLite)
* Graphical User Interface (GUI)

---

## 📸 Sample Output

```text
Railway Management System

1. View Available Trains
2. Book a Ticket
3. View Booked Tickets
4. Search Your Ticket
5. Cancel a Booking
6. Exit
```

---

## 🤝 Contributing

Contributions, suggestions, and improvements are welcome. Feel free to fork the repository and submit a pull request.

---

Developed as a C++ Object-Oriented Programming project demonstrating file handling and basic railway reservation management.

---

## 👨‍💻 Author

Sourabh (https://github.com/Sourabh108-Coder)
