/*4. Design, develop and implement YACC/C program to demonstrate Shift Reduce Parsing
technique for the grammar rules: E →E+T | T, T →T*F | F, F →(E) | id and parse the sentence:
id + id * id.
Program:4.c
E -> E+T | T, T ->T*F | F, F ->(E) | id */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ip_sym[15],stack[15];
int ip_ptr=0,st_ptr=0,len,i;
char temp[2];
char act[15];
void check();
void main()
{
printf("\n\t\t SHIFT REDUCE PARSER\n");
printf("\n GRAMMER\n");
printf("\n E->E+T|T\n T->T* F | F");
printf("\n F-> (E) | id \n ");
printf("\n enter the input symbol:\t");
scanf("%s",ip_sym);
printf("\n\t stack implementation table\n");
printf("\n stack\t\t input symbol\t\t action");
printf("\n______\t\t ____________\t\t ______\n");
printf("\n $\t\t%s$\t\t--",ip_sym); /*first step empty action */
strcpy(act,"shift ");
if (ip_sym[ip_ptr]=='(')
{
temp[0]=ip_sym[ip_ptr];
temp[1]='\0';
}
else
{
temp[0]=ip_sym[ip_ptr];
temp[1]=ip_sym[ip_ptr+1];
temp[2]='\0';
}
strcat(act,temp);
len=strlen(ip_sym);
for(i=0;i<=len-1;i++)
{
if(ip_sym[ip_ptr]=='i' &&ip_sym[ip_ptr+1]=='d')
{
stack[st_ptr]=ip_sym[ip_ptr];
st_ptr++;
ip_sym[ip_ptr]=' ';
ip_ptr++;
stack[st_ptr]= ip_sym[ip_ptr];
stack[st_ptr+1]='\0';
ip_sym[ip_ptr]=' ';
ip_ptr++;
}
else
{
stack[st_ptr]=ip_sym[ip_ptr];
stack[st_ptr+1]='\0';
ip_sym[ip_ptr]=' ';
ip_ptr++;
}
printf("\n $%s\t\t%s$\t\t%s",stack,ip_sym,act); /* second print with action shift*/
strcpy(act,"shift ");
if (ip_sym[ip_ptr]=='(' || ip_sym[ip_ptr]=='*' || ip_sym[ip_ptr]=='+' || ip_sym[ip_ptr]==')')
{
temp[0]=ip_sym[ip_ptr];
temp[1]='\0';
}
else
{
temp[0]=ip_sym[ip_ptr];
temp[1]=ip_sym[ip_ptr+1];
temp[2]='\0';
}
strcat(act,temp);
check();
st_ptr++;
}
st_ptr++;
check();
}
void check()
{
int flag=0;
while(1)
{
if (stack[st_ptr]=='d'&& stack[st_ptr-1]=='i')
{
stack[st_ptr-1]='F';
stack[st_ptr]='\0';
st_ptr--;
flag=1;
printf("\n $%s\t\t%s$\t\tF->id",stack, ip_sym);
}
if (stack[st_ptr]==')' && stack[st_ptr-1]=='E' && stack[st_ptr-2]=='(')
{
stack[st_ptr-2]='F';
stack[st_ptr-1]='\0';
flag=1;
st_ptr=st_ptr-2;
printf("\n $%s\t\t%s$\t\tF->id",stack, ip_sym);
}
if (stack[st_ptr]=='F' && stack[st_ptr-1]=='*' && stack[st_ptr-2]=='T')
{
// stack[st_ptr-2]='T';
stack[st_ptr-1]='\0';
st_ptr= st_ptr-2;
flag=1;
printf("\n $%s\t\t%s$\t\tT->T*F",stack, ip_sym);
}
else
{
if (stack[st_ptr]=='F')
{
stack[st_ptr]='T';
flag=1;
printf("\n $%s\t\t%s$\t\tT->F",stack, ip_sym);
}
}
if( stack[st_ptr]=='T' && stack[st_ptr-1]=='+' && stack[st_ptr-2]=='E' && ip_sym[ip_ptr]!='*' )
{
//stack[st_ptr-2]='E';
stack[st_ptr-1]='\0';
st_ptr= st_ptr-2;
flag=1;
printf("\n $%s\t\t%s$\t\tE->E+T",stack, ip_sym);
}
else
if ((stack[st_ptr]=='T' && ip_sym[ip_ptr]== '+') || (stack[0]=='T' && ip_sym[ip_ptr]== '\0') ||
(stack[st_ptr]=='T' && ip_sym[ip_ptr]== ')'))
{
stack[st_ptr]='E';
flag=1;
printf("\n $%s\t\t%s$\t\tE->T",stack, ip_sym);
}
if((stack[st_ptr]=='T' && ip_sym[ip_ptr]== '*') ||
(stack[st_ptr]=='E' && ip_sym[ip_ptr]==')')||
(stack[st_ptr]=='E' && ip_sym[ip_ptr]=='+')||
(stack[st_ptr]=='+'&& ip_sym[ip_ptr]=='i' && ip_sym[ip_ptr+1]=='d')||
( stack[st_ptr]== '(' && ip_sym[ip_ptr]=='i' && ip_sym[ip_ptr+1]=='d') ||
(stack[st_ptr]== '(' && ip_sym[ip_ptr]=='(')||
(stack[st_ptr]=='*'&& ip_sym[ip_ptr]=='i' && ip_sym[ip_ptr+1]=='d' ) ||
(stack[st_ptr]=='*'&& ip_sym[ip_ptr]=='(') ||
(stack[st_ptr]=='+'&& ip_sym[ip_ptr]=='(')
)
{
flag=2;
}
if(!strcmp(stack,"E")&& ip_sym[ip_ptr]=='\0')
{
printf("\n $%s\t\t%s$\t\tACCEPT",stack,ip_sym);
exit(0);
}
if(flag==0)
{
printf("\n%s\t\t\t%s\t\treject",stack,ip_sym);
exit(0);
}
if (flag==2)
return;
flag=0;
}
}
