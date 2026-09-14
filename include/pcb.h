#ifdef PCB_H
#define PCB_H

typedef struct {
    char name[50];
    unsigned int pid;
    int priority;
    int owner;
    int dateHour;
    int startTime;
    int endTime;
} PCB;

PCB *create_pcb(const char* name, unsigned int pid, int priority, int DateHour, int StartTime, int EndTime);
PCB *destroy_pcb(PCB *pcb);

void print_pcb(const PCB *pcb);
void set_pcb_priority(PCB *pcb, int priority);

#endif