//
// Created by shiraz on 4.11.2019.
//

#ifndef EX1__EX1_H_
#define EX1__EX1_H_
#include <unordered_map>
#include "Expression.h"
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <sstream>
#define UMINUS '@'
#define UPLUS '&'
enum operators { OPEN_BRACKET = 0, PLUS, MINUS, MUL, DIV, U_MINUS, U_PLUS };
using namespace std;

class UnaryOperator : public Expression {
 public:
  UnaryOperator(Expression *expression) : m_expression(expression) {}
  double calculate() {
    return this->m_expression->calculate();
  }
  virtual ~UnaryOperator() {
  }
 protected:
  Expression *m_expression;
};

class UPlus : public UnaryOperator {
 public:
  UPlus(Expression *expression) : UnaryOperator(expression) {}
  virtual ~UPlus() {
    delete m_expression;
  }
};

class UMinus : public UnaryOperator {
 public:
  UMinus(Expression *expression) : UnaryOperator(expression) {}
  double calculate() {
    return -1 * UnaryOperator::calculate();
  }
  virtual ~UMinus() {
    delete m_expression;
  }
};

class BinaryOperator : public Expression {
 public:
  BinaryOperator(Expression *left, Expression *right) : m_left(left), m_right(right) {}
  Expression *getLeft() {
    return this->m_left;
  }
  Expression *getRight() {
    return this->m_right;
  }
  virtual ~BinaryOperator() {}
 protected:
  Expression *m_left;
  Expression *m_right;
};

class Plus : public BinaryOperator {
 public:
  Plus(Expression *left, Expression *right) : BinaryOperator(left, right) {}
  double calculate() {
    return getLeft()->calculate() + getRight()->calculate();
  }
  virtual ~Plus() {
    delete m_right;
    delete m_left;
  }
};

class Minus : public BinaryOperator {
 public:
  Minus(Expression *left, Expression *right) : BinaryOperator(left, right) {}
  double calculate() {
    return getLeft()->calculate() - getRight()->calculate();
  }
  virtual ~Minus() {
    delete m_right;
    delete m_left;
  }
};

class Mul : public BinaryOperator {
 public:
  Mul(Expression *left, Expression *right) : BinaryOperator(left, right) {}
  double calculate() {
    return getLeft()->calculate() * getRight()->calculate();
  }
  virtual ~Mul() {
    delete m_right;
    delete m_left;
  }
};

class Div : public BinaryOperator {
 public:
  Div(Expression *left, Expression *right) : BinaryOperator(left, right) {}
  double calculate() {
    if (getRight()->calculate() == 0) {
      throw "bad input - divide by zero";
    }
    double div = getLeft()->calculate() / getRight()->calculate();
    return div;
  }
  virtual ~Div() {
    delete m_right;
    delete m_left;
  }
};

class Value : public Expression {
 private:
  double const m_value;
 public:
  Value(double value) : m_value(value) {}
  double calculate() {
    return this->m_value;
  }
  virtual ~Value() {}
};

class Variable : public Expression {
 public:
  Variable(const string &name, unordered_map<string, float> var_values_var1) : m_name(name), var_values_var(var_values_var1) {
    checkValidity(name);
  }
  void checkValidity(string c) {
    int length = c.length();
    for (int i = 0; i < length; i++) {
      //is not a letter
      if (isLetter(c[i]) == false) {
        //is not _
        if (c[i] != '_') {
          // is not a number
          if (isDigit(c[i]) == false) {
            throw "bad input - invalid variable m_name";
            //if the variable m_name starts with a number it is invalid
          } else if (i == 0) {
            throw "bad input - invalid variable m_name";
          }
        }
      }
    }
  }
  bool isDigit(char c) {
    string digits = "0123456789";
    int length = digits.length();
    for (int i = 0; i < length; i++) {
      if (c == digits[i]) {
        return true;
      }
    }
    return false;
  }
  bool isLetter(char c) {
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int length = letters.length();
    for (int i = 0; i < length; i++) {
      if (c == letters[i]) {
        return true;
      }
    }
    return false;
  }
  double calculate() {
    return var_values_var.at(m_name);
  }
  void increase(int number) {
    var_values_var.at(m_name) += number;
  }
  void decrease(int number) {
    var_values_var.at(m_name) -= number;
  }

