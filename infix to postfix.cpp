#include<stdio.h>
#include<string.h>
int pre(char c)
{
	if(c=='+'||c=='-')
	   {
	      return 1;
	   } 
	
	else if(c=='*'||c=='/')
	   {
	     return 2;
	   }
	   
	else if(c=='^')
	   {
	      return 3;
	   } 
	   
	else
	  {
	     return -1;
	  }
}
int stack[100],top;
main()
{
	char a[1000];
	int i;
	top=-1;
	char ch;
	
	printf("\nEnter any expression : ");
	fflush(stdin);
	gets(a);
	fflush(stdin);
	
	do{
	
	
	for(i=0;i<strlen(a);i++)
	{
		if((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z'))
		{
			printf("%c",a[i]);
		}
		else if(a[i]=='(')
		{
			top++;
			stack[top]=a[i];
		}
		else if(a[i]==')')
		{
			while(stack[top]!='(')
			{
				printf("%c",stack[top]);
				top--;
			}
			top--;
		}
		else
		{
			if(stack[top]=='(')
			{
				top++;
				stack[top]=a[i];
			}
			else
			{
				while(pre(stack[top])>=pre(a[i]))
				{
					printf("%c",stack[top]);
					top--;
			    }
			    top++;
			    stack[top]=a[i];
			}
		}
	}
	for(i=top;i>=0;i--)
	{
		printf("%c",stack[i]);
	}

	printf("\nDo you wan to continue : (y/n) :: ");
	fflush(stdin);
	scanf("%c",ch);
	fflush(stdin);
}while(ch=='y');
}

	
	
