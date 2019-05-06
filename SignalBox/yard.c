/* 
 * File:   RailYard.c
 * Author: Oge Tasie oot4
 * 
 * Description:
 * The Railway Yard operations are handled here
 *
 * Created on 06 December 2016
 */

#include "incsrc.h"
#include "impsrc.h"

typedef int MAXCAP;

typedef struct sidings {
    int capacity;
    int wagons;
} siding;

siding headshunt;
siding s1;
siding s2;
siding s3;

MAXCAP max;

void initialize() {
    //initialize head shunt
    max = 8;
    MAXCAP cap0 = 3;
    MAXCAP cap1 = 5;
    MAXCAP cap2 = 3;
    MAXCAP cap3 = 3;

    headshunt.capacity = cap0;
    headshunt.wagons = 0;

    //set sidings.
    s1.capacity = cap1;
    s2.capacity = cap2;
    s3.capacity = cap3;

    s1.wagons = 2;
    s1.wagons = 3;
    s1.wagons = 3;

    sendToClient("Inglenook Sidings oot4\n");
    printf("Initialized successful..\n");
}

void put(int a, int b) {
    char num = (char) ('0' + b);
    char s[60];
    switch (a) {
        case 1:
            //Check if there is enough space in sidings
            if (s1.wagons < s1.capacity && (s1.wagons + b) <= s1.capacity) {
                //Check that headshunt is not empty
                if (headshunt.wagons > 0 && (headshunt.wagons - b) >= 0) {
                    s1.wagons = s1.wagons + b;
                    headshunt.wagons = headshunt.wagons - b;
                    strcpy(s, "~Wagons moved: Status ");
                    strncat(s, &num, 1);
                    strcat(s, " REVERSE NORMAL\n");
                    sendToClient(s);
                    printf("Status 0 put in %d success..\n", a);
                } else {
                    //Error msg: Not enough wagons in headshunt
                    sendToClient("#No Wagons were moved: Status -2\n");
                    printf("Status -2 put error..\n");
                }
            } else {
                //Error msg: not enough space for wagons in sidings
                sendToClient("#No Wagons were moved: Status -1\n");
                printf("Status -1 put error..\n");
            }
            break;
        case 2:
            if (s2.wagons < s2.capacity && (s2.wagons + b) <= s2.capacity) {
                if (headshunt.wagons > 0 && (headshunt.wagons - b) >= 0) {
                    s2.wagons = s2.wagons + b;
                    headshunt.wagons = headshunt.wagons - b;
                    strcpy(s, "~Wagons moved: Status ");
                    strncat(s, &num, 1);
                    strcat(s, " NORMAL REVERSE\n");
                    sendToClient(s);
                    printf("Status 0 put in %d success..\n", a);
                } else {
                    sendToClient("#No Wagons were moved: Status -2\n");
                    printf("Status -2 put error..\n");
                }
            } else {
                sendToClient("#No Wagons were moved: Status -1\n");
                printf("Status -1 put error..\n");
            }
            break;
        case 3:
            if (s3.wagons < s3.capacity && (s3.wagons + b) <= s3.capacity) {
                if (headshunt.wagons > 0 && (headshunt.wagons - b) >= 0) {
                    s3.wagons = s3.wagons + b;
                    headshunt.wagons = headshunt.wagons - b;
                    strcpy(s, "~Wagons moved: Status ");
                    strncat(s, &num, 1);
                    strcat(s, " NORMAL NORMAL\n");
                    sendToClient(s);
                    printf("Status 0 put in %d success..\n", a);
                } else {
                    sendToClient("#No Wagons were moved: Status -2\n");
                    printf("Status -2 put error..\n");
                }
            } else {
                sendToClient("#No Wagons were moved: Status -1");
                printf("Status -1 put error..\n");
            }
            break;
        default:
            sendToClient("#No Wagons were moved: Status -3\n");
            printf("Status -3 put error..\n");

            break;
    }
}

