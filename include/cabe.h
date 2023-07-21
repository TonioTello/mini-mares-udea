#define ESTUDIANTE 0
#define PROFESOR 1
#define TRUE 1
#define FALSE 0
#define ADMUSERNAME  "administrador"
#define PASSWORD "mares"

struct usuarios {

	char nombre_usua[20];
	char cedula_usua[15];
	char username[20];
	char password[30];
	struct usuarios *sig;
};



struct notasmaterias {          
	
	int num_notas;
	char **apt_ident;             
          int *apt_portj;        
};


	
struct materias{

	char name_materia[20];
	int creditos;
	char name_teacher[20];
	struct calificaciones * apt_calificaciones;
	struct notasmaterias *apt_notasmaterias; 	
          struct materias *next; 
};

struct calificaciones{
       char Ccdula[15];
       char **notas;
       struct calificaciones *sgt;       
};

typedef struct materias curs;
typedef struct usuarios usua;
typedef struct calificaciones cali;
typedef struct notasmaterias  nota;

void pause(void);
char Menu_principal();
char Rol_student();
char Rol_teacher();
char Rol_second_teacher();
char Rol_Administrator();



