# SPA - Domaća zadaća 1

## Rok za predaju:	29. travnja 2017, 23:59:59
### Upute za predaju rješenja: 
- Rješenje se predaje pull requestom na projekt https://github.com/racspa/spa2017
- Rješenje predano nakon gornjeg roka neće se uvažiti
- Naziv pull requesta treba biti u obliku *SPA-Z01-ImePrezime-ImeAsistenta* (npr *SPA-Z01-ImePrezime-dbele* ili *SPA-Z01-ImePrezime-mzagar*)

## I2: 3 boda
### Uvod
Igra života je igra za 0 igrača koju je osmislio britanski matematičar John Horton Conwaya 1970:
- http://en.wikipedia.org/wiki/Conway's_Game_of_Life
- http://www.youtube.com/watch?v=CgOcEZinQ2I&feature=share&list=FLwikA_t8e6TSJW-L-lAHkKw

Ova igra se sastoji od niza organizama koji žive u vlastitim ćelijama u dvodimenzionalnom svijetu. Konfiguracija organizama se mijenja  u diskretnim vremenskim trenucima, pri čemu svaka ćelija matrice može biti prazna (mrtva) ili zauzeta (živa). Nova generacija organizama u ćelijama nastaje na osnovu stare generacije organizama ovisno o sadržaju osam susjednih ćelija svake pojedine ćelije (sve izvan matrice smatramo mrtvim organizmima). Pravila za formiranje nove generacije organizama su:
1.	Živi organizam u ćeliji preživljava u sljedećoj generaciji ukoliko je broj njegovih susjeda dva ili tri.
2.	Živi organizam u ćeliji umire u sljedećoj generaciji ukoliko je broj njegovih susjeda manji od dva (zbog usamljenosti) ili veći od tri (zbog prenaseljenosti).
3.	U praznoj ćeliji se rađa novi organizam ukoliko se u točno tri njene susjedne ćelije nalaze živi organizmi.
Igra života počinje od zadane početne konfiguracije i u diskretnim trenucima se formiraju sljedeće konfiguracije organizama istovremenom primjenom gornjih pravila na sve ćelije prethodne konfiguracije. Igra nema kraja.

### Vaš zadatak
Vaš zadatak je dovršiti implementaciju Igre života. Datoteke program.cpp i game_of_life.h (pri čemu se javni članovi ne smiju mijenjati, ali slobodno mijenjajte privatne članove ako smatrate da treba) su dane u predlošku projekta, a vaš zadatak je napraviti implementaciju u datoteci game_of_life.cpp. U prilogu se nalazi i exe datoteka s gotovim rješenjem kakvo i vi trebate dobiti. Neka prilikom inicijalizacije postoji 20% šanse da će u ćeliji biti živi organizam.
Za rješavanje zadatka će biti potrebno koristiti višedimenzionalna polja, tj. polje čiji svaki element čuva novo polje (http://www.cplusplus.com/doc/tutorial/arrays/).

### Koraci za kreiranje pull requesta
- kreirajte github account
- ulogirajte se na github
- otvorite url projekta https://github.com/racspa/spa2017 i kreirajte kopiju na svom github racunu klikom na gumb 'Fork' 
- rijesite zadatak i push-ajte promjene u svoj spa2017 projekt repozitorij (mozete commit-ati i push-ati koliko promjena god zelite)
- kada ste rijesili zadatak predajte ga kreiranjem pull requesta sa svog projekt natrag u projekt racspa/spa2017
- naziv pull requesta zadajte prema gore navedenim uputama
- upute za kreiranje pull requesta iz kreiranog forka: https://help.github.com/articles/creating-a-pull-request-from-a-fork/
