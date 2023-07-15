//1.l 
%{
#include<stdio.h>
int opr=0,opnd=0,b=0;
%}
%%
[0-9]+ {opnd++;printf("operand %s",yytext);}
[+\-*/] {opr++;printf("operator %s",yytext);}
[(] {b++;}
[)] {b--;}
%%

int main(){
  printf("enter expression : ");
  yylex();
  if(opr>=opnd || b!=0 || opnd==1){
    printf("invalid\n");
    exit(0);
  }
  else{
    printf("no of operators : %d\n",opr);
    printf("no of operands : %d\n",opnd);
  }
}
