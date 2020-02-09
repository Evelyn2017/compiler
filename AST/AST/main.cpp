//
//  main.cpp
//  AST
//
//  Created by Evelyn on 2020/2/1.
//  Copyright © 2020 Evelyn. All rights reserved.
//

#include "Lexer.hpp"
#include "Parser.hpp"
#include <iostream>
using namespace std;

std:: ostream& operator<< (std:: ostream &strm, const Token& token) {
    return strm << "Token <" <<  token.type << ", " << token.value << ">" << endl;
}

//int main(int argc, const char * argv[]) {
//    string t = "1+ 2";
//    Lexer x = Lexer(t);
//    cout<< x.token_num();
//    vector<Token> token_stream = x.tokenizer();
//    for(int i = 0; i < token_stream.size(); i++) {
//        cout << "i";
//        cout << token_stream[i] <<endl;
//    }
//    return 0;
//}


int main() {
    string input = "1+ 2 +   3";
    Lexer l = Lexer(input);
    Token p1 = l.peek();
    cout<<"peek1: " << p1 << endl;
    Token n1 = l.get_next_token();
    cout << "next1: " << n1 << endl;
    p1 = l.peek();
    cout << "peek2: " << p1 << endl;
    p1 = l.peek();
    cout<< "peek3: " << p1 << endl;
    n1 = l.get_next_token();
    n1 = l.get_next_token();
    cout << "peek4: "<< l.peek() << endl;
    return 0;
}
