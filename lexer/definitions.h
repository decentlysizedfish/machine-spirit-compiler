// definitions enums and structures used in the lexer
//
// Lists all libraries
// libraries are declared here and will be imported into executable files via this header
#include <stdio.h> // input and output
#include <stdlib.h> // memory management
#include <ctype.h> // character mod and utility
#include <string.h> 


// expanded token types

// keyword tokens
// these types are from *geekforgeeks.org*
enum keyword_token {
    // numbers

    // may want to make new category for literals
    T_INT,
    T_DOUBLE,
    T_LONG,
    T_FLOAT,
    T_SHORT,
    // blank (will sort these later for efficiency -- more common keywords first)
    T_VOID,
    T_CHAR,
    T_ENUM,
    T_STRUCT,
    T_TYPEDEF,
    T_UNSIGNED,
    T_AUTO,
    T_BREAK,
    T_CASE,
    T_CONST,
    T_CONTINUE,
    T_DEFAULT,
    T_DO,
    T_ELSE,
    T_EXTERN,
    T_FOR,
    T_GOTO, // HUH
    T_IF,
    T_RETURN,
    T_SIGNED,
    T_SIZEOF,
    T_STATIC,
    T_SWITCH,
    T_UNION,
    T_VOLATILE,
    T_WHILE
};

// mainly used for identifying when things need to be done/order of operations -- cooler name to come
enum punctuation_tokens {
    T_OPEN_BRACE,
    T_CLOSE_BRACE,
    T_OPEN_PAREN,
    T_CLOSE_PAREN,
    T_SEMICOLON
};

// probably will be empty since these will be defined at run time, but the slot is still here
// needs to identify letters/words/maybe even numbers?
enum identifier_tokens {};


enum operator_tokens {
    T_PLUS,
    T_MINUS,
    T_STAR, // multi 
    T_BACKSLASH // division 
};

// tokens used for identifier 

enum token_type {
    T_KEYWORD,
    T_PUNCTUATION,
    T_IDENTIFIER,
    T_OPERATOR
};

/*
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

*/