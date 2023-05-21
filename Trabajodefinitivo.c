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

float media1 (struct TDistrito[], int);
float media2 (struct TDistrito[], int);
float media3 (struct TDistrito[], int);
float media4 (struct TDistrito[], int);

float maximo1 (struct TDistrito[], int);
int maximo2 (struct TDistrito[], int);
int maximo3 (struct TDistrito[], int);
int maximo4 (struct TDistrito[], int);
	
float minimo1 (struct TDistrito[], int);
int minimo2 (struct TDistrito[], int);
int minimo3 (struct TDistrito[], int);
int minimo4 (struct TDistrito[], int);


int main () {
    	
	int estadisticas, media_particular, maximo, minimo, guardar;
	//float media1, media2, media3, media4, maximo1, maximo2, maximo3, maximo4, minimo1, minimo2, minimo3, minimo4;
	 
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
    
    do {
		printf("\nQue estadistica quieres calcular? Selecciona un numero de los siguientes:\n1 - Media\n2 - Maximo\n3 - Minimo\nPulsa 4 si desea salir del programa\n");
		scanf("%d", &estadisticas);
		
		switch(estadisticas){ //hacer estadisticas 
			
			case 1:
				printf("De que parametro quieres hacer la media?\n1 - pH\n2 - Conductividad\n3 - Turbidez\n4 - Coliformes\n");
				
				scanf("%d",&media_particular);
				
				switch(media_particular){
					
					case 1:
						printf("Media de pH = %f", media1(mes,25));
						if (guardar == 1) {
							fprintf(fsalida, "Media de pH = %f\n", media1(mes,25));
						}
						break;
					case 2:
						printf("Media de Conductividad = %f\n", media2(mes,25));
						if (guardar == 1) {
							fprintf(fsalida, "Media de Conductividad = %f\n", media2(mes,25));
						}
						break;
					case 3:
						printf("Media de Turbidez = %f", media3(mes,25));
						if (guardar == 1) {
							fprintf(fsalida, "Media de Turbidez = %f\n", media3(mes,25));
						}
						break;
					case 4:
						printf("Media de Coliformes = %f", media4(mes,25));
						if (guardar == 1) {
							fprintf(fsalida, "Media de Coliformes = %f\n", media4(mes,25));
						}
						break;
				}
				
				break;
				
			case 2:
				printf("De que parametro quieres buscar el maximo?\n1 - pH\n2 - Conductividad\n3 - Turbidez\n4 - Coliformes\n");
	
				scanf("%d",&maximo);
				
				switch(maximo){
					
					case 1:
						printf("Maximo de pH = %f", maximo1(mes,25));
						if (guardar == 1) {
							fprintf(fsalida, "Maximo de pH = %f\n", maximo1(mes,25));
						}
						break;
					case 2:
						printf("Maximo de Conductividad = %d", maximo2(mes,25));
						if (guardar == 1) {
							fprintf(fsalida, "Maximo de Conductividad = %f\n", maximo2(mes,25));
						}
						break;
					case 3:
						printf("Maximo de Turbidez = %d", maximo3(mes,25));
						if (guardar == 1) {
							fprintf(fsalida, "Maximo de Turbidez = %f\n", maximo3(mes,25));
						}
						break;
					case 4:
						printf("Maximo de Coliformes = %d", maximo4(mes,25));
						if (guardar == 1) {
							fprintf(fsalida, "Maximo de Coliformes = %f\n", maximo4(mes,25));
						}
						break;
				}
				
				break;
				
			case 3:
				printf("De que parametro quieres buscar el minimo?\n1 - pH\n2 - Conductividad\n3 - Turbidez\n4 - Coliformes\n");
				
				scanf("%d",&minimo);
				
				switch(minimo){
					
					case 1:
						printf("Minimo de pH = %f", minimo1(mes,25));
						if (guardar == 1) {
							fprintf(fsalida, "Minimo de pH = %f\n", minimo1(mes,25));
						}
						break;
					case 2:
						printf("Minimo de Conductividad = %d", minimo2(mes,25));
						if (guardar == 1) {
							fprintf(fsalida, "Minimo de Conducitividad = %f\n", minimo2(mes,25));
						}
						break;
					case 3:
						printf("Minimo de Turbidez = %d", minimo3(mes,25));
						if (guardar == 1) {
							fprintf(fsalida, "Minimo de Turbidez = %f\n", minimo3(mes,25));
						}
						break;
					case 4:
						printf("Minimo de Coliformes = %d", minimo4(mes,25));
						if (guardar == 1) {
							fprintf(fsalida, "Minimo de Coliformes = %f\n", minimo4(mes,25));
						}
						break;
				}
				
				break;
				
			case 4:
				fclose(fsalida);
				return 0;
			
		}
	} while (estadisticas != 4);
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
    
    fclose(fentrada);
    
    if (guardar == 1) {
    	for (i = 0; i < 1; i++) {
        fprintf(fsalida, "%s\t%s\t%s\t%s\t%s\n", titulo1,titulo2, titulo3, titulo4, titulo5);
    	}
    
    for (i = 0; i < dim; i++) {
        fprintf(fsalida, "%s\t%.2f\t%d\t%d\t%d\n", mes[i].parametros, mes[i].ph, mes[i].conductividad, mes[i].turbidez, mes[i].coliformes);
    	}
    
    //fclose(fsalida);
	}
}

