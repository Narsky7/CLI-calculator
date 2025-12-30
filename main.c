#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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

void skip_whitespace(){
    while(input[pos] != '\0' && isspace(input[pos])){
        pos++;
    }
}

Token current_token;

Token get_next_token(){
    skip_whitespace();
    char c = input[pos];
    Token token;

    if (c == '\n' || c == '\0'){
        token.type = TOKEN_EOF;
        return token;
    }
    
    if(isdigit(c)){
        token.type = TOKEN_INT;
        token.value = 0;

        while (isdigit(input[pos])){
            token.value = token.value * 10 + (input[pos] - '0');
            pos++;
        }
        return token;
    }

    if (c == '+'){token.type = TOKEN_PLUS;pos++;return token;}
    if (c == '-'){token.type = TOKEN_MINUS;pos++;return token;}
    if (c == '*'){token.type = TOKEN_MUL;pos++;return token;}
    if (c == '/'){token.type = TOKEN_DIV;pos++;return token;}
    if (c == '('){token.type = TOKEN_LPAREN;pos++;return token;}
    if (c == ')'){token.type = TOKEN_RPAREN;pos++;return token;}

    printf("syntax error, '%c' is not a valid character",c);
    exit(1);
}

void eat(TokenType type) {
    if (current_token.type == type) {
        current_token = get_next_token();
    } else {
        printf("Błąd składni! Oczekiwano typu %d, a otrzymano %d\n", type, current_token.type);
        exit(1);
    }
}

int main(){

    char buffer[1024];
    //REPL architecture
    while (1==1){
        //Read
        printf("$> ");
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
        //Evaluate
        //Print
    }    
    return 0;
}
