/* 
 * File:   siding.cpp
 * Author: Oge Tasie
 * 
 * Description: Siding representation
 *
 * Created on 13 December 2016, 00:49
 */

#include "siding.hpp"
#include "vehicle.hpp"
#include "wagon.hpp"

int Siding::num_of_sidings = 0;

Siding::Siding( int max, int cur, vector <int> c ) : maxcap( max ), curcap( cur ), config( c ) {
}

//Delete object

Siding::~Siding( ) {
    this->maxcap = -1;
    this->curcap = -1;
    this->config.clear( );
    num_of_sidings--;
}

//Default

Siding::Siding( ) {
    this->maxcap = 0;
    this->curcap = 0;
    num_of_sidings++;
}

//Print
//Could be considered as a verbose toString function.

void Siding::toString( vector<Wagon> w ) {
    cout << "Siding of " << this->maxcap << " number of wagons " << this->curcap << endl;
    if ( curcap != 0 ) {
        for ( int j : this->config ) {
            for ( Wagon ws : w ) {
                if ( ws.getSerialNumber( ) == j ) {
                    cout << ws.toString( ) << endl;
                }
            }
        }
        cout << "\n" << endl;
    } else {
        cout << "\n" << endl;
    }
}

//Stack Principle, LIFO--(Concept applied here)

string Siding::graphicString( int which_graphic ) {
    string graphic = "=";
    if ( which_graphic == 0 ) {
        for ( int j = 0; j < maxcap; j++ ) {
            if ( j < curcap ) {
                int l = this->config.at( j );
                graphic = graphic + to_string( l ) + "=";
            } else {
                graphic = graphic + "======";
            }
        }
    } else {
        for ( int i = maxcap; i > 0; i-- ) {
            if ( i <= curcap ) {
                int k = this->config.at( i - 1 );
                graphic = graphic + to_string( k ) + "=";
            } else {
                graphic = graphic + "======";
            }
        }
    }
    return graphic;
}