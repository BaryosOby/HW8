#ifndef HW8_ENCODER_H
#define HW8_ENCODER_H

#define MAX_CHARS 16
#define MAX_LEN 1000
#include <stdio.h>
#include <assert.h>


/** dictionary struct is purposed to hold information about each line in the file.*/
/** chars array 'keys': holds the different chars in their order of appearance in the line.
 * a char's index is its numeric value in the specific line. */
/** int array 'values': holds the index+1 of a given char in the 'keys' array. */
/** example for the line "abfa":
 *      keys = {'a', 'b', 'f'};
 *      values[97] = 1, values[98] = 2, values[99] = 0 ... values[102] = 3;
 */
typedef struct dictionary{
    char keys[MAX_CHARS+1];
    int values[256];
}Dict;

FILE* createOutputFile(char* inputName,char* end, char* operation);

int flipFile(FILE* input,FILE* output);

void azbySwap(FILE *path, FILE *dest);

int strToBinary(FILE *path, FILE *dest);

#endif
