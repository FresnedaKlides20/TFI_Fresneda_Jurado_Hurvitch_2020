
/*
********************************************************************** 
prototipos   de structuras  
*********************************************************************
*/

struct Fecha_de_Nacimiento 
{
char anio [4];
int mes;
int dia;	
};
 struct Usuarios

{
char  Usuario[10] ;
char  Contrasenia[10] ;
char Apellido_y_Nombre[60] ; 

	
};
struct Veterinario
{
char Apellido_y_Nombre[60] ;
int Matricula ;
int Dni ;
char Telefono [10];
	
	
};

struct Mascota
{
char Apellido_y_Nombre [60];
 char Domicilio  [60];
int DNI_Duenio; 
 char Localidad  [60];
Fecha_de_Nacimiento Fecha;
float Peso ;
char Telefono [25];
	

};
struct Turnos
{
int Matricula_de_Veterinario;
int DNI_Duenio;
Fecha_de_Nacimiento fecha;
char Detalle_de_Atencion [380];
int ac;	
};

