#include<math.h>
#include <stdio.h>
void main() {
	int i,n;
	long long int tr1=1,tr2=1,nextTerm;
	double t1,t2,p1,p2,res,diff,sqroot5;
	if(n==2||n==1)
		nextTerm=1;
	printf("Enter n: ");
	scanf("%d", &n);

	for (i=3;i<=n;++i) {
	    nextTerm = tr1 + tr2;
	    tr1 = tr2;
	    tr2 = nextTerm;
	}
 	printf("Actual output::%lli\n", nextTerm);
 	sqroot5=sqrt(5);
	t1=(1+(double)sqroot5)/2.0;
	t2=(1-(double)sqroot5)/2.0;
	
	p1= (double)pow(t1,n)/(double)sqroot5;
	p2= (double)pow(t2,n)/(double)sqroot5;
	
	res=p1-p2;
	printf("\nFormula output:: %.0lf",res);
	diff=nextTerm-res;
	printf("\n\nDifference: %e",diff);
}
