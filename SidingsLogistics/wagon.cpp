/* 
 * File:   wagon.cpp
 * Author: Oge Tasie
 * 
 * Description Wagon representation
 *
 * Created on 13 December 2016, 00:49
 */

#include "wagon.hpp"

int Wagon::num_of_wagons = 0;
//Constructor

Wagon::Wagon( boost::tokenizer<boost::escaped_list_separator<char> >::iterator data ) : vehicle( data ) {
    product = *data;
    if ( product.at( 0 ) == ' ' )
        product.replace( 0, 1, "" );

    num_of_wagons++;
}

//Print to user

string Wagon::toString( ) {
    string wmsg = this->streamHelper( );

    wmsg = wmsg + " " + this->product;
    return wmsg;
}