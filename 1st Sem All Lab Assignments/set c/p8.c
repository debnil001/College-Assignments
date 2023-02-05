// Write a program to read a text file, convert each character to uppercase and write it to another file.
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp1, *fp2;
	const char *file1 = "Input.txt";
	const char *file2 = "Result.txt";
	fp1 = fopen(file1,"r");
	fp2 = fopen(file2,"a");
	char ch;
	if(fp1 == NULL)
	{
		printf("Error : Input.txt file can't find.");
		return(0);
	}
	if(fp2 == NULL)
	{
		printf("Error : Result.txt file can't find.");
		return(0);
	}
	while((ch=fgetc(fp1)) != EOF)
	{
		putc(ch, fp2);
	}
	fclose(fp2);
	fclose(fp1);
	printf("\n\n");
	return(0);
}
