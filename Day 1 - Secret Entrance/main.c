#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

FILE* GetInputFile(const char* filename)
{
    FILE* inputFile = fopen(filename, "r");

    if (inputFile == NULL)
    {
        exit(1);
    }

    return inputFile;
}

int8_t GetSign(const char* signLetter)
{
    if (*signLetter == 'L')
    {
        return -1;
    }
    return  1;
}

int main(void)
{
    FILE* inputFile = GetInputFile("E:\\Coding\\Advent of Code 2025\\Day 1 - Secret Entrance\\input.txt");

    int32_t dialNumber = 50;
    uint32_t zerosPassed = 0;

    char buffer[10];
    while (fgets(buffer, 10, inputFile))
    {
        const char* numberStart = &buffer[1];
        const int8_t sign = GetSign(&buffer[0]);

        const uint32_t turnDistance = (int32_t)strtol(numberStart, NULL, 10);

        const uint32_t fullTurns = turnDistance / (uint32_t)100;
        const int32_t remainder = sign * (turnDistance - (fullTurns * 100));

        zerosPassed += fullTurns;

        int32_t originalDialNumber = dialNumber;
        dialNumber += remainder;


        if (dialNumber > 99)
        {
            dialNumber -= 100;
            zerosPassed++;
        }
        else if (dialNumber < 0)
        {
            dialNumber += 100;
            if (originalDialNumber != 0)
            {
                zerosPassed++;
            }

        }
        else if (dialNumber == 0)
        {
            zerosPassed++;
        }
    }

    printf("\n\n%d\n\n", zerosPassed);

    return 0;
}