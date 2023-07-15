//6b.y

%{
#include<stdio.h>
int id=0,key=0,op=0;
extern FILE *yyin;
%}

%token KEY ID OP

%%
S : E '\n' {printf("valid\n");return 0;}
E : KEY E {key++;}
  | ID E {id++;}
  | OP E {op++;}
  | KEY {key++;}
  | ID {id++;}
  | OP {op++;};
%%

int main(){
  yyin = fopen("file.c","r");
  yyparse();
  printf("\n");
  printf("keywords : %d\noperators : %d\nidentifiers : %d\n",key,op,id);
  return 0;
}

int yyerror(){
  printf("invalis\n");
  return 1;
}
