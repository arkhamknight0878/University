#pragma once

#include "synthax_analyzer.h"

class assembler_code_generator : public synthax_analyzer
{
private:
	std::ofstream program_output;

	std::vector<int> call_labels_vetor;
	std::vector<int> gosub_labels_vector;

	int last_label;

	std::string decode_char_name(int TO_index_);

	bool is_in_gosub_labels_vector(int label_to_check_);
public:
	assembler_code_generator(const char* mini_basic_program_file_);

	~assembler_code_generator();

	void generate(const char* assembler_program_file_);
};