void take(int a, int b) {
    char num = (char) ('0' + b);
    char s[60];
    switch (a) {
        case 1:
            //Check if there are enough wagons to take from sidings
            if (s1.wagons > 0 && (s1.wagons - b) >= 0) {
                //Check that headshunt is not full
                if (headshunt.wagons < headshunt.capacity && (headshunt.wagons + b) <= headshunt.capacity) {
                    s1.wagons = s1.wagons - b;
                    headshunt.wagons = headshunt.wagons + b;
                    strcpy(s, "~Wagons moved: Status ");
                    strncat(s, &num, 1);
                    strcat(s, " REVERSE NORMAL\n");
                    sendToClient(s);
                    printf("Status 0 take from %d success..\n", a);
                } else {
                    //Error msg: Not enough space in head shunt
                    sendToClient("#No Wagons were moved: Status -1");
                    printf("Status -1 take error..\n");
                }
            } else {
                //Error msg: Not enough wagons in the siding
                sendToClient("#No Wagons were moved: Status -2");
                printf("Status -2 take error..\n");
            }
            break;
        case 2:
            if (s2.wagons > 0 && (s2.wagons - b) >= 0) {
                if (headshunt.wagons < headshunt.capacity && (headshunt.wagons + b) <= headshunt.capacity) {
                    s2.wagons = s2.wagons - b;
                    headshunt.wagons = headshunt.wagons + b;
                    strcpy(s, "~Wagons moved: Status ");
                    strncat(s, &num, 1);
                    strcat(s, " NORMAL REVERSE\n");
                    sendToClient(s);
                    printf("Status 0 take from %d success..\n", a);
                } else {
                    sendToClient("#No Wagons were moved: Status -1");
                    printf("Status -1 take error..\n");
                }
            } else {
                sendToClient("#No Wagons were moved: Status -2");
                printf("Status -2 take error..\n");
            }
            break;
        case 3:
            if (s3.wagons > 0 && (s3.wagons - b) >= 0) {
                if (headshunt.wagons < headshunt.capacity && (headshunt.wagons + b) <= headshunt.capacity) {
                    s3.wagons = s3.wagons - b;
                    headshunt.wagons = headshunt.wagons + b;
                    strcpy(s, "~Wagons moved: Status ");
                    strncat(s, &num, 1);
                    strcat(s, " NORMAL NORMAL\n");
                    sendToClient(s);
                    printf("Status 0 take from %d success..\n", a);
                } else {
                    sendToClient("#No Wagons were moved: Status -1");
                    printf("Status -1 take error..\n");
                }
            } else {
                sendToClient("#No Wagons were moved: Status -2");
                printf("Status -2 take error..\n");
            }
            break;
        default:
            sendToClient("#No Wagons were moved: Status -3\n");
            printf("Status -3 take error..\n");

            break;
    }
}

void load(int a, int b, int c) {
    int i = 0;
    //Check against total wagon cap
    if ((a + b + c) > 0 && (a + b + c) <= max) {
        //Iterate through each siding
        for (i = 1; i <= 3; i++) {
            //Check against siding caps
            switch (i) {
                case 1:
                    if (a > 0 && a <= s1.capacity) {
                        s1.wagons = a;
                        //Test
                    } else {
                        //Error msg: Wagon number not between 0 and s.capacity
                        sendToClient("Wagon number for Siding 1 is not between 0 and siding capacity.\n");
                        printf("load error in siding 1..\n");
                        initialize();
                        return;
                    }
                    break;
                case 2:
                    if (b > 0 && b <= s2.capacity) {
                        s2.wagons = b;
                    } else {
                        sendToClient("Wagon number for Siding 2 is not between 0 and siding capacity.\n");
                        printf("load error in siding 2..\n");
                        initialize();
                        return;
                    }
                    break;
                case 3:
                    if (c > 0 && c <= s3.capacity) {
                        s3.wagons = c;
                    } else {
                        sendToClient("Wagon number for Siding 3 is not between 0 and siding capacity.\n");
                        printf("load error in siding 3..\n");
                        initialize();
                        return;
                    }
                    break;
                default:
                    sendToClient("Unknown error, contact administrator.\n");
                    printf("Unknown error..\n");
                    break;
            }
        }
        sendToClient("Config reset..\n");
        printf("Load successful..\n");
    } else {
        //Error msg: Too many wagons, max cap exceeded
        sendToClient("Too many wagons, max capacity exceeded.\n");
        printf("Load error invalid number of wagons..\n");
        initialize();
        return;
    }
}