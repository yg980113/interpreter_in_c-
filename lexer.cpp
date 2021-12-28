#include "lexer.hpp"

Lexer::Lexer(const std::string &filename) {
    New(filename);
}

 int Lexer::New(const std::string& filename) {
     FILE *fp = fopen(filename.c_str(), "r");
     if (!fp) {
         return -1;
     }

    fseek(fp, 0, SEEK_END);
    // 파일의 사이즈를 구한다
    size_t size = ftell(fp);

    if (size > 0) {
        // 문자열의 메모리를 재할당해준다.
        input.resize(size);

        // 파일 포인터를 첫번째 위치로 이동
        rewind(fp);

        // 파일의 내용을 읽는다.    
        fread(&input[0], 1, size, fp);
    }

    fclose(fp);
    ReadChar();

    return 0;
 }

void Lexer::ReadChar() {
    if (read_position >= input.length()) {
        ch = 0;
    } else {
        ch = input[read_position];
    }

    position = read_position;
    read_position += 1;
}

Token Lexer::NextToken() {
    Token token {};

    switch (ch) {
        case '=':
            token.token_type = TOKEN_ASSIGN;
            token.literal = "=";
            break;
        case ';':
            token.token_type = TOKEN_SEMICOLON;
            token.literal = ";";
            break;
        case '(':
            token.token_type = TOKEN_LPAREN;
            token.literal = "(";
            break;
        case ')':
            token.token_type = TOKEN_RPAREN;
            token.literal = ")";
            break;
        case ',':
            token.token_type = TOKEN_COMMA;
            token.literal = ",";
            break;
        case '+':
            token.token_type = TOKEN_PLUS;
            token.literal = "+";
            break;
        case '{':
            token.token_type = TOKEN_LBRACE;
            token.literal = "{";
            break;
        case '}':
            token.token_type = TOKEN_RBRACE;
            token.literal = "}";
            break;
        case 0:
            token.token_type = TOKEN_EOF;
            token.literal = "";
            break;
        default:
            if (IsLetter(ch)) {
                token.literal = ReadIdentifier();
                return token;
            } else {
                token.token_type = TOKEN_ILLEGAL;
                token.literal = "ILLEGAL";
            } 
    }

    ReadChar();
    return token;
}

bool Lexer::IsLetter(char ch) {
    return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_';
}

std::string Lexer::ReadIdentifier() {
    size_t start_position = position;
    while (IsLetter(ch)){
        ReadChar();
    }
    return input.substr(start_position, position - start_position);
}