/*  Napisati na jeziku C++ sledeće klase(klase opremiti onim konstruktorima,
	destruktorom i operatorom za dodelu vrednosti koji su potrebni
	za bezbedno korišćenje klasa;
	greške prijavljivati izuzecima tipa jednostavnih klasa koje su opremljene pisanjem teksta poruke):

	Generička lista podataka nekog tipa stvara se prazna
		posle čega se podaci dodaju jedan po jedan na kraju liste.
		Može da se postavi na prvi element liste,
		da se prelazi na sledeći element u odnosu na tekući,
		da se ispita da li postoji tekući element,
		da se pristupi podatku u tekućem elementu sa mogućnošću
		promene vrednosti podatka i da se tekući element izbaci iz liste
		(pri tome sledeći element postaje tekući).
		Greška je ako tekući element ne postoji u momentu pokušaja pristupanja elementu
		ili izbacivanja elementa.

	Datum se zadaje pomoću dana, meseca i godine.
		Pri stvaranju datuma nije potrebno proveravati ispravnost parametara.
		Komponente datuma mogu da se dohvate. Datum može da se upiše u izlazni tok (it<<datum).

	Za osobu se zna ime i datum rođenja. Podaci o osobi mogu da se dohvataju,
		da se promene i mogu da se upišu u izlazni tok (it<<osoba).
		Osoba ne sme da se kopira ni na koji način.

	Ispit se zadaje pomoću jednoslovne šifre predmeta,
		dobijene ocene i datuma polaganja ispita.
		Moguće ocene su od 0 do 10 (ne treba proveravati).
		Ispit je položen ako je ocena 6 ili viša. Podaci o ispitu mogu da se dohvataju.
		Ispit ne sme da se kopira ni na koji način.

	Đak je osoba koja je polagala izvestan broj ispita.
		Stvara se s praznom listom ispita posle čega se ispiti dodaju jedan po jedan
		(djak+=&ispit; đak postane vlasnik ispita).
		Može da se odredi srednja ocena položenih ispita.
		U izlazni tok se pored opštih podataka piše i srednja ocena položenih ispita.

	Škola ima ime i sadrži listu đaka koji pohađaju školu.
		Stvara se prazna posle čega se đaci dodaju jedan po jedan
		(skola+= djak; škola ne postane vlasnik đaka).
		Može da se dohvati đak s najvišom srednjom ocenom položenih ispita
		bez mogućnosti promene podataka o tom đaku.
		Škola ne sme da se kopira ni na koji način.

	Napisati na jeziku C++ program koji napravi školu s dva đaka sa po tri polagana ispita
	i ispiše na glavnom izlazu podatke o đaku s boljim prosekom.
*/
#include "skola.h"
int main() {
	Datum d1(2, 3, 1999);
	Datum datPolaganja(25, 1, 2020);

	Djak* dj = new Djak("Petar Petrovic", d1);
	Ispit* i = new Ispit('A', datPolaganja, 9);

	*dj += i;
	Skola s("ETF");
	s += *dj;
	cout << *s.najbolji();
}