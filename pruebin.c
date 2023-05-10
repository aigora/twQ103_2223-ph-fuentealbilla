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

int media1 (struct TDistrito[], int);
int media2 (struct TDistrito[], int);
int media3 (struct TDistrito[], int);
int media4 (struct TDistrito[], int);

int maximo1 (struct TDistrito[], int);
int maximo2 (struct TDistrito[], int);
int maximo3 (struct TDistrito[], int);
int maximo4 (struct TDistrito[], int);
	
int minimo1 (struct TDistrito[], int);
int minimo2 (struct TDistrito[], int);
int minimo3 (struct TDistrito[], int);
int minimo4 (struct TDistrito[], int);


int main () {
    	
	int estadisticas, media_particular, maximo, minimo, documento;
	float media1, media2, media3, media4,contador1, contador2, contador3, contador4, contador5, contador6, contador7, contador8;
	 
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
	
	printf("Quieres imprimir el documento en .exe (1) o .txt(2) \n");
	scanf("%d", &documento);
	
	switch (documento) {
			case 1: 
				imprimirMes(mes, 26, fsalida, fentrada);
				break;
				
			case 2:
				imprimirMestxt(mes, 26, fsalida, fentrada);
				break;
		}	
    
	printf("Que estadistica quieres calcular? Selecciona un numero de los siguientes:\n1 - Media\n2 - Maximo\n3 - Minimo\n");
	scanf("%d", &estadisticas);
	
	switch(estadisticas){ //hacer estadisticas 
		
		case 1:
			printf("De que parametro quieres hacer la media?\n1 - pH\n2 - Conductividad\n3 - Turbidez\n4 - Coliformes\n");
			
			scanf("%d",&media_particular);
			
			switch(media_particular){
				
				case 1:
					printf("Media de pH = %d", media1);
					break;
				case 2:
					printf("Media de Conductividad = %d", media2);
					break;
				case 3:
					printf("Media de Turbidez = %d", media3);
					break;
				case 4:
					printf("Media de Coliformes = %d", media4);
					break;
			}
			
			break;
			
		case 2:
			printf("De que parametro quieres buscar el maximo?\n1 - pH\n2 - Conductividad\n3 - Turbidez\n4 - Coliformes\n");

			scanf("%d",&maximo);
			
			switch(maximo){
				
				case 1:
					printf("Maximo de pH = %f", mes[contador1].ph);
					break;
				case 2:
					printf("Maximo de Conductividad = %d", mes[contador2].conductividad);
					break;
				case 3:
					printf("Maximo de Turbidez = %d", mes[contador3].turbidez);
					break;
				case 4:
					printf("Maximo de Coliformes = %d", mes[contador4].coliformes);
					break;
			}
			
			break;
			
		case 3:
			printf("De que parametro quieres buscar el minimo?\n1 - pH\n2 - Conductividad\n3 - Turbidez\n4 - Coliformes\n");
			
			scanf("%d",&minimo);
			
			switch(minimo){
				
				case 1:
					printf("Minimo de pH = %f", mes[contador5].ph);
					break;
				case 2:
					printf("Minimo de Conductividad = %d", mes[contador6].conductividad);
					break;
				case 3:
					printf("Minimo de Turbidez = %d", mes[contador7].turbidez);
					break;
				case 4:
					printf("Minimo de Coliformes = %d", mes[contador8].coliformes);
					break;
			}
			
			break;
		
	}	
	
	fclose(fentrada);
    fclose(fsalida);
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

int media1(struct TDistrito mes[], int n){ //media ph
	int suma=0, i;
	float media1;
	
	for(i=0;i<25;i++){
		suma += mes[i].ph;
	}
	media1=(float)suma/25;
	
	return media1;
}

int media2 (struct TDistrito mes[], int n){ //media conductividad
	int suma=0, i;
	float media2;
	
	for(i=0;i<25;i++){
		suma += mes[i].conductividad;
	}
	media2=suma/25;
	
	return media2;
}

int media3 (struct TDistrito mes[], int n){ //media turbidez
	int suma=0, i;
	float media3;
	
	for(i=0;i<25;i++){
		suma += mes[i].turbidez;
	}
	media3=suma/25;
	
	return media3;
}

int media4 (struct TDistrito mes[], int n){ //media coliformes 

	int suma=0, i;
	float media4;
	
	for(i=0;i<25;i++){
		suma += mes[i].coliformes;
	}
	media4=suma/25;
	
	return media4;
}

int maximo1 (struct TDistrito mes[], int n){ //maximo ph
	
	struct TDistrito maximo1;
	int i, contador1;

maximo1=mes[0];
	
	for(i=0;i<25;i++){
		if(mes[i].ph > maximo1.ph){
			maximo1=mes[i];
			contador1=i;
		}
	}
	return contador1;
}

int maximo2 (struct TDistrito mes[], int n){ //maximo conductividad
	
	struct TDistrito maximo2;
	int i, contador2;

maximo2=mes[0];
	
	for(i=0;i<25;i++){
		if(mes[i].ph > maximo2.ph){
			maximo2=mes[i];
			contador2=i;
		}
	}
	return contador2;
}

int maximo3 (struct TDistrito mes[], int n){ //maximo turbidez
	
	struct TDistrito maximo3;
	int i, contador3;

maximo3=mes[0];
	
	for(i=0;i<25;i++){
		if(mes[i].ph > maximo3.ph){
			maximo3=mes[i];
			contador3=i;
		}
	}
	return contador3;
}

int maximo4 (struct TDistrito mes[], int n){ //maximo coliformes
	
	struct TDistrito maximo4;
	int i, contador4;

maximo1=mes[0];
	
	for(i=0;i<25;i++){
		if(mes[i].ph > maximo4.ph){
			maximo4=mes[i];
			contador4=i;
		}
	}
	return contador4;
}
int minimo1 (struct TDistrito mes[], int n){ //minimo ph
	
	struct TDistrito minimo1;
	int i, contador5;

minimo1=mes[0];
	
	for(i=0;i<25;i++){
		if(mes[i].conductividad < minimo1.conductividad){
			minimo1=mes[i];
			contador5=i;
		}
	}
	return contador5;
}
int minimo2(struct TDistrito mes[], int n){ //minimo conductividad 
	
	struct TDistrito minimo2;
	int i, contador6;

minimo2=mes[0];
	
	for(i=0;i<25;i++){
		if(mes[i].conductividad < minimo2.conductividad){
			minimo2=mes[i];
			contador6=i;
		}
	}
	return contador6;
}
int minimo3 (struct TDistrito mes[], int n){ //minimo turbidez
	
	struct TDistrito minimo3;
	int i, contador7;

minimo1=mes[0];
	
	for(i=0;i<25;i++){
		if(mes[i].conductividad < minimo3.conductividad){
			minimo3=mes[i];
			contador7=i;
		}
	}
	return contador7;
}
int minimo4 (struct TDistrito mes[], int n){ //minimo coliformes
	
	struct TDistrito minimo4;
	int i, contador8;

minimo4=mes[0];
	
	for(i=0;i<25;i++){
		if(mes[i].conductividad < minimo4.conductividad){
			minimo4=mes[i];
			contador8=i;
		}
	}
	return contador8;
}
