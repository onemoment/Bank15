#include <iostream>
#include <string>
#include "Tool.h"
#include "Adres.h"

using namespace std;

Adres::Adres():
  fUlica(""), fDom(""), fMieszkanie(0), fKod(0), fMiasto("//"), fKraj("POLSKA") 
{}


Adres::Adres(string Ulica, string Dom, int Mieszkanie, int Kod, string Miasto, string Kraj){
	this->setUlica(Ulica);
	this->setDom(Dom);
	this->setMieszkanie(Mieszkanie);
	this->setMiasto(Miasto);
	this->setKod(Kod);
	this->setKraj(Kraj);
}
	
// setter
void Adres::setUlica(string Ulica){ this->fUlica.assign(Ulica); }
void Adres::setDom(string Dom){ this->fDom = Dom; }
void Adres::setMieszkanie(int Mieszkanie){ this->fMieszkanie = Mieszkanie; }
void Adres::setMiasto(string Miasto){ this->fMiasto = Miasto; }
void Adres::setKod(int Kod){ this->fKod = Kod; }
void Adres::setKraj(string Kraj){ this->fKraj = Kraj; }

// getter
string Adres::getUlicaDom(){
	string Result = "";
	Result.append(this->fUlica) += " ";
	Result.append(this->fDom);

	if (this->fMieszkanie > 0)
		Result.append("/") += Tool::asString(static_cast<long long> (this->fMieszkanie));

	return Result;
}

string Adres::getKodMiasto(){
	string Result;

	Result = this->getKod();
	Result.append(" ").append(this->fMiasto);

	return Result;
}

string Adres::getKraj(){
	return this->fKraj;
}

string Adres::getKod(){
	string Result;
	Result = Tool::asString(static_cast<long long> (this->fKod));

	if (Result.length() < 5){
		string Lead = "";
		for (int i = 1; i< (5 -Result.length()); i++)
			Lead.append("0");
		Result = Lead + Result;
	}

	if (this->getKraj().compare("POLSKA") == 0)
		Result = Result.substr(0,2).append("-").append(Result.substr(2,3));

	return Result;
}