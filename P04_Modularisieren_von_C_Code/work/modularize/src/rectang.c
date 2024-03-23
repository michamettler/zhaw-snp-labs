/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */
// begin students to add code for task 4.1

#include "rectang.h"

int isRightAngled(int a, int b, int c){

        int aS = a*a;
        int bS = b*b;
        int cS = c*c;
        if ((a == 0) && (b == 0) && (c == 0))
            return 0;
        else if ((aS + bS) == cS)
            return 1;
        else if ((aS + cS) == bS)
            return 1;
        else if ((bS + cS) == aS)
            return 1;
        else
            return 0;

}
// end students to add code