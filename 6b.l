//6b.l

%{
#include "y.tab.h"
%}

%%
int|char|bool|float|void|for|do|while|if|else|return|void {printf("keyword is %s\n",yytext);return KEY;}
[+|-|*|/|=|<|>] {printf("operator is %s\n",yytext);return OP;}
[a-zA-Z_][a-zA-Z0-9_]+ {printf("identifier is %s\n",yytext);return ID;}
{;}
[\n] {return yytext[0];}
%%
       
