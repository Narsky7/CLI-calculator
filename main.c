#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *input;
int pos;


char peek(){
    if (input[pos] == '\0') {
        return '\0';
    }
    if (input[pos] == '\n') {
        return '\0';
    }

    return input[pos];
}

void advance(){
    pos++;
}

int parse_number(){
    int result = 0;

    while(isdigit(peek())){
        result = result * 10 + (peek() - '0') ;
        advance();
    }

    return result;
}

void skip_whitespace(){
    while(isspace(peek())){
        advance();
    }
}

int parse_expression(){
    skip_whitespace();
    int val = parse_number();
    while (1){
        skip_whitespace();       
        char operator = peek();

        if (operator == '+') {
            advance();
            skip_whitespace();
            int next_val = parse_number();
            val = val + next_val;
        } 
        else if (operator == '-') {
            advance();
            skip_whitespace();
            int next_val = parse_number();
            val = val - next_val;
        } 
        else if (operator == '\0' || operator == '\n') {
            break;
        } 
        else {
            // Handle unknown characters
            printf("Syntax Error: Unexpected character '%c'\n", operator);
            return -1;
        }
    }
    return val;
}


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
