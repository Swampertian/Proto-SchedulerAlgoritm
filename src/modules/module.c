#include <stdio.h>
#include "module.h"

const char* get_module_name(Core* module){
    return module->name;
}