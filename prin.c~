#include <ncurses.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cabe.h"	
#include "cabe2.h"

int main(void)
{
	char opc1, opc_stu, AUX, opc1_2, opc_teach, opc_teach_2, opc1_adm, opc_adm2, numCedula[20], rol, nom_materia[20], creditos, opc_adm3;
	char apodo[20], clave[30];			
	int sw, answ, ch, curso;	   // sw y ch, son variables tipo switch
	usua * aptstudent=NULL, *aptteacher=NULL;
          curs *aptmateria=NULL;
		    
	initscr();

	do
	{	
		erase();     
		opc1 = Menu_principal();
		erase(); //opc1= EOF;
		
		switch (opc1)
		{
		       case '1':  printw("Menu_principal/Creacion_una_cuenta_de_usuario");

			        answ=3;   sw=0;   // Inicializacion de variables;
	
                                move(6,4); printw("Identificacion: ");
			        //noecho();		
			        scanw("%s", &numCedula);				
			        //echo();
			        //printw("%s", numCedula);

			        answ = buscarDatoCrearCuenta(aptstudent,numCedula);

			        if(!answ){	    // !answ equivale a answ ==0
				     answ = buscarDatoCrearCuenta(aptteacher,numCedula);
				     sw=1;			
			        }	
			        
			        if(!answ)
  				      printw("\n\nEl numero de cedula ingresado, no esta en registrado!!\n\n");	
				

			        pause();
			        refresh();
		       	        erase();	
		
			        break; 		
				
		       case '2':  //**********Menu de acuerdo al rol************//
			        printw("Menu_principal/Ingresar_a_su_cuenta");	

			        ///*************Ingresar_a_su_cuenta****************		 
			        apodo[0]='\0';   clave[0]='\0';
			        move(6,4);printw("username: ");    	
			        scanw("%s", apodo);	     
		   	        move(8,4);printw("password: ");     
				noecho();
			        scanw("%s", clave);	    
			        echo();

			        ch=1;   answ=3;	 opc1_2='1';	
			        answ = ingresarCuenta(aptstudent, apodo, clave);
	
			        if(!answ){	    // !answ equivale a answ ==0
				     answ = ingresarCuenta(aptteacher, apodo, clave);
				     ch=2;	opc1_2 = '2';	
			        }	
			
			        if( (strcmp(ADMUSERNAME, apodo)==0) && (strcmp(PASSWORD, clave)==0) ){
				     answ=1;  ch=3; opc1_2 = '3';
			        }		
				///***************************************************		    

			        if(!answ){	
				    printw("\n\nError!! Fallo de autentificacion");
				    pause();   break;
			        }		
			        else
			        {					   				   	  
					  erase();
					  switch (opc1_2)
					  {				   
						 case '1':  //*********Menu Estudiante*********//							      
							       							      							      
							       opc_stu = Rol_student();
							       erase();
							       while(opc_stu != '2')
							       {		    
								      if(opc_stu=='1')
								          //informacionDeMateriaAStudieant(aptstudent, aptmateria, apodo);  nos produce un fallo de segmentacion
									     								    						      
								      pause();  erase();								      							
								      opc_stu = Rol_student();
								      erase();

							       }
							       break;	
		     
						 case '2':  //*********Menu Profesor*********//
							       
							do
							{								       
							       erase();
							       opc_teach = Rol_teacher(); 
							       erase();
		     
							       switch (opc_teach)
							       {
								      case '1':  //*********Menu Secundario Profesor*********//
										    
										    do
										    {	   erase();	
											   opc_teach_2 = Rol_second_teacher();
											   erase();			



											   if( (aptmateria == NULL)  && (opc_teach_2 !='4')){
												  printw("\n\nNo tiene cursos!!");  pause();  continue;
										           }
										    
											   switch (opc_teach_2) 		
											   {
												  
												  
												  case '1': 	 //***aqui lista de cursos...despues de seleccionar el curso viene 2menu***//
														printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Profesor/Menu_Secundario_Profesor/Definir_notas");
														
							
														buscarUsername(aptteacher,aptmateria,apodo);
														printw("\n\nSeleccione el curso al cual quiere acceder: ");
														scanw("%d", &curso);

														aptmateria = buscaMateria(aptmateria,curso); // busca el curso correspondiente para definir las notas
														break;

												  case '2':      //****el profesor podrá ver la lista de estudiantes matriculados en******
														printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Profesor/Menu_Secundario_Profesor/Ingresar_notas");
														buscarUsername(aptteacher,aptmateria,apodo);
														printw("\n\nSeleccione el curso al cual quiere acceder: ");
														scanw("%d", &curso);
														aptmateria = ingresarNotas(aptstudent, curso, aptmateria);					      
														break; 
												  case '3':     printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Profesor/Menu_Secundario_Profesor/Ver_notas");
														break;												  
											   }

											   if(opc_teach_2 != '4'){
												  printw("\n\nIngrese cualquier tecla para continuar, o, \"q\" para volver al menu anterior ");	
												  opc_teach_2=getch();
											   }								  
										    }
										    while(opc_teach_2 != 'q');

										    break;

								      case '2':     printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Profesor/Ver_lista_de_clase");
										    printw("\n\nLista de estudiantes matriculados...\n\n");
										    mostrarListaStudiantAProfesor(aptstudent);
										    pause();  erase();
										    break;

								      case '3':     break;  // aqui retorna al menu principal	
								      default :     move(4,4); printw("Opcion no validad.");
										    move(7,4); pause();
										    erase();								  
							       }
						
							}
							while(opc_teach != '3');							      
							break;

						 case '3':  //*********Menu Administrador*********// 							       
							
							do
							{
							       
							       opc1_adm = Rol_Administrator();
							       erase();

							       switch (opc1_adm) 		
							       {
								      case '1': 
										    break;
								      case '2': 
										    break;
								      case '3':  

										    do
										    {
											   erase();
											   printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Administrador/Gestionar_usuarios/");	
											   move(4,4); printw("1. Ver la lista de usuarios");
											   move(5,4); printw("2. Ingresar nuevo usuario");
											   move(6,4); printw("3. <------");	
											   move(8,7); printw("Opcion: ");	
											   opc_adm2 = getch();    erase(); 
											   refresh();  
											   
						 
											   switch (opc_adm2)
											   {
											   
												  case '1':  erase();
													 printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Administrador/Gestionar_usuarios/Ver_la_lista_de_usuarios");	
													 printw("\n\n\nLista Estudiantes\n\n");
													 mostrarListaUsua(aptstudent);  // llamado a una funcion
													 printw("\n\n************************************************\n\nLista Profesores\n\n\n\n");
													 mostrarListaUsua(aptteacher);   // llamado a una funcion
													 pause(); erase();
													 refresh();  
													 break;

												  case '2': 
													 printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Administrador/Gestionar_usuarios/Ingresar_nuevo_usuario");	
													 move(4,4); printw("Para ingresar un nuevo usuario seleccione el rol. (Presione 1 o 2)");											  
													 move(6,4); printw("1. Estudiante"); 	
													 move(7,4); printw("2. Profesor");
													 move(8,4); printw("3. <------");	
													 move(10,7); printw("Opcion: ");												              	
													 rol = getch();  refresh(); 

													 if( (rol == '1') || (rol == '2') )												 	      	      
														printw("\n\nSelccionó %s\n", rol=='1' ? "Estudiante" : "Profesor");	  
														
													 switch (rol)
													 {
														erase();		     
														case '1':  aptstudent = insertarEnUsua(aptstudent);
															   break; 	
														case '2':  aptteacher = insertarEnUsua(aptteacher);
														           break; 	
														case '3':
														           break; 	
														default :  erase(); move(4,4); printw("Opcion no validad.");
														           pause();
														           refresh();		  
													 }		      	

													 if( (rol == '1') || (rol == '2') )
													 {												 	      
														printw("\n\nNuevo usuario ingresadó!!");  pause();
													 }	      
													 refresh();   
													 erase();	      
													 break;

												  case '3':  break;		

												  default:   move(4,4); printw("Opcion no validad.");
													 move(7,4); pause();
													 refresh();  erase();
											   }					     
										    }
										    while( opc_adm2!='3');	
										    
										    break;
								      case '4': 

										    do
										    {
											   erase();	
											   printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Administrador/Gestionar_materias_del_semestre");	
											   move(4,4); printw("1. Ver la lista de materias");
											   move(5,4); printw("2. Ingresar nueva materia");
											   move(6,4); printw("3. <------");	
											   move(8,7); printw("Opcion: ");	
											   opc_adm3 = getch();   erase(); 
											   refresh();  
											   
						 
											   switch (opc_adm3)
											   {
											   
												  case '1':  erase();
													 printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Administrador/Gestionar_materias_del_semestre/Ver_la_lista_de_materias");	
													 printw("\n\n\nLista de Materias\n\n");
													 mostrarListaMateria(aptmateria); 							   			         
													 pause(); erase();
													 refresh();  
													 break;

												  case '2':
													 printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Administrador/Gestionar_materias_del_semestre/Ingresar_nueva_materia");		 
													 printw("\n\n\nPara ingresar una nueva materia, ingrese nombre y #de creditos...\n\n");										
													 printw("Recuerde!. No se dejar espacios en el nombre de la materia.\n\n");
													 aptmateria = insertarEnMaterias(aptmateria,aptteacher); 
													 pause(); refresh();  erase();					
													 break;

												  case '3':  break;		

												  default:   move(4,4); printw("Opcion no validad.");
													 move(7,4); pause();
													 refresh();  erase();
											   }					     
										    }
										    while( opc_adm3!='3');	

										    break;
								      case '5': 
										    break;
								      default:  
										    move(4,4); printw("Opcion no validad.");
										    move(7,4); pause();
										    erase();				

							       }	
							}
							while( opc1_adm!='5' );	
							break;

						 default :  move(4,4); printw("Opcion no validad.");
							    move(7,4); pause();  erase();					     
						 
					  }					  
			        }	

			        break; 

		       case '3':printw("\n\nMini-mares se esta cerrando....");
			        pause(); break;
	
		       default:  move(4,4); printw("Opcion no validad.");
			         move(7,4); pause();  erase();					
			        
		}
	       

	}
        while(opc1 != '3');
	
	endwin();
	

	return 0;
	
}
