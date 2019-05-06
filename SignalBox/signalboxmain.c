/* 
 * File:   SignalBoxMain.c
 * Author: Oge Tasie oot4
 * 
 * Description: 
 * Main Method. Separated from rest of code for clarity.
 *
 * Created on 06 December 2016
 */

#include "incsrc.h"
#include "impsrc.h"

int main(int argc, char** argv) {

    int server_running;
    //    bool canExit = false;
    char buffer[10];

    //Initialise
    server_running = bootServer();
    initialize();

    //communicate

    while (server_running > 0) {
        do {
            recvFromClient();
            *buffer = '#';
        } while (*buffer != '#');
        server_running = getServerStatus();
    }

    closeServer();
    return (EXIT_SUCCESS);
}