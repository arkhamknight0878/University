#ifndef LEXICAL_BLOCK_H
#define LEXICAL_BLOCK_H

#include "const_analyzer.h"
#include "string_table.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <vector>
#include <iomanip>

using namespace std;

// STC stands for "Symbolic Token"
enum SYMBOLIC_TOKEN_CLASSES
{
    STC_LETTER,
    STC_DIGIT,
    STC_RELATION_OPERATION,
    STC_ARITHMETICAL_OPERATION,
    STC_LBRACE,
    STC_RBRACE,
    STC_DOT,
    STC_SPACE,
    STC_CR,
    STC_END,
    STC_OTHER
};

// TC stands for "Token Class"
enum TOKEN_CLASSES
{
    TC_ROWLABEL = 1,
    TC_OPERAND,
    TC_ARITHMETICAL_OPERATION,
    TC_RELATION_OPERATION,
    TC_NEXT,
    TC_LET,
    TC_FOR,
    TC_GOTO,
    TC_GOSUB,
    TC_LBRACE,
    TC_RBRACE,
    TC_IF,
    TC_RETURN,
    TC_END,
    TC_TO,
    TC_STEP,
    TC_REM,
    TC_ERROR,
    TC_ENDFILE,
};

struct token
{
    int TokenClass;
    int TokenValue;
};

class LexicalAnalyzer
{
protected:
    typedef void(LexicalAnalyzer::* fptr)(); // State function pointer


    fstream la_errors_file;
    vector <token> TL; // Tokens table
    vector<string> errors_vector;
    string current_str;
    string last_error_message;      // Last error message
    vector <int> initial_vector;    // Initial vector for detection table
    fptr state_function_pointer;
    int current_line;               // Current line number
    int RCH;                        // Digit register
    int RZ;                         // Sign register
    int RP;                         // Order register
    int RS;                         // Counter register
    int RKL;                        // Token class register
    int ROT;                        // Relation value register
    int RZN;                        // Current char value register
    int RSOS;                       // Current state register
    int ROB;                        // Detection register
    int RK;                         // Symbolic token class register
    int RSTR;                       // Line register
    int RI;                         // Register of char index in variable name
    int RSE;                        // Number of errors register

    string_table TS;

    double TO[1024];    // Operands table
    int NTO;            // Index of first availible element in operands table
    int NTS;            // Index of first availible element in string table
    int NTL;            // Index of first availible element in tokens table

    struct detection_table_node
    {
        int letter;
        int alternative;
        void(LexicalAnalyzer::* pfunc)();
    };
    vector<detection_table_node> table_alternatives; // Detection table

    void A1();
    void A2();
    void A3();

    void B1();

    void C1();
    void C2();

    void D1();
    void D2();
    void D3();
    void D4();
    void D5();
    void D6();

    void E1();
    void E2();

    void F1();
    void F2();
    void F3();

    void G1();

    void H1();

    void transliterator(const char char_to_transliterate_);

    void parse();

    void end();

    void create_token();

    void errors_output();

    void tokens_output();

    void operands_output();

    void string_table_output();
public:
    LexicalAnalyzer();

    void initial_vector_initialization();

    void detection_table_initialization();

    virtual void start(const char* file_name_);

    void next();

    void A1a();
    void A1b();
    void A1c();
    void A1d();
    void A1e();
    void A1f();

    void A2a();
    void A2b();
    void A2c();
    void A2h();
    void A2l();
    void A2g();
    void A2p();
    void A2r();
    void A2k();
    void A2s();
    void A2q();
    void A2o();
    void A2u();
    void A2j();
    void A2f();
    void A2t();

    void A3a();
    void A3b();
    void A3c();
    void A3d();
    void A3g();

    void B1a();
    void B1b();
    void B1c();
    void B1e();

    void C1a();
    void C2a();
    void C2b();
    void C2d();

    void D1a();
    void D1b();
    void D1c();

    void D2a();
    void D2b();
    void D2c();

    void D3a();

    void D4a();

    void D5a();
    void D5b();
    void D5c();

    void D6a();
    void D6b();

    void E1a();
    void E1b();

    void E2a();
    void E2b();
    void E2c();

    void F1a();
    void F1b();

    void F2a();

    void F3a();

    void G1a();
    void G1b();

    void H1a();
    void H1b();
    void H1c();
    void H1f();

    void M1();
    void M2();
    void M3();

    void exit1();
    void exit2();
    void exit3();
    void exit4();
    void exit5();

    void la_error();
};

#endif // !LEXICAL_BLOCK_H