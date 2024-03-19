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
#ifndef READ_H
#define READ_H
int getInt(int maxResult);

// end of input
#define EOF   (-1) // end of file
#define EOL   10 // end of line
// abnormal return values
#define PARSE_ERROR (-1)
#define READ_ERROR   (-2)
// ASCII Codes
#define ASCII_SPACE    32 // ' '
#define ASCII_DIGIT_0  48 // '0'
#define ASCII_DIGIT_9  57 // '9'

// conversion buffer
#define NO_POS (-1)
#define BUFFERSIZE  10
#endif
// end students to add code