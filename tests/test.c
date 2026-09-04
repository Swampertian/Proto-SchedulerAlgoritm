#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "core.h"
#include "module.h"

static void test_get_core_name(void) {
    Core core = { .id = 1, .name = "core-test" };
    assert(strcmp(get_core_name(&core), "core-test") == 0);
}

static void test_get_module_name(void) {
    Core module = { .id = 2, .name = "module-test" };
    assert(strcmp(get_module_name(&module), "module-test") == 0);
}

int main(void) {
    test_get_core_name();
    test_get_module_name();

    printf("All tests passed.\n");
    return 0;
}
