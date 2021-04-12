#include <stdio.h>
#include <stdlib.h>

struct link
{
    int data;
    struct link *next;
};

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

void print_list(struct link *list)
{
    if (list == NULL)
    {
        printf("empty");
    }
    else
    {
        struct link listModel = *list;
        printf("%d ->", listModel.data);
        while (listModel.next != NULL)
        {
            listModel = *listModel.next;
            printf("%d ->", listModel.data);
        }
        printf("NULL\n");
    }
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

struct link *get_element_before_x(struct link *list, struct link *before)
{
    struct link *currentElement;
    currentElement = list;
    if (currentElement == NULL)
    {
        return (NULL);
    }
    while (currentElement->next != before)
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

struct link *add_new_to_start(struct link **list, int data)
{
    // struct link *temp = *list;
    struct link *placeForNewData = malloc(sizeof(struct link));
    placeForNewData->data = data;
    placeForNewData->next = *list;
    *list = placeForNewData;
    return placeForNewData;
    // printf("%d", (*list)->data);
}

void move_to_start(struct link **list, struct link *dataToMove)
{
    // struct link *temp = *list;
    struct link *before = get_element_before_x(*list, dataToMove);
    before->next = dataToMove->next;
    dataToMove->next = *list;
    *list = dataToMove;
}

void free_last_item(struct link *list)
{
    struct link *last = get_last_item(list);
    struct link *before = get_element_before_x(list, last);
    before->next = NULL;
    free(last);
}

struct link *getItemByIndex(struct link *list, int index)
{
    struct link *currentElement;
    currentElement = list;
    int count = 0;
    if (currentElement == NULL)
    {
        return (NULL);
    }
    while (count != index)
    {
        currentElement = currentElement->next;
        count++;
    }
    return (currentElement);
}

void free_by_index(struct link **list, int index, int *isFirst)
{
    struct link *byIndex = getItemByIndex(*list, index);
    struct link *lastElement = get_last_item(*list);
    if (byIndex == lastElement && index == 0)
    {
        *isFirst = 1;
        free(byIndex);
        *list = NULL;
    }
    else if (index == 0)
    {
        *list = byIndex->next;
        free(byIndex);
    }
    else if (byIndex == lastElement)
    {
        struct link *before = get_element_before_x(*list, byIndex);
        before->next = NULL;
        free(byIndex);
    }
    else
    {
        struct link *before = get_element_before_x(*list, byIndex);
        before->next = byIndex->next;
        free(byIndex);
    }
}

void sortListSmallToBig(struct link *list)
{
    struct link *i = list;
    struct link *j = list->next;
    for (i = list; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main()
{
    struct link *list = NULL;
    int isFirst = 1;

    struct link *first = create(5, &list, &isFirst);
    struct link *second = create(4, &list, &isFirst);
    struct link *third = create(3, &list, &isFirst);
    struct link *fourth = create(2, &list, &isFirst);
    struct link *fifth = create(1, &list, &isFirst);
    print_list(list);
    sortListSmallToBig(list);
    print_list(list);

    freeList(list);

    return 0;
}