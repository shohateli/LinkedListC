#include <stdio.h>
#include <stdlib.h>

struct link
{
    int data;
    struct link *next;
};

void print_list(struct link link)
{
    printf("%d ->", link.data);
    while (link.next != NULL)
    {
        link = *link.next;
        printf("%d ->", link.data);
    }
    printf("NULL");
}

int get_len_of_list(struct link list)
{
    int len = 1;
    while (list.next != NULL)
    {
        list = *(list.next);
        len++;
    }
    return len;
}

void freeList(struct link *list)
{
    struct link *tmp;

    while (list != NULL)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

struct link *get_last_item(struct link *list)
{
    struct link *currentElement;
    currentElement = list;
    if (currentElement == NULL)
    {
        return (NULL);
    }
    while (currentElement->next != NULL)
    {
        currentElement = currentElement->next;
    }
    return (currentElement);
}

struct link *create(int data, struct link **list, int *isFirst)
{
    if (*isFirst == 1)
    {
        struct link *placeForNewData = malloc(sizeof(struct link));
        // printf("%s", *list);
        placeForNewData->data = data;
        placeForNewData->next = NULL;
        *list = placeForNewData;
        *isFirst = 2;
        return placeForNewData;
        //turn isfirst to something other than one
    }
    else
    {
        struct link *lastItem = get_last_item(*list);
        // printf("%d\n", lastItem->data);
        struct link *placeForNewData = malloc(sizeof(struct link));
        placeForNewData->data = data;
        placeForNewData->next = NULL;
        lastItem->next = placeForNewData;
        return placeForNewData;
    }
}

int main()
{
    struct link *list = NULL;
    int isFirst = 1;

    // struct link *new = create(2, &link1, &link1, 1);
    // print_list(*list);
    create(5, &list, &isFirst);
    create(4, &list, &isFirst);
    create(3, &list, &isFirst);
    create(2, &list, &isFirst);
    create(1, &list, &isFirst);

    // printf("%d\n", get_last_item(list)->data);
    print_list(*list);
    // printf("%d", last.data);
    // printf("%d", get_len_of_list(*list));
    // free(new);
    freeList(list);

    return 0;
}