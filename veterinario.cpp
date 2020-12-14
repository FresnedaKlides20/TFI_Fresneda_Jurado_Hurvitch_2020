#include<stdio.h>
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

void contrasenia_matricula( Veterinario uno,int &ab );
void log_veterinario(Veterinario uno );	
void detalle (Turnos dos );
void listar(); //  lista
void clave(char cadena[10]);

main ()
{
Veterinario list1;Turnos list2;
  
setlocale(LC_ALL, "spanish"); /* Permite imprimir caracteres con tilde */
system("color 5f");
char linea[80];	
int comp=1,band=1,SW_1;
int cp=0;

while(band!=0)
{



	system("CLS");
	
printf("\t============================================================\n");			
printf(" \tModulo Consultorio Veterinario\n");		
printf("\t============================================================\n");	
printf("\t----------------------------------------------------------\n");		
printf(" \t\t2.- Iniciar Sesión\n");		
printf(" \t\t3.- Visualizar Lista de Espera de Turnos (informe)\n");		
printf(" \t\t4.- Registrar Evolución de la Mascota \n");		
printf(" \t\t5.- Cerrar la aplicación.\n");		
printf("\t----------------------------------------------------------\n");				
printf("\t\tIngrese una opción:  [ ]\b\b");	

	
scanf("%i",&SW_1);
switch(SW_1)	
{
case 2:
contrasenia_matricula( list1,cp );	
getch();

break;	
case 3:
if ( cp==0)	
printf ("\tpor favor inicie seción ");
else

listar();
getch();

break;	
case 4:
if ( cp==0)
{printf ("\tpor favor inicie seción ");

	}
else

detalle(list2);
getch();
break;	
case 5:	
exit(1);
break;	
}
_flushall();
printf("\n ");		
printf(" \t desea continuar? \n \t0 salir Y 1 continuar [ ]\b\b");	
scanf( "%i", &band);
 
} ;




	
}

void detalle (Turnos dos)
{
FILE*arch2;
int dni;

arch2=fopen("Turnos.dat","r+");
fread(&dos,sizeof(Turnos),1,arch2);
while(!feof(arch2))
{printf ("ingrese dni del dueño :");
scanf("%d",&dni);
if(dni==dos.DNI_Duenio)
{printf("\t\t\t ingrese dettalle de atención max 380 palabras \n ");	
_flushall();
gets(dos.Detalle_de_Atencion);
fwrite(&dos.Detalle_de_Atencion,sizeof(Turnos),1,arch2);
}else
fread(&dos,sizeof(Turnos),1,arch2);
}
fread(&dos,sizeof(Turnos),1,arch2);
fclose(arch2);	

}



void clave(char cadena[10]){
	int i = 0;	/* Indica la posición del caracter leído en la cadena */
	char caracter = getch();
	while (i < 10 && caracter != 13) {
		cadena[i] = caracter;
		i++;
		printf("*");
		caracter = getch();
	}
	cadena[i] = '\0';
}
	

void contrasenia_matricula( Veterinario uno,int &ab )
{

FILE*arch; int org,contra ,intento=0; char aux[10]; 
arch=fopen("Veterinarios.dat","r+b");
rewind(arch);
while(  intento<3 )
{printf("\t ingrese Matricula:\t");	
_flushall();
clave(aux);
sscanf(aux,"%d",&contra);
fread(&uno,sizeof(Veterinario),1,arch);
if(uno.Matricula==contra) 
{
	system("color 5b");
	ab=1;printf(" \n\t____________Bienvenido doc %s____________",uno.Apellido_y_Nombre);
	intento=3;
}
	else
	{printf("\n\t\t\tintente luego : la matricula no corresponde\n");
	ab=0;	

	}
	fread(&org,sizeof(Veterinario),1,arch);
	intento++;

}

fclose(arch);
}


 // crea turnos
