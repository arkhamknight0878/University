#include "Character_Type.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum Race
{
	elf = 1,
	gnome,
	human
}Race;

typedef enum Klass
{
	paladin = 1,
	barbarian,
	rogue
}Klass;

struct Abilities
{
	size_t strength;
	size_t dexterety;
	size_t constitution;
	size_t inteligence;
	size_t wisdom;
	size_t charisma;
};

struct Modifiers
{
	int strength;
	int dexterety;
	int constitution;
	int inteligence;
	int wisdom;
	int charisma;
};

struct Character
{
	char* name;
	size_t hits;
	size_t hit_dice;
	size_t lvl;
	size_t race;
	size_t klass;
	Abilities* abilities;
	Modifiers* modifiers;
};

struct DataBase
{
	Character** character;
	size_t size;
	size_t capasity;
};

void Character_Menu_Print()
{
	printf("What Do You Want to Do?\n");
	printf("1. Create Character\n");
	printf("2. See Character Info\n");
	printf("3. Exit\n");
	printf("> ");
}

size_t Option_Chooing(size_t max_opt_amount_)
{
	size_t option = 0;
	scanf_s("%Iu", &option);

	while (option < 1 || option > max_opt_amount_)
	{
		printf("!!! Incorrect Input !!! Please, Try Again:\n> ");
		scanf_s("%Iu", &option);
	}

	return option;
}

// ------------------------------ Character Creation Functions ------------------------------

void Race_List_Print()
{
	printf("1. Elf\n");
	printf("2. Gnome\n");
	printf("3. Human\n");
	printf("> ");
}

void Klass_List_Print()
{
	printf("1. Paladin\n");
	printf("2. Barbarian\n");
	printf("3. Rogue\n");
}

void Race_Choosing(Character* character_)
{
	if (!character_)
		return;

	printf("Now, please, Choose Your Character Race:\n");
	Race_List_Print();

	size_t option = Option_Chooing(3);

	switch (option)
	{
	case 1:
		character_->race = elf;
		character_->abilities->dexterety += 2;
		break;
	case 2:
		character_->race = gnome;
		character_->abilities->inteligence += 2;
		break;
	case 3:
		character_->race = human;
		character_->abilities->charisma++;
		character_->abilities->constitution++;
		character_->abilities->dexterety++;
		character_->abilities->inteligence++;
		character_->abilities->strength++;
		character_->abilities->wisdom++;
		break;
	}
}

void Klass_Choosing(Character* character_)
{
	printf("Now, please, Choose Your Character Klass:\n");
	Klass_List_Print();
	printf("> ");

	size_t option = Option_Chooing(3);

	switch (option)
	{
	case 1:
		character_->klass = paladin;
		character_->hit_dice = 10;
		break;
	case 2:
		character_->klass = barbarian;
		character_->hit_dice = 12;
		break;
	case 3:
		character_->klass = rogue;
		character_->hit_dice = 8;
		break;
	}
}

void Abilities_Adjust(Character* character_)
{
	printf("Adjust Characteristics of Your Character:\n");
	printf("\n");
	printf("Step 1: Roll four 6-sided dice and record the total of\
the highest three dice on a piece of scratch paper. Do\
this five more times, so that you have seven numbers\n\n\
Step 2: Now take your six numbers and write each number\
beside one of your character’s six abilities:\n");
	printf("\n");

	printf("1. Strength	- ");
	scanf_s("%Iu", &character_->abilities->strength);
	while (character_->abilities->strength > 20 || character_->abilities->strength == 0)
	{
		printf("Maximum Value of Any Ability is 20, Minimum - 1\nPlease, Try Again\n> ");
		scanf_s("%Iu", &character_->abilities->strength);
	}

	printf("2. Dexterety	- ");
	scanf_s("%Iu", &character_->abilities->dexterety);
	while (character_->abilities->dexterety > 20 || character_->abilities->dexterety == 0)
	{
		printf("Maximum Value of Any Ability is 20, Minimum - 1\nPlease, Try Again\n> ");
		scanf_s("%Iu", &character_->abilities->dexterety);
	}

	printf("3. Constitution - ");
	scanf_s("%Iu", &character_->abilities->constitution);
	while (character_->abilities->constitution > 20 || character_->abilities->constitution == 0)
	{
		printf("Maximum Value of Any Ability is 20, Minimum - 1\nPlease, Try Again\n > ");
		scanf_s("%Iu", &character_->abilities->constitution);
	}

	printf("4. Inteligence	- ");
	scanf_s("%Iu", &character_->abilities->inteligence);
	while (character_->abilities->inteligence > 20 || character_->abilities->inteligence == 0)
	{
		printf("Maximum Value of Any Ability is 20, Minimum - 1\nPlease, Try Again\n> ");
		scanf_s("%Iu", &character_->abilities->inteligence);
	}

	printf("5. Wisdom	- ");
	scanf_s("%Iu", &character_->abilities->wisdom);
	while (character_->abilities->wisdom > 20 || character_->abilities->wisdom == 0)
	{
		printf("Maximum Value of Any Ability is 20, Minimum - 1\nPlease, Try Again\n> ");
		scanf_s("%Iu", &character_->abilities->wisdom);
	}

	printf("6. Charisma	- ");
	scanf_s("%Iu", &character_->abilities->charisma);
	while (character_->abilities->charisma > 20 || character_->abilities->charisma == 0)
	{
		printf("Maximum Value of Any Ability is 20, Minimum - 1\nPlease, Try Again\n> ");
		scanf_s("%Iu", &character_->abilities->charisma);
	}
}

