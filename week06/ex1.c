#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
int p[2];
char first_str[] = "Some text";
char second_str[sizeof(first_str)];
if(pipe(p) < 0) {
	exit(-1);
}
write(p[1], first_str, sizeof(first_str));
read(p[0], second_str, sizeof(first_str));
printf("%s\n", second_str);
close(p[1]);
return 0;
}
