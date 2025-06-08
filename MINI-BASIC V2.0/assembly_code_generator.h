#ifndef ASSEMBLY_CODE_GENERATOR
#define ASSEMBLY_CODE_GENERATOR

#include "syntax_block.h"

class AssemblyCodeGenerator : public SyntaxAnalyzer
{
private:
	ofstream output_file;
	const char* filename;
public:
	AssemblyCodeGenerator(const char* input_file_name_);

	void code_generator();
};

#endif // !ASSEMBLY_CODE_GENERATOR