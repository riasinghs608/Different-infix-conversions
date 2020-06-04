#include<stdio.h>
#include<string.h>

int prece(char c)
{
	if(c=='^'||c=='$')
	   return 3;
	
	else if(c=='*'||c=='/')
	   return 2;
	    
	else if(c=='+'||c=='-')
	   return 1;
	
	else
	  return -1;
}
int stack[1000],top;
main()
{
	char a[1000],b[1000];
	top=-1;
	int i;
	
	printf("\nEnter an expression  : ");
	gets(a);
	strrev(a);
	int k=0;
	for(i=0;i<strlen(a);i++)
	{
		if((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z'))
		{
			b[k]=a[i];
			k++;
		}
		else if(a[i]==')')
		{
			top++;
			stack[top]=a[i];
		}
		else if(a[i]=='(')
		{
			while(stack[top]!=')')
			{
				b[k]=stack[top];
				k++;
				top--;
			}
			top--;
		}
		else
		{
			if(stack[top]==')')
			{
				top++;
				stack[top]=a[i];
				
			}
			else
			{
				while(prece(stack[top])>=prece(a[i]))
				{
					b[k]=stack[top];
					k++;
					top--;
				}
				top++;
				stack[top]=a[i];
			}
		}
	}
	for(i=top;i>=0;i--)
	{
		b[k]=stack[i];
		k++;
	}
	strrev(b);
	puts(b);
}
