#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"
#include "short.c"

int main()
{
    // List of funcs:
    //void printFromSmallToBig();                 v
    // int get_len_of_list(struct link list);         v
    // void print_list(struct link *list);                     v
    // void freeList(struct link *list);
    // struct link *get_last_item(struct link *list);                v
    // struct link *get_element_before_x(struct link *list, struct link *before);
    // struct link *create(int data, struct link **list, int *isFirst);         v
    // struct link *add_new_to_start(struct link **list, int data);
    // void move_to_start(struct link **list, struct link *dataToMove);
    // void free_last_item(struct link *list);
    // struct link *getItemByIndex(struct link *list, int index);
    // void free_by_index(struct link **list, int index, int *isFirst);
    // void sortListSmallToBig(struct link *list);

    // struct link *list = NULL;
    // int isFirst = 1;
    // struct link *first = create(5, &list, &isFirst);
    // struct link *second = create(4, &list, &isFirst);
    // struct link *third = create(3, &list, &isFirst);
    // struct link *fourth = create(2, &list, &isFirst);
    // struct link *fifth = create(1, &list, &isFirst);
    // print_list(list);
    // sortListSmallToBig(list);
    // print_list(list);
    // freeList(list);
    printf("Welcome to the linked list assignment!\n");
    printf("Enter 's' to print 15 user picked numbers in order (short.c): \n");
    printf("Enter 'f' to try out some of the functions yourself: \n");
    printf("Enter '0' to exit: ");
    char letter = 'l';
    int indicator = 1;
    scanf("%c", &letter);
    printf("\n");
    //exits if '0'
    if (letter == '0')
    {
        return 0;
    }
    if (tolower(letter) == 's' || tolower(letter) == 'f')
    {
        indicator = 2;
    }
    while (indicator == 1)
    {
        printf("Enter 's' to print 15 user picked numbers in order (short.c): \n");
        printf("Enter 'f' to try out some of the functions yourself: \n");
        printf("Enter '0' to exit: ");
        scanf("%c", &letter);
        printf("\n");
        //exits if '0'
        if (letter == '0')
        {
            return 0;
        }
        if (letter == 's' || letter == 'f')
        {
            indicator = 2;
        }
    }
    if (letter == 's')
    {
        printFromSmallToBig();
        return 0;
    }
    if (letter == 'f')
    {
        int num = 15;
        struct link *list = NULL;
        int isFirst = 1;
        while (num != 0)
        {
            printf("Enter 1 to print the linked list: \n");
            printf("Enter 2 to add item to linked list: \n");
            printf("Enter 3 to get length of list: \n");
            printf("Enter 4 to get last item in list: \n");
            printf("Enter 5 to add new item to front of list: \n");
            printf("Enter 6 to free last item: \n");
            printf("Enter 7 to free by index: \n");
            printf("Enter 8 to sort from smallest to biggest: \n");
            printf("Enter 9 to get item by index: \n");
            printf("Enter 10 to get new empty part: \n");
            printf("Enter 0 to exit: ");
            scanf(" %d", &num);
            printf("\n");
            if (num == 0)
            {
                printf("\nOk bye!!!\n");
                return 0;
            }
            else if (num == 1)
            {
                printf("\n");
                print_list(list);
                printf("\n");
            }
            else if (num == 2)
            {
                int numberToInsert;
                printf("Enter number to insert: ");
                scanf(" %d", &numberToInsert);
                struct link *item = create(numberToInsert, &list, &isFirst);
                printf("\n%d\n", item->data);
            }
            else if (num == 3)
            {
                int length = get_len_of_list(list);
                printf("\n%d\n", length);
            }
            else if (num == 4)
            {
                printf("\n%d\n", get_last_item(list)->data);
            }
            else if (num == 5)
            {
                int numberToInsert;
                printf("Enter number to insert: ");
                scanf(" %d", &numberToInsert);

                struct link *item = add_new_to_start(&list, numberToInsert);
                printf("\n&d\n", item->data);
            }
            else if (num == 6)
            {
                if (list == NULL)
                {
                    printf("\nList empty, nothing to free.\n");
                }
                else
                {
                    free_last_item(list);
                    printf("\nLast item removed from list and freed.\n");
                }
            }
            else if (num == 7)
            {
                if (list == NULL)
                {
                    printf("\nList empty, nothing to free.\n");
                }
                else
                {
                    int index;
                    printf("\nWhat index would you like to free? ");
                    scanf(" %d", &index);
                    printf("\n");
                    int len = get_len_of_list(list);
                    while (index > len - 1)
                    {
                        printf("\nIndex out of range\nWhat index would you like to free? ");
                        scanf(" %d", &index);
                        printf("\n");
                    }
                    free_by_index(&list, index, &isFirst);
                    printf("\nItem at index %d of list is freed\n", index);
                }
            }
            else if (num == 8)
            {
                if (list == NULL)
                {
                    printf("\nList empty, nothing to sort.\n");
                }
                else
                {
                    sortListSmallToBig(list);
                    printf("\nList sorted.\n");
                }
            }
            else if (num == 9)
            {
                if (list == NULL)
                {
                    printf("\nList empty, no indexes exist.\n");
                }
                else
                {
                    int index;
                    printf("\nWhat index would you like to get? ");
                    scanf(" %d", &index);
                    printf("\n");
                    int len = get_len_of_list(list);
                    while (index > len - 1)
                    {
                        printf("\nIndex out of range\nWhat index would you like to get? ");
                        scanf(" %d", &index);
                        printf("\n");
                    }
                    printf("\nItem at index %d: %d\n", index, getItemByIndex(list, index)->data);
                }
            }
            else if (num == 10)
            {
                struct link *newPlace = create_skeleton();
                printf("\nNew empty part at place: %d\nData: %d\n\n", newPlace, newPlace->data);
                free(newPlace);
            }
        }
    }

    return 0;
}