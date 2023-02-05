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
int main()
{
	Lib arr[50];
	int ch, index=0, i, search_acc, temp=0, flag=0, j;
	char b_title[20];
	char b_author[20];
	char search[20];
	char temp_str[20];
	while(1)
	{
		printf("\n\n<---------- Menu ---------->\n");
		printf("\n01. Add book information.\n02. Display book information.\n03. List all books of given author.\n04. List the title of specified book.\n");
		printf("05. List the count of books in the library.\n06. List the books in the order of Accession Number.\n07. For Exit.\n\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n<----- Enter the Book Information ----->\n");
				printf("\nAccession Number : ");
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
				printf("\n<----- List of Available Books ----->\n");
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
				for(i=0;i<index;i++)
				{
					if(strcmp(search, arr[i].author) == 0)
					{
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
				for(i=0;i<index;i++)
				{
					if(search_acc == arr[i].acc_no)
					{
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
				printf("\n<----- List the books in the order of Accession Number ----->\n");
				for(i=0;i<index;i++)
				{
					// Swap the details of books based on Accession Number...
					for(j=i+1;j<index;j++)
					{
						if(arr[i].acc_no > arr[j].acc_no)
						{
							// Swap Accession Number.
							flag = arr[i].acc_no;
							arr[i].acc_no = arr[j].acc_no;
							arr[j].acc_no = flag;
							// Swap the title of the book.
							strcpy(temp_str, arr[i].title);
							strcpy(arr[i].title, arr[j].title);
							strcpy(arr[j].title, temp_str);
							// Swap the author of the book.
							strcpy(temp_str, arr[i].author);
							strcpy(arr[i].author, arr[j].author);
							strcpy(arr[j].author, temp_str);
							// Swap the price of the book.
							flag = arr[i].price;
							arr[i].price = arr[j].price;
							arr[j].price = flag;
						}
					}
				}
				printf("\n<----- After Ordering The Result Is ----->\n");
				for(i=0;i<index;i++)
				{
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
				printf("\n\nError : Please choose a correct option.\n\n");
				break;
		}
	}
	return(0);
}
