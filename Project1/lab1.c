//
// Created by Mihai on 05.03.2025.
//
// Lab 1
#include <stdio.h>
#include <math.h>
double square_root(int n,double precision) {
    double approx=n/2.0;
    while (fabs(approx*approx-n)>precision) {
        approx=(approx+n/approx)/2.0;
    }
    return approx;
}

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
    int n,command;
    double precision;
    while (1){
        jump_here:
        printf("1.Pascal Triangle\n2.Square root\n3.Exit\n");
        scanf("%d",&command);
        if (command==3) {
            break;
        }
        else if (command==2) {
            printf("Enter number:");
            scanf("%d",&n);
            if (n<=-1) {
                break;
            }
            printf("Enter Precision:");
            scanf("%lf",&precision);
            printf("\n%lf\n",square_root(n,precision));
        }
        else if (command==1) {
            printf("Enter Pascal Depth:");
            scanf("%d",&n);
            if (n<=-1) {
                printf("Invalid depth\n");
                goto jump_here;
            }
            triPascal(n);
            printf("\n");
        }
    }
    return 0;
}