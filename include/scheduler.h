#pragma once
#include "pcb.h"
#include "queue.h"

unsigned int scheduler_round_robin(LinkedQueue* multi_queues[], unsigned int num_queues);

int execute_pcb(PCB *pcb, unsigned int quantum);

void printSchedulerQueues(LinkedQueue* multi_queues[], unsigned int num_queues);
