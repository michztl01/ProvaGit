#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>



int main(int argc, char** argv){
    int *prova=malloc(sizeof(int));
    int pid;
    pid=fork();
    if( pid == 0){
        puts("Child process");
        printf("Valore di *prova 1  %p\n",prova);
        prova=(int*)3001;
        printf("Valore di *prova 2  %p\n",prova);
    }
    else{
        puts("Parent process");
        printf("Valore di *prova 3  %p\n",prova);
        wait(NULL);
    }
    printf("Valore di prova 4  %p\n",prova);
    free(prova);
    
}
//conclusione, i puntatori essendo varibili non vengono condivise tra parent e child