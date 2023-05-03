#include <stdio.h>
#include <string.h>

struct TDistrito {
    char parametros[200];
    float ph;
    int conductividad;
    int turbidez;
    int coliformes;
};

void imprimirMes(struct TDistrito [], int, FILE *, FILE*);

int main () {
    int nfuentes = 25, i;
    
    FILE *fentrada, *fsalida;
    struct TDistrito mes[12];
    char nombrefichero[100];
    
    printf("Introduce el nombre del fichero que contine los datos \n");
    scanf("%s", nombrefichero);
    
    fentrada = fopen(nombrefichero, "r"); //read
    if (fentrada == NULL) {
        printf("Error en la apertura del fichero de entrada\n");
        return 0;
    }

	fsalida = fopen("resultadosfuentes.txt", "w"); //write
	if (fsalida == NULL) {
        printf("Error en la apertura del fichero de salida\n");
        return 0;
    }

    imprimirMes(mes, 12, fsalida, fentrada);
    
    fclose(fentrada);
    fclose(fsalida);
}

void imprimirMes(struct TDistrito mes[], int dim, FILE *fsalida, FILE*fentrada) {
    int i, nfuentes = 25;
    
    for (i = 0; i < nfuentes; i++) {
    	 while(fscanf(fentrada, "%s\t%.2f\t%d\t%d\t%d\n", mes[i].parametros, mes[i].ph, mes[i].conductividad, mes[i].turbidez, mes[i].coliformes != EOF)) {
		fprintf(fsalida, "%s\t%.2f\t%d\t%d\t%d\n", mes[i].parametros, mes[i].ph, mes[i].conductividad, mes[i].turbidez, mes[i].coliformes);
		}
	}
}
