/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stdlib.h>
/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief This function moves data from source to destination
 * 
 * This function takes two byte pointers (one source and one 
 * destination)  and a length of bytes to move from the source
 * location to the destination.It is capable pf handling overlap 
 * of source and destination, by copying with no data corruption.
 * All operations are performed using pointer arithmetic, not
 * array indexing
 * 
 * @param src pointer to the source
 * @param dst pointer to the destination
 * @param length length of tje bytes to be moved
 * 
 * @return pointer to the destination(dst)
 */

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief This function copies data from source to destination
 * 
 * This function takes two byte pointers (one source and one 
 * destination) and a length of bytes to copy from the source 
 * location to the destination. The behavior is undefined if 
 * there is overlap of source and destination. Copy should still 
 * occur, but will likely corrupt your data. All operations need
 *  to be performed using pointer arithmetic, not array indexing.
 * 
 * @param src pointer to the source
 * @param dst pointer to the destination
 * @param length length of bytes to be copied
 * 
 * @return pointer to the destination(dst).
 */

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/** 
 * @brief This function set a length of memory to a particular value
 *
 * This function takes a pointer to a source memory location, a length
 * in bytes and set all locations of that memory to a given value. All
 * operations are performed using pointer arithmetic, not array indexing.
 * 
 * @param src pointer to the source
 * @param length length of bytes to be replaced by a value
 * @param value the value to be set
 */

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief This function sets a length od bytes in source data to zero.
 * 
 * This function takes a pointer to a memory location, a length in bytes
 * and zero out all of the memory. All the operations are perfprmed using 
 * pointer arithmetic, not array indexing.
 * 
 * @param src pointer to the source
 * @param length length of the memory segment
 * 
 * @return pointer to the source(src);
 */

uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief This function reverse the order of all bytes of particular length
 *  
 * This function takes a pointer to a memory location and a length in bytes
 * and reverse the order of all of the bytes. All operations are performed in 
 * pointer arithmetic, not array indexing.
 * 
 * @param src pointer to the source
 * @param length length of the memory segment
 * 
 * @return pointer to the source(src)
 */

uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief This function allocates certain number of words in dynamic memory
 * 
 * This function takes a number of words to be allocated in dynamic memory. 
 * All operations are performed in pointer artithmetic and not array indexing.
 * 
 * @param length length of the memory to be allocated in dynamic memory
 * 
 * @return pointer to the memory if successful, or a Null pointer if not successful
 */

int32_t * reserve_words(size_t length);

/**
 * @brief this function free a dynamic memory allocation
 * 
 * When given the pointer to the source of a dynamic memory
 * allocation this function frees the dynamically allocated memory. All operations
 * are performed in pointer arithmetic not array indexing.
 * 
 * @param src pointer to the dynamically allocated memory
 * 
 * @return NULL
 * 
 */

void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
