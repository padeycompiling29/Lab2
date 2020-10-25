#include <stdlib.h>         /*for define exit()*/
#include <unistd.h>         /*for fork() and getpid*/
#include <stdio.h>          /*for printf()*/
#include <sys/wait.h>


int main(int argc,char **argv){

	int pid;        /*process id*/

	switch (pid=fork()){
	case 0:     /*a fork return 0 to the child*/

		printf("I am the child process : pid=%d     \n",getpid());

		break;

	default:       /*a fork return a pid  to the parent*/

		wait(NULL);
		printf("I am the parent process : pid=%d, child pid=%d           \n",getpid(),pid);
		break;

	case -1:      /*something went wrong*/

		perror("fork");
		exit(1);


	}

exit(0);

}
