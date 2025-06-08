#include "syntax_block.h"

void SyntaxAnalyzer::create_atom(int atom_type_, int attribute1_, int attribute2_, int attribute3_, int attribute4_)
{
    atom new_atom;

    new_atom.type = atom_type_;
    new_atom.attribute1 = attribute1_;
    new_atom.attribute2 = attribute2_;
    new_atom.attribute3 = attribute3_;
    new_atom.attribute4 = attribute4_;

    atoms_table.push_back(new_atom);
}

void SyntaxAnalyzer::sa_error(string error_message_)
{
    sa_error_file << "Error(" << num_str << "): " << error_message_ << endl;
    error_flag = true;

    if (TL[in].TokenClass == 23) in++;
    else
    {
        while (in < TL.size() && TL[in].TokenClass != 1)
            in++;
    }

    if (stk.top() == 1 || stk.top() == 2 || stk.top() == 4) return;
    else if (stk.top() == 16 || stk.top() == 18)
    {
        stk.pop();
        stk.push(2);
    }
    else
    {
        while (stk.top() != 4)
            stk.pop();
    }
}

void SyntaxAnalyzer::F1()
{
    stk.pop();
    stk.push(16);
    stk.push(2);
    cout << TL[in].TokenClass << ' ' << TL[in].TokenValue << endl;
    create_atom(1, TL[in].TokenValue);

    num_str = TS.get_label(TL[in].TokenValue);
    in++;
}

void SyntaxAnalyzer::F2()
{
    stk.pop();
    int k = stk.top();
}

void SyntaxAnalyzer::F3()
{
    create_atom(1, TL[in].TokenValue);
    num_str = TS.get_label(TL[in].TokenValue);
    in++;
}

void SyntaxAnalyzer::F4()
{
    stk.pop();
    stk.push(4);
    stk.push(0);
    stk.push(TL[in].TokenValue);
    stk.push(19);
    stk.push(3);
    stk.push(5);
    in++;
}

void SyntaxAnalyzer::F5()
{
    stk.pop();
    stk.push(4);
    create_atom(3, TL[in].TokenValue);
    in++;
}

void SyntaxAnalyzer::F6()
{
    stk.pop();
    stk.push(4);
    stk.push(0);
    stk.push(0);
    stk.push(0);
    stk.push(0);
    stk.push(20);
    stk.push(5);
    stk.push(14);
    stk.push(5);
    stk.push(5);
    stk.push(8);
    stk.push(12);
    stk.push(8);
    stk.push(5);
    in++;
}

void SyntaxAnalyzer::F7()
{
    stk.pop();
    stk.push(4);
    create_atom(4, TL[in].TokenValue);
    in++;
}

void SyntaxAnalyzer::F8()
{
    stk.pop();
    stk.push(4);
    create_atom(5);
    in++;
}

void SyntaxAnalyzer::F9()
{
    int input_value, s, t, u, v, y;
    input_value = TL[in].TokenValue;  // Значение входа
    s = NTX;                // Значение поставляемому вызовом процедуры НОВТX
    NTX++;
    t = NTX;                // Значение поставляемому другим вызовом процедуры НОВТХ
    NTX++;
    u = NTM;                // значение поставляемому вызовом процедуры НОВТАМ
    NTM++;
    v = NTM;                //значение поставляемому другим вызовом процедуры НОВТАМ
    NTM++;
    y = num_str;
    stk.pop();
    stk.push(4);
    stk.push(v);
    stk.push(22);
    stk.push(u);
    stk.push(26);
    stk.push(t);
    stk.push(input_value);
    stk.push(25);
    stk.push(y);
    stk.push(0);
    stk.push(input_value);
    stk.push(24);
    stk.push(3);
    stk.push(13);
    stk.push(4);
    stk.push(v);
    stk.push(t);
    stk.push(s);
    stk.push(input_value);
    stk.push(23);
    stk.push(u);
    stk.push(22);
    stk.push(t);
    stk.push(0);
    stk.push(21);
    stk.push(2);
    stk.push(3);
    stk.push(s);
    stk.push(0);
    stk.push(21);
    stk.push(2);
    stk.push(5);
    stk.push(17);
    stk.push(0);
    stk.push(input_value);
    stk.push(19);
    stk.push(3);
    stk.push(5);
    in++;
}

void SyntaxAnalyzer::F10()
{
    stk.pop();
    stk.push(5);
    in++;
}

void SyntaxAnalyzer::F11()
{
    TO[NTO] = 1;
    stk.pop();
    stk.pop();
    int tmp = stk.top();
    stk.pop();
    stk.pop();
    stk.push(TO[NTO]);
    stk.push(tmp);

    NTO++;
}

void SyntaxAnalyzer::F12()
{
    stk.pop();
    stk.push(4);
    in++;
}

void SyntaxAnalyzer::F13()
{
    stk.pop();
    stk.push(2);
    create_atom(1, TL[in].TokenValue);
    num_str = TS.get_label(TL[in].TokenValue);
    in++;
}

void SyntaxAnalyzer::F14()
{
    stk.pop();
    stk.push(0);
    stk.push(9);
    stk.push(2);
    stk.push(6);
}

void SyntaxAnalyzer::F15()
{
    stk.pop();
    stk.push(NTtemp);
    stk.push(9);
    stk.push(NTtemp);
    stk.push(0);
    stk.push(32);
    stk.push(2);
    stk.push(6);
    NTtemp++;
    in++;
}

void SyntaxAnalyzer::F16()
{
    stk.pop();
    stk.push(NTtemp);
    stk.push(9);
    stk.push(NTtemp);
    stk.push(0);
    stk.push(33);
    stk.push(2);
    stk.push(6);
    NTtemp++;
    in++;
}

void SyntaxAnalyzer::F17()
{
    stk.pop();
    int tmp = stk.top();
    stk.pop();
    stk.push(NTtemp);
    stk.push(9);
    stk.push(NTtemp);
    stk.push(0);
    stk.push(tmp);
    stk.push(27);
    stk.push(3);
    stk.push(6);
    NTtemp++;
    in++;
}

void SyntaxAnalyzer::F18()
{
    stk.pop();
    int tmp = stk.top();
    stk.pop();
    stk.push(NTtemp);
    stk.push(9);
    stk.push(NTtemp);
    stk.push(0);
    stk.push(tmp);
    stk.push(28);
    stk.push(3);
    stk.push(6);
    NTtemp++;
    in++;
}

