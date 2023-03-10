#include "Key.h"
int Key::comparisons = 0;
int Key::assignments = 0;
int Key::operations = 0;
void Key::init() {
	comparisons = 0;
}
int Key::count() {
	return comparisons;
}
int Key::the_key() const
{
	return key;
}
Key::Key(int x)
{
	key = x;
}
Key& Key::operator=(const Key& x)
{
	Key::assignments++;
	key = x.key;
	return *this;
}
bool operator ==(const Key& x, const Key& y)
{
	Key::comparisons++;
	return x.the_key() == y.the_key();
}

bool operator>(const Key& x, const Key& y)
{
	Key::comparisons++;
	return x.the_key() > y.the_key();
}

bool operator<(const Key& x, const Key& y)
{
	Key::comparisons++;
	return x.the_key() < y.the_key();
}

bool operator>=(const Key& x, const Key& y)
{
	Key::comparisons++;
	return x.the_key() >= y.the_key();
}

bool operator<=(const Key& x, const Key& y)
{
	Key::comparisons++;
	return x.the_key() <= y.the_key();
}

bool operator!=(const Key& x, const Key& y)
{
	Key::comparisons++;
	return x.the_key() != y.the_key();
}



