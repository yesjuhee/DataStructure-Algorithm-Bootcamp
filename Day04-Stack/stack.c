#include <stdio.h>
#include <stdlib.h>
typedef int elem;

int stack_top = -1;
int stack_size = 0;
elem *stack;

int size()
{
    return stack_top + 1;
}

int empty()
{
    if (stack_top == -1)
    {
        return 1;
    }
    return 0;
}

int full()
{
    if (stack_top == stack_size - 1)
    {
        return 1;
    }
    return 0;
}

void push(elem item)
{
    if (full())
    {
        printf("Stack is full!\n");
        return;
    }
    stack[++stack_top] = item;
}

elem pop()
{
    if (empty())
    {
        printf("Stack is empty!\n");
        return NULL;
    }
    return stack[stack_top--];
}

elem top()
{
    if (empty())
    {
        printf("Stack is empty!\n");
    }
    return stack[stack_top];
}

void print()
{
    for (int i = 0; i <= stack_top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main(void)
{
    int action = 0;
    elem newElem = 0;
    printf("Size of stack: ");
    scanf("%d", &stack_size);
    rewind(stdin);
    // dynamic allocation
    stack = (elem *)malloc(sizeof(int) * stack_size);

    while (1)
    {
        printf("Choose action: \n");
        printf("1: push(), 2: pop(), 3: top(), 4: size(), 5: empty(), 6: end\n");
        scanf("%d", &action);
        rewind(stdin);

        switch (action)
        {
        case 1:
            printf("Element to push: ");
            scanf("%d", &newElem);
            rewind(stdin);
            push(newElem);
            print();
            break;
        case 2:
            printf("pop(): %d\n", pop());
            print();
            break;
        case 3:
            printf("top(): %d\n", top());
            print();
            break;
        case 4:
            printf("size(): %d\n", size());
            print();
            break;
        case 5:
            printf("empty(): %d\n", empty());
            print();
            break;
        case 6:
            printf("End the program\n");
            exit(0);
        default:
            printf("Wrong option: %d\n", action);
        }
    }
}