int Modifier_Value(size_t ability_value_)
{
	int modifier = -5;

	if (ability_value_ == 1)
		return modifier;

	for (size_t i = 1; i < 20; i += 2)
	{
		++modifier;

		if (ability_value_ > i && ability_value_ < (i + 3))
			return modifier;
	}

	if (ability_value_ == 20)
		return 5;

	return 1;
}

void Abilities_Modifiers(Character* character_)
{
	character_->modifiers->charisma = Modifier_Value(character_->abilities->charisma);
	character_->modifiers->constitution = Modifier_Value(character_->abilities->constitution);
	character_->modifiers->dexterety = Modifier_Value(character_->abilities->dexterety);
	character_->modifiers->inteligence = Modifier_Value(character_->abilities->inteligence);
	character_->modifiers->strength = Modifier_Value(character_->abilities->strength);
	character_->modifiers->wisdom = Modifier_Value(character_->abilities->wisdom);
}

Character* Character_Create_File(const char* filename_)
{
	FILE* file;
	fopen_s(&file, filename_, "r");
	if (!file)
		return NULL;

	Character* character = (Character*)malloc(sizeof(Character));
	if (!character)
		return NULL;

	character->name = (unsigned char*)calloc(21, sizeof(unsigned char));
	if (!character->name)
	{
		free(character);
		return NULL;
	}

	character->abilities = (Abilities*)malloc(sizeof(Abilities));
	if (!character->abilities)
	{
		free(character->name);
		free(character);
		return NULL;
	}

	character->modifiers = (Modifiers*)malloc(sizeof(Modifiers));
	if (!character->modifiers)
	{
		free(character->name);
		free(character->abilities);
		free(character);
		return NULL;
	}

	fscanf_s(file, "%[^|]%Iu%Iu%Iu%Iu%Iu%Iu%Iu%Iu", character->name, 21,
		&character->race, &character->klass, &character->abilities->strength, &character->abilities->dexterety, &character->abilities->constitution, &character->abilities->inteligence,
		&character->abilities->wisdom, &character->abilities->charisma);

	if (character->race == 1)
		character->race = elf;
	else if (character->race == 2)
		character->race = gnome;
	else if (character->race == 3)
		character->race = human;

	if (character->klass == 1)
		character->klass = paladin;
	else if (character->klass == 2)
		character->klass = barbarian;
	else if (character->klass == 3)
		character->klass = rogue;

	Abilities_Modifiers(character);

	character->lvl = 1;

	character->hits = character->hit_dice + character->modifiers->constitution;

	fclose(file);

	return character;
}

Character* Character_Create()
{
	Character* character = malloc(sizeof(Character));
	if (!character)
		return NULL;

	character->abilities = malloc(sizeof(Abilities));
	if (!character->abilities)
	{
		free(character);
		return NULL;
	}

	character->modifiers = malloc(sizeof(Modifiers));
	if (!character->modifiers)
	{
		free(character->abilities);
		free(character);
		return NULL;
	}

	// Name Choosing
	character->name = (char*)malloc(21 * sizeof(char));
	if (!character->name)
	{
		free(character->abilities);
		free(character->modifiers);
		free(character);
		return NULL;
	}

	printf("Please, Enter Your Character Name(Max Length: 20)\n> ");
	scanf_s("%s", character->name, 20);
	printf("------------------------------------------------------------------\n");

	// Race Choosing
	Race_Choosing(character);
	printf("------------------------------------------------------------------\n");

	// Klass Choosing
	Klass_Choosing(character);
	printf("------------------------------------------------------------------\n");

	// Characteristics Adjusting
	Abilities_Adjust(character);
	Abilities_Modifiers(character);
	printf("------------------------------------------------------------------\n");

	character->lvl = 1;

	character->hits = character->hit_dice + character->modifiers->constitution;

	return character;
}