void SyntaxAnalyzer::F19()
{
    stk.pop();
    int tmp1 = stk.top();
    stk.pop();
    int tmp2 = stk.top() - 1;
    stk.pop();
    stack<int> tmp_vector;
    while (tmp2 > 0)
    {
        tmp_vector.push(stk.top());
        stk.pop();
        tmp2--;
    }

    while (stk.top() != 0)
    {
        tmp_vector.push(stk.top());
        stk.pop();
    }
    stk.pop();
    stk.push(tmp1);
    while (!tmp_vector.empty())
    {
        stk.push(tmp_vector.top());
        tmp_vector.pop();
    }
}

void SyntaxAnalyzer::F20()
{
    stk.pop();
    stk.push(0);
    stk.push(10);
    stk.push(2);
    stk.push(7);
}

void SyntaxAnalyzer::F21()
{
    stk.pop();
    int tmp = stk.top();
    stk.pop();
    stk.push(NTtemp);
    stk.push(10);
    stk.push(NTtemp);
    stk.push(0);
    stk.push(tmp);
    stk.push(29);
    stk.push(3);
    stk.push(7);
    NTtemp++;
    in++;
}

void SyntaxAnalyzer::F22()
{
    stk.pop();
    int tmp = stk.top();
    stk.pop();
    stk.push(NTtemp);
    stk.push(10);
    stk.push(NTtemp);
    stk.push(0);
    stk.push(tmp);
    stk.push(30);
    stk.push(3);
    stk.push(7);
    NTtemp++;
    in++;
}

void SyntaxAnalyzer::F23()
{
    stk.pop();
    int tmp1 = stk.top();
    stk.pop();
    int tmp2 = stk.top() - 1;
    stk.pop();
    stack<int> tmp_vector;
    while (tmp2 != 0)
    {
        tmp_vector.push(stk.top());
        stk.pop();
        tmp2--;
    }
    while (stk.top() != 0)
    {
        tmp_vector.push(stk.top());
        stk.pop();
    }
    stk.pop();
    stk.push(tmp1);
    while (!tmp_vector.empty())
    {
        stk.push(tmp_vector.top());
        tmp_vector.pop();
    }
}

void SyntaxAnalyzer::F24()
{
    stk.pop();
    stk.push(0);
    stk.push(11);
    stk.push(2);
    stk.push(8);
}

void SyntaxAnalyzer::F25()
{
    stk.pop();
    int tmp1 = stk.top();
    stk.pop();
    int tmp2 = stk.top();
    stk.push(NTtemp);
    stk.push(11);
    stk.push(NTtemp);
    stk.push(0);
    stk.push(tmp1);
    stk.push(31);
    stk.push(3);
    stk.push(8);
    NTtemp++;
    in++;
}

void SyntaxAnalyzer::F26()
{
    stk.pop();
    int tmp1 = stk.top();
    stk.pop();
    int tmp2 = stk.top() - 1;
    stk.pop();
    stack<int> tmp_vector;
    while (tmp2 > 0)
    {
        tmp_vector.push(stk.top());
        stk.pop();
        tmp2--;
    }

    while (stk.top() != 0)
    {
        tmp_vector.push(stk.top());
        stk.pop();
    }
    stk.pop();
    stk.push(tmp1);
    while (!tmp_vector.empty())
    {
        stk.push(tmp_vector.top());
        tmp_vector.pop();
    }
}

void SyntaxAnalyzer::F27()
{
    stk.pop();
    int tmp = stk.top();
    stk.pop();
    stk.push(15);
    stk.push(tmp);
    stk.push(5);
    in++;
}

void SyntaxAnalyzer::F28()
{
    stk.pop();
    int tmp = stk.top() - 1;
    stk.pop();
    stack<int> tmp_vector;
    while (tmp > 0)
    {
        tmp_vector.push(stk.top());
        stk.pop();
        tmp--;
    }
    while (stk.top() != 0)
    {
        tmp_vector.push(stk.top());
        stk.pop();
    }
    stk.pop();
    stk.push(TL[in].TokenValue);
    while (!tmp_vector.empty())
    {
        stk.push(tmp_vector.top());
        tmp_vector.pop();
    }

    in++;
}

void SyntaxAnalyzer::a()
{
    stk.pop();
    in++;
}

void SyntaxAnalyzer::b()
{
    stk.pop();
    int tmp = stk.top() - 1;
    stk.pop();
    stack<int> tmp_vector;
    while (tmp != 0)
    {
        tmp_vector.push(stk.top());
        stk.pop();
        tmp--;
    }
    stk.pop();
    stk.push(TL[in].TokenValue);
    while (!tmp_vector.empty())
    {
        stk.push(tmp_vector.top());
        tmp_vector.pop();
    }
    in++;
}

void SyntaxAnalyzer::c()
{
    create_atom(0);
    in++;
}

void SyntaxAnalyzer::d()
{
    int tmp1;
    int tmp2;
    stk.pop();
    tmp1 = stk.top();
    stk.pop();
    tmp2 = stk.top();
    stk.pop();
    create_atom(2, tmp1, tmp2);
}

void SyntaxAnalyzer::e()
{
    int p, q, r, s;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    r = stk.top();
    stk.pop();
    s = stk.top();
    stk.pop();
    create_atom(6, p, q, r, s);
}

void SyntaxAnalyzer::f()
{
    int p, q;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    create_atom(7, p, q);
}

void SyntaxAnalyzer::g()
{
    int p;
    stk.pop();
    p = stk.top();
    stk.pop();
    create_atom(8, p);
}

void SyntaxAnalyzer::h()
{
    int p, q, r, s;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    r = stk.top();
    stk.pop();
    s = stk.top();
    stk.pop();
    create_atom(9, p, q, r, s);
}

void SyntaxAnalyzer::i()
{
    int k1, k2;
    stk.pop();
    k1 = stk.top();
    stk.pop();
    k2 = stk.top();
    stk.pop();

    if (k1 != k2) sa_error("The variable in the 'next' statement is different from the variable in the 'for' statement");

    stk.pop();
}

void SyntaxAnalyzer::j()
{
    int p, q;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    create_atom(10, p, q);
}

