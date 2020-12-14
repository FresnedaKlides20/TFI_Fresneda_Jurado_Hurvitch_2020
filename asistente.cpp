#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
#include "proto.h"
/*
********************************************************************** 
prototipos de funciones  
*********************************************************************
*/	
void contrasenia( Usuarios uno,int &ab ); // verifica que la contraeña del archivo y la ingresada sean igules .si es asi asigan valor 1 a un puntero
void asg_mascota(Mascota uno); // carga mascotas	
void asg_turnos(Turnos uno);
void clave(char cadena[10]);
void rrak();

main ()
{
Veterinario list1;Turnos list2;Usuarios list,admin;Mascota list3;
  

	
	system("color 37");
	
int comp=1,band=1,SW_2;
int cp1=0;
	setlocale(LC_ALL, "spanish"); /* Permite imprimir caracteres con tilde */
while(band!=0) 
{



	system("cls");
printf("\t============================================================\n");			
printf(" \tModulo del Asistente\n");	
printf("\t============================================================\n");	
printf("\t----------------------------------------------------------\n");			
printf(" \t\t2.- Iniciar Sesión\n");		
printf(" \t\t3.- Registrar Mascota\n");		
printf(" \t\t4.- Registrar Turno \n");		
printf(" \t\t5.- Cerrar la aplicación.\n");		
printf("\t----------------------------------------------------------\n");				
printf("\t\tIngrese una opción:  [ ]\b\b");		
scanf("%i",&SW_2);
	
switch(SW_2)	

{
case 2:
contrasenia(list,cp1);	
break;	
case 3:
if ( cp1 ==0)
{
		
printf ("\tpor favor inicie seción ");
getch();}
else
asg_mascota( list3 );
break;	
case 4:
if ( cp1 ==0)	{

printf ("\tpor favor inicie seción ");
getch();}
else
asg_turnos(list2);
break;	
case 5:
exit(1);
break;
}
	
	
_flushall();
printf("\n");		
printf(" \t desea continuar? \n \t0 salir Y 1 continuar [ ]\b\b");	
scanf("%i",&band);	
} 
}

void asg_turnos(Turnos uno)

{
FILE*arch3; int c=0;
c++;
arch3=fopen("Turnos.dat","a+b");
printf(" \t\t\tingrese el dni  del  Dueño "); 	
scanf("%d",&uno.DNI_Duenio);
printf("\t\t\tingrese fecha de atencion dia/mes/año\t") ;	
printf("\t\t\t\t\tingrese dia \t") ;	
scanf("%d",&uno.fecha.dia);
_flushall();
printf("\t\t\tingrese /mes/\t") ;
scanf("%d",&uno.fecha.mes);
_flushall();
printf("\t\t\tingrese/año\t") ;
gets(uno.fecha.anio);
printf("\t\t\tingrese la Matruicula "); 
scanf ("%d",&uno.Matricula_de_Veterinario);
fwrite(&uno,sizeof(Turnos),1,arch3);
fclose(arch3);

}



void clave(char *cadena[10]){
	int i = 0;	/* Indica la posición del caracter leído en la cadena */
	char caracter = getch();
	while (i < 10 && caracter != 13) {
		*cadena[i] = caracter;
		i++;
		printf("*");
		caracter = getch();
	}
	cadena[i] = '\0';
}

void contrasenia( Usuarios uno,int &ab ) {
	ab=0;	char aux [10]; char nick [10];
	FILE*arch;
	arch=fopen("Usuarios.dat","r+b");
	if(arch == NULL) {
		system("CLS");
		printf("\n\n Se produjo un ERROR al intentar abrir el archivo\n");
		printf("el archivo no a sido creado. Gracias");
		printf("\n\n\t");
		system("PAUSE");
		exit(1);
	}

	else
 
 
    	

    printf("\nIniciar Seción: \n");
	printf("\n\tUsuario: ");
	_flushall();
	gets(nick);
    printf("\tClave: ");
    clave(aux);
    fread(&uno,sizeof(Usuarios),1,arch);
    while (!feof(arch))
    {if (strcmp(aux,uno.Contrasenia)==0 ,strcmp(aux,uno.Contrasenia)==0  )
    {system("color 35");
	printf("\t\t bienvenido");
	printf("\n\t\t---------------%s----------------",uno.Apellido_y_Nombre);
		printf("\n");
	ab=1;
	getch();}
	
		 else {	
		 printf("\n\t\t\t\t\tintente luego");
		 	ab=0;}
       
     fread(&uno,sizeof(Usuarios),1,arch);
    }
    fclose(arch);
		

	
}

void asg_mascota(Mascota uno)
{

FILE*arch1;
arch1=fopen("mascotas.dat","ab+");
_flushall();
printf("\t\t\tingresa Apellido y Nombre\t");
gets(uno.Apellido_y_Nombre);
_flushall();
printf("\t\t\tingresa Localidad\t");
gets(uno.Localidad );
_flushall();
printf("\t\t\tingresa domicilio\t");
gets(uno.Domicilio );
_flushall();
printf("\t\t\tingresa Dni del dueño\t");
scanf("%d",&uno.DNI_Duenio );
_flushall();
printf("\t\t\tingresa Telefono\t");
gets(uno.Telefono );
_flushall();
printf("\t\t\tingresa Peso\t");
scanf("%f",&uno.Peso );
_flushall();
printf("\t\t\tingresa fecha de naciminto /d/m/año/\n");
printf("\t\t\tingresa fecha de naciminto /d/ ");
/*scanf("%d",&uno.fecha.dia );	*/
_flushall();
printf("\t\t\tingresa fecha de naciminto /m/ ");
/*scanf("%d",&uno.Fecha.mes );*/
_flushall();
printf("\t\t\tingresa fecha de naciminto /año/ ");
/*gets(uno.Fecha.anio );*/
fwrite(&uno,sizeof(Mascota),1,arch1);
fclose(arch1);

}



