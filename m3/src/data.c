/**
 * @file data.h
 * @brief this file is for doing some very basic data manipulation
 * 
 * @author Godha Lakshmi
 * @date June 28 2020
 * 
 */


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    int negative = -1;
    int length = 0;
    int digit; 
    if(data == 0){
        *ptr = 48;
        return length;
    }
    else{
        negative = 1;
        data *= -1;
    }

    while(data != 0){
        digit = data % base;
        data /= base;

        if(digit>9){
            *(ptr + length) = digit + 55;
        }
        else
        {
            *(ptr + length) = digit + 48;
        }
        length++;
    }

    *(ptr + length) = "\0";

    if(negative){
        my_memmove(ptr, ptr+1, length);
        *ptr = 45;
        length++;
    }

    return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    int negative = -1;
    int power = 1;
    int num = 0, temp = 0;

    for(int i = digits-1; i >= 0; i++){
        if(*(ptr + i) == '-'){
            negative = 1;
        }
        if(*(ptr + i)>9){
            temp = int(*(ptr + i)) - 55;
            num += power * temp;
        }
        else{
            temp = int(*(ptr+i)) - 48;
            num += power * temp;
        }
        power = power*base;
        if(negative){
            num = num * -1;
        }
        return num;
    }



}