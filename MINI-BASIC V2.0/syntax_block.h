#ifndef SYNTAX_BLOCK_H
#define SYNTAX_BLOCK_H

#include "lexical_block.h"
#include "atom.h"

#include <stack>

using namespace std;

class SyntaxAnalyzer : public LexicalAnalyzer
{
protected:
    typedef void(SyntaxAnalyzer::* func)();

    ofstream sa_error_file;
    vector<atom> atoms_table;
    vector<int> TM;      //Таблица меток
    vector<int> TX;      //Таблица для хранения результатов атома хранения
    stack <int> stk;
    func control_table[34][24];
    int in;              //Указатель на индекс входной лексемы
    int num_str;         //Номер текущей строки
    int NTM;             //Указатель на первый свободный элемент таблицы меток
    int NTX;             //Указатель на первый свободный элемент таблицы результатов атома хранения
    int NTtemp;          //Указатель на первый свободный элемент в таблицы промежуточных результатов
    bool error_flag;     //Вид обнаружения ошибки
    bool test_flag;

    void create_atom(int atom_type_, int attribute1_ = -1, int attribute2_ = -1, int attribute3_ = -1, int attribute4_ = -1);

    void sa_error(string error_message_);

    void F1();
    void F2();
    void F3();
    void F4();
    void F5();
    void F6();
    void F7();
    void F8();
    void F9();
    void F10();
    void F11();
    void F12();
    void F13();
    void F14();
    void F15();
    void F16();
    void F17();
    void F18();
    void F19();
    void F20();
    void F21();
    void F22();
    void F23();
    void F24();
    void F25();
    void F26();
    void F27();
    void F28();

    void a();
    void b();
    void c();
    void d();
    void e();
    void f();
    void g();
    void h();
    void i();
    void j();
    void k();
    void l();
    void m();
    void n();
    void o();
    void p();
    void q();
    void r();

    void A();
    void B();
    void C();
    void D();

    void E1();
    void E2();
    void E3();

    void G1();
    void G2();

    void K();
    void K1();
    void K2();
    void K3();
    void K4();
    void K5();
    void K6();
    void K7();

    void L();

    void M1();
    void M2();
    void M3();
    void M4();

    void N1();
    void N2();

    void O();

    void P();
    void P1();
    void P2();
    void P3();
    void P4();

    void T1();
    void T2();
    void T3();

    void initialize_control_table();
public:
    SyntaxAnalyzer();

    void atoms_table_output();

    void stack_output();

    void start(const char* input_file_name_) override;
};

#endif // !SYNTHAX_BLOCK_H