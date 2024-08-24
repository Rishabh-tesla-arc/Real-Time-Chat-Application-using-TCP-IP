# Real-Time Chat Application

## Overview

This project implements a simple real-time chat application using TCP in C. The application consists of a server and multiple clients. The server handles multiple client connections and facilitates message exchange between clients.

## Features

- **Server**: Listens for incoming client connections, handles multiple clients, and broadcasts messages from one client to all others.
- **Client**: Connects to the server, sends messages, and displays messages received from other clients.

## Requirements

- C compiler (e.g., `gcc`)
- POSIX-compatible environment (Linux or macOS)

## Getting Started

### 1. Clone the Repository
`git clone https://github.com/your-username/chat-application.git
cd chat-application`


### 2. To Run the Code 
Compile the Server and Client
To compile the server and client, use the following commands:

`gcc -o server server.c -lpthread`
`gcc -o client client.c -lpthread`

### 3. 3. Run the Server
In one terminal, start the server:
`./server`
The server will start listening on port 8080 by default.

### 4. Run the Clients
In one or more additional terminals, start the clients:

`./client`

Each client will connect to the server and be able to send and receive messages.


## Code Explanation
Server Code (server.c)
- Socket Creation: The server creates a socket for communication.
- Binding: The server binds the socket to an address and port.
- Listening: The server listens for incoming client connections.
- Handling Clients: For each client connection, a new thread is created to handle communication.
- Message Broadcasting: Messages received from one client are broadcast to all other connected clients.

Client Code (client.c)
- Socket Creation: The client creates a socket for communication.
- Connecting: The client connects to the server using the specified address and port.
- Message Sending: The client reads input from the user and sends it to the server.
- Message Receiving: The client receives messages from the server and displays them.


## Configuration
By default, the server listens on port 8080 and clients connect to 127.0.0.1 (localhost). You can modify these settings in the code if needed.
