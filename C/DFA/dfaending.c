#include<stdio.h>
int main()
{
    int state = '0';
    
    char str[100];
    printf("Enter the String need to Check: ");
    scanf("%s",str);

    for(int i=0 ; str[i]!='\0' ;i++)
    {
        switch(state)
        {
            case '0':
                if(str[i]=='a'){
                    state = '1';
                }
                else if(str[i]=='b'){
                    state = '0';
                }
                break;
            case '1':
                if(str[i] == 'a')
                {
                    state = '2';
                }
                else if (str[i]=='b')
                {
                    state = '0';
                }
                break;
            case '2':
                if(str[i] == 'a'){
                    state = '1';
                }
                else if(str[i] == 'b'){
                    state = '0' ;
                }
                break;
        }
    }
    if (state == '2')
    {
        printf("The given string is accepted\n");
    }
    else
    {
        printf("The Given String is no accepted\n");
    }
}