#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define QUANTUM 10

LinkedQueue* create_queue(unsigned int capacity) {
    LinkedQueue* queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    if (queue == NULL) {
        fprintf(stderr, "Memory allocation failed for queue\n");
        return NULL;
    }
    queue->quantum = QUANTUM;
    queue->Processes = (PCB**)malloc(capacity * sizeof(PCB*));
    if (queue->Processes == NULL) {
        fprintf(stderr, "Memory allocation failed for queue processes\n");
        free(queue);
        return NULL;
    }
    queue->front = 0;
    queue->rear = 0;
    queue->capacity = capacity;
    return queue;
}

void enqueue(LinkedQueue* queue, PCB* pcb) {
    if (queue == NULL || pcb == NULL) {
        fprintf(stderr, "Queue or PCB is NULL\n");
        return;
    }
    if ((queue->rear + 1) % queue->capacity == queue->front) {
        fprintf(stderr, "Queue is full, cannot enqueue\n");
        return;
    }
    queue->Processes[queue->rear] = pcb;
    queue->rear = (queue->rear + 1) % queue->capacity;
}

// Requeue function to add a PCB back to the queue (useful for round-robin scheduling)
void requeue(LinkedQueue* queue, PCB* pcb) {
    if (queue == NULL || pcb == NULL) {
        fprintf(stderr, "Queue or PCB is NULL\n");
        return;
    }
    if ((queue->rear + 1) % queue->capacity == queue->front) {
        fprintf(stderr, "Queue is full, cannot requeue\n");
        return;
    }
    queue->Processes[queue->rear] = pcb;
    queue->rear = (queue->rear + 1) % queue->capacity;
}
PCB* dequeue(LinkedQueue* queue) {
    if (queue == NULL) {
        fprintf(stderr, "Queue is NULL\n");
        return NULL;
    }
    if (queue->front == queue->rear) {
        fprintf(stderr, "Queue is empty, cannot dequeue\n");
        return NULL;
    }
    PCB* pcb = queue->Processes[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    return pcb;
}

void printQueue(LinkedQueue* queue){
    if (queue == NULL) {
        fprintf(stderr, "Queue is NULL\n");
        return;
    }
    if (queue->front == queue->rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents:\n");
    for (unsigned int i = queue->front; i != queue->rear; i = (i + 1) % queue->capacity) {
        printf("\nPosition %u \n", i);
        print_pcb(queue->Processes[i]);
    }
}

void printQueueFirst(LinkedQueue* queue){
    if (queue == NULL) {
        fprintf(stderr, "Queue is NULL\n");
        return;
    }
    if (queue->front == queue->rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("First element in the queue:\n");
    print_pcb(queue->Processes[queue->front]);
}