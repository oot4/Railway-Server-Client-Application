/* 
 * File:   impsrc.h
 * Author: Oge Tasie oot4
 *
 * Description:
 * Implementation source file.
 * 
 * Created on 06 December 2016
 */

#ifndef IMPSRC_H
#define IMPSRC_H

#ifdef __cplusplus
extern "C" {
#endif

    int getServerStatus( );
    int bootServer( );
    void closeServer( );

    void sendToClient( );
    void recvFromClient( );

    int isRunning( );

    void initialize( );
    void put( int a, int b );
    void take( int a, int b );
    void load( int a, int b, int c );

#ifdef __cplusplus
}
#endif

#endif /* IMPSRC_H */

