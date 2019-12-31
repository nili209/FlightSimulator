//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__INTERPRETER_H_
#define EX3__INTERPRETER_H_
#define UMINUS '@'
#define UPLUS '&'
#include "Variable.h"
#include "UnaryOperator.h"
#include "BinaryOperator.h"
#include "UPlus.h"
#include "UMinus.h"
#include "Plus.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include "Value.h"
#include <unordered_map>
#include "Expression.h"
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <sstream>
enum operators { OPEN_BRACKET = 0, PLUS, MINUS, MUL, DIV, U_MINUS, U_PLUS };
using namespace std;
class Interpreter {
 private:
  map<string, double> variablesMap;
  stack<char> operatorStack = {};
  stack<Expression *> expressionStack = {};
  queue<char> postQueue = {};
  unordered_map<string, float> var_values;
  bool isPrevUnary = false;
 public:
  Interpreter(unordered_map<string, float> var_values1);
  float interpret(string expression);
  bool isOperator(char c);
  void insertDelimiterIfNeeded(char previous);
  void creatingPostQueue(string expression);
  Expression *creatingExpression();
  enum operators operatorTyp(char oper);
  void addExpressionToStack(enum operators oper);
  void insertBinaryExpression(enum operators binaryOperator, Expression *left, Expression *right);
  void insertUnaryExpression(operators unaryOperator, Expression *expression);
  bool isUnaryOperator(operators oper);
  bool isBinary(char current, char prev);
  bool isUnary(char previous);
  bool isCurrentSmaller(operators current, operators prev);
  void creatingVarOrValue(string v);
  void insertOperator(char currentChar, char previous);
  bool isCharConstException(exception e);
  bool isVariableName(char currentChar);
  bool isANumber(string st);
  virtual ~Interpreter();
};
#endif //EX3__INTERPRETER_H_
