#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define LEFTTOP 1
#define TOP 2

typedef struct _Item
{
    int w;
    int v;
} Item;

void DPKnapsack(Item *itemSet, int maxWeight, int itemNumber, int *valueTable, int *arrowTable)
{
    int i, w;

    for (w = 1; w < itemSet[1].w; ++w)
    {
        *(valueTable + 1 * (maxWeight + 1) + w) = 0;
        *(arrowTable + 1 * (maxWeight + 1) + w) = TOP;
    }
    for (w = itemSet[1].w; w <= maxWeight; ++w)
    {
        *(valueTable + 1 * (maxWeight + 1) + w) = itemSet[1].v;
        *(arrowTable + 1 * (maxWeight + 1) + w) = LEFTTOP;
    }

    for (i = 2; i <= itemNumber; ++i)
    {
        for (w = 1; w <= maxWeight; ++w)
        {
            if (itemSet[i].w <= w && *(valueTable + (i - 1) * (maxWeight + 1) + w) <=
                                         *(valueTable + (i - 1) * (maxWeight + 1) + w - itemSet[i].w) + itemSet[i].v)
            {
                *(valueTable + i * (maxWeight + 1) + w) = *(valueTable + (i - 1) * (maxWeight + 1) + w - itemSet[i].w) + itemSet[i].v;
                *(arrowTable + i * (maxWeight + 1) + w) = LEFTTOP;
            }
            else
            {
                *(valueTable + i * (maxWeight + 1) + w) = *(valueTable + (i - 1) * (maxWeight + 1) + w);
                *(arrowTable + i * (maxWeight + 1) + w) = TOP;
            }
        }
    }
    return;
}
void PrintKnapsackItem(Item *itemSet, int *arrowTable, int maxWeight, int i, int w)
{
    if (i == 0 || w == 0)
    {
        return;
    }

    if (*(arrowTable + i * (maxWeight + 1) + w) == LEFTTOP)
    {
        PrintKnapsackItem(itemSet, arrowTable, maxWeight, i - 1, w - itemSet[i].w);
        printf("%d ", i);
    }
    else
    {
        PrintKnapsackItem(itemSet, arrowTable, maxWeight, i - 1, w);
    }

    return;
}
int main(int argc, char *argv[])
{
    int maxWeight, itemNumber, i;
    Item *itemSet;
    int *valueTable, *arrowTable;

    // input data
    scanf("%d", &maxWeight);
    scanf("%d", &itemNumber);

    valueTable = (int *)malloc((itemNumber + 1) * (maxWeight + 1) * sizeof(int));
    arrowTable = (int *)malloc((itemNumber + 1) * (maxWeight + 1) * sizeof(int));
    memset(valueTable, 0, (itemNumber + 1) * (maxWeight + 1) * sizeof(int));
    memset(arrowTable, 0, (itemNumber + 1) * (maxWeight + 1) * sizeof(int));

    itemSet = (Item *)malloc((itemNumber + 1) * sizeof(Item));
    itemSet[0].w = 0;
    itemSet[0].v = 0;
    for (i = 1; i <= itemNumber; ++i)
    {
        scanf("%d %d", &itemSet[i].w, &itemSet[i].v);
    }

    // test
    DPKnapsack(itemSet, maxWeight, itemNumber, valueTable, arrowTable);
    PrintKnapsackItem(itemSet, arrowTable, maxWeight, itemNumber, maxWeight);

    return 0;
}