//
//  Metodos.h
//  Practica FIS
//
//  Created by AndrÃ©s Arcones Crespo on 10/3/17.
//  Copyright Â© 2017 AndrÃ©s Arcones Crespo. All rights reserved.
//

#ifndef Metodos_h
#define Metodos_h

/*Cuidado con los parámetros bool porque hay que evaluar
 * que esté dentro del parámetro el "objeto" que devolvemos, además
 * de evaluar que el bool sea true.
 */


//Métodos del paciente

char* buscarPacientes(/*fichero, nombre*/); //Hay que cambiarlo
void agregarPaciente(/*fichero*/);
void modificarPaciente (/*fichero, nombre*/);

//Métodos del Calendario
void crearCalendario(Calendario.mes, Especialista);
void mostrarCalendario(Calendario.mes, Especialista);
bool modificarCalendario(FILE *calendario, int dia); //parametros o dentro metodo

//Métodos del médico

bool buscarMedicoNombre (char* nombre_completo, FILE fich_medicos);
bool buscarMedicoEspecialidad (char especialidad.tipo, FILE fich_medicos);
void agregarMedico (char* nombre_completo, int numColegiado, Especialidad especialidad);
void agregarEspecialidad (Especialidad especialidad);
void modificarFicha (Ficha ficha);
void modificarMedico (FILE *fich_medicos, int numColegiado);

//Métodos Clínica

void visualizarCalendariosDia (int dia);
void gestionarCita (int dia, char*nombre_medico);//Con Dia y hora la prox
void altaPaciente ();
void altaMedico ();
void bajaPaciente();
void bajaMedico();

//Necesitamos gestionar la entrada al sistema de alguna manera #Sprint2

//Métodos Ficha

void CrearFicha ();
void agregarComentarios ();

#endif /* Metodos_h */