void SyntaxAnalyzer::k()
{
    int p;
    stk.pop();
    p = stk.top();
    stk.pop();
    create_atom(3, p);
}

void SyntaxAnalyzer::l()
{
    int p, q, r;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    r = stk.top();
    stk.pop();
    create_atom(11, p, q, r);
}

void SyntaxAnalyzer::m()
{
    int p, q, r;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    r = stk.top();
    stk.pop();
    create_atom(12, p, q, r);
}

void SyntaxAnalyzer::n()
{
    int p, q, r;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    r = stk.top();
    stk.pop();
    create_atom(13, p, q, r);
}

void SyntaxAnalyzer::o()
{
    int p, q, r;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    r = stk.top();
    stk.pop();
    create_atom(14, p, q, r);
}

void SyntaxAnalyzer::p()
{
    int p, q, r;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    r = stk.top();
    stk.pop();
    create_atom(15, p, q, r);
}

void SyntaxAnalyzer::q()
{
    int k1, k2;
    stk.pop();
    k1 = stk.top();
    stk.pop();
    k2 = stk.top();
    stk.pop();
    create_atom(16, k1, k2);
}

void SyntaxAnalyzer::r()
{
    int k1, k2;
    stk.pop();
    k1 = stk.top();
    stk.pop();
    k2 = stk.top();
    stk.pop();
    create_atom(17, k1, k2);
}

void SyntaxAnalyzer::A() { sa_error("Error: Program starts wrong."); }

void SyntaxAnalyzer::B() { sa_error("Error: Operator starts wrong."); }

void SyntaxAnalyzer::C() { sa_error(" "); }

void SyntaxAnalyzer::D() { sa_error("Error: Unexpected entry after operator."); }

void SyntaxAnalyzer::E1() { sa_error("Error: Unexpected entry in the if operator."); }

void SyntaxAnalyzer::E2() { sa_error("Error: If operator is invalid."); }

void SyntaxAnalyzer::E3() { sa_error("Error: Extra right bracket in the expression after AND."); }

void SyntaxAnalyzer::G1() { sa_error("Error: Unexpected entry after for-operator."); }

void SyntaxAnalyzer::G2() { sa_error("Error: Missing right bracket in expression after table_operands."); }

void SyntaxAnalyzer::K() { sa_error("Error: for-operators are not valid - unnecessary next."); }

void SyntaxAnalyzer::K1() { sa_error("Error: Expression illegal - no operand."); }

void SyntaxAnalyzer::K2() { sa_error("Error: Operator is invalid."); }

void SyntaxAnalyzer::K3() { sa_error("Error: In the expression, operand is omitted."); }

void SyntaxAnalyzer::K4() { sa_error("Error: Unexpected entry after expression."); }

void SyntaxAnalyzer::K5() { sa_error("Error: The expression starts with an invalid character."); }

void SyntaxAnalyzer::K6() { sa_error("Error: Two characters in the expression."); }

void SyntaxAnalyzer::K7() { sa_error("Error: Operation sign missing in expression."); }

void SyntaxAnalyzer::L() { sa_error("Error: for-operators are spun incorrectly. Skipped next"); }

void SyntaxAnalyzer::M1() { sa_error("Error: Unexpected entry in the if-operator."); }

void SyntaxAnalyzer::M2() { sa_error("Error: If operator is invalid."); }

void SyntaxAnalyzer::M3() { sa_error("Error: Two characters in if-operator."); }

void SyntaxAnalyzer::M4() { sa_error("Error: Missing right bracket in the expression after the relationship sign."); }

void SyntaxAnalyzer::N1() { sa_error("Error: Left right bracket before entry."); }

void SyntaxAnalyzer::N2() { sa_error("Missing opening brace at the end of the line."); }

void SyntaxAnalyzer::O() { sa_error("Compiler error."); }

void SyntaxAnalyzer::P() { sa_error("Error: Program continues after end operator."); }

void SyntaxAnalyzer::P1() { sa_error("Error: Unexpected entry in for-operator."); }

void SyntaxAnalyzer::P2() { sa_error("for-operator was not finised."); }

void SyntaxAnalyzer::P3() { sa_error("Error: Missing right bracket in the expression after to."); }

void SyntaxAnalyzer::P4() { sa_error("Error: To skipped or not at its place in the for-operator."); }

void SyntaxAnalyzer::T1() { sa_error("Error: There is no program."); }

void SyntaxAnalyzer::T2() { sa_error("Error: End operator skipped."); }

void SyntaxAnalyzer::T3() { sa_error("Error: Program ends inside operator."); }

