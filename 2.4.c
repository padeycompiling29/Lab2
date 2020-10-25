#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

	void childTask() {
		char name[50];

		printf("Excuse me,may i know your name :");
		fgets(name,50,stdin);
		printf("Your name is : %s",name);
		exit(0);
	}

	void parentTask(){
		printf("Job is Done!\n");
	}

	int main(void){
	int i;

	for(i=0; i<4; i++){
		pid_t pid= fork();

	if(pid==0){
		childTask();
		exit(EXIT_SUCCESS);
	}

	else{
	wait(NULL);
	parentTask();
	}

	}

}





