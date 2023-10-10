#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200

typedef struct {
    int fruit[MAX_SIZE];
    int lemon;
    int apple;
} Queue;

void inicialQuene(Queue* queue) {
    queue->lemon = -1;
    queue->apple = -1;
}

int isEmpty(Queue* queue) {
    return queue->lemon == -1;
}

int isFull(Queue* queue) {
    return (queue->lemon == 0 && queue->apple == MAX_SIZE - 1) || (queue->lemon == queue->apple + 1);
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Erro: a fila está cheia.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->lemon = queue->apple = 0;
    } else if (queue->apple == MAX_SIZE - 1) {
        queue->apple = 0;
    } else {
        queue->apple++;
    }

    queue->fruit[queue->apple] = value;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Erro: a fila está vazia.\n");
        return -1;
    }

    int value = queue->fruit[queue->lemon];

    if (queue->lemon == queue->apple) {
        queue->lemon = queue->apple = -1;
    } else if (queue->lemon == MAX_SIZE - 1) {
        queue->lemon = 0;
    } else {
        queue->lemon++;
    }

    return value;
}

int main() {
    Queue queue;
    inicialQuene(&queue);

    enqueue(&queue, 85);
    enqueue(&queue, 8555);
    enqueue(&queue, 120);
    enqueue(&queue, 1220);

    printf("Elemento: %d\n", dequeue(&queue));
    printf("Elemento: %d\n", dequeue(&queue));
    printf("Elemento: %d\n", dequeue(&queue));
    printf("Elemento: %d\n", dequeue(&queue));

    return 0;
}

