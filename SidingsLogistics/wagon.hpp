/* 
 * File:   wagon.hpp
 * Author: Oge Tasie
 *
 * Created on 13 December 2016, 00:49
 */

#ifndef WAGON_HPP
#define WAGON_HPP

#include "incsrc.hpp"
#include "vehicle.hpp"

class Wagon : public vehicle {
private:
    string product;

    static int num_of_wagons;
public:

    void setProduct( string s ) {
        this->product = s;
    }

    string getProduct( ) {
        return this->product;
    }

    //constructor

    Wagon( boost::tokenizer<boost::escaped_list_separator<char> >::iterator );

    //Print functions
    string toString( );
};
#endif /* WAGONS_HPP */