// ------------------------------ Character Info Print Functions ------------------------------

void Race_Print(Character* character_)
{
	printf("Race: ");

	switch (character_->race)
	{
	case elf:
		printf("Elf\n");
		break;
	case gnome:
		printf("Gnome\n");
		break;
	case human:
		printf("Human\n");
		break;
	}
}

void Klass_Print(Character* character_)
{
	printf("Klass: ");

	switch (character_->klass)
	{
	case paladin:
		printf("Paladin\n");
		break;
	case barbarian:
		printf("Barbarian\n");
		break;
	case rogue:
		printf("Rogue\n");
		break;
	}
}

void Abilities_Table_Print(Character* character_)
{
	printf("\n+----------------------+-----------+------------+\n");
	printf("|       Ability        |   Value   |  Modifier  |\n");
	printf("+----------------------+-----------+------------+\n");
	printf("|      Strength        |    %2Iu     |     %2d     |\n", character_->abilities->strength, character_->modifiers->strength);
	printf("+----------------------+-----------+------------+\n");
	printf("|      Dexterity       |    %2Iu     |     %2d     |\n", character_->abilities->dexterety, character_->modifiers->dexterety);
	printf("+----------------------+-----------+------------+\n");
	printf("|     Consitution      |    %2Iu     |     %2d     |\n", character_->abilities->constitution, character_->modifiers->constitution);
	printf("+----------------------+-----------+------------+\n");
	printf("|     Intelegence      |    %2Iu     |     %2d     |\n", character_->abilities->inteligence, character_->modifiers->inteligence);
	printf("+----------------------+-----------+------------+\n");
	printf("|       Wisdom         |    %2Iu     |     %2d     |\n", character_->abilities->wisdom, character_->modifiers->wisdom);
	printf("+----------------------+-----------+------------+\n");
	printf("|      Charisma        |    %2Iu     |     %2d     |\n", character_->abilities->charisma, character_->modifiers->charisma);
	printf("+----------------------+-----------+------------+\n");
}

void Info_Print(Character* character_)
{
	printf("Name: %s%10s: %Iu\n", character_->name, "Level", character_->lvl);
	printf("Hits: %Iu%10s: D%Iu\n",character_->hits, "Hit Dice", character_->hit_dice);
	printf("-----------------------------------\n");

	Race_Print(character_);
	Klass_Print(character_);

	Abilities_Table_Print(character_);
}

// ------------------------------ Level Up Functions ------------------------------

void Abilities_Print()
{
	printf("1. Strength\n");
	printf("2. Dexterity\n");
	printf("3. Constitution\n");
	printf("4. Intelegence\n");
	printf("5. Wisdom\n");
	printf("6. Charisma\n");
	printf("> ");
}

void Hits_Adjusting(Character* character_)
{
	size_t max_hits_adjusting = 0;

	printf("Now Let's Increase Your Hits\n");
	printf("Please Roll %IuxD%Iu and Add to Result %IuxConstitution Modifier\n", character_->lvl, character_->hit_dice, character_->lvl);
	printf("~ Your Courrent Constiotutin Modifier is: %d\n", character_->modifiers->constitution);
	printf("Please, Enter Result\n> ");
	scanf_s("%Iu", &max_hits_adjusting);

	while (max_hits_adjusting > character_->lvl * character_->hit_dice + character_->lvl * character_->modifiers->constitution)
	{
		printf("Don't Cheat, Please\nTry Again\n> ");
		scanf_s("%Iu", &max_hits_adjusting);
	}

	character_->hits += max_hits_adjusting;
}

