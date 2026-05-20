#ifndef TOK_DEFINITIONS_H
#define TOK_DEFINITIONS_H

// idk what all libraries i need atm, so now we have none

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

#endif