#include <stdio.h>
#include <stdlib.h>

extern "C" int String_length(char *chArrIn);

int main()
{
        char *inputBuffer;                                          //pointer to the input buffer
        size_t bufferSize = 32;                                     //buffer to hold the string
        size_t charCount;                                           //number of characters in the string
        
        inputBuffer = (char *)malloc(bufferSize *sizeof(char));     //get the string from the user
 
        printf("Please enter a string: ");
        getline(&inputBuffer, &bufferSize, stdin);                  //&inputBuffer = address where the string will be stored
                                                                    //&size = size of the string
        int length = String_length(inputBuffer);
        printf("The string's length is: %d \n", length);            //print the string's length
        
        return 0;
}    
