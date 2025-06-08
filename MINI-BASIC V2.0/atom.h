#ifndef ATOM_H
#define ATOM_H

#include <vector>
#include <string>

using namespace std;

// AT stands for "Atom Type"
enum ATOM_TYPE
{
    AT_START = -1,
    AT_END,
    AT_NUMBER_LINE,
    AT_ASSIGNMENT,
    AT_TRANSITION,
    AT_STORAGE_TRANSITION,
    AT_RETURN_TRANSITION,
    AT_CONDITIONAL_TRANSITION,
    AT_STORAGE,
    AT_LABLE,
    AT_CHECK,
    AT_INCREASE,
    AT_ADDITION,
    AT_SUBSTRACTION,
    AT_MULTIPLICATION,
    AT_DIVISION,
    AT_POWER,
    AT_PLUS,
    AT_MINUS
};

const vector<string> AtomTypeString
{
    "END",
    "NUMBER_LINE",
    "ASSIGNMENT",
    "TRANSITION",
    "STORAGE_TRANSITION",
    "RETURN_TRANSITION",
    "CONDITIONAL_TRANSITION",
    "STORAGE",
    "LABLE",
    "CHECK",
    "INCREASE",
    "ADDITION",
    "SUBSTRACTION",
    "MULTIPLICATION",
    "DIVISION",
    "POWER",
    "PLUS",
    "MINUS"
};

struct atom
{
    int type = AT_START;
    int attribute1 = -1;
    int attribute2 = -1;
    int attribute3 = -1;
    int attribute4 = -1;
};

const vector<string> TableType1
{
   "<Programm>", 
   "<Programm's body>",
   "<Step>",
   "<Other rows>",
   "<Expression>",
   "<Term>",
   "<Multiplier>",
   "<E-list>",
   "<T-list>",
   "<F-list>",
   "Relation",
   "End cycle",
   "Transition",
   "Right bracket",
   "End",
   "To",
   "@",
   "{Assign}",
   "{Conditional transition}",
   "{Store}",
   "{Label}",
   "{Check}", 
   "{Control}",
   "{Increase}",
   "{Transition}",
   "{Addition}",
   "{Substract}",
   "{Multiplication}",
   "{Division}",
   "{Power}",
   "{Plus}",
   "{Minus}"
};

const vector<string> TableType2
{
   "LABEL",
   "Operand",
   "Relation",
   "NEXT",
   "LET",
   "FOR",
   "GOTO",
   "GOSUB",
   "Left bracket",
   "Right bracket",
   "IF",
   "RETURN",
   "END",
   "TO",
   "STEP",
   "COMMENT",
   "+",
   "-",
   "*",
   "/",
   "^",
   "ERROR",
   "END_MARK"
};

#endif // !ATOM_H