void listar()
{
	
FILE*tur;FILE*med;FILE*masc;	
tur=fopen("Turnos.dat","r+b");
med=fopen("Veterinarios.dat","r+b");
masc=fopen("mascotas.dat","r+b");
Turnos t; Veterinario m;Mascota ms;
int i=0;	int ac;		
system("cls");
printf("Ha seleccionado la opcion 'Visualizar lista de espera de pacientes', la lista se mostrara a continuacion: ");
fread(&m,sizeof(Veterinario),1,med);
fread(&t,sizeof(Turnos),1,tur);
fread(&ms,sizeof(Mascota),1,masc);
printf("\nLista de espera: \n");
while(!feof(med)||!feof(tur)||!feof(masc)){
if(m.Matricula==t.Matricula_de_Veterinario){
	
printf("\nTurno %d:",i+1);

printf("\n________________________________________\n");
printf("\nFecha:");
printf("\n\n /%s/%d/%d/",t.fecha.anio,t.fecha.mes,t.fecha.dia);
printf("\n ________________________________________\n");
printf("\nDNI del Dueño: %d", t.DNI_Duenio);
printf("\n ________________________________________\n");
}
else
fread(&m,sizeof(Veterinario),1,med);
fread(&t,sizeof(Turnos),1,tur);

if(ms.DNI_Duenio==t.DNI_Duenio)
{

printf("\nNombre y apellido:%s",ms.Apellido_y_Nombre);
printf("\n ________________________________________\n");
printf("\ndomicillio:%s",ms.Domicilio);
printf("\n ________________________________________\n");
printf("\nLocalidad:%s",ms.Localidad);
printf("\n ________________________________________\n");
printf("\nTelefono :%s",ms.Telefono);
printf("\n ________________________________________\n");
printf(" peso: %2.f  ", ms.Peso);
printf("\n ________________________________________\n");
printf("Fecha de nacimiento /%s/%i/%d/", ms.Fecha.anio,ms.Fecha.mes,ms.Fecha.dia);
printf("\n ________________________________________\n");
}
else

fread(&ms,sizeof(Mascota),1,masc);
i++;
}

fclose(med);
fclose(tur);
fclose(masc);
}
 //  lista



#include<stdio.h>
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

void contrasenia_matricula( Veterinario uno,int &ab );
void log_veterinario(Veterinario uno );	
void detalle (Turnos dos );
void listar(); //  lista
void clave(char cadena[10]);

main ()
{
Veterinario list1;Turnos list2;
  
setlocale(LC_ALL, "spanish"); /* Permite imprimir caracteres con tilde */
system("color 5f");
char linea[80];	
int comp=1,band=1,SW_1;
int cp=0;

while(band!=0)
{



	system("CLS");
	
printf("\t============================================================\n");			
printf(" \tModulo Consultorio Veterinario\n");		
printf("\t============================================================\n");	
printf("\t----------------------------------------------------------\n");		
printf(" \t\t2.- Iniciar Sesión\n");		
printf(" \t\t3.- Visualizar Lista de Espera de Turnos (informe)\n");		
printf(" \t\t4.- Registrar Evolución de la Mascota \n");		
printf(" \t\t5.- Cerrar la aplicación.\n");		
printf("\t----------------------------------------------------------\n");				
printf("\t\tIngrese una opción:  [ ]\b\b");	

	
scanf("%i",&SW_1);
switch(SW_1)	
{
case 2:
contrasenia_matricula( list1,cp );	
getch();

break;	
case 3:
if ( cp==0)	
printf ("\tpor favor inicie seción ");
else

listar();
getch();

break;	
case 4:
if ( cp==0)
{printf ("\tpor favor inicie seción ");

	}
else

detalle(list2);
getch();
break;	
case 5:	
exit(1);
break;	
}
_flushall();
printf("\n ");		
printf(" \t desea continuar? \n \t0 salir Y 1 continuar [ ]\b\b");	
scanf( "%i", &band);
 
} ;




	
}

