#include <stdio.h>
#include <string.h>

struct TDistrito {
    char parametros[200];
    float ph;
    int conductividad;
    int turbidez;
    int coliformes;
};

void imprimirMes(struct TDistrito [], int, FILE *, FILE *);
void imprimirMestxt(struct TDistrito [], int, FILE *, FILE *);

int main () {
    	
	char estadisticas;
	char media_particular;
	char maximo;
	char minimo;
	float media1, media2, media3, media4, maximo1,maximo2,maximo3,maximo4,minimo1,minimo2,minimo3,minimo4;
	
	FILE *fentrada, *fsalida;
    struct TDistrito mes[26] = {0};
    char nombrefichero[100];
    
    printf("Introduce el nombre del fichero que contiene los datos \n");
    scanf("%s", nombrefichero);
    
    fentrada = fopen(nombrefichero, "r");
    if (fentrada == NULL) {
        printf("Error en la apertura del fichero de entrada\n");
        return 0;
    }

    fsalida = fopen("resultadosfuentes.txt", "w");
    if (fsalida == NULL) {
        printf("Error en la apertura del fichero de salida\n");
        return 0;
    }

    imprimirMes(mes, 26, fsalida, fentrada);
    
    fclose(fentrada);
    fclose(fsalida);
	
	printf("¿Que estadistica quieres hacer? Selecciona un numero de los siguientes: \n");
	
	printf("1 - Media\n");
	printf("2 - Maximo\n");
	printf("3 - Minimo\n");
	
	scanf("%c",&estadisticas);
	
	switch(estadisticas){ //hacer estadisticas 
		
		case 1:
			printf("¿De que parametro quieres hacer la media?\n");
			printf("1 - Ph\n");
			printf("2 - Conductividad\n");
			printf("3 - Turbidez\n");
			printf("4 - Coliformes\n");
			
			scanf("%c",&media_particular);
			
			switch(media_particular){
				
				case 1:
					printf("Media de Ph = %d", media1);
				case 2:
					printf("Media de Conductividad = %d", media2);
				case 3:
					printf("Media de Turbidez = %d", media3);
				case 4:
					printf("Media de Coliformes = %d", media4);
			}
			
			break;
			
		case 2:
			printf("¿De que parametro quieres buscar el maximo?\n");
			printf("1 - Ph\n");
			printf("2 - Conductividad\n");
			printf("3 - Turbidez\n");
			printf("4 - Coliformes\n");
			
			scanf("%c",&maximo);
			
			switch(maximo){
				
				case 1:
					printf("Maximo de Ph = %d", maximo1);
				case 2:
					printf("Maximo de Conductividad = %d", maximo2);
				case 3:
					printf("Maximo de Turbidez = %d", maximo3);
				case 4:
					printf("Maximo de Coliformes = %d", maximo4);
			}
			
			break;
			
		case 3:
			printf("¿De que parametro quieres buscar el minimo?\n");
			printf("1 - Ph\n");
			printf("2 - Conductividad\n");
			printf("3 - Turbidez\n");
			printf("4 - Coliformes\n");
			
			scanf("%c",&minimo);
			
			switch(minimo){
				
				case 1:
					printf("Minimo de Ph = %d", minimo1);
				case 2:
					printf("Minimo de Conductividad = %d", minimo2);
				case 3:
					printf("Minimo de Turbidez = %d", minimo3);
				case 4:
					printf("Minimo de Coliformes = %d", minimo4);
			}
			
			break;
		
	}	
	
}

void imprimirMes(struct TDistrito mes[], int dim, FILE *fsalida, FILE *fentrada) {
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
    
    for (i = 0; i < dim; i++) {
        fprintf(fsalida, "%s\t%.2f\t%d\t%d\t%d\n", mes[i].parametros, mes[i].ph, mes[i].conductividad, mes[i].turbidez, mes[i].coliformes);
    }
}

