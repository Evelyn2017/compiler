# Token type
INTEGER, PLUS, MINUS, MUL, DIV, LPAREN, RPAREN, EOF = ('INTEGER', 'PLUS', 'MINUS',
                                                       'MUL', 'DIV', '(', ')', 'EOF')


class Token(object):

    def __init__(self, type, value):
        self.type = type
        self.value = value

    def __str__(self):
        return "Token <{type}, {value}>".format(type=self.type,
                                                value=repr(self.value))

    def __repr__(self):
        return self.__str__()


class Lexical(object):

    def __init__(self, text):
        self.text = text

        self.pos = 0

        self.current_char = self.text[self.pos]

    def error(self):
        raise Exception("Invalid syntax!")

    def advance(self):
        self.pos += 1
        if self.pos > len(self.text) - 1:
            self.current_char = None
        else:
            self.current_char = self.text[self.pos]

    def skip_whitespace(self):
        while self.current_char is not None and self.current_char.isspace():
            self.advance()

    def integer(self):
        result = ''
        while self.current_char is not None and self.current_char.isdigit():
            result += self.current_char
            self.advance()
        return int(result)

    def get_next_token(self):
        while self.current_char is not None:

            if self.current_char.isspace():
                self.skip_whitespace()
                continue

            if self.current_char.isdigit():
                return Token(INTEGER, self.integer())

            if self.current_char == '+':
                self.advance()
                return Token(PLUS, '+')

            if self.current_char == '-':
                self.advance()
                return Token(MINUS, '-')

            if self.current_char == '*':
                self.advance()
                return Token(MUL, '*')

            if self.current_char == '/':
                self.advance()
                return Token(DIV, '/')

            if self.current_char == '(':
                self.advance()
                return Token(LPAREN, '(')

            if self.current_char == ')':
                self.advance()
                return Token(RPAREN, ')')

            self.error()

        return Token(EOF, None)


class Interprtr(object):

    def __init__(self, lexical):
        self.lexical = lexical

        self.current_token = self.lexical.get_next_token()

    def error(self):
        raise Exception("Invalid syntax!")

    def eat(self, token_type):
        if self.current_token.type == token_type:
            self.current_token = self.lexical.get_next_token()
        else:
            self.error()

    def factor(self):
        """factor: INTEGER | LPAREN expr RPAREN"""
        token = self.current_token
        if token.type == INTEGER:
            self.eat(INTEGER)
            return token.value
        elif token.type == LPAREN:
            self.eat(LPAREN)
            result = self.expr()
            self.eat(RPAREN)
            return result

    def term(self):
        """term : factor ((MUL | DIV) factor)*"""
        result = self.factor()
        while self.current_token.type in (MUL, DIV):
            token = self.current_token
            if token.type == MUL:
                self.eat(MUL)
                result = result * self.factor()
            elif self.current_token.type == DIV:
                try:
                    self.eat(DIV)
                    result = result / self.factor()
                except Exception:
                    raise Exception("can not divided by zero!")

        return result

    def expr(self):
        """expr : term ((PLUS | MINUS) term) *"""
        result = self.term()

        while self.current_token.type in (PLUS, MINUS):
            token = self.current_token
            if token.type == PLUS:
                self.eat(PLUS)
                result = result + self.term()
            elif token.type == MINUS:
                self.eat(MINUS)
                result = result - self.term()

        return result


def main():
    while True:
        text = input('xx: ')
        lexer = Lexical(text)
        it = Interprtr(lexer)
        print(it.expr())


if __name__ == '__main__':
    main()