void detalle (Turnos dos)
{
FILE*arch2;
int dni;

arch2=fopen("Turnos.dat","r+");
fread(&dos,sizeof(Turnos),1,arch2);
while(!feof(arch2))
{printf ("ingrese dni del dueño :");
scanf("%d",&dni);
if(dni==dos.DNI_Duenio)
{printf("\t\t\t ingrese dettalle de atención max 380 palabras \n ");	
_flushall();
gets(dos.Detalle_de_Atencion);
fwrite(&dos.Detalle_de_Atencion,sizeof(Turnos),1,arch2);
}else
fread(&dos,sizeof(Turnos),1,arch2);
}
fread(&dos,sizeof(Turnos),1,arch2);
fclose(arch2);	

}



void clave(char cadena[10]){
	int i = 0;	/* Indica la posición del caracter leído en la cadena */
	char caracter = getch();
	while (i < 10 && caracter != 13) {
		cadena[i] = caracter;
		i++;
		printf("*");
		caracter = getch();
	}
	cadena[i] = '\0';
}
	

void contrasenia_matricula( Veterinario uno,int &ab )
{

FILE*arch; int org,contra ,intento=0; char aux[10]; 
arch=fopen("Veterinarios.dat","r+b");
rewind(arch);
while(  intento<3 )
{printf("\t ingrese Matricula:\t");	
_flushall();
clave(aux);
sscanf(aux,"%d",&contra);
fread(&uno,sizeof(Veterinario),1,arch);
if(uno.Matricula==contra) 
{
	system("color 5b");
	ab=1;printf(" \n\t____________Bienvenido doc %s____________",uno.Apellido_y_Nombre);
	intento=3;
}
	else
	{printf("\n\t\t\tintente luego : la matricula no corresponde\n");
	ab=0;	

	}
	fread(&org,sizeof(Veterinario),1,arch);
	intento++;

}

fclose(arch);
}


 // crea turnos
void listar()
{
	
FILE*tur;FILE*med;FILE*masc;	
tur=fopen("Turnos.dat","r+b");
med=fopen("Veterinarios.dat","r+b");
masc=fopen("mascotas.dat","r+b");
Turnos t; Veterinario m;Mascota ms;
int i=0;	int ac;		
system("cls");
printf("Ha seleccionado la opcion 'Visualizar lista de espera de pacientes', la lista se mostrara a continuacion: ");
fread(&m,sizeof(Veterinario),1,med);
fread(&t,sizeof(Turnos),1,tur);
fread(&ms,sizeof(Mascota),1,masc);
printf("\nLista de espera: \n");
while(!feof(med)||!feof(tur)||!feof(masc)){
if(m.Matricula==t.Matricula_de_Veterinario){
	
printf("\nTurno %d:",i+1);

printf("\n________________________________________\n");
printf("\nFecha:");
printf("\n\n /%s/%d/%d/",t.fecha.anio,t.fecha.mes,t.fecha.dia);
printf("\n ________________________________________\n");
printf("\nDNI del Dueño: %d", t.DNI_Duenio);
printf("\n ________________________________________\n");
}
else
fread(&m,sizeof(Veterinario),1,med);
fread(&t,sizeof(Turnos),1,tur);

if(ms.DNI_Duenio==t.DNI_Duenio)
{

printf("\nNombre y apellido:%s",ms.Apellido_y_Nombre);
printf("\n ________________________________________\n");
printf("\ndomicillio:%s",ms.Domicilio);
printf("\n ________________________________________\n");
printf("\nLocalidad:%s",ms.Localidad);
printf("\n ________________________________________\n");
printf("\nTelefono :%s",ms.Telefono);
printf("\n ________________________________________\n");
printf(" peso: %2.f  ", ms.Peso);
printf("\n ________________________________________\n");
printf("Fecha de nacimiento /%s/%i/%d/", ms.Fecha.anio,ms.Fecha.mes,ms.Fecha.dia);
printf("\n ________________________________________\n");
}
else

fread(&ms,sizeof(Mascota),1,masc);
i++;
}

fclose(med);
fclose(tur);
fclose(masc);
}
 //  lista




