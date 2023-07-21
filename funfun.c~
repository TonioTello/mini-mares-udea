#include <ncurses.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cabe.h"
#include "cabe2.h"



usua *insertarEnUsua(usua *apuntador) // permite ingresar dentro de una lista enlazada los valores correpondientes
{
	usua *apuntadorAux, *newStruct;

	newStruct = (usua *)malloc(sizeof(usua));
	
 	if(newStruct != NULL)   // ingresa aqui, en caso de que la creacion dinamica de memoria se exitosa
	{
		printw("Nombre: ");         // ingresamos por teclado la informacion correpondiente...
		scanw("%s", newStruct-> nombre_usua);
		printw("Cedula: ");
		scanw("%s", newStruct-> cedula_usua);
		strcpy(newStruct-> username, "NA");
		strcpy(newStruct-> password, "NA");
		newStruct-> sig = NULL;
		
		if(apuntador == NULL)
		{
			apuntador = newStruct;
		}
		else
		{
			apuntadorAux = apuntador;
			while( apuntadorAux->sig != NULL)
				apuntadorAux = apuntadorAux->sig;
			apuntadorAux->sig = newStruct;
		}
	}
	return apuntador;
}

void mostrarListaUsua(usua *apuntador)  // imprime en pantalla la lista de usuarios
{
	usua * apuntadorAux;
	int k=1, sw=0;
	apuntadorAux = apuntador;
	
	printw("    %-20s Cedula\n", "Nombre" ); 
        refresh(); 
	 
	while(apuntadorAux != NULL)
	{
		printw("%d.  %-20s %-20s %-20s %s\n", k ,apuntadorAux->nombre_usua, apuntadorAux->cedula_usua, apuntadorAux->username, apuntadorAux->password);		
		apuntadorAux = apuntadorAux -> sig;   
		  
		++k;
		   sw=1; 
	}
	refresh();
	
	if(!sw)
	    printw("\n    ¡Lista vaciá!\n");
	putchar('\n');  
	refresh();  
}

void crearArchivos(FILE * ptd, FILE *ptk)
{
	ptd = fopen("usuarios.txt","r");
	ptk = fopen("materias.txt","r");	
	
	if (!ptd)
	{
		ptd = fopen("usuarios.txt","w");
		printf("Archivo creado...\n\n");	
	}	
	else
	{	
		//printf("Ya exites este archivo...\n\n");	
	}
	fclose(ptd);
}


void saveInFile_dataUsua(usua *apuntador, usua *apuntador2, FILE *ptd)
{
	char nombre[20], cedula[15], apodo[20], clave[30], cadena[100];
	usua *apuntadorAux, *apuntadorAux2;

	ptd = fopen("usuarios.txt","a"); //abre el archivo de (usuarios.txt) para añadir...

	apuntadorAux = apuntador;      // apuntador que apunta a la primera estructura...estudiantes
	apuntadorAux2 = apuntador2;     // apuntador que apunta a la primera estructura...profesor

	while(apuntadorAux != NULL)  // para usuarios del rol estudiante
	{
		fgets(cadena, 100, ptd);
		if(cadena[0]=='\n')
			break;

		strcpy( nombre, apuntadorAux -> nombre_usua ); //En "nombre de tipo cadena" se guarda el valor de  "otroapuntadorAuxiliar -> nombre_usua"...
		fputs(nombre, ptd); // en el archivo el cual es apuntado por ptd se escribe lo que esta en la variable nombre, que es una cadena.
		fputc(',', ptd);
		fputc(32, ptd); // en el archivo el cual... se escribe un enter (32 valor ascii correspondiente a un espacio).

		strcpy( cedula, apuntadorAux-> cedula_usua );
		fputs(cedula, ptd);
		fputc(',', ptd);
		fputc(32, ptd);

		strcpy( apodo, apuntadorAux -> username );
		fputs(apodo, ptd);
		fputc(',', ptd);   
		fputc(32, ptd);

		strcpy( clave, apuntadorAux-> password );
		fputs(clave, ptd);		

		fputc('\n',ptd);	
		apuntadorAux = apuntadorAux -> sig;
	}
	fputc('\n',ptd);	// enter para diferenciar los estudiantes de los profesores
	
	
	while(apuntadorAux2 != NULL)   // para usuarios del rol profesor
	{
		strcpy( nombre, apuntadorAux2 -> nombre_usua ); //En "nombre de tipo cadena" se guarda el valor de  "otroapuntadorAuxiliar -> nombre_usua"...
		fputs(nombre, ptd); // en el archivo el cual es apuntado por ptd se escribe lo que esta en la variable nombre, que es una cadena.
		fputc(',', ptd);
		fputc(32, ptd); // en el archivo el cual... se escribe un enter (32 valor ascii correspondiente a un espacio).

		strcpy( cedula, apuntadorAux2-> cedula_usua );
		fputs(cedula, ptd);
		fputc(',', ptd);
		fputc(32, ptd);

		strcpy( apodo, apuntadorAux2 -> username );
		fputs(apodo, ptd);
		fputc(',', ptd);   
		fputc(32, ptd);

		strcpy( clave, apuntadorAux2-> password );
		fputs(clave, ptd);		

		fputc('\n',ptd);	
		apuntadorAux2 = apuntadorAux2 -> sig;
	}
	fclose(ptd);	
}




