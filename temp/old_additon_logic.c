//Old logic of base expression parsing, thought it might be useful
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

// simple function to increment the position parameter
void advance(){
    pos++;
}

// func to check if what peek returns is a digit and parse a multi-number digits
int parse_number(){
    int result = 0;

    while(isdigit(peek())){
        // every another number in our notation is just x10, '0' can be interpreted as ascii number associated to that char
        result = result * 10 + (peek() - '0') ;
        advance();
    }

    return result;
}

// simple helper func to skip whitespaces in input
void skip_whitespace(){
    while(isspace(peek())){
        advance();
    }
}

// function that takes 1st value and based on operator adds or decrements by another
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
