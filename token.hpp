#include <iostream>
#include <string>

enum TokenType {
    TOKEN_ILLEGAL,      // illegal
    TOKEN_EOF,          // eof
    TOKEN_IDENT,        // ident
    TOKEN_ASSIGN,       // =
    TOKEN_PLUS,         // +
    TOKEN_COMMA,        // ,
    TOKEN_SEMICOLON,    // ;
    TOKEN_LPAREN,       // (
    TOKEN_RPAREN,       // )
    TOKEN_LBRACE,       // {
    TOKEN_RBRACE,       // }
    TOKEN_FUNCTION,     // FUNCTION
    TOKEN_LET           // LET
};

typedef struct Token {
    int token_type;
    std::string literal;
}Token;

// class Token {
// public:
//     void SetLiteral();

// public:
//     int token_type;
//     std::string literal;
// };