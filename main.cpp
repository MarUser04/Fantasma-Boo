#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define f 20
#define c 20


struct fantasma
{
	int matriz[f][c];
	int u, v, sent;
	int bf[7][17]={{0, 0, 1, 1, 1, 0, 0},
			       {0, 0, 1, 1, 1, 0, 0},
			       {0, 1, 2, 2, 2, 1, 0},
			       {0, 1, 2, 2, 2, 1, 0},
			       {1, 1, 3, 3, 3, 2, 1},
			       {1, 2, 3, 3, 3, 2, 1},
			       {0, 1, 3, 3, 3, 2, 1},
			       {0, 1, 3, 0, 3, 2, 1},
			       {0, 0, 1, 0, 3, 2, 1},
			       {0, 0, 1, 3, 3, 2, 1},
			       {0, 1, 3, 3, 3, 2, 1},
			       {0, 1, 3, 3, 3, 2, 1},
			       {1, 2, 3, 3, 3, 2, 1},
			       {1, 1, 2, 2, 2, 1, 0},
			       {0, 1, 2, 2, 2, 1, 0},
			       {0, 0, 1, 1, 1, 0, 0},
			       {0, 0, 1, 1, 1, 0, 0}
				  };
};

void gotoxy(int y,int x);
void color(int X);
void pintar(fantasma *boo);
void imprimir(fantasma *boo);
//void fuego();
void jugar(fantasma *boo);

int main(int argc, char** argv) 
{
	
	fantasma boo;
	
	system("color f0");
	
	boo.u=8;
	boo.v=20;
	boo.sent=1;
	
	pintar(&boo);
	imprimir(&boo);
	jugar(&boo);
	
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

void pintar(fantasma *boo){
		
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
                 boo->matriz[i][j]=aux[i][j];
                
            }
        }
        
        

		
}


void imprimir(fantasma *boo){
	
	
	gotoxy(boo->u,boo->v);
	int x=boo->u, y=boo->v;
	if(boo->sent==1)
	{
			
	for(int i=0; i<f; i++)
	{
	
		for(int j=0; j<c;j++)
		{
			if(boo->matriz[i][j]==1 )
			{
				color(15*16+0);
				printf("%c", 219);
			}
			
			else  if(boo->matriz[i][j]==2)
				{
					color(15*16+12);
						printf("%c", 219);
				}
			else
			  printf(" ");
		}
			gotoxy(++x,y); //columna estatica porque sino el muñeco se aplasta
		
	}

	}
	else if(boo->sent==2)
	{
			
	for(int i=0; i<f; i++)
	{
	
		for(int j=c; j>=0;j--)
		{
			if(boo->matriz[i][j]==1 )
			{
				color(15*16+0);
				printf("%c", 219);
			}
			
			else  if(boo->matriz[i][j]==2)
				{
					color(15*16+12);
						printf("%c", 219);
				}
			else
			  printf(" ");
		}
			gotoxy(++x,y); //columna estatica porque sino el muñeco se aplasta
		
	}

	}
	
}
/*void fuego()
{
	int ff= , fc= ;
	
	for(int i=0; i<15; i++)
	{
		gotoxy(ff, fc);
		printf("")
	}
}*/
void jugar(fantasma *boo)
{
	char tecla;
	
	



	if(kbhit)
	{
	
	while(tecla != 'x')
	{
	
		tecla=getch();
		

		
		if(tecla== 'd' || tecla=='D')
        {
            boo->v++;
            gotoxy(boo->u, boo->v+1);
            printf(" ");
            boo->sent=1;
  
        }
         
        if(tecla== 'a' || tecla=='A')    
        {
        	if(boo->v-1 !=0)
        	{
        	boo->v--;
            gotoxy(boo->u, boo->v-1);
             printf(" ");
             boo->sent=2;
         
			}

        }
         
        if(tecla== 's' || tecla=='S')
        {
            boo->u++;
            gotoxy(boo->u+1, boo->v);
            printf(" ");
       }
         
        if(tecla== 'w' || tecla=='W')
        {
        	if(boo->u-1 !=0)
        	{
        	boo->u--;
        	gotoxy(boo->u-1, boo->v);
             printf(" ");
			}
             
        }
        if(tecla =='l' || tecla =='L')
        {
         	for(int i=0; i<7; i++)
         	{
         		printf("\n");
         		for(int j=0; j<16; j++)
         		{
         			printf("%d", boo->bf[i][j]);
				 }
			 }
		}
      
         imprimir(boo);
        Sleep(120);
                

	}
	
	}//kbhit
	
}
