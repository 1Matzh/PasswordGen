#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class GeradorDeSenhas {
public:
    GeradorDeSenhas() {
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    // Função que gera uma senha baseada em um conjunto de caracteres.
    string GerarSenha(int comprimento, bool incluirLetrasMaiusculas, bool incluirLetrasMinusculas, bool incluirNumeros, bool incluirCaracteresEspeciais) {
        string caracteres;
        if (incluirLetrasMaiusculas)
            caracteres += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if (incluirLetrasMinusculas)
            caracteres += "abcdefghijklmnopqrstuvwxyz";
        if (incluirNumeros)
            caracteres += "0123456789";
        if (incluirCaracteresEspeciais)
            caracteres += "!@#$%^&*()_+-=[]{}|;:,.<>?";

        if (caracteres.empty()) {
            return "Erro: Nenhum conjunto de caracteres selecionado.";
        }

        // Gera a senha com base nos caracteres selecionados.
        string senha;
        for (int i = 0; i < comprimento; i++) {
            int indice = rand() % caracteres.size();
            senha += caracteres[indice];
        }

        return senha;
    }
};



 // Função principal que gera uma senha baseada em entrada do usuário.
int main() {
    GeradorDeSenhas gerador;

    int comprimento;
    bool incluirLetrasMaiusculas, incluirLetrasMinusculas, incluirNumeros, incluirCaracteresEspeciais;

    cout << "Comprimento da senha: ";
    cin >> comprimento;

    cout << "Incluir letras maiusculas (1/0): ";
    cin >> incluirLetrasMaiusculas;

    cout << "Incluir letras minusculas (1/0): ";
    cin >> incluirLetrasMinusculas;

    cout << "Incluir numeros (1/0): ";
    cin >> incluirNumeros;

    cout << "Incluir caracteres especiais (1/0): ";
    cin >> incluirCaracteresEspeciais;

    string senha = gerador.GerarSenha(comprimento, incluirLetrasMaiusculas, incluirLetrasMinusculas, incluirNumeros, incluirCaracteresEspeciais);

    if (senha.substr(0, 5) == "Erro:") {
        cout << senha << endl;
    } else {
        cout << "Senha gerada: " << senha << endl;
    }

    system("pause"); // Pausa o programa antes de encerrar

    return 0;
}
