#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include <windows.h>


main()
{
    char Usuario[10], contrasenia[10];
    int opcion, matricula, salirPrograma;
    bool admin, veterinario, asistente;
    
    
    printf("==========================================================\n");
	printf("==== BIENVENIDOS A LA CLINICA VETERINARIA CENTRAL=======\n");
	printf("======================================================\n\n\n");

    do
    {
     system("CLS");
	printf("=========inicie su seccion en:  =================\n");
	printf("=======================================================\n");
	printf(" 1- Modulo administracion \n");
    printf(" 2- Modulo del Asistente \n");
    printf(" 3- Modulo  consultorio veterinario \n");
	printf(" 4- salir del menu  \n");
    scanf("%d", &opcion);
    system("cls");

        
		switch (opcion)
        {
        case 1:
    	
     	system("CLS");
		printf("=============inicie seccion en administracion ==========\n");
		printf("=======================================================\n");
        printf("===========Ingrese un 0 para salir==================\n\n");

           
		    printf("\n\n\tUsuario Administracion : \n\t> ");
            _flushall();
            gets(Usuario);

            if (strcmp(Usuario, "0") == 0)
            {
                break;
            }

            printf("\n\n\tContrasenia \n\t> ");
            _flushall();
            gets(contrasenia);

            if (inicioAdministracion(Usuario, contrasenia, 1)) //el parametro 1 es para especificar que es un administrador
            {
                printf("\n\tSesion iniciada correctamente...");
                admin = true;

                getch();
                system("ModuloAdministracion.exe");
            }
            else
            {
                printf("\n\tError: usuario o contrasena incorrectos");
            }

            getch();

            break;
        case 2:
        	
       	system("CLS");
		printf("=============inicie seccion en Veterinario ==========\n");
		printf("=======================================================\n");
        printf("===========Ingrese un 0 para salir==================\n\n");
        
        
        printf("\n\n\tMatricula veterinario: \n\t> ");
        scanf("%d", &matricula);

            if (matricula == 0)
            {
                break;
            }

            printf("\n\n\tcontrasenia :\n\t> ");
            _flushall();
            gets(contrasenia);

            if (inicioVeterinario(matricula, contrasenia))
            {
                printf("\n\tSesion iniciada correctamente...");
                veterinario = true;

                getch();
                system("ModuloConsultorio.exe");
            }
            else
            {
                printf("\n\tError: matricula o contrasena incorrecta");
            }

            getch();

            break;
        case 3:
        system("CLS");
		printf("=============inicie seccion Asistente==========\n");
		printf("=======================================================\n");
        printf("===========Ingrese un 0 para salir==================\n\n");

           

            printf("\n\n\tUsuario Asistente \n\t> ");
            _flushall();
            gets(Usuario);

            if (strcmp(Usuario, "0") == 0)
            {
                break;
            }

            printf("\n\n\tcontrasenia\n\t> ");
            _flushall();
            gets(contrasenia);

            if (incioAsistente(Usuario, contrasenia, 3)) //el parametro 3 es para especificar que es un asistente
            {
                printf("\n\tSesion iniciada correctamente...");
                asistente = true;

                getch();
                system("ModuloAsistente.exe");
            }
            else
            {
                printf("Error: usuario o contrasena incorrectos");
            }

            getch();

            break;
        case 4:
            printf("\n\tSeguro que desea salir?");
            printf("\n\n\t1.Si");
            printf("\n\n\t2.No");
             printf("\n\t> ");

            scanf("%d", &salirPrograma);

            if (salirPrograma != 1)
            {
                opcion = 1;
            }
            break;
        }

    } while (opcion != 4);
}


