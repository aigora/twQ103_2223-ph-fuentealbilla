#include <stdio.h>

struct TLavapies {
    char parametros;
    float ph;
    int conductividad;
    int turbidez;
    int coliformes;
};

int main () {
    FILE* fentrada, * fsalida;
    struct TLavapies mes01;
    char nombrefichero[100];
    int numfichero = 0;

    printf("Introduce el nombre del fichero que contiene los datos: ");
    scanf("%s", nombrefichero);

    fentrada = fopen(nombrefichero, "r"); //read
    if (fentrada == NULL) {
        printf("Error en la apertura del fichero de entrada\n");
        return 0;
    }
    fsalida = fopen("resultados.txt", "w"); // write
    if (fsalida == NULL) {
        printf("Error en la apertura del fichero de salida\n");
        return 0;
    }
    int i,conductividad;
    float ph;
    for (i=0; i<numfichero; i++) {
    	fscanf(fentrada, "%d %f", &conductividad, &ph);
		printf("%d %f\n", conductividad, ph);
    }

    fclose(fentrada);
    fclose(fsalida);

    return 0;
}
