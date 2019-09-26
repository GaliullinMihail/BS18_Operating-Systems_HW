#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void singal_usr_1()
{
    printf(" SIGUSR1 has pressed\n");
}

void singal_stop()
{
    printf(" SIGSTOP has pressed\n");
}

void singal_kill()
{
    printf(" SIGKILL has pressed\n");
}

void singal_ctrl_c()
{
    printf(" SIGINT has pressed\n");
}

int main()
{
    signal(SIGINT, singal_ctrl_c);
    signal(SIGKILL, singal_kill);
    signal(SIGSTOP, singal_stop);
    signal(SIGUSR1, singal_usr_1);
    sleep(100);
return 0;
}