void SyntaxAnalyzer::initialize_control_table()
{
    control_table[1][1] = &SyntaxAnalyzer::F1;
    control_table[1][2] = &SyntaxAnalyzer::A;
    control_table[1][3] = &SyntaxAnalyzer::A;
    control_table[1][4] = &SyntaxAnalyzer::A;
    control_table[1][5] = &SyntaxAnalyzer::A;
    control_table[1][6] = &SyntaxAnalyzer::A;
    control_table[1][7] = &SyntaxAnalyzer::A;
    control_table[1][8] = &SyntaxAnalyzer::A;
    control_table[1][9] = &SyntaxAnalyzer::A;
    control_table[1][10] = &SyntaxAnalyzer::A;
    control_table[1][11] = &SyntaxAnalyzer::A;
    control_table[1][12] = &SyntaxAnalyzer::A;
    control_table[1][13] = &SyntaxAnalyzer::A;
    control_table[1][14] = &SyntaxAnalyzer::A;
    control_table[1][15] = &SyntaxAnalyzer::A;
    control_table[1][16] = &SyntaxAnalyzer::A;
    control_table[1][17] = &SyntaxAnalyzer::A;
    control_table[1][18] = &SyntaxAnalyzer::A;
    control_table[1][19] = &SyntaxAnalyzer::A;
    control_table[1][20] = &SyntaxAnalyzer::A;
    control_table[1][21] = &SyntaxAnalyzer::A;
    control_table[1][22] = &SyntaxAnalyzer::C;
    control_table[1][23] = &SyntaxAnalyzer::T1;

    control_table[2][1] = &SyntaxAnalyzer::F3;
    control_table[2][2] = &SyntaxAnalyzer::B;
    control_table[2][3] = &SyntaxAnalyzer::B;
    control_table[2][4] = &SyntaxAnalyzer::F2;
    control_table[2][5] = &SyntaxAnalyzer::F4;
    control_table[2][6] = &SyntaxAnalyzer::F9;
    control_table[2][7] = &SyntaxAnalyzer::F5;
    control_table[2][8] = &SyntaxAnalyzer::F7;
    control_table[2][9] = &SyntaxAnalyzer::B;
    control_table[2][10] = &SyntaxAnalyzer::B;
    control_table[2][11] = &SyntaxAnalyzer::F6;
    control_table[2][12] = &SyntaxAnalyzer::F8;
    control_table[2][13] = &SyntaxAnalyzer::F2;
    control_table[2][14] = &SyntaxAnalyzer::B;
    control_table[2][15] = &SyntaxAnalyzer::B;
    control_table[2][16] = &SyntaxAnalyzer::F12;
    control_table[2][17] = &SyntaxAnalyzer::B;
    control_table[2][18] = &SyntaxAnalyzer::B;
    control_table[2][19] = &SyntaxAnalyzer::B;
    control_table[2][20] = &SyntaxAnalyzer::B;
    control_table[2][21] = &SyntaxAnalyzer::B;
    control_table[2][22] = &SyntaxAnalyzer::C;
    control_table[2][23] = &SyntaxAnalyzer::T2;

    control_table[3][1] = &SyntaxAnalyzer::F11;
    control_table[3][2] = &SyntaxAnalyzer::G1;
    control_table[3][3] = &SyntaxAnalyzer::G1;
    control_table[3][4] = &SyntaxAnalyzer::G1;
    control_table[3][5] = &SyntaxAnalyzer::G1;
    control_table[3][6] = &SyntaxAnalyzer::G1;
    control_table[3][7] = &SyntaxAnalyzer::G1;
    control_table[3][8] = &SyntaxAnalyzer::G1;
    control_table[3][9] = &SyntaxAnalyzer::G1;
    control_table[3][10] = &SyntaxAnalyzer::G2;
    control_table[3][11] = &SyntaxAnalyzer::G1;
    control_table[3][12] = &SyntaxAnalyzer::G1;
    control_table[3][13] = &SyntaxAnalyzer::G1;
    control_table[3][14] = &SyntaxAnalyzer::G1;
    control_table[3][15] = &SyntaxAnalyzer::F10;
    control_table[3][16] = &SyntaxAnalyzer::G1;
    control_table[3][17] = &SyntaxAnalyzer::G1;
    control_table[3][18] = &SyntaxAnalyzer::G1;
    control_table[3][19] = &SyntaxAnalyzer::G1;
    control_table[3][20] = &SyntaxAnalyzer::G1;
    control_table[3][21] = &SyntaxAnalyzer::G1;
    control_table[3][22] = &SyntaxAnalyzer::C;
    control_table[3][23] = &SyntaxAnalyzer::T2;

    control_table[4][1] = &SyntaxAnalyzer::F13;
    control_table[4][2] = &SyntaxAnalyzer::D;
    control_table[4][3] = &SyntaxAnalyzer::D;
    control_table[4][4] = &SyntaxAnalyzer::D;
    control_table[4][5] = &SyntaxAnalyzer::D;
    control_table[4][6] = &SyntaxAnalyzer::D;
    control_table[4][7] = &SyntaxAnalyzer::D;
    control_table[4][8] = &SyntaxAnalyzer::D;
    control_table[4][9] = &SyntaxAnalyzer::D;
    control_table[4][10] = &SyntaxAnalyzer::D;
    control_table[4][11] = &SyntaxAnalyzer::D;
    control_table[4][12] = &SyntaxAnalyzer::D;
    control_table[4][13] = &SyntaxAnalyzer::D;
    control_table[4][14] = &SyntaxAnalyzer::D;
    control_table[4][15] = &SyntaxAnalyzer::D;
    control_table[4][16] = &SyntaxAnalyzer::D;
    control_table[4][17] = &SyntaxAnalyzer::D;
    control_table[4][18] = &SyntaxAnalyzer::D;
    control_table[4][19] = &SyntaxAnalyzer::D;
    control_table[4][20] = &SyntaxAnalyzer::D;
    control_table[4][21] = &SyntaxAnalyzer::D;
    control_table[4][22] = &SyntaxAnalyzer::C;
    control_table[4][23] = &SyntaxAnalyzer::T2;

    control_table[5][1] = &SyntaxAnalyzer::K2;
    control_table[5][2] = &SyntaxAnalyzer::F14;
    control_table[5][3] = &SyntaxAnalyzer::K1;
    control_table[5][4] = &SyntaxAnalyzer::K4;
    control_table[5][5] = &SyntaxAnalyzer::K4;
    control_table[5][6] = &SyntaxAnalyzer::K4;
    control_table[5][7] = &SyntaxAnalyzer::K1;
    control_table[5][8] = &SyntaxAnalyzer::K4;
    control_table[5][9] = &SyntaxAnalyzer::F14;
    control_table[5][10] = &SyntaxAnalyzer::K3;
    control_table[5][11] = &SyntaxAnalyzer::K4;
    control_table[5][12] = &SyntaxAnalyzer::K4;
    control_table[5][13] = &SyntaxAnalyzer::K4;
    control_table[5][14] = &SyntaxAnalyzer::K1;
    control_table[5][15] = &SyntaxAnalyzer::K1;
    control_table[5][16] = &SyntaxAnalyzer::K4;
    control_table[5][17] = &SyntaxAnalyzer::F15;
    control_table[5][18] = &SyntaxAnalyzer::F16;
    control_table[5][19] = &SyntaxAnalyzer::K5;
    control_table[5][20] = &SyntaxAnalyzer::K5;
    control_table[5][21] = &SyntaxAnalyzer::K5;
    control_table[5][22] = &SyntaxAnalyzer::C;
    control_table[5][23] = &SyntaxAnalyzer::T3;

    control_table[6][1] = &SyntaxAnalyzer::K2;
    control_table[6][2] = &SyntaxAnalyzer::F20;
    control_table[6][3] = &SyntaxAnalyzer::K1;
    control_table[6][4] = &SyntaxAnalyzer::K4;
    control_table[6][5] = &SyntaxAnalyzer::K4;
    control_table[6][6] = &SyntaxAnalyzer::K4;
    control_table[6][7] = &SyntaxAnalyzer::K1;
    control_table[6][8] = &SyntaxAnalyzer::K4;
    control_table[6][9] = &SyntaxAnalyzer::F20;
    control_table[6][10] = &SyntaxAnalyzer::K3;
    control_table[6][11] = &SyntaxAnalyzer::K4;
    control_table[6][12] = &SyntaxAnalyzer::K4;
    control_table[6][13] = &SyntaxAnalyzer::K4;
    control_table[6][14] = &SyntaxAnalyzer::K1;
    control_table[6][15] = &SyntaxAnalyzer::K1;
    control_table[6][16] = &SyntaxAnalyzer::K4;
    control_table[6][17] = &SyntaxAnalyzer::K6;
    control_table[6][18] = &SyntaxAnalyzer::K6;
    control_table[6][19] = &SyntaxAnalyzer::K6;
    control_table[6][20] = &SyntaxAnalyzer::K6;
    control_table[6][21] = &SyntaxAnalyzer::K6;
    control_table[6][22] = &SyntaxAnalyzer::C;
    control_table[6][23] = &SyntaxAnalyzer::T3;

    control_table[7][1] = &SyntaxAnalyzer::K2;
    control_table[7][2] = &SyntaxAnalyzer::F24;
    control_table[7][3] = &SyntaxAnalyzer::K1;
    control_table[7][4] = &SyntaxAnalyzer::K4;
    control_table[7][5] = &SyntaxAnalyzer::K4;
    control_table[7][6] = &SyntaxAnalyzer::K4;
    control_table[7][7] = &SyntaxAnalyzer::K1;
    control_table[7][8] = &SyntaxAnalyzer::K4;
    control_table[7][9] = &SyntaxAnalyzer::F24;
    control_table[7][10] = &SyntaxAnalyzer::K3;
    control_table[7][11] = &SyntaxAnalyzer::K4;
    control_table[7][12] = &SyntaxAnalyzer::K4;
    control_table[7][13] = &SyntaxAnalyzer::K4;
    control_table[7][14] = &SyntaxAnalyzer::K1;
    control_table[7][15] = &SyntaxAnalyzer::K1;
    control_table[7][16] = &SyntaxAnalyzer::K4;
    control_table[7][17] = &SyntaxAnalyzer::K6;
    control_table[7][18] = &SyntaxAnalyzer::K6;
    control_table[7][19] = &SyntaxAnalyzer::K6;
    control_table[7][20] = &SyntaxAnalyzer::K6;
    control_table[7][21] = &SyntaxAnalyzer::K6;
    control_table[7][22] = &SyntaxAnalyzer::C;
    control_table[7][23] = &SyntaxAnalyzer::T3;

    control_table[8][1] = &SyntaxAnalyzer::K2;
    control_table[8][2] = &SyntaxAnalyzer::F28;
    control_table[8][3] = &SyntaxAnalyzer::K1;
    control_table[8][4] = &SyntaxAnalyzer::K4;
    control_table[8][5] = &SyntaxAnalyzer::K4;
    control_table[8][6] = &SyntaxAnalyzer::K4;
    control_table[8][7] = &SyntaxAnalyzer::K1;
    control_table[8][8] = &SyntaxAnalyzer::K4;
    control_table[8][9] = &SyntaxAnalyzer::F27;
    control_table[8][10] = &SyntaxAnalyzer::K3;
    control_table[8][11] = &SyntaxAnalyzer::K4;
    control_table[8][12] = &SyntaxAnalyzer::K4;
    control_table[8][13] = &SyntaxAnalyzer::K4;
    control_table[8][14] = &SyntaxAnalyzer::K1;
    control_table[8][15] = &SyntaxAnalyzer::K1;
    control_table[8][16] = &SyntaxAnalyzer::K4;
    control_table[8][17] = &SyntaxAnalyzer::K6;
    control_table[8][18] = &SyntaxAnalyzer::K6;
    control_table[8][19] = &SyntaxAnalyzer::K6;
    control_table[8][20] = &SyntaxAnalyzer::K6;
    control_table[8][21] = &SyntaxAnalyzer::K6;
    control_table[8][22] = &SyntaxAnalyzer::C;
    control_table[8][23] = &SyntaxAnalyzer::T3;

    control_table[9][1] = &SyntaxAnalyzer::F19;
    control_table[9][2] = &SyntaxAnalyzer::K7;
    control_table[9][3] = &SyntaxAnalyzer::F19;
    control_table[9][4] = &SyntaxAnalyzer::O;
    control_table[9][5] = &SyntaxAnalyzer::O;
    control_table[9][6] = &SyntaxAnalyzer::O;
    control_table[9][7] = &SyntaxAnalyzer::F19;
    control_table[9][8] = &SyntaxAnalyzer::O;
    control_table[9][9] = &SyntaxAnalyzer::K7;
    control_table[9][10] = &SyntaxAnalyzer::F19;
    control_table[9][11] = &SyntaxAnalyzer::O;
    control_table[9][12] = &SyntaxAnalyzer::O;
    control_table[9][13] = &SyntaxAnalyzer::O;
    control_table[9][14] = &SyntaxAnalyzer::F19;
    control_table[9][15] = &SyntaxAnalyzer::F19;
    control_table[9][16] = &SyntaxAnalyzer::O;
    control_table[9][17] = &SyntaxAnalyzer::F17;
    control_table[9][18] = &SyntaxAnalyzer::F18;
    control_table[9][19] = &SyntaxAnalyzer::O;
    control_table[9][20] = &SyntaxAnalyzer::O;
    control_table[9][21] = &SyntaxAnalyzer::O;
    control_table[9][22] = &SyntaxAnalyzer::O;
    control_table[9][23] = &SyntaxAnalyzer::O;

    control_table[10][1] = &SyntaxAnalyzer::F23;
    control_table[10][2] = &SyntaxAnalyzer::K7;
    control_table[10][3] = &SyntaxAnalyzer::F23;
    control_table[10][4] = &SyntaxAnalyzer::O;
    control_table[10][5] = &SyntaxAnalyzer::O;
    control_table[10][6] = &SyntaxAnalyzer::O;
    control_table[10][7] = &SyntaxAnalyzer::F23;
    control_table[10][8] = &SyntaxAnalyzer::O;
    control_table[10][9] = &SyntaxAnalyzer::K7;
    control_table[10][10] = &SyntaxAnalyzer::F23;
    control_table[10][11] = &SyntaxAnalyzer::O;
    control_table[10][12] = &SyntaxAnalyzer::O;
    control_table[10][13] = &SyntaxAnalyzer::O;
    control_table[10][14] = &SyntaxAnalyzer::F23;
    control_table[10][15] = &SyntaxAnalyzer::F23;
    control_table[10][16] = &SyntaxAnalyzer::O;
    control_table[10][17] = &SyntaxAnalyzer::F23;
    control_table[10][18] = &SyntaxAnalyzer::F23;
    control_table[10][19] = &SyntaxAnalyzer::F21;
    control_table[10][20] = &SyntaxAnalyzer::F22;
    control_table[10][21] = &SyntaxAnalyzer::O;
    control_table[10][22] = &SyntaxAnalyzer::O;
    control_table[10][23] = &SyntaxAnalyzer::O;

    control_table[11][1] = &SyntaxAnalyzer::F26;
    control_table[11][2] = &SyntaxAnalyzer::K7;
    control_table[11][3] = &SyntaxAnalyzer::F26;
    control_table[11][4] = &SyntaxAnalyzer::K4;
    control_table[11][5] = &SyntaxAnalyzer::K4;
    control_table[11][6] = &SyntaxAnalyzer::K4;
    control_table[11][7] = &SyntaxAnalyzer::F26;
    control_table[11][8] = &SyntaxAnalyzer::K4;
    control_table[11][9] = &SyntaxAnalyzer::K7;
    control_table[11][10] = &SyntaxAnalyzer::F26;
    control_table[11][11] = &SyntaxAnalyzer::K4;
    control_table[11][12] = &SyntaxAnalyzer::K4;
    control_table[11][13] = &SyntaxAnalyzer::K4;
    control_table[11][14] = &SyntaxAnalyzer::F26;
    control_table[11][15] = &SyntaxAnalyzer::F26;
    control_table[11][16] = &SyntaxAnalyzer::K4;
    control_table[11][17] = &SyntaxAnalyzer::F26;
    control_table[11][18] = &SyntaxAnalyzer::F26;
    control_table[11][19] = &SyntaxAnalyzer::F26;
    control_table[11][20] = &SyntaxAnalyzer::F26;
    control_table[11][21] = &SyntaxAnalyzer::F25;
    control_table[11][22] = &SyntaxAnalyzer::C;
    control_table[11][23] = &SyntaxAnalyzer::T2;

    control_table[12][1] = &SyntaxAnalyzer::E2;
    control_table[12][2] = &SyntaxAnalyzer::E1;
    control_table[12][3] = &SyntaxAnalyzer::b;
    control_table[12][4] = &SyntaxAnalyzer::E1;
    control_table[12][5] = &SyntaxAnalyzer::E1;
    control_table[12][6] = &SyntaxAnalyzer::E1;
    control_table[12][7] = &SyntaxAnalyzer::E1;
    control_table[12][8] = &SyntaxAnalyzer::E1;
    control_table[12][9] = &SyntaxAnalyzer::E1;
    control_table[12][10] = &SyntaxAnalyzer::E3;
    control_table[12][11] = &SyntaxAnalyzer::E1;
    control_table[12][12] = &SyntaxAnalyzer::E1;
    control_table[12][13] = &SyntaxAnalyzer::E1;
    control_table[12][14] = &SyntaxAnalyzer::E1;
    control_table[12][15] = &SyntaxAnalyzer::E1;
    control_table[12][16] = &SyntaxAnalyzer::E1;
    control_table[12][17] = &SyntaxAnalyzer::E1;
    control_table[12][18] = &SyntaxAnalyzer::E1;
    control_table[12][19] = &SyntaxAnalyzer::E1;
    control_table[12][20] = &SyntaxAnalyzer::E1;
    control_table[12][21] = &SyntaxAnalyzer::E1;
    control_table[12][22] = &SyntaxAnalyzer::C;
    control_table[12][23] = &SyntaxAnalyzer::T3;

    control_table[13][1] = &SyntaxAnalyzer::O;
    control_table[13][2] = &SyntaxAnalyzer::O;
    control_table[13][3] = &SyntaxAnalyzer::O;
    control_table[13][4] = &SyntaxAnalyzer::b;
    control_table[13][5] = &SyntaxAnalyzer::O;
    control_table[13][6] = &SyntaxAnalyzer::O;
    control_table[13][7] = &SyntaxAnalyzer::O;
    control_table[13][8] = &SyntaxAnalyzer::O;
    control_table[13][9] = &SyntaxAnalyzer::O;
    control_table[13][10] = &SyntaxAnalyzer::O;
    control_table[13][11] = &SyntaxAnalyzer::O;
    control_table[13][12] = &SyntaxAnalyzer::O;
    control_table[13][13] = &SyntaxAnalyzer::L;
    control_table[13][14] = &SyntaxAnalyzer::O;
    control_table[13][15] = &SyntaxAnalyzer::O;
    control_table[13][16] = &SyntaxAnalyzer::O;
    control_table[13][17] = &SyntaxAnalyzer::O;
    control_table[13][18] = &SyntaxAnalyzer::O;
    control_table[13][19] = &SyntaxAnalyzer::O;
    control_table[13][20] = &SyntaxAnalyzer::O;
    control_table[13][21] = &SyntaxAnalyzer::O;
    control_table[13][22] = &SyntaxAnalyzer::O;
    control_table[13][23] = &SyntaxAnalyzer::O;

    control_table[14][1] = &SyntaxAnalyzer::M2;
    control_table[14][2] = &SyntaxAnalyzer::M1;
    control_table[14][3] = &SyntaxAnalyzer::M3;
    control_table[14][4] = &SyntaxAnalyzer::M1;
    control_table[14][5] = &SyntaxAnalyzer::M1;
    control_table[14][6] = &SyntaxAnalyzer::M1;
    control_table[14][7] = &SyntaxAnalyzer::b;
    control_table[14][8] = &SyntaxAnalyzer::M1;
    control_table[14][9] = &SyntaxAnalyzer::M1;
    control_table[14][10] = &SyntaxAnalyzer::M4;
    control_table[14][11] = &SyntaxAnalyzer::M1;
    control_table[14][12] = &SyntaxAnalyzer::M1;
    control_table[14][13] = &SyntaxAnalyzer::M1;
    control_table[14][14] = &SyntaxAnalyzer::M1;
    control_table[14][15] = &SyntaxAnalyzer::M1;
    control_table[14][16] = &SyntaxAnalyzer::M1;
    control_table[14][17] = &SyntaxAnalyzer::M1;
    control_table[14][18] = &SyntaxAnalyzer::M1;
    control_table[14][19] = &SyntaxAnalyzer::M1;
    control_table[14][20] = &SyntaxAnalyzer::M1;
    control_table[14][21] = &SyntaxAnalyzer::M1;
    control_table[14][22] = &SyntaxAnalyzer::C;
    control_table[14][23] = &SyntaxAnalyzer::T3;

    control_table[15][1] = &SyntaxAnalyzer::N2;
    control_table[15][2] = &SyntaxAnalyzer::N1;
    control_table[15][3] = &SyntaxAnalyzer::N1;
    control_table[15][4] = &SyntaxAnalyzer::N1;
    control_table[15][5] = &SyntaxAnalyzer::N1;
    control_table[15][6] = &SyntaxAnalyzer::N1;
    control_table[15][7] = &SyntaxAnalyzer::N1;
    control_table[15][8] = &SyntaxAnalyzer::N1;
    control_table[15][9] = &SyntaxAnalyzer::N1;
    control_table[15][10] = &SyntaxAnalyzer::a;
    control_table[15][11] = &SyntaxAnalyzer::N1;
    control_table[15][12] = &SyntaxAnalyzer::N1;
    control_table[15][13] = &SyntaxAnalyzer::N1;
    control_table[15][14] = &SyntaxAnalyzer::N1;
    control_table[15][15] = &SyntaxAnalyzer::N1;
    control_table[15][16] = &SyntaxAnalyzer::N1;
    control_table[15][17] = &SyntaxAnalyzer::N1;
    control_table[15][18] = &SyntaxAnalyzer::N1;
    control_table[15][19] = &SyntaxAnalyzer::N1;
    control_table[15][20] = &SyntaxAnalyzer::N1;
    control_table[15][21] = &SyntaxAnalyzer::N1;
    control_table[15][22] = &SyntaxAnalyzer::C;
    control_table[15][23] = &SyntaxAnalyzer::T3;

    control_table[16][1] = &SyntaxAnalyzer::O;
    control_table[16][2] = &SyntaxAnalyzer::O;
    control_table[16][3] = &SyntaxAnalyzer::O;
    control_table[16][4] = &SyntaxAnalyzer::K;
    control_table[16][5] = &SyntaxAnalyzer::O;
    control_table[16][6] = &SyntaxAnalyzer::O;
    control_table[16][7] = &SyntaxAnalyzer::O;
    control_table[16][8] = &SyntaxAnalyzer::O;
    control_table[16][9] = &SyntaxAnalyzer::O;
    control_table[16][10] = &SyntaxAnalyzer::O;
    control_table[16][11] = &SyntaxAnalyzer::O;
    control_table[16][12] = &SyntaxAnalyzer::O;
    control_table[16][13] = &SyntaxAnalyzer::a;
    control_table[16][14] = &SyntaxAnalyzer::O;
    control_table[16][15] = &SyntaxAnalyzer::O;
    control_table[16][16] = &SyntaxAnalyzer::O;
    control_table[16][17] = &SyntaxAnalyzer::O;
    control_table[16][18] = &SyntaxAnalyzer::O;
    control_table[16][19] = &SyntaxAnalyzer::O;
    control_table[16][20] = &SyntaxAnalyzer::O;
    control_table[16][21] = &SyntaxAnalyzer::O;
    control_table[16][22] = &SyntaxAnalyzer::O;
    control_table[16][23] = &SyntaxAnalyzer::O;

    control_table[17][1] = &SyntaxAnalyzer::P2;
    control_table[17][2] = &SyntaxAnalyzer::P1;
    control_table[17][3] = &SyntaxAnalyzer::P1;
    control_table[17][4] = &SyntaxAnalyzer::P1;
    control_table[17][5] = &SyntaxAnalyzer::P1;
    control_table[17][6] = &SyntaxAnalyzer::P1;
    control_table[17][7] = &SyntaxAnalyzer::P1;
    control_table[17][8] = &SyntaxAnalyzer::P1;
    control_table[17][9] = &SyntaxAnalyzer::P1;
    control_table[17][10] = &SyntaxAnalyzer::P3;
    control_table[17][11] = &SyntaxAnalyzer::P1;
    control_table[17][12] = &SyntaxAnalyzer::P1;
    control_table[17][13] = &SyntaxAnalyzer::P1;
    control_table[17][14] = &SyntaxAnalyzer::a;
    control_table[17][15] = &SyntaxAnalyzer::P4;
    control_table[17][16] = &SyntaxAnalyzer::P1;
    control_table[17][17] = &SyntaxAnalyzer::P1;
    control_table[17][18] = &SyntaxAnalyzer::P1;
    control_table[17][19] = &SyntaxAnalyzer::P1;
    control_table[17][20] = &SyntaxAnalyzer::P1;
    control_table[17][21] = &SyntaxAnalyzer::P1;
    control_table[17][22] = &SyntaxAnalyzer::C;
    control_table[17][23] = &SyntaxAnalyzer::T3;

    control_table[18][1] = &SyntaxAnalyzer::P;
    control_table[18][2] = &SyntaxAnalyzer::P;
    control_table[18][3] = &SyntaxAnalyzer::P;
    control_table[18][4] = &SyntaxAnalyzer::P;
    control_table[18][5] = &SyntaxAnalyzer::P;
    control_table[18][6] = &SyntaxAnalyzer::P;
    control_table[18][7] = &SyntaxAnalyzer::P;
    control_table[18][8] = &SyntaxAnalyzer::P;
    control_table[18][9] = &SyntaxAnalyzer::P;
    control_table[18][10] = &SyntaxAnalyzer::P;
    control_table[18][11] = &SyntaxAnalyzer::P;
    control_table[18][12] = &SyntaxAnalyzer::P;
    control_table[18][13] = &SyntaxAnalyzer::P;
    control_table[18][14] = &SyntaxAnalyzer::P;
    control_table[18][15] = &SyntaxAnalyzer::P;
    control_table[18][16] = &SyntaxAnalyzer::P;
    control_table[18][17] = &SyntaxAnalyzer::P;
    control_table[18][18] = &SyntaxAnalyzer::P;
    control_table[18][19] = &SyntaxAnalyzer::P;
    control_table[18][20] = &SyntaxAnalyzer::P;
    control_table[18][21] = &SyntaxAnalyzer::P;
    control_table[18][22] = &SyntaxAnalyzer::C;
    control_table[18][23] = &SyntaxAnalyzer::c;

    for (int i = 1; i < 24; i++)
        control_table[19][i] = &SyntaxAnalyzer::d;

    for (int i = 1; i < 24; i++)
        control_table[20][i] = &SyntaxAnalyzer::e;

    for (int i = 1; i < 24; i++)
        control_table[21][i] = &SyntaxAnalyzer::f;

    for (int i = 1; i < 24; i++)
        control_table[22][i] = &SyntaxAnalyzer::g;

    for (int i = 1; i < 24; i++)
        control_table[23][i] = &SyntaxAnalyzer::h;

    for (int i = 1; i < 24; i++)
        control_table[24][i] = &SyntaxAnalyzer::i;

    for (int i = 1; i < 24; i++)
        control_table[25][i] = &SyntaxAnalyzer::j;

    for (int i = 1; i < 24; i++)
        control_table[26][i] = &SyntaxAnalyzer::k;

    for (int i = 1; i < 24; i++)
        control_table[27][i] = &SyntaxAnalyzer::l;

    for (int i = 1; i < 24; i++)
        control_table[28][i] = &SyntaxAnalyzer::m;

    for (int i = 1; i < 24; i++)
        control_table[29][i] = &SyntaxAnalyzer::n;

    for (int i = 1; i < 24; i++)
        control_table[30][i] = &SyntaxAnalyzer::o;

    for (int i = 1; i < 24; i++)
        control_table[31][i] = &SyntaxAnalyzer::p;

    for (int i = 1; i < 24; i++)
        control_table[32][i] = &SyntaxAnalyzer::q;

    for (int i = 1; i < 24; i++)
        control_table[33][i] = &SyntaxAnalyzer::r;
}

