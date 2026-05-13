// definitions enums and structures used in the lexer
//
// Lists all libraries
// libraries are declared here and will be imported into executable files via this header
#include <stdio.h> // input and output
#include <stdlib.h> // memory management
#include <ctype.h> // character mod and utility
#include <string.h> 

// token types - note for the time being it will only handle arithmetic operations
enum token_type {
    TOK_PLUS, // +
    TOK_MINUS, // -
    TOK_MULT, // *
    TOK_DIV, // /
    TOK_INT // integer
};

struct token // defining the token
{
    token_type type;
    int int_value; // stores the int value if it exists (token is TOK_INT)
};

