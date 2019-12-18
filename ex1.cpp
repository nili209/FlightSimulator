//
// Created by shiraz on 4.11.2019.
//

#include "ex1.h"
#include <sstream>
#include <list>
#include <string>
using namespace std;
//UnaryOperator::UnaryOperator(Expression *expression) : m_expression(expression) {}
//
//double UnaryOperator::calculate() {
//  return this->m_expression->calculate();
//}
//UnaryOperator::~UnaryOperator() {
//}
//
//UPlus::UPlus(Expression *expression) : UnaryOperator(expression) {}
//UPlus::~UPlus() {
//  delete m_expression;
//}
//
//UMinus::UMinus(Expression *expression) : UnaryOperator(expression) {}
//double UMinus::calculate() {
//  return -1 * UnaryOperator::calculate();
//}
//UMinus::~UMinus() {
//  delete m_expression;
//}
//
//BinaryOperator::BinaryOperator(Expression *left, Expression *right) : m_left(left), m_right(right) {}
//Expression *BinaryOperator::getLeft() {
//  return this->m_left;
//}
//Expression *BinaryOperator::getRight() {
//  return this->m_right;
//}
//
//BinaryOperator::~BinaryOperator() {
//}
//
//Value::Value(double value) : m_value(value) {}
//
//double Value::calculate() {
//  return this->m_value;
//}
//Value::~Value() {
//}
//
//Variable::Variable(const string &name) : m_name(name) {
//  checkValidity(name);
//}
//void Variable::checkValidity(string c) {
//  int length = c.length();
//  for (int i = 0; i < length; i++) {
//    //is not a letter
//    if (isLetter(c[i]) == false) {
//      //is not _
//      if (c[i] != '_') {
//        // is not a number
//        if (isDigit(c[i]) == false) {
//          throw "bad input - invalid variable m_name";
//          //if the variable m_name starts with a number it is invalid
//        } else if (i == 0) {
//          throw "bad input - invalid variable m_name";
//        }
//      }
//    }
//  }
//}
//bool Variable::isDigit(char c) {
//  string digits = "0123456789";
//  int length = digits.length();
//  for (int i = 0; i < length; i++) {
//    if (c == digits[i]) {
//      return true;
//    }
//  }
//  return false;
//}
//bool Variable::isLetter(char c) {
//  string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
//  int length = letters.length();
//  for (int i = 0; i < length; i++) {
//    if (c == letters[i]) {
//      return true;
//    }
//  }
//  return false;
//}
//double Variable::calculate() {
//  Var* v = (Var*)singleton->symbol_table_program.at(m_name);
//  return v->getValue();
//}
//void Variable::increase(int number) {
//  Var* v = (Var*)singleton->symbol_table_program.at(m_name);
//  v->getValue() += number;
//}
//void Variable::decrease(int number) {
//  Var* v = (Var*)singleton->symbol_table_program.at(m_name);
//  v->getValue() -= number;
//}
//
//Variable &Variable::operator++() {
//  this->increase(1);
//  return *this;
//}
//Variable &Variable::operator++(int) {
//  this->operator++();
//  return *this;
//}
//Variable &Variable::operator--() {
//  this->decrease(1);
//  return *this;
//}
//Variable &Variable::operator--(int) {
//  this->operator--();
//  return *this;
//}
//Variable &Variable::operator+=(double number) {
//  this->increase(number);
//  return *this;
//}
//Variable &Variable::operator-=(double number) {
//  this->decrease(number);
//  return *this;
//}
//
//Variable::~Variable() {
//}
//
//Plus::Plus(Expression *left, Expression *right) : BinaryOperator(left, right) {}
//double Plus::calculate() {
//  return getLeft()->calculate() + getRight()->calculate();
//}
//
//Plus::~Plus() {
//  delete m_right;
//  delete m_left;
//}
//Minus::Minus(Expression *left, Expression *right) : BinaryOperator(left, right) {}
//double Minus::calculate() {
//  return getLeft()->calculate() - getRight()->calculate();
//}
//Minus::~Minus() {
//  delete m_right;
//  delete m_left;
//}
//Mul::Mul(Expression *left, Expression *right) : BinaryOperator(left, right) {}
//double Mul::calculate() {
//  return getLeft()->calculate() * getRight()->calculate();
//}
//Mul::~Mul() {
//  delete m_right;
//  delete m_left;
//}
//
//Div::Div(Expression *left, Expression *right) : BinaryOperator(left, right) {}
//double Div::calculate() {
//  if (getRight()->calculate() == 0) {
//    throw "bad input - divide by zero";
//  }
//  double div = getLeft()->calculate() / getRight()->calculate();
//  return div;
//}
//Div::~Div() {
//  delete m_right;
//  delete m_left;
//}

//Interpreter::Interpreter() {
//}

