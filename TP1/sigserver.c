#include <stdio.h> 
#include <stdlib.h>
#include <signal.h> 
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>




void sighand(int signo, siginfo_t *info, void *extra)
{
       void *ptr_val = info->si_value.sival_ptr;
       int int_val = info->si_value.sival_int;
       printf("Signal: %d, value: [%d] %s\n", signo, int_val, (char*)ptr_val);
}

int main()
{
        struct sigaction action;

        action.sa_flags = SA_SIGINFO;
        action.sa_sigaction = &sighand;

        if (sigaction(SIGUSR2, &action, NULL) == -1) {
                perror("sigusr: sigaction");
                return 0;
        }
        
        printf("PID of the server is %i \n", getpid());
        printf("Signal handler installed, waiting for signal\n");

        while(1) {sleep(2);}

        return 0;
}