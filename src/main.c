#include <stdio.h>
#include "pcb.h"
#include "queue.h"
#include "scheduler.h"

int main() {
    LinkedQueue *queues[] = {
        create_queue("System", 3),
        create_queue("Real", 3)
    };
    PCB *processes[] = {
        create_pcb("Process1", 1, 0, 0, 0, 25),
        create_pcb("Process2", 2, 1, 0, 0, 15),
        create_pcb("Process3", 3, 1, 0, 0, 15)
    };
    size_t size_process = sizeof(processes) / sizeof(processes[0]);
    size_t size_queue = sizeof(queues) / sizeof(queues[0]);

    enqueue(queues[0], processes[0]);
    enqueue(queues[1], processes[1]);
    enqueue(queues[1], processes[2]);

    printf("Numero de Processos: %zu\n", size_process);
    printf("Numero de Filas: %zu\n", size_queue);
    printSchedulerQueues(queues, size_queue);
    scheduler_round_robin(queues, size_queue);

    size_t i = 0;
    while (i < size_process) {
        destroy_pcb(processes[i]);
        i++;
    }

    i = 0;
    while (i < size_queue) {
        destroy_queue(queues[i]);
        i++;
    }

    return 0;
}
