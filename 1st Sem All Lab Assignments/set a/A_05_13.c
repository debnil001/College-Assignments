#include<stdio.h>
#include<stdlib.h>
main(){
    int M[50][50],i,j,k,power,c=1;
    float M_to_power_p[50][50],R[50][1],temp[50][50],n,sum;
    
    printf("Enter n::");
    scanf("%f",&n);
    
    for(i=0;i<n;i++){
        sum=0;
        for(j=0;j<n-1;j++){
            M[i][j]=rand()%5;//generating random numbers less than 5
            sum+=M[i][j];
        }
        M[i][j]=1-sum;
    }

    printf("\nRandom Matrix M with Order %d x %d is:\n",(int)n,(int)n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%5d",M[i][j]);
        }
		printf("\n");
    }

    printf("\nEnter p:");
    scanf("%d",&power);

    printf("\nColumn vector R with order %d x 1 is:: \n",(int)n);
    for(i=0;i<n;i++){
            R[i][0]=(1/n);
            printf("%5.3f\n",R[i][0]);
    }
    
    printf("\n-----------------------------------------\n");
    //creating another copy of M to find M^p
    for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
    		M_to_power_p[i][j]=M[i][j];
		}
    }
    //calculating M^p
    while(c<power){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                sum=0;
                for(k=0;k<n;k++){
                    sum+=M_to_power_p[i][k]*M[k][j];
                }
                temp[i][j]=sum;
            }
        }c++;
    }
    //copying the final m^p to the final matrix
    printf("\nM^p is:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        	M_to_power_p[i][j]=temp[i][j];
        	printf("%6.0f",M_to_power_p[i][j]);
	  }printf("\n");
    }

    for(i=0;i<n;i++){
        	sum=0;
            for(k=0;k<n;k++){
                sum+=M_to_power_p[i][k]*R[k][0];
            }
            temp[i][0]=sum;
    }
    
    printf("\n(M^p)*R matrix with order %d x 1:\n",(int)n);
      for(i=0;i<n;i++){        
	  printf("%5.3f",temp[i][0]);
	  printf("\n");
    }
    printf("\nHence R=(M^p)*R is proven\n");
    
    
}
