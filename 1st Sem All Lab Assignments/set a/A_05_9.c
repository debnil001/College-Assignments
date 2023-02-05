#include <stdio.h>

int prime(int n) {
    int c = 0, i = 1;
    for(i = 2;i <= n/2;i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int main()
{
    int n, i;
    printf("\nEnter the range: ");
    scanf("%d", &n);

    for(i=2;i<n;i++) {
        if(prime(i))
            printf("%d, ", i);
    }

}