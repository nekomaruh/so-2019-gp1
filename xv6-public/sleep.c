#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    // Johan Esteban Ordenes Galleguillos - A01756580
	int time;
    // Si hay más de 2 argumentos, se lanza un error
	if (argc != 2){
		printf(2, "Error: Ingrese los segundos correctamente (Ej: sleep 10)\n");
		exit();
	}
    // Transforma los milisegundos en segundos
	time = atoi(argv[1])*100;
	if (time > 0){
		sleep(time);
	} else {
		printf(2, "Ingrese un intervalo de tiempo válido (En segundos)%s\n");
	}
	exit();
}