void imprimirMestxt(struct TDistrito mes[], int dim, FILE *fsalida, FILE *fentrada) {
    int i;
    char titulo1[50], titulo2[50], titulo3[50], titulo4[50], titulo5[50];
    
    for (i = 0; i < 1; i++) {
        scanf("%s%s%s%s%s", titulo1, titulo2, titulo3, titulo4, titulo5);
    }
    
    while (fscanf(fentrada, "%s%f%d%d%d", mes[i].parametros, &mes[i].ph, &mes[i].conductividad, &mes[i].turbidez, &mes[i].coliformes) != EOF) {
		i++;
	}
    
    for (i = 0; i < 1; i++) {
        printf("%s\t%s\t%s\t%s\t%s\n", titulo1,titulo2, titulo3, titulo4, titulo5);
    }
    
    for (i = 0; i < dim; i++) {
        printf("%s\t%.2f\t%d\t%d\t%d\n", mes[i].parametros, mes[i].ph, mes[i].conductividad, mes[i].turbidez, mes[i].coliformes);
    }
}

float media1 (int);
float media2 (int);
float media3 (int);
float media4 (int);

float maximo1 (int n);
float maximo2 (int n);
float maximo3 (int n);
float maximo4 (int n);
	
float minimo1 (int n);
float minimo2 (int n);
float minimo3 (int n);
float minimo4 (int n);

float media1(struct TDistrito mes[], int n){ //media ph
	int suma=0, i;
	float media1;
	
	for(i=0;i<25;i++){
		suma += mes[i].ph;
	}
	media1=(float)suma/25;
	
	return media1;
}

float media2 (struct TDistrito mes[], int n){ //media conductividad
	int suma=0, i;
	float media2;
	
	for(i=0;i<25;i++){
		suma += mes[i].conductividad;
	}
	media2=suma/25;
	
	return media2;
}

float media3 (struct TDistrito mes[], int n){ //media turbidez
	int suma=0, i;
	float media3;
	
	for(i=0;i<25;i++){
		suma += mes[i].turbidez;
	}
	media3=suma/25;
	
	return media3;
}

float media4 (struct TDistrito mes[], int n){ //media coliformes 

	int suma=0, i;
	float media4;
	
	for(i=0;i<25;i++){
		suma += mes[i].coliformes;
	}
	media4=suma/25;
	
	return media4;
}

float maximo1 (struct TDistrito mes[], int n){ //maximo ph
	
	int i, contador;
	float maximo1=0;
	
	for(i=0;i<25;i++){
		if(maximo1<mes[i].ph){
			maximo1=mes[i].ph;
		}
	}
	return maximo1;
}

int maximo2 (struct TDistrito mes[], int n){ //maximo conductividad
	
	int i,maximo2=0;
	
	for(i=0;i<25;i++){
		if(maximo2<mes[i].conductividad){
			maximo2=mes[i].conductividad;
		}
	}
	return maximo2;
}

int maximo3 (struct TDistrito mes[], int n){ //maximo turbidez
	
	int i,maximo3=0;
	
	for(i=0;i<25;i++){
		if(maximo3<mes[i].turbidez){
			maximo3=mes[i].turbidez;
		}
	}
	return maximo3;
}

int maximo4 (struct TDistrito mes[], int n){ //maximo coliformes
	
	int i,maximo4=0;
	
	for(i=0;i<25;i++){
		if(maximo4<mes[i].coliformes){
			maximo4=mes[i].coliformes;
		}
	}
	return maximo4;
}
float minimo1 (struct TDistrito mes[], int n){ //minimo ph
	
	int i, minimo1=0;
	
	for(i=0;i<25;i++){
		if(minimo1>mes[i].ph){
			minimo1=mes[i].ph;
		}
	}
	return minimo1;
}
float minimo2(struct TDistrito mes[], int n){ //minimo conductividad 
	
	int i, minimo2=0;
	
	for(i=0;i<25;i++){
		if(minimo2>mes[i].conductividad){
			minimo2=mes[i].conductividad;
		}
	}
	return minimo2;
}
float minimo3 (struct TDistrito mes[], int n){ //minimo turbidez
	
	int i, minimo3=0;
	
	for(i=0;i<25;i++){
		if(minimo3>mes[i].turbidez){
			minimo3=mes[i].turbidez;
		}
	}
	return minimo3;
}
float minimo4 (struct TDistrito mes[], int n){ //minimo coliformes
	
	int i, minimo4=0;
	
	for(i=0;i<25;i++){
		if(minimo4>mes[i].coliformes){
			minimo4=mes[i].coliformes;
		}
	}
	return minimo4;
}

