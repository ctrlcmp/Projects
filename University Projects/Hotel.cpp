#define _CRT_NO_SECURE_WARNINGS	
#include<iostream>
#include<fstream>
#include<string>
#include<vector>//za koriscenje niza fajlova
#include<cstdio>// za remove
using namespace std;
class hotel {
public:
	string lokacija = "Kosancicev venac 7";
	int sobe = 2;
	int br_paketa = 3;
	virtual void infromacije(void) {
		cout << "Informacije vezane za hotel:" << endl << endl;
		cout << "Hotel se nalazi na lokaciji " << lokacija << " Sadrzi u ponudi [" << br_paketa << "] paketa, sa po  [" << sobe << "]	po paketu " << endl
		<<"Ukupno 6 soba za izdavanje "<<endl<< " Radno vreme recepcije je 24h " << " Radno vreme Objekta je 365 dana u godini " << endl << endl;
	}
};
class standard :public hotel {
public:
	int kvadratura = 15;
	string eksluzivnost = "Standardan paket omogucava:dorucak-svedski sto(od 7:00h do 10:30h ujutru)";
	string paket = "Dvokrevetna soba sa opcijom Francuskog lezaja,Mini bar,Sauna,klima,Flat-televizor ";
	int cena = 70;
	fstream prijave;
	int broj_prijave=0;
	void upis_u_fajl(int broj_prijave)
	{
			prijave.open("standard_prijave.txt", ios::app);
			if (prijave.fail())
			{
				cerr << " Problem pri otvaranju fajla u klasi Standard za prijave korisnika " << endl;
				exit(1);
			}
			prijave << broj_prijave << endl;
			prijave.close();
	}
	int citanje_iz_fajla() // ovako znamo koliko da ako imas vise od 2 linije taj paket je zauzet
	{
		int brojac_linija = 0;
		string linija;
		prijave.open("standard_prijave.txt", ios::in);
		if (!prijave.is_open()) return 0;//ako ne postoji vrati nulu
		if (prijave.fail())
		{
			cerr << " Problem pri otvaranju Citanje fajla u klasi Standard za prijave korisnika " << endl;
			exit(1);
		}
		while (getline(prijave, linija))
		{
			brojac_linija++;
		}
		prijave.close();
		return brojac_linija;
	}
	void brisanje_iz_fajla()
	{
		ofstream privremenaDatoteka("privremena_standard_prijave.txt");
		string linija;
		if (!privremenaDatoteka.is_open())
		{
			cerr << " Problem pri otvaranju datoteke standard iz brisanja fajla u klasi standard" << endl;
			exit(1);
		}
		privremenaDatoteka << "1" << endl;
		privremenaDatoteka.close();

		if (remove("standard_prijave.txt") != 0)
		{
			cerr << "Greška prilikom brisanja originalne datoteke" << std::endl;
			exit(1);
		}
		if (rename("privremena_standard_prijave.txt", "standard_prijave.txt") != 0)
		{
			cerr << "Greška prilikom preimenovanja privremene datoteke" << std::endl;
			exit(1);
		}

	}
	virtual void infromacije_hotela() {
		hotel::infromacije();
	}
	virtual void ispis()
	{
		cout << " STANDARD PAKET " << endl << endl;
		cout << " Soba je velicine: " << kvadratura << "[m2] prostora " << endl;
		cout << eksluzivnost << endl;
		cout << " Opis sobe " << endl;
		cout << paket << endl;
		cout << " Cena se odnosi na 24h koriscenja usluga standard paketa je: [" << cena << "$]"<<endl << endl;
	}
};
class lux :public hotel {
public:
	int kvadratura = 50;
	string eksluzivnost = " Lux paket omogucava:dorucak-svedski sto(od 7:00h do 10:30h),Rucak(od 13:00h do  16:30h),Vecera(od 19:00h do 22:30h)";
	string paket = " Dvokrevetna soba sa opcijom Francuskog lezaja ili treceg kreveta,Mini bar,Sauna,klima,Flat-televizor,Teretana,Aparat za espreso";
	int cena = 120;
	fstream prijave;
	int broj_prijave = 0;
	void upis_u_fajl(int broj_prijave)
	{
		prijave.open("lux_prijave.txt", ios::app);
		if (prijave.fail())
		{
			cerr << " Problem pri otvaranju fajla u klasi Lux za prijave korisnika " << endl;
			exit(1);
		}
		prijave << broj_prijave << endl;
		prijave.close();
	}
	int citanje_iz_fajla() // ovako znamo koliko da ako imas vise od 2 linije taj paket je zauzet
	{
		int brojac_linija = 0;
		string linija;
		prijave.open("lux_prijave.txt", ios::in);
		if (!prijave.is_open()) return 0;//ako ne postoji vrati nulu
		if (prijave.fail())
		{
			cerr << " Problem pri otvaranju fajla u klasi Lux za prijave korisnika " << endl;
			exit(1);
		}
		while (getline(prijave, linija))
		{
			brojac_linija++;
		}
		prijave.close();
		return brojac_linija;
	}
	void brisanje_iz_fajla()
	{
		ofstream privremenaDatoteka("privremena_lux_prijave.txt");
		string linija;
		if (!privremenaDatoteka.is_open())
		{
			cerr << " Problem pri otvaranju datoteke standard iz brisanja fajla u klasi standard" << endl;
			exit(1);
		}
		privremenaDatoteka << "1" << endl;
		privremenaDatoteka.close();

		if (remove("lux_prijave.txt") != 0)
		{
			cerr << "Greška prilikom brisanja originalne datoteke" << std::endl;
			exit(1);
		}
		if (rename("privremena_lux_prijave.txt", "lux_prijave.txt") != 0)
		{
			cerr << "Greška prilikom preimenovanja privremene datoteke" << std::endl;
			exit(1);
		}

	}
	virtual void infromacije_hotela() {
		hotel::infromacije();
	}
	virtual void ispis()
	{
		cout << " LUX PAKET " << endl << endl;
		cout << " Soba je velicine: " << kvadratura << "[m2] prostora " << endl;
		cout << eksluzivnost << endl;
		cout << " Opis sobe: " << endl;
		cout << paket << endl;
		cout << " Cena se odnosi na 24h koriscenja usluga lux paketa je : [" << cena <<"$]" << endl << endl;
	}
};
class delux :public hotel {
public:
	int kvadratura = 150;
	string eksluzivnost = " Korisnicima Delux paketa je rucavanje omoguceno u bilo kom periodu dana(24h)"
		" koji se sastoji od bilo cega sa menija samog hotela(dogovor),rucavanje je mobilne prirode-telefonskim pozivom bice dostavljeno u vidu francuskog serviranja ispred broja sobe ";
	string paket = " Trokrevetna soba sa opcijom cetvrtog kreveta,Mini bar,Sauna,klima,Flat-televizor,Teretana,Aparat za espreso,Djakuzi,Tursko kupatilo,Terasa sa pogledom Na Centar Beograda";
	int cena = 200;
	fstream prijave;
	int broj_prijave = 0;
	void upis_u_fajl(int broj_prijave)
	{
		prijave.open("Delux_prijave.txt", ios::app);
		if (prijave.fail())
		{
			cerr << " Problem pri otvaranju fajla u klasi Delux za prijave korisnika " << endl;
			exit(1);
		}
		prijave << broj_prijave << endl;
		prijave.close();
	}
	int citanje_iz_fajla() // ovako znamo koliko da ako imas vise od 2 linije taj paket je zauzet
	{
		int brojac_linija = 0;
		string linija;
		prijave.open("Delux_prijave.txt", ios::in);
		if (!prijave.is_open()) return 0;//ako ne postoji vrati nulu
		if (prijave.fail())
		{
			cerr << " Problem pri otvaranju fajla u klasi Delux za prijave korisnika " << endl;
			exit(1);
		}
		while (getline(prijave, linija))
		{
			brojac_linija++;
		}
		prijave.close();
		return brojac_linija;
	}
	void brisanje_iz_fajla()
	{
		ofstream privremenaDatoteka("privremena_delux_prijave.txt");
		string linija;
		if (!privremenaDatoteka.is_open())
		{
			cerr << " Problem pri otvaranju datoteke standard iz brisanja fajla u klasi standard" << endl;
			exit(1);
		}
		privremenaDatoteka << "1" << endl;
		privremenaDatoteka.close();

		if (remove("delux_prijave.txt") != 0)
		{
			cerr << "Greška prilikom brisanja originalne datoteke" << std::endl;
			exit(1);
		}
		if (rename("privremena_delux_prijave.txt", "delux_prijave.txt") != 0)
		{
			cerr << "Greška prilikom preimenovanja privremene datoteke" << std::endl;
			exit(1);
		}
	}
	virtual void infromacije_hotela() {
		hotel::infromacije();
	}
	virtual void ispis()
	{
		cout << " DELUX PAKET " << endl << endl;
		cout << " Soba je velicine: " << kvadratura << "[m2] prostora " << endl;
		cout << eksluzivnost << endl;
		cout << " Opis sobe: " << endl;
		cout << paket << endl;
		cout << " Cena se odnosi na 24h koriscenja usluga delux paketa je : [" << cena <<"$]" << endl << endl;
	}
};
int paket = 0, aranzman = 0, soba, brojac_rezervacija = 0; // globalne promeljive
string glob;
vector<fstream>standard_paket(2);
vector<fstream>lux_paket(2);
vector<fstream>delux_paket(2);//nizovi od 2 fajla;
int izbor();
void paketi(int paket, hotel hotel1, standard *standard1, lux *lux1, delux *delux1);
void rezervacija(standard *standard1, lux *lux1, delux *delux1);
void otkazivanje(standard *standard1, lux *lux1, delux *delux1);
void prikazivanje(standard* standard1, lux* lux1, delux* delux1);
void dobrodoslica(string dobrodoslica = "Dobrodosli u aplikaciju Hotela Grand")
{
	const char* dobrodoslica_niz = dobrodoslica.c_str();// pretvara string u niz karaktera
	int brojac = 0;
	for (int i = 0; i < 5; i++)//osnovna petlja
	{
		if (i == 0 || i == 4)// gornji/donji okvir da ispise samo u tim iteracijama
		{
			for (int j = 0; j < dobrodoslica.length() + 2; j++)putchar(' ');//petlja za centriranje
			for (int g = 0; g < dobrodoslica.length() + 2; g++)putchar('*');
			putchar('\n');
		}
		if (i > 0 && i < 4)//deo petlje za ispis vodoravnih delova okvira
		{
			for (int x = 0; x < dobrodoslica.length() + 2; x++)putchar(' ');
			for (int c = 0; c < dobrodoslica.length() + 2; c++)
			{
				if (c == 0 || c == dobrodoslica.length() + 1)
				{
					putchar('*');
				}
				else if (i == 2)cout << dobrodoslica_niz[brojac++];//ispis teksta
				else putchar(' ');
			}
			putchar('\n');
		}
	}
}
bool osobaOcenilaVec(const string& ime, const string& paket, const string& sifra);
int main()
{
	standard standard1;lux lux1;delux delux1;hotel hotel1;
	dobrodoslica();// funkcija dobrodoslice
	cout << "Dobar dan,Dobrodoslicu Vam zeli ceo tim hotela Grand" << endl<<endl;
    izbor();
	paketi(paket, hotel1,&standard1 , &lux1, &delux1);
	dobrodoslica(" Sve najbolje Vam zeli tim GRAND ");
	return 0;
}
int izbor() { //  ovako odvajamo postojece od buducih klijenata
	string osoblje, pitanje;
	do
	{
		cout << "Da li zelite da rezervisete sobu(Da/Ne): "; cin >> osoblje;
		if (osoblje == "Da" || osoblje == "DA" || osoblje == "da" || osoblje == "dA")
		{
			return paket = 1;
			aranzman = 0;
			break;
		}
		else if (osoblje == "Ne" || osoblje == "NE" || osoblje == "ne" || osoblje == "nE")
		{		
			return aranzman = 1;
			paket = 0;
			break;
		}
	} while (osoblje != "Da" || osoblje != "DA" && osoblje != "Ne" || osoblje != "NE");

}
void paketi(int paket, hotel hotel1, standard* standard1, lux* lux1, delux* delux1)
{
	int opcija, brojac = 0, upis, prijava1 = 0;
	bool tacno_netacno = false;
	string rec, da;
	if (paket == 1)// to je u slucaju da nemaju rezervaciju
	{
		hotel1.infromacije();
		while (brojac != 4)//3 za prikaz svih paketa i jedan loop za izbor
		{
				do
				{
					cout << " 1: za *Standardni* paket  " << endl << " 2: za *Lux* paket" << endl << " 3: za *Delux paket* " << endl;
					cout << " Upisite:    "; cin >> opcija;
				} while (opcija != 1 && opcija != 2 && opcija != 3);
				if (opcija == 1 || opcija == 2 || opcija == 3)brojac++;
				if (opcija == 1)standard1->ispis();
				else if (opcija == 2)lux1->ispis();
				else delux1->ispis();
				cout << " Zelite li prestati sa pregledom paketa (da/ne):  "; cin >> rec;
				cout << endl;
			if (rec == "Da" || rec == "DA" || rec == "dA" || rec == "da")break;
		}
		cout << " Da li zelite da rezervisete sobu ? (da/ne):  ";cin >> da;
		cout << endl;
		if (da == "Da" || da == "DA" || da == "dA" || da == "da")
		{
			do {
				cout << " Ako zelis da rezervises neku od ponudjene tri opcije upisi (1,2,3):  ";
				cin >> upis;
				cout << endl;
				soba = upis;// upis sobe u globalnu promenljivu(ne treba mi povratni tip za funkciju)
				if (soba == 1)
				{
					if (standard1->citanje_iz_fajla() < 2)
					{
						rezervacija(standard1, lux1, delux1); // vrsimo rezervaciju
						if (brojac_rezervacija > 0)// ako plati kaparu onda se vrsi rezervacija
						{
							++prijava1; 
							standard1->upis_u_fajl(prijava1);//upisujemo broj  1(true) sto znaci da je neko zauzeo taj paket
						}
					}
					else if (standard1->citanje_iz_fajla() == 2) // ovaj kod ovde nam dozvoljava da nekom prodamo pored standard paketa i lux i delux paket
					{
						string da;
						cout << " Trenutno nemamo dostupnih soba sa paketom STANDARD , " << endl;
						cout << " Da li zelite mozda da proverite da li imamo drugih soba sa drugim paketom ? (da/ne)";
						cin >> da;
						if (da == "Da" || da == "DA" || da == "dA" || da == "da")
						{
							if (lux1->citanje_iz_fajla() < 2)
							{
								string da;
								cout << "Broj zauzetih soba  paketa lux je: [" << lux1->citanje_iz_fajla() << "]" << endl;
								cout << " Da li zelite da rezervisete lux (da/ne) "; cin >> da;
								cout << endl;
								if (da == "Da" || da == "DA" || da == "dA" || da == "da")
								{
									soba = 2;
									rezervacija(standard1, lux1, delux1);
									if (brojac_rezervacija > 0)
									{
										++prijava1;
										lux1->upis_u_fajl(prijava1);
										break;
									}
								}
							}
							else cout << " Trenutno nemamo slobodnim soba sa paketom Lux " << endl;
							if (delux1->citanje_iz_fajla() < 2)
							{
								string da;
								cout << "Broj zauzetih soba  paketa delux je: [" << delux1->citanje_iz_fajla() << "]" << endl;
								cout << " Da li zelite da rezervisete delux (da/ne) "; cin >> da;
								cout << endl;
								if (da == "Da" || da == "DA" || da == "dA" || da == "da")
								{
									soba = 3;
									rezervacija(standard1, lux1, delux1);
									if (brojac_rezervacija > 0)
									{
										++prijava1;
										delux1->upis_u_fajl(prijava1);
										break;
									}
								}
							}
							else cout << " Trenutno nemamo slobodnim soba sa paketom Delux " << endl;
						}
						else cout << " Prijatno " << endl;
					}
				}
				else if (soba == 2)
				{
					if (lux1->citanje_iz_fajla() < 2)
					{
						rezervacija(standard1, lux1, delux1); // vrsimo rezervaciju
						if (brojac_rezervacija > 0)
						{
							++prijava1;
							lux1->upis_u_fajl(prijava1);
						}
					}
					else if (lux1->citanje_iz_fajla() == 2)
					{
						string da;
						cout << " Trenutno nemamo dostupnih soba sa paketom Lux , " << endl;
						cout << " Da li zelite mozda da proverite da li imamo drugih soba sa drugim paketom ? (da/ne)";
						cin >> da;
						if (da == "Da" || da == "DA" || da == "dA" || da == "da")
						{
							if (standard1->citanje_iz_fajla() < 2)
							{
								string da;
								cout << "Broj zauzetih soba  paketa standard je: [" << standard1->citanje_iz_fajla() << "]" << endl;
								cout << " Da li zelite da rezervisete standard (da/ne) "; cin >> da;
								cout << endl;
								if (da == "Da" || da == "DA" || da == "dA" || da == "da")
								{
									soba = 1;
									rezervacija(standard1, lux1, delux1);
									if (brojac_rezervacija > 0)
									{
										++prijava1;
										standard1->upis_u_fajl(prijava1);
										break;
									}
								}
							}
							else cout << " Trenutno nemamo slobodnim soba sa paketom standard " << endl;
							if (delux1->citanje_iz_fajla() < 2)
							{
								string da;
								cout << "Broj zauzetih soba  paketa delux je: [" << delux1->citanje_iz_fajla() << "]" << endl;
								cout << " Da li zelite da rezervisete delux (da/ne) "; cin >> da;
								cout << endl;
								if (da == "Da" || da == "DA" || da == "dA" || da == "da")
								{
									soba = 3;
									rezervacija(standard1, lux1, delux1);
									if (brojac_rezervacija > 0)
									{
										++prijava1;
										delux1->upis_u_fajl(prijava1);
										break;
									}
								}
							}
							else cout << " Trenutno nemamo slobodnim soba sa paketom Delux " << endl;
						}
						else cout << " Prijatno " << endl;
					}
				}
				else
				{
					if (delux1->citanje_iz_fajla() < 2)
					{
						rezervacija(standard1, lux1, delux1); // vrsimo rezervaciju
						if (brojac_rezervacija > 0)
						{
							++prijava1;
							delux1->upis_u_fajl(prijava1);
						}
					}
					else if (delux1->citanje_iz_fajla() == 2)
					{
						string da;
						cout << " Trenutno nemamo dostupnih soba sa paketom Delux , " << endl;
						cout << " Da li zelite mozda da proverite da li imamo drugih soba sa drugim paketom ? (da/ne)";
						cin >> da;
						if (da == "Da" || da == "DA" || da == "dA" || da == "da")
						{
							if (standard1->citanje_iz_fajla() < 2)
							{
								string da;
								cout << "Broj zauzetih soba  paketa standard je: [" << standard1->citanje_iz_fajla() << "]" << endl;
								cout << " Da li zelite da rezervisete standard (da/ne) "; cin >> da;
								cout << endl;
								if (da == "Da" || da == "DA" || da == "dA" || da == "da")
								{
									soba = 1;
									rezervacija(standard1, lux1, delux1);
									if (brojac_rezervacija > 0)
									{
										++prijava1;
										standard1->upis_u_fajl(prijava1);
										break;
									}
								}
							}
							else cout << " Trenutno nemamo slobodnim soba sa paketom standard " << endl;
							if (lux1->citanje_iz_fajla() < 2)
							{
								string da;
								cout << "Broj zauzetih soba  paketa lux je: [" << lux1->citanje_iz_fajla() << "]" << endl;
								cout << " Da li zelite da rezervisete lux (da/ne) "; cin >> da;
								cout << endl;
								if (da == "Da" || da == "DA" || da == "dA" || da == "da")
								{
									soba = 2;
									rezervacija(standard1, lux1, delux1);
									if (brojac_rezervacija > 0)
									{
										++prijava1;
										lux1->upis_u_fajl(prijava1);
										break;
									}
								}
							}
							else cout << " Trenutno nemamo slobodnim soba sa paketom lux " << endl;
						}
						else cout << " Prijatno " << endl;
					}
				}

			} while (soba != 1 && soba != 2 && soba != 3);
		}
		else cout << " Hvala vam na izdvojenom vremenu i pregledu nasih akcija! " << endl;
	}
	else if (aranzman = 1)
	{
		string da;
		cout << " Da li zelite da pregledate Vasu rezervaciju (da/ne):  "; cin >> da;
		cout << endl;
		if (da == "Da" || da == "DA" || da == "dA" || da == "da")prikazivanje(standard1, lux1, delux1);
		cout << " Ako ste zainteresovani da vidite dosadasnje ocene klijenata napisite da "; cin >> da;
		cout << endl;
		if (da == "Da" || da == "DA" || da == "dA" || da == "da")
		{
			string linija;
			fstream focena;
			focena.open("Ocene_hotela.txt", ios::in);
			if (!focena.is_open())
			{
				cerr << "  Trenutno nemamo recenzija, Hvala na strpljenju " << endl;
				exit(1);
			}
			while (getline(focena, linija))
			{
				cout << linija << endl;
			}
		}
	}
}
void rezervacija(standard *standard1, lux *lux1, delux *delux1)				
{
	if (soba == 1)
	{
		string ime, prezime,paket="standard";
		int *sifra = new int[2];//dinamickmi alociram niz za sifre
		if (sifra == nullptr) { // provera
			cerr << "Niz sifra u standardu nije dobro alociran" << endl; exit(1);
		}
		string kapara,datum_dolaska,datum_odlaska;
		int dani;
		do
		{
			cout << " Koliko ste dana hteli da ostanete: ? "; cin >> dani;
		} while (dani < 0);
		cout << " Zdravo, u toku buduce saradnje politika firme jeste ostavljanje kapare koja iznosi 50% radi sigurnosti " << endl;
		cout << " Ako zelite da ostavite kaparu Vasa soba sa datim paketom bice smatrana kao izdana i niko nece moci da je zauzme " << endl << endl;
			cout << " Ako zelite da ostavite kaparu od : [ " <<(standard1->cena*dani)/2 << " $ ] napisite(da/ne) : "; cin >> kapara;
			if (kapara == "Da" || kapara == "DA" || kapara == "dA" || kapara == "da")
			{
				for (int i = standard1->citanje_iz_fajla(); i < standard1->citanje_iz_fajla()+1; i++)//prvi put I bude nula sl. put I=1 i tako omogucimoo loop da cita samo jedanput
				{
					cout << " Uspesno ste se prijavili za STANDARD paket " << endl;
					cout << " U prilozenom cemo Vam poslati informacije vezane za rezervaciju " << endl << endl;
					cout << " Vase ime : "; cin >> ime; cout << endl;
					cout << " Vase Prezime : "; cin >> prezime; cout << endl;
					cout << " Datum dolaska: "; cin >> datum_dolaska;
					cout << " Datum odlaska: "; cin >> datum_odlaska;
					for (int j = standard1->citanje_iz_fajla(); j < standard1->citanje_iz_fajla() + 1; j++)
					{
						if (j == 0) // prvi korisnik standard paketa ce imati drugacija pravial za sifru da nam se ne bi poklapale
						{
							do
							{
								cout << " Unesite neki dvocifren broj koji ce biti Vasa sifra rezervacije: "; cin >> sifra[i];
							} while (sifra[i] < 10 || sifra[i] >99);
						}
						else
						{
							do
							{
								cout << " Unesite neki trocifren broj koji ce biti Vasa sifra rezervacije: "; cin >> sifra[i];
							} while (sifra[i] < 100 || sifra[i] >999);
						}
					}
					standard_paket[i].open(ime + ("_") + paket + ("_") + ("paket")+ to_string(sifra[i])+".txt", ios::out | ios::_Noreplace);
					if (standard_paket[i].fail())
					{
						cerr << "Neuspelo otvaranje fajla u funkciji  rezervacija STANDARD" << endl;
						exit(1);
					}
					standard_paket[i] << ime << endl << prezime << endl << paket << endl << datum_dolaska << endl << datum_odlaska <<endl <<dani<<endl<<sifra[i] << endl;
					brojac_rezervacija++;
					standard_paket[i].close();
				}
				cout << endl;
				cout << " Rezervacija je bila uspesna, puno pozdrava Vas hotel GRAND " << endl << endl;
			}
			else
			{
				cout << endl;
				cout << " Rezervacija nije uspela " << endl;
				cout << " Hvala Vam na potrosenom vremenu, Vas hotel Grand " << endl;
				brojac_rezervacija=0;
			}
			delete[]sifra;//oslobadjanje sifre
	}
	else if (soba == 2)
	{
		string ime, prezime,paket="lux";
		int *sifra = new int[2]; // dinamicki alociran niz za sifre
		if (sifra == nullptr) { // provera
			cerr << "Niz sifra u lux nije dobro alociran" << endl; exit(1);
		}
		string kapara,datum_dolaska,datum_odlaska;
		int dani;
		do
		{
			cout << " Koliko ste dana hteli da ostanete: ? "; cin >> dani;
		} while (dani < 0);
		cout << " Zdravo, u toku buduce saradnje politika firme jeste ostavljanje kapare koja iznosi 50% radi sigurnosti " << endl;
		cout << " Ako zelite da ostavite kaparu Vasa soba sa datim paketom bice smatrana kao izdana i niko nece moci da je zauzme " << endl<<endl;
		cout << " Ako zelite da ostavite kaparu od : [ " << (lux1->cena * dani) / 2 << " $ ] napisite(da/ne) : "; cin >> kapara;
		if (kapara == "Da" || kapara == "DA" || kapara == "dA" || kapara == "da")
		{
			for (int i = lux1->citanje_iz_fajla(); i < lux1->citanje_iz_fajla() + 1; i++)//prvi put I bude nula sl. put I=1 i tako omogucimoo loop da cita samo jedanput
			{
				cout << " Uspesno ste se prijavili za LUX paket " << endl;
				cout << " U prilozenom cemo Vam poslati informacije vezane za rezervaciju " << endl<<endl;
				cout << " Vase ime : "; cin >> ime; cout << endl;
				cout << " Vase Prezime : "; cin >> prezime; cout << endl;
				cout << " Datum dolaska: "; cin >> datum_dolaska;
				cout << " Datum odlaska "; cin >> datum_odlaska;
				for (int j = lux1->citanje_iz_fajla(); j < lux1->citanje_iz_fajla() + 1; j++)
				{
					if (j == 0) // prvi korisnik lux paketa ce imati drugacija pravial za sifru da nam se ne bi poklapale
					{
						do
						{
							cout << " Unesite neki dvocifren broj koji ce biti Vasa sifra rezervacije: "; cin >> sifra[i];
						} while (sifra[i] < 10 || sifra[i] >99);
					}
					else
					{
						do
						{
							cout << " Unesite neki trocifren broj koji ce biti Vasa sifra rezervacije: "; cin >> sifra[i];
						} while (sifra[i] < 100 || sifra[i] >999);
					}
				}
				lux_paket[i].open(ime + ("_") + paket + ("_") + ("paket")+to_string(sifra[i]) + ".txt", ios::out | ios::_Noreplace);
				if (lux_paket[i].fail())
				{
					cerr << "Neuspelo otvaranje fajla u funkciji  rezervacija LUX" << endl;
					exit(1);
				}
				lux_paket[i] << ime << endl << prezime << endl << paket <<endl<<datum_dolaska<<endl<<datum_odlaska<<endl<<dani<<endl<<sifra[i] << endl;
				brojac_rezervacija++;
				lux_paket[i].close();
			}
			cout << endl;
			cout << " Rezervacija je bila uspesna, puno pozdrava Vas hotel GRAND " << endl << endl;
		}
		else
		{
			cout << endl;
			cout << " Hvala Vam na potrosenom vremenu, Vas hotel Grand " << endl;
			brojac_rezervacija = 0;
		}
		delete[]sifra;
	}
	else if(soba==3)
	{
		string ime, prezime,paket="delux";
		int *sifra=new int[2];//dinamicki alociran niz za sifre
		if (sifra == nullptr) { // provera
			cerr << "Niz sifra u delux nije dobro alociran" << endl; exit(1);
		}
		string kapara,datum_dolaska,datum_odlaska;
		int dani;
		do
		{
			cout << " Koliko ste dana hteli da ostanete: ? "; cin >> dani;
		} while (dani < 0);
		cout << " Zdravo, u toku buduce saradnje politika firme jeste ostavljanje kapare koja iznosi 50% radi sigurnosti " << endl;
		cout << " Ako zelite da ostavite kaparu Vasa soba sa datim paketom bice smatrana kao izdana i niko nece moci da je zauzme " << endl<<endl;
		cout << " Ako zelite da ostavite kaparu od : [ " << (delux1->cena * dani) / 2 << " $ ] napisite(da/ne) : "; cin >> kapara;
		if (kapara == "Da" || kapara == "DA" || kapara == "dA" || kapara == "da")
		{
			for (int i = delux1->citanje_iz_fajla(); i < delux1->citanje_iz_fajla() + 1; i++)//prvi put I bude nula sl. put I=1 i tako omogucimoo loop da cita samo jedanput
			{
				cout << " Uspesno ste se prijavili za DELUX paket " << endl;
				cout << " U prilozenom cemo Vam poslati informacije vezane za rezervaciju " << endl<<endl;
				cout << " Vase ime : "; cin >> ime; cout << endl;
				cout << " Vase Prezime : "; cin >> prezime; cout << endl;
				cout << " Datum dolaska: "; cin >> datum_dolaska;
				cout << " Datum odlaska: "; cin >> datum_odlaska;
				for (int j = delux1->citanje_iz_fajla(); j < delux1->citanje_iz_fajla() + 1; j++)
				{
					if (j == 0) // prvi korisnik delux paketa ce imati drugacija pravial za sifru da nam se ne bi poklapale
					{
						do
						{
							cout << " Unesite neki dvocifren broj koji ce biti Vasa sifra rezervacije: "; cin >> sifra[i];
						} while (sifra[i] < 10 || sifra[i] >99);
					}
					else
					{
						do
						{
							cout << " Unesite neki trocifren broj koji ce biti Vasa sifra rezervacije: "; cin >> sifra[i];
						} while (sifra[i] < 100 || sifra[i] >999);
					}
				}
				delux_paket[i].open(ime + ("_") + paket + ("_") + ("paket")+to_string(sifra[i]) + ".txt", ios::out | ios::_Noreplace);
				if (delux_paket[i].fail())
				{
					cerr << "Neuspelo otvaranje fajla u funkciji  rezervacija DELUX" << endl;
					exit(1);
				}
				delux_paket[i] << ime << endl << prezime << endl <<paket<<endl<<datum_dolaska<<endl<<datum_odlaska<<endl<<dani<<endl<<sifra[i] << endl;
				brojac_rezervacija++;
				delux_paket[i].close();
			}
			cout << endl;
			cout << " Rezervacija je bila uspesna, puno pozdrava Vas hotel GRAND " << endl << endl;
		}
		else
		{
			cout << endl;
			cout << " Hvala Vam na potrosenom vremenu, Vas hotel Grand " << endl;
			brojac_rezervacija = 0;
		}
		delete[]sifra;// oslobadjanje sifre
	}
}
void otkazivanje(standard* standard1, lux* lux1, delux* delux1)
{
	string rec,ime,linija,paket,broj;
		cout << " Unesite ime rezervacije: "; cin >> ime;
		cout << " Unesite sifru vaseg paketa: "; cin >> broj;
		do
		{
			cout << " Unesite Ime vaseg paketa: "; cin >> paket;
			if (paket == "standard")
			{
				if (standard1->citanje_iz_fajla() > 1)
					standard1->brisanje_iz_fajla();
				else remove("standard_prijave.txt");
			}
			else if (paket == "lux")
			{
				if (lux1->citanje_iz_fajla() > 1)
					lux1->brisanje_iz_fajla();
				else remove("lux_prijave.txt");
			}
			else if (paket == "delux")
			{
				if (delux1->citanje_iz_fajla() > 1)
					delux1->brisanje_iz_fajla();
				else remove("delux_prijave.txt");
			}
		} while (paket != "standard" && paket != "lux" && paket != "delux");
		remove((ime + ("_") + paket + ("_") + ("paket") + broj + ".txt").c_str());
		cout << " Uspesno ste otkazali vasu rezervaciju! " << endl;
	
}
void prikazivanje(standard* standard1, lux* lux1, delux* delux1)
{
	fstream focena;
	string ime, sifra, paket, datum_dolaska, datum_odlaska,prezime;
	int ocena=0, brojac = 0;
	cout << " Zdravo, ako zelite da proverite Vasu rezervaciju ili da vidite Vase podatke, molimo Vas da unesete: " << endl;
	cout << endl;
	cout << " Ime rezervacije:  "; cin >> ime;
	cout << " Paket rezervacije:  "; cin >> paket;
	cout << " Sifru rezervacije:  "; cin >> sifra;
	cout << " Prezime:  "; cin >> prezime;
	string ime_fajla = ime + ("_") + paket + ("_") + ("paket") + sifra + ".txt"; // putanja do naseg trazenog fajla
	focena.open("Ocene_hotela.txt", ios::app);
	if (!focena.is_open())
	{
		cerr << "  Greska pri otvaranju FAJLA  za ocene hotela " << endl;
		exit(1);
	}
do
{
		if (paket == "standard")
	{
			cout << endl;
			int dani = 0;
		for (int i = 0; i < 1; i++)
		{
			standard_paket[i].open(ime_fajla, ios::in);
			if (standard_paket[i].is_open())
			{
				string linija;
				while (getline(standard_paket[i], linija))
				{
					brojac++;
					switch (brojac)
					{
					case 1:cout << " Ime  : " << linija << endl;
						break;
					case 2:cout << " Prezime:  " << linija << endl;
						break;
					case 3:cout << " Paket: " << linija << endl;
						break;
					case 4:cout << " Datum dolaska: " << linija << endl;
						break;
					case 5:cout << " Datum odlaska: " << linija << endl;
						break;
					case 6:cout << " Broj dana ostanka: " << linija << endl;
						break;
					case 7:cout << " Sifra paketa:  " << linija << endl;
					}
					if (brojac == 6) {
						dani = stoi(linija);
					}
				}
			}
			else
			{
				cout << " Problem pri otvaranju fajla u funkciji prikazivanje standard " << endl;
				exit(1);
			}
			standard_paket[i].close();
		}
		cout << endl;
		if (!osobaOcenilaVec(ime, prezime, paket)) {
			cout << " Kako vam se do sada svidelo iskustvo u Hotelu Grand: " << endl << " To mozete pokazati ocenom hotela ocenom od (1/5) :  "; cin >> ocena;
			focena << "Podaci: " << ime << " " << prezime << " " << paket << " ocena: " << ocena << endl;
		}
		fstream ocenjeneOsobeFile("OcenjeneOsobe.txt", ios::app);
		if (!ocenjeneOsobeFile.is_open()) {
			cerr << "Greska pri otvaranju datoteke sa ocenjenim osobama." << endl;
			exit(1);
		}
		ocenjeneOsobeFile << ime << prezime << paket << endl;
		ocenjeneOsobeFile.close();
		if (ocena < 3)
		{		
			cout << " Ako Niste zadovoljni uslugama Hotela napisite (da/ne):   "; cin >> glob;
			if (glob == "Da" || glob == "DA" || glob == "dA" || glob == "da")
			{
				cout << " Ako ste bili do sada nezadovoljni vasim boravkom u Hotelu, Grand Vam nudi mogucnost povratka novca prilikom otkazivanja trenutnog boravista " << endl;
				otkazivanje(standard1, lux1, delux1);
				cout << " Kapara u iznosu od [" << (standard1->cena * dani) / 2 << "$ ] ce Vas cekati na nasoj recepciji,hvala na iskrenim ocenama ! " << endl;
				dobrodoslica(" Sve najbolje Vam zeli tim GRAND ");
			}
			else break;
		}
		else
		{
			cout << " Drago nam je da ste zadovoljni celokupnim tretmanom, sve najbolje hotel Grand " << endl;
			dobrodoslica(" Sve najbolje Vam zeli tim GRAND ");
			exit(1);
		}
		focena.close();
	}
	else if (paket == "lux")
	{
			cout << endl;
		int dani = 0;
		for (int i = 0; i < 1; i++)
		{
			lux_paket[i].open(ime_fajla, ios::in);
			if (lux_paket[i].is_open())
			{
				string linija;
				while (getline(lux_paket[i], linija))
				{
					brojac++;
					switch (brojac)
					{
					case 1:cout << " Ime  : " << linija << endl;
						break;
					case 2:cout << " Prezime:  " << linija << endl;
						break;
					case 3:cout << " Paket: " << linija << endl;
						break;
					case 4:cout << " Datum dolaska: " << linija << endl;
						break;
					case 5:cout << " Datum odlaska: " << linija << endl;
						break;
					case 6:cout << " Broj dana ostanka: " << linija << endl;
						break;
					case 7:cout << " Sifra paketa:  " << linija << endl;
					}
					if (brojac == 6) {
						dani = stoi(linija);
					}
				}
			}
			else
			{
				cout << " Problem pri otvaranju fajla u funkciji prikazivanje standard " << endl;
				exit(1);
			}
			lux_paket[i].close();
		}
		cout << endl;
		if (!osobaOcenilaVec(ime, prezime, paket)) {
			cout << " Kako vam se do sada svidelo iskustvo u Hotelu Grand: " << endl << " To mozete otkriti ocenom hotela ocenom od (1/5) :  "; cin >> ocena;
			focena << "Podaci: " << ime << " " << prezime << " " << paket << " ocena: " << ocena << endl;
		}
		fstream ocenjeneOsobeFile("OcenjeneOsobe.txt", ios::app);
		if (!ocenjeneOsobeFile.is_open()) {
			cerr << "Greska pri otvaranju datoteke sa ocenjenim osobama." << endl;
			exit(1);
		}
		ocenjeneOsobeFile << ime << prezime << paket << endl;
		ocenjeneOsobeFile.close();
		if (ocena < 3)
		{
			string da;
			cout << " Ako  Niste zadovoljni uslugama Hotela napisite (da/ne):   "; cin >> glob;
			if (glob == "Da" || glob == "DA" || glob == "dA" || glob == "da")
			{
				cout << " Ako ste bili do sada nezadovoljni vasim boravkom u Hotelu, Grand Vam nudi mogucnost povratka novca prilikom otkazivanja trenutnog boravista " << endl;
				otkazivanje(standard1, lux1, delux1);
				cout << " Kapara u iznosu od [" << (lux1->cena * dani) / 2 << "$ ] ce Vas cekati na nasoj recepciji,hvala na iskrenim ocenama ! " << endl;
				dobrodoslica(" Sve najbolje Vam zeli tim GRAND ");
			}
			else break;
		}
		else
		{
			cout << " Drago nam je da ste zadovoljni celokupnim tretmanom, sve najbolje hotel Grand " << endl;
			dobrodoslica(" Sve najbolje Vam zeli tim GRAND ");
			exit(1);
		}
		focena.close();
	}
	else if (paket == "delux")
	{
		cout << endl;
		int dani = 0;
		for (int i = 0; i < 1; i++)
		{
			delux_paket[i].open(ime_fajla, ios::in);
			if (delux_paket[i].is_open())
			{
				string linija;
				while (getline(delux_paket[i], linija))
				{
					brojac++;
					switch (brojac)
					{
					case 1:cout << " Ime  : " << linija << endl;
						break;
					case 2:cout << " Prezime:  " << linija << endl;
						break;
					case 3:cout << " Paket: " << linija << endl;
						break;
					case 4:cout << " Datum dolaska: " << linija << endl;
						break;
					case 5:cout << " Datum odlaska: " << linija << endl;
						break;
					case 6:cout << " Broj dana ostanka: " << linija << endl;
						break;
					case 7:cout << " Sifra paketa:  " << linija << endl;
					}
					if (brojac == 6) {
						dani = stoi(linija);
					}
				}
			}
			else
			{
				cout << " Problem pri otvaranju fajla u funkciji prikazivanje standard " << endl;
				exit(1);
			}
			delux_paket[i].close();
		}
		cout << endl;
		if (!osobaOcenilaVec(ime, prezime ,paket)) {
			cout << " Kako vam se do sada svidelo iskustvo u Hotelu Grand: " << endl << " To mozete otkriti ocenom hotela ocenom od (1/5) :  "; cin >> ocena;
			focena << "Podaci: " << ime << " " << prezime << " " << paket << " ocena: " << ocena << endl;
		}
		fstream ocenjeneOsobeFile("OcenjeneOsobe.txt", ios::app);
		if (!ocenjeneOsobeFile.is_open()) {
			cerr << "Greska pri otvaranju datoteke sa ocenjenim osobama." << endl;
			exit(1);
		}
		ocenjeneOsobeFile << ime << prezime << paket <<endl;
		ocenjeneOsobeFile.close();

		if (ocena < 3)
		{
			cout << " Ako Niste zadovoljni uslugama Hotela napisite (da/ne):   "; cin >> glob;
			if (glob == "Da" || glob== "DA" || glob == "dA" || glob == "da")
			{
				cout << " Ako ste bili do sada nezadovoljni vasim boravkom u Hotelu, Grand Vam nudi mogucnost povratka novca prilikom otkazivanja trenutnog boravista " << endl;
				otkazivanje(standard1, lux1, delux1);
				cout << " Kapara u iznosu od [" << (delux1->cena * dani) / 2 << "$ ]  ce Vas cekati na nasoj recepciji,hvala na iskrenim ocenama ! " << endl;
				dobrodoslica(" Sve najbolje Vam zeli tim GRAND ");
			}
			else break;
		}
		else
		{
			cout << " Drago nam je da ste zadovoljni celokupnim tretmanom, sve najbolje hotel Grand " << endl;
			dobrodoslica(" Sve najbolje Vam zeli tim GRAND ");
			exit(1);
		}
		focena.close();
	}
 }while (paket != "standard" && paket != "lux" && paket != "delux");
}
bool osobaOcenilaVec(const string& ime, const string& prezime, const string& paket) {
	fstream ocenjeneOsobeFile("OcenjeneOsobe.txt",ios::in);// moramo fizicki napraviti ovaj fajl pre pokretenja programa
	if (!ocenjeneOsobeFile.is_open()) {
		cerr << "Greska pri otvaranju datoteke sa ocenjenim osobama." << endl;
		exit(1);
	}
string linija;
	while (getline(ocenjeneOsobeFile, linija)) {
		// Proveri da li osoba vec postoji u datoteci
		if (linija == (ime + prezime + paket)) {
			ocenjeneOsobeFile.close();
			return true;  // Osoba već ocenila usluge hotela
		}
	}
	ocenjeneOsobeFile.close();
	return false;  // Osoba još nije ocenila usluge hotela
}
