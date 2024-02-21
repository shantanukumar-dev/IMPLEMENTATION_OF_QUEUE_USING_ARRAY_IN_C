#include <stdio.h>
#include <conio.h>
#define size 10
typedef struct Queue
{
    int Array[size];
    int rear;
    int front;
} Queue;
void initialize(Queue *Q)
{
    Q->rear = -1;
    Q->front = -1;
}
int isempty(Queue *Q)
{
    if (Q->front == -1 && Q->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(Queue *Q)
{
    if ((Q->rear + 1) % size == Q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(Queue *Q, int element)
{
    if (isfull(Q))
    {
        return;
    }
    else if (isempty(Q))
    {
        Q->rear = (Q->rear + 1) % size;
        Q->front = (Q->front + 1) % size;
    }
    else
    {
        Q->rear = (Q->rear + 1) % size;
    }
    Q->Array[Q->rear] = element;
}
void display(Queue *Q)
{
    for (int i = Q->front; i <= Q->rear; i++)
    {
        printf("%d<-", Q->Array[i]);
    }
}
void dequeue(Queue *Q)
{
    if (isempty(Q))
    {
        return;
    }
    else if (Q->rear == Q->front)
    {
        Q->rear = -1;
        Q->front = -1;
    }
    else
    {
        Q->front = Q->front + 1;
    }
}
int main()
{
    Queue Q;
    initialize(&Q);
    isempty(&Q);
    isfull(&Q);
    enqueue(&Q, 100);
    enqueue(&Q, 200);
    enqueue(&Q, 300);
    enqueue(&Q, 400);
    enqueue(&Q, 500);
    display(&Q);
    dequeue(&Q);
    printf("\n");
    display(&Q);
    getch();
    return 0;
}