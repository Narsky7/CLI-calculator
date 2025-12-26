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

int main(){

    char buffer[1024];
    //REPL architecture
    while (1==1){
        //Read
        printf("Type in: ");
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
        printf("check 1: %d\n", parse_number());

    }    
    return 0;
}