float media1(struct TDistrito mes[], int n){ //media ph
	float suma=0;
	int i;
	float media;
	
	for(i=0;i<n;i++){
		suma += mes[i].ph;
	}
	media=suma/n;
	
	return media;
}

float media2(struct TDistrito mes[], int n){ //media ph
	float suma=0;
	int i;
	float media;
	
	for(i=1;i<n;i++){
		suma += mes[i].ph;
	}
	media=suma/n;
	
	return media;
}

float media3(struct TDistrito mes[], int n){ //media ph
	float suma=0;
	int i;
	float media;
	
	for(i=1;i<n;i++){
		suma += mes[i].ph;
	}
	media=suma/n;
	
	return media;
}

float media4(struct TDistrito mes[], int n){ //media ph
	float suma=0;
	int i;
	float media;
	
	for(i=1;i<n;i++){
		suma += mes[i].ph;
	}
	media=suma/n;
	
	return media;
}
float maximo1 (struct TDistrito mes[], int n){ //maximo ph
	
	struct TDistrito maximo1;
	int i;

    maximo1=mes[1];
	
	for(i=1;i<n;i++){
		if(mes[i].ph > maximo1.ph){
			maximo1=mes[i];
		}
	}
	return maximo1.ph;
}

int maximo2 (struct TDistrito mes[], int n){ //maximo ph
	
	struct TDistrito maximo2;
	int i;

    maximo2=mes[1];
	
	for(i=1;i<n;i++){
		if(mes[i].conductividad > maximo2.conductividad){
			maximo2=mes[i];
		}
	}
	return maximo2.conductividad;
}

int maximo3 (struct TDistrito mes[], int n){ //maximo ph
	
	struct TDistrito maximo3;
	int i;

    maximo3=mes[1];
	
	for(i=1;i<n;i++){
		if(mes[i].turbidez > maximo3.turbidez){
			maximo3=mes[i];
		}
	}
	return maximo3.turbidez;
}

int maximo4 (struct TDistrito mes[], int n){ //maximo ph
	
	struct TDistrito maximo4;
	int i;

    maximo4=mes[1];
	
	for(i=1;i<n;i++){
		if(mes[i].coliformes > maximo4.coliformes){
			maximo4=mes[i];
		}
	}
	return maximo4.coliformes;
}

float minimo1 (struct TDistrito mes[], int n){ //minimo ph
	
	struct TDistrito minimo1;
	int i;

    minimo1=mes[1];
	
	for(i=1;i<n;i++){
		if(mes[i].ph < minimo1.ph){
			minimo1=mes[i];
		}
	}
	return minimo1.ph;
}

int minimo2(struct TDistrito mes[], int n){ //minimo conductividad 
	
	struct TDistrito minimo2;
	int i;

    minimo2=mes[1];
	
	for(i=1;i<n;i++){
		if(mes[i].conductividad < minimo2.conductividad){
			minimo2=mes[i];
		}
	}
	return minimo2.conductividad;
}

int minimo3(struct TDistrito mes[], int n){ //minimo turbidez 
	
	struct TDistrito minimo3;
	int i;

    minimo3=mes[1];
	
	for(i=1;i<n;i++){
		if(mes[i].turbidez < minimo3.turbidez){
			minimo3=mes[i];
		}
	}
	return minimo3.turbidez;
}

int minimo4(struct TDistrito mes[], int n){ //minimo coliformes 
	
	struct TDistrito minimo4;
	int i;

    minimo4=mes[1];
	
	for(i=1;i<n;i++){
		if(mes[i].coliformes < minimo4.coliformes){
			minimo4=mes[i];
		}
	}
	return minimo4.coliformes;
}
