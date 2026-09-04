#ifndef CORE_H
#define CORE_H

typedef struct {
    int id;
    char name[50];
} Core;

const char* get_core_name(Core* core);

#endif // CORE_H