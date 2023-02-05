#include<stdio.h>
void print(int matrix[][50],int m,int n){
	int c,d;
	for (c=0;c<m;c++){
      for (d=0;d<n;d++)
         printf("%5d",matrix[c][d]);
        printf("\n");
    }
}
void merge(int m1[][50],int m2[][50],int res[][50],int r1,int r2,int col){
	int c=0;
	int i,j;
	for(i=0;i<r1;i++){
		for(j=0;j<col;j++){
			res[c][j]=m1[i][j];
		}
		c++;
	}
	for(i=0;i<r2;i++){
		for(j=0;j<col;j++){
			res[c][j]=m2[i][j];
		}
		c++;
	}
	print(res,r1+r2,col);
}
void sortRowWise(int m[][50],int r, int c){
int i,j,k;
for (i=0;i<r;i++){
	for(j=0;j<c;j++){
	for (k=0;k<c-j-1;k++){
		if (m[i][k]>m[i][k+1]){
			int temp=m[i][k];
			m[i][k]=m[i][k+1];
			m[i][k+1]=temp;
		}
	}
	}
}

for (i=0;i<r;i++){
	for (j=0;j<c;j++)
	printf("%5d",m[i][j]);
	printf("\n");
}
}

int main(){
    int r1,r2,c1,c2;
    int matrix1[50][50],matrix2[50][50],res[50][50];
    printf("Enter the number of rows and columns of matrix\n");
    scanf("%d%d",&r1,&c1);
    printf("Enter the elements of matrix\n");
    int c,d;
    for (c=0;c<r1;c++)
      for (d=0;d<c1;d++)
         scanf("%d",&matrix1[c][d]);
    printf("Enter the number of rows and columns of matrix\n");
    scanf("%d%d",&r2,&c2);
    printf("Enter the elements of matrix\n");
    for (c=0;c<r2;c++)
      for (d=0;d<c2;d++)
         scanf("%d",&matrix2[c][d]);
    print(matrix1,r1,c1);
    printf("\n");
    print(matrix2,r2,c2);
    printf("\n");
    sortRowWise(matrix1,r1,c1);
    printf("\n");
    sortRowWise(matrix2,r2,c2);
    printf("\n");
    merge(matrix1,matrix2,res,r1,r2,c1);
    return 0;
}
