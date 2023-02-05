#include<stdio.h>
#include<limits.h>
void findThirdMax(int[],int);
void findFifthMin(int[],int);
void findMiddle(int[],int);
int main(){
    int a[50],size,i;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    printf("Enter the elements of the array : \n");
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    findFifthMin(a,size);
    findThirdMax(a,size);
    findMiddle(a,size);
}

void findThirdMax(int a[],int len){
    int m1,m2,m3,i,curr;
    m1=m2=m3=INT_MIN;
    for(i=0;i<len;i++){
      curr = a[i];
            if(m1<curr){
                m3=m2;
                m2=m1;
                m1=curr;
            }
            else if(m2<curr){
                m3=m2;
                m2=curr;
            }
            else if(m3<curr){
                m3=curr;
            }
    }
    printf("The third miximum value of the array is : %d\n",m3);
}

void findFifthMin(int a[],int len){
    int m1,m2,m3,m4,m5,i,curr;
    m1=m2=m3=m4=m5=INT_MAX;
    for(i=0;i<len;i++){
      curr = a[i];
            if(m1>curr){
                m5=m4;
				m4=m3;
				m3=m2;
                m2=m1;
                m1=curr;
            }
            else if(m2>curr){
                m5=m4;
				m4=m3;
				m3=m2;
                m2=curr;
            }
            else if(m3>curr){
                m5=m4;
				m4=m3;
				m3=curr;
            }
            else if(m4>curr){
                m5=m4;
				m4=curr;
            }
            else if(m5>curr){
                m5=curr;
            }
    }
    printf("The fifth minimum value of the array is : %d\n",m5);
}

void findMiddle(int a[],int len)
{
	int mid;
	if(len%2==0){
		printf("middle elements of the array are : %d %d",a[len/2-1],a[len/2]);
	}
	else
	printf("middle element of the array is : %d",a[len/2]);
}