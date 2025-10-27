#include<stdio.h>
#include<stdlib.h>
int main()
{
	int states = '0';
	char str[100];
	
	printf("Enter the string:");
	scanf("%s",str);
	
	for(int i=0;str[i]!='\0';i++)
	{
		switch(states)
		{
			case '0':
				if(str[i]=='a'){
				states = '1';
				}
				else if(str[i]=='b'){
				states = '3';
				}
				else{
				printf("Invalid\n");
				exit(0);
				}
				break;
			case '1':
				if(str[i]=='a'){
				states = '2';
				}
				else if(str[i]=='b')
				{
				states = '3';
				}
				else{
				printf("Invalid\n");
				exit(0);
				}
				break;
			case '2':
				if(str[i]=='a'){
				states = '2';
				}
				else if(str[i]=='b'){
				states = '2';
				}
				else{
				printf("Invalid\n");
				exit(0);
				}
				break;
			case '3':
                		if(str[i] == 'a'){
                	    states = '3';
               			}
                		else if(str[i]=='b'){
                    		states = '3';
                		}
                		else{
				printf("Invalid\n");
				exit(0);
				}
                		break;
		}
	}
	
	if(states =='2')
	{
		printf("Accepted\n");
	}
	else {
		printf("Not accepted\n");
	}
	return 0;
}
