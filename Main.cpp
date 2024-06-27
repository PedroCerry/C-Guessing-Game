#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main (){    
    cout <<"*************************************" << endl;
    cout <<"* Bem Vindos ao jogo da adivinhacao *" << endl;
    cout <<"*************************************" << endl;

    cout << "Escolha seu nivel de dificuldade :" << endl;
    cout << "Facil (F), Medido (M) ou Dificil (D)" << endl;

    char dificuldade;
    cin >> dificuldade;

    int ntentativas;
    
    if(dificuldade == 'F'){
        ntentativas = 15;
    }
    else if (dificuldade == 'M'){
        ntentativas = 10;
    }
    else{
        ntentativas = 5;
    }

    srand(time(NULL)); // ou time(0)
    const int NUMERO_SECRETO = rand() % 100; // Valor aleatorio 

    bool nao_acertou = true;
    int tentativa = 0;

    double pontos = 1000.0;

    for(tentativa = 1; tentativa <= ntentativas; tentativa++){
        int chute; 
        cout << "Tentativa: " << tentativa << endl;
        cout << "Qual e seu chute: ";
        cin >> chute;

        double pontosperdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos = pontos - pontosperdidos;

        cout << "O valor do seu chute e: " << chute << endl;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO; 

        if (acertou) {
            cout << "Acertou" << endl;
            nao_acertou = false;
            break;
        }
        else if (maior) {
            cout << "Seu chute foi maior" << endl;
        }
        else {
            cout << "Seu chute foi menor" << endl;
        };

    };

    if (nao_acertou){
        cout << "Voce perdeu, numero de tentativas exedido" << endl;
    }
    else{
        cout << "Fim de Jogo, voce acertou em " << tentativa << " tentaivas" << endl;
        cout.precision(2); //Setar casas decimais
        cout << fixed; //Fixar virgula, para que não seja mostrado numero em notação
        cout << "Sua pontuacao foi de " << pontos << " pontos" << endl;
    }
    
   
}

