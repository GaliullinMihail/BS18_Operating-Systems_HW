#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void pressed_ctrl_c()
{
    printf("Ctrl-C has pressed\n");
}

void main()
{
    signal(SIGINT, pressed_ctrl_c);
    sleep(10);
}
