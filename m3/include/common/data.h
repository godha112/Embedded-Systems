/**
 * @file data.h
 * @brief this file is for doing some very basic data manipulation
 * 
 * @author Godha Lakshmi
 * @date June 28 2020
 * 
 */

#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief convert data from a standard integer type to an ASCII string'
 * 
 * All these operations are performed using pointer arithmetic, not 
 * array indexing. Input for this function is a signed 32 bit integer. All
 * bases from 2 to 16 are supported and this function can handle signed data.
 * 
 * @param data input data to be converted
 * @param ptr pointer to hold the converted string
 * @param base base of the converted data, any base from 2 to 16
 * 
 * @return the length of the converted data including the NULL terminator.
 */

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief converts data back from an ASCII represented string into as integer type.
 * 
 * All operations are performed using pointer arithmetic, not array indexing
 * Input of this function is a string which is passed as a pointer. this function
 * supports all bases from 2 to 16. This function can handle signed data.
 * 
 * @param ptr the ASCII string to be cinverted back to an integer
 * @param digits the number of digits in character set
 * @param base base of the input ptr, all bases from 2 to 16 are supported
 * 
 * @return converted 32-bit signed data.
 * 
 */

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);


#endif