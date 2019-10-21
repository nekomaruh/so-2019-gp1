#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int p, n = 0;
    scanf("%d\n",&p);
    fprintf(stderr, "Imprimiendo los primos:\n");
    fprintf(stderr,"p -> %d\n",p);
    while(1){
        scanf("%d\n",&n); // Se lee el stdout
        if(n == -1){
            break;
        }
        fprintf(stderr, "%d\n",n);
        int primo=0;
        int divisor=2;
        while(divisor<n  && primo!=1){
            if(n%divisor==0)
                primo=1;
                divisor++;
        }
        if (primo==0){ // Si el número es primo
            fprintf(stdout,"p -> %d\n",n); // Se envía el stdout
        }
  }
  fprintf(stderr, "Completado\n");
}

