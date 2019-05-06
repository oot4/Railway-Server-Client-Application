/* 
 * File:   filereader.cpp
 * Author: Oge Tasie
 * 
 * Description: Handles Loading in files and initializing the wagon configuration and data
 *
 * Created on 11 December 2016, 21:05
 */

#include "filereader.hpp"
#include "siding.hpp"
#include "wagon.hpp"

FileReader::FileReader( string path, int type ) {
    this->file_path = path;
    this->file_type = type;
}

void FileReader::readFile( ) {
    int max;
    int cur;
    int serial;
    string toTok;
    vector<int> c;


    //Read file based on type ie Positions file, Data file
    ifstream wagons( this->file_path );
    if ( !wagons.is_open( ) ) {
        cerr << "Can't open " << this->file_path << "!\n" << endl;
    } else {
        if ( this->file_type == 0 ) {
            while ( !wagons.eof( ) ) {
                wagons >> max;
                wagons >> cur;

                if ( wagons.eof( ) ) {
                    break;
                } else {
                    //get the current number of wagons
                    for ( int j = 0; j < cur; j++ ) {
                        wagons >> serial;
                        c.push_back( serial );
                    }

                    Siding *temp = new Siding( max, cur, c );
                    this->sidings.push_back( *temp );
                    c.clear( );
                    max = 0;
                    cur = 0;
                }
            }
        } else if ( this->file_type == 1 ) {
            while (!wagons.eof( )) {
                getline( wagons, toTok );
                boost::tokenizer<boost::escaped_list_separator<char> > tok{toTok };
                Wagon * wagon = new Wagon( tok.begin( ) );
                this->wagon_vehicles.push_back( *wagon );
            }
        } else {
            cout << "Invalid type" << endl;
        }
    }
    wagons.close( );
}

//Move wagons around

void FileReader::moveWagons( int from, int to, int amount ) {
    for ( int i = 0; i < amount; i++ ) {
        int w = sidings[from].wagonOut( );
        sidings[to].wagonIn( w );
    }

}
//Print to user

void FileReader::printSidings( ) {
    cout << "Here are the sidings:\n" << endl;
    for ( Siding s : this->sidings ) {
        s.toString( this->wagon_vehicles );
    }
}

void FileReader::graphicPrintSidings( ) {
    for ( unsigned int i = 0; i < this->sidings.capacity( ); i++ ) {
        if ( i == 0 ) {
            cout << this->sidings.at( i ).graphicString( 0 ) << "\\                  \n";
            cout << "                   \\\n";
        } else {
            cout << "                   \\" << this->sidings.at( i ).graphicString( 1 ) << "\n";
            cout << "                   \\\n";
        }
    }
}

//design load command

string FileReader::loadThis( ) {
    char value;
    string load = "load";
    for ( Siding s : this->sidings ) {
        if ( s.getCurCap( ) == 0 ) {
        } else {
            value = '0' + s.getCurCap( );
            load.push_back( ' ' );
            load.push_back( value );
        }
    }

    return load;
}
//Default

FileReader::FileReader( ) {
    this->file_path = "";
    this->file_type = 0;
}

//Delete object

FileReader::~FileReader( ) {
    this->file_path = "";
    this->file_type = -1;
    this->sidings.clear( );
}
