// Library Implementation...
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct library
{
	int acc_no;
	char title[20];
	char author[20];
	float price;
	int flag;
}Lib;
int main(){
	Lib arr[1000];
	int ch, index=0, i, search_acc, temp=0, flag=0, j;
	char b_title[20];
	char b_author[20];
	char search[20];
	char temp_str[20];
	while(1){
		printf("\n1.Add book information\n2.Display book information\n3.List all books of given author.\n"
		"4.List the title of specified book.\n"
		"5.List the count of books in the library.\n6.List the books in the order of Accession Number.\n7.Exit.\n\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the Book Information --->\n");
				printf("\nACC Number : ");
				scanf("%d",&arr[index].acc_no);
				printf("Title : ");
				scanf("%s",b_title);
				strcpy(arr[index].title, b_title);
				printf("Author : ");
				scanf("%s",b_author);
				strcpy(arr[index].author, b_author);
				printf("Price : ");
				scanf("%f",&arr[index].price);
				arr[index].flag = 0;
				index++;
				break;
			case 2:
				printf("\nList of Available Books --->\n");
				for(i=0;i<index;i++)
				{
					printf("\n\n#.Book : %d",i+1);
					printf("\nAccession Number : %d",arr[i].acc_no);
					printf("\nTitle : %s",arr[i].title);
					printf("\nAuthor : %s",arr[i].author);
					printf("\nPrice : %.2f",arr[i].price);
				}
				break;
			case 3:
				printf("\nEnter Author Name to list the books : ");
				scanf("%s",search);
				for(i=0;i<index;i++){
					if(strcmp(search, arr[i].author) == 0){
						printf("\nBook : %d",i+1);
						printf("\nAccession Number : %d",arr[i].acc_no);
						printf("\nTitle : %s",arr[i].title);
						printf("\nAuthor : %s",arr[i].author);
						printf("\nPrice : %f",arr[i].price);
					}
				}
				break;
			case 4:
				temp=0;
				printf("\nEnter Accession Number to search : ");
				scanf("%d",&search_acc);
				for(i=0;i<index;i++){
					if(search_acc == arr[i].acc_no){
						printf("\nTitle : %s",arr[i].title);
						printf("\nAuthor : %s",arr[i].author);
						printf("\nPrice : %f",arr[i].price);
						temp=1;
						break;
					}
				}
				if(temp == 0)
					printf("\nNo Book is found.\n");
				break;
			case 5:
				printf("\nTotal %d books are available in library.\n",index);
				break;
			case 6:
				printf("\nList the books in the order of Accession Number--->\n");
				for(i=0;i<index;i++)
				{
					// Swap the details of books based on Accession Number...
					for(j=i+1;j<index;j++){
						if(arr[i].acc_no>arr[j].acc_no){
							Lib temp=arr[i];
							arr[i]=arr[j];
							arr[j]=temp;
						}
					}
				}
				printf("\nAfter Ordering the Result is--->\n");
				for(i=0;i<index;i++){
					printf("\n\n#.Book : %d",i+1);
					printf("\nAccession Number : %d",arr[i].acc_no);
					printf("\nTitle : %s",arr[i].title);
					printf("\nAuthor : %s",arr[i].author);
					printf("\nPrice : %.2f",arr[i].price);
				}
				break;
			case 7:
				exit(0);
			default:
				printf("\nInvalid option\n");
				break;
		}
	}
	return 0;
}
