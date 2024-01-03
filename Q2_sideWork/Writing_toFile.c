#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *infile;
	infile = fopen("SomeFile2.txt", "a");
	int originalX = 200;
	int originalY = 255;
	
	int child = fork();
	if (child < 0) {
		fprintf(stderr, "fork fails!\n");
	
	// Only the child enters the else if here:
	} else if (child == 0) {
	originalX = 400;
	originalY = 425;
	fprintf(infile, "%d:%d\n", originalX , originalY);
	} else {
	fprintf(infile, "%d:%d\n", originalX, originalY);
	}

}



