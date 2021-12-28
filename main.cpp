#include <iostream>
#include <string>
#include "lexer.hpp"

int main(void) {
    std::string file_name { "/home/smoh/interpreter_in_c++/file/input" };
    
    Lexer lexer;
    lexer.New(file_name);


    while(1) {
        Token token = lexer.NextToken();
        if (token.token_type == TOKEN_EOF) {
            break;
        }

        printf("%d %s\n", token.token_type, token.literal.c_str());
    }    

    return 0;
}