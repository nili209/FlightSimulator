//
// Created by shiraz and nili on 31.12.2019.
//
#include "Interpreter.h"
/*
 * Constructor.
 */
Interpreter::Interpreter(unordered_map<string, float> var_values1) : var_values(var_values1){}
/*
 * The function interprets a string to an expression to a value of the calculatoin of the expression.
 */
float Interpreter::interpret(string expression) {
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
/*
 * The function returns true if c is operator and false otherise.
 */
bool Interpreter::isOperator(char c) {
  if ((c == '+') || (c == '-') || (c == '*') || (c == '/')) {
    return true;
  }
  return false;
}
/*
 * The function inserts a delimiter of ; to the postQueue if needed.
 */
void Interpreter::insertDelimiterIfNeeded(char previous) {
  if (postQueue.empty()) {
    return;
  }
  if ((postQueue.back() != ';') && (isOperator(previous) == false) && (previous != UMINUS) && (previous != UPLUS)) {
    postQueue.push(';');
  }
}
/*
 * The function creates a post order queue out of the string received.
 */
void Interpreter::creatingPostQueue(string expression) {
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
/*
 * The function creates and returns an expression out of the postQueue.
 */
Expression *Interpreter::creatingExpression() {
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
/*
 * The function returns the enum type of oper.
 */
enum operators Interpreter::operatorTyp(char oper) {
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
/*
 * The function add an expression to the expression stack.
 */
void Interpreter::addExpressionToStack(enum operators oper) {
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
/*
 * The function inserts a binary expression to the expression stack.
 */
void Interpreter::insertBinaryExpression(enum operators binaryOperator, Expression *left, Expression *right) {
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
/*
 * The function inserts an unary expression to the expression stack.
 */
void Interpreter::insertUnaryExpression(operators unaryOperator, Expression *expression) {
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
/*
 * The function returns true if oper is unary operator and false otherwise.
 */
bool Interpreter::isUnaryOperator(operators oper) {
  if ((oper == U_MINUS) || (oper == U_PLUS)) {
    return true;
  }
  return false;

}
/*
 * The function returns true if oper is binary operator and false otherwise.
 */
bool Interpreter::isBinary(char current, char prev) {
  if (isOperator(current) == true) {
    if (isUnary(prev) == false) {
      return true;
    }
  }
  return false;
}
/*
 * The function returns true if the previos char is ' '  or ( ',
 * meaning the operator that comes after that is unary and false otherwise.
 */
bool Interpreter::isUnary(char previous) {
  if ((previous == ' ') || (previous == '(')) {
    return true;
  }
  return false;
}
/*
 * The function returns true if current operator has lower or even priority than prev and false otherwise.
 */
bool Interpreter::isCurrentSmaller(operators current, operators prev) {
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
/*
 * The function creates a new var or value according to v received and push it to the expression stack.
 */
void Interpreter::creatingVarOrValue(string v) {
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
/*
 * The function inserts an operator to the operator stack.
 */
void Interpreter::insertOperator(char currentChar, char previous) {
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
/*
 * The function returns true if e is a knowen exception and false otherwise and false otherwise.
 */
bool Interpreter::isCharConstException(exception e) {
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
/*
 * The function returns true if currentChar is a valid char for variable name and false otherwise.
 */
bool Interpreter::isVariableName(char currentChar) {
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
/*
 * The function returns true if st is a number and false otherwise.
 */
bool Interpreter::isANumber(string st) {
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
/*
 * Destructor.
 */
Interpreter::~Interpreter() {}
