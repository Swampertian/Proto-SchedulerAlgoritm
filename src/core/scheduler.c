#include <stdio.h>
#include "scheduler.h"

int execute_pcb(PCB *pcb, unsigned int quantum) {
    if (pcb == NULL || quantum == 0 || pcb->isCompleted) {
        return 0;
    }

    int slice = (int)quantum;
    if (pcb->remainingTime < slice) {
        slice = pcb->remainingTime;
    }

    pcb->remainingTime -= slice;
    pcb->isCompleted = pcb->remainingTime == 0;
    return slice;
}


unsigned int scheduler_round_robin(LinkedQueue* multi_queues[], unsigned int num_queues) {
    if (multi_queues == NULL || num_queues == 0) {
        return 0;
    }

    unsigned int i = 0;
    while (i < num_queues) {
        if (multi_queues[i] == NULL || multi_queues[i]->quantum <= 0) {
            return 0;
        }
        i++;
    }

    unsigned int slices = 0;
    unsigned int completed = 0;

    while (completed < num_queues) {
        completed = 0;

        i = 0;
        while (i < num_queues) {
            LinkedQueue *queue = multi_queues[i];
            if (queue->size == 0) {
                completed++;
                i++;
                continue;
            }

            PCB *running = dequeue(queue);
            execute_pcb(running, (unsigned int)queue->quantum);
            slices++;

            if (!running->isCompleted) {
                requeue(queue, running);
            }
            break;
        }
    }

    return slices;
}

void printSchedulerQueues(LinkedQueue* multi_queues[], unsigned int num_queues) {
    if (multi_queues == NULL) {
        return;
    }

    unsigned int i = 0;
    while (i < num_queues) {
        if (multi_queues[i] == NULL) {
            i++;
            continue;
        }
        printf("\nPriority queue %u: %s\n", i, multi_queues[i]->name);
        printQueue(multi_queues[i]);
        i++;
    }
}
