
#include <stdio.h>

#define tna 25

int main ()
{
	char p_nombre_a [tna], /*repetir,*/ c;
	FILE *p_archivo;
/*do{*/	
	printf ("\nIndique el nombre del mapa que va a crear con extension '.txt':   ");
	gets (p_nombre_a);
	p_archivo = fopen (p_nombre_a,"w+");
	puts ("\nComience a modelar su mapa empleando el caracter # (se debe realizar por filas). Al terminar pulse Retorno y Ctrl-Z...\n");
	while (c != EOF)
	{
		c = getchar ();
		fputc (c, p_archivo);
	}
	fflush (p_archivo);
	printf("\n\nEste es el mapa que ha creado");
	puts ("\n\n");

	rewind (p_archivo);
	c = 1;
	while (c != EOF)
	{
		c = fgetc (p_archivo);
		printf ("%c", c);
	}
	/*printf ("\n\n¿Este es al mapa que desea guardar?   ");
 	scanf ("%c", &repetir);
	fflush (stdin); 
} while ((repetir == 'n')||(repetir == 'N'));*/	
	fclose (p_archivo);
	
	return 999;
}
