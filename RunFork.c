#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

void wait_or_die() {
    int rc = wait(NULL);
    assert(rc > 0);
}

int fork_or_die() {
    int rc = fork();
    assert(rc >= 0);
    return rc;
}

int main(int argc, char *argv[]) {
    int x  = 100;
    printf("hello I am Parent process: (pid: %d)\n", (int) getpid());
    int fSucc = fork();
    if(fSucc < 0 ) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (fSucc == 0) {
        fprintf(stderr, "I am Child: I am going to sleep for 7 seconds here! and set x to be 200 \n");
        x = 200;
        sleep(7);
        printf("Done sleep!\n");
        printf("I am Child: (pid: %d)\n and value of x is %d .\n" ,  getpid(), x);
    } else {
        int wc = wait(NULL);
        printf("Waiting for Child to get done!\n I am the parent of %d with a (pid:%d) \n" ,
        fSucc , (int) getpid());    
        printf("Value of wc is : %d \n" , (int)wc);
        printf("In Parent: the value of x is still the old value: %d \n", x);
        }
}
