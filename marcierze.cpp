#include <iostream>

using namespace std;

typedef int macierz[3][3]; //zmienne użyte w programie
macierz m1, m2, wynik;
int i, j, odp;

bool wpisywanie(macierz& m1, macierz& m2)
{ //wpisywanie danych do macierzy A i B
    cout << "Wpisz 9 liczb do macierzy 3x3 (A): \n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cin >> m1[i][j];
        }
    }
    cout << "Wpisz 9 liczb do macierzy 3x3 (B): \n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cin >> m2[i][j];
        }
    }
    return true;
}

bool wpisywanie2(macierz& m1)
{ //wpisywanie danych do pojedyńczej macierzy
    cout << "Wpisz 9 liczb do macierzy 3x3: \n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cin >> m1[i][j];
        }
    }
    return true;
}

void dodawanieMacierzy(const macierz& m1, const macierz& m2, macierz& wynik)
{ //dodawanie macierzy A i B do siebie
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            wynik[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void odejmowanieMacierzy(const macierz& m1, const macierz& m2, macierz& wynik)
{ //odejmowanie macierzy A i B od siebie
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            wynik[i][j] = m1[i][j] - m2[i][j];
        }
    }
}

void mnozenieMacierzy(const macierz& m1, const macierz& m2, macierz& wynik)
{ //mnożenie macierzy A i B
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            wynik[i][j] += m1[i][j] * m2[i][j];
        }
    }
}

void transpozycjaMacierzy(const macierz& m1, macierz& wynik)
{ //transpozycja pojedyńczej macierzy
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            wynik[j][i] = m1[i][j];
        }
    }
}

void wypiszMacierz(const macierz& m)
{ //wypisywanie macierzy na ekran
    for (i = 0; i < 3; i++) {
        cout << "[ ";
        for (int j = 0; j < 3; j++) {
            cout << m[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void wypiszDane()
{ //wpisywanie danych do macierzy A i B i wypisywanie ich na ekran
    wpisywanie(m1, m2);
    cout << "Macierz A:" << endl;
    wypiszMacierz(m1);
    cout << "\n \n";
    cout << "Macierz B:" << endl;
    wypiszMacierz(m2);
    cout << "\n \n";
}

int main() {
    cout << "Kalkulator macierzowy" << endl << " 1. Dodawanie macierzy"
        << endl << " 2. Odejmowanie macierzy" << endl << " 3. Mnozenie macierzy"
        << endl << " 4. Transpozycja macierzy" << endl << " Wybor: ";
    cin >> odp; //wybór działania
    switch (odp)
    {
    case 1:
        wypiszDane();
        dodawanieMacierzy(m1, m2, wynik);
        cout << "Macierz Wynikowa:" << endl;
        wypiszMacierz(wynik);
        break;
    case 2:
        wypiszDane();
        odejmowanieMacierzy(m1, m2, wynik);
        cout << "Macierz Wynikowa:" << endl;
        wypiszMacierz(wynik);
        break;
    case 3:
        wypiszDane();
        mnozenieMacierzy(m1, m2, wynik);
        cout << "Macierz Wynikowa:" << endl;
        wypiszMacierz(wynik);
        break;
    case 4:
        wpisywanie2(m1);
        cout << "Macierz:" << endl;
        wypiszMacierz(m1);
        cout << "\n \n";
        transpozycjaMacierzy(m1, wynik);
        cout << "Wynik:" << endl;
        wypiszMacierz(wynik);
        break;
    default: //zakończenie programu w przypadku niepoprawnej odpowiedzi
        cout << "Blad!" << endl;
        break;
    }
    return 0;
}