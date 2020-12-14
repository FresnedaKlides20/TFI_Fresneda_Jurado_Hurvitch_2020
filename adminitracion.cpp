#include <stdio.h>
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
void log_user(Usuarios dos ); // carga usuarios
void log_use1(Usuarios dos ); // carga usuarios
void log_veterinario(Veterinario uno );
void ranking();
void clave(char cadena[10]);

main () {
	Veterinario list1;
	Turnos list2;
	Usuarios list,admin;
	Mascota list3;
  


	system("color 30");

	int comp=1,band=1,band_C=1,band_R=1,band_G=1,sw,SW_1,SW_2,SW_3,cnat;
	int cp=0,cp1=0,cp2=0;
	setlocale(LC_ALL, "spanish"); /* Permite imprimir caracteres con tilde */
	while(band!=0) {






		system("cls");
		printf("\t============================================================\n");
		printf(" \t\t\t\t\t\ttMódulo Administración\n");
		printf("\t============================================================\n");
		printf("\t----------------------------------------------------------\n");
		printf(" \t\t1.- Iniciar Sesión\n");
		printf(" \t\t2.- Registrar Veterinario\n");
		printf(" \t\t3.- Registrar Usuario Admin  \n");
		printf(" \t\t4.- Registrar Usuario Asistente  \n");
		printf(" \t\t5.- Atencioness por veterinarios  \n");
		printf("\t\t==================================\n");
		printf(" \t\t6.- Cerrar la aplicación.\n");
		printf("\t----------------------------------------------------------\n");
		printf("\t\tIngrese una opción:  [ ]\b\b");	
	
		scanf("%i",&SW_3);
		switch(SW_3)

		{
			case 1:
				contrasenia(admin,cp2);
			
				break;
			case 2:
				if ( cp2==0)	{

					printf ("\tpor favor inicie seción ");
					getch();
				} else
					log_veterinario(list1);
				break;
			case 3:
				log_use1(admin);
				break;
			case 4:
				if ( cp2==0)	{

					printf ("\tpor favor inicie seción ");
					getch();
				} else
				
					log_user(list);
				break;
			case 5:
				if ( cp2==0)	{

					printf ("\tpor favor inicie seción ");
					getch();
				} else 
					ranking();
			
				

					break;	
					case 6:
						
				    exit(1);
					break;
		}
		_flushall();	
		printf("\n ");	
printf(" \t desea continuar? \n \t0 salir Y 1 continuar [ ]\b\b");	
		scanf("%i",&band);



	}


}

