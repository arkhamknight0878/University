#include "assembler_code_generator.h"

std::string assembler_code_generator::decode_char_name(int TO_index_)
{
	std::string res;
	if (TO_index_ <= 26)
		res += (char)(TO_index_ + 'A' - 1);
	else
	{
		int RZN_plus_1 = TO_index_ / 26;
		int RI = TO_index_ % 26;
		int RZN = RZN_plus_1 - 1;

		res += (char)('A' + RI - 1) + std::to_string(RZN);
	}

	return res;
}

bool assembler_code_generator::is_in_gosub_labels_vector(int label_to_check_)
{
	auto it = gosub_labels_vector.begin();
	while (it != gosub_labels_vector.end())
	{
		if (*it == label_to_check_)
			return true;

		++it;
	}

	return false;
}

assembler_code_generator::assembler_code_generator(const char* mini_basic_program_file_)
{
	synthax_analyzer::start(mini_basic_program_file_);

	last_label = 0;
}

assembler_code_generator::~assembler_code_generator() { ; }

void assembler_code_generator::generate(const char* assembler_program_file_)
{
	program_output.open(assembler_program_file_);
	if (!program_output)
	{
		std::cout << "Ошибка: Не удалось открыть файл для записи программы на Ассемблере." << std::endl;
		return;
	}

	program_output << "include \\masm32\\include\\masm32rt.inc\n\n";
	program_output << ".365\n\n";

	program_output << "\t.data?" << std::endl << std::endl;
	for (int i = 0; i <= 286; i++)
	{
		if (TO[i] == 1)
			program_output << "\t\t" << decode_char_name(i) << " dd ?" << std::endl;
	}

	for (int i = NTO; i < NTtemp; i++)
	{
		program_output << "\t\ttemp_" << i << " dd ?" << std::endl;
	}

	for (int i = 700; i < NTX; i++)
		program_output << "\t\ttemp_" << i << " dd ?" << std::endl;

	program_output << "\t.code" << std::endl << "start:" << std::endl << std::endl;

	for (int i = 0; i < 512; ++i)
	{
		switch (TA[i].atom_type)
		{
		case 0:
			program_output << "end start";

			break;
		case 1:
			if (is_in_gosub_labels_vector(TS.get_label(TA[i].atr1)))
			{
				program_output << "\tlabel_" << std::to_string(TS.get_label(TA[i].atr1)) << " proc" << std::endl;
				gosub_labels_vector.pop_back();
			}
			else
				program_output << "\tlabel_" << std::to_string(TS.get_label(TA[i].atr1)) << ':' << std::endl;

			break;
		case 2:
			program_output << "\t\tmov eax, " << std::to_string(TA[i].atr2) << std::endl;
			program_output << "\t\tmov " << decode_char_name(TA[i].atr1) << ", eax" << std::endl;

			break;
		case 4:
			program_output << "\t\tcall label_" << std::to_string(TS.get_label(TA[i].atr1)) << std::endl;

			break;
		case 5:
			program_output << "\t\tcall label_" << std::to_string(TS.get_label(TA[i].atr1)) << std::endl;
			call_labels_vetor.push_back(TS.get_label(TA[i].atr1));
			gosub_labels_vector.push_back(TS.get_label(TA[i].atr1));

			break;
		case 6:
			program_output << "\t" << std::to_string(call_labels_vetor.back());
			call_labels_vetor.pop_back();

			break;
		case 7:
			program_output << "\t\tmov eax, " << std::to_string(TA[i].atr1) << std::endl;
			program_output << "\t\tcmp eax, " << std::to_string(TA[i].atr2) << std::endl;

			switch (TA[i].atr3)
			{
			case 1:
				program_output << "\t\tJE label_" << std::to_string(TS.get_label(TA[i].atr4)) << std::endl;

				break;
			case 2:
				program_output << "\t\tJS label_" << std::to_string(TS.get_label(TA[i].atr4)) << std::endl;

				break;
			case 3:
				program_output << "\t\tJNS label_" << std::to_string(TS.get_label(TA[i].atr4)) << std::endl;

				break;
			case 4:
				program_output << "\t\tJE label_" << std::to_string(TS.get_label(TA[i].atr4)) << std::endl;
				program_output << "\t\tJS label_" << std::to_string(TS.get_label(TA[i].atr4)) << std::endl;

				break;
			case 5:
				program_output << "\t\tJE label_" << std::to_string(TS.get_label(TA[i].atr4)) << std::endl;
				program_output << "\t\tJNS label_" << std::to_string(TS.get_label(TA[i].atr4)) << std::endl;

				break;
			case 6:
				program_output << "\t\tJNE label_" << std::to_string(TS.get_label(TA[i].atr4)) << std::endl;

				break;
			}
			break;
		case 8:
			program_output << "\t\tmov eax, " << std::to_string(TA[i].atr1) << std::endl;
			program_output << "\t\tmov tmp_" << std::to_string(TA[i].atr2) << ", eax" << std::endl;

			break;
		case 9:
			//Êàê íîìñòðîê îòëè÷àåòñÿ îò ìåòêè?

			break;

		case 10:
			program_output << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;
			program_output << "\t\tcmp eax, tmp_" << std::to_string(TA[i].atr2) << std::endl;
			program_output << "\t\tJE label_" << std::to_string(TS.get_label(TA[i].atr4)) << std::endl;
			program_output << "\t\tJNS label_" << std::to_string(TS.get_label(TA[i].atr4)) << std::endl;
			// ×òî äåëàòü ñî step?

			break;
		case 11:
			program_output << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;
			program_output << "\t\tadd eax, " << std::to_string(TA[i].atr2) << std::endl;
			program_output << "\t\tmov tmp_" << std::to_string(TA[i].atr2) << ", eax" << std::endl;

			break;
		case 12:
			program_output << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;
			program_output << "\t\tadd eax, " << decode_char_name(TA[i].atr2) << std::endl;
			program_output << "\t\tmov tmp_" << std::to_string(TA[i].atr3) << ", eax" << std::endl;

			break;
		case 13:
			program_output << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;
			program_output << "\t\sub eax, " << decode_char_name(TA[i].atr2) << std::endl;
			program_output << "\t\tmov tmp_" << std::to_string(TA[i].atr3) << ", eax" << std::endl;

			break;
		case 14:
			program_output << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;
			program_output << "\t\tmov ebx, " << decode_char_name(TA[i].atr2) << std::endl;
			program_output << "\t\tmul ebx" << std::endl;
			program_output << "\t\tmov tmp_" << std::to_string(TA[i].atr3) << ", eax" << std::endl;

			break;
		case 15:
			program_output << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;
			program_output << "\t\tmov ebx, " << decode_char_name(TA[i].atr2) << std::endl;
			program_output << "\t\tdiv ebx" << std::endl;
			program_output << "\t\tmov tmp_" << std::to_string(TA[i].atr3) << ", eax" << std::endl;

			break;
		case 16:
			program_output << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;

			for (int j = 1; j < TA[i].atr2; j++)
				program_output << "\t\tmul eax" << std::endl;
			program_output << "\t\tmov tmp_" << std::to_string(TA[i].atr3) << ", eax" << std::endl;

			break;
		case 17:
			program_output << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;
			program_output << "\t\tinc eax" << std::endl;
			program_output << "\t\tmov " << std::to_string(TA[i].atr2) << ", eax" << std::endl;
			break;
		case 18:
			program_output << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;
			program_output << "\t\tdec eax" << std::endl;
			program_output << "\t\tmov " << std::to_string(TA[i].atr2) << ", eax" << std::endl;
			break;
		}
	}
	
	program_output.close();
}