#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd = open("SomeFile.txt", O_WRONLY | O_CREAT | O_APPEND);
	assert(fd > -1);
	
	int x = 997;
	// fork a child process
	int fChild = fork();
	if(fChild < 0) {
		fprintf(stderr, "fork is failing !\n");
		//exit(1);
	} else if(fChild == 0){ // Child Process only here
		x = 331;
		int childNumb = write(fd, "A Message from Child!\n", strlen("A Message from Child!\n"));
		//write(fd ,x, 1);
	}
	sleep(5);
	int sec = write(fd, "Message From parent!\n", strlen("Message From parent!\n"));
	//write(fd, x, 1);
	close(fd);
}
