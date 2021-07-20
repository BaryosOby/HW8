#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "matam.h"
#include "Encoder.h"

/*in all the functions in the module
 * it been assumed that files has been opened and checked, and will be closed.*/
FILE* createOutputFile(char* inputName,char* end, char* operation) {
    char *outputName, *ext;
    FILE* outPut;
    outputName = ALLOC(char ,strlen (inputName) + 1);
    strcpy (outputName, inputName);
    ext = strrchr (outputName, '.');
    if (ext != NULL)
        strcpy(ext,end);
    outPut = fopen(outputName,operation);
    assert(outPut);
    FREE(outputName);
    return outPut ;
}


void getSentence(FILE* input,char* temp){
    char curr;
    int count =0;
    fseek(input,-1,SEEK_CUR);
    while ((curr = fgetc(input))!='.'){
        if (curr==EOF){break;}
        if (curr =='\n'|| curr==' '){
            if (count==0){continue;}
            curr=' ';}
        if (curr=='\r'){continue;}
        temp[count] = curr;
        count++;
    }
    temp[count]='\0';
}

int wordLen(char* str,int index){
    int len = 0;
    while (str[index]!=' '&& index >=0){
        len++;
        index--;
    }
    return len;
}

void printToFile(FILE* output,char* temp) {
    int index = strlen(temp)-1, currWordLen, i,strLen=index;
    char curr;
    if (index<0){return;}
    if(ftell(output) != 0){
        fputc('\n', output);
    }
    while (index >= 0) {
        currWordLen = wordLen(temp, index);
        index += -currWordLen+1;
        for (i = 0; i < currWordLen; i++) {
            curr=temp[i+index];
            fputc(curr, output);
        }
        index -= 2;
        if (index>=0){putc(' ',output);}
    }
    fputc('.',output);
    for (i=0;i<strLen;i++){temp[i]='\0';}
}

int flipFile(FILE* input,FILE* output) {
    char temp[1001];
    if (!input||!output) {
        puts("couldn't open this file");
        return -1;
    }

    while ((fgetc(input))!=EOF){
        getSentence(input,temp);
        printToFile(output,temp);

    }
    fseek(output,0,SEEK_SET);
    return 1;
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
    fseek(dest, 0, SEEK_SET);
}

void initMinOne(int* arr, int size){
    int i;
    for (i=0; i<size; i++){
        arr[i] = -1;
    }
}

int charsDict(char* line, Dict *dict, int size){
    int i = 0, count = 0;
    while(*line != '.' && count < size){
        if(dict->values[(int)*line] == -1){
            dict->keys[i] = *line;
            dict->values[(int)*line] = count;
            count++;
            i++;
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
        initMinOne((int *) &(dict.values), 256);
        memset(dict.keys, 0, MAX_CHARS);
        count = charsDict(line, &dict, MAX_CHARS);
        if(count == -1){
            perror("file cannot be encrypted. process has been stopped");
            printf("problem in line: %s", line);
            exit(1);
        }
        line[count] = '\0';
        len = strlen(line);
        encrypted = ALLOC(char, len/2);

        /*takes every two chars in values[] and creates new char from their numeric values.*/
        for(i = 0; i<len; i+=2){
            ch = (char)( (dict.values[(int)line[i]] <<4 ) + (dict.values[(int)line[i+1]] ) );
            encrypted[i] = ch;
        }
        fwrite(&count, sizeof (int), 1, dest); /*print to file count. */
        fwrite(&(dict.keys), sizeof (char), count, dest); /*print to file keys[] objects.*/
        fwrite(encrypted, sizeof (char), len/2, dest); /*print to file encrypted. */
    }
    return 1;
}



