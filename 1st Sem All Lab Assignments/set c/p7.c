#include<stdio.h>
void getMatrix()
{
	FILE *fp;
	char c;
	int mat[20][20];
	int row=0, col=0,i,j,finalCol;;
	fp = fopen("matrix.txt","r");
	if(fp == NULL){
		printf("\nerror in file.\n");
		return;
	}
	
	for (c=getc(fp);c!=EOF;c=getc(fp)){
        if(c==' ')
        	continue;
		if(c=='\n'){ // Increment count if character is newline
            row++;
            finalCol=col;
            col=0;
        }
        else{
        	mat[row][col++]=c-48;
		}
	}
	FILE *fp1;int sum;
	fp1=fopen("matrixDetails.txt","w");
	printf("Row- %d\n",row);
	printf("column- %d\n",finalCol);
	printf("\n\nGenerated Matrix Is : \n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<finalCol;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<row;i++)
	{
		sum=0;
		for(j=0;j<finalCol;j++)
		{
			sum+=mat[i][j];
		}
		fprintf(fp1,"sum of Row no %d ----> %d\n",i,sum);
	}
	fclose(fp);
	fclose(fp1);
}
int main()
{
	getMatrix();
	return(0);
}
