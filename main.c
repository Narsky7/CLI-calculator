#include <stdio.h>
#include <string.h>

char *input;
int pos;

int main(){

    char buffer[1024];
    //REPL architecture
    while (1==1){
        //Read
        printf("Type in: ");
        fgets(buffer,sizeof(buffer),stdin);
        input = buffer;
        pos = 0;
        printf("%s",input);
        if(strncmp(buffer,"exit",4) == 0){
            printf("exitting");
            break;
        }
        //Tokenize (lexer)
        //Parse
        //Evaluator
        //Print
    }    
    return 0;
}
