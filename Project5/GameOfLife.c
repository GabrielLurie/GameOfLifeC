#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"


 void show(int** matrix,int N){

	 int i,j;

	 for(i=1;i<N+1;i++) {
		 printf("\n");
		 for(j=1;j<N+1;j++)
			 printf("%d",matrix[i][j]);
	 }
 }


 void Start_Game(int N,int rounds){

	 int i,x,s,y;
	 int* values = (int*)calloc((N+2)*(N+2), sizeof(int));
	 int** Board = (int**)malloc((N+2)*sizeof(int*));
	 printf("before");
	 for (i=0; i<(N+2); ++i){
    
		Board[i] = values + i*(N+2);
    }

	

	 init_Board(Board,N);

	 printf("The initiated board is: \n");
	 show(Board,N);
	 //----------------------------------------------GAME PROCESS STARTS HERE(!)---------------------------------------------------
	 for(x=1;x<=rounds;x++){  
	
		
		                         //NEW BOARD
		 int* valuesN = (int*)calloc((N+2)*(N+2), sizeof(int));
	 int** BoardN = (int**)malloc((N+2)*sizeof(int*));


	                 
	  for (i=0; i<(N+2); ++i){
		BoardN[i] = valuesN + i*(N+2);
    }
	 

	    // OLD BOARD IS BEING COPIED TO THE NEW BOARD
	 for(s=0;s<N+2;s++)
		 for(y=0;y<N+2;y++)
			 BoardN[s][y]=Board[s][y];


	
	 
	 
	
	 //
	 //// ----------------------------------------------DEBUGGING UNIT ------------------------------------------
	 //OLD UNIT
	


	 #ifdef TestVAR1
	 
	 show(BoardN,N);
	 printf("\n\n");
	 show(Board,N);
	  printf("\n\n--------------------------------");
      #endif
	 BoardN=step_Next(Board,N);
	
	 #ifdef TestVAR2

	 // //NEW UNIT
	 show(BoardN,N);
	 printf("\n\n");
	 show(Board,N);
	 // // ----------------------------------------------DEBUGGING UNIT --------------------------------------------
	  printf("\n\n--------------------------------");
	   printf("%d",Board[0][0]);
	   printf("%d",BoardN[0][0]);
	 #endif


	 
	         // NEW BOARD IS BEING COPIED TO THE OLD BOARD (SWAP).
	 for(s=1;s<N+1;s++)
		 for(y=1;y<N+1;y++){
		
			 Board[s][y]=BoardN[s][y];
		 }
	
		
		 
		 printf("\n\n Round No. %d",x);
		  show(Board,N);
		  printf("\n\n");
		
		  
		  
	//	  free_board(BoardN,N+2);

		//free_board(Board,N);
	//	 show(Board,N);

	 }
 }

 
  


 int** step_Next(int** current_State,int N){


	 int i,j;

	 int* values = (int*)calloc(N*N, sizeof(int));
	 int** rows = (int**)malloc(N*sizeof(int*));
    for (i=0; i<(N+2); ++i){
    
		rows[i] = values + i*(N+2);
    }


	 for(i=1;i<N+1;i++)
		 for(j=1;j<N+1;j++){
			 if(Alive(current_State,i,j)==TRUE) rows[i][j]=TRUE;
			 else rows[i][j]=FALSE;
 }
		 return rows;
     }


void init_Board(int **brd,int N){


	 
		   time_t T;
		   int i,j;
		  srand((unsigned)time(NULL)+1258769*time(&T)+9999955+58954*time(&T));


	
	for(i=0;i<N+2;i++)
		for(j=0;j<N+2;j++)
			brd[i][j]=FALSE;

	for(i=1;i<N+1;i++)
		for(j=1;j<N+1;j++)
			brd[i][j]=random_number();//0,1);



}




 int random_number()
        {
			int r;
		r=rand()%2;
               return r;

        }



 boolean Alive(int** matrix, int i,int j){

	int count=0;
	// printf("I'm executed from Alive");
	 
	 
	if(matrix[i-1][j-1]==TRUE) count++;
	if(matrix[i-1][j]==TRUE) count++;
	if(matrix[i-1][j+1]==TRUE) count++;
	 
	 if(matrix[i][j-1]==TRUE) count++;
	 if(matrix[i][j+1]==TRUE) count++;
	
	if(matrix[i+1][j-1]==TRUE) count++;
	if(matrix[i+1][j]==TRUE) count++;
	if(matrix[i+1][j+1]==TRUE) count++;

	if(count<2) return FALSE;
	if(count>3) return FALSE;
	 
	           if(matrix[i][j]==FALSE && count==3) return TRUE;
			   if(matrix[i][j]==TRUE && (count==3 || count==2)) return TRUE;

	 

	return FALSE;

 }

 void free_board(int **board, int Rows) 
{
    int row;
	
    // first free each row
    for (row = 0; row < Rows; row++) {
         free(board[row]);
		 printf("deleted unit");
    }

    // Eventually free the memory of the pointers to the rows
   //free(board);
 }