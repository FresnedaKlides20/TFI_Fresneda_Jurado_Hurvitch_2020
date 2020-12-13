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


main ()
{
Veterinario list1;Turnos list2;
  
setlocale(LC_ALL, "spanish"); /* Permite imprimir caracteres con tilde */
system("color 5f");
	
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
printf("\t\tIngrese una opción: [] ");	

	
scanf("%i",&SW_1);
switch(SW_1)	
{
case 2:
contrasenia_matricula( list1,cp );	

printf("\n \t\t_____________________Bienvenido doc %s _____________________",list1.Apellido_y_Nombre);
getch();
break;	
case 3:
if ( cp ==0)	
printf ("\tpor favor inicie seción ");
else
system("color 53");
listar();

getch();
break;	
case 4:
if ( cp ==0)
{printf ("\tpor favor inicie seción ");
getch();
	}
else
system("color 53");
detalle(list2);
break;	
case 5:	
band=0;
break;	
}
		
printf(" \t\t\t desea continuar? \n \t\t\t[0 salir Y 1 continuar]");	
scanf("%i \n",&band);	
} ;




	
}

void detalle (Turnos dos)
{
FILE*arch3;
arch3=fopen("Turnos.dat","w+b");	
int dn_cp;
printf("\t\t\t ingrese dni del dueño \n ");	
scanf("%i",&dn_cp);


		
if (dn_cp==dos.DNI_Duenio)	
{
printf("\t\t\t ingrese dettalle de atención max 380 palabras \n ");	
gets(dos.Detalle_de_Atencion);
fwrite(&dos.Detalle_de_Atencion,sizeof(Turnos),1,arch3);
}
	fclose(arch3);

	
}
	


	

void contrasenia_matricula( Veterinario uno,int &ab )
{

FILE*arch; int org,contra ,intento=0;
arch=fopen("Veterinarios.dat","r+b");
rewind(arch);
while(  intento<3 )
{printf("\t ingrese Matricula");	
_flushall();
scanf("%i",&contra);
fread(&org,sizeof(Veterinario),1,arch);
if(org==contra) 
{
	printf("\t\t\t\t\tbienvenido\n");
	ab=1;
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
masc=fopen("Mascota.dat","r+b");
Turnos t; Veterinario m;Mascota ms;
int i=0;			
system("cls");
printf("Ha seleccionado la opcion 'Visualizar lista de espera de pacientes', la lista se mostrara a continuacion: ");
fread(&m,sizeof(Veterinario),1,med);
fread(&t,sizeof(Turnos),1,tur);
printf("\nLista de espera: \n");
while(!feof(med)||!feof(tur)){
if(m.Matricula==t.Matricula_de_Veterinario){
printf("\nTurno %d:",i+1);
printf("\nFecha:");
printf("\n\nDia: %d",t.fecha.dia);
printf("\nMes: %d",t.fecha.mes);
printf("\nAño: %d",t.fecha.anio);
printf("\nDNI del Dueño: %d", t.DNI_Duenio);
printf("\nNombre: %s",ms.Apellido_y_Nombre);
printf("\ndomicilio: %s",ms.Domicilio);
printf("\npeso: %s",ms.Apellido_y_Nombre);
printf("\n localidad: %s",ms.Localidad);
printf("\nTelefono: %s",ms.Telefono);
printf("\nPeso: %2.f",ms.Peso);
printf("\nfecha de nacimiento: %s/%i/%i",ms.Fecha.anio,ms.Fecha.mes,ms.Fecha.dia);
fread(&m,sizeof(Veterinario),1,med);
fread(&t,sizeof(Turnos),1,tur);
fread(&masc,sizeof(Mascota),1,masc);
}
else{
	fread(&m,sizeof(Veterinario),1,med);
fread(&t,sizeof(Turnos),1,tur);
fread(&masc,sizeof(Mascota),1,masc);
					}
				}
				
				fclose(med);
				fclose(tur);
				fclose(masc);
		}

 //  lista




