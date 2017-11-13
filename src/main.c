#include <stdio.h>
#include "inc/6502.h"

int main(int argc, char **argv)
{
    printf("Apple-I Computer\n");
    
    init(); // start the processor
    run();  // and runs it
    
    return 0;
}
