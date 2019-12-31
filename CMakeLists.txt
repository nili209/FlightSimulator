cmake_minimum_required(VERSION 3.15)
project(ex3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(ex3 main.cpp Singleton.cpp SleepCommand.cpp PrintCommand.cpp VarCommand.cpp
        OpenServerCommand.cpp LoopCommand.cpp IfCommand.cpp DefineVarCommand.cpp ConnectCommand.cpp
        ConditionParser.cpp FlightSimulator.cpp UnaryOperator.h UPlus.h UMinus.h BinaryOperator.h Plus.h Minus.h
        Mul.h Div.h Value.h Variable.h Interpreter.h Variable.cpp Value.cpp UPlus.cpp UnaryOperator.cpp UMinus.cpp ShuntingYard.cpp Plus.cpp Mul.cpp Minus.cpp Interpreter.cpp Div.cpp BinaryOperator.cpp)