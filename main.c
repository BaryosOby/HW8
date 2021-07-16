#include <stdio.h>
#include "Encoder.h"

void writeBin(FILE *dest){
    int i;
    for(i = 0; i<5; i++){
        fwrite(&i, sizeof(int), 1, dest);
    }
}

void readBin(FILE *dest){
    int i;
    while(fread(&i, sizeof(int), 1, dest) == 1){
        printf("%d\n", i);
    }

}




int main() {
    FILE * writeFile = fopen("/home/baryos/.config/JetBrains/CLion2020.3/scratches/writeTo.txt","w+");
    FILE * readFile = fopen("/home/baryos/.config/JetBrains/CLion2020.3/scratches/read_from.txt", "r");

    wordsSwap(readFile,writeFile);
    azbySwap(readFile, writeFile);

    fclose(readFile);
    fclose(writeFile);

//    if (writeFile != NULL)
//    {
//        writeBin(writeFile);

        //test int vars
//        int test1 = 1;
//        int test2 = 2;
//        int test3 = 3;
//
//        //writing some ints to binary file
//        fwrite(&test1,sizeof(test1),1, writeFile);
//        fwrite(&test2,sizeof(test2),1, writeFile);
//        fwrite(&test3,sizeof(test3),1, writeFile);

//        fclose(writeFile);
//    }
//    else
//    {
//        perror("Error opening file to write: ");
//        return 1;
//    }
//
//
//    FILE *readFile = fopen("test.bin","rb");
//    if (readFile != NULL)
//    {

//        readBin(readFile);
//        int data;
//        while(fread(&data,sizeof(data),1, readFile)==1){
//            printf("%d\n", data);
//        }
//        fclose(readFile);
//    }
//    else
//    {
//        perror("Error opening file to read: ");
//        return 1;
//    }

    return 0;

}
