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

void eat(TokenType type);
Token get_next_token();
int parse_expression();
int parse_term();
int parse_factor();

Token current_token;

void eat(TokenType type) {
    if (current_token.type == type) {
        current_token = get_next_token();
    } else {
        printf("Błąd składni! Oczekiwano typu %d, a otrzymano %d\n", type, current_token.type);
        exit(1);
    }
}

void skip_whitespace(){
    while(input[pos] != '\0' && isspace(input[pos])){
        pos++;
    }
}

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

int parse_factor(){
    if(current_token.type == TOKEN_INT){
            int current_number = current_token.value;
            eat(TOKEN_INT);
            return current_number;
    }
    if(current_token.type == TOKEN_LPAREN){
        eat(TOKEN_LPAREN);
        int result = parse_expression();
        eat(TOKEN_RPAREN);
        return result;
    }
    else{
        printf("Undefined error *todo*");
        return 1;
    }
}

int parse_term(){
    int result = parse_factor();

    while(current_token.type == TOKEN_DIV || current_token.type ==  TOKEN_MUL){
        if(current_token.type ==  TOKEN_MUL){
            eat(TOKEN_MUL);
            int right_side = parse_factor();
            result = result * right_side;
        }
        if(current_token.type == TOKEN_DIV){
            eat(TOKEN_DIV);
            int right_side = parse_factor();
            result = result / right_side;
        }
        }
        return result;
}

int parse_expression(){
    int result = parse_term();
    while(current_token.type == TOKEN_PLUS || current_token.type ==  TOKEN_MINUS){
        if(current_token.type ==  TOKEN_PLUS){
            eat(TOKEN_PLUS);
            int right_side = parse_term();
            result = result + right_side;
        }
        if(current_token.type == TOKEN_MINUS){
            eat(TOKEN_MINUS);
            int right_side = parse_term();
            result = result - right_side;
        }       
    }
    return result;
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
        current_token = get_next_token(); 
        int result = parse_expression();
        printf("%d \n",result);
        //Tokenize (lexer)
        //Parse
        //Evaluate
        //Print
    }    
    return 0;
}