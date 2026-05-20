// definitions enums and structures used in the lexer

#include <stdio.h> // input and output
#include <stdlib.h> // memory management
#include <ctype.h> // character mod and utility
#include <string.h> 

typedef enum {
    TOK_KEYWORD,
    TOK_OPERATOR,
    TOK_IDENTIFIER,
    TOK_PUNCTUATION,
    TOK_LITERAL
} tok_type_t;

typedef struct {
    tok_type_t tok;
    // points to the starting character in file buffer
    const char *start; 
    int length;
    int line;
} tok_t;

