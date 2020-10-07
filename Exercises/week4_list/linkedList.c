#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;

typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
} ArrayListType;

void error(const char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(ArrayListType *L)
{
    L->size = 0;
}

int is_empty(ArrayListType *L)
{
    return L->size == 0;
}

int is_full(ArrayListType *L)
{
    return L->size == MAX_LIST_SIZE;
}

element getElement(ArrayListType *L, int pos)
{
    if(pos < 0 || pos >= L->size)
        error("location error\n");
    return L->array[pos];
}

void print_list(ArrayListType *L)
{
    int i;
    for(i = 0; i < L->size -1; i++)
        printf("%d->", L->array[i]);
    printf("%d\n", L->array[i]);
}

void insert_last(ArrayListType *L, element item)
{
    if (L->size >= MAX_LIST_SIZE) {
        error("list overflow\n");
        //return;
    }
    L->array[L->size++] = item;
}

void insert(ArrayListType *L, int pos, element item)
{
    if(!is_full(L) && (pos >= 0) && (pos <= L->size)) {
        for (int i = (L->size - 1); i >= pos; i--)
            L->array[i + 1] = L->array[i];
        L->array[pos] = item;
        L->size++;
    }
}

element del(ArrayListType *L, int pos)
{
    element item;
    if(pos < 0 || pos >= L->size) error("location error");
    item = L ->array[pos];
    for (int i = pos; i < (L->size -1); i++)
        L->array[i] = L->array[i+1];
    L->size--;
    return item;
}

int main(void)
{
    ArrayListType list;

    init(&list);

    insert(&list, 0, 10);
    printf("\n0번째 위치에 10 추가\n");
    print_list(&list);

    insert(&list, 0, 20);
    printf("\n0번째 위치에 20 추가\n");
    print_list(&list);

    insert(&list, 0, 30);
    printf("\n0번째 위치에 30 추가\n");
    print_list(&list);

    insert_last(&list, 40);
    printf("\n마지막 위치에 40 추가\n");
    print_list(&list);

    del(&list, 0);
    printf("\n0번째 항목 삭제\n");
    print_list(&list);
}
