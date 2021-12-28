#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "token.hpp"

class Lexer {
public:
    Lexer() = default;
    Lexer(const std::string &filename);

    int New(const std::string& filename);
    void ReadChar();
    Token NextToken();

private:
    bool IsLetter(char ch);
    std::string ReadIdentifier();

    std::string input {};
    size_t position = 0;
    size_t read_position = 0;
    char ch = 0;    
};