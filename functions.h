#ifndef SOME_HEADER_GUARD_WITH_UNIQUE_NAME
#define SOME_HEADER_GUARD_WITH_UNIQUE_NAME

#include <stdlib.h>
#include <stdio.h>

struct link
{
    int data;
    struct link *next;
};

void printFromSmallToBig();

int get_len_of_list(struct link *list);

void print_list(struct link *list);

void freeList(struct link *list);

struct link *get_last_item(struct link *list);

struct link *get_element_before_x(struct link *list, struct link *before);

struct link *create_skeleton();

struct link *create(int data, struct link **list, int *isFirst);

struct link *add_new_to_start(struct link **list, int data);

void move_to_start(struct link **list, struct link *dataToMove);

void free_last_item(struct link *list);

struct link *getItemByIndex(struct link *list, int index);

void free_by_index(struct link **list, int index, int *isFirst);

void sortListSmallToBig(struct link *list);

#endif