curs *insertarEnMaterias(curs *apuntador, usua *apuntador2) // permite ingresar dentro de una lista enlazada la informacion respecto a las materias
{
	curs *apuntadorAux,  *newStruct=NULL;  // este es un apuntador a materias
	usua *apuntadorAux2;  // este es apuntador a usuarios
	int num, k, sw=0;
	char opc;  
	 
	if(apuntador2 != NULL )   // probamos primero que haya profesores, sino no perdemos tiempo creando espacio en memoria...
                newStruct = (curs *) malloc(sizeof(curs));
	else
		printw("\n\nNo hay profesores!");   
	
 	if(newStruct != NULL)   // ingresa aqui, en caso de que la creacion dinamica de memoria se exitosa
	{
	   	printw("Materia: ");         // ingresamos por teclado la informacion correpondiente...
	  	scanw("%s", newStruct-> name_materia);
		printw("Creditos : ");
		scanw("%d", &newStruct-> creditos);     		

	  	printw("\nSeleccione el profesor. Presione el numero correspondiente.\n\n");
		mostrarListaUsua(apuntador2);//apuntador2
		printw("    Opcion: ");   

		while( scanw("%d", &num) != 1);   // num = getchar();
		    printw("\n    OK!....");
	
		apuntadorAux2 = apuntador2;  
		for(k=1; k< num; ++k)//selecciona la struct del profesor indicado
		     apuntadorAux2 = apuntadorAux2 -> sig;
		      		  
	 	strcpy( (newStruct -> name_teacher), (apuntadorAux2 -> nombre_usua) );				
				
		newStruct-> apt_calificaciones = NULL;
		newStruct-> apt_notasmaterias = NULL;
		newStruct-> next = NULL;

		if(apuntador == NULL){
			apuntador = newStruct;
		}
		else{
			apuntadorAux = apuntador;
			while( apuntadorAux->next != NULL)
				apuntadorAux = apuntadorAux->next;
			apuntadorAux->next = newStruct;
		}
	}
	
	return apuntador;
}

void mostrarListaMateria(curs *apuntador)  // imprime en pantalla la lista de materias
{
	curs * apuntadorAux;
	int k=1, sw=0;
	apuntadorAux = apuntador;
	
	printw("   %-20s %-20s Profesor\n", "Nombre", "Creditos"); refresh();  
	while(apuntadorAux != NULL)
	{
		printw("%d. %-20s %-20d %s", k ,apuntadorAux->name_materia, apuntadorAux->creditos, apuntadorAux->name_teacher);
		apuntadorAux = apuntadorAux -> next;   
		refresh(); 
		++k;
		sw=1; 
		printw("\n");    refresh();  
	}
	
	if(!sw)
	    printw("\n    ¡Lista vaciá!\n");
	putchar('\n');  
	refresh();  
}


void saveInFile_dataMateria(curs *apuntador, FILE *ptd)
{
	char materia[20], teacher[20], ncreditos;
	curs *apuntadorAux;

	ptd = fopen("materias.txt","a"); //abre el archivo de (usuarios.txt) para añadir...
	apuntadorAux = apuntador;

	while(apuntadorAux != NULL)
	{
		strcpy( materia, apuntadorAux -> name_materia ); //En "nombre de tipo cadena" se guarda el valor de  "otroapuntadorAuxiliar -> nombre_usua"...
		fputs(materia, ptd); // en el archivo el cual es apuntado por ptd se escribe lo que esta en la variable nombre, que es una cadena.
		fputc(',', ptd);
		fputc(32, ptd); // en el archivo el cual... se escribe un enter (32 valor ascii correspondiente a un espacio).

		ncreditos = apuntadorAux-> creditos;
		fputc(ncreditos, ptd);
		fputc(',', ptd);
		fputc(32, ptd);

		strcpy( teacher, apuntadorAux -> name_teacher );
		fputs(teacher, ptd);

		fputc('\n',ptd);	
		apuntadorAux = apuntadorAux -> next;
	}	
	fclose(ptd);	
}


