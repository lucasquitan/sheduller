/*
    @author: Lucas Quintanilha
    Algoritmo FCFS: First come, first served.
 */

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 9999

using namespace std;

typedef struct data
{
    int io;
    int cpu;
    char line[MAX];
} process;

int total, value[MAX];
process proc[MAX];
string aux;


void clearString(char *s) {
    *(s) = '\0';
}

void createProcess(int n) {
    for (int i=0; i<n; i++) {
        getline(cin, aux);
        strcpy(proc[i].line, aux.c_str());
        aux.clear();
    }
}

int resultProcess(int n) {
    int result = 0;
    for (int i=0; i<n; i++) {
        result += proc[i].cpu + proc[i].io;
    }
    return result;
}

void listProcessLine(int n) {
    for (int i=0; i<n; i++) {
        printf("#%i: CPU: %i | IO: %i\n", i+1, proc[i].cpu, proc[i].io); 
    }
    printf("Tempo total: %i\n", resultProcess(total));
}



int main(int argc, char const *argv[])
{
    cout << "Number of process: ";
    cin >> total;
    cin.ignore();

    createProcess(total);

    for (int i=0; i<total; i++) {
        int j, b, ioaux, cpuaux, numaux;
        char number[3];
        j = b = ioaux = cpuaux = 0;

        while (proc[i].line[j] != '\0') /* obtendo valores de CPU e IO */
        {
           if ((proc[i].line[j] - '0' > 47) && (proc[i].line[j] - '0' < 58)) { /* is number */
                /* cout << "Achou um numero!" << endl; */
                number[b++] += proc[i].line[j];
           }
           
           else if (proc[i].line[j] - '0' == 99 ) { /* cpu */            
                cpuaux = atoi(number);
                //cout << cpuaux << endl;
                proc[i].cpu += cpuaux;
                clearString(number); cpuaux = 0; b= 0;
           }

           else if (proc[i].line[j] - '0' == 105) { /* io */
                ioaux = atoi(number);
                //cout << ioaux << endl;
                proc[i].io += ioaux;
                clearString(number); ioaux = 0; b = 0;
           }

           else {
               j++;
           }
        }
        
    }

    listProcessLine(total);
}
