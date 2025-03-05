#include <stdio.h>
unsigned long long factorial(int n) {
    if (n==0) {
        return 1;
    }
    else {
        return n*factorial(n-1);
    }
}

unsigned long long combination(int n,int k) {
    return factorial(n)/(factorial(k)*factorial(n-k));
}

void triPascal(int n) {
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=i;j++) {
            printf("%llu ",combination(i,j));
        }
        printf("\n");
    }
}

int main(void) {
    int m;
    while (1){
        printf("Print Pascal triangle or enter -1 to exit\n");
        scanf("%d",&m);
        if (m<=-1) {
            break;
        }
        else {
           triPascal(m);
        }
    }
    return 0;
}