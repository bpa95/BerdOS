#include "helpers.h"
#include <stdlib.h>

int main(int argc, char * argv[])
{
    char** args = (char**) calloc(argc + 1, sizeof(char*));
    int i;
    for (i = 0; i < argc - 1; i++) {
        args[i] = argv[i + 1];
    }
    args[argc] = NULL;

    args[argc - 1] = ".";
    int res = spawn(args[0], args);

    free(args);
    return 0;
}
