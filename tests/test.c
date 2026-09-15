#include <assert.h>
#include <stdio.h>

#include "pcb.h"
#include "queue.h"
#include "scheduler.h"

static void test_queue_requeue_does_not_duplicate(void) {
    LinkedQueue *queue = create_queue("test", 2);
    PCB *pcb = create_pcb("process", 1, 1, 0, 0, 3);

    enqueue(queue, pcb);
    assert(queue->size == 1);
    assert(dequeue(queue) == pcb);
    requeue(queue, pcb);
    assert(queue->size == 1);
    assert(dequeue(queue) == pcb);

    destroy_pcb(pcb);
    destroy_queue(queue);
}

static void test_priority_queues(void) {
    LinkedQueue *system_queue = create_queue("system", 2);
    LinkedQueue *user_queue = create_queue("user", 2);
    LinkedQueue *queues[] = { system_queue, user_queue };
    PCB *system_process = create_pcb("system-process", 1, 0, 0, 0, 15);
    PCB *first_user = create_pcb("first-user", 2, 1, 0, 0, 15);
    PCB *second_user = create_pcb("second-user", 3, 1, 0, 0, 5);

    system_queue->quantum = 10;
    user_queue->quantum = 10;
    enqueue(system_queue, system_process);
    enqueue(user_queue, first_user);
    enqueue(user_queue, second_user);

    assert(scheduler_round_robin(queues, 2) == 5);
    assert(system_queue->size == 0);
    assert(user_queue->size == 0);
    assert(system_process->isCompleted);
    assert(first_user->isCompleted);
    assert(second_user->isCompleted);

    destroy_pcb(system_process);
    destroy_pcb(first_user);
    destroy_pcb(second_user);
    destroy_queue(system_queue);
    destroy_queue(user_queue);
}

int main(void) {
    test_queue_requeue_does_not_duplicate();
    test_priority_queues();

    printf("All tests passed.\n");
    return 0;
}
