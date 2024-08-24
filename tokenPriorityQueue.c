#include <stdio.h>

int token = 0;
#define size 6

struct stack
{
    int stack[size];
    int top;
};

void push(struct stack *stack, int item)
{
    // Check Overflow
    if (stack->top == size - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    // Inserting element at top of the stack
    else
    {
        stack->top = stack->top + 1;
        stack->stack[stack->top] = item;
    }
}

int pop(struct stack *stack)
{
    // Check Underflow
    if (stack->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    // Decrementing Top to remove element from stack
    else
    {
        int item = stack->stack[stack->top];
        stack->top = stack->top - 1;

        return item;
    }
}

struct queue_item
{
    char item;
    int priority;
    int token;
};

struct token_queue
{
    struct queue_item queue[size];
    struct stack spaces;
};

void insert(struct token_queue *queue, char item, int priority)
{
    // Check underflow of the stack to verify there are empty spaces
    if (queue->spaces.top == -1)
    {
        printf("Queue Overflow\n");
        return;
    }
    // Insert element with its priority and token
    else
    {
        token = token + 1;
        struct queue_item Item = {item, priority, token};
        int index = pop(&queue->spaces);

        queue->queue[index] = Item;
    }
}

char delete(struct token_queue *queue)
{
    // Checking overflow of stack to verify that queue is not empty
    if (queue->spaces.top == size - 1)
    {
        printf("Queue Underflow\n");
        return '!';
    }
    else
    {
        struct queue_item priorityItem;
        int index = -1;
        int initial_check = 1;

        for (int i = 0; i < size; i++)
        {
            if (queue->queue[i].item == '$')
            {
                continue;
            }
            if (initial_check == 1)
            {
                priorityItem = queue->queue[i];
                initial_check = 0;
                index = i;
                continue;
            }

            // Get the highest priority item
            if (queue->queue[i].priority < priorityItem.priority)
            {
                priorityItem = queue->queue[i];
                index = i;
            }
            // if same priorty then select based on order/token
            else if (queue->queue[i].priority == priorityItem.priority)
            {
                if (queue->queue[i].token < priorityItem.token)
                {
                    priorityItem = queue->queue[i];
                    index = i;
                }
            }
        }
        push(&queue->spaces, index);
        printf("Deleting item: %c\n", priorityItem.item);
        queue->queue[index].item = '$';
        return priorityItem.item;
    }
}

void printQueue(struct token_queue *Q)
{
    // Printing elements of Priority Queue
    printf("Queue: ");
    for (int i = 0; i < size; i++)
    {
        if (Q->queue[i].item != '$')
        {
            printf("%c ", Q->queue[i].item);
        }
    }
    printf("\n");
}
void printStack(struct token_queue *Q)
{
    // Printing elements of stack
    printf("empty spaces: ");
    for (int i = Q->spaces.top; i >= 0; i--)
    {
        int ele = Q->spaces.stack[i];
        printf("%d ", ele);
    }
    printf("\n");
}

void intializeStack(struct token_queue *Q)
{
    for (int i = size - 1; i >= 0; i--)
    {
        push(&Q->spaces, i);
    }
}

int main()
{
    struct token_queue Q = {{{
                                '$',
                            }},
                            {{0}, -1}};

    intializeStack(&Q);
    printStack(&Q);

    // Adding Items to Queue
    insert(&Q, 'A', 6);
    insert(&Q, 'B', 2);
    insert(&Q, 'C', 1);
    insert(&Q, 'D', -3);
    insert(&Q, 'E', 1);
    insert(&Q, 'F', 5);

    printQueue(&Q);

    // Deleting Items from Queue
    delete (&Q);
    delete (&Q);
    delete (&Q);

    printQueue(&Q);
}