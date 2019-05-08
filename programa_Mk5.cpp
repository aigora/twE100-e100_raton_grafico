#include <conio.h>
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void animation_gameover(){
char c;
int k=0;
FILE *archivo;
archivo = fopen ("Recursos/Splash/splash_over.txt", "r");
    for(c=0; c != EOF;){
c = fgetc (archivo);
printf ("%c", c);
Sleep(2);
}
}

void  nombre_mapa(char * n){
char mapa[50],nombre[20];
printf("Introduce el nombre del mapa: \n");
gets(nombre);
strcpy(mapa,"Mapas/");
strcat(nombre,".txt");
strcat(mapa,nombre);
strcpy(n,mapa);
}

int juego_laberinto(){
int i, n, reading, size_map, pos[]={1,1}, look[]={0,0};
char c, nombre[25];
bool muerte= false;
FILE *p_archivo;
nombre_mapa(nombre);
printf("%s",nombre);
Sleep(2500);
    p_archivo = fopen(nombre, "r");

    for(reading=0;c != EOF; reading++){
c = fgetc (p_archivo);
if(c=='\n'){
break;}
else size_map++;
}
printf("%i",size_map);
Sleep(2500);
system("CLS");
rewind(p_archivo);
    while(1){
if (kbhit()){
for(i=0;i<=1;i++){
fflush(stdin);
        switch((n=getch())) {
        case KEY_UP:
        look[0]=-1;
        look[1]=0;
            break;
        case KEY_DOWN:
        look[0]=1;
        look[1]=0;
            break;
        case KEY_LEFT:
        look[0]=0;
        look[1]=-1;
            break;
        case KEY_RIGHT:
        look[0]=0;
        look[1]=1;
            break;
        }
    }
    }
    else{
    pos[0]=pos[0]+look[0];
    pos[1]=pos[1]+look[1];
}
for(reading=0;c != EOF; reading++){
c = fgetc (p_archivo);
if((reading%(size_map+1)==pos[1])&&(reading/(size_map+1)==pos[0])){
printf("0");
if (c=='#'){
muerte=true;
}
}
else printf ("%c", c);
}
c=0;
rewind(p_archivo);
printf("\nloop posx%i, posy%i, looky%i, lookx%i",pos[1],pos[0],look[1],look[0]);
if(muerte) break;
Sleep(25);
fflush(stdin);
system("CLS");
}
}

int main()
{
    int i, n;
    char c, mapa[20];
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    juego_laberinto();
    Sleep(500);
    system("CLS");
    animation_gameover();
    return 0;
}
