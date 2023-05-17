#include <stdio.h>
#include <string.h>

struct TDistrito {
    char parametros[200];
    float ph;
    int conductividad;
    int turbidez;
    int coliformes;
};

void imprimirMestxt(struct TDistrito [], int, FILE *, FILE*);

int main () {
    
    FILE *fentrada, *fsalida;
    struct TDistrito mes[26] = {0};
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

    imprimirMestxt(mes, 26, fsalida, fentrada);
    imprimirMes(mes, 26, fsalida, fentrada);
    
    fclose(fentrada);
    fclose(fsalida);
}

void imprimirMestxt(struct TDistrito mes[], int dim, FILE *fsalida, FILE *fentrada) {
    int i;
    char titulo1[50], titulo2[50], titulo3[50], titulo4[50], titulo5[50];
    
    for (i = 0; i < 1; i++) {
        fscanf(fentrada, "%s%s%s%s%s", titulo1, titulo2, titulo3, titulo4, titulo5);
    }
    
    while (fscanf(fentrada, "%s%f%d%d%d", mes[i].parametros, &mes[i].ph, &mes[i].conductividad, &mes[i].turbidez, &mes[i].coliformes) != EOF) {
		i++;
	}
    
    for (i = 0; i < 1; i++) {
        fprintf(fsalida, "%s\t%s\t%s\t%s\t%s\n", titulo1,titulo2, titulo3, titulo4, titulo5);
    }
    
    for (i = 1; i < dim; i++) {
        fprintf(fsalida, "%s\t%.2f\t%d\t%d\t%d\n", mes[i].parametros, mes[i].ph, mes[i].conductividad, mes[i].turbidez, mes[i].coliformes);
    }
}

void imprimirMes(struct TDistrito mes[], int dim, FILE *fsalida, FILE *fentrada) {
    int i;
    char titulo1[50], titulo2[50], titulo3[50], titulo4[50], titulo5[50];
    
    printf("\n\t\t\t----DOCUMENTO----\n\n");
    for (i = 0; i < 1; i++) {
        fscanf(fentrada, "%s%s%s%s%s", titulo1, titulo2, titulo3, titulo4, titulo5);
    }
    
	while (fscanf(fentrada, "%s%f%d%d%d", mes[i].parametros, &mes[i].ph, &mes[i].conductividad, &mes[i].turbidez, &mes[i].coliformes) != EOF) {
		i++;
	}
	
    for (i = 0; i < 1; i++) {
        printf("%s\t%s\t%s\t%s\t%s\n", titulo1,titulo2, titulo3, titulo4, titulo5);
    }
    
    for (i = 1; i < dim; i++) {
        printf("%s\t%.2f\t%d\t%d\t%d\n", mes[i].parametros, mes[i].ph, mes[i].conductividad, mes[i].turbidez, mes[i].coliformes);
    }
}
