#include <stdlib.h>
#include <stdio.h>



int main(int argc, char *argv[])
{   
    FILE* fichier = NULL;

    fichier = fopen("test.txt", "w");
 
    if (fichier != NULL)
    {
 
        // On l'écrit dans le fichier
        fprintf(fichier, "%d", 12);
        fclose(fichier);
    }

    
    
    

    return 0;
}  
