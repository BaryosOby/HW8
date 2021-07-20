#include "Encoder.h"


int main() {

    FILE* readFile;
    FILE* flipped;
    FILE* azbySwapped;
    FILE* binaryEncripted;

    readFile = fopen("/home/baryos/.config/JetBrains/CLion2020.3/scratches/read_from.txt", "r");
    assert(readFile);

    flipped = createOutputFile("readFrom.txt", ".rpl", "w+");
    flipFile(readFile, flipped);

    azbySwapped = createOutputFile("readFrom.txt", ".bend", "w+");
    azbySwap(flipped, azbySwapped);

    binaryEncripted = createOutputFile("readFrom.txt", ".rds", "wb");
    strToBinary(azbySwapped, binaryEncripted);

    fclose(readFile);
    fclose(flipped);
    fclose(azbySwapped);
    fclose(binaryEncripted);

    return 0;

}
