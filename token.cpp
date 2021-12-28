#include "token.hpp"

void Token::SetLiteral() {
    switch(token_type){
        case TOKEN_ILLEGAL:
            literal = "ILLEGAL";
            break;
        case TOKEN_EOF:
            literal = "EOF";
            break;
        case TOKEN_IDENT:
            literal = "IDENT";
            break;
        case TOKEN_ASSIGN:
            literal = "=";
            break;
        case TOKEN_PLUS:
            literal = "+";
            break;
        case TOKEN_COMMA:
            literal = ",";
            break;
        case TOKEN_SEMICOLON:
            literal = ";";
            break;
        case TOKEN_LPAREN:
            literal = "(";
            break;
        case TOKEN_RPAREN:
            literal = ")";
            break;
        case TOKEN_LBRACE:
            literal = "{";
            break;
        case TOKEN_RBRACE:
            literal = "}";
            break;
        case TOKEN_FUNCTION:
            literal = "FUNCTION";
            break;
        case TOKEN_LET:
            literal = "LET";
            break;
    }
}