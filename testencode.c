/*
Name                    : Uday KUmar K p
Date                    : 04-08-2023
Project Name            : LSB image steganography
File	                  : test_encode.c file
*/
//preprocessor directives
#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "decode.h"
#include "types.h"


//Main function with arguments passed through command line after successful execution returning integer value
int main(int argc, char **argv)
{
    //Checking if encoding chosen by user
    if (check_operation_type(argv) == e_encode)
    {
        printf("\nSelected encoding\n");
        EncodeInfo encInfo;            //declaring variable 'encInfo' which is typedef with structure EncodeInfo

        //Checking if all arguments are correctly passed through command line for encoding
        if (read_and_validate_encode_args(argv, &encInfo) == e_success)
        {
            printf("Read and validate is successful\n");
            //Checking if Encoding secret data is success or not
            if (do_encoding(&encInfo) == e_success)
            {
                printf(".............Encoding completed................\n\n");
            }
            else
            {
                printf("Encoding was failure\n");
            }
        }
        else
        {
            printf("Read and validate was not successful\n");
            return 1;
        }
    }
    //Checking if decoding chosen by user
    else if (check_operation_type(argv) == e_decode)
    {
        printf("\nSelected decoding\n");
        DecodeInfo decInfo;            //Declaring variable 'decInfo' which is typedef with structure DecodeInfo

        //Checking if all arguments are correctly passed through command line for decoding
        if (read_and_validate_decode_args(argv, &decInfo) == e_success)
        {
            printf("Read and validate is successful\n");

            //Checking if Decoding secret data is success or not
            if (do_decoding(&decInfo) == e_success)
            {
                printf("................Decoding completed................\n\n");
            }
            else
            {
                printf("Decoding was failure\n");
                return e_failure;
            }
        }
        else
        {
            printf("Read and validate was not successful\n");
            return e_failure;
        }
    }
    else
    {
        printf("Invalid input\nPlease pass\nEncoding: ./a.out -e beautiful.bmp secret.txt stego.bmp\nDecoding: ./a.out -d stego.bmp decode.txt\n");    //if arguments are not correctly passed
        return e_failure;
    }
}


//Defining function to check if the second argument passed through command line specifies encoding or decoding
OperationType check_operation_type(char *argv[])
{
    //Checking if the argument is for encoding 
    if ((strcmp(argv[1],"-e")) == 0)
    {
        return e_encode;               //Start to perform encoding
    }
    //Checking if the argument is for decoding 
    else if ((strcmp(argv[1], "-d")) == 0)
    {
        return e_decode;               //Start to perform decoding
    }
    else
    {
        return e_unsupported;          //Invalid
    }
}