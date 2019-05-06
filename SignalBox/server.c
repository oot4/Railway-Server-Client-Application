/*
 * File:   Server.c
 * Author: Oge Tasie oot4
 * 
 * Description:
 * The server is created and maintained here. This code is based off Dave Price 
 * Lamb Poem Service Program.
 * 
 * Created on 06 December 2016
 */
#include "incsrc.h"
#include "impsrc.h"

#define LAMBPORT 10095

int new_server;
int new_client;

typedef int cmd_arg;

//Boot

int bootServer() {
    //Initialisation
    //-------------------
    struct sockaddr_in server;
    unsigned int add_len;

    printf("Creating new socket..\n");
    //Create socket.
    //-------------------
    if ((new_server = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        //Error handling
        closeServer();
        perror("Socket..");
    }

    int reuse;
    if (setsockopt(new_server, SOL_SOCKET, SO_REUSEADDR, (char*) &reuse, sizeof (reuse)) == 1) {
        closeServer();
        perror("setsockopt -- REUSEADDR");
    }

    printf("Binding socket..\n");
    //Setup master socket
    //-------------------
    //Set socket
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(LAMBPORT);
    //Bind to LAMBPORT(Error Handling)
    if (bind(new_server, (struct sockaddr *) &server, sizeof (server)) < 0) {
        closeServer();
        perror("Bind..");
    }

    printf("Listening for connections..\n");
    if (listen(new_server, 1) < 0) {
        closeServer();
        perror("Listen....");
    }

    //Accept Connection
    //-------------------
    //Initialise
    add_len = sizeof (struct sockaddr_in);
    if ((new_client = accept(new_server, (struct sockaddr *) &server, &add_len)) < 0) {
        closeServer();
        perror("Accept....");
    }

    //Test
    //printf("New socket is %d\n", new_client);
    //printf("Master socket is %d\n", new_server);
    printf("Connection accepted..\n");
    printf("Signal Box running..\n");
    return new_server;
}

//Send

void sendToClient(char *msg) {
    printf("Sending message..\n");

    if (send(new_client, msg, strlen(msg), 0) != strlen(msg)) {
        closeServer();
        perror("Error sending to client..");
    } else {
        printf("Message sent successfully..\n");
    }
}

//Receive

void recvFromClient() {
    int reader, count = 0;
    char buffer[20];
    char *ptr_buffer;
    char cmd[4][5] = {"", "", "", ""};
    cmd_arg argn1 = 0, argn2 = 0, argn3 = 0;

    printf("Receiving message from client..\n");
    //Get msg
    if ((reader = recv(new_client, &buffer, 1024, 0)) < 0) {
        closeServer();
        perror("Error receiving from client..");
    } else {
        printf("Message received..\n");
    }
    //Break the string to get the command
    buffer[reader] = '\0';
    ptr_buffer = strtok(buffer, " .,-");

    memset(cmd, '\0', sizeof (cmd));

    while (ptr_buffer != NULL && count < 4) {
        strcpy(cmd[count], ptr_buffer);
        ptr_buffer = strtok(NULL, " ,.-");
        count++;
    }

    //Perform actions based on command
    if (strncmp(cmd[0], "load", 4) == 0) {
        argn1 = atoi(cmd[1]);
        argn2 = atoi(cmd[2]);
        argn3 = atoi(cmd[3]);

        //Load command
        if (argn1 != 0 && argn2 != 0 && argn3 != 0) {
            sleep(1);
            load(argn1, argn2, argn3);
        } else {
            sendToClient("Status -4\n");
            printf("Status -4 command not recognized..\n");
        }
    } else if (strncmp(cmd[0], "take", 4) == 0) {
        argn1 = atoi(cmd[1]);
        argn2 = atoi(cmd[2]);

        //Take command
        if (argn1 != 0 && argn2 != 0) {
            take(argn1, argn2);
        } else {
            sendToClient("Status -4\n");
            printf("Status -4 command not recognized..\n");
        }
    } else if (strncmp(cmd[0], "put", 3) == 0) {
        argn1 = atoi(cmd[1]);
        argn2 = atoi(cmd[2]);

        //Put command
        if (argn1 != 0 && argn2 != 0) {
            put(argn1, argn2);
        } else {
            sendToClient("Status -4\n");
            printf("Status -4 command not recognized..\n");
        }
    } else if (strncmp(cmd[0], "exit", 4) == 0) {
        closeServer();
    } else {
        sendToClient("<<<<---->>>>\n");
        printf("Status -4 command not recognized or end of line..\n");
    }
    //Test
    //for (int i = 0; i < count; i++) {
    //printf("%s\n", cmd[i]);
    //}
}

//Check if program is running

int getServerStatus() {
    return new_server;
}

//Close socket

void closeServer() {
    printf("Connection closing..\n");
    close(new_server);
    new_server = -1;
    printf("Connection closed..\n");
}

