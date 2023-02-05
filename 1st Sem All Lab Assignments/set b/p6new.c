#include<stdio.h>
void print(int matrix[][10],int m,int n){
	int c,d;
	for (c=0;c<m;c++){
      for (d=0;d<n;d++)
         printf("%5d",matrix[c][d]);
        printf("\n");
    }
}
void trans(int matrix[][10],int transpose[][10],int m,int n){
   int c,d;
   for(c=0;c<m;c++)
   {
      for(d=0;d<n;d++)
      {
         transpose[d][c] = matrix[c][d];
      }
   }
 	print(transpose,n,m);
}
void mul(int matrix[][10],int transpose[][10],int product[][10],int m,int n){
   int c,d,k,sum;
   for (c=0;c<m;c++){
      for(d=0;d<n;d++){
         for (k=0;k<n;k++){
            sum=sum+matrix[c][k]*transpose[k][d];
         }
         product[c][d]=sum;
         sum=0;
      }
   }
   print(product,m,n);
}
void isOrthogonal(int product[][10],int m){
     int c,d;
     for(c=0;c<m;c++){
       for(d=0;d<m;d++){
           if(c==d){
                if(product[c][d]!=1)
                   break;
           }
           else{
               if(product[c][d]!=0)
                  break;
           }
       }
       if(d!=m)
          break;
   }
   if(c!=m)
      printf("Matrix is not orthogonal.\n");
   else
      printf("Matrix is orthogonal.\n");
 
}
void main(){
   int m, n, p, c, d, k, sum = 0;
   int matrix[10][10], transpose[10][10], product[10][10];
 
   printf("Enter the number of rows and columns of matrix\n");
   scanf("%d%d",&m,&n);
   printf("Enter the elements of matrix\n");
 
   for (c=0;c<m;c++)
      for (d=0;d<n;d++)
         scanf("%d",&matrix[c][d]);

   printf("A::\n");
   print(matrix,m,n);
   printf("A^T::\n");
   trans(matrix,transpose,m,n);
	printf("A.A^T::\n");
   mul(matrix,transpose,product,m,n);
   isOrthogonal(product,m);
}
