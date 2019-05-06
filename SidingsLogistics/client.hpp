/* 
 * File:   Client.hpp
 * Author: Oge Tasie
 * 
 * Description: Client connects to the c server and translates user messages.
 *
 * Created on 13 December 2016, 22:25
 */

#ifndef CLIENT_HPP
#define CLIENT_HPP


#include "incsrc.hpp"
#include "filereader.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstring>
#include <errno.h>
#include <sstream>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>

#define LAMBPORT 10095

class Client {
private:
    FileReader r;

    char next_move;

    int result_of;
    int client_socket;
    int continue_this;

    struct hostent *host_ptr;
    struct sockaddr_in server_socket;

public:
    void bootClient( string );

    int getCont( ) {
        return this->continue_this;
    }

    //Protocol
    void moveWagons( int, int, int );

    void sendToServer( string );
    void getInput( string );
    void recvFromServer( );
    void closeClient( );
    //    void comWithServer( );

    Client( FileReader );
};

#endif /* CLIENT_HPP */