void LVL_Up(Character* character_)
{
	if (character_->lvl == 20)
	{
		printf("You Have Reached the Peak of Your Capabilities.\nThere Is No Further Way...");
		return;
	}

	size_t option = 0;

	++character_->lvl;

	printf("Congrats With Level %Iu! You Can Increase 1 Ability by 2 Now!\n", character_->lvl);
	printf("Which Abilitie Do You Want Increse?\n");
	Abilities_Print();

	option = Option_Chooing(6);

	switch (option)
	{
	case 1:
		if (character_->abilities->strength == 20)
		{
			printf("You Already Maxed Out That Ability. Choose Another One\n");
			break;
		}

		character_->abilities->strength += 2;
		break;
	case 2:
		if (character_->abilities->dexterety == 20)
		{
			printf("You Already Maxed Out That Ability. Choose Another One\n");
			break;
		}

		character_->abilities->dexterety += 2;
		break;
	case 3:
		if (character_->abilities->constitution == 20)
		{
			printf("You Already Maxed Out That Ability. Choose Another One\n");
			break;
		}

		character_->abilities->constitution += 2;
		character_->hits += 2;
		break;
	case 4:
		if (character_->abilities->inteligence == 20)
		{
			printf("You Already Maxed Out That Ability. Choose Another One\n");
			break;
		}

		character_->abilities->inteligence += 2;
		break;
	case 5:
		if (character_->abilities->wisdom == 20)
		{
			printf("You Already Maxed Out That Ability. Choose Another One\n");
			break;
		}

		character_->abilities->wisdom += 2;
		break;
	case 6:
		if (character_->abilities->charisma == 20)
		{
			printf("You Already Maxed Out That Ability. Choose Another One\n");
			break;
		}

		character_->abilities->charisma += 2;
		break;
	}

	Abilities_Modifiers(character_);

	Hits_Adjusting(character_);

	if (character_->lvl == 20)
	{
		printf("You Achieved The Pinnacle of Your Vlass Features and Became Heroic (or villainous) Archetype In Your Own Right.\n\
The Fate of The World Or Even The Fundamental Order of The Multiverse Is In Your Hands");
	}
}

// ------------------------------ Character Reability Functions ------------------------------

size_t All_Abilities_Count(Character* character_)
{
	size_t abilities = character_->abilities->charisma + character_->abilities->constitution + character_->abilities->dexterety +
		character_->abilities->inteligence + character_->abilities->strength + character_->abilities->wisdom;

	return abilities;
}

void Abilities_Zeroing(Character* character_)
{
	character_->abilities->charisma = 1;
	character_->abilities->constitution = 1;
	character_->abilities->dexterety = 1;
	character_->abilities->inteligence = 1;
	character_->abilities->strength = 1;
	character_->abilities->wisdom = 1;
}

void Reabilities(Character* character_)
{
	size_t abilities_points = All_Abilities_Count(character_) - 6;
	size_t option = 0;

	Abilities_Zeroing(character_);

	while (abilities_points)
	{
		size_t add_amount = 0;

		printf("Abilities Points Availible: %Iu\n", abilities_points);
		printf("Which Ability Do Want to Increase?\n");

		printf("How Much Abilities Points Do You Want To Add?\n> ");
		scanf_s("%Iu", &add_amount);

		while (add_amount > 20 || add_amount > abilities_points)
		{
			printf("Max Value of Any Ability Was Exceeded OR You Want To Add More, Then You Can\nPlease, Try Again\n> ");
			scanf_s("%Iu", &add_amount);
		}

		printf("Which Ability Do You Want to Increase by %Iu?\n", add_amount);
		Abilities_Print();

		option = Option_Chooing(6);

		switch (option)
		{
		case 1:
			if (character_->abilities->strength == 20)
			{
				printf("You Already Maxed Out That Ability. Choose Another One\n");
				break;
			}

			character_->abilities->strength += add_amount - 1;
			break;
		case 2:
			if (character_->abilities->dexterety == 20)
			{
				printf("You Already Maxed Out That Ability. Choose Another One\n");
				break;
			}

			character_->abilities->dexterety += add_amount - 1;
			break;
		case 3:
			if (character_->abilities->constitution == 20)
			{
				printf("You Already Maxed Out That Ability. Choose Another One\n");
				break;
			}

			character_->abilities->constitution += add_amount - 1;
			break;
		case 4:
			if (character_->abilities->inteligence == 20)
			{
				printf("You Already Maxed Out That Ability. Choose Another One\n");
				break;
			}

			character_->abilities->inteligence += add_amount - 1;
			break;
		case 5:
			if (character_->abilities->wisdom == 20)
			{
				printf("You Already Maxed Out That Ability. Choose Another One\n");
				break;
			}

			character_->abilities->wisdom += add_amount - 1;
			break;
		case 6:
			if (character_->abilities->charisma == 20)
			{
				printf("You Already Maxed Out That Ability. Choose Another One\n");
				break;
			}

			character_->abilities->charisma += add_amount - 1;
			break;
		}

		abilities_points -= add_amount;
	}

	Abilities_Modifiers(character_);

	character_->hits = character_->hit_dice + character_->modifiers->constitution;

	Hits_Adjusting(character_);
}