void log_user( Usuarios uno ) {

	FILE*arch1;
	arch1=fopen("Usuarios.dat","ab+");
	

	bool b1, b2 , b3, b4, b5;
		bool aceptar; 
			
				char aux[20];
	_flushall();
	printf("\t\t\tingrese el Apellido y nombre  a registrar ");
	gets (uno.Apellido_y_Nombre);
	
	printf("\t\t\tingrese la ID usuario a registrar \n");
	
				system("cls");
				int cm=0, cn=0,i=0;
			
				printf("\nHa seleccionado 'Registrar Usuario Recepcion', por favor ingrese los datos que se solicitan a continuacion: \n\n");
				printf("Nombre de usuario \n(Tiene que comenzar con una letra minuscula, tener al menos 2 mayusculas, y no mas de 3 digitos): ");
				_flushall();
				gets(aux);
				b1=false; b2=false; b3=false; b4=false; b5=false;
				/*
				b1==Sea unico para cada usuario*
				b2==Comenzar con una letra minuscula*
				b3==Tener al menos 2 letras mayusculas*
				b4==Tener como maximo 3 digitos*
				b5==Cantidad de caracteres*
				
				*/
		    	while(b1==false && b2==false && b3==false && b4==false && b5==false){
					rewind(arch1);
    				fread(&uno,sizeof(Usuarios),1,arch1);
					while(!feof(arch1)){
						if(strcmp(aux,uno.Usuario)){
							printf("\nEste nombre de usuario ya existe, por favor digite otro: ");
							gets(aux);
							b1=false;	
						}
						else{
							b1=true;
						}
					}
							
							
					if(aux[0]=='q' ||	aux[0]=='w' || aux[0]=='e' || aux[0]=='r' || aux[0]=='t' || aux[0]=='y' || aux[0]=='u' || aux[0]=='i' || aux[0]=='o' || aux[0]=='p' || aux[0]=='a' || aux[0]=='s' || aux[0]=='d' || aux[0]=='f' || aux[0]=='g' || aux[0]=='h' || aux[0]=='j' || aux[0]=='k' || aux[0]=='l' || aux[0]=='ñ' || aux[0]=='z' || aux[0]=='x' || aux[0]=='c' || aux[0]=='v' || aux[0]=='b' || aux[0]=='n' || aux[0]=='m'){
						b2=true;
					}
					else{
						b2=false;
						printf("El nombre no comienza con minuscula, por favor digite otro: ");
						gets(aux);
					}
																													
					for(i=0;i<20;i++){
						if(aux[i]=='A'||aux[i]=='B'||aux[i]=='C'||aux[i]=='D'||aux[i]=='E'||aux[i]=='F'||aux[i]=='G'||aux[i]=='H'||aux[i]=='I'||aux[i]=='J'||aux[i]=='K'||aux[i]=='L'||aux[i]=='M'||aux[i]=='N'||aux[i]=='O'||aux[i]=='P'||aux[i]=='Q'||aux[i]=='R'||aux[i]=='S'||aux[i]=='T'||aux[i]=='U'||aux[i]=='V'||aux[i]=='W'||aux[i]=='X'||aux[i]=='Y'||aux[i]=='Z'){
							cm++;
						}
					}
					if(cm<2){
						printf("\nNo posee 2 mayusculas o mas, por favor digite otro:  ");
						gets(aux);
						b3=false;
					}
					else{
						b3=true;
					}
					for(i=0;i<20;i++){
						if(aux[i]=='1'){
							cn++;
						}
						else{
							if(aux[i]=='2'){
								cn++;
							}
							else{
								if(aux[i]=='3'){
									cn++;
								}
								else{
									if(aux[i]=='4'){
										cn++;	
						   			}
						   			else{
						   				if(aux[i]=='5'){
						   					cn++;
									    }
									    else{
									    	if(aux[i]=='6'){
									    		cn++;
											}
											else{
												if(aux[i]=='7'){
													cn++;
												}
												else{
													if(aux[i]=='8'){
														cn++;
													}
													else{
														if(aux[i]=='9'){
															cn++;
														}
														else{
															if(aux[i]=='0'){
																cn++;
															}
														}
													}
												}
											}
										}
								    }
								}
							}
						}
					}
					
					if(cn>3){
						printf("\nEl maximo de numeros permitidos es 3, por favor digite otro: ",cn);
						gets(aux);
						b4=false;
					}
					else{
						b4=true;
					}
					if(strlen(aux)>10 || strlen(aux)<6){
						printf("\nEl tama%co del nombre no es valido, por favor digite otro: ",164);
						gets(aux);
						b5=false;
					}
					else{
						b5=true;
						strcpy(aux,uno.Usuario);
					}				
				} 
				
	printf("\t\t\tingrese la contraseña de usuarios a registrar ");
		
		
		
		
	printf("\nIngrese la contraseña para el usuario, debe cumplir con las siguientes caracteristicas: \na) Poseer al menos, una letra mayuscula, una minuscula y un numero\nb) No debe poseer caracteres de puntuacion, solo letras y numeros\nc) De entre al menos 6 y 32 caracteres\nd) No debe tener mas de 3 numeros consecutivos\ne) No debe contener 2 caracteres que se refieran a letras alfabeticamente consecutivas (ascendentes)\nIngrese la contraseña: ");
				_flushall();
	gets(uno.Contrasenia);
				aceptar=false;
				
				while(aceptar==false){
				if(strstr(uno.Contrasenia,"Q")==NULL && strstr(uno.Contrasenia,"W")==NULL && strstr(uno.Contrasenia,"E")==NULL && strstr(uno.Contrasenia,"R")==NULL && strstr(uno.Contrasenia,"T")==NULL && strstr(uno.Contrasenia,"Y")==NULL && strstr(uno.Contrasenia,"U")==NULL && strstr(uno.Contrasenia,"I")==NULL && strstr(uno.Contrasenia,"O")==NULL && strstr(uno.Contrasenia,"P")==NULL && strstr(uno.Contrasenia,"A")==NULL && strstr(uno.Contrasenia,"S")==NULL && strstr(uno.Contrasenia,"D")==NULL && strstr(uno.Contrasenia,"F")==NULL && strstr(uno.Contrasenia,"G")==NULL && strstr(uno.Contrasenia,"H")==NULL && strstr(uno.Contrasenia,"J")==NULL && strstr(uno.Contrasenia,"K")==NULL && strstr(uno.Contrasenia,"L")==NULL && strstr(uno.Contrasenia,"Ñ")==NULL && strstr(uno.Contrasenia,"Z")==NULL && strstr(uno.Contrasenia,"X")==NULL && strstr(uno.Contrasenia,"C")==NULL && strstr(uno.Contrasenia,"V")==NULL && strstr(uno.Contrasenia,"B")==NULL && strstr(uno.Contrasenia,"N")==NULL && strstr(uno.Contrasenia,"M")==NULL)
				{
					printf("La contraseña no posee mayuscula, ingrese de nuevo la contraseña");
					_flushall;
					gets(uno.Contrasenia);
				}
				else
				{	if(strstr(uno.Contrasenia,"q")==NULL && strstr(uno.Contrasenia,"w")==NULL && strstr(uno.Contrasenia,"e")==NULL && strstr(uno.Contrasenia,"r")==NULL && strstr(uno.Contrasenia,"t")==NULL && strstr(uno.Contrasenia,"y")==NULL && strstr(uno.Contrasenia,"u")==NULL && strstr(uno.Contrasenia,"i")==NULL && strstr(uno.Contrasenia,"o")==NULL && strstr(uno.Contrasenia,"p")==NULL && strstr(uno.Contrasenia,"a")==NULL && strstr(uno.Contrasenia,"s")==NULL && strstr(uno.Contrasenia,"d")==NULL && strstr(uno.Contrasenia,"f")==NULL && strstr(uno.Contrasenia,"g")==NULL && strstr(uno.Contrasenia,"H")==NULL && strstr(uno.Contrasenia,"j")==NULL && strstr(uno.Contrasenia,"k")==NULL && strstr(uno.Contrasenia,"l")==NULL && strstr(uno.Contrasenia,"ñ")==NULL && strstr(uno.Contrasenia,"z")==NULL && strstr(uno.Contrasenia,"x")==NULL && strstr(uno.Contrasenia,"c")==NULL && strstr(uno.Contrasenia,"v")==NULL && strstr(uno.Contrasenia,"b")==NULL && strstr(uno.Contrasenia,"n")==NULL && strstr(uno.Contrasenia,"m")==NULL)
				{
					printf("La contraseña no posee mayuscula, ingrese de nuevo la contraseña");
					_flushall;
					gets(uno.Contrasenia);
					}
					else
					{
						if(strstr(uno.Contrasenia,"0")==NULL && strstr(uno.Contrasenia,"1")==NULL && strstr(uno.Contrasenia,"2")==NULL && strstr(uno.Contrasenia,"3")==NULL && strstr(uno.Contrasenia,"4")==NULL && strstr(uno.Contrasenia,"5")==NULL && strstr(uno.Contrasenia,"6")==NULL && strstr(uno.Contrasenia,"7")==NULL && strstr(uno.Contrasenia,"8")==NULL && strstr(uno.Contrasenia,"9")==NULL)
						{
							printf("La contraseñca no posee numeros, ingrese de nuevo la contraseña");
							_flushall;
							gets(uno.Contrasenia);
						}
						else
						{
							if(strstr(uno.Contrasenia,",")!=NULL && strstr(uno.Contrasenia,".")!=NULL && strstr(uno.Contrasenia,"-")!=NULL && strstr(uno.Contrasenia,"á")!=NULL && strstr (uno.Contrasenia,"é")!=NULL && strstr(uno.Contrasenia,"í")!=NULL && strstr(uno.Contrasenia,"ó")!=NULL && strstr(uno.Contrasenia,"ú")!=NULL && strstr(uno.Contrasenia,",")!=NULL && strstr(uno.Contrasenia,"Á")!=NULL && strstr(uno.Contrasenia,"É")!=NULL && strstr(uno.Contrasenia,"Í")!=NULL && strstr(uno.Contrasenia,"Ó")!=NULL && strstr(uno.Contrasenia,"Ú")!=NULL)
							{
								printf("La contraseña posee signos de puntuacion, ingrese de nuevo la contraseña");
								_flushall;
								gets(uno.Contrasenia);
							}
							else
							{
								if(strlen(uno.Contrasenia)<6)
								{
									printf("La contraseña es muy corta, ingrese de nuevo la contraseña");
									_flushall;
									gets(uno.Contrasenia);
								}
								else
								{
									if(strlen(uno.Contrasenia)>32)
									{
										printf("La contraseña es muy larga, ingrese de nuevo la contraseña");
										_flushall;
										gets(uno.Contrasenia);
									}
									else
									{
										for(int i=0;i<strlen(uno.Contrasenia);i++)
										{
											if((uno.Contrasenia[i+2]==uno.Contrasenia[i+1]+1) && (uno.Contrasenia[i+1]==uno.Contrasenia[i]+1))
											{
												printf("No ingrese numeros ni letras consecutivos, ingrese de nuevo la contraseña: ");
												_flushall();
												gets(uno.Contrasenia);
											}
											else
											{
												aceptar=true;
											}
										}								
										if(aceptar==true)
										{
											printf("\t________Contraseña aceptada______");
											printf("\t________Contraseña:%s  ______",uno.Contrasenia);
											
										}
									}
								}
							}
						}
					}
				}
			}

		
	
	fwrite(&uno,sizeof(Usuarios),1,arch1);	
	fclose(arch1);

	
}
				
	
void log_use1( Usuarios uno ) {

	FILE*arch1;
	arch1=fopen("Usuarios_admin.dat","a+b");
	

	bool b1, b2 , b3, b4, b5;
		bool aceptar; 
			
				char aux[20];
	_flushall();
	printf("\t\t\tingrese el Apellido y nombre  a registrar ");
	gets (uno.Apellido_y_Nombre);
	
	printf("\t\t\tingrese la ID usuario a registrar \n");
	
				system("cls");
				int cm=0, cn=0,i=0;
			
				printf("\nHa seleccionado 'Registrar Usuario Recepcion', por favor ingrese los datos que se solicitan a continuacion: \n\n");
				printf("Nombre de usuario \n(Tiene que comenzar con una letra minuscula, tener al menos 2 mayusculas, y no mas de 3 digitos): ");
				_flushall();
				gets(aux);
				b1=false; b2=false; b3=false; b4=false; b5=false;
				/*
				b1==Sea unico para cada usuario*
				b2==Comenzar con una letra minuscula*
				b3==Tener al menos 2 letras mayusculas*
				b4==Tener como maximo 3 digitos*
				b5==Cantidad de caracteres*
				
				*/
		    	while(b1==false && b2==false && b3==false && b4==false && b5==false){
					rewind(arch1);
    				fread(&uno,sizeof(Usuarios),1,arch1);
					while(!feof(arch1)){
						if(strcmp(aux,uno.Usuario)){
							printf("\nEste nombre de usuario ya existe, por favor digite otro: ");
							gets(aux);
							b1=false;	
						}
						else{
							b1=true;
						}
					}
							
							
					if(aux[0]=='q' ||	aux[0]=='w' || aux[0]=='e' || aux[0]=='r' || aux[0]=='t' || aux[0]=='y' || aux[0]=='u' || aux[0]=='i' || aux[0]=='o' || aux[0]=='p' || aux[0]=='a' || aux[0]=='s' || aux[0]=='d' || aux[0]=='f' || aux[0]=='g' || aux[0]=='h' || aux[0]=='j' || aux[0]=='k' || aux[0]=='l' || aux[0]=='ñ' || aux[0]=='z' || aux[0]=='x' || aux[0]=='c' || aux[0]=='v' || aux[0]=='b' || aux[0]=='n' || aux[0]=='m'){
						b2=true;
					}
					else{
						b2=false;
						printf("El nombre no comienza con minuscula, por favor digite otro: ");
						gets(aux);
					}
																													
					for(i=0;i<20;i++){
						if(aux[i]=='A'||aux[i]=='B'||aux[i]=='C'||aux[i]=='D'||aux[i]=='E'||aux[i]=='F'||aux[i]=='G'||aux[i]=='H'||aux[i]=='I'||aux[i]=='J'||aux[i]=='K'||aux[i]=='L'||aux[i]=='M'||aux[i]=='N'||aux[i]=='O'||aux[i]=='P'||aux[i]=='Q'||aux[i]=='R'||aux[i]=='S'||aux[i]=='T'||aux[i]=='U'||aux[i]=='V'||aux[i]=='W'||aux[i]=='X'||aux[i]=='Y'||aux[i]=='Z'){
							cm++;
						}
					}
					if(cm<2){
						printf("\nNo posee 2 mayusculas o mas, por favor digite otro:  ");
						gets(aux);
						b3=false;
					}
					else{
						b3=true;
					}
					for(i=0;i<20;i++){
						if(aux[i]=='1'){
							cn++;
						}
						else{
							if(aux[i]=='2'){
								cn++;
							}
							else{
								if(aux[i]=='3'){
									cn++;
								}
								else{
									if(aux[i]=='4'){
										cn++;	
						   			}
						   			else{
						   				if(aux[i]=='5'){
						   					cn++;
									    }
									    else{
									    	if(aux[i]=='6'){
									    		cn++;
											}
											else{
												if(aux[i]=='7'){
													cn++;
												}
												else{
													if(aux[i]=='8'){
														cn++;
													}
													else{
														if(aux[i]=='9'){
															cn++;
														}
														else{
															if(aux[i]=='0'){
																cn++;
															}
														}
													}
												}
											}
										}
								    }
								}
							}
						}
					}
					
					if(cn>3){
						printf("\nEl maximo de numeros permitidos es 3, por favor digite otro: ",cn);
						gets(aux);
						b4=false;
					}
					else{
						b4=true;
					}
					if(strlen(aux)>10 || strlen(aux)<6){
						printf("\nEl tama%co del nombre no es valido, por favor digite otro: ",164);
						gets(aux);
						b5=false;
					}
					else{
						b5=true;
						strcpy(aux,uno.Usuario);
					}				
				} 
				
	printf("\t\t\tingrese la contraseña de usuarios a registrar ");
		
		
		
		
	printf("\nIngrese la contraseña para el usuario, debe cumplir con las siguientes caracteristicas: \na) Poseer al menos, una letra mayuscula, una minuscula y un numero\nb) No debe poseer caracteres de puntuacion, solo letras y numeros\nc) De entre al menos 6 y 32 caracteres\nd) No debe tener mas de 3 numeros consecutivos\ne) No debe contener 2 caracteres que se refieran a letras alfabeticamente consecutivas (ascendentes)\nIngrese la contraseña: ");
				_flushall();
	gets(uno.Contrasenia);
				aceptar=false;
				
				while(aceptar==false){
				if(strstr(uno.Contrasenia,"Q")==NULL && strstr(uno.Contrasenia,"W")==NULL && strstr(uno.Contrasenia,"E")==NULL && strstr(uno.Contrasenia,"R")==NULL && strstr(uno.Contrasenia,"T")==NULL && strstr(uno.Contrasenia,"Y")==NULL && strstr(uno.Contrasenia,"U")==NULL && strstr(uno.Contrasenia,"I")==NULL && strstr(uno.Contrasenia,"O")==NULL && strstr(uno.Contrasenia,"P")==NULL && strstr(uno.Contrasenia,"A")==NULL && strstr(uno.Contrasenia,"S")==NULL && strstr(uno.Contrasenia,"D")==NULL && strstr(uno.Contrasenia,"F")==NULL && strstr(uno.Contrasenia,"G")==NULL && strstr(uno.Contrasenia,"H")==NULL && strstr(uno.Contrasenia,"J")==NULL && strstr(uno.Contrasenia,"K")==NULL && strstr(uno.Contrasenia,"L")==NULL && strstr(uno.Contrasenia,"Ñ")==NULL && strstr(uno.Contrasenia,"Z")==NULL && strstr(uno.Contrasenia,"X")==NULL && strstr(uno.Contrasenia,"C")==NULL && strstr(uno.Contrasenia,"V")==NULL && strstr(uno.Contrasenia,"B")==NULL && strstr(uno.Contrasenia,"N")==NULL && strstr(uno.Contrasenia,"M")==NULL)
				{
					printf("La contraseña no posee mayuscula, ingrese de nuevo la contraseña");
					_flushall;
					gets(uno.Contrasenia);
				}
				else
				{	if(strstr(uno.Contrasenia,"q")==NULL && strstr(uno.Contrasenia,"w")==NULL && strstr(uno.Contrasenia,"e")==NULL && strstr(uno.Contrasenia,"r")==NULL && strstr(uno.Contrasenia,"t")==NULL && strstr(uno.Contrasenia,"y")==NULL && strstr(uno.Contrasenia,"u")==NULL && strstr(uno.Contrasenia,"i")==NULL && strstr(uno.Contrasenia,"o")==NULL && strstr(uno.Contrasenia,"p")==NULL && strstr(uno.Contrasenia,"a")==NULL && strstr(uno.Contrasenia,"s")==NULL && strstr(uno.Contrasenia,"d")==NULL && strstr(uno.Contrasenia,"f")==NULL && strstr(uno.Contrasenia,"g")==NULL && strstr(uno.Contrasenia,"H")==NULL && strstr(uno.Contrasenia,"j")==NULL && strstr(uno.Contrasenia,"k")==NULL && strstr(uno.Contrasenia,"l")==NULL && strstr(uno.Contrasenia,"ñ")==NULL && strstr(uno.Contrasenia,"z")==NULL && strstr(uno.Contrasenia,"x")==NULL && strstr(uno.Contrasenia,"c")==NULL && strstr(uno.Contrasenia,"v")==NULL && strstr(uno.Contrasenia,"b")==NULL && strstr(uno.Contrasenia,"n")==NULL && strstr(uno.Contrasenia,"m")==NULL)
				{
					printf("La contraseña no posee mayuscula, ingrese de nuevo la contraseña");
					_flushall;
					gets(uno.Contrasenia);
					}
					else
					{
						if(strstr(uno.Contrasenia,"0")==NULL && strstr(uno.Contrasenia,"1")==NULL && strstr(uno.Contrasenia,"2")==NULL && strstr(uno.Contrasenia,"3")==NULL && strstr(uno.Contrasenia,"4")==NULL && strstr(uno.Contrasenia,"5")==NULL && strstr(uno.Contrasenia,"6")==NULL && strstr(uno.Contrasenia,"7")==NULL && strstr(uno.Contrasenia,"8")==NULL && strstr(uno.Contrasenia,"9")==NULL)
						{
							printf("La contraseñca no posee numeros, ingrese de nuevo la contraseña");
							_flushall;
							gets(uno.Contrasenia);
						}
						else
						{
							if(strstr(uno.Contrasenia,",")!=NULL && strstr(uno.Contrasenia,".")!=NULL && strstr(uno.Contrasenia,"-")!=NULL && strstr(uno.Contrasenia,"á")!=NULL && strstr (uno.Contrasenia,"é")!=NULL && strstr(uno.Contrasenia,"í")!=NULL && strstr(uno.Contrasenia,"ó")!=NULL && strstr(uno.Contrasenia,"ú")!=NULL && strstr(uno.Contrasenia,",")!=NULL && strstr(uno.Contrasenia,"Á")!=NULL && strstr(uno.Contrasenia,"É")!=NULL && strstr(uno.Contrasenia,"Í")!=NULL && strstr(uno.Contrasenia,"Ó")!=NULL && strstr(uno.Contrasenia,"Ú")!=NULL)
							{
								printf("La contraseña posee signos de puntuacion, ingrese de nuevo la contraseña");
								_flushall;
								gets(uno.Contrasenia);
							}
							else
							{
								if(strlen(uno.Contrasenia)<6)
								{
									printf("La contraseña es muy corta, ingrese de nuevo la contraseña");
									_flushall;
									gets(uno.Contrasenia);
								}
								else
								{
									if(strlen(uno.Contrasenia)>32)
									{
										printf("La contraseña es muy larga, ingrese de nuevo la contraseña");
										_flushall;
										gets(uno.Contrasenia);
									}
									else
									{
										for(int i=0;i<strlen(uno.Contrasenia);i++)
										{
											if((uno.Contrasenia[i+2]==uno.Contrasenia[i+1]+1) && (uno.Contrasenia[i+1]==uno.Contrasenia[i]+1))
											{
												printf("No ingrese numeros ni letras consecutivos, ingrese de nuevo la contraseña: ");
												_flushall();
												gets(uno.Contrasenia);
											}
											else
											{
												aceptar=true;
											}
										}								
										if(aceptar==true)
										{
											printf("\t________Contraseña aceptada______");
											printf("\t________Contraseña:%s  ______",uno.Contrasenia);
											
										}
									}
								}
							}
						}
					}
				}
			}

		
	
	fwrite(&uno,sizeof(Usuarios),1,arch1);	
	fclose(arch1);

	
}
	

