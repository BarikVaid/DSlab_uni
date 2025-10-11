#include<stdio.h>

void tower(int n, char s, char a, char d)
{
    if(n==1)
    {
        printf("\nMove disk 1 from %c to %c",s,d);
        return;
    }
    tower(n-1,s,d,a);
    printf("\nMove disk %d from %c to %c",n,s,d);
    tower(n-1,a,s,d);
}

int main()
{
    int n;
    printf("Enter number of disks:");
    scanf("%d",&n);
    tower(n,'A','B','C');
    return 0;
}
//cse78