//
//  main.cpp
//  AST
//
//  Created by Evelyn on 2020/2/1.
//  Copyright © 2020 Evelyn. All rights reserved.
//

#include <iostream>
using namespace std;

enum token_type {
    NUMBER,
    PLUS,
    MINUS,
    END
};

class Token {
public:
    token_type type;
    string value;
    
    Token();
    Token(token_type, string);
    
    void error();
};

Token:: Token() {
    
}

Token:: Token(token_type type, string value) {
    this->type = type;
    this->value = value;
}

std:: ostream& operator<< (std:: ostream &strm, const Token &token) {
    return strm << "Token <" <<  token.type << ", " << token.value << ">" << endl;
}


///////////////////////////////////////////////
// Lexical analysis part.                    //
///////////////////////////////////////////////
class Lexer{
public:
    string text;
    // a pointer to input string `text`.
    int pos;
    char current_char;
    
    Lexer();
    Lexer(string text);
    void error();
    Token get_next_token();

private:
    void advance();
    void skip_whitespace();
    int integer();
};

Lexer:: Lexer() {
    
}

Lexer:: Lexer(string text) {
    this->text = text;
    this->pos = 0;
    this->current_char = this->text[0];
}

void Lexer:: error() {
    throw "Invalid lexicality!";
}

/**
 move `pos` pointer advance and set the `current_char` variable.
 */
void Lexer:: advance() {
    this->pos += 1;
    if (this->pos > this->text.length() - 1) {
        this->current_char = NULL;
    }
    else
        this->current_char = this->text[this->pos];
}

void Lexer:: skip_whitespace() {
    while (this->pos < this->text.length()  && this->current_char == ' ') {
        this->advance();
    }
}

/**
 return a multi-integer digit. e.g. 123
 @return 123
 */
int Lexer:: integer() {
    string res;
    while (this->pos < this->text.length() && this->current_char >= '0' && this->current_char <= '9') {
        res += this->current_char;
        this->advance();
    }
    return atoi(res.c_str());
}

Token Lexer:: get_next_token() {
    while (this->pos < this->text.length()) {
        if (this->current_char == ' ') {
            this->skip_whitespace();
            continue;
        }
        
        if (this->current_char <= '9' && this->current_char >= '0')
            return Token(NUMBER, std:: to_string(this->integer()));
        
        if (this->current_char ==  '+') {
            this->advance();
            return Token(PLUS, "+");
        }
        
        if (this->current_char == '-') {
            this->advance();
            return Token(MINUS, "-");
        }
        
        this->error();
    }
    return Token(END, "NULL");
}


///////////////////////////////////////////////
// Parser part.                              //
///////////////////////////////////////////////
class Parser {
public:
    Lexer lexer;
    Token current_token;
    
    Parser();
    Parser(Lexer lexer, Token token);
    
    void error();
    
private:
    void eat();
};

Parser:: Parser() {
    
}

Parser:: Parser (Lexer lexer, Token token) {
    this->lexer = lexer;
    this->current_token = token;
}

void Parser:: error() {
    throw "Invalid syntax!";
}


int main(int argc, const char * argv[]) {
    string t = "1+ 2";
    Lexer x = Lexer(t);
    cout<< x.get_next_token() <<endl;
    cout<<x.get_next_token()<<endl;
    cout<<x.get_next_token()<<endl;
    
    return 0;
}
