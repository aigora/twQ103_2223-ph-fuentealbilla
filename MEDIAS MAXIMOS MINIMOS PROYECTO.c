#include <stdio.h>

float media1 (int)
float media2 (int)
float media3 (int)
float media4 (int)

float maximo1 (int n)
int maximo2 (int n)
int maximo3 (int n)
int maximo4 (int n)

int main(){
	
	char estadisticas;
	char media_particular;
	char maximo;
	char minimo;
	
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
					printf("Media de Ph = %f", media1());
				case 2:
					printf("Media de Conductividad = %f", media2());
				case 3:
					printf("Media de Turbidez = %f", media3());
				case 4:
					printf("Media de Coliformes = %f", media4());
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
					printf("Maximo de Ph = %f", maximo1());
				case 2:
					printf("Maximo de Conductividad = %f", maximo2());
				case 3:
					printf("Maximo de Turbidez = %f", maximo3());
				case 4:
					printf("Maximo de Coliformes = %f", maximo4());
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
					printf("Minimo de Ph = %f", minimo1());
				case 2:
					printf("Minimo de Conductividad = %f", minimo2());
				case 3:
					printf("Minimo de Turbidez = %f", minimo3());
				case 4:
					printf("Minimo de Coliformes = %f", minimo4());
			}
			
			break;
		
	}	
	
}

float media1 (int n){ //media ph
	int suma=0, i;
	float media2;
	
	for(i=0;i<25;i++){
		suma += mes[i].ph;
	}
	media2=suma/25;
	
	return media1;
}

float media2 (int n){ //media conductividad
	int suma=0, i;
	float media2;
	
	for(i=0;i<25;i++){
		suma += mes[i].conductividad;
	}
	media2=suma/25;
	
	return media2;
}

float media3 (int n){ //media turbidez
	int suma=0, i;
	float media3;
	
	for(i=0;i<25;i++){
		suma += mes[i].turbidez;
	}
	media3=suma/25;
	
	return media3;
}

float media4 (int n){ //media coliformes 

	int suma=0, i;
	float media4;
	
	for(i=0;i<25;i++){
		suma += mes[i].coliformes;
	}
	media4=suma/25;
	
	return media4;
}

float maximo1 (int n){ //maximo ph
	
	int i;
	float maximo1=0;
	
	for(i=0;i<25;i++){
		if(maximo1<mes[i].ph){
			maximo1=mes[i].ph;
		}
	}
	return maximo1;
}

int maximo2 (int n){ //maximo conductividad
	
	int i,maximo2=0;
	
	for(i=0;i<25;i++){
		if(maximo2<mes[i].conductividad){
			maximo2=mes[i].conductividad;
		}
	}
	return maximo2;
}

int maximo3 (int n){ //maximo turbidez
	
	int i,maximo3=0;
	
	for(i=0;i<25;i++){
		if(maximo3<mes[i].turbidez){
			maximo3=mes[i].turbidez;
		}
	}
	return maximo3;
}

int maximo4 (int n){ //maximo coliformes
	
	int i,maximo4=0;
	
	for(i=0;i<25;i++){
		if(maximo4<mes[i].coliformes){
			maximo4=mes[i].coliformes;
		}
	}
	return maximo4;
}

