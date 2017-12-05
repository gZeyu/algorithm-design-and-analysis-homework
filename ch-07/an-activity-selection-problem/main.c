#include <stdio.h>
#include <malloc.h>

typedef struct _Task
{
    int id;
    struct _Task *next;
} Task;
void PrintTaskSet(Task *taskSet)
{
    Task *task;

    if (taskSet != NULL)
    {
        printf("{");
        printf("a%d", taskSet->id);
        task = taskSet->next;
        while (task != NULL)
        {
            printf(", a%d", task->id);
            task = task->next;
        }
        printf("}\n");
    }
    else
    {
        printf("Ø\n");
    }
}
Task *RecursiveTaskSelect(int *s, int *f, int i, int j)
{
    int m;
    Task *task;

    m = i + 1;
    while (m < j && s[m] < f[i])
    {
        ++m;
    }
    if (m < j)
    {
        task = (Task *)malloc(sizeof(Task));
        task->id = m;
        task->next = RecursiveTaskSelect(s, f, m, j);
        return task;
    }
    else
    {
        return NULL;
    }
}
Task *GreedyTaskSelect(int *s, int *f, int n)
{
    int i, m;
    Task *taskSet, *task;

    task = (Task *)malloc(sizeof(Task));
    task->id = 1;
    task->next = NULL;
    taskSet = task;

    for (m = 2, i = 1; m < n; ++m)
    {
        if (s[m] >= f[i])
        {
            task->next = (Task *)malloc(sizeof(Task));
            task->next->id = m;
            task->next->next = NULL;
            task = task->next;
            i = m;
        }
    }

    return taskSet;
}
int main(int argc, char *argv[])
{
    int s[] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int f[] = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};

    int len = sizeof(s) / sizeof(s[0]);
    Task *taskSet;

    taskSet = RecursiveTaskSelect(s, f, 0, len);
    PrintTaskSet(taskSet);

    taskSet = GreedyTaskSelect(s, f, len);
    PrintTaskSet(taskSet);

    return 0;
}