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
#include <fstream>
#include <set>
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


//int main() {
//    string input = "12+ 224 +   33 + 22";
//    Lexer l = Lexer(input);
//    cout<<"peek1: "<<l.peek()<<endl;
//    cout<<"next1: "<<l.get_next_token()<<endl;
//    cout<<"peel2: "<<l.peek()<<endl;
//    cout<<"peek3: "<<l.peek() <<endl;
//    l.get_next_token();
//    l.get_next_token();
//    l.get_next_token();
//    cout<<"peek4: "<<l.peek()<<endl;
////    cout<<"next2-4:" <<l.get_next_token()<<endl;
//    cout<<"peek4: "<<l.peek()<<endl;
//    
//    return 0;
//}
void crack_grammer() {
    set<char> non_t;
    set<char> t;
    
    string line;
    ifstream g_file("g.txt");
    if (!g_file.is_open()) {
        cout<<"error openning file" <<endl;
        exit(1);
    }
    while (getline(g_file, line)) {
        non_t.insert(line[0]);
    }
    
    set<char> :: iterator it;
    for (it = non_t.begin(); it != non_t.end(); it++)
        cout<<*it<<" ";
}

//int main() {
//    crack_grammer();
//    return 0;
//}