//float Interpreter::interpret(string expression) {
//  try {
//    creatingPostQueue(expression);
//    return creatingExpression()->calculate();
//  } catch (exception e) {
//    if (!isCharConstException(e)) {
//      throw "bad input";
//    }
//  }
//  return nullptr;
//}
//
//void Interpreter::setVariables(string variables) {
//  stringstream ss(variables);
//  string item1;
//  list<string> tempList;
//  int flag = 0;
//  //create a list in the odd places is the m_value and other places are for the m_name
//  while (getline(ss, item1, *";")) {
//    stringstream ss2(item1);
//    string item2;
//    flag = 0;
//    //;;
//    if (item1.compare("") == 0) {
//      throw "bad input";
//    }
//    while (getline(ss2, item2, *"=")) {
//      if (flag >= 2) {
//        throw "bad intput";
//      }
//
//      tempList.push_back(item2);
//      flag++;
//    }
//  }
//  //now create a map with <m_value, m_name>
//  int i = 0;
//  string name;
//  double value;
//  string valueString;
//  try {
//    for (auto v = tempList.begin(); v != tempList.end(); v++) {
//      //m_name
//      if (i == 0) {
//        name = *v;
//      }
//      //m_value
//      if (i == 1) {
//        valueString = *v;
//        if (valueString[0] == '.') {
//          throw "bad input - invalid m_value";
//        }
//        if (valueString[0] == '-' || valueString[0] == '+') {
//          if (isANumber(&valueString[1]) == false) {
//            throw "bad input";
//          }
//        } else if (isANumber(*v) == false) {
//          throw "bad input";
//        }
//        value = stod(*v);
//      }
//      i++;
//      if (i == 2) {
//        i = 0;
//        //check if the variable m_name is valid
//        Variable *check = new Variable(name, value);
//        delete check;
//        if (this->variablesMap.empty()) {
//          this->variablesMap.insert({name, value});
//        } else {
//          //check if the variable exist
//          map<string, double>::iterator it;
//          it = this->variablesMap.find(name);
//          if (it != this->variablesMap.end()) {
//            it->second = value;
//          } else {
//            this->variablesMap.insert({name, value});
//          }
//        }
//      }
//    }
//  } catch (exception e) {
//    throw "bad input - invalid m_value";
//  }
//}
//
//Interpreter::~Interpreter() {
//}
//bool Interpreter::isOperator(char c) {
//  if ((c == '+') || (c == '-') || (c == '*') || (c == '/')) {
//    return true;
//  }
//  return false;
//}
//void Interpreter::insertDelimiterIfNeeded(char previous) {
//  if (postQueue.empty()) {
//    return;
//  }
//  if ((postQueue.back() != ';') && (isOperator(previous) == false) && (previous != UMINUS) && (previous != UPLUS)) {
//    postQueue.push(';');
//  }
//}
//void Interpreter::creatingPostQueue(string expression) {
//  int i;
//  char previous = ' ';
//  char currentChar = ' ';
//  int length = expression.length();
//  for (i = 0; i < length; i++) {
//    currentChar = expression[i];
//    if (currentChar == '(') {
//      operatorStack.push(currentChar);
//      previous = currentChar;
//      isPrevUnary = false;
//      continue;
//    } else if (currentChar == ')') {
//      if (operatorStack.empty()) {
//        throw "bad input - invalid bracket";
//      }
//      while (operatorStack.top() != '(') {
//        if (!postQueue.empty()) {
//          insertDelimiterIfNeeded(postQueue.back());
//        }
//        postQueue.push(operatorStack.top());
//        operatorStack.pop();
//        if (operatorStack.empty()) {
//          throw "bad input - invalid bracket";
//        }
//      }
//      if (operatorStack.top() == '(') {
//        if (!postQueue.empty()) {
//          insertDelimiterIfNeeded(postQueue.back());
//        }
//        operatorStack.pop();
//      }
//      previous = currentChar;
//      isPrevUnary = false;
//      continue;
//      //it is an operator
//    } else if (isOperator(currentChar)) {
//      insertOperator(currentChar, previous);
//      previous = currentChar;
//      continue;
//    } else {
//      //check if this is a situation of unary operation before variable m_name without brackets
//      if (isVariableName(currentChar) == true) {
//        if (isPrevUnary == true) {
//          throw "bad input - invalid operation";
//        } else {
//          postQueue.push(currentChar);
//          previous = currentChar;
//
//          continue;
//        }
//      }
//      if (currentChar == UMINUS || currentChar == UPLUS)  {
//        throw "bad input - invalid operator";
//      }else if (currentChar == '1' || currentChar == '2' || currentChar == '3' || currentChar == '4' ||
//      currentChar == '5' || currentChar == '6' || currentChar == '7' || currentChar == '8'
//      || currentChar == '9' || currentChar == '0'){
//        postQueue.push(currentChar);
//        previous = currentChar;
//      } else if (currentChar == '.') {
//        if (previous == '.') {
//          throw "bad input";
//        }
//        if (previous == '1' || previous == '2' || previous == '3' || previous == '4' ||
//            previous == '5' || previous == '6' || previous == '7' || previous == '8'
//            || previous == '9' || previous == '0'){
//            postQueue.push(currentChar);
//            previous = currentChar;
//        } else {
//          throw "bad input";
//        }
//      } else {
//        throw "bad input - invalid operator";
//      }
//
//    }
//  }
//  while (!operatorStack.empty()) {
//    if (operatorStack.top() == '(') {
//      throw "bad input - invalid bracket";
//    }
//    if (!postQueue.empty()) {
//      insertDelimiterIfNeeded(postQueue.back());
//    }
//    postQueue.push(operatorStack.top());
//    operatorStack.pop();
//  }
//  if (!postQueue.empty()) {
//    insertDelimiterIfNeeded(postQueue.back());
//  }
//}
//Expression *Interpreter::creatingExpression() {
//  string v = "";
//  while (!postQueue.empty()) {
//    char currentChar = postQueue.front();
//    bool c = (isOperator(currentChar) || (currentChar == UMINUS) || (currentChar == UPLUS));
//    //this is a m_value or a variable m_name
//    if ((currentChar != ';') && (c == false)) {
//      v += currentChar;
//    } else if (currentChar == ';') {
//      creatingVarOrValue(v);
//      v = "";
//      //this is an operator
//    } else if (c == true) {
//      enum operators oper = operatorTyp(currentChar);
//      addExpressionToStack(oper);
//    }
//    postQueue.pop();
//  }
//  if (expressionStack.empty()) {
//    throw "bad input";
//  }
//  Expression *ex = expressionStack.top();
//  expressionStack.pop();
//  if (!expressionStack.empty()) {
//    throw "bad input";
//  }
//  return ex;
//}
//
//enum operators Interpreter::operatorTyp(char oper) {
//  switch (oper) {
//    case '+': {
//      return PLUS;
//    }
//    case '-': {
//      return MINUS;
//    }
//    case '*' : {
//      return MUL;
//    }
//    case '/': {
//      return DIV;
//    }
//    case UMINUS: {
//      return U_MINUS;
//    }
//    case UPLUS : {
//      return U_PLUS;
//    }
//    case '(' : {
//      return OPEN_BRACKET;
//    }
//    default:throw "bad input - invalid operator";
//  }
//}
//
//void Interpreter::addExpressionToStack(enum operators oper) {
//  if (expressionStack.empty()) {
//    throw "bad input - invalid operation";
//  }
//  if (isUnaryOperator(oper) == true) {
//    Expression *exp = expressionStack.top();
//    expressionStack.pop();
//    insertUnaryExpression(oper, exp);
//    return;
//  }
//  //this is binary operator
//  Expression *right = expressionStack.top();
//  expressionStack.pop();
//  if (expressionStack.empty()) {
//    throw "bad input - invalid operation";
//  }
//  Expression *left = expressionStack.top();
//  expressionStack.pop();
//  insertBinaryExpression(oper, left, right);
//}
//void Interpreter::insertBinaryExpression(enum operators binaryOperator, Expression *left, Expression *right) {
//  switch (binaryOperator) {
//    case PLUS: {
//      expressionStack.push(new Plus(left, right));
//      break;
//    }
//    case MINUS: {
//      expressionStack.push(new Minus(left, right));
//      break;
//    }
//    case MUL: {
//      expressionStack.push(new Mul(left, right));
//      break;
//    }
//    case DIV: {
//      expressionStack.push(new Div(left, right));
//      break;
//    }
//    default:throw "bad input - invalid operator";
//  }
//}
//void Interpreter::insertUnaryExpression(operators unaryOperator, Expression *expression) {
//  switch (unaryOperator) {
//    case U_PLUS: {
//      expressionStack.push(new UPlus(expression));
//      break;
//    }
//    case U_MINUS: {
//      expressionStack.push(new UMinus(expression));
//      break;
//    }
//    default:throw "bad input - invalid operator";
//  }
//}
//
//bool Interpreter::isUnaryOperator(operators oper) {
//  if ((oper == U_MINUS) || (oper == U_PLUS)) {
//    return true;
//  }
//  return false;
//
//}
//bool Interpreter::isBinary(char current, char prev) {
//  if (isOperator(current) == true) {
//    if (isUnary(prev) == false) {
//      return true;
//    }
//  }
//  return false;
//}
//bool Interpreter::isUnary(char previous) {
//  if ((previous == ' ') || (previous == '(')) {
//    return true;
//  }
//  return false;
//}
///*
// * check the operation precidence
// */
//bool Interpreter::isCurrentSmaller(operators current, operators prev) {
//  switch (current) {
//    case MUL: {
//    }
//    case DIV : {
//      if ((prev == MUL) || (prev == DIV) || (prev == PLUS) || (prev == MINUS)) {
//        return false;
//      }
//      return false;
//    }
//    case PLUS : {
//
//    }
//    case MINUS : {
//      if ((prev == PLUS) || (prev == MINUS) || (prev == OPEN_BRACKET)) {
//        return false;
//      }
//      return true;
//    }
//    case U_PLUS : {
//
//    }
//    case U_MINUS : {
//      if ((prev == U_PLUS) || (prev == U_MINUS)) {
//        return false;
//      }
//      return true;
//    }
//    case OPEN_BRACKET : {
//      if (prev == OPEN_BRACKET) {
//        return false;
//      }
//      return true;
//    }
//    default: {
//      throw "bad input - invalid operator";
//    }
//  }
//}
//void Interpreter::creatingVarOrValue(string v) {
//  map<string, double>::iterator it;
//  it = this->variablesMap.find(v);
//  //check if variable exist
//  if (it != this->variablesMap.end()) {
//    expressionStack.push(new Variable(v, it->second));
//  } else {
//      if (isANumber(v)) {
//        expressionStack.push(new Value(stod(v)));
//      } else {
//      throw "bad input - variable does not exist";
//    }
//  }
//}
//void Interpreter::insertOperator(char currentChar, char previous) {
//  if (!postQueue.empty()) {
//    insertDelimiterIfNeeded(postQueue.back());
//  }
//  if (isOperator(previous)) {
//    throw "bad input - invalid operation";
//  }
//  if (isUnary(previous) == true) {
//    isPrevUnary = true;
//    if (currentChar == '-') {
//      operatorStack.push(UMINUS);
//    } else {
//      operatorStack.push(UPLUS);
//    }
//  } else if (isBinary(currentChar, previous)) {
//    isPrevUnary = false;
//    while (!postQueue.empty()) {
//      insertDelimiterIfNeeded(postQueue.back());
//      if (operatorStack.empty()) {
//        operatorStack.push(currentChar);
//        break;
//      }
//      if (isCurrentSmaller(operatorTyp(currentChar), operatorTyp(operatorStack.top()))) {
//        postQueue.push(operatorStack.top());
//        operatorStack.pop();
//      } else {
//        operatorStack.push(currentChar);
//        break;
//      }
//    }
//  }
//}
//bool Interpreter::isCharConstException(exception e) {
//  string exception = e.what();
//  string message1 = "bad input - invalid variable m_name";
//  string message2 = "bad input - divide by zero";
//  string message3 = "bad input - invalid m_value";
//  string message4 = "bad input - invalid bracket";
//  string message5 = "bad input - invalid operator";
//  string message6 = "bad input - invalid operation";
//  string message7 = "bad input - variable does not exist";
//  string message8 = "bad input - unary operation on variable without brackets";
//
//  if ((message1.compare(exception) == 0) || (message2.compare(exception) == 0) || (message3.compare(exception) == 0)
//      || (message4.compare(exception) == 0) || (message5.compare(exception) == 0) || (message6.compare(exception) == 0)
//      || (message7.compare(exception) == 0) || (message8.compare(exception) == 0)) {
//    return true;
//  }
//  return false;
//}
//bool Interpreter::isVariableName(char currentChar) {
//  string name = "";
//  name += currentChar;
//  try {
//    Variable *v = new Variable(name, 0);
//    v->calculate();
//  } catch (const char *e) {
//    return false;
//  }
//  return true;
//}
//
//bool Interpreter::isANumber(string st) {
//  string numbers = "1234567890";
//  int stringLength = st.length();
//  //int numberLength = numbers.length();
//  //bool isANum = false;
//  int period = 0;
//
//  for (int i = 0; i < stringLength; i++) {
//    if (!(st[i] == '1' || st[i] == '2' || st[i] == '3' || st[i] == '4' || st[i] == '5' || st[i] == '6'
//    || st[i] == '7' || st[i] == '8' || st[i] == '9' || st[i] == '0')) {
//      if (st[i] == '.' && i != 0) {
//        if (period < 1) {
//          period++;
//          continue;
//        } else {
//          return false;
//        }
//      } else {
//        return false;
//      }
//    }
//  }
//  return true;
//  /*
//  for (int j = 0; j < stringLength; j++) {
//    isANum = false;
//    for (int i = 0; i < numberLength; i++) {
//      if (numbers[i] == st[j]) {
//        isANum = true;
//      }
//    }
//    if (!isANum) {
//      if (st[j] == '.') {
//        period++;
//        if (period > 1) {
//          return false;
//        }
//    }
//
//  }
//}
//   */
//
//}

