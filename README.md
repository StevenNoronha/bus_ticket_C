# Bus Ticket Booking System

This code implements a bus ticket booking system that allows users to book bus tickets, view available buses, and check seat availability. The system stores information about each bus, including the agent name, bus number, the source and destination location, the fare, and the availability of seats. The system supports searching for buses by source and destination locations, searching for bus tickets by bus number, and displaying seat availability for a particular bus.

## Features
1. Insert bus information
2. Display all buses
3. Available bus one a particular route
4. Display information of particular bus
5. Book a seat in a particular bus
6. Display available seats

## Functionality
* display()
Displays all the buses in the system, including the agent name, bus number, source and destination locations, and the fare.

* insert()
Adds a new bus to the system. Prompts the user to enter the agent name, bus number, source and destination locations, and fare. Initializes the seat availability matrix to 0.

* search()
Searches for a bus in the system by source and destination locations. Prompts the user to enter the source and destination locations and displays all the buses that match the search criteria.

* searchp()
Searches for a bus in the system by bus number. Prompts the user to enter the bus number and displays the bus if found.

* issue()
Allows the user to book a seat on a bus. Prompts the user to enter the bus number and the seat number to book.
