#include "Hash.h"


int main()
{
	Hash new_hash;
	new_hash.add(21, 1);
	new_hash.add(121, 1);
	new_hash.add(221, 1);
	new_hash.add(421, 1);
	new_hash.add(421, 1);

	cout << new_hash;

	new_hash.erase(121);
	new_hash.erase(221);

	cout << new_hash;

	new_hash.add(321, 1);

	cout << new_hash;

	new_hash.add(521, 1);

	cout << new_hash;

	return 0;
}