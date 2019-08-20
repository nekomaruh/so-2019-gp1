
#include <stdio.h>
#include "./libhello.h"

int main(int argc, char**argv){

    int i = 0;
    for(i=1; i<argc; i++){
        printf("Hola hi %s\n",argv[i]);
    }

    printHello("Hola mundo");

    return 0;
}

