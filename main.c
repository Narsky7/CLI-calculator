#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *input;
int pos;

// token definitions

typedef enum {
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MUL,
    TOKEN_DIV,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_EOF, // End Of File
} TokenType;

typedef struct{
    TokenType type;
    int value;
} Token;


int main(){

    char buffer[1024];
    //REPL architecture
    while (1==1){
        //Read
        printf(">> ");
        fgets(buffer,sizeof(buffer),stdin);
        input = buffer;
        pos = 0;
        // printf("%s",input);
        if(strncmp(buffer,"exit",4) == 0){
            printf("exiting... \n");
            break;
        }
        //Tokenize (lexer)
        //Parse
        int equals = parse_expression();
        //Evaluate
        //Print
        printf("%d \n", equals);

    }    
    // todo : fix whitespace bug + fix multiple numbers addiditon problem
    return 0;
}
