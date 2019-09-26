#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <wait.h>
int main(){
int res;
int p[2];
if(pipe(p) < 0) {
	exit(-1);
};
printf("Pipe successfully created\n");

pid_t fork_check_1 = fork();
if ( fork_check_1 > 0) printf("First process forked\n");

pid_t fork_check_2 = fork();
if ( fork_check_2 > 0) printf("Second process forked\n");

if (fork_check_1 != 0 && fork_check_2 != 0){
	write(p[1], &fork_check_2, sizeof(fork_check_2));
	printf("Parent process wait for changes in second child\n");

	waitpid(fork_check_2, &res, WUNTRACED);
	printf("Parent get some changes in second child\n");

	exit(0);
	
} else if (fork_check_1 == 0)
{
	printf("We are inside first process\n");
	read(p[0], &fork_check_2, sizeof(fork_check_2));
	printf("First process reads from pipe\n");
	
	printf("First process sleeps 5second\n");
	sleep(5);
	
	printf("First process sends signal to kill second process\n");
	kill(fork_check_2, SIGSTOP);

	printf("second process was killed\n");
} else if( fork_check_2 == 0)
{
	
	while (1)
	{
		printf("Second process alive\n");
		sleep(1);
	}
}

return 0;
}
