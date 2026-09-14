#ifdef QUEUE_H
#define QUEUE_H
#include "pcb.h"

// Fila Circular dinâmica para armazenar processos (PCBs)
typedef struct {
    PCB **Processes;
    unsigned int front;
    unsigned int rear;
    unsigned int capacity;
} CircularQueue;

typedef CircularQueue circularQueue;

circularQueue* create_queue(unsigned int capacity);

void enqueue(circularQueue* queue, PCB* pcb);

PCB* dequeue(circularQueue* queue);
#endif // QUEUE_H
