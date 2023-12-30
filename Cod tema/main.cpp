#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    //Deschidere fisier pentru citire
    ifstream fisier("fisier.txt");

    if (!fisier.is_open())
    {
        cout<<"Nu s-a putut deschide fisierul!!";
        return 1;
    }

    //Creare tablou pentru stocarea numarului de aparitii a fiecarei cifre
    int NrAparitii[10] = {0};

    char Numere;
    int TotalNumere = 0;

    //Citirea inclusiv a spatiilor
    fisier >> noskipws;

    //Citirea si numararea aparitiilor fiecarei cifre
    while (fisier >> Numere)
    {
        if (isdigit(Numere))
        {
            int index = Numere - '0';//Converteste caracterul in cifra numerica
            NrAparitii[index]++;
            TotalNumere++;
        }
    }

    fisier.close();

    //Calculare entropie
    double Entropie = 0.0;
    int i = 0;
    for (i=0; i<10; i++)
    {
        cout<<"Cifra "<< i <<" apare de "<< NrAparitii[i] <<" ori."<<endl;//Afisarea numarului de aparitii al fiecarei cifre
        if (NrAparitii[i] > 0)
        {
            double Probabilitate = static_cast<double>(NrAparitii[i]) / TotalNumere;
            Entropie = Entropie - Probabilitate*log2(Probabilitate);
        }
    }

    cout<<endl;
    cout<<"Entropia parolei este: "<<Entropie<<endl;

    return 0;
}
