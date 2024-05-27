#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef struct DataBase DataBase;

typedef struct Abilities Abilities;

typedef struct Modifiers Modifiers;

typedef struct Level_Info Level_Info;

typedef struct Character Character;

void Character_Menu_Print();

size_t Option_Chooing(size_t max_opt_amount_);

// ------------------------------ Character Creation Functions ------------------------------

/**
 * @brief : List of Races Output
 */
void Race_List_Print();

/**
 * @brief : List of Klasses Output
 */
void Klass_List_Print();

/**
 * @brief : Race Choosing and Abilities Adjusting
 * @param character_ : Character
 */
void Race_Choosing(Character* character_);

/**
 * @brief : Klass Choosing and Abilities Adjusting
 * @param character_ : Character
 */
void Klass_Choosing(Character* character_);

/**
 * @brief : Abilities Adjusting
 * @param character_ : Character
 */
void Abilities_Adjust(Character* character_);

int Modifier_Value(size_t ability_value_);

void Abilities_Modifiers(Character* character_);

Character* Character_Create_File(const char* filename_);

/**
 * @brief : Character Creation
 * @return : Character
 */
Character* Character_Create();

// ------------------------------ Character Info Print Functions ------------------------------

void Race_Print(Character* character_);

void Klass_Print(Character* character_);

void Abilities_Table_Print(Character* character_);

void Info_Print(Character* character_);

// ------------------------------ Level Up Functions ------------------------------

void Abilities_Print();

void Hits_Adjusting(Character* character_);

void LVL_Up(Character* character_);

// ------------------------------ Character Reability Functions ------------------------------

size_t All_Abilities_Count(Character* character_);

void Abilities_Zeroing(Character* character_);

void Reabilities(Character* character_);

void Rename(Character* character_);

void Character_Delete(Character* character_);

// ------------------------------ Data Base Functions ------------------------------

DataBase* DataBase_Create(size_t size_);

void DataBase_Menu_Print();

void Add_Menu_Print();

void Add_Element(DataBase* database_, const char* filename_);

void Edit_Menu_Print();

void Names_Print(DataBase* database_);

void Edit_Element(DataBase* database_);

void List_Print(DataBase* database_);

void Sort_By_Race(DataBase* database_);