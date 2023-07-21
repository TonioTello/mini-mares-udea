#include <ncurses.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cabe.h"


void pause(void)  // funcion que me permite hacer pausas en la ejecucion del programa...
{
	printw("\n\nPresione cualquier tecla para continuar..."); getch();
	erase();		    
}

//**********Menu principal************//
char Menu_principal(void)
{	
	char opc;  
          printw("Menu_principal");
	move(4,7); printw("Bienvenidos a Mini-mares (Menu Principal). ");
	move(6,4); printw("1. Crear una nueva cuenta. ");
	move(7,4); printw("2. Ingresar a su cuenta. ");	
	move(8,4); printw("3. Salir de Mini-mares");
          move(10,7); printw("Opcion: ");
	refresh();
	//scanf("%c", &opc);			
	opc =getch();  // getch();
	return opc;
}


//*********Menu Estudiante*********//
char Rol_student(void)
{
	char opc;
	do        //****Valida que el numero ingresado si este dentro de las opciones****/
	{
	        printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Estudiante");
		move(4,7); printw("Menu de Opciones Para Estudiante. ");			
		move(6,4); printw("1. Consultar notas.\n");
		move(7,4); printw("2. Volver a menu principal.\n");
		move(9,7); printw("Opcion: ");	
		
		opc = getch();
		if( (opc!='1') && (opc!='2') )	
		{	erase();
			move(4,4); printw("Opcion no validad.");
			move(7,4); pause();
			erase();						
		}
	  	refresh();	
	}
	while ( (opc!='1') && (opc!='2') );
	return opc;
}

//*********Menu Profesor*********//
char Rol_teacher(void)
{
	char opc;
        printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Profesor");
	move(4,7); printw("Menu de Opciones Para Profesor. ");			
	move(6,4); printw("1. Gestionar notas.\n");
	move(7,4); printw("2. Ver lista de clase.\n");
	move(8,4); printw("3. Volver a menu principal.\n");
	move(10,7); printw("Opcion: ");	
	refresh();
	opc = getch();
	return opc;
}

//*********Menu Secundario Profesor*********//
char Rol_second_teacher(void)
{
	char opc;
	do        
	{	
	        printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Profesor/Menu_Secundario_Profesor/");
		move(4,7); printw("Opciones Para Profesores. ");						
		move(6,4); printw("1. Definir notas.\n");
		move(7,4); printw("2. Ingresar notas.\n");
		move(8,4); printw("3. Ver notas.\n");
		move(9,4); printw("4. <------\n");
		move(11,7); printw("Opcion: ");	
		
		opc = getch();
		if( (opc!='1') && (opc!='2') && (opc!='3') && (opc!='4') )	
		{	erase();
			move(4,4); printw("Opcion no validad.");
			move(7,4); pause();
			erase();						
		}
	  	refresh();	
	}
	while ( (opc!='1') && (opc!='2') && (opc!='3') && (opc!='4') );
	return opc;
}

//*********Menu Administrador*********// 
char Rol_Administrator(void)
{
	char opc;

        printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Administrador");     
        move(4,7); printw("Menu de Opciones Para Adminiestrador ");						
        move(6,4); printw("1. Guardar datos del sistema.\n");
        move(7,4); printw("2. Cargar datos del sistema.\n");
        move(8,4); printw("3. Gestionar usuarios ");		
        move(9,4); printw("4. Gestionar materias del semestre.\n");
        move(10,4); printw("5. Volver a menu principal.\n");
        move(12,7); printw("Opcion: ");	       
        opc = getch();
        refresh();	
		
	return opc;
}


// otras funciones......................................................



