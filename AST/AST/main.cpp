//
//  main.cpp
//  AST
//
//  Created by Evelyn on 2020/2/1.
//  Copyright © 2020 Evelyn. All rights reserved.
//

#include <iostream>
using namespace std;

string INTEGER = "INTEGER";
string PLUS = "PLUS";
string MINUS = "MINUS";
string END = "END";

class Token {
public:
    string type;
    string value;
    
    Token();
    Token(string, string);
    
    string to_string();
    
    void error();
};

Token:: Token(string type, string value) {
    this->type = type;
    this->value = value;
}

std:: ostream& operator<< (std:: ostream &strm, const Token &token) {
    return strm << "Token <" << token.type << ", " << token.value << ">" << endl;
}

///////////////////////////////////////////////
// Lexical analysis part.                    //
///////////////////////////////////////////////
class Tokenizer {
public:
    string text;
    int pos;
    char current_char = text[pos];
};


///////////////////////////////////////////////
// Parser part.                              //
///////////////////////////////////////////////
class Parser {
public:
    Tokenizer tokenizer;
    Token current_token;
    
    void error();
    
    
};

int main(int argc, const char * argv[]) {
    Token t = Token("PLUS", "+");
    cout << t <<endl;
    return 0;
}
