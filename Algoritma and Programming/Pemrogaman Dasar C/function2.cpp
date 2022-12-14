#include <stdio.h>
void print(int A[3][4])
{
      int row,col;
      for(row=0; row<3; row++){
          for(col=0; col<4; col++)
		printf("X[%d][%d]=%d",row,col,A[row][col]);
          printf("\n");
      }
}

int main()
{
   int x[3][4]={{1,2,3,4},
                {8,7,6,5},
                {9,10,11,12}};
   print(x);
   return(0);
}