void Rename(Character* character_)
{
	char* temp = (char*)realloc(character_->name, 21);
	if (!temp)
		return;

	character_->name = temp;

	printf("Please, Enter New Character Name(Max Length: 20)\n> ");
	scanf_s("%s", character_->name, 20);
}

void Character_Delete(Character*  character_)
{
	free(character_->name);
	free(character_->abilities);
	free(character_->modifiers);
	free(character_);

}

// ------------------------------ Data Base Functions ------------------------------

void DataBase_Menu_Print()
{
	printf("What Do You Want to Do?\n");
	printf("1. Create New Character\n");
	printf("2. Edit an Existing Character\n");
	printf("3. Print Characters List\n");
	printf("4. Sort Characters by Key\n");
	printf("5. Find Characters by Key\n");
	printf("6. Delete Characters by Key\n");
	printf("7. Exit\n");
	printf("> ");
}

DataBase* DataBase_Create(size_t size_)
{
	DataBase* database = malloc(sizeof(DataBase));
	if (!database)
		return NULL;

	database->character = malloc(size_ * sizeof(Character));
	if (!database->character)
	{
		free(database);
		return NULL;
	}

	database->size = 0;
	database->capasity = size_;

	return database;
}

void Add_Menu_Print()
{
	printf("How Do You Want to Create Your Character?\n");
	printf("1. From File\n");
	printf("2. Manualy\n");
	printf("3. Cancel\n");
	printf("> ");
}

void Add_Element(DataBase* database_, const char* filename_)
{
	if (!database_)
		return;

	size_t option = 0;

	Add_Menu_Print();

	option = Option_Chooing(2);

	switch (option)
	{
	case 1:
		database_->character[database_->size] = Character_Create_File(filename_);
		break;
	case 2:
		database_->character[database_->size] = Character_Create();
		break;
	}

	database_->size++;

	if (database_->size >= database_->capasity)
	{
		database_->capasity *= 2;

		Character* temp = (Character*)realloc(*database_->character, database_->size);
		if (!temp)
			return;

		*database_->character = temp;
	}
}

void Edit_Menu_Print()
{
	printf("1. Level Up\n");
	printf("2. Reallocate Abilities\n");
	printf("3. Rename Character\n");
	printf("4. Get Full Info\n");
	printf("5. Delete Character\n");
	printf("6. Cansel\n");
	printf("> ");
}

void Names_Print(DataBase* database_)
{
	for (size_t i = 0; i < database_->size; i++)
		printf("%Iu. %s\n", i + 1, database_->character[i]->name);

	printf("> ");
}

void Edit_Element(DataBase* database_)
{
	size_t index = 0;

	size_t option = 0;

	printf("Which Character Do You Want To Edit?\n");
	Names_Print(database_);

	scanf_s("%Iu", &index);

	while (index > database_->size)
	{
		printf("There Is No Such Character. Please, Try Again\n> ");
		scanf_s("%Iu", &index);
	}

	printf("What Do You Want To Do With %s\n", database_->character[index - 1]->name);
	Edit_Menu_Print();

	option = Option_Chooing(6);

	switch (option)
	{
	case 1:
		LVL_Up(database_->character[index - 1]);
		break;
	case 2:
		Reabilities(database_->character[index - 1]);
		break;
	case 3:
		Rename(database_->character[index - 1]);
		break;
	case 4:
		Info_Print(database_->character[index - 1]);
		break;
	case 5:
		Character_Delete(database_->character[index - 1]);
		database_->character[index - 1] = database_->character[database_->size - 1];
		database_->size--;
		break;
	}
}

void List_Print(DataBase* database_)
{
	if (database_->size == 0)
	{
		printf("There Is No Characters Now In The Database");
		return;
	}

	for (size_t i = 0; i < database_->size; ++i)
	{
		printf("-----------------------------------------\n");
		printf("Name: %s%10s: %Iu\n", database_->character[i]->name, "Level", database_->character[i]->lvl);

		Race_Print(database_->character[i]);
		Klass_Print(database_->character[i]);
	}

	printf("-----------------------------------------\n");
}

void Sort_By_Race(DataBase* database_)
{

}