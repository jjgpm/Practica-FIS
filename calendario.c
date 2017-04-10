#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

//#include <Metodos.h>

struct Calendarios{
    char* Mes;
    int Numeros;
    double Hora_Cita;
} ;//calendario API lib C

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                /////////FIN ////////////////////////////


//FUNCIONES CALENDARIO

void crearMes(FILE *calendar, int numerodias, char mes[],char anio[]);
void crearCalendario(FILE *c);
void mostrarCalendarioMes(FILE *calendar, char doctor[], int mes, char anio[]);


// FUNCIONES  AUXILIARES A MÉTODOS PRINCIPALES
int getModuloMes(int mes, int bisiesto);
char* getNombreMes(int num, char *abr);


int main(){

	FILE *fich_calendar = NULL;

	/************** PRUEBAS CALENDARIO ************/

	crearCalendario(fich_calendar);
	crearMes(fich_calendar, 31, "ENERO", "2017");
	mostrarCalendarioMes(fich_calendar, "lolo", 1, "2017");
	
    return 0;


}

//FUNCIONES CALENDARIO

void crearMes(FILE *calendar, int numDias, char mes[], char anio[]){ //se crea un mes vacio
	//k = nº de posibles citas a lo largo del dia(jornada laboral)
	//jornada laboral (9:00 a 20:00);
	//duracion por cita 30 min;
			
	int i,j, k,m; 
	int min=0;
	float hora=8;
	char mesFich[20];
	memset(mesFich, 0, sizeof(mesFich));
	//Generar nombre del fichero
	
	strcat(mesFich, mes);
	strcat(mesFich, anio);
	strcat(mesFich,".txt");	
	
	calendar = fopen(mesFich, "w");
	if(calendar==NULL){
			printf("CALENDARIO NO ENCONTRADO.\n");
	}else{

		fprintf(calendar, "%s\n", mes);
		
		for(i = 1; i <= numDias; i++){
			fprintf(calendar, "\t     "); //+5espacios
				if(i <= 9){
					fprintf(calendar, "0%i ", i);
				}else fprintf(calendar, "%i ", i);
			}
		
		for(k = 0; k < 11; k++){ //horas de la citas

			min = (hora- ((int)hora))*60;
			fprintf(calendar, "\n%0.2d:%0.2d", (int)hora, min);
			hora = hora +0.5;
			
			for(m=0; m<3;m++){ //m = nº campos a rellenar por cita
				for(j = 1; j<=numDias; j++){
				
					if(m==0){
						fprintf(calendar, "\t#especi ");
					}else if(m==1){
						fprintf(calendar, "\t#nomPac ");
					}else{
						fprintf(calendar, "\t#DNI    ");
					}					
				}
				fprintf(calendar, "\n");	
			}
						
		}				
	}
	fclose(calendar);
}

void crearCalendario(FILE *c){//AÑO COMPLETO introducir parametro año 

	int i;
	char ani[4];
	char abrev[3];
	

	time_t fecha= time(0);
	int anio;
	struct tm *tlocal = localtime(&fecha);
	anio=(tlocal->tm_year)+1900;
	
	sprintf(ani, "%d", anio);
	//printf("anio: %s", ani);
	
	for (i = 1; i <= 12; ++i) {
		if(i==4 || i==6 || i==9 || i==11){
			crearMes(c, 30, getNombreMes(i, abrev),ani);
		}else if(i==2){
				if(anio%4==0 && (anio%100!=0) || anio%400==0){// AÑO BISIESTO
					crearMes(c, 29, getNombreMes(i, abrev), ani);
				}else crearMes(c, 28, getNombreMes(i, abrev), ani);
			}else crearMes(c, 31, getNombreMes(i, abrev), ani);
	}
}

