#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
int p[2] , fork_check;
char first_str[] = "Some text";
char second_str[sizeof(first_str)];
if(pipe(p) < 0) {
	exit(-1);
};
fork_check = fork();
if (fork_check>0){
	write(p[1], first_str, sizeof(first_str));
	close(p[1]);
} else {
	read(p[0], second_str, sizeof(first_str));
	close (p[0]);
	printf("%s\n", second_str);
};
return 0;
}
