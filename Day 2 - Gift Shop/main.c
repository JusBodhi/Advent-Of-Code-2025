#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/stat.h>

typedef struct
{
    char min[12];
    char max[12];
} Range;

typedef struct
{
    FILE* filePtr;
    size_t fileSize;
} FileInfo;

FileInfo GetInputFileInfo()
{
    FILE* fptr = fopen("E:\\Coding\\Advent-Of-Code-2025\\Day 2 - Gift Shop\\input.txt", "r");

    if (fptr == NULL)
    {
        printf("File could not be opened\n");
        exit(1);
    }

    struct stat stats;
    stat("E:\\Coding\\Advent-Of-Code-2025\\Day 2 - Gift Shop\\input.txt", &stats);

    FileInfo fileInfo =
        {
        .filePtr = fptr,
        .fileSize = stats.st_size
    };

    return fileInfo;
}

char* GetInputFileContents(size_t* fileSize)
{
    FileInfo inputFileInfo = GetInputFileInfo();

    FILE* fptr = inputFileInfo.filePtr;

    char* fileContents;
    fileContents = malloc(inputFileInfo.fileSize + 1);

    char c;
    int i = 0;
    while ((c = fgetc(fptr)) != EOF)
    {
        fileContents[i] = c;
        i++;
    }

    fileContents[inputFileInfo.fileSize] = '\0';

    *fileSize = inputFileInfo.fileSize;

    fclose(fptr);

    return fileContents;
}

int main(void)
{
    size_t fileSize = 0;
    char* fileContents = GetInputFileContents(&fileSize);

    char buffer[10] = {0};
    int j = 0;

    Range* ranges[50];
    for (int i = 0; i < 50; i++)
    {
        ranges[i] = malloc(sizeof(Range));
    }
    int k = 0;

    for (int i = 0; i < fileSize; i++)
    {
        if (fileContents[i] == ',')
        {
            buffer[j] = '\0';
            strcpy(ranges[k]->max, buffer);
            memset(buffer, 0, sizeof(buffer));
            j = 0;
            k++;
        }
        else if (fileContents[i] == '-')
        {
            buffer[j] = '\0';
            strcpy(ranges[k]->min, buffer);
            memset(buffer, 0, sizeof(buffer));
            j = 0;
        }
        else
        {
            buffer[j] = fileContents[i];
            j++;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%s - %s\n", ranges[i]->min, ranges[i]->max);
    }



    return 0;
}