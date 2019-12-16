#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 9999
#define MAX_STRING 256

typedef struct data
{
    int IOtotal;
    int CPUtotal;
    char line[MAX];
} process;

int processQtd;
process Process[MAX];
char aux[MAX];

int createBuffer() {
    char *name = malloc(MAX_STRING);
    if (name == NULL) {
        printf("No memory.\n");
        return -1;
    } else { return 0; }
}

void clear(char  *s) {
    *(s) = '\0';
}

void createProcess(int index, char *name) {
     strcpy(Process[index].line, name);
     clear(aux);
}



int main() {
    createBuffer();
    printf("Number of process: ");
    scanf("%d", &processQtd);

    for (int i=0; i<processQtd; i++) {
        gets(aux);
        strcpy(Process[i].line, aux);
        clear(aux);
    }

    for (int i=0; i<processQtd; i++) {
        printf("#%d: %s\n", i+1, Process[i].line);
    }    

}