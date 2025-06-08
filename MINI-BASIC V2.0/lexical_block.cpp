#include "lexical_block.h"

void LexicalAnalyzer::A1()
{
    switch (RK)
    {
    case STC_DIGIT:
        E2a();
        break;
    case STC_SPACE:
        break;
    case STC_CR:
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Initial label was not found.\0";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::A2()
{
    switch (RK)
    {
    case STC_LETTER:
        C2a();
        break;
    case STC_DIGIT:
        D1a();
        break;
    case STC_ARITHMETICAL_OPERATION:
        A2a();
        break;
    case STC_RELATION_OPERATION:
        H1a();
        break;
    case STC_LBRACE:
        A2h();
        break;
    case STC_RBRACE:
        A3b();
        break;
    case STC_DOT:
        D6b();
        break;
    case STC_SPACE:
        break;
    case STC_CR:
        state_function_pointer = &LexicalAnalyzer::A1;
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Incorrect Assignment.\0";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::A3()
{
    switch (RK)
    {
    case STC_LETTER:
        B1a();
        break;
    case STC_DIGIT:
        D1a();
        break;
    case STC_ARITHMETICAL_OPERATION:
        A2a();
        break;
    case STC_RELATION_OPERATION:
        H1a();
        break;
    case STC_LBRACE:
        A2h();
        break;
    case STC_RBRACE:
        A3b();
        break;
    case STC_DOT:
        D6b();
        break;
    case STC_SPACE:
        break;
    case STC_CR:
        state_function_pointer = &LexicalAnalyzer::A1;
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Incorrect symbol or symbols.\0";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::B1()
{
    switch (RK)
    {
    case STC_LETTER:
        M1();
        break;
    case STC_SPACE:
        break;
    case STC_CR:
        A1f();
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Incorrect symbol or symbols.\0";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::C1()
{
    switch (RK)
    {
    case STC_LETTER:
        C2d();
        break;
    case STC_SPACE:
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Incorrect label after key word.\0";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::C2()
{
    switch (RK)
    {
    case STC_LETTER:
        B1b();
        break;
    case STC_DIGIT:
        A3a();
        break;
    case STC_ARITHMETICAL_OPERATION:
        A2g();
        break;
    case STC_RELATION_OPERATION:
        H1b();
        break;
    case STC_LBRACE:
        A2k();
        break;
    case STC_RBRACE:
        A3c();
        break;
    case STC_SPACE:
        break;
    case STC_CR:
        A1a();
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Incorrect symbol or symbols.\0";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::D1()
{
    switch (RK)
    {
    case STC_LETTER:
        M2();
        break;
    case STC_DIGIT:
        D1b();
        break;
    case STC_ARITHMETICAL_OPERATION:
        A2c();
        break;
    case STC_RELATION_OPERATION:
        H1c();
        break;
    case STC_LBRACE:
        A2l();
        break;
    case STC_RBRACE:
        A3d();
        break;
    case STC_DOT:
        D2c();
        break;
    case STC_SPACE:
        break;
    case STC_CR:
        A1b();
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Incorrect symbol or symbols.\0";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::D2()
{
    switch (RK)
    {
    case STC_LETTER:
        M3();
        break;
    case STC_DIGIT:
        D2a();
        break;
    case STC_ARITHMETICAL_OPERATION:
        A2c();
    case STC_RELATION_OPERATION:
        H1c();
    case STC_LBRACE:
        A2l();
    case STC_RBRACE:
        A3d();
        break;
    case STC_SPACE:
        break;
    case STC_CR:
        A1c();
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Incorrect symbol or symbols.\0";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::D3()
{
    switch (RK)
    {
    case STC_DIGIT:
        D5a();
        break;
    case STC_ARITHMETICAL_OPERATION:
        D4a();
        break;
    case STC_SPACE:
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Incorrect symbol or symbols.\0";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::D4()
{
    switch (RK)
    {
    case STC_DIGIT:
        D5b();
        break;
    case STC_SPACE:
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Incorrect symbol or symbols.\0";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::D5()
{
    switch (RK)
    {
    case STC_LETTER:
        B1c();
        break;
    case STC_DIGIT:
        D5c();
        break;
    case STC_RELATION_OPERATION:
        H1c();
        break;
    case STC_LBRACE:
        A2l();
        break;
    case STC_RBRACE:
        A3d();
        break;
    case STC_SPACE:
        break;
    case STC_CR:
        A1d();
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Incorrect symbol or symbols.\0";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::D6()
{
    switch (RK)
    {
    case STC_DIGIT:
        D2b();
        break;
    case STC_SPACE:
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Incorrect symbol or symbols.\0";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::E1()
{
    switch (RK)
    {
    case STC_DIGIT:
        E2b();
        break;
    case STC_SPACE:
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Incorrect symbol or symbols.\0";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::E2()
{
    switch (RK)
    {
    case STC_LETTER:
        B1e();
        break;
    case STC_DIGIT:
        E2c();
        break;
    case STC_RELATION_OPERATION:
        H1f();
        break;
    case STC_SPACE:
        break;
    case STC_ARITHMETICAL_OPERATION:
        A2f();
        break;
    case STC_LBRACE:
        A2j();
        break;
    case STC_RBRACE:
        A3g();
    case STC_CR:
        A1e();
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Incorrect symbol or symbols.\0";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::F1()
{
    switch (RK)
    {
    case STC_LETTER:
        F2a();
        break;
    case STC_SPACE:
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Incorrect symbol or symbols.\0";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::F2()
{
    switch (RK)
    {
    case STC_DIGIT:
        F3a();
        break;
    case STC_RELATION_OPERATION:
        A2o();
        break;
    case STC_SPACE:
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Incorrect assignment of variable: variable name can not contain more than one letter.\0";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::F3()
{
    switch (RK)
    {
    case STC_RELATION_OPERATION:
        A2o();
        break;
    case STC_SPACE:
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Incorrect assignment of variable: variable name can not contain more than one digit.\0";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::G1()
{
    switch (RK)
    {
    case STC_CR:
        state_function_pointer = &LexicalAnalyzer::A1;
        break;
    default:
        state_function_pointer = &LexicalAnalyzer::G1;
    }
}

void LexicalAnalyzer::H1()
{
    switch (RK)
    {
    case STC_LETTER:
        C2b();
        break;
    case STC_DIGIT:
        D1c();
        break;
    case STC_ARITHMETICAL_OPERATION:
        A2g();
        break;
    case STC_RELATION_OPERATION:
        A2p();
        break;
    case STC_LBRACE:
        A2k();
        break;
    case STC_RBRACE:
        A3c();
        break;
    case STC_DOT:
        D6a();
        break;
    case STC_SPACE:
        break;
    case STC_CR:
        A1a();
        break;
    default:
        last_error_message = "Error(" + to_string(current_line) + "):  Incorrect symbol or symbols.\0 ";
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::transliterator(const char char_to_transliterate_)
{
    if (char_to_transliterate_ >= 'a' && char_to_transliterate_ <= 'z')
    {
        RK = STC_LETTER;
        RZN = char_to_transliterate_ - 'a' + 1;
    }
    else if (char_to_transliterate_ >= 'A' && char_to_transliterate_ <= 'Z')
    {
        RK = STC_LETTER;
        RZN = char_to_transliterate_ - 'A';
    }
    else if (char_to_transliterate_ >= '0' && char_to_transliterate_ <= '9')
    {
        RK = STC_DIGIT;
        RZN = char_to_transliterate_ - '0';
    }
    else if (char_to_transliterate_ == '+')
    {
        RK = STC_ARITHMETICAL_OPERATION;
        RZN = 1;
    }
    else if (char_to_transliterate_ == '-')
    {
        RK = STC_ARITHMETICAL_OPERATION;
        RZN = 2;
    }
    else if (char_to_transliterate_ == '*')
    {
        RK = STC_ARITHMETICAL_OPERATION;
        RZN = 3;
    }
    else if (char_to_transliterate_ == '/')
    {
        RK = STC_ARITHMETICAL_OPERATION;
        RZN = 4;
    }
    else if (char_to_transliterate_ == '^')
    {
        RK = STC_ARITHMETICAL_OPERATION;
        RZN = 5;
    }
    else if (char_to_transliterate_ == ' ' || char_to_transliterate_ == '\t')
    {
        RK = STC_SPACE;
    }
    else if (char_to_transliterate_ == '.')
    {
        RK = STC_DOT;
    }
    else if (char_to_transliterate_ == '\n')
    {
        RK = STC_CR;
    }
    else if (char_to_transliterate_ == '(')
    {
        RK = STC_LBRACE;
    }
    else if (char_to_transliterate_ == ')')
    {
        RK = STC_RBRACE;
    }
    else if (char_to_transliterate_ == '=')
    {
        RK = STC_RELATION_OPERATION;
        RZN = 1;
    }
    else if (char_to_transliterate_ == '<')
    {
        RK = STC_RELATION_OPERATION;
        RZN = 2;
    }
    else if (char_to_transliterate_ == '>')
    {
        RK = STC_RELATION_OPERATION;
        RZN = 3;
    }
    else {
        RK = STC_OTHER;
    }
}

void LexicalAnalyzer::parse()
{
    for (int i = 0; i < current_str.size(); ++i)
    {
        transliterator(current_str[i]);
        (this->*state_function_pointer)();
    }
}

void LexicalAnalyzer::end()
{
    if (state_function_pointer == &LexicalAnalyzer::A1 || state_function_pointer == &LexicalAnalyzer::A2 ||
        state_function_pointer == &LexicalAnalyzer::A3 || state_function_pointer == &LexicalAnalyzer::G1)
    {
        state_function_pointer = &LexicalAnalyzer::exit1;
    }
    else if (state_function_pointer == &LexicalAnalyzer::C1 || state_function_pointer == &LexicalAnalyzer::D1)
    {
        state_function_pointer = &LexicalAnalyzer::exit3;
    }
    else if (state_function_pointer == &LexicalAnalyzer::C2 || state_function_pointer == &LexicalAnalyzer::D2)
    {
        state_function_pointer = &LexicalAnalyzer::exit4;
    }
    else if (state_function_pointer == &LexicalAnalyzer::H1)
    {
        state_function_pointer = &LexicalAnalyzer::exit2;
    }
    else if (state_function_pointer == &LexicalAnalyzer::D5)
    {
        state_function_pointer = &LexicalAnalyzer::exit5;
    }
    else
        state_function_pointer = &LexicalAnalyzer::la_error;

    for (int i = 0; i < TL.size(); i++)
    {
        if (TL[i].TokenClass == TC_GOTO || TL[i].TokenClass == TC_GOSUB)
        {
            int l = TS.get_token_table_index(TL[i].TokenValue);
            if (l == -1)
            {
                string error_msg = "Error(" + to_string(current_line) + "):  Goto operator calls undenefied label.\0" + to_string(TS.get_label(TL[i].TokenValue));
                errors_vector.push_back(error_msg);
                la_errors_file << error_msg << endl;
            }
        }
    }

    (this->*state_function_pointer)();

    tokens_output();
    operands_output();
    string_table_output();
    errors_output();

    la_errors_file.close();
}

void LexicalAnalyzer::create_token()
{
    token new_token;
    new_token.TokenClass = RKL;
    new_token.TokenValue = -1;

    if (RKL == TC_ERROR)
    {
        string error_message = "Error(" + to_string(current_line) + "): " + last_error_message + '\0';
        errors_vector.push_back(error_message);
        la_errors_file << "Error(" << to_string(current_line) + "): " + last_error_message << '\0' << endl;

        return;
    }
    else if (RKL == TC_ROWLABEL || RKL == TC_GOTO || RKL == TC_GOSUB)
    {
        if (RKL == TC_GOTO || RKL == TC_GOSUB)
        {
            int psk = TS.find(RSTR);

            if (psk == -1) new_token.TokenValue = TS.el_add(RSTR, -1);
            else new_token.TokenValue = psk;
        }
        else
        {
            if (RSTR == 2000)
            {
                cout << endl << endl;
                int x = 0;
                x++;
            }

            int is_exist = TS.find(RSTR);

            if (is_exist == -1) TS.el_add(RSTR, NTL);
            else if ((is_exist != -1) && (TS.get_token_table_index(is_exist) != -1))
            {
                RSE++;
                string error_msg = "Error(" + to_string(current_line) + "): Reinitialization of " + to_string(RSTR) + " label.\0";
                errors_vector.push_back(error_msg);
                la_errors_file << error_msg << endl;
            }
            else if ((is_exist != -1 && TS.get_token_table_index(is_exist) == -1)) TS.change_token_table_index(is_exist, NTL);

            new_token.TokenValue = TS.find(RSTR);
        }

        RSTR = 0;
    }
    else if (RKL == TC_OPERAND || RKL == TC_NEXT)
    {
        if (RI)
        {
            int to_index = (RK == STC_DIGIT) ? (RI + 26 * (RZN + 1)) : RI;
            TO[to_index] = 1;

            new_token.TokenValue = to_index;

            RI = 0;
        }
        else
        {
            double const_value = RCH * pow(10, RZ * (RP - RS));

            bool is_already_in_TO = false;
            for (int i = 287; i < NTO; ++i)
            {
                if (TO[i] == const_value)
                {
                    new_token.TokenValue = i;
                    is_already_in_TO = true;
                    break;
                }
            }

            if (!is_already_in_TO)
            {
                TO[NTO] = const_value;
                new_token.TokenValue = NTO;
                NTO++;
            }

            RCH = RP = RS = 0;
            RZ = 1;
        }
    }
    else if (RKL == TC_LET || RKL == TC_FOR)
    {
        TO[RI] = 1;
        new_token.TokenValue = RI;
        RI = 0;

    }
    else if (RKL == TC_ARITHMETICAL_OPERATION)
    {
        new_token.TokenValue = RZN;
    }
    else if (RKL == TC_RELATION_OPERATION)
    {
        new_token.TokenValue = ROT;
    }

    TL[NTL] = new_token;
    NTL++;
}

void LexicalAnalyzer::errors_output()
{
    if (!errors_vector.empty())
    {
        cout << "\nErrors List:\n";
        cout << "--------------------------------------\n";
        for (const auto& error : errors_vector)
            cout << error << endl;
        cout << "--------------------------------------\n";
    }
    else
        cout << "\nОшибок не обнаружено.\n";
}

void LexicalAnalyzer::tokens_output()
{
    ofstream output_file("tokens_list.txt");
    if (!output_file) throw "Error: Unable to open file for writing token list.\0";

    cout << "Tokens Table:" << endl << endl;
    cout << left << setw(5) << "№" << setw(25) << "Token Class" << setw(15) << "Token Value" << endl;
    cout << "-------------------------------------------------------------" << endl;

    output_file << "Tokens Table:" << endl << endl;
    output_file << left << setw(5) << "№" << setw(25) << "Token Class" << setw(15) << "Token Value" << endl;
    output_file << "-------------------------------------------------------------" << endl;

    char Tclass[19][23] = { "LABEL", "OPERAND", "RELATION_OPERATION", "ARITHMETICAL_OPERATION", "NEXT", "LET", "FOR", "GOTO", "GOSUB", "LBREACE", "RBRACE",
                 "IF", "RETURN", "END", "TO", "STEP", "REM", "ERROR", "ENDMARKER" };

    for (int i = 1; i < NTL; i++)
    {
        cout << left << setw(5) << i
            << setw(25) << Tclass[TL[i].TokenClass - 1]
            << setw(15) << TL[i].TokenValue << endl;

        output_file << left << setw(5) << i
            << setw(25) << Tclass[TL[i].TokenClass - 1]
            << setw(15) << TL[i].TokenValue << endl;
    }

    output_file.close();
}

void LexicalAnalyzer::operands_output()
{
    ofstream output_file("operands_list.txt");
    if (!output_file) throw "Error: Unable to open file for writing operandslist.\0";

    cout << endl;
    cout << "Operands table:" << endl << endl;
    cout << left << setw(5) << "№" << setw(15) << "Operand" << endl;
    cout << "--------------------------------------" << endl;

    output_file << "Operands table:" << endl << endl;
    output_file << left << setw(5) << "№" << setw(15) << "Operand" << endl;
    output_file << "--------------------------------------" << endl;

    for (int i = 1; i < 287; ++i)
    {
        output_file.width(3);
        if (TO[i])
        {
            cout << left << setw(5) << i
                << setw(15) << TO[i] << endl;

            output_file << left << setw(5) << i
                << setw(15) << TO[i] << endl;
        }
    }

    for (int i = 287; i < NTO; ++i)
    {
        cout << left << setw(5) << i
            << setw(15) << TO[i] << endl;

        output_file << left << setw(5) << i
            << setw(15) << TO[i] << endl;
    }

    output_file.close();
}

void LexicalAnalyzer::string_table_output()
{
    cout << "String Table:" << endl;
    ofstream fout("string_table.txt");
    TS.write_in_file(fout);
    cout << TS << endl;
}

LexicalAnalyzer::LexicalAnalyzer() :
    initial_vector(26, 0),
    table_alternatives(26),
    TL(512),
    TS(512),
    la_errors_file("la_errors.txt"),
    NTO(287),
    NTL(1),
    NTS(1),
    RZ(1),
    RI(0),
    RCH(0),
    RP(0),
    RS(0),
    RSE(0)
{
    memset(TO, 0, sizeof(TO));
    initial_vector_initialization();
    detection_table_initialization();
    state_function_pointer = &LexicalAnalyzer::A1;
}

void LexicalAnalyzer::initial_vector_initialization()
{
    initial_vector.resize(26);
    initial_vector['E' - 'A'] = 0;    // END
    initial_vector['F' - 'A'] = 2;    // FOR
    initial_vector['G' - 'A'] = 4;    // GOTO, GOSUB
    initial_vector['I' - 'A'] = 10;   // IF
    initial_vector['L' - 'A'] = 11;   // LET
    initial_vector['N' - 'A'] = 13;   // NEXT
    initial_vector['R' - 'A'] = 16;   // RETURN, REM
    initial_vector['S' - 'A'] = 22;   // STEP
    initial_vector['T' - 'A'] = 25;   // TO
}

void LexicalAnalyzer::detection_table_initialization()
{
    for (int i = 0; i < 26; ++i) {
        table_alternatives[i].alternative = -1;
        table_alternatives[i].pfunc = &LexicalAnalyzer::next;
    }

    table_alternatives[0].letter = 'N' - 'A';
    table_alternatives[1].letter = 'D' - 'A';
    table_alternatives[1].pfunc = &LexicalAnalyzer::A2q;    // END processing function
    table_alternatives[2].letter = 'O' - 'A';
    table_alternatives[3].letter = 'R' - 'A';
    table_alternatives[3].pfunc = &LexicalAnalyzer::F1b;    // FOR processing function
    table_alternatives[4].letter = 'O' - 'A';
    table_alternatives[5].alternative = 7;		            // GOSUB elternative
    table_alternatives[5].letter = 'T' - 'A';
    table_alternatives[6].letter = 'O' - 'A';
    table_alternatives[6].pfunc = &LexicalAnalyzer::E1a;    // GOTO processing function
    table_alternatives[7].letter = 'S' - 'A';
    table_alternatives[8].letter = 'U' - 'A';
    table_alternatives[9].letter = 'B' - 'A';
    table_alternatives[9].pfunc = &LexicalAnalyzer::E1b;    // функция для GOSUB processing function
    table_alternatives[10].letter = 'F' - 'A';
    table_alternatives[10].pfunc = &LexicalAnalyzer::A2r;   // IF processing function
    table_alternatives[11].letter = 'E' - 'A';
    table_alternatives[12].letter = 'T' - 'A';
    table_alternatives[12].pfunc = &LexicalAnalyzer::F1a;   // LET processing function
    table_alternatives[13].letter = 'E' - 'A';
    table_alternatives[14].letter = 'X' - 'A';
    table_alternatives[15].letter = 'T' - 'A';
    table_alternatives[15].pfunc = &LexicalAnalyzer::C1a;   // NEXT processing function
    table_alternatives[16].letter = 'E' - 'A';
    table_alternatives[17].letter = 'T' - 'A';
    table_alternatives[17].alternative = 21;
    table_alternatives[18].letter = 'U' - 'A';
    table_alternatives[19].letter = 'R' - 'A';
    table_alternatives[20].letter = 'N' - 'A';
    table_alternatives[20].pfunc = &LexicalAnalyzer::A2s;   // RETURN processing function
    table_alternatives[21].letter = 'M' - 'A';
    table_alternatives[21].pfunc = &LexicalAnalyzer::G1a;   // REM processing function
    table_alternatives[22].letter = 'T' - 'A';
    table_alternatives[23].letter = 'E' - 'A';
    table_alternatives[24].letter = 'P' - 'A';
    table_alternatives[24].pfunc = &LexicalAnalyzer::A2t;   // STEP processing function
    table_alternatives[25].letter = 'O' - 'A';
    table_alternatives[25].pfunc = &LexicalAnalyzer::A2u;   // TO processing function
}

void LexicalAnalyzer::start(const char* file_name_)
{
    ifstream input_file(file_name_);
    if (!input_file) throw "Error: Unable to open file " + string(file_name_) + " for lexical analisis.";

    int line_number = 0;

    while (!input_file.eof())
    {
        current_str.clear();
        getline(input_file, current_str);

        line_number++;
        current_line = line_number;
        current_str += '\n';

        parse();
    }

    end();

    input_file.close();
}

void LexicalAnalyzer::next() { ROB++; }

void LexicalAnalyzer::A1a()
{
    create_token();
    state_function_pointer = &LexicalAnalyzer::A1;
}

void LexicalAnalyzer::A1b()
{
    RP = 0;
    create_token();
    state_function_pointer = &LexicalAnalyzer::A1;
}

void LexicalAnalyzer::A1c()
{
    create_token();
    state_function_pointer = &LexicalAnalyzer::A1;
}

void LexicalAnalyzer::A1d()
{
    create_token();
    state_function_pointer = &LexicalAnalyzer::A1;
}

void LexicalAnalyzer::A1e()
{
    A1a();
    state_function_pointer = &LexicalAnalyzer::A1;
}

void LexicalAnalyzer::A1f()
{
    RKL = TC_ERROR;
    create_token();
    state_function_pointer = &LexicalAnalyzer::A1;
}

void LexicalAnalyzer::A2a()
{
    RKL = TC_ARITHMETICAL_OPERATION;
    create_token();
    state_function_pointer = &LexicalAnalyzer::A2;
}

void LexicalAnalyzer::A2b()
{
    create_token();
    state_function_pointer = &LexicalAnalyzer::A2;
}

void LexicalAnalyzer::A2c()
{
    create_token();
    RKL = TC_ARITHMETICAL_OPERATION;
    create_token();
    state_function_pointer = &LexicalAnalyzer::A2;
}

void LexicalAnalyzer::A2h()
{
    RKL = TC_LBRACE;
    create_token();
    state_function_pointer = &LexicalAnalyzer::A2;
}

void LexicalAnalyzer::A2l()
{
    create_token();
    RKL = TC_LBRACE;
    create_token();
    state_function_pointer = &LexicalAnalyzer::A2;
}

void LexicalAnalyzer::A2g()
{
    create_token();
    RKL = TC_ARITHMETICAL_OPERATION;
    create_token();
    state_function_pointer = &LexicalAnalyzer::A2;
}

void LexicalAnalyzer::A2p()
{
    if (ROT == 2 && RZN == 1) ROT = 4;
    else if (ROT == 3 && RZN == 1) ROT = 5;
    else if (ROT == 2 && RZN == 3) ROT = 6;

    create_token();
    state_function_pointer = &LexicalAnalyzer::A2;
}

void LexicalAnalyzer::A2r()
{
    RKL = TC_IF;
    A2b();
    state_function_pointer = &LexicalAnalyzer::A2;
}

void LexicalAnalyzer::A2k()
{
    create_token();
    RKL = TC_LBRACE;
    create_token();
    state_function_pointer = &LexicalAnalyzer::A2;
}

void LexicalAnalyzer::A2s()
{
    RKL = TC_RETURN;
    A2b();
    state_function_pointer = &LexicalAnalyzer::A2;
}

void LexicalAnalyzer::A2q()
{
    RKL = TC_END;
    A2b();
    state_function_pointer = &LexicalAnalyzer::A2;
}

void LexicalAnalyzer::A2o()
{
    if (RZN == 1)
    {
        create_token();
    }
    else
    {
        G1b();
        return;
    }
    state_function_pointer = &LexicalAnalyzer::A2;
}

void LexicalAnalyzer::A2u()
{
    RKL = TC_TO;
    A2b();
    state_function_pointer = &LexicalAnalyzer::A2;
}

void LexicalAnalyzer::A2j()
{
    create_token();
    RKL = TC_LBRACE;
    create_token();
    state_function_pointer = &LexicalAnalyzer::A2;
}

void LexicalAnalyzer::A2f()
{
    create_token();
    RKL = TC_ARITHMETICAL_OPERATION;
    create_token();
    state_function_pointer = &LexicalAnalyzer::A2;
}

void LexicalAnalyzer::A2t()
{
    RKL = TC_STEP;
    A2b();
    state_function_pointer = &LexicalAnalyzer::A2;
}

void LexicalAnalyzer::A3a()
{
    create_token();
    state_function_pointer = &LexicalAnalyzer::A3;
}

void LexicalAnalyzer::A3b()
{
    RKL = TC_RBRACE;
    create_token();
    state_function_pointer = &LexicalAnalyzer::A3;
}

void LexicalAnalyzer::A3c()
{
    create_token();
    RKL = TC_RBRACE;
    create_token();
    state_function_pointer = &LexicalAnalyzer::A3;
}

void LexicalAnalyzer::A3d()
{
    create_token();
    RKL = TC_RBRACE;
    create_token();
    state_function_pointer = &LexicalAnalyzer::A3;
}

void LexicalAnalyzer::A3g()
{
    create_token();
    RKL = TC_RBRACE;
    create_token();
    state_function_pointer = &LexicalAnalyzer::A3;
}

void LexicalAnalyzer::B1a()
{
    ROB = initial_vector[RZN];
    state_function_pointer = &LexicalAnalyzer::B1;
}

void LexicalAnalyzer::B1b()
{
    create_token();
    ROB = initial_vector[RZN];
    state_function_pointer = &LexicalAnalyzer::B1;
}

void LexicalAnalyzer::B1c()
{
    create_token();
    ROB = initial_vector[RZN];
    state_function_pointer = &LexicalAnalyzer::B1;
}

void LexicalAnalyzer::B1e()
{
    create_token();
    ROB = initial_vector[RZN];
    state_function_pointer = &LexicalAnalyzer::B1;
}

void LexicalAnalyzer::C1a()
{
    RKL = TC_NEXT;
    state_function_pointer = &LexicalAnalyzer::C1;
}

void LexicalAnalyzer::C2a()
{
    RKL = TC_OPERAND;
    RI = RZN;
    state_function_pointer = &LexicalAnalyzer::C2;
}

void LexicalAnalyzer::C2b()
{
    create_token();
    RKL = TC_OPERAND;
    RI = RZN;
    state_function_pointer = &LexicalAnalyzer::C2;
}

void LexicalAnalyzer::C2d()
{
    RI = RZN;
    state_function_pointer = &LexicalAnalyzer::C2;
}

void LexicalAnalyzer::D1a()
{
    RKL = TC_OPERAND;
    RCH = RZN;
    state_function_pointer = &LexicalAnalyzer::D1;
}

void LexicalAnalyzer::D1b()
{
    RCH *= 10;
    RCH += RZN;
    state_function_pointer = &LexicalAnalyzer::D1;
}

void LexicalAnalyzer::D1c()
{
    create_token();
    RKL = TC_OPERAND;
    RCH = RZN;
    state_function_pointer = &LexicalAnalyzer::D1;
}

void LexicalAnalyzer::D2a()
{
    RS++;
    RCH *= 10;
    RCH += RZN;
    state_function_pointer = &LexicalAnalyzer::D2;
}

void LexicalAnalyzer::D2b()
{
    RS = 1;
    RCH = RZN;
    state_function_pointer = &LexicalAnalyzer::D2;
}

void LexicalAnalyzer::D2c()
{
    RS = 0;
    state_function_pointer = &LexicalAnalyzer::D2;
}

void LexicalAnalyzer::D3a()
{
    RS = 0;
    state_function_pointer = &LexicalAnalyzer::D3;
}

void LexicalAnalyzer::D4a()
{
    if (RZN == 1) RZ = 1;
    else if (RZN == 2) RZ = -1;

    state_function_pointer = &LexicalAnalyzer::D4;
}

void LexicalAnalyzer::D5a()
{
    RZ = 1;
    RP = RZN;
    state_function_pointer = &LexicalAnalyzer::D5;
}

void LexicalAnalyzer::D5b()
{
    RP = RZN;
    state_function_pointer = &LexicalAnalyzer::D5;
}

void LexicalAnalyzer::D5c()
{
    RP *= 10;
    RP += RZN;
    state_function_pointer = &LexicalAnalyzer::D5;
}

void LexicalAnalyzer::D6a()
{
    create_token();
    RKL = TC_OPERAND;
    state_function_pointer = &LexicalAnalyzer::D6;
}

void LexicalAnalyzer::D6b()
{
    RKL = TC_OPERAND;
    state_function_pointer = &LexicalAnalyzer::D6;
}

void LexicalAnalyzer::E1a()
{
    RKL = TC_GOTO;
    state_function_pointer = &LexicalAnalyzer::E1;
}

void LexicalAnalyzer::E1b()
{
    RKL = TC_GOSUB;
    state_function_pointer = &LexicalAnalyzer::E1;
}

void LexicalAnalyzer::E2a()
{
    RKL = TC_ROWLABEL;
    RSTR = RZN;
    state_function_pointer = &LexicalAnalyzer::E2;
}

void LexicalAnalyzer::E2b()
{
    RSTR = RZN;
    state_function_pointer = &LexicalAnalyzer::E2;
}

void LexicalAnalyzer::E2c()
{
    RSTR *= 10;
    RSTR += RZN;
    state_function_pointer = &LexicalAnalyzer::E2;
}

void LexicalAnalyzer::F1a()
{
    RKL = TC_LET;
    state_function_pointer = &LexicalAnalyzer::F1;
}

void LexicalAnalyzer::F1b()
{
    RKL = TC_FOR;
    state_function_pointer = &LexicalAnalyzer::F1;
}

void LexicalAnalyzer::F2a()
{
    RI = RZN;
    state_function_pointer = &LexicalAnalyzer::F2;
}

void LexicalAnalyzer::F3a()
{
    RI += (RZN) * 26;
    state_function_pointer = &LexicalAnalyzer::F3;
}

void LexicalAnalyzer::G1a()
{
    RKL = TC_REM;
    create_token();
    state_function_pointer = &LexicalAnalyzer::G1;
}

void LexicalAnalyzer::G1b()
{
    RKL = TC_ERROR;
    create_token();
    state_function_pointer = &LexicalAnalyzer::G1;
}

void LexicalAnalyzer::H1a()
{
    RKL = TC_RELATION_OPERATION;
    ROT = RZN;
    state_function_pointer = &LexicalAnalyzer::H1;
}

void LexicalAnalyzer::H1b()
{
    create_token();
    RKL = TC_RELATION_OPERATION;
    ROT = RZN;
    state_function_pointer = &LexicalAnalyzer::H1;
}

void LexicalAnalyzer::H1c()
{
    create_token();
    RKL = TC_RELATION_OPERATION;
    ROT = RZN;
    state_function_pointer = &LexicalAnalyzer::H1;
}

void LexicalAnalyzer::H1f()
{
    H1b();
    RKL = TC_RELATION_OPERATION;
    ROT = RZN;
    state_function_pointer = &LexicalAnalyzer::H1;
}

void LexicalAnalyzer::M1()
{
    if (ROB == -1)
    {
        G1b();
        return;
    }
    if (RZN == table_alternatives[ROB].letter)
    {
        (this->*(table_alternatives[ROB].pfunc))();
    }
    else
    {
        ROB = table_alternatives[ROB].alternative;
        if (ROB)
        {
            (this->*(table_alternatives[ROB].pfunc))();
        }
        else
            G1b();
    }
}

void LexicalAnalyzer::M2()
{
    if (RZN == 5)
    {
        D3a();
        return;
    }
    else
    {
        create_token();
        ROB = initial_vector[RZN];
        state_function_pointer = &LexicalAnalyzer::B1;
    }
}

void LexicalAnalyzer::M3() { if (RZN == 5) state_function_pointer = &LexicalAnalyzer::D3; }

void LexicalAnalyzer::exit1()
{
    RKL = TC_ENDFILE;
    create_token();
}

void LexicalAnalyzer::exit2()
{
    create_token();
    RKL = TC_ENDFILE;
    create_token();
}

void LexicalAnalyzer::exit3()
{
    create_token();
    RKL = TC_ENDFILE;
    create_token();
}

void LexicalAnalyzer::exit4()
{
    create_token();
    RKL = TC_ENDFILE;
    create_token();
}

void LexicalAnalyzer::exit5()
{
    create_token();
    RKL = TC_ENDFILE;
    create_token();
}

void LexicalAnalyzer::la_error()
{
    RKL = TC_ERROR;
    create_token();
    RKL = TC_ENDFILE;
    create_token();
}
