%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>

#include "syntax_tree.h"
#include "syntax_analyzer.h"

int files_count;
int lines;
int pos_start;
int pos_end;
int i;

void pass_node(char *text){
     yylval.node = new_syntax_tree_node(text);
}
%}

/***************
 TO STUDENTS: Copy your Lab1 here. Make adjustments if necessary.

 Note: don't modify the prologue unless you know what you are doing.
***************/

letter [A-Za-z]
digit [0-9]
id {letter}+
integer {digit}+
float ({digit}+\.|{digit}*\.{digit}+)
other [^*]
other1 [^*/]
comment ([/]\*{other}*(\*\**{other1}{other}*)*\**\*[/])|([/]\*[/]) 


%%

"+" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return ADD;}
"-" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return SUB;}
"*" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return MUL;}
"/" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return DIV;}
"<" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return LT;}
"<=" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return LTE;}
">" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return GT;}
">=" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return GTE;}
"==" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return EQ;}
"!=" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return NEQ;}
"=" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return ASSIN;}

";" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return SEMICOLON;}
"," { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return COMMA;}
"(" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return LPARENTHESE;}
")" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return RPARENTHESE;}
"[" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return LBRACKET;}
"]" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return RBRACKET;}
"{" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return LBRACE;}
"}" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return RBRACE;}

"else" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return ELSE;}
"if" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return IF;}
"int" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return INT;}
"float" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return FLOAT;}
"return" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return RETURN;}
"void" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return VOID;}
"while" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return WHILE;}

{id} { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return IDENTIFIER;}
{integer} { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return INTEGER;}
{float} { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return FLOATPOINT;}
"[]" { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return ARRAY;}
{letter} { pos_start = pos_end; pos_end += yyleng; pass_node(yytext); return LETTER;}

\r\n|\n|\r { lines++; pos_start = 1; pos_end = 1; }
{comment} {
     i = 0;
	pos_start = pos_end; 
	while(yytext[i]) {
	     if(yytext[i] == '\n') {
		     lines++;
			pos_start = 1;
			pos_end = 1;
			i++;
			continue;
		}
	    i++;
	    pos_end++;	
	}
}
[ \t] {pos_start = pos_end; pos_end += yyleng; }
. {return ERROR;} 

%%
