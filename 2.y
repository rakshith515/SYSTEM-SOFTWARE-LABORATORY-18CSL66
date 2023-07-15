//2.y

%{
#include<stdio.h>
%}
%token A B
%%
str : S '\n' {printf("valid\n");return 0;}
S : C B
C : A C
  | A;
%%
int main(){
  printf("enter input string : ");
  yyparse();
}

int yyerror(){
  printf("invalid\n");
  return 1;
}
