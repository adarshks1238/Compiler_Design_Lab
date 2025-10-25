#include<stdio.h>
int array[20][20];
int done[20];
int n;


void closure(int i)
{
    done[i] = 1;

    for(int j = 0; j<n ; j++)
    {
        if (array[i][j] == 1 && done[j] != 1)
        {
            printf(", q%d",j);
            closure(j);
        }
    }
}
int main()
{
    int t;
    int s1,s2;
    char trans;

    printf("Enter the no.of States:");
    scanf("%d",&n);
    printf("\n Enter the no.of Transcation:");
    scanf("%d",&t);

    printf("Enter the details in such a way that SOURCE TRANS(e for Epsilon) DESTINATION\n");
    
    for(int i=0;i<t;i++)
    {
        scanf("%d %c %d",&s1, &trans, &s2);
        if(trans == 'e')
        {
            array[s1][s2] = 1;
        }
    }

    printf("Epsilon closure of all states\n");
    for(int i = 0; i<n ;i++)
    {
        for (int j = 0;j<n;j++)
        {
            done[j] = 0;
        }
        printf("closure of q%d :{ q%d ",i, i);
        closure(i);
        printf("}\n");
    }
}