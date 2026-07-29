# 🚆 RailConnect - Railway Reservation Management System

A **console-based Railway Reservation Management System** developed in **C++** using **Object-Oriented Programming (OOP)** concepts and **file handling**. The application provides separate interfaces for **users** and **administrators**, allowing users to register, log in, book train tickets, search reservations, and cancel bookings, while administrators can view registered users, trains, and booked tickets.

---

# 📌 Features

### 👤 User Features

- User Registration
- User Login Authentication
- View Available Trains
- Book Train Tickets
- View Booked Tickets
- Search Ticket
- Cancel Booked Ticket
- Input Validation
  - Email Validation
  - Age Validation
  - Gender Validation
  - Phone Number Validation

### 👨‍💼 Admin Features

- Admin Login
- View All Registered Users
- View Available Trains
- View All Booked Tickets

### 💾 File Handling

- Load train details from a file
- Store registered users
- Store booked passenger records
- Automatically load saved passenger records when the program starts

---

# 🛠️ Technologies Used

- **Language:** C++
- **Programming Paradigm:** Object-Oriented Programming (OOP)

### Concepts Used

- Classes and Objects
- Inheritance
- Constructors
- Pointers
- Arrays
- File Handling (`ifstream`, `ofstream`)
- String Streams (`stringstream`)
- Input Validation
- Dynamic Memory Allocation

---

# 📂 Project Structure

```text
RailConnect/
│── main.cpp
│── trains.txt
│── users.txt
│── admin.txt
│── new_passenger_records.txt
└── README.md
```

---

# 🚀 How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/Sourabh108-Coder/RailConnect.git
```

### 2. Open the Project

Open the project in your preferred C++ IDE (Visual Studio Code, Code::Blocks, Dev-C++, etc.).

### 3. Compile

```bash
g++ main.cpp -o RailConnect
```

### 4. Run

Linux/macOS

```bash
./RailConnect
```

Windows

```bash
RailConnect.exe
```

---

# 🔐 Login System

When the application starts, users are presented with the following options:

```text
=========== Railway Login System ===========

1. Register
2. Login
3. Admin Login
4. Exit
```

### User Registration

- Register using an email and password.
- Duplicate email registration is prevented.
- Email format is validated.

### User Login

- Login using registered credentials stored in `users.txt`.

### Admin Login

- Admin credentials are verified using `admin.txt`.

---

# 📋 User Menu

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

# 👨‍💼 Admin Menu

```text
========== Admin Panel ==========

1. View All Registered Users
2. View All Trains
3. View All Booked Tickets
4. Exit
```

---

# 💾 Data Storage

The project uses text files for persistent storage.

| File | Purpose |
|------|----------|
| `trains.txt` | Stores train information |
| `users.txt` | Stores registered user credentials |
| `admin.txt` | Stores admin login credentials |
| `new_passenger_records.txt` | Stores booked passenger records |

Passenger records are stored in the following format:

```text
Seat Number, Name, Age, Gender, Phone Number, Train Name
```

---

# 📚 Object-Oriented Design

## Ticket

Base class containing the common attribute:

- Passenger/Train Name

---

## Train

Derived from the `Ticket` class.

Attributes:

- Train Name
- Source
- Destination
- Total Seats
- Available Seats

---

## Passenger

Derived from the `Ticket` class.

Attributes:

- Passenger Name
- Age
- Gender
- Phone Number
- Seat Number
- Pointer to the Booked Train

---

# ✅ Input Validation

The application validates user input for:

- Valid email format
- Duplicate email registration
- Valid age (1–120)
- Valid gender
- 10-digit phone number
- Registered email before ticket booking

---

# 📸 Screenshots

---
## Login Menu
![Login Menu](screenshots/login-menu.png)


---



---



---



---


---



---



---


---

---



---

# 👨‍💻 Author

**Sourabh**

GitHub: **https://github.com/Sourabh108-Coder**