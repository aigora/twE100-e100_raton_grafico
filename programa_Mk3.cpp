#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main()
{
	
    int i, n, reading,posx=1,posy=1,lookx,looky = 0;
    char c;
    bool muerte= false;
    FILE *p_archivo;
    p_archivo = fopen ("Mapas/map.txt", "r");
    
    while(1){
        n = 0;
		
		if (kbhit()){
			for(i=0;i<=1;i++){
			
				fflush(stdin);
		        switch((n=getch())) {
			        case KEY_UP:
			        	looky=-1;
			        	lookx=0;
			            break;
			        case KEY_DOWN:
			        	looky=1;
			        	lookx=0;
			            break;
			        case KEY_LEFT:
			        	looky=0;
			        	lookx=-1;
			            break;
			        case KEY_RIGHT:
			        	looky=0;
			        	lookx=1;
			            break;
		        }
	    	}
    	}
    	else{
    		posx=posx+lookx;
    		posy=posy+looky;
		}
		for(reading=0;c != EOF; reading++)
		{
			c = fgetc (p_archivo);
			if((reading%41==posx)&&(reading/41==posy)){
				printf("0");
				if (c=='#'){
					muerte=true;
				}
			}
			else printf ("%c", c);
		}
		c=0;
		rewind(p_archivo);
		printf("\nloop posx%i, posy%i, looky%i, lookx%i",posx,posy,looky,lookx);
		if(muerte){
			break;
		}
		Sleep(10);
		fflush(stdin);
		system("CLS");
    }
    system("CLS");
    fclose(p_archivo);
    p_archivo = fopen ("Recursos/Splash/splash_over.txt", "r");
    for(c=0; c != EOF;){
		c = fgetc (p_archivo);
		printf ("%c", c);
	}
    getch();
    return 0;
}
