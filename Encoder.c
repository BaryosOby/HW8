#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "matam.h"
#include "Encoder.h"

/*in all the functions in the module
 * it been assumed that files has been opened and checked, and will be closed.*/


FILE* createOutPutFile(char* inputName) {
    char *outputName, *ext;
    FILE* outPut;
    outputName = ALLOC(char ,strlen (inputName) + 1);
    strcpy (outputName, inputName);
    ext = strrchr (outputName, '.');
    if (ext != NULL)
        strcpy(ext,".rpl");
    outPut = fopen(outputName,"w");
    FREE(outputName);
    return outPut ;
}


/*help function to find a word's length*/
int wordLen(FILE *path, long *start){
    /*word is defined as all characters between white space, including separators.
     * if we are here, no periods should be found.*/
    char c;
    int len = 0;
    fseek(path, -1, SEEK_CUR);
    c = fgetc(path); /*gets the last char that is not a period*/
    while(c != ' ' && c!= '\n'){
        fseek(path, -1, SEEK_CUR);
        if(ftell(path) == 0){ /*check for the last char (the first in original file)*/
            len++;
            *start = 0; /*finish to read the file.*/
            break;
        }
        fseek(path, -1, SEEK_CUR);
        c = fgetc(path);
        len++;
    }

    return len;
}

void wordsSwap(FILE *path, FILE *dest){
    File output = char c;
    bool flag = false;
    long start;
    int count, i;
    fseek(path, -1, SEEK_END); /*one step back from EOF*/
    start = ftell(path);
    while(start != 0){
        c = fgetc(path);
        if(c == '.'){
            if(flag == true){
                fputc(c, dest); /*will put a period in the end of every new sentence, and go down a line.*/
                fputc('\n', dest);
            }
            else{
                flag= true;
            }
            fseek(path, -2, SEEK_CUR);
        }
        else {
            count = wordLen(path, &start);
            c = fgetc(path);
            for (i = 0; i < count; i++) { /*writes the word by its length*/
                fputc(c, dest);
                c = fgetc(path);
            }
            fputc(' ', dest);
            fseek(path, -(count + 3), SEEK_CUR); /*jumps to the previous word.*/
        }
    }
}


void azbySwap(FILE *path, FILE *dest){
    /*the function runs from two directions until half point.
     * in every iteration it writes the char which is in the 'i' distance from both directions.*/
    int i;
    char c;
    long halfPoint, endText;
    fseek(path, 0, SEEK_END);
    endText = ftell(path);
    halfPoint = (endText/2);  /*finds the half point of the text*/
    for(i= 0; i < halfPoint; i++){
        /*writes the i char from beginning*/
        fseek(path, i, SEEK_SET);
        c = fgetc(path);
        fputc(c, dest);
        /*writes the i char from end of text*/
        fseek(path, -(1+i), SEEK_END);
        c = fgetc(path);
        fputc(c, dest);
    }
    /*writes the middle char*/
    if(endText % 2 != 0){
        fseek(path, i, SEEK_SET);
        c = fgetc(path);
        fputc(c, dest);
    }
}

bool isInArr(char ch, char arr[], int size){
    int i;
    for(i = 0; i<size; i++){
        if(arr[i] == ch){
            return true;
        }
    }
    return false;
}

int charsDict(char* line, Dict *dict, int size){
    int i, count = 0;
    while(*line != '.' || count < size){
        for(i=0; i<size; i++){
            if(dict->values[*line] == 0){
                count++;
                dict->keys[i] = *line;
                dict->values[*line] = count;
            }
        }
        line++;
    }
    dict->keys[count] = '\0';
    return (*line == '.') ? count : -1;
}

int strToBinary(FILE *path, FILE *dest){
    int count, len, i;
    char line[MAX_LEN+1], *encrypted, ch;
    Dict dict;
    while(fgets(line, MAX_LEN, path)) {
        memset(dict.values, 0, 256);
        memset(dict.keys, 0, MAX_CHARS);
        count = charsDict(line, &dict, MAX_CHARS);
        if(count == -1){
            perror("file cannot be encrypted. process has been stopped");
            printf("problem in line: %s", line);
            exit(1);
        }
        len = strlen(line);
        encrypted = ALLOC(char, len/2);

        /*takes every two chars in values[] and creates new char from their numeric values.*/
        for(i = 0; i<len; i+=2){
            ch = (char)( ((dict.values[line[i]] -1) <<4 ) + (dict.values[line[i+1]] -1) );
            encrypted[i] = ch;
        }
        ch = '\n';
        fwrite(&count, sizeof (int), 1, dest); /*print to file count. */
        fwrite(&(dict.keys), sizeof (char), count, dest); /*print to file keys[] objects.*/
        fwrite(encrypted, sizeof (char), len/2, dest); /*print to file encrypted. */
        fwrite(&ch, sizeof (char), 1, dest); /*go down a line. */
    }
}