void mostrarCalendarioMes(FILE *calendar, char doctor[], int mes, char anio[]){ //doctor = "<mes><anio><DNIdoctor>.txt"

	//si se crean carpetas direccion de cada carpeta
	char lineFich[200];
	char nomFich[20];
	char abre[3];

	//nomFich = getNombreMes(mes, nomFich);
	//printf("nabreveo: %s\n", nomFich);
	
	strcpy(nomFich,getNombreMes(mes, abre));
	strcat(nomFich, anio);
	strcat(nomFich, ".txt");
	
	//printf("nom fich: %s", nomFich);
	
	calendar = fopen(nomFich, "r");
	if(calendar==NULL){
			printf("CALENDARIO NO ENCONTRADO.\n");
	}else{
		
		printf("\n\n\t******************** CALENDARIO DEL DOCTOR %s ********************\n\n",doctor);
		while(!feof(calendar)){
				fgets(lineFich, 200,calendar);
				printf("%s", lineFich);
				memset(lineFich, 0, sizeof(lineFich));
			}
	}
}


//FUNCIONES AUXILIARES

char* getNombreMes(int num, char *abr){
	char *mes;
	switch(num){
	case 1: mes = "ENERO"; abr = "ene"; break;
	case 2: mes = "FEBRERO"; abr= "feb"; break;
	case 3: mes = "MARZO"; abr= "mar"; break;
	case 4: mes = "ABRIL"; abr="abr"; break;
	case 5: mes = "MAYO"; abr="may"; break;
	case 6: mes = "JUNIO"; abr="jun"; break;
	case 7: mes = "JULIO"; abr="jul"; break;
	case 8: mes = "AGOSTO"; abr="ago"; break;
	case 9: mes = "SEPTIEMBRE"; abr="sep"; break;
	case 10: mes = "OCTUBRE"; abr="oct"; break;
	case 11: mes = "NOVIEMBRE"; abr="nov"; break;
	case 12: mes = "DICIEMBRE"; abr="dic";break;
	}
	return mes;
}


int getModuloMes(int mes, int bisiesto){//para calcular las semanas
	int moduloMes=0;
	if (bisiesto == 1) {
		switch (mes){
			case 0:moduloMes=0;break;
			case 1:moduloMes=3;break;
			case 2:moduloMes=4;break;
			case 3:moduloMes=0;break;
			case 4:moduloMes=2;break;
			case 5:moduloMes=5;break;
			case 6:moduloMes=0;break;
			case 7:moduloMes=3;break;
			case 8:moduloMes=6;break;
			case 9:moduloMes=1;break;
			case 10:moduloMes=4;break;
			case 11:moduloMes=6;break;
		}
	}else{
		switch (mes){
			
			case 0:moduloMes=0;break;
			case 1:moduloMes=3;break;
			case 2:moduloMes=3;break;
			case 3:moduloMes=6;break;
			case 4:moduloMes=1;break;
			case 5:moduloMes=4;break;
			case 6:moduloMes=6;break;
			case 7:moduloMes=2;break;
			case 8:moduloMes=5;break;
			case 9:moduloMes=0;break;
			case 10:moduloMes=3;break;
			case 11:moduloMes=5;break;
		}
 	}
 	return moduloMes;
}



/*void mostrarCalendarioAnio(char doctor[]){ //doctor = "calendar<DNIdoctor>.txt"
	
}*/


/*void mostrarCalendarioSemana(char doctor[], int mes, int semana){ //1º, 2º ...semana del mes	
}

void mostrarCalendarioDia(){
}
void mostrarCalendarioDias(char doctor, int mes, int anio, int inicio, int final){
}

bool buscarCalendarioMes(){
	
}

void modificarCalendario(){
}*/
//mostrar calendario por año, por mes y por semana
//modificar calendario
//buscar calendarios

/*void mostrarCalendario(char* mes, char Especialista){
	FILE calendario;//tipo file
	int dia;
	char marca;
	char blanco;
	while(fscanf(calendario,"%d%c", &dia, &blanco) != "\n" ){
		fprintf("%i%c\n", dia, blanco);
	}
	while(fscanf(calendario, "%c%c", &marca, &blanco) != "\n" ){
		fprintf("%c%c", marca, blanco);
	}

}*/

