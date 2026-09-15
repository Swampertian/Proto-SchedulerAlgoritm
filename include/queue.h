// Novidade de Sintaxe das versões mais novas do GCC, substituindo o tradicional #ifndef/#define/#endif para evitar múltiplas inclusões do mesmo arquivo de cabeçalho.
#pragma once
#include "pcb.h"
typedef struct {
    
    PCB **Processes;
    unsigned int front;
    unsigned int rear;
    unsigned int size;
    unsigned int capacity;
    signed short quantum;
    char name[50];

} CircularQueue;

typedef CircularQueue LinkedQueue;

LinkedQueue* create_queue(const char* name, unsigned int capacity);

void enqueue(LinkedQueue* queue, PCB* pcb);

void requeue(LinkedQueue* queue, PCB* pcb);

void destroy_queue(LinkedQueue* queue);

void printQueue(LinkedQueue* queue);

void printQueueFirst(LinkedQueue* queue);

PCB* dequeue(LinkedQueue* queue);
