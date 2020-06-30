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
 * @file stats.c
 * @brief performs statistical analysis on a dataset which is an array of
 *
 * unsigned chars
 *
 * @author Godha Lakshmi
 * @date 12-06-2020
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

/*int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};*/

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  /*print_statistics(test, SIZE);
  
  return 0;


}*/

/* Add other Implementation File Code Here */

void print_statistics(unsigned char test[], unsigned int len){

    PRINTF("the input array - \n\n");
    print_array(test, len);

    sort_array(test, len);
    PRINTF("the sorted array - \n\n");
    print_array(test, len);

    unsigned char mean = find_mean(test, len);
    unsigned char median = find_median(test, len);
    unsigned char maximum = find_maximum(test, len);
    unsigned char minimum = find_minimum(test, len);

    PRINTF("the mean of the given array = %d\n\n", mean);
    PRINTF("the median of the given array = %d\n\n", median);
    PRINTF("the maximum element of the given array = %d\n\n", maximum);
    PRINTF("the minimum element of the given array = %d\n\n", minimum);

}

void print_array(unsigned char test[], unsigned int len){
    #ifdef VERBOSE
    int i = 0, j = 0;
    for(i = 0; i<len/8; i++){
        for(j = 0; j<len/5; j++){
            PRINTF("%3d ", test[(8*i)+j]);
        }
        PRINTF("\n");
    }
    PRINTF("\n");

    #endif
}

unsigned char find_mean(unsigned char test[], unsigned int len){
    unsigned int sum = 0;
    int i = 0;

    for(i = 0; i<len; i++){
        sum += test[i];
    }

    unsigned char mean = sum/len;

    return mean;
}

unsigned char find_median(unsigned char test[], unsigned int len){
    int middle_element;
    unsigned char median;
    if(len%2 != 0){
        middle_element = (len-1)/2;
        median = test[middle_element];
    }
    else{
        middle_element = (len-1)/2;
        median = (test[middle_element]+test[middle_element+1])/2;
    }

    return median;
}

unsigned char find_maximum(unsigned char test[], unsigned int len){
    return(test[0]);
}

unsigned char find_minimum(unsigned char test[], unsigned int len){
    return(test[len-1]);
}

void sort_array(unsigned char test[], unsigned int len){
    unsigned int temp = 0;
    int i = 0, j = 0;

    for(i = 0; i<len; i++){
        for(j = i; j>0; j--){
            if(test[j]>test[j-1]){
                    temp = test[j];
                    test[j] = test[j-1];
                    test[j-1] = temp;
            }
        }
    }
}

