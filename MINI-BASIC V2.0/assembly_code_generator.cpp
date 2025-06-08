#include "assembly_code_generator.h"

AssemblyCodeGenerator::AssemblyCodeGenerator(const char* input_file_name_) :output_file("final_program.asm"), filename(input_file_name_)
{
	if (!output_file.is_open())
	{
		cout << "Error: Unable to open file fo write program in assembly." << endl;
		system("pause");
		exit;
	}
}

void AssemblyCodeGenerator::code_generator()
{
	this->SyntaxAnalyzer::start(filename);

	output_file << "include \\masm32\\include\\masm32rt.inc" << endl << endl << ".386" << endl << endl;

	output_file << ".data?" << endl;
	for (int i = 0; i < 286; i++)
	{
		if (TO[i])
			output_file << "x" << i << " dd " << '?' << endl;
	}
	for (const auto el : atoms_table)
	{
		if (el.type == 7)
			if (el.attribute2 != -1)
				output_file << 'x' << el.attribute2 << '\t' << "dd" << '\t' << '?' << endl;
	}

	output_file << endl << ".data" << endl;
	output_file << "x0 dd 1" << endl;
	for (int i = 287; i < NTtemp; i++)
		output_file << "x" << i << " dd " << TO[i] << endl;

	output_file << endl << ".code" << endl;
	output_file << "start:" << endl;
	for (int i = 0; i < atoms_table.size(); i++)
	{
		switch (atoms_table[i].type)
		{
		case 0:
			output_file << "print str$(x17),10,13" << endl;
			output_file << "end start";
			break;
		case 1:

			output_file << "label_" << TS.get_label(atoms_table[i].attribute1) << ':' << endl;
			break;
		case 2:
			output_file << "mov eax, " << "x" << atoms_table[i].attribute2 << endl;
			output_file << "mov x" << atoms_table[i].attribute1 << ", eax\n";
			break;
		case 3:
			output_file << "jmp " << "label_" << (TS.get_label(atoms_table[i].attribute1) == -1 ? atoms_table[i].attribute1 : TS.get_label(atoms_table[i].attribute1)) << endl;
			break;
		case 4:
			output_file << "call label_" << TS.get_label(atoms_table[i].attribute1) << endl;
			break;
		case 5:
			output_file << "ret" << endl;
			break;
		case 6:
			switch (atoms_table[i].attribute3)
			{
				output_file << "mov eax," << 'x' << atoms_table[i].attribute1 << endl;
				output_file << "cmp eax," << 'x' << atoms_table[i].attribute2 << endl;
			case 1:
				output_file << "je " << "label_" << TS.get_label(atoms_table[i].attribute4) << endl;
			case 2:

				output_file << "jl " << "label_" << TS.get_label(atoms_table[i].attribute4) << endl;
			case 3:

				output_file << "jg " << "label_" << TS.get_label(atoms_table[i].attribute4) << endl;
			case 4:

				output_file << "jle " << "label_" << TS.get_label(atoms_table[i].attribute4) << endl;
			case 5:

				output_file << "jge " << "label_" << TS.get_label(atoms_table[i].attribute4) << endl;
			case 6:

				output_file << "jne " << "label_" << TS.get_label(atoms_table[i].attribute4) << endl;
			}
			break;
		case 7:
			output_file << "mov eax, " << 'x' << atoms_table[i].attribute1 << endl;
			output_file << "mov x" << atoms_table[i].attribute2 << " " << ", eax" << endl;
			break;
		case 8:
			output_file << "label_" << atoms_table[i].attribute1 << ':' << endl;
			break;
		case 9:
			output_file << "mov eax, " << 'x' << atoms_table[i].attribute1 << endl;
			output_file << "cmp eax, x" << atoms_table[i].attribute2 << endl;
			output_file << "jg label_" << atoms_table[i].attribute4 << endl;
			break;
		case 10:
			output_file << "mov " << "eax, " << "x" << atoms_table[i].attribute1 << endl;
			output_file << "add " << "eax, " << "x" << atoms_table[i].attribute2 << endl;
			output_file << "mov " << "x" << atoms_table[i].attribute1 << ", eax" << endl;
			break;
		case 11:
			output_file << "mov " << "eax, " << "x" << atoms_table[i].attribute2 << endl;
			output_file << "add " << "eax, " << "x" << atoms_table[i].attribute1 << endl;
			output_file << "mov " << "x" << atoms_table[i].attribute3 << ", eax" << endl;
			break;
		case 12:
			output_file << "mov " << "eax, " << "x" << atoms_table[i].attribute1 << endl;
			output_file << "sub " << "eax, " << "x" << atoms_table[i].attribute2 << endl;
			output_file << "mov " << "x" << atoms_table[i].attribute3 << ", eax" << endl;
			break;
		case 13:
			output_file << "mov " << "eax, " << "x" << atoms_table[i].attribute1 << endl;
			output_file << "imul " << "x" << atoms_table[i].attribute2 << endl;
			output_file << "mov " << "x" << atoms_table[i].attribute3 << ", eax" << endl;
			break;
		case 14:
			output_file << "mov " << "eax, " << "x" << atoms_table[i].attribute1 << endl;
			output_file << "cdq" << endl;
			output_file << "idiv x" << atoms_table[i].attribute2 << endl;
			output_file << "mov " << "x" << atoms_table[i].attribute3 << ", eax" << endl;
			break;
		case 15:
			output_file << "mov edx, 0" << endl;
			output_file << "mov eax, x" << atoms_table[i].attribute1 << endl;
			output_file << "mov ecx, x" << atoms_table[i].attribute2 << endl;
			output_file << "dec ecx" << endl;
			output_file << "beg: " << endl;
			output_file << "mul x" << atoms_table[i].attribute1 << endl;
			output_file << "loop beg" << endl;
			output_file << "mov x" << atoms_table[i].attribute3 << ", eax" << endl;
			break;
		case 16:
			output_file << "mov eax, x" << atoms_table[i].attribute1 << endl;
			output_file << "mov x" << atoms_table[i].attribute2 << ", eax" << endl;
			break;
		case 17:
			output_file << "mov " << "eax, " << 0 << endl;
			output_file << "sub " << "eax, " << "x" << atoms_table[i].attribute1 << endl;
			output_file << "mov " << "x" << atoms_table[i].attribute2 << ", eax" << endl;
			break;
		}
	}
}
