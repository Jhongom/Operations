#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAX_VECTOR 100
#define MAX_FILE_SIZE 100

/*

 -v   
      Version 1.0 
	  Autor Jhon Gomez Torres
	  Fecha de desarrollo: 29 de septiembre*/
	  
/*   --help 
      Este programa cuenta con los siguientes argumentos que pueden ser de su ayuda*
	  -v    	muestra version, autores y fecha de desarrollo
	  -t		transpuesta de matrices
	  -a		Suma de 2 matrices
	  -r 		resta de 2 matrices
	  -w		indica que el resultado de la operacion se debe guardar en un archivo con formato CSV. agrega la ruta y nombre del archivo*/





void mostrar_matrices (*descriptor, *descriptor2);


void main (int argc, char *argv[])
{

	
	char bandera=0;
	
	printf("Hola, este programa opera matrices, por favor digite la direccion de 2 matrices");
	
	if (argc != 3)
	{
		printf("\nError, se necesita digitar 2 direcciones de las matrices\n\n");
		bandera=0;
	}
	
	if (bandera=1)
	{
		if(strcmp(argv[1],"matrices")==0)
		{
			printf("\n\nDijito las siguientes matrices");
			mostrar_matrices(descriptor, descriptor2);
		}
	}
	
	return bandera;
	
}

void mostrar_matrices (*descriptor,*descriptor2)
{
	
	float matriz1[MAX_VECTOR];
	float matriz2[MAX_VECTOR];
	char subbuff, subbuff2;
	FILE descriptor, descriptor2;
	char buffer [MAX_FILE_SIZE];
	char buffer2 [MAX_FILE_SIZE];

	size_t result, result2 =0;
	long file_size, file_size2 =0;
	
	
	descriptor = fopen ("matriz1.csv","r");
	fseek ( descriptor, 0, SEEK_END);
	file_size = ftell (descriptor);
	rewind ( descriptor );
	
	result = fread (buffer, 1, file_size, descriptor);

	descriptor2 = fopen ("matriz2.csv","r");
	fseek ( descriptor2, 0, SEEK_END);
	file_size2 = ftell (descriptor2);
	rewind ( descriptor2 );
	
	result2 = fread (buffer2, 1, file_size, descriptor2);

	
	if (result!= file_size)
	{
		fputs("error en lectura", stderr);
		
	}
	fclose (descriptor);
	
	if (result2!= file_size2)
	{
		fputs("error en lectura", stderr);
	}
	fclose (descriptor2);
	
	strcat(matriz1, buffer);
	strcat(matriz2, buffer2);
	
	
	printf("\n\n El archivo es: \n\n%s\n\n", matriz1);
	printf("\n %s\n\n", matriz2);
	
	
}

