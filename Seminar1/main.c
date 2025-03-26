#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct {
    int arr[10000];
    int lg;
}lista;


/*
void evenNums(int n, int v[],int* lg) {
    int j=0;
    for (int i=0;i<=n;i+=2) {
        v[j]=i;
        ++j;
    }
    *lg=j;
}

int* getPare(int nr) {
    int rez[10000];
    int j=0;
    for (int i=0;i<=nr;i+=2) {
        rez[j]=i;
        j++;
    }
    return rez;
}
*/

lista getPare(int nr) {
    lista rez;
    int j=0;
    for (int i=0;i<=nr;i+=2) {
        rez.arr[j]=i;
        j++;
    }
    rez.lg=j;
    return rez;
}

void testPare() {
    lista l1=getPare(2);
    assert(l1.arr[0]==0);
    assert(l1.lg==2);
    assert(l1.arr[1]==2);
}

void runAllTest() {
    testPare();
}

void runApp () {
    char command;
    while (1)
    {
        printf("Menu\n1.Numere Pare\n2.Exit\n");
        scanf(" %c",&command);
        if (command!='1') {
            break;
        }
        int n;
        printf("Enter number: ");
        scanf("%d",&n);
        if (n<0) {
            printf("Invalid value");
            break;
        }
        lista rez = getPare(n);
        //evenNums(n,v,&cate);
        for (int i=0;i<rez.lg;++i) {
            printf("%d, ",rez.arr[i]);
        }
    }
}

int main() {
    runAllTest();
    runApp();
    return 0;
}