#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void printFromSmallToBig()
{
    printf("\n");
    struct link *startList = NULL;
    int number = 1;
    int isFirst;
    for (int i = 0; i < 15; i++)
    {
        if (number == 1)
        {
            isFirst = 1;
        }
        else
        {
            isFirst = 2;
        }
        int tempNumber;
        printf("Insert number %d of 15: ", number);
        scanf(" %d", &tempNumber);
        create(tempNumber, &startList, &isFirst);
        printf("\n");
        number++;
    }
    sortListSmallToBig(startList);
    print_list(startList);
    freeList(startList);
}