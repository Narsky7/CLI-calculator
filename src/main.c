/*
 Easy CLI calculator by narsky
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

char *input;
int pos;

typedef enum {
    TOKEN_NUMBER,  
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MUL,
    TOKEN_DIV,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_EOF, 
    TOKEN_ID,
} TokenType;

typedef struct{
    TokenType type;
    double value;  
    char name[64];
} Token;

void eat(TokenType type);
Token get_next_token();
double parse_expression();
double parse_term();
double parse_factor();

Token current_token;

void eat(TokenType type) {
    if (current_token.type == type) {
        current_token = get_next_token();
    } else {
        printf("Syntax error, expected: %d ,and got: %d\n", type, current_token.type);
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
    
    if(isdigit(c) || c == '.'){
        token.type = TOKEN_NUMBER;
        token.value = 0.0;

        while (isdigit(input[pos])){
            token.value = token.value * 10.0 + (input[pos] - '0');
            pos++;
        }

        if (input[pos] == '.') {
            pos++; 
            double divisor = 10.0;
            
            while (isdigit(input[pos])) {
                token.value = token.value + (input[pos] - '0') / divisor;
                divisor *= 10.0;
                pos++;
            }
        }
        return token;
    }

    if (isalpha(input[pos])){
        token.type = TOKEN_ID;
        int name_pos = 0;
        while(isalnum(input[pos])){ 
            if (name_pos < 63){
                token.name[name_pos] = input[pos];
                name_pos++; 
            }
            pos++;
        }
        token.name[name_pos] = '\0';
        return token;
    }

    if (c == '+'){token.type = TOKEN_PLUS;pos++;return token;}
    if (c == '-'){token.type = TOKEN_MINUS;pos++;return token;}
    if (c == '*'){token.type = TOKEN_MUL;pos++;return token;}
    if (c == '/'){token.type = TOKEN_DIV;pos++;return token;}
    if (c == '('){token.type = TOKEN_LPAREN;pos++;return token;}
    if (c == ')'){token.type = TOKEN_RPAREN;pos++;return token;}
    
    printf("Error unkown sign: '%c'\n", c);
    exit(1);
}

double parse_factor(){
    Token token = current_token;

    if(token.type == TOKEN_NUMBER){
            double val = token.value;
            eat(TOKEN_NUMBER);
            return val;
    }
    if(token.type == TOKEN_LPAREN){
        eat(TOKEN_LPAREN);
        double result = parse_expression();
        eat(TOKEN_RPAREN);
        return result;
    }
    if(token.type == TOKEN_ID){
            char func_name[64];
            strcpy(func_name, token.name);
            eat(TOKEN_ID);
            eat(TOKEN_LPAREN);
            double argument = parse_expression(); 
            eat(TOKEN_RPAREN);

            if(strcmp(func_name, "sqrt") == 0){
                return sqrt(argument); 
            }
            else if(strcmp(func_name, "sin") == 0){
                 return sin(argument);
            }
            else if(strcmp(func_name, "ln") == 0){
                 return log(argument);
            }           
            else if(strcmp(func_name, "exit") == 0){
                printf("Exiting...\n");
                exit(0);
            }
            else {
                printf("Error: Unknown function '%s'\n", func_name);
                exit(1);
            }
    }
    
    printf("Error in factor. Token: %d\n", token.type);
    exit(1);
}

double parse_term(){
    double result = parse_factor();

    while(current_token.type == TOKEN_DIV || current_token.type ==  TOKEN_MUL){
        if(current_token.type ==  TOKEN_MUL){
            eat(TOKEN_MUL);
            result = result * parse_factor();
        }
        else if(current_token.type == TOKEN_DIV){
            eat(TOKEN_DIV);
            result = result / parse_factor();
        }
    }
    return result;
}

double parse_expression(){
    double result = parse_term();
    while(current_token.type == TOKEN_PLUS || current_token.type ==  TOKEN_MINUS){
        if(current_token.type ==  TOKEN_PLUS){
            eat(TOKEN_PLUS);
            result = result + parse_term();
        }
        else if(current_token.type == TOKEN_MINUS){
            eat(TOKEN_MINUS);
            result = result - parse_term();
        }       
    }
    return result;
}


int main(){
    char buffer[1024];
    
    while (1){
        printf("$> ");
        if (fgets(buffer,sizeof(buffer),stdin) == NULL) break;
        
        input = buffer;
        pos = 0;
        
        if(strncmp(buffer,"exit",4) == 0){
            break;
        }

        current_token = get_next_token(); 
        double result = parse_expression();
        
        printf("%g \n", result); 
    }    
    return 0;
}