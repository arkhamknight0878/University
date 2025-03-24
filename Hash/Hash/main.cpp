#include "Hash.h"

int main()
{
	Hash new_hash;
	new_hash.add(210, 1);
	new_hash.add(110, 1);
	new_hash.add(310, 1);
	new_hash.add(25, 1);
	new_hash.add(15, 1);
	new_hash.add(10, 1);
	new_hash.add(135, 1);
	new_hash.add(235, 1);
	new_hash.add(35, 1);

	cout << new_hash;

	new_hash.erase(10);
	new_hash.erase(135);
	new_hash.erase(25);

	cout << new_hash;

	new_hash.add(410, 1);
	new_hash.add(335, 1);
	new_hash.add(125, 1);

	cout << new_hash;

	return 0;
}