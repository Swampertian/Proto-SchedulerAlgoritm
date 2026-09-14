#include <stdio.h>
#include "pcb.h"
#include "queue.h"

int main() {
    LinkedQueue *queue = create_queue(100);
    PCB *pcb = create_pcb("Process1", 1, 1, 1, 1, 1);
    PCB *pcb2 = create_pcb("Process2", 2, 2, 2, 2, 2);
    enqueue(queue, pcb);
    enqueue(queue, pcb2);
    printQueue(queue);
    printf("\n");
    requeue(queue, pcb);
    printQueue(queue);
    printf("\n");
    requeue(queue, pcb2);
    printQueue(queue);
    printQueueFirst(queue);

    return 0;
}