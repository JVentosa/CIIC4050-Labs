//#include "ex3.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


void decode(char* cmd){
    //TODO
    int sqrtLength = sqrt(strlen(cmd));
    if ((sqrtLength * sqrtLength) == strlen(cmd)){
        char matrix[sqrtLength][sqrtLength];

        int counter = 0;

        for (int i = 0; i < sqrtLength; i++){
            for (int j = 0; j < sqrtLength; j++){
                matrix[j][i] = cmd[counter];
                counter++;
            }
        }
                for (int i = 0; i < sqrtLength; i++){
            for (int j = 0; j < sqrtLength; j++){
                printf("%c", matrix[i][j]);
            }
        }
        printf("\n");
    }
    else{
        printf("INVALID\n");
    }
}

int main(void)
{
    // Tests Variables
    char cmd[MAX_CHARS];

    // Test 1
    strcpy(cmd, "WE OUE OUT LNGSAO H RWDN!");
    decode(cmd); // Expected: WE ARE LOW ON DOUGHNUTS !
    memset(cmd, 0, MAX_CHARS);

    // Test 2
    strcpy(cmd, "S EFEM FNOCEDROE");
    decode(cmd); // Expected: SEND MORE COFFEE
    memset(cmd, 0, MAX_CHARS);

    // Test 3
    strcpy(cmd, "CSERULES");
    decode(cmd); // Expected: INVALID
    memset(cmd, 0, MAX_CHARS);

    return 0;
}