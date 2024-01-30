#pragma once
#include <exception>
using namespace std;

class GMalaVrednostIgraca : public exception
{
public:
	GMalaVrednostIgraca() : exception("GRESKA: Igrac nema dovoljnu vrednost za privilegovan tim") {};
};

class GNepostojecaPozicija: public exception
{
public:
	GNepostojecaPozicija() : exception("GRESKA: Zadata pozicija igraca nije dostupna u timu") {};
};

class GNemaMesta : public exception
{
public:
	GNemaMesta() : exception("GRESKA: U timu je vec ima maximalan broj igraca") {};
};

class GNeodigranMec : public exception
{
public:
	GNeodigranMec() : exception("GRESKA: Mec nije odigran") {};
};

