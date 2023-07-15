//6.l

%{
#include<stdio.h>
int sc=0,mc=0; 
%}

%%
"/*"[^*/]*"*/" {mc++;} 
"//".* {sc++;}
./\n {fprintf(yyout,"%s",yytext);}
%%

int main( int argc, char *argv[])
{
FILE *f1,*f2;
if(argc ==3) {
yyin=fopen(argv[1],"r");
yyout=fopen(argv[2],"w");
yylex();
printf("Number of Comment Lines: \nsingle line : %d\nmulti line : %d\n",sc,mc);
}
else{
    printf("ERROR");
}
return 0; 
}

int yywrap(){
    return 1;
}