void SyntaxAnalyzer::atoms_table_output()
{
    ofstream output_file("atoms.txt");
    if (!output_file) throw "Error: Unable to open file for writing atoms table.";

    cout << "Atoms Table:" << endl << endl << string(25, '-') << endl;
    output_file << "Atoms Table:" << endl << endl << string(25, '-') << endl;

    int sz = atoms_table.size();
    for (int i = 0; i < atoms_table.size(); i++)
    {
        cout << AtomTypeString[atoms_table[i].type];
        output_file << AtomTypeString[atoms_table[i].type];

        if (atoms_table[i].attribute1 != -1)
        {
            cout << " " << atoms_table[i].attribute1;
            output_file << " " << atoms_table[i].attribute1;
        }
        if (atoms_table[i].attribute2 != -1)
        {
            cout << " " << atoms_table[i].attribute2;
            output_file << " " << atoms_table[i].attribute2;
        }
        if (atoms_table[i].attribute3 != -1)
        {
            cout << " " << atoms_table[i].attribute3;
            output_file << " " << atoms_table[i].attribute3;
        }
        if (atoms_table[i].attribute4 != -1)
        {
            cout << " " << atoms_table[i].attribute4;
            output_file << " " << atoms_table[i].attribute4;
        }

        cout << endl << string(25, '-') << endl;
        output_file << endl << string(25, '-') << endl;
    }
}

