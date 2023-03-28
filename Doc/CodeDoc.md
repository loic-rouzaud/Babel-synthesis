# Code and explications

# Client side

## Core.hpp

Inherits from the QApplication class provided by the Qt framework.
The Core class has two private member variables: a pointer to a GraphicSystem object, and a pointer to a Client object.
These two objects create my Client algorithm, and create my graphic user interface.

```bash
private:
        GraphicSystem *_graphicSystem;
        Client *_network;
```

## Core.cpp

Core class constructor and destructor, as well as the main function for the program. The Core class inherits from QApplication and is responsible for creating and connecting the Client and GraphicSystem objects. The constructor initializes the Client and GraphicSystem objects, connects their signals and slots, and shows the GraphicSystem object. The main function creates an instance of the Core class and executes it.

## GraphicSystem.hpp

Inherits from the QWidget class provided by the Qt framework, to create GUI for the user.

Signals :
**SendMessages(QString message)** is not working now. But reception function exists

Slots :
**OnclickSend()** and **OnclickConnnect()** works when a button is clicked.

Private :
**QLineEdit** A line edit allows the user to enter and edit a single line of plain text with a useful collection of editing functions, including undo and redo, cut and paste, and drag and drop.

## GraphicSystem.cpp

Sorry for this too long function. I put all the GUI in alony one function. Everything is splitable, and then call only the functions.

## Client.hpp

Inherits from the QObject class provided by the Qt framework.

**explicit Client(QObject *parent = nullptr)** : constructor that takes an optional parent object.

**~Client()**: destructor that cleans up the instance.

**void disconnectFromServer()**: closes the socket and disconnects from the server.

Signals:
**void messageReceived(QString message)** : emitted when a message is received from the server. **(Cf GUI SendMessage function)**

**void error(QAbstractSocket::SocketError socketError)** : emitted when an error occurs in the socket.


Slots:
**void onSendMessage(QString message)** : sends a message to the connected server. **(Cf GUI SendMessage function)**

**void connectToServer(QString host, quint16 port)** : connects to the specified host and port.

Private:
**QTcpSocket *m_socket** : Use to create the ClientSocket.

# Server side

## Core

Inherit from a QApplication.

**Core(int ac, char \**av)** : Create my server object, the graphic object. It connects the graphic view to the main.

**main(int ac, char *av[])** : Create my core object and execute it.

Private:
**GraphicSystem *_graphicSystem** : Instanciate my graphic system.

## ANetwork

This file is a abstract for the separation between my server, and the new connection or disconnection of my TcpSocket files.
It's compose of two pure virtual slots functions, reused in my server files, to manage the jsonManager.
I choose the architechture :
**First** : If i had to create a new protocol (UDP for example), it will be more easy to plug it to my server.
**Second** : Because I had a database manager, and if i want to change the json database by an sqlite database, it will be more easy.

**ANetwork()** : constructor for the ANetwork class.

**~ANetwork()*** : destructor for the ANetwork class.

Slots:
**OnNewClient(QString clientAddress)** : pure virtual slot to be implemented by derived classes to handle new client connections.

**OnDisconnected(QString clientAddress)** : pure virtual slot to be implemented by derived classes to handle client disconnections.

Protected:
**m_server** : a pointer to the QTcpServer object that manages the server-side of the network communication.
In protected because i need it in my server.

Private:
**_tcpSocket**: a pointer to a TcpSocket object that is used for communication with clients.

## TcpSocket

**TcpSocket(QTcpServer *server, QObject *parent = 0)** : constructor that takes a pointer to a QTcpServer object and an optional parent object as arguments. When TcpSocket is created in ANetwork constructor, the socket is created, and give to the TcpSocket manager.

Signals:
**newClient(QString clientAddress)** : emitted when a new client connection is established. It takes a string parameter that represents the client's IP address.

**disconnected(QString clientAddress)** : emitted when a client is disconnected. It takes a string parameter that represents the client's IP address.

Public slots:
**handleNewConnection()** : called when a new client connection is established. It creates a new QTcpSocket object for the client and adds it to the m_clients list.

**handleDisconnected()**: called when a client is disconnected. It removes the disconnected client's QTcpSocket object from the m_clients list.

Private members:
**_server** : a pointer to a QTcpServer object that represents the server.

**m_clients** : a list of QTcpSocket objects that represent the connected clients.

## Server

Inherit of ANetwork, to override the pure vituals slot functions in it, and to get the socket. Server is a QObject too because it uses slots ans signals.

**explicit Server()** : Construct the server, it listen on the IP and the port created, and receive it by the slots.

Signals:
**void jsonRefresh(QString clientAddress)** : Emit a signal to the graphic interface to refresh the display of connected users or not.

Slots:
**void OnNewClient(QString clientAddress) override** : Overrided function of ANetwork. This function call the databse manager to add a new client to the database, and set a online status to true.

**void OnDisconnected(QString clientAddress) override** : Overrided function of ANetwork. This function call the databse manager set the online status to false.

Private:
**JsonManager *m_jsonManager** : Property of jsonManager instanciate in my Server.

## ISystem

Is empty, but can be usefull if i want to create a new system like a EventSystem.

Includes my graphicSystem and called in my Core.

## GraphicSystem

Display the database.

Inherit from QWidget.

**GraphicSystem(QWidget *parent = nullptr)** : Create a window where is display the database. Is called once in the Core, then when the refresh slot function is call. 

**~GraphicSystem()** : Destroy the graphicSystem.

**void displayJsonFile(const QString &fileName, QListView *listView)** : Parse the Json and display it in a listView.

Slots:
**void refresh(QString clientAddress)** : Call GraphicSystem construtor.

## JSON

Store the data. Create an QString ipAdress[UserNumber], and a boolean online status.   