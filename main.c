//
//  main.c
//  Practica FIS
//
//  Created by Andrés Arcones Crespo on 10/3/17.
//  Copyright © 2017 Andrés Arcones Crespo. All rights reserved.
//

#include <stdio.h>
//#include <Metodos.h>

typedef struct Calendarios{
    char* Mes;
    int Numeros;
    double Hora_Cita;
};//calendario API lib C

typedef struct Ficha{
    char* Comentarios; // SE CREAR UN FICHERO NUEVO
};


typedef struct Especialidad{
    char* tipo;             // lista??
    struct Calendarios cal;
    struct Ficha ficha;
};


typedef struct Medicos{
    char* Nombre_completo;
    int Num_colegiado;
    struct Especialidad especialista[5]; //posibilidad con Maps
    
};



typedef struct Pacientes{ //lista ordenada
    char* Nombre;
    char DNI[9];
    char* Seguro_medico;
    
    
};



typedef struct Clinica{
    struct Medicos medico[5];
    struct Pacientes paciente[5];
    
};





int main(){
    
    
    
    return 0;
}



