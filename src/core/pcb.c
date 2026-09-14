#include <stdio.h>
#include <stdlib.h>
#include "pcb.h"

PCB *create_pcb(const char* name, unsigned int pid, int priority, int DateHour, int StartTime, int EndTime) {
    PCB *pcb = (PCB *)malloc(sizeof(PCB));
    if (pcb == NULL) {
        fprintf(stderr, "Memory allocation failed for PCB\n");
        return NULL;
    }
    snprintf(pcb->name, sizeof(pcb->name), "%s", name);
    pcb->pid = pid;
    pcb->priority = priority;
    pcb->dateHour = DateHour;
    pcb->startTime = StartTime;
    pcb->endTime = EndTime;
    return pcb;
}

PCB *destroy_pcb(PCB *pcb) {
    if (pcb != NULL) {
        free(pcb);
    }
    return NULL;
}

void print_pcb(const PCB *pcb) {
    if (pcb != NULL) {
        printf("Name: %s\n", pcb->name);
        printf("PID: %u\n", pcb->pid);
        printf("Priority: %d\n", pcb->priority);
        printf("Date and Hour: %d\n", pcb->dateHour);
        printf("Start Time: %d\n", pcb->startTime);
        printf("End Time: %d\n", pcb->endTime);
    }
}

void set_pcb_priority(PCB *pcb, int priority) {
    if (pcb != NULL) {
        pcb->priority = priority;
    }
}