int buscarDatoCrearCuenta(usua *apuntador, char *cedula)
{
	int sw=0;

	usua *apuntadorAuxiliar;   
	apuntadorAuxiliar = apuntador;   
		
	for(  ; apuntadorAuxiliar != NULL;  apuntadorAuxiliar = apuntadorAuxiliar -> sig ){
		if( strcmp(cedula, apuntadorAuxiliar-> cedula_usua)==0 ){
			 sw = 1;   
			 break;	
		}
	}

	if(sw==0){
	       return FALSE;    //printf("\nNo esta en lista\n");	
	}
	else{

	       if(strcmp("NA", apuntadorAuxiliar->username)==0 )
	       {
		    printw("\n\nPara crear una cuenta de usuario...");		
		    printw("\n\nIngrese su nombre de usuario: ");
		    scanw("%s", &apuntadorAuxiliar->username );
		    printw("\nIngrese su contraseña ");	       
		    noecho();
		    scanw("%s", &apuntadorAuxiliar->password );  
		    echo(); 
		    printw("\n\nCuenta creadá!!...\n\n");			
	       }
	       else
	       {
		    printw("\n\nUd ya tiene una cuanta activa!!\n\n");	
	       }
			
   	       return TRUE;     //printf("\nEsta en lista\n");	
	}
}

int ingresarCuenta(usua *apuntador, char *apodo, char *clave) // esta funcio verifica el nombre de usuario  y su contraseña
{
	int sw=0;
	usua *apuntadorAuxiliar;   
	
	apuntadorAuxiliar = apuntador;   
		
	for(  ; apuntadorAuxiliar != NULL;  apuntadorAuxiliar = apuntadorAuxiliar -> sig ){
		if( (strcmp(apodo, apuntadorAuxiliar-> username)==0) && (strcmp(clave, apuntadorAuxiliar-> password)==0) ){
			 sw = 1;   break;	
		}
	}
        return !sw ? FALSE:TRUE; 
}


void buscarUsername(usua *apuntador, curs *apuntador2, char *apodo) // busca la estructura donde esta el apodo del profesor, luego toma el verdadero nombre del profor y lo pasa a "mostrarCursos"....
{
	int sw=0;

	usua *apuntadorAuxiliar;   
	apuntadorAuxiliar = apuntador;   // hay que utilizar un apondor a _nodo auxiliar para que no modifiquemos la el apuntador que apunta a la cabeza...
		
	for(  ; apuntadorAuxiliar != NULL;  apuntadorAuxiliar = apuntadorAuxiliar -> sig ){
		if( strcmp(apodo, apuntadorAuxiliar-> username)==0 ){
			 mostrarCursos(apuntador2, apuntadorAuxiliar-> nombre_usua); 
			 break;	
		}
	}

}

void mostrarCursos(curs *apuntador, char *nombre) //imprime los cursos que el profesor tiene disponible	
{
        int k=0, sw=0;
	curs *apuntadorAuxiliar;   
	apuntadorAuxiliar = apuntador;   // hay que utilizar un apondor a auxiliar para que no modifiquemos el apuntador que apunta a la cabeza...
		
	printw("\n\n    Cursos:\n");      
	for(  ; apuntadorAuxiliar != NULL;  apuntadorAuxiliar = apuntadorAuxiliar -> next){
		if( strcmp(nombre, apuntadorAuxiliar-> name_teacher)==0 ){			 
			 printw("%d.  %s\n", ++k, apuntadorAuxiliar-> name_materia );  
		         sw=1;			 
		}
	}       
        if(!sw)
	      printw("\n\nNo tiene cursos!!");
}


