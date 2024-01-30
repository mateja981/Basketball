#pragma once
#include "Igrac.h"
#include "Greske.h"
#include "Tim.h"
#include "Privilegovani.h"

template<typename T>
class Par
{
	T* t1, * t2;
public:
	Par(T* t11, T* t22) { t1 = t11; t2 = t22; }
	T& dohvati1() {return *t1;}
	T& dohvati2() { return *t2; }
	T& postavi(const T& t11, const T& t22) { t1 = t11; t2 = t22; }
	bool uporedi(const Par& p2);
	ostream& ispis(ostream& os) const;
	friend bool operator == (const Par& p1, const Par& p2) { return p1.uporedi(p2); }
	friend ostream& operator << (ostream& os, const Par& p) { return p.ispis(os); }

};

template<typename T>
bool Par<T>::uporedi(const Par& p2) {
	if (*t1 == *p2.t1 && *t2 == *p2.t2) return true;
	return false;
}

template<typename T>
ostream& Par<T>::ispis(ostream& os) const
{
	os << "[" << *t1 << "-" << *t2 << "]" << endl;
	return os;
}

