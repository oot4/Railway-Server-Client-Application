/* 
 * File:   filereader.hpp
 * Author: Oge Tasie
 * Desrciption: Defines the file reader class for reading in the siding text files.
 *
 * Created on 12 December 2016, 09:18
 */

#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <fstream>
#include "siding.hpp"
#include "wagon.hpp"

class FileReader {
private:
    string file_path;
    int file_type;

public:

    vector<Siding> sidings;
    vector<Wagon> wagon_vehicles;
    //Getters and Setters

    string getFileType( ) {
        return this->file_path;
    }

    int getFilePath( ) {
        return this->file_type;
    }

    void setFileType( int type ) {
        this->file_type = type;
    }

    void setFilePath( string path ) {
        this->file_path = path;
    }

    vector<Siding> getSidings( ) {
        return sidings;
    }

    string loadThis( );
    void moveWagons( int, int, int );

    void readFile( );
    void printSidings( );
    void graphicPrintSidings( );

    //Constructor/Destructor
    FileReader( string, int );
    FileReader( );
    ~FileReader( );
};

#endif /* FILEREADER_HPP */