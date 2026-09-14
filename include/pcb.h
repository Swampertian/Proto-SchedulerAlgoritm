// Novidade de Sintaxe das versões mais novas do GCC, substituindo o tradicional #ifndef/#define/#endif para evitar múltiplas inclusões do mesmo arquivo de cabeçalho.
#pragma once

typedef struct PCB {
    char name[50];
    unsigned int pid;
    int priority;
    int dateHour;
    int startTime;
    int endTime;
    bool isCompleted;
    struct PCB *next;
} PCB;

PCB *create_pcb(const char* name, unsigned int pid, int priority, int DateHour, int StartTime, int EndTime);
PCB *destroy_pcb(PCB *pcb);

void print_pcb(const PCB *pcb);
void set_pcb_priority(PCB *pcb, int priority);
