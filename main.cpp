#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Obrazki{
ifstream plik;
vector <string> obraz;
int popr = 0;
int do_zrobienia = 0;
int niepopr = 0;
	
public:
	Obrazki();
	~Obrazki();
	void wczyt();
	void napewno_poprawny_pytanie();
};

Obrazki::Obrazki() {
plik.open("dane_obrazki.txt");
}

void Obrazki::wczyt() {
			string wiersz, pusta;
int lini=0;
		if(plik.good()) {
			while(!plik.eof()) {
					lini++;
						plik>>wiersz;
						obraz.push_back(wiersz);
							if(lini==21){
								this->napewno_poprawny_pytanie();
					lini=0;
					obraz.clear();
					plik>>pusta;
}
}
}
cout<<"poprawnych "<<popr<<"\n";
cout<<"niepoprawnych "<<niepopr<<"\n";
cout<<"do naprawy "<<do_zrobienia<<"\n";
}

		void Obrazki::napewno_poprawny_pytanie() {
				int ile_pierwsze=0;
				int ile_bl=0;
				bool poprK = false;
				bool poprW = false;
					for (int w=0; w<obraz.size()-1; w++) {
						for (int k=0; k<obraz.size()-1; k++) {
									if (obraz[w][k]=='1') {
			    							ile_pierwsze++;
}
}
		if ((ile_pierwsze%2==0 && obraz[w][obraz.size()-1]=='0') || (ile_pierwsze%2==1 && obraz[w][obraz.size()-1]=='1')) {
			poprW = true;			
}
		else {
			ile_bl++;
}
}
	if (ile_bl>2) {
		niepopr++;
		return;
}
	ile_bl=0;
	for (int k=0; k<obraz.size()-1; k++) {
		for (int w=0; w<obraz.size()-1; w++) {
			if (obraz[w][k]=='1') {
			    ile_pierwsze++;
}
}
		if ((ile_pierwsze%2==0 && obraz[obraz.size()-1][k]=='0') || (ile_pierwsze%2==1 && obraz[obraz.size()-1][k]=='1')) {
			poprK = true;			
}
		else {
			ile_bl++;
}
}
	if (ile_bl>2) {
		niepopr++;
			return;
}
			if (poprK && poprW) {
				popr++;
				return;
}
		do_zrobienia++;
		return;
}

Obrazki::~Obrazki() {
	plik.close();
}

int main(int argc, char** argv) {
	Obrazki o;
	o.wczyt();
	
	return 0;
}
