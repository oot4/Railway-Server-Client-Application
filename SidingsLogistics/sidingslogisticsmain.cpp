/* 
 * File:   sidingslogisticsmain.cpp
 * Author: Oge Tasie
 * 
 * Description:
 * Main c++ file, handles main operations between the program and user.
 * Note: This program is unable to hold more than 3 sidings. (implementation coming soon).
 *
 * Created on 11 December 2016, 21:05
 */

#include "filereader.hpp"
#include "client.hpp"

int main( int argc, char** argv ) {
    string line;

    //Previous Algorithm Work:working ?
    //    bool canExit = false;
    //    char theEnd = ' ';


    //CanTest:File Reading and Client work work independently but are mutual
    //Read in the wagon data and positions
    FileReader fr( "wagon_positions.txt", 0 );
    fr.readFile( );
    fr.setFilePath( "wagon_data.txt" );
    fr.setFileType( 1 );
    fr.readFile( );

    //Port connection
    Client cl( fr );
    cl.bootClient( "localhost" );
    cl.recvFromServer( );
    //Initialize the wagon config
    cl.sendToServer( fr.loadThis( ) );
    cl.recvFromServer( );
    //Communication
    fr.printSidings( );
    fr.graphicPrintSidings( );
    for (;; ) {
        getline( cin, line );
        cl.getInput( line );
        cl.recvFromServer( );
        if ( cl.getCont( ) == 0 )
            break;
    }

    cl.closeClient( );
    return 0;
}

//Test:working ?
//    Siding Class Test:*put in main to test*
//    int i = 11111, j = 22222;
//    std::vector<int>::iterator it;
//    std::vector<int> shit;
//
//    shit.push_back( i );
//    shit.push_back( j );
//
//    Siding siding( 5, 2, shit );
//    siding.toString( );
//    for ( it = shit.begin( ); it < shit.end( ); it++ )
//        std::cout << ' ' << *it;
//    std::cout << '\n';