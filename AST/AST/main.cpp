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
    string input = "12+ 224 +   33 + 22";
    Lexer l = Lexer(input);
    cout<<"peek1: "<<l.peek()<<endl;
    cout<<"next1: "<<l.get_next_token()<<endl;
    cout<<"peel2: "<<l.peek()<<endl;
    cout<<"peek3: "<<l.peek() <<endl;
    l.get_next_token();
    l.get_next_token();
    l.get_next_token();
    cout<<"peek4: "<<l.peek()<<endl;
    cout<<"next2-4:" <<l.get_next_token()<<endl;
    cout<<"peek4: "<<l.peek()<<endl;
    
    return 0;
}
