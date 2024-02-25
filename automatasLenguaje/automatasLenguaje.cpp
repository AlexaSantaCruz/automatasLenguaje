
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>



using namespace std;

int showMenu(int menuVal);
vector<string> createLanguaje();
void actions(int menuVal, vector<string> languaje1, vector<string> languaje2);
void intersection(vector<string> languaje1, vector<string> languaje2);
void difference(vector<string> languaje1, vector<string> languaje2);
void concatenate(vector<string> languaje1, vector<string> languaje2);
void prefix();
void suffix();

int main()
{
    vector<string> languaje1;
    vector<string> languaje2;
    languaje1 = createLanguaje();
    languaje2 = createLanguaje();

    int menuVal=0;
    while (menuVal != 6) {
        menuVal = showMenu(menuVal);
        actions(menuVal, languaje1, languaje2);
    }
}

void intersection(vector<string> language1, vector<string> language2) {
    /*Crear conjuntos para almacenar las palabras de ambos lenguajes*/
    set<string> set1(language1.begin(), language1.end());
    set<string> set2(language2.begin(), language2.end());
    set<string> intersectionSet;

    /*Iterar sobre el primer conjunto y comprobar si cada palabra está presente en el segundo conjunto*/
    for (const auto& word : set1) {
        if (set2.find(word) != set2.end()) {
            intersectionSet.insert(word);
        }
    }

    cout << "Intersección de los lenguajes:\n";
    for (const auto& word : intersectionSet) {
        cout << word << endl;
    }
}
void difference(vector<string> language1, vector<string> language2) {
    /*Crear conjuntos para almacenar las palabras de ambos lenguajes*/
    vector<string> result;

    /*Ordenar ambos vectores para usar set_difference*/
    vector<string> sortedLanguage1 = language1;
    vector<string> sortedLanguage2 = language2;
    sort(sortedLanguage1.begin(), sortedLanguage1.end());
    sort(sortedLanguage2.begin(), sortedLanguage2.end());

    /*Encontrar la diferencia entre los dos conjuntos*/
    set_difference(sortedLanguage1.begin(), sortedLanguage1.end(),
        sortedLanguage2.begin(), sortedLanguage2.end(),
        back_inserter(result));

    cout << "Diferencia entre los lenguajes:\n";
    for (const auto& word : result) {
        cout << word << endl;
    }
}

void concatenate(vector<string> language1, vector<string> language2) {
    vector<string> result;

    /*Iterar sobre cada palabra en el primer vector*/
    for (const auto& word1 : language1) {
        /*Iterar sobre cada palabra en el segundo vector*/
        for (const auto& word2 : language2) {
            /*Concatenar las dos palabras y agregarlas al resultado*/
            result.push_back(word1 + word2);
        }
    }

    cout << "Resultado de la concatenación:\n";
    for (const auto& word : result) {
        cout << word << endl;
    }
}

void prefix() {
    string palabra;
    int lenght;
    
    cout <<endl<< "Ingresa una palabra" << endl;
    cin >> palabra;

    lenght = palabra.length();
    for (int i = 0; i < lenght; i++) {
    cout << palabra<<endl;
    palabra.pop_back();
    }

}

void suffix() {
    string palabra;
    int lenght;

    cout << endl << "Ingresa una palabra" << endl;
    cin >> palabra;

    lenght = palabra.length();
    for (int i = 0; i < lenght; i++) {
        cout << palabra << endl;
        palabra.erase(palabra.begin());
    }


}

void actions(int menuVal, vector<string> languaje1, vector<string> languaje2) {
    switch (menuVal)
    {
    case 1:
        intersection(languaje1, languaje2);
        break;

    case 2:
        difference(languaje1, languaje2);
        break;

    case 3:
        concatenate(languaje1, languaje2);
        break;

    case 4:
        prefix();
        break;

    case 5:
        suffix();

    case 6:
        cout << "chao" << endl;
        break;

    default:
        cout << "Los valores del menu van del 1-6 >:("<<endl;
        break;
    }
}

int showMenu(int menuVal) {
   
        cout << "Menu\n";
        cout << "TEORIA DE AUTOMATAS\n";
        cout << "Opciones:\n";
        cout << "1)Intersección\n";
        cout << "2)Diferencia\n";
        cout << "3)Concatenacion\n";
        cout << "4)Prefijos de una palabra\n";
        cout << "5)Sufijos de una palabra\n";
        cout << "6)Salir del sistema\n";

        cin >> menuVal;
        cout << endl;
        return menuVal;

}

vector<string>createLanguaje() {
    int numPalabras;
    vector<string> palabras;

    cout << "¿Cuántas palabras tiene el lenguaje?";
    cin >> numPalabras;

    cout << "Ingresa las " << numPalabras << " palabras de lenguaje:" << endl;
    for (int i = 0; i < numPalabras; ++i) {
        string palabra;
        cin >> palabra;
        palabras.push_back(palabra);
    }

    return palabras;

}