nota *definirNotas(nota *apuntador) //define la cantidad de notas y el porcentage de cada una, permite ingresar dentro de una lista enlazada los valores correpondientes
{
	nota *apuntadorAux, *newStruct;
        char identif[20]; 
	int acumulador=0, j, k;      

	newStruct = (nota *)malloc(sizeof(nota));
	
 	if(newStruct != NULL)   // ingresa aqui, en caso de que la creacion dinamica de memoria se exitosa
	{	        
		printw("\nCantidad de notas: ");         // ingresamos por teclado la informacion correpondiente...
		scanw("%d", &newStruct-> num_notas);
	      	        
       
	        newStruct-> apt_ident = (char **) malloc( newStruct-> num_notas * sizeof(char *) );	
       	
	         k=0;
	        for(j=0; j < (newStruct-> num_notas); ++j )
	        {
			    newStruct-> apt_ident[j] = (char *) malloc( 20 * sizeof(char ) );
			    

			    printw("Ingresar el identificador de la nota #%d\n", j+1);
			    scanw("%s", &(newStruct-> apt_ident)[k][j]);			   
	      
		}  	        

	        newStruct-> apt_portj = (int *) malloc( newStruct-> num_notas * sizeof(int) );
	        

	        while(acumulador!=100){
		     acumulador = 0;
		     printw("\nPorcentajes...\n\n");
		     for(j=0; j < (newStruct-> num_notas); ++j )
		     {
			    printw("Valor porcentual de la nota #%d\n", j+1);
			    scanw("%d", &(newStruct-> apt_portj)[j]);
			    acumulador += (newStruct-> apt_portj)[j];
		     }

		     if(acumulador != 100)
		     {
			    erase();
			    printw("\nEl porcentaje total diferente del 100%...Ingrese nuevamente los porcentajes correspondientes\n");
			    
		     }		     
	        }

	}
	return newStruct;
}


curs *buscaMateria(curs *apuntador, int num) //imprime los cursos que el profesor tiene disponible	
{
        int k=0, sw=0;
	curs *apuntadorAux;   

        if(apuntador == NULL){
	      printw("\n\nNo tiene cursos!!");
	      return NULL;
        }
        
	apuntadorAux = apuntador;  //variable global-cabeza de materias... // hay que utilizar un apuntador a auxiliar para que no modifiquemos el apuntador que apunta a la cabeza...
		       
        for(k=1; k< num; ++k)
	     apuntadorAux = apuntadorAux->next;
	printw("\n\nSeleccionó el curso de %s\n", apuntadorAux-> name_materia); 
        if(apuntadorAux-> apt_notasmaterias == NULL )
	      apuntadorAux-> apt_notasmaterias = definirNotas(apuntadorAux-> apt_notasmaterias);        
        else
	      printw("\n\nYa!! definio notas en este curso...");

	return apuntador;				  		       
}


curs *ingresarNotas(usua *apuntador2, int num, curs *apuntador3)   // permite ingresar dentro de una lista enlazada los valores correpondientes
{
	cali *apuntadorAux, *newStruct = NULL;
        curs *apuntadorAux3; 
        char opc, **ident_notas;
        int k, numnotas;

	if(apuntador2 ==NULL)
	        return NULL;

       apuntadorAux3 = apuntador3;  		       	      
        for(k=1; k< num; ++k)
	             apuntadorAux3 = apuntadorAux3->next;

        do
        {
	      newStruct = (cali *)malloc(sizeof(cali));
	      

	      mostrarListaStudiantAProfesor(apuntador2);
	      
	      if(newStruct != NULL)   // ingresa aqui, en caso de que la creacion dinamica de memoria se exitosa
	      {
		     printw("\n\nNumero de cedula: ");
		     scanw("%s", newStruct->Ccdula);

		     while(!buscarCedula(newStruct->Ccdula, apuntador2))
		     {		     
			    printw("\n\nDato incorrecto!!...¡intente nuevamente!\n\n");
			    printw("Numero de cedula: ");
			    scanw("%s", newStruct->Ccdula);
		     } 

		     numnotas= (apuntadorAux3->apt_notasmaterias)->num_notas; // asignamos a esta variable la cantidad de notas

		     newStruct-> notas = (char **) malloc (numnotas * sizeof(char *));                    

		     for(k=0; k < numnotas ; ++k )	
		     {
			    (newStruct-> notas)[k] = (char *) malloc( 7 * sizeof(char) );     
			    strcpy( ((newStruct-> notas)[k]), "NI" );	
		     }     
			    
		    k=0;
		    do      
		     {
			    printw("\n\nIngrese Nota%d: ", k+1);     
			    scanw("%s", (newStruct-> notas)[k]); 			    
			    if(k<numnotas){
				   printw("\n\nDigite un tecla diferente de \"s\" para ingresar otra nota...");	
				   opc = getch();			   
			    }
			    ++k;
			    //if(opc = 's')
				//   break;      		        		     
		     }
		     while( (k<numnotas) && opc != 's');				 
		     
		     if( apuntadorAux3 -> apt_calificaciones == NULL)
		     {
			    apuntadorAux3 -> apt_calificaciones = newStruct;
		     }
		     else
		     {
			    apuntadorAux = apuntadorAux3 -> apt_calificaciones;
			    while( apuntadorAux->sgt != NULL)
				   apuntadorAux = apuntadorAux->sgt;
			    apuntadorAux->sgt = newStruct;
		     }
	      }	
	      printw("\n\nDigite un tecla diferente de \"q\" para ingresar las notas..."); 
	      opc = getch();
        }
        while(opc != 'q');

       return apuntador3;
       
}


