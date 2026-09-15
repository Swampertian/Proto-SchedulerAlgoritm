#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define QUANTUM 5

LinkedQueue* create_queue(const char* name, unsigned int capacity) {
    if (capacity == 0) {
        fprintf(stderr, "Queue capacity must be greater than zero\n");
        return NULL;
    }

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
    snprintf(queue->name, sizeof(queue->name), "%s", name);
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

void enqueue(LinkedQueue* queue, PCB* pcb) {
    if (queue == NULL || pcb == NULL) {
        fprintf(stderr, "Queue or PCB is NULL\n");
        return;
    }
    if (queue->size == queue->capacity) {
        fprintf(stderr, "Queue is full, cannot enqueue\n");
        return;
    }

    unsigned int position = queue->front;
    unsigned int checked = 0;
    while (checked < queue->size) {
        if (queue->Processes[position] == pcb) {
            fprintf(stderr, "PCB is already in the queue\n");
            return;
        }

        position++;
        if (position == queue->capacity) {
            position = 0;
        }
        checked++;
    }

    queue->Processes[queue->rear] = pcb;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
}
// Garante Lista Circular
void requeue(LinkedQueue* queue, PCB* pcb) {
    if (queue == NULL || pcb == NULL) {
        fprintf(stderr, "Queue or PCB is NULL\n");
        return;
    }
    enqueue(queue, pcb);
}

void destroy_queue(LinkedQueue* queue) {
    if (queue != NULL) {
        free(queue->Processes);
        free(queue);
    }
}

PCB* dequeue(LinkedQueue* queue) {
    if (queue == NULL) {
        fprintf(stderr, "Queue is NULL\n");
        return NULL;
    }
    if (queue->size == 0) {
        fprintf(stderr, "Queue is empty, cannot dequeue\n");
        return NULL;
    }
    PCB* pcb = queue->Processes[queue->front];
    queue->Processes[queue->front] = NULL;
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return pcb;
}

void printQueue(LinkedQueue* queue){
    if (queue == NULL) {
        fprintf(stderr, "Queue is NULL\n");
        return;
    }
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents:\n");
    unsigned int position = queue->front;
    unsigned int printed = 0;
    while (printed < queue->size) {
        printf("\nPosition %u \n", position);
        print_pcb(queue->Processes[position]);

        position++;
        if (position == queue->capacity) {
            position = 0;
        }
        printed++;
    }
}

void printQueueFirst(LinkedQueue* queue){
    if (queue == NULL) {
        fprintf(stderr, "Queue is NULL\n");
        return;
    }
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("First element in the queue:\n");
    print_pcb(queue->Processes[queue->front]);
}