void log_veterinario(Veterinario uno )

{

	FILE*arch;
	arch=fopen("Veterinarios.dat","a+b");
	_flushall();
	printf("\t\t\tingrese el Apellido y nombre  a registrar ");
	gets(uno.Apellido_y_Nombre);
	_flushall();
	printf("\t\t\tingrese el dni ");
	scanf("%d",&uno.Dni);
	printf("\t\t\tingrese su numero de telefono \n");
	_flushall()	;
	gets(uno.Telefono);
	printf("\t\t\tingrese la Matruicula ");
	scanf ("%d",&uno.Matricula);
	fwrite(&uno,sizeof(Veterinario),1,arch);
	fclose(arch);



}


void clave(char* cadena[10]){
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
	ab=0;  char aux[10], nick[10];
	FILE*arch;
	arch=fopen("Usuarios_admin.dat","r+b");
	if(arch == NULL) {
		system("CLS");
		printf("\n\n Se produjo un ERROR al intentar abrir el archivo\n");
		printf("el archivo no a sido creado. Gracias");
		printf("\n\n\t");
		system("PAUSE");
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
	printf("\n\t\t---------------%s---------------",uno.Apellido_y_Nombre);
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

void ranking()
{
		
FILE*tur;FILE*med;	
tur=fopen("Turnos.dat","r+b");
med=fopen("Veterinarios.dat","r+b");
Turnos t; Veterinario m;
int i=0; int ac=0;			
system("cls");
printf("atenciones de veterinarios ");
fread(&m,sizeof(Veterinario),1,med);
fread(&t,sizeof(Turnos),1,tur);
printf("\nLista : \n");
while(!feof(med)||!feof(tur)){
if(m.Matricula==t.Matricula_de_Veterinario){
	ac++;
printf(" veterinario  %d:",i+1);

printf("\n________________________________________\n");
printf("\n\n Nombre y apellido \t");
puts(m.Apellido_y_Nombre);
printf("\n ________________________________________\n");
printf("\n atenciones: %d", ac);
printf("\n ________________________________________\n");
fread(&m,sizeof(Veterinario),1,med);
fread(&t,sizeof(Turnos),1,tur);
i++;
}
else
fread(&m,sizeof(Veterinario),1,med);
fread(&t,sizeof(Turnos),1,tur);
				
}

fclose(med);
fclose(tur);

}

