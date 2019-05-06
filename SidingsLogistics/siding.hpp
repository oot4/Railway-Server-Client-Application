/* 
 * File:   siding.hpp
 * Author: Oge Tasie
 *
 * Created on 12 December 2016, 10:26
 */

#ifndef SIDING_HPP
#define SIDING_HPP

#include "incsrc.hpp"
#include "wagon.hpp"

class Siding {
private:
    int maxcap;
    int curcap;
    vector<int> config;

    //Keep track of number of sidings
    static int num_of_sidings;
public:
    //Getters and Setters

    void setMaxCap( int max ) {
        this->maxcap = max;
    }

    void setCurCap( int cur ) {
        this->curcap = cur;
    }

    void setConfig( vector<int> c ) {
        this->config = c;
    }

    vector<int> getConfig( ) {
        return this->config;
    }

    int getMaxCap( ) {
        return this->maxcap;
    }

    int getCurCap( ) {
        return this->curcap;
    }

    int wagonOut( ) {
        int r = config.back( );
        curcap--;
        config.pop_back( );
        return r;
    }

    void wagonIn( int w ) {
        config.push_back( w );
        curcap++;
    }

    //Constructors/Destructor
    Siding( int, int, vector<int> );
    Siding( );
    ~Siding( );

    //Static Methods

    static int getNumOfSidings( ) {
        return num_of_sidings;
    }

    //Returns Siding Capacity, and current wagons in siding.
    //Returns Wagon details
    void toString( vector<Wagon> );
    string graphicString( int );
};

#endif /* SIDING_HPP */