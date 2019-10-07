#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


// lire chap 4-5-6

// ecrire un programme qui compte le nm de ligne d'un fichier texte 
// ( chaines d etaille max)
// 



int main(int argc, char const *argv[])
{

	
	FILE* fichier = fopen("file.txt", "r+");


	//We browse the file and each number are put in the map->grid
	char c ;
	

    int i;

    fscanf(fichier,"%d", &c) ;

    printf("char : %c \n", c);



	fclose(fichier);

    return 0;
}

