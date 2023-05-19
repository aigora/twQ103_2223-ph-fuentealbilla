#include <stdio.h>
#include <string.h>

struct TDistrito {
    char parametros[200];
    float ph;
    int conductividad;
    int turbidez;
    int coliformes;
};

void imprimirMes(struct TDistrito [], int, FILE *, FILE *, int);

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
    	
	int estadisticas, media_particular, maximo, minimo, guardar;
	float media1, media2, media3, media4, maximo1, maximo2, maximo3, maximo4, minimo1, minimo2, minimo3, minimo4;
	 
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
	
	printf("\nQuieres guardar los datos en un .txt al finalizar al cerrar el programa? Se incluiran los valores calculados) \nSi (1) No (0) \n");
    scanf("%d", &guardar);
    
    if (guardar == 1) {
    	fsalida = fopen("resultadosfuentes.txt", "w");
    	if (fsalida == NULL) {
        	printf("Error en la apertura del fichero de salida\n");
       	 	return 0;
  		}
	}
    
    imprimirMes(mes, 25, fsalida, fentrada, guardar);
    
	printf("\nQue estadistica quieres calcular? Selecciona un numero de los siguientes:\n1 - Media\n2 - Maximo\n3 - Minimo\n");
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
					printf("Maximo de pH = %d", maximo1);
					break;
				case 2:
					printf("Maximo de Conductividad = %d", maximo2);
					break;
				case 3:
					printf("Maximo de Turbidez = %d", maximo3);
					break;
				case 4:
					printf("Maximo de Coliformes = %d", maximo4);
					break;
			}
			
			break;
			
		case 3:
			printf("De que parametro quieres buscar el minimo?\n1 - pH\n2 - Conductividad\n3 - Turbidez\n4 - Coliformes\n");
			
			scanf("%d",&minimo);
			
			switch(minimo){
				
				case 1:
					printf("Minimo de pH = %d", minimo1);
					break;
				case 2:
					printf("Minimo de Conductividad = %d", minimo2);
					break;
				case 3:
					printf("Minimo de Turbidez = %d", minimo3);
					break;
				case 4:
					printf("Minimo de Coliformes = %d", minimo4);
					break;
			}
			
			break;
		
	}	
	
	fclose(fentrada);
    fclose(fsalida);
}

void imprimirMes(struct TDistrito mes[], int dim, FILE *fsalida, FILE *fentrada, int guardar) {
    int i;
    char titulo1[100], titulo2[50], titulo3[50], titulo4[50], titulo5[50];
    
    fscanf(fentrada, "%s%s%s%s%s", titulo1, titulo2, titulo3, titulo4, titulo5);

    i=0;
    while (fscanf(fentrada, "%s%f%d%d%d", mes[i].parametros, &mes[i].ph, &mes[i].conductividad, &mes[i].turbidez, &mes[i].coliformes) != EOF) {
		i++;
	}
    
    printf("\n\t\t\t----DOCUMENTO---- \n");
    for (i = 0; i < 1; i++) {
        printf("%s\t%s\t%s\t%s\t%s\n", titulo1,titulo2, titulo3, titulo4, titulo5);
    }
    
    for (i = 0; i < dim; i++) {
        printf("%s\t%.2f\t%d\t%d\t%d\n", mes[i].parametros, mes[i].ph, mes[i].conductividad, mes[i].turbidez, mes[i].coliformes);
    }
    
    if (guardar == 1) {
    	for (i = 0; i < 1; i++) {
        fprintf(fsalida, "%s\t%s\t%s\t%s\t%s\n", titulo1,titulo2, titulo3, titulo4, titulo5);
    }
    
    for (i = 0; i < dim; i++) {
        fprintf(fsalida, "%s\t%.2f\t%d\t%d\t%d\n", mes[i].parametros, mes[i].ph, mes[i].conductividad, mes[i].turbidez, mes[i].coliformes);
    }
	}
}

int media1(struct TDistrito mes[], int n){ //media ph
	int suma=0, i;
	float media1;
	
	for(i=0;i<n;i++){
		suma += mes[i].ph;
	}
	media1=(float)suma/n;
	
	return media1;
}

int media2 (struct TDistrito mes[], int n){ //media conductividad
	int suma=0, i;
	float media2;
	
	for(i=0;i<n;i++){
		suma += mes[i].conductividad;
	}
	media2=suma/n;
	
	return media2;
}

int media3 (struct TDistrito mes[], int n){ //media turbidez
	int suma=0, i;
	float media3;
	
	for(i=0;i<n;i++){
		suma += mes[i].turbidez;
	}
	media3=suma/n;
	
	return media3;
}

int media4 (struct TDistrito mes[], int n){ //media coliformes 

	int suma=0, i;
	float media4;
	
	for(i=0;i<n;i++){
		suma += mes[i].coliformes;
	}
	media4=suma/n;
	
	return media4;
}

int maximo1 (struct TDistrito mes[], int n){ //maximo ph
	
	int i, contador;
	float maximo1=0;
	
	for(i=0;i<n;i++){
		if(maximo1<mes[i].ph){
			maximo1=mes[i].ph;
		}
	}
	return maximo1;
}

int maximo2 (struct TDistrito mes[], int n){ //maximo conductividad
	
	int i,maximo2=0;
	
	for(i=0;i<n;i++){
		if(maximo2<mes[i].conductividad){
			maximo2=mes[i].conductividad;
		}
	}
	return maximo2;
}

int maximo3 (struct TDistrito mes[], int n){ //maximo turbidez
	
	int i,maximo3=0;
	
	for(i=0;i<n;i++){
		if(maximo3<mes[i].turbidez){
			maximo3=mes[i].turbidez;
		}
	}
	return maximo3;
}

int maximo4 (struct TDistrito mes[], int n){ //maximo coliformes
	
	int i,maximo4=0;
	
	for(i=0;i<n;i++){
		if(maximo4<mes[i].coliformes){
			maximo4=mes[i].coliformes;
		}
	}
	return maximo4;
}
int minimo1 (struct TDistrito mes[], int n){ //minimo ph
	
	int i, minimo1=0;
	
	for(i=0;i<n;i++){
		if(minimo1>mes[i].ph){
			minimo1=mes[i].ph;
		}
	}
	return minimo1;
}
int minimo2(struct TDistrito mes[], int n){ //minimo conductividad 
	
	int i, minimo2=0;
	
	for(i=0;i<n;i++){
		if(minimo2>mes[i].conductividad){
			minimo2=mes[i].conductividad;
		}
	}
	return minimo2;
}
int minimo3 (struct TDistrito mes[], int n){ //minimo turbidez
	
	int i, minimo3=0;
	
	for(i=0;i<n;i++){
		if(minimo3>mes[i].turbidez){
			minimo3=mes[i].turbidez;
		}
	}
	return minimo3;
}
int minimo4 (struct TDistrito mes[], int n){ //minimo coliformes
	
	int i, minimo4=0;
	
	for(i=0;i<n;i++){
		if(minimo4>mes[i].coliformes){
			minimo4=mes[i].coliformes;
		}
	}
	return minimo4;
}
