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

	std::cout << "include \\masm32\\include\\masm32rt.inc\n\n";
	std::cout << ".365\n\n";

	std::cout << "\t.data?" << std::endl << std::endl;
	for (int i = 0; i <= 286; i++)
	{
		if (TO[i] == 1)
			std::cout << "\t\t" << decode_char_name(i) << " dd ?" << std::endl;
	}

	for (int i = NTO; i < NTtemp; i++)
	{
		std::cout << "\t\ttemp_" << i << " dd ?" << std::endl;
	}

	for (int i = 700; i < NTX; i++)
		std::cout << "\t\ttemp_" << i << " dd ?" << std::endl;

	std::cout << "\t.code" << std::endl << "start:" << std::endl << std::endl;

	for (int i = 0; i < 512; ++i)
	{
		switch (TA[i].atom_type)
		{
		case 1:
			std::cout << "end start";

			break;
		case 2:
			if (is_in_gosub_labels_vector(TS[TA[i].atr1]))
			{
				std::cout << "\tlabel_" << std::to_string(TS[TA[i].atr1]) << " proc" << std::endl;
				gosub_labels_vector.pop_back();
			}
			else
				std::cout << "\tlabel_" << std::to_string(TS[TA[i].atr1]) << ':' << std::endl;

			break;
		case 3:
			std::cout << "\t\tmov eax, " << std::to_string(TA[i].atr2) << std::endl;
			std::cout << "\t\tmov " << decode_char_name(TA[i].atr1) << ", eax" << std::endl;

			break;
		case 4:
			std::cout << "\t\tcall label_" << std::to_string(TS[TA[i].atr1]) << std::endl;

			break;
		case 5:
			std::cout << "\t\tcall label_" << std::to_string(TS[TA[i].atr1]) << std::endl;
			call_labels_vetor.push_back(TS[TA[i].atr1]);
			gosub_labels_vector.push_back(TS[TA[i].atr1]);

			break;
		case 6:
			std::cout << "\t" << std::to_string(call_labels_vetor.back());
			call_labels_vetor.pop_back();

			break;
		case 7:
			std::cout << "\t\tmov eax, " << std::to_string(TA[i].atr1) << std::endl;
			std::cout << "\t\tcmp eax, " << std::to_string(TA[i].atr2) << std::endl;

			switch (TA[i].atr3)
			{
			case 1:
				std::cout << "\t\tJE label_" << std::to_string(TS[TA[i].atr4]) << std::endl;

				break;
			case 2:
				std::cout << "\t\tJS label_" << std::to_string(TS[TA[i].atr4]) << std::endl;

				break;
			case 3:
				std::cout << "\t\tJNS label_" << std::to_string(TS[TA[i].atr4]) << std::endl;

				break;
			case 4:
				std::cout << "\t\tJE label_" << std::to_string(TS[TA[i].atr4]) << std::endl;
				std::cout << "\t\tJS label_" << std::to_string(TS[TA[i].atr4]) << std::endl;

				break;
			case 5:
				std::cout << "\t\tJE label_" << std::to_string(TS[TA[i].atr4]) << std::endl;
				std::cout << "\t\tJNS label_" << std::to_string(TS[TA[i].atr4]) << std::endl;

				break;
			case 6:
				std::cout << "\t\tJNE label_" << std::to_string(TS[TA[i].atr4]) << std::endl;

				break;
			}
			break;
		case 8:
			std::cout << "\t\tmov eax, " << std::to_string(TA[i].atr1) << std::endl;
			std::cout << "\t\tmov tmp_" << std::to_string(TA[i].atr2) << ", eax" << std::endl;

			break;
		case 9:
			//Êàê íîìñòðîê îòëè÷àåòñÿ îò ìåòêè?

			break;

		case 10:
			std::cout << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;
			std::cout << "\t\tcmp eax, tmp_" << std::to_string(TA[i].atr2) << std::endl;
			std::cout << "\t\tJE label_" << std::to_string(TS[TA[i].atr4]) << std::endl;
			std::cout << "\t\tJNS label_" << std::to_string(TS[TA[i].atr4]) << std::endl;
			// ×òî äåëàòü ñî step?

			break;
		case 11:
			std::cout << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;
			std::cout << "\t\tadd eax, " << std::to_string(TA[i].atr2) << std::endl;
			std::cout << "\t\tmov tmp_" << std::to_string(TA[i].atr2) << ", eax" << std::endl;

			break;
		case 12:
			std::cout << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;
			std::cout << "\t\tadd eax, " << decode_char_name(TA[i].atr2) << std::endl;
			std::cout << "\t\tmov tmp_" << std::to_string(TA[i].atr3) << ", eax" << std::endl;

			break;
		case 13:
			std::cout << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;
			std::cout << "\t\sub eax, " << decode_char_name(TA[i].atr2) << std::endl;
			std::cout << "\t\tmov tmp_" << std::to_string(TA[i].atr3) << ", eax" << std::endl;

			break;
		case 14:
			std::cout << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;
			std::cout << "\t\tmov ebx, " << decode_char_name(TA[i].atr2) << std::endl;
			std::cout << "\t\tmul ebx" << std::endl;
			std::cout << "\t\tmov tmp_" << std::to_string(TA[i].atr3) << ", eax" << std::endl;

			break;
		case 15:
			std::cout << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;
			std::cout << "\t\tmov ebx, " << decode_char_name(TA[i].atr2) << std::endl;
			std::cout << "\t\tdiv ebx" << std::endl;
			std::cout << "\t\tmov tmp_" << std::to_string(TA[i].atr3) << ", eax" << std::endl;

			break;
		case 16:
			std::cout << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;

			for (int j = 1; j < TA[i].atr2; j++)
				std::cout << "\t\tmul eax" << std::endl;
			std::cout << "\t\tmov tmp_" << std::to_string(TA[i].atr3) << ", eax" << std::endl;

			break;
		case 17:
			std::cout << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;
			std::cout << "\t\tinc eax" << std::endl;
			std::cout << "\t\tmov " << std::to_string(TA[i].atr2) << ", eax" << std::endl;
			break;
		case 18:
			std::cout << "\t\tmov eax, " << decode_char_name(TA[i].atr1) << std::endl;
			std::cout << "\t\tdec eax" << std::endl;
			std::cout << "\t\tmov " << std::to_string(TA[i].atr2) << ", eax" << std::endl;
			break;
		}
	}
	
	program_output.close();
}