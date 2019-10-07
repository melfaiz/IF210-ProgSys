#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/*

Un fork est une fonctionnalité sous les systèmes Unix ou Linux qui 
permet de dupliquer un processus.

Le fils hérite une copie de la table du descripteur de son pere dans
son etat au moment du fork elles sont apres independantes.

*/

void exo1(){

    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Le PID du pere est: %d \n", getppid());
    }else
    {
        printf("Le PID est: %d \n",pid);
    }
    
}

void exo2(){

    // le \n vide le buffer avant de faire un retour a la ligne

    printf("Coucou \n");

   // fflush(stdout);

    fork();

    printf("Hello \n");
    

    
}

void exo3(){

    pid_t fils;

    for (size_t i = 0; i < 10; i++)
    {
        fils = fork();

        // fils == 0 : hierarchie en arbre

        if( fils > 0) // hierarchie en droite
            break;

    }   


}


int main (int argc, char *argv[]) {

    exo2();

    return 0;
}