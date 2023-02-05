#include<stdio.h>
typedef struct 
{
    int acno;
    char name[100];
    unsigned int blnce;
}BANK;
void printDetails(BANK obj){
    printf("\nAccount NO. %d",obj.acno);
    printf("\nBalance Rs.%d\n",obj.blnce);
}
void banking(BANK obj[],int n,int code){
	int ac,i,bln;
	printf("Enter account number::");
	scanf("%d",&ac);
	for(i=0;i<n;i++){
		if(ac==obj[i].acno){
			if(code==1){
			printf("Enter amount to deposit::");
			scanf("%d",bln);
			obj[i].blnce+=bln;
			break;
			}
			else if(code==0){
				printf("Enter amount to withdraw::");
				scanf("%d",&bln);
				if(bln>obj[i].blnce){
					printf("Insufficient balance\n");
				}
				else{
					obj[i].blnce-=bln;
				}
				break;
			}
		}
	}
	if(i==n){
		printf("Account number invalid\n");
	}
}
int main(){
    BANK customers[500];
    int n;
    printf("Enter customer numbers::");
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        printf("Enter Customer%d details->",i+1);
        printf("Enter account number::");
        scanf("%d",&customers[i].acno);
        printf("Enter customer name::");
        fflush(stdin);
        gets(customers[i].name);
        printf("Enter deposit amount::");
        scanf("%d",&customers[i].blnce);
    }
    printf("Customers details who has balance less than 1000->\n");
    for(i=0;i<n;i++){
        if(customers[i].blnce<1000)
            printDetails(customers[i]);
    }
    int code;
    printf("Enter 1 for deposit and 0 for withdraw::");
    scanf("%d",&code);
    banking(customers,n,code);
    printf("Customers details->\n");
    for(i=0;i<n;i++){
        printDetails(customers[i]);
    }
    return 0;
}