  Variable &operator++() {
    this->increase(1);
    return *this;
  }
  Variable &operator++(int) {
    this->operator++();
    return *this;
  }
  Variable &operator--() {
    this->decrease(1);
    return *this;
  }
  Variable &operator--(int) {
    this->operator--();
    return *this;
  }
  Variable &operator+=(double number) {
    this->increase(number);
    return *this;
  }
  Variable &operator-=(double number) {
    this->decrease(number);
    return *this;
  }

  virtual ~Variable() {}
 private:
  string m_name;
  unordered_map<string, float> var_values_var;
};

class Interpreter {
 private:
  map<string, double> variablesMap;
  stack<char> operatorStack = {};
  stack<Expression *> expressionStack = {};
  queue<char> postQueue = {};
  unordered_map<string, float> var_values;
  bool isPrevUnary = false;
 public:
  Interpreter(unordered_map<string, float> var_values1) : var_values(var_values1){};
  float interpret(string expression) {
    try {
      creatingPostQueue(expression);
      return creatingExpression()->calculate();
    } catch (exception e) {
      if (!isCharConstException(e)) {
        throw "bad input";
      }
    }
    return 0;
  }
  virtual ~Interpreter() {}
  bool isOperator(char c) {
    if ((c == '+') || (c == '-') || (c == '*') || (c == '/')) {
      return true;
    }
    return false;
  }
  void insertDelimiterIfNeeded(char previous) {
    if (postQueue.empty()) {
      return;
    }
    if ((postQueue.back() != ';') && (isOperator(previous) == false) && (previous != UMINUS) && (previous != UPLUS)) {
      postQueue.push(';');
    }
  }
  void creatingPostQueue(string expression) {
    int i;
    Variable* v = new Variable("s", var_values);
    char previous = ' ';
    char currentChar = ' ';
    int length = expression.size();
    for (i = 0; i < length; i++) {
      currentChar = expression[i];
      if (currentChar == '(') {
        operatorStack.push(currentChar);
        previous = currentChar;
        isPrevUnary = false;
        continue;
      } else if (currentChar == ')') {
        if (operatorStack.empty()) {
          throw "bad input - invalid bracket";
        }
        while (operatorStack.top() != '(') {
          if (!postQueue.empty()) {
            insertDelimiterIfNeeded(postQueue.back());
          }
          postQueue.push(operatorStack.top());
          operatorStack.pop();
          if (operatorStack.empty()) {
            throw "bad input - invalid bracket";
          }
        }
        if (operatorStack.top() == '(') {
          if (!postQueue.empty()) {
            insertDelimiterIfNeeded(postQueue.back());
          }
          operatorStack.pop();
        }
        previous = currentChar;
        isPrevUnary = false;
        continue;
        //it is an operator
      } else if (isOperator(currentChar)) {
        insertOperator(currentChar, previous);
        previous = currentChar;
        continue;
        //love
      } else if (v->isLetter(currentChar)) {
        postQueue.push(currentChar);
        previous = currentChar;
      } else {      //check if this is a situation of unary operation before variable m_name without brackets
        if (isVariableName(currentChar) == true) {
          if (isPrevUnary == true) {
            throw "bad input - invalid operation";
          } else {
            postQueue.push(currentChar);
            previous = currentChar;

            continue;
          }
        }
        if (currentChar == UMINUS || currentChar == UPLUS)  {
          throw "bad input - invalid operator";
        }else if (currentChar == '1' || currentChar == '2' || currentChar == '3' || currentChar == '4' ||
            currentChar == '5' || currentChar == '6' || currentChar == '7' || currentChar == '8'
            || currentChar == '9' || currentChar == '0'){
          postQueue.push(currentChar);
          previous = currentChar;
        } else if (currentChar == '.') {
          if (previous == '.') {
            throw "bad input";
          }
          if (previous == '1' || previous == '2' || previous == '3' || previous == '4' ||
              previous == '5' || previous == '6' || previous == '7' || previous == '8'
              || previous == '9' || previous == '0'){
            postQueue.push(currentChar);
            previous = currentChar;
          } else {
            throw "bad input";
          }
        } else {
          throw "bad input - invalid operator";
        }

      }
    }
    while (!operatorStack.empty()) {
      if (operatorStack.top() == '(') {
        throw "bad input - invalid bracket";
      }
      if (!postQueue.empty()) {
        insertDelimiterIfNeeded(postQueue.back());
      }
      postQueue.push(operatorStack.top());
      operatorStack.pop();
    }
    if (!postQueue.empty()) {
      insertDelimiterIfNeeded(postQueue.back());
    }
  }
  Expression *creatingExpression() {
    string v = "";
    while (!postQueue.empty()) {
      char currentChar = postQueue.front();
      bool c = (isOperator(currentChar) || (currentChar == UMINUS) || (currentChar == UPLUS));
      //this is a m_value or a variable m_name
      if ((currentChar != ';') && (c == false)) {
        v += currentChar;
      } else if (currentChar == ';') {
        creatingVarOrValue(v);
        v = "";
        //this is an operator
      } else if (c == true) {
        enum operators oper = operatorTyp(currentChar);
        addExpressionToStack(oper);
      }
      postQueue.pop();
    }
    if (expressionStack.empty()) {
      throw "bad input";
    }
    Expression *ex = expressionStack.top();
    expressionStack.pop();
    if (!expressionStack.empty()) {
      throw "bad input";
    }
    return ex;
  }
  enum operators operatorTyp(char oper) {
    switch (oper) {
      case '+': {
        return PLUS;
      }
      case '-': {
        return MINUS;
      }
      case '*' : {
        return MUL;
      }
      case '/': {
        return DIV;
      }
      case UMINUS: {
        return U_MINUS;
      }
      case UPLUS : {
        return U_PLUS;
      }
      case '(' : {
        return OPEN_BRACKET;
      }
      default:throw "bad input - invalid operator";
    }
  }
  void addExpressionToStack(enum operators oper) {
    if (expressionStack.empty()) {
      throw "bad input - invalid operation";
    }
    if (isUnaryOperator(oper) == true) {
      Expression *exp = expressionStack.top();
      expressionStack.pop();
      insertUnaryExpression(oper, exp);
      return;
    }
    //this is binary operator
    Expression *right = expressionStack.top();
    expressionStack.pop();
    if (expressionStack.empty()) {
      throw "bad input - invalid operation";
    }
    Expression *left = expressionStack.top();
    expressionStack.pop();
    insertBinaryExpression(oper, left, right);
  }
  void insertBinaryExpression(enum operators binaryOperator, Expression *left, Expression *right) {
    switch (binaryOperator) {
      case PLUS: {
        expressionStack.push(new Plus(left, right));
        break;
      }
      case MINUS: {
        expressionStack.push(new Minus(left, right));
        break;
      }
      case MUL: {
        expressionStack.push(new Mul(left, right));
        break;
      }
      case DIV: {
        expressionStack.push(new Div(left, right));
        break;
      }
      default:throw "bad input - invalid operator";
    }
  }
  void insertUnaryExpression(operators unaryOperator, Expression *expression) {
    switch (unaryOperator) {
      case U_PLUS: {
        expressionStack.push(new UPlus(expression));
        break;
      }
      case U_MINUS: {
        expressionStack.push(new UMinus(expression));
        break;
      }
      default:throw "bad input - invalid operator";
    }
  }
  bool isUnaryOperator(operators oper) {
    if ((oper == U_MINUS) || (oper == U_PLUS)) {
      return true;
    }
    return false;

  }
  bool isBinary(char current, char prev) {
    if (isOperator(current) == true) {
      if (isUnary(prev) == false) {
        return true;
      }
    }
    return false;
  }
  bool isUnary(char previous) {
    if ((previous == ' ') || (previous == '(')) {
      return true;
    }
    return false;
  }
  bool isCurrentSmaller(operators current, operators prev) {
    switch (current) {
      case MUL: {
      }
      case DIV : {
        if ((prev == PLUS) || (prev == MINUS)) {
          return false;
        }
        return false;
      }
      case PLUS : {

      }
      case MINUS : {
        if ((prev == OPEN_BRACKET)) {
          return false;
        }
        return true;
      }
      case U_PLUS : {

      }
      case U_MINUS : {

        return false;
        //return true;
      }
      case OPEN_BRACKET : {
        if (prev == OPEN_BRACKET) {
          return false;
        }
        return true;
      }
      default: {
        throw "bad input - invalid operator";
      }
    }
  }
  void creatingVarOrValue(string v) {
    unordered_map<string, float>::iterator it;
    //Singleton* singleton = Singleton::getSingleton();
    it = var_values.find(v);
    //check if variable exist
    if (it != var_values.end()) {
      expressionStack.push(new Variable(v, var_values));
    } else {
      if (isANumber(v)) {
        expressionStack.push(new Value(stod(v)));
      } else {
        throw "bad input - variable does not exist";
      }
    }
  }
  void insertOperator(char currentChar, char previous) {
    if (!postQueue.empty()) {
      insertDelimiterIfNeeded(postQueue.back());
    }
    if (isOperator(previous)) {
      throw "bad input - invalid operation";
    }
    if (isUnary(previous) == true) {
      isPrevUnary = true;
      if (currentChar == '-') {
        operatorStack.push(UMINUS);
      } else {
        operatorStack.push(UPLUS);
      }
    } else if (isBinary(currentChar, previous)) {
      isPrevUnary = false;
      while (!postQueue.empty()) {
        insertDelimiterIfNeeded(postQueue.back());
        if (operatorStack.empty()) {
          operatorStack.push(currentChar);
          break;
        }
        if (isCurrentSmaller(operatorTyp(currentChar), operatorTyp(operatorStack.top()))) {
          postQueue.push(operatorStack.top());
          operatorStack.pop();
        } else {
          operatorStack.push(currentChar);
          break;
        }
      }
    }
  }
  bool isCharConstException(exception e) {
    string exception = e.what();
    string message1 = "bad input - invalid variable m_name";
    string message2 = "bad input - divide by zero";
    string message3 = "bad input - invalid m_value";
    string message4 = "bad input - invalid bracket";
    string message5 = "bad input - invalid operator";
    string message6 = "bad input - invalid operation";
    string message7 = "bad input - variable does not exist";
    string message8 = "bad input - unary operation on variable without brackets";

    if ((message1.compare(exception) == 0) || (message2.compare(exception) == 0) || (message3.compare(exception) == 0)
        || (message4.compare(exception) == 0) || (message5.compare(exception) == 0) || (message6.compare(exception) == 0)
        || (message7.compare(exception) == 0) || (message8.compare(exception) == 0)) {
      return true;
    }
    return false;
  }
  bool isVariableName(char currentChar) {
    string name = "";
    name += currentChar;
    try {
      Variable *v = new Variable(name, var_values);
      v->calculate();
    } catch (const char *e) {
      return false;
    }
    return true;
  }
  bool isANumber(string st) {
    string numbers = "1234567890";
    int stringLength = st.length();
    //int numberLength = numbers.length();
    //bool isANum = false;
    int period = 0;

    for (int i = 0; i < stringLength; i++) {
      if (!(st[i] == '1' || st[i] == '2' || st[i] == '3' || st[i] == '4' || st[i] == '5' || st[i] == '6'
          || st[i] == '7' || st[i] == '8' || st[i] == '9' || st[i] == '0')) {
        if (st[i] == '.' && i != 0) {
          if (period < 1) {
            period++;
            continue;
          } else {
            return false;
          }
        } else {
          return false;
        }
      }
    }
    return true;
  }




};


class ex1 {
 public :
  static float cal(string expression, unordered_map<string, float> var_values) {
    Interpreter* interpreter = new Interpreter(var_values);
    //dispose the spaces
    unsigned int i = 0, count_open_brackets = 0, count_close_brackes = 0;
    string newString = "";
    for (; i < expression.size(); i++) {
      if (expression[i] == ' ') {
        continue;
      }
      if (expression[i] == ')') {
        count_close_brackes++;
      }
      if (expression[i] == '(') {
        count_open_brackets++;
      }
      newString += expression[i];
    }
    //cout<<newString[newString.length()-1];
    if (count_close_brackes > count_open_brackets) {
      newString = newString.substr(0, newString.length() - 1);
    }
    if (count_close_brackes < count_open_brackets) {
      newString = newString.substr(1, newString.length() - 1);
    }
    return interpreter->interpret(newString);
  }
};

#endif //EX1__EX1_H_
