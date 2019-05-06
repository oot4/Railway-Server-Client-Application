/* 
 * File:   Client.hpp
 * Author: Oge Tasie
 * 
 * Description: includes client.hpp (Inspired by Dave Price Lamb reader program
 *
 * Created on 13 December 2016, 22:25
 */

#include "client.hpp"
#include "filereader.hpp"

//Default

Client::Client( FileReader reader ) {
    this->r = reader;
}
//----------

void Client::bootClient( string name ) {

    //Get host name
    this->host_ptr = gethostbyname( name.c_str( ) );
    if ( this->host_ptr == NULL ) {
        this->continue_this = 0;
        perror( "Server Name.." );
    }

    //Set socket
    this->server_socket.sin_family = AF_INET;
    this->server_socket.sin_addr.s_addr = INADDR_ANY;
    this->server_socket.sin_port = htons( LAMBPORT );

    this->client_socket = socket( AF_INET, SOCK_STREAM, 0 );

    //server
    if ( this->client_socket < 0 ) {
        this->continue_this = 0;
        perror( "socket_fd.." );
    }

    if ( connect( this->client_socket, ( struct sockaddr* ) & this->server_socket, sizeof (this->server_socket ) ) < 0 ) {
        this->continue_this = 0;
        perror( "Socket.." );
    }

    this->continue_this = 1;
}
//Handles the user inputs, uses Boost Library

void Client::getInput( string user_input ) {
    vector<int> arguments;

    int num_args = 0;
    int siding1;
    int siding2;
    int move_these;

    boost::char_separator<char> s( "\r\n,.- " );
    boost::tokenizer < boost::char_separator<char> > t( user_input, s );

    //    get all the integer arguments from the user

    BOOST_FOREACH( const string &input, t ) {
        int argument;
        if ( stringstream( input ) >> argument )
            arguments.push_back( argument );
        num_args++;
    }


    //Exit Command
    if ( user_input.compare( "exit" ) == 0 ) {
        this->continue_this = 0;
        sendToServer( "exit" );
    } else {
        //    translate the commands
        if ( num_args == 3 ) {
            siding1 = arguments[0];
            siding2 = arguments[1];
            move_these = arguments[2];
            moveWagons( siding1, siding2, move_these );
            sendToServer( "-" );

        } else {
            sendToServer( "-" );
        }
    }
}

//Wagon moves

void Client::moveWagons( int from, int to, int amount ) {
    string take = "take";
    string put = "put";
    char f = '0' + from;
    char t = '0' + to;
    char a = '0' + amount;

    //move operations
    //Headshunt moves from
    if ( from == 0 && to > 0 && amount > 0 ) {
        put.push_back( ' ' );
        put.push_back( t );
        put.push_back( ' ' );
        put.push_back( a );
        cout << "Moving: " << a << " wagons from siding: " << f << " to siding: " << t << endl;
        cout << "Sent SBP: " << put << endl;
        sendToServer( put );
        recvFromServer( );
        if ( this->next_move == '~' ) {
            this->r.moveWagons( from, to, amount );
            this->r.printSidings( );
            this->r.graphicPrintSidings( );
        }
        //headshunt moves to
    } else if ( to == 0 && from > 0 && amount > 0 ) {
        take.push_back( ' ' );
        take.push_back( f );
        take.push_back( ' ' );
        take.push_back( a );
        cout << "Moving: " << a << " wagons from siding: " << f << " to siding: " << t << endl;
        cout << "Sent SBP: " << take << endl;
        sendToServer( take );
        recvFromServer( );
        if ( this->next_move == '~' ) {
            this->r.moveWagons( from, to, amount );
            this->r.printSidings( );
            this->r.graphicPrintSidings( );
        }
        //all other moves
    } else if ( from > 0 && to > 0 && amount > 0 ) {
        take.push_back( ' ' );
        take.push_back( f );
        take.push_back( ' ' );
        take.push_back( a );
        put.push_back( ' ' );
        put.push_back( t );
        put.push_back( ' ' );
        put.push_back( a );
        cout << "Moving: " << a << " wagons from siding: " << f << " to siding: " << t << endl;
        cout << "Sent SBP: " << take << endl;
        cout << "Sent SBP: " << put << endl;
        sendToServer( take );
        recvFromServer( );
        //ensure that wagons are reset after invalid move
        //no matter the number of move operations
        if ( this->next_move == '~' ) {
            sendToServer( put );
            recvFromServer( );
            if ( this->next_move == '#' ) {
                cout << "Undoing previous move.." << endl;
                put = "put";
                put.push_back( ' ' );
                put.push_back( f );
                put.push_back( ' ' );
                put.push_back( a );
                sendToServer( put );
            } else {
                this->r.moveWagons( from, to, amount );
                this->r.printSidings( );
                this->r.graphicPrintSidings( );
            }
        }
        //exit ? command(Warning, SBP takes this command in, a work in progress.)
        //exit command moved to getInput()
    } else if ( from == 0 && to == 0 && amount == 0 ) {
        //        this->continue_this =0;
        //Throw a warning on invalid command
        cout << "Invalid Command" << endl;
    } else if ( from == 0 && to == 0 && amount > 0 ) {
        cout << "Invalid Command" << endl;
    } else {
        cout << "Invalid Command" << endl;
    }
}

void Client::sendToServer( string msg ) {
    unsigned int len = msg.length( );
    if ( send( this->client_socket, msg.c_str( ), msg.length( ), 0 ) != len ) {
        this->continue_this = 0;
        perror( "Error sending to client.." );
    }
}

void Client::recvFromServer( ) {
    int reader;
    char buffer[1024];
    if ( ( reader = recv( client_socket, &buffer, 1024, 0 ) ) < 0 ) {
        this->continue_this = 0;
        perror( "Error receiving from client.." );
    }

    //syntax
    buffer[reader] = '\0';
    if ( buffer[0] == '~' || buffer[0] == '#' ) {

        this->next_move = buffer[0];
        buffer[0] = ' ';
    }
    //print message from server
    cout << buffer << endl;
}

void Client::closeClient( ) {
    close( client_socket );
}
//Test:working ? 
//void Client::comWithServer( ) {
//    char buffer[buf_size];
//    //Recieving messages
//    recv( this->client, buffer, this->buf_size, 0 );
//
//    do {
//        //Send to server
//        do {
//            send( this->client, buffer, this->buf_size, 0 );
//
//            if ( *buffer == '~' ) {
//
//            }
//        } while ( *buffer != '$' );
//
//        //recv from server
//        do {
//            recv( this->client, buffer, this->buf_size, 0 );
//
//            if ( *buffer == '~' ) {
//                *buffer = '*';
//                this->canExit = true;
//            }
//        } while ( *buffer != '$' );
//    } while ( !this->canExit );
//
//    close( this->client );
//}