#include "helpers.h"

int main(int argc, char * argv[])
{
    char* args[] = {"ls", "/bin", NULL};
    int res = spawn("ls", args);
    return res;
}
