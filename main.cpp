#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define f 20
#define c 20


void gotoxy(int y,int x);
void color(int X);
void pintar(int mat[f][c]);
void pintar2(int mat[f][c]);
//void fuego( int po, int pe);
void imprimir(int mat[f][c], int u, int v);
void jugar(int mat[f][c], int u, int v);


int main(int argc, char** argv) {
	
	system("color f0");

	//char soundfile[] = "C:/Castle Theme - Super Mario World.waw" ; 
	//PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC );

	int matriz[f][c], u=8, v=20 ; //, po=58, pe=180;
	
	pintar(matriz);
	
	imprimir(matriz, u, v);
	jugar(matriz, u, v);
	
	system("pause>null");
	return 0;
}


void gotoxy(int y,int x)
{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
 
 void color(int X) 
{ 
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X); 
} 


void pintar(int mat[f][c]){
		
	int aux[f][c]={ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				    {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
					{0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
					{0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
					{0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
					{0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0},
					{0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
					{0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 1, 0},
					{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 1, 6},
					{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 1, 0, 0},
					{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 1, 0, 0},
					{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 1, 0, 0, 0},
					{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}				
			};
			
			
				
	 int i, j;
         
        for(i=0 ;i<f; i++)
        {
            for(j=0; j<c; j++)
            {
                 mat[i][j]=aux[i][j];
                
            }
        }

		

}

void pintar2(int mat[f][c]){
		
				//   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19
	int aux[f][c]={ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
					{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
					{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0},
					{0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0},
					{0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
					{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
					{0, 1, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
					{0, 1, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
					{0, 0, 1, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
					{0, 0, 1, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
					{0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
					{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					
					
		          };
			
			
				
	 int i, j;
         
        for(i=0 ;i<f; i++)
        {
            for(j=0; j<c; j++)
            {
                 mat[i][j]=aux[i][j];
                
            }
        }

		

}


void imprimir(int mat[f][c], int u, int v){
	
	
	gotoxy(u,v);
	
	for(int i=0; i<f; i++)
	{
	
		for(int j=0; j<c;j++)
		{
			if(mat[i][j]==1 )
			{
				color(15*16+0);
				printf("%c", 219);
			}
			
			else  if(mat[i][j]==2)
				{
					color(15*16+12);
						printf("%c", 219);
				}
			else
			  printf(" ");
		}
			gotoxy(++u,v); //columna estatica porque sino el muñeco se aplasta
		
	}

}
/*void fuego( int po, int pe){
	
	int poder[5][5];
int aux2[5][5]= {{3, 3, 4, 5, 5,},
			   {3, 4, 5, 5, 5,},
			   {4, 4, 5, 5, 5,},
			   {3, 4, 5, 5, 5,},
			   {3, 3, 4, 5, 5,},
			  };
			
		int i, j;
         
        for(i=0 ;i<5; i++)
        {
            for(j=0; j<5; j++)
            {
                 poder[i][j]=aux2[i][j];
                
            }
        }
       
	    
	gotoxy(po, pe);
        
    for(int i=0; i<5; i++)
	{
		//printf("\n");
		for(int j=0; j<5;j++)
		{
			if(poder[i][j]==4 )
			{
				color(15*16+12);
				printf("%c", 219);
			}
			
			else  if(poder[i][j]==5)
				{
					color(15*16+14);
					printf("%c", 219);
				}
			else
			  printf(" ");
		}
		gotoxy(++po,pe); //columna estatica porque sino el muñeco se aplasta
		
	}
}*/


void jugar(int mat[f][c], int u, int v)
{
	char tecla;
	
	
	//int fg=40, fo=29;


	if(kbhit)
	{
	
	while(tecla != 'x'){
		tecla=getch();
		
	//	mat[fg][fo]=6;
		
		if(tecla== 'd' || tecla=='D')
        {
            v++;
            gotoxy(u, v+1);
            printf(" ");
            pintar(mat);
            imprimir(mat, u, v);
        }
         
        if(tecla== 'a' || tecla=='A')    
        {
            v--;
            gotoxy(u, v-1);
             printf(" ");
             pintar2(mat);
             imprimir(mat, u, v);

        }
         
        if(tecla== 's' || tecla=='S')
        {
            u++;
            gotoxy(u+1, v);
            printf(" ");
            imprimir(mat, u, v);
        }
         
        if(tecla== 'w' || tecla=='W')
        {
            u--;
        	gotoxy(u-1, v);
             printf(" ");
             imprimir(mat, u, v);

        }
        /*if( tecla== 'l' || tecla=='L'&& mat[fg][fo]==6)
        {
        	
            fuego(fg, fo);

        }*/
        
        
        Sleep(120);
                

	}//while
	
	}//kbhit
	
}
