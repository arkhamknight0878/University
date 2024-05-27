#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef enum Race Race;

typedef enum Klass Klass;

typedef struct DataBase DataBase;

typedef struct Abilities Abilities;

typedef struct Modifiers Modifiers;

typedef struct Level_Info Level_Info;

typedef struct Character Character;

// -------------------------------- Interactive Menu Functions --------------------------------

/**
 * @brief : Option Choosing In Interaction Menu
 * @param max_opt_amount_ : Highest Amount of Availible Menu Otions
 * @return : Chosen Menu Option
 */
size_t Option_Chooing(size_t max_opt_amount_);

// --------------------------------- Search & Sort Functions ----------------------------------

void Merge(unsigned int* arr_, unsigned int left_, unsigned int midle_, unsigned int right_);

void Merge_Sort_Recursive(unsigned int* arr_, unsigned int left_, unsigned int right_);

void Merge_Sort(unsigned int* arr_, unsigned int size_);

// ------------------------------- Character Creation Functions -------------------------------

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

/**
 * @brief : Modifies Character Ability Depending on It's Value
 * @param ability_value_ : Value of Midificated Ability
 * @return : Modificated Ability Value
 */
int Modifier_Value(size_t ability_value_);

/**
 * @brief : Modifies All Character Abilities Whith Previous Function
 * @param character_ : Character
 */
void Abilities_Modifiers(Character* character_);

/**
 * @brief : Creates Character From File
 * @param filename_ : File Name
 * @return : Created Character
 */
Character* Character_Create_File(const char* filename_);

/**
 * @brief : Creates Character With Custom Values
 * @return : Created Character
 */
Character* Character_Create();

// ------------------------------ Character Info Print Functions ------------------------------

/**
 * @brief : Prints Character Race
 * @param character_ : Character
 */
void Race_Print(Character* character_);

/**
 * @brief : Prints Character Klass
 * @param character_ : Character
 */
void Klass_Print(Character* character_);

/**
 * @brief : Prints Character Abilities Table
 * @param character_ : Character
 */
void Abilities_Table_Print(Character* character_);

/**
 * @brief : Prints Detailed Character Information
 * @param character_ : Character
 */
void Info_Print(Character* character_);

// ------------------------------------ Level Up Functions ------------------------------------

/**
 * @brief : Prints List of Abilities
 */
void Abilities_List_Print();

/**
 * @brief : Adjust Character Hits Depending on Result of Dice Roll
 * @param character_ : Character
 */
void Hits_Adjusting(Character* character_);

/**
 * @brief : Levels Up Character & Increases One of He's Ability by Two & Increses Hit Points
 * @param character_ : Character
 */
void LVL_Up(Character* character_);

// ------------------------------ Character Reability Functions ------------------------------

/**
 * @brief : Counts Sum of All Character Ailities Values
 * @param character_ : Character
 * @return : Sum of All Character Ailities Values
 */
size_t All_Abilities_Count(Character* character_);

/**
 * @brief : Set All Character Abilities to Min Value - 1
 * @param character_ : Character
 */
void Abilities_Zeroing(Character* character_);

/**
 * @brief : Allows to Redistribute Abilities Point
 * @param character_ : Character
 */
void Reabilities(Character* character_);

/**
 * @brief : Allows to Change Character Name
 * @param character_ : Character
 */
void Rename(Character* character_);

/**
 * @brief : Removes Character
 * @param character_ : Character
 */
void Character_Delete(DataBase* database_, size_t index_);

// ------------------------------------ Data Base Functions -----------------------------------

/**
 * @brief : Creates Data Base
 * @param size_ : Size of Character Type Array
 * @return : Created Data Base
 */
DataBase* DataBase_Create(size_t size_);

/**
 * @brief : Prints Data Base Interaction Menu
 */
void DataBase_Menu_Print();

/**
 * @brief : Prints Character Add Interaction Menu
 */
void Add_Menu_Print();

/**
 * @brief : Adds New Character to Data Base
 * @param database_ : Data Base
 * @param filename_ : File Name (In Case Customer Wants to Create Character From File)
 */
void Add_Element(DataBase* database_, const char* filename_);

/**
 * @brief : Prints Character Edit Menu
 */
void Edit_Menu_Print();

/**
 * @brief : Prints Names of Character from Data Base
 * @param database_ : Data Base
 */
void Names_Print(DataBase* database_);

/**
 * @brief : Alows to Edit Some Character Info
 * @param database_ : Data Base
 */
void Edit_Element(DataBase* database_);

/**
 * @brief : Prints List of Characters & Main Info About Them from Data Base
 * @param database_ : Data Base
 */
void Data_Base_List_Print(DataBase* database_);

// --------------------------------- Keys Requaered Functions ---------------------------------

void Keys_List_Print();

/**
 * @brief : Sort Characters in Data Base by Race Value
 * @param database_ : Data Base
 */
void Sort_By_Race(DataBase* database_);

// ------------------------------------- Delete Functions -------------------------------------

/**
 * @brief : Deletes Characters By Race
 * @param database_ : Database
 * @param race_ : Key Race
 */
void Delete_By_Race(DataBase* database_, Race race_);

/**
 * @brief : Deletes Characters By Klass
 * @param database_ : Database
 * @param klass_ : Key Klass
 */
void Delete_By_Klass(DataBase* database_, Klass klass_);

/**
 * @brief : Deletes Characters By Level
 * @param database_ : Database
 * @param level_ : Key Level
 */
void Delete_By_Level(DataBase* database_, size_t level_);

/**
 * @brief : Deletes Characters By Key With 3 previous Functions (depends on what key customer choose)
 * @param database_ : Database
 */
void Delete_By_Key(DataBase* database_);

// ------------------------------------- Search Functions -------------------------------------

/**
 * @brief : Searches Characters By Race & Prints Their Positions
 * @param database_ : Database
 * @param race_ : Key Race
 */
void Search_By_Race(DataBase* database_, Race race_);

/**
 * @brief : Searches Characters By Klass & Prints Their Positions
 * @param database_ : Database
 * @param klass_ : Key Klass
 */
void Search_By_Klass(DataBase* database_, Klass klass_);

/**
 * @brief : Searches Characters By Level & Prints Their Positions
 * @param database_ : Database
 * @param level_ : Key Level
 */
void Search_By_Level(DataBase* database_, size_t level_);

/**
 * @brief : Searches Characters By Key With 3 Previous Functions (depends on what key customer choose)
 * @param database_ : Database
 */
void Search_By_Key(DataBase* database_);
