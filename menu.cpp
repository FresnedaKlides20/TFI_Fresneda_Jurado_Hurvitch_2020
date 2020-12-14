#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include "libreriamodulito.h"
#include <windows.h>

typedef char cadena[20];
typedef char nombreArchi[20];

void RegistrarVeterinario(FILE *arch1, nombreArchi archiVets);
void RegistrarUsuario(FILE *arch1, int tipoUsuario, nombreArchi archiUsuarios);
void BuscarTurnosAtendidos(FILE *arch1, FILE *arch2, nombreArchi archiVeterinario, nombreArchi archiTurno);
void RankingVeterinarios(FILE *arch1, FILE *arch2, nombreArchi archiVeterinarios, nombreArchi archiTurnos);

main()
{
	FILE *arch1, *arch2, *arch3;
	nombreArchi ArchivoUsuarios = "Usuarios.dat", ArchivoVeterinarios = "Veterinarios.dat", ArchivoTurnos = "Turnos.dat";
    
    AbrirGenerarArchivo(arch1, ArchivoVeterinarios);
	AbrirGenerarArchivo(arch2, ArchivoUsuarios);
	AbrirGenerarArchivo(arch3, ArchivoTurnos);
	
		int caso = 0;
	int registrarVet;
	int registrarAsistente;
	int registrarAdmin;
	int salirPrograma;

	
	
	
	char Usuario[10], Clave[10];
    int iniciar, matricula, salir; 
    bool asistente, veterinario, administrador;
    
    
      system ("color F0");//Cambia el color de la pantalla a blanco
    
    system("cls");
    printf("==========================================================================\n");
	printf("==============================BIENVENIDOS A ==============================\n");
	printf("===========================VETERINARIA CENTRAL ===========================\n");
	printf("======================================================================\n\n\n");
	
	printf("\n\nBienvenido a veterina central para poder ingresar al programa usted debe de  iniciar sesion");


	do
	{
		printf("-------iniciar seccion--------- \n");
		printf("------------------------------- \n");
		printf("\n");
		printf("\n 1-   iniciar seccion como Administraccion");
        printf("\n 2-   iniciar seecion como veterinario ");
        printf("\n 3-   iniciar seccion como Asistente");
        printf("elija una opcion --> ");
	    scanf("%d", &iniciar);
     	system("CLS");
     	
        switch (iniciar)
        {
        	
        	/*1-   iniciar seccion como Administraccion*/
        	
            case 1:
             printf("===========iniciar seccion administracion===============\n");
             printf("========================================================\n");
             printf("============Ingrese un 0 para salir=====================\n\n\n");
             
             printf("\n\n\tUsuario:\n ");//ingresa el usuario de administracion
             _flushall();
             gets(Usuario);
             if (strcmp(Usuario, "0") == 0)//para salir del la seccion administraccion
            {
                break;
            }
            printf("\n\n\Clave:\n ");//ingresa la conraseña de el usuario de administracion
            _flushall();
            gets(Clave);
            scanf("%d", &registrarAdmin);
			if (registrarAdmin == 1)
			{
				system("cls");
				RegistrarUsuario(arch2, 1, ArchivoUsuarios); //El argumento 1 indica que es un administrador
			
            {
                printf("\n\tSesion iniciada correctamente...");
                administrador = true;

                getch();
                system("ModuloAdministracion.exe");
            }
        }
    }
           
            
            

	
	
	
