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
 * @file stats.h
 * @brief performs statistical analysis on the data given as input
 *
 *
 * @author Godha Lakshmi
 * @date 12-06-2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

 /**
 * @brief given an array and its length
 *
 * this function prints all the statistical
 * data of the elements present in the array
 *
 * @param test an array
 * @param Size length of the array
 *
 *
 * @return NULL
 */

 void print_statistics(unsigned char test[], unsigned int Size);

 /**
 * @brief given an array and its length
 *
 * this function prints all the elemnts
 * of the given array
 *
 * @param test an array
 * @param Size length of the array
 *
 *
 * @return NULL
 */

 void print_array(unsigned char test[], unsigned int Size);

/**
 * @brief given an array and its length
 *
 * this function outputs the mean of the
 * the elements present in the array
 *
 * @param test an array
 * @param Size length of the array
 *
 *
 * @return mean of the dataset
 */

  unsigned char find_mean(unsigned char test[], unsigned int Size);

/**
 * @brief given an array and its length
 *
 * this function outputs the median of the
 * the elements present in the array
 *
 * @param test an array
 * @param Size length of the array
 *
 *
 * @return median of the dataset
 */

  unsigned char find_median(unsigned char test[], unsigned int Size);

/**
 * @brief given an array and its length
 *
 * this function returns the largest
 * number of the array
 *
 * @param test an array
 * @param Size length of the array
 *
 *
 * @return maximum of the elements of the array
 */

  unsigned char find_maximum(unsigned char test[], unsigned int Size);

/**
 * @brief given an array and its length
 *
 * this function returns the smallest
 * number of the array
 *
 * @param test an array
 * @param Size length of the array
 *
 *
 * @return minimum of the elements of the array
 */

  unsigned char find_minimum(unsigned char test[], unsigned int Size);

/**
 * @brief given an array and its length
 *
 * this function sorts the elements of
 * the array in descending order
 *
 * @param test an array
 * @param Size length of the array
 *
 *
 * @return NULL
 */

  void sort_array(unsigned char test[], unsigned int Size);

#endif /* __STATS_H__ */