int buscarCedula(char *cedula, usua *apuntador) // dice si un numero de cedula ingresado por el usuario esta en la base de datos(usuaPRUEBA)
{
	int sw=0;

	usua *apuntadorAuxiliar;   
	apuntadorAuxiliar = apuntador; //variable global  // hay que utilizar un apondor a _nodo auxiliar para que no modifiquemos la el apuntador que apunta a la cabeza...
		
	for(  ; apuntadorAuxiliar != NULL;  apuntadorAuxiliar = apuntadorAuxiliar -> sig ){
		if( strcmp(cedula, apuntadorAuxiliar-> cedula_usua)==0 ){
			 sw = 1;   
			 break;	
		}
	}

        return !sw ? FALSE:TRUE;
}


void mostrarListaStudiantAProfesor(usua *apuntador)  // imprime en pantalla la lista de usuarios
{
	usua * apuntadorAux;
	int k=1, sw=0;
	apuntadorAux = apuntador;
	
	printw("\n\n    %-20s Cedula\n", "Nombre" ); 
        refresh(); 
	 
	while(apuntadorAux != NULL)
	{
		printw("%d.  %-20s %s\n", k ,apuntadorAux->nombre_usua, apuntadorAux->cedula_usua);		
		apuntadorAux = apuntadorAux -> sig;   
		  
		++k;
		   sw=1; 
	}
	refresh();
	
	if(!sw)
	    printw("\n    ¡Lista vaciá!\n");
	putchar('\n');  
	refresh();  
}


/*void informacionDeMateriaAStudieant(usua *apuntador, curs *apuntador2, char *apodo)  // imprime en pantalla la lista de usuarios
{
	usua * apuntadorAux;
        curs * apuntadorAux2, *apuntadorAux3;
	int k=1, sw=0;
        float acumulado;

	apuntadorAux = apuntador;
	apuntadorAux2 = apuntador2;
        apuntadorAux3 = apuntador2;


       for(  ; apuntadorAux != NULL;  apuntadorAux = apuntadorAux -> sig ){
		if( strcmp(apodo, apuntadorAux-> username)==0 ){

			 printw("\n\nEstudiante: %s(Cc. %s)",apuntadorAux-> nombre_usua, apuntadorAux-> cedula_usua );   			
			 break;	
		}
	}       
       
        while(apuntadorAux2 != NULL)
        {
	      for(  ;  apuntadorAux3-> apt_calificaciones != NULL;   apuntadorAux3-> apt_calificaciones  =  (apuntadorAux3-> apt_calificaciones) -> sgt ){
		     if( strcmp(apuntadorAux-> cedula_usua, (apuntadorAux3-> apt_calificaciones)->Ccdula)==0 ){
			    acumulado =0;   
			    printw("\n\nNombre de la materia: %s\n", apuntadorAux2-> name_materia );
			    printw("Creditos: %s\n", apuntadorAux2-> creditos );   
			    for(k=0; k < (apuntadorAux2->apt_notasmaterias)->num_notas ; ++k )
			    {
					  printw("%s = %d \n", ((apuntadorAux2->apt_notasmaterias)->apt_ident)[k], ((apuntadorAux2->apt_notasmaterias)->apt_portj)[k] );
					  
			    }

			    for(k=0; k < (apuntadorAux2->apt_notasmaterias)->num_notas ; ++k )
			    {
					  printw("%s = %s \n",((apuntadorAux2->apt_notasmaterias)->apt_ident)[k], ((apuntadorAux2->apt_calificaciones)->notas)[k] );
					  if(((apuntadorAux2->apt_calificaciones)->notas)[k] != "NI")
						 acumulado += atof(((apuntadorAux2->apt_calificaciones)->notas)[k]); 
			    }   
			    printw("\nAcumulado = %1.2f", acumulado);   
			    
		     }
	      }
	      apuntadorAux2 = apuntadorAux2->next;
        }

}*/
