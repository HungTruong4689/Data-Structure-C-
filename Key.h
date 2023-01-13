#pragma once


class Key {
	int key;

public:
	static int comparisons;
	static int assignments;
	static int operations;
	static void init();
	static int count();
	Key(int x = 0);
	int the_key() const;
	Key& operator = (const Key& y);
};

bool operator ==(const Key& x, const Key& y);
bool operator >(const Key& x, const Key& y);
bool operator <(const Key& x, const Key& y);
bool operator >=(const Key& x, const Key& y);
bool operator <=(const Key& x, const Key& y);
bool operator !=(const Key& x, const Key& y);