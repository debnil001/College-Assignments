#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct student{
	char name[200];
	int roll;
	int marks;
	char DOB[20];
}Std;

void add(){
	FILE *fp;
	Std *s;
	int num, i;
	char nm[20];
	fp = fopen("StudentRecords.txt","a");
	if(fp == NULL){
		printf("\nFile is not opened.\n");
		return;
	}
	printf("\nEnter no of records:: ");
	scanf("%d",&num);
	s = (Std*)calloc(num, sizeof(Std));
	for(i=0;i<num;i++){
		printf("\nEnter Name : ");
		scanf("%s",nm);
		strcpy(s[i].name, nm);
		printf("Enter Roll : ");
		scanf("%d",&s[i].roll);
		printf("Enter Marks : ");
		scanf("%d",&s[i].marks);
		printf("Enter DOB (DD/MM/YYYY) : ");
		scanf("%s",nm);
		strcpy(s[i].DOB,nm);
		fwrite(&s[i], sizeof(Std), 1, fp);
	}
	printf("\nNew Record has been added successfully.\n");
	fclose(fp);
}
void del(){
	Std s;
	int rl, flag=0;
	FILE *fp1,*fp2;
	printf("\nEnter Roll No. to delete record:: ");
	scanf("%d",&rl);
	fp1 = fopen("StudentRecords.txt","r");
	if(fp1 == NULL){
		printf("\nFile isn't opened\n");
		return;
	}
	fp2 = fopen("Temp.txt","w");
	if(fp2 == NULL){
		printf("\nFile isn't' opened\n");
		return;
	}
	while(fread(&s, sizeof(Std), 1, fp1)){
		if(s.roll == rl){
			flag=1;
		}
		else{
			fwrite(&s, sizeof(Std), 1, fp2);
		}
	}
	if(flag == 1){
		fclose(fp1);
		fclose(fp2);
		fp1 = fopen("StudentRecords.txt","w");
		fp2 = fopen("Temp.txt","r");
		while(fread(&s, sizeof(Std), 1, fp2)){
			fwrite(&s, sizeof(Std), 1, fp1);
		}
		printf("\nDeleted Successfully.\n");
	}
	else{
		printf("\nRoll is not found.\n");
		return;
	}
	fclose(fp1);
	fclose(fp2);
}
void modify(){
	int update=0,i;
	Std s;
	FILE *fp1, *fp2;
	fp1 = fopen("StudentRecords.txt","r");
	fp2 = fopen("Temp.txt","w");
	if(fp1 == NULL){
		printf("\nFile can't opened properly.\n");
		return;
	}
	if(fp2 == NULL){
		printf("\nFile can't opened properly.\n");
		return;
	}
	while(fread(&s, sizeof(Std), 1, fp1)){
		if(s.marks>40 && s.marks<50){
			update=1;
			s.marks=s.marks+10;
			fwrite(&s,sizeof(Std), 1, fp2);
		}
		else{
			fwrite(&s, sizeof(Std), 1, fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	if(update == 1){
		printf("\nData updated successfully.\n");
		fp1=fopen("StudentRecords.txt","w");
		fp2=fopen("Temp.txt","r");
		while(fread(&s,sizeof(Std),1,fp2)){
			fwrite(&s,sizeof(Std),1,fp1);
		}
		fclose(fp1);
		fclose(fp2);
	}
	else{
		printf("\nNo marks found between 40 to 50.\n");
	}
}
void display(){
	Std s;
	FILE *fp;
	fp = fopen("StudentRecords.txt","r");
	printf("\nName		Roll		Marks		DOB\n--------------------------------------------------------\n");
	while(fread(&s, sizeof(Std), 1, fp)){
		printf("\n%-10s	%-10d %8d %20s",s.name,s.roll,s.marks,s.DOB);
	}
	printf("\n");
	fclose(fp);
}
int main(){
	int ch;
	while(1){
		printf("\n1.Display Records\n2.Add new records"
		"\n3.Delete a record.\n4.Modify record.\n5.Exit.\n");
		printf("\nEnter your choice:: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				display();
				break;
			case 2:
				add();
				break;
			case 3:
				del();
				break;
			case 4:
				modify();
				break;
			case 5:
				exit(0);
			default:
				printf("\nInvalid choice\n");
				break;
		}
	}
	return(0);
}
