# Token types
# 
INTEGER, PLUS, MINUS, EOF = 'INTEGER', 'PLUS', 'MINUS', 'EOF'


class Token(object):

    def __init__(self, type, value):
        self.type = type
        self.value = value

    def __str__(self):
        return "Token <{type}, {value}>".format(type=self.type,
                                                value=repr(self.value))

    def __repr__(self):
        return self.__str__()


class Scanner(object):

    def __init__(self, text):
        # client input string, e.g. "3+5", "12 + 2+ 1", etc.
        self.text = text
        # an index into self.text
        self.pos = 0

        self.current_char = self.text[self.pos]

    def error(self):
        raise Exception("Invalid syntax!")

    def advance(self):
        # Advance self.pos and set self.current_chat variable.
        self.pos += 1
        if self.pos > len(self.text) - 1:
            self.current_char = None
        else:
            self.current_char = self.text[self.pos]

    def skip_whitespace(self):
        if self.current_char is not None and self.current_char.isspace():
            self.advance()

    def integer(self):
        # return a (multi-integer) digit consumed from the input string.
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

            self.error()

        return Token(EOF, None)


class Interpreter(object):

    def __init__(self, scanner):
        self.scanner = scanner

        self.current_token = scanner.get_next_token()

    def error(self):
        raise Exception("Invalid syntax!")

    def eat(self, token_type):
        token = self.current_token
        if token.type == token_type:
            self.current_token = self.scanner.get_next_token()
        else:
            self.error()

    def factor(self):
        token = self.current_token
        self.eat(INTEGER)
        return token.value

    def expr(self):
        result = self.factor()

        while self.current_token.type in (PLUS, MINUS):
            if self.current_token.type == PLUS:
                self.eat(PLUS)
                result = result + self.factor()
            elif self.current_token.type == MINUS:
                self.eat(MINUS)
                result = result - self.factor()
        return result


if __name__ == '__main__':
    text = input('calc1> ')
    scanner = Scanner(text)
    interpreter = Interpreter(scanner)
    print(interpreter.expr())
    # print(scanner.integer())
    # print(scanner.get_next_token())
    # print(scanner.get_next_token())
    # print(scanner.get_next_token())
    # print(scanner.get_next_token())
