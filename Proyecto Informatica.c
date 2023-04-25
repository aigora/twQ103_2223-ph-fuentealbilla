#include <stdio.h>

struct TLavapies {
		char parametros;
		float ph;
		int conductividad;
		int turbidez;
		int coliformes;
	};
	
int main () {
	
	FILE*fentrada, *fsalida;
	struct TLavapies mes01;
	char nombrefichero[100];
	int numfichero=0;
	
	printf("Introduce el nombre del fichero que contine los datos \n");
	scanf("%s", &nombrefichero);
	
	fentrada = fopen("nombrefichero", "r"); //read
	if (fentrada == NULL) {
		printf("Error en la apertura del fichero de entrada\n");
		return 0;
	}
	fsalida = fopen("resultados.txt", "w"); // write
	if (fsalida == NULL) {
		printf("Error en la apertura del fichero de salida\n");
		return 0;
	}
	   int valor=0;
        while(fscanf(FILE, "%d", &valor) == 1) {
            nombrefichero[numfichero++] = valor;
        }

       
	fclose(fentrada);
	fclose(fsalida);
	
}
