#include<stdio.h>
int main()
{
    int state ='0';
    char str[100];

    printf("Enter the string need ");
    scanf("%s",str);

    for(int i=0;str[i]!='\0';i++)
    {
        switch(state)
        {
            case '0':
                if(str[i] == 'a'){
                    state = '1';
                }
                else{
                    state = '3';
                }
                break;
            case '1':
                if(str[i] == 'a'){
                    state = '2';
                }
                else{
                    state = '3';
                }
                break;
            case '2':
                if(str[i] == 'a'){
                    state = '2';
                }
                else {
                    state = '2';
                }
                break;
            case '3':
                if(str[i] == 'a'){
                    state = '3';
                }
                else {
                    state = '3';
                }
                break;

        }
    }
    if (state == '2')
    {
        printf("String is accepted\n");
    }
    else{
        printf("String is not accepted\n");
    }
}