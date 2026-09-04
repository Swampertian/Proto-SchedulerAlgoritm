#include <stdio.h>
#include "core.h"
#include "module.h"
int main() {
    Core core = {1, "Alice"};

    printf("This is a C Repository Template\n");
    printf("Core name: %s\n", get_core_name(&core));
    printf("Module name: %s\n", get_module_name(&core));
    return 0;
}