void SyntaxAnalyzer::stack_output()
{
    cout << "Stack" << endl;

    stack<int> temp;

    for (int i = 0; i < stk.size();)
    {
        cout << stk.top() << " " << endl;
        temp.push(stk.top());
        stk.pop();
    }
    for (int i = 0; i < temp.size();)
    {
        stk.push(temp.top());
        temp.pop();
    }

    cout << endl;
}

SyntaxAnalyzer::SyntaxAnalyzer() :sa_error_file("sa_errors.txt"),
in(1),
NTX(1),
NTM(1),
error_flag(0)
{
    initialize_control_table();

    stk.push(18);
    stk.push(1);

    test_flag = false;
}

void SyntaxAnalyzer::start(const char* input_file_name_)
{
    LexicalAnalyzer::start(input_file_name_);

    if (RSE)
    {
        sa_error("Error during lexical analisis.\n");
        return;
    }

    NTtemp = NTO;
    NTX = 700;
    NTM = 256;

    for (int i = 1; i < TL.size(); i++)
    {
        /*switch (TL[i].TokenClass)
        {
        case 17:
            TL[i].TokenClass = 22;
            break;
        case 18:
            TL[i].TokenClass = 23;
            break;
        case 19:
            TL[i].TokenClass = 16 + TL[i].TokenValue;
            break;
        }*/

        switch (TL[i].TokenClass)
        {
        case 1:
            TL[i].TokenClass = 1;
            break;
        case 2:
            TL[i].TokenClass = 2;
            break;
        case 3:
            TL[i].TokenClass = 16 + TL[i].TokenValue;
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            --TL[i].TokenClass;
            break;
        case 18:
            TL[i].TokenClass = 22;
            break;
        case 19:
            TL[i].TokenClass = 23;
            break;
        }
    }

    int temp_par = -1;
    int sz = 0;
    for (int i = 1; i < TL.size(); i++)
    {
        if (TL[i].TokenClass == 0)
        {
            sz = i;
            break;
        }
    }
    while (in < sz)
    {
        temp_par = stk.top();
        if (test_flag)
        {
            cout << temp_par << " " << TL[in].TokenClass << endl;
            stack_output();
            atoms_table_output();
            cout << endl;
        }
        (this->*control_table[temp_par][TL[in].TokenClass])();
    }

    if (error_flag) cout << "Errors are present." << endl;

    stack_output();
    atoms_table_output();
    cout << endl;

    sa_error_file.close();
}
