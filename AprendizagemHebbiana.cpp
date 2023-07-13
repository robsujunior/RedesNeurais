#include <iostream>
#include <iomanip>
#include <math.h>
#include <locale.h>
using namespace std;

double rostos[4][10] = {
    {+1, -1, -1, +1, -1, +1, +1, -1, -1, +1},
    {+1, -1, -1, -1, +1, -1, +1, -1, +1, +1},
    {+1, +1, -1, -1, -1, +1, +1, -1, +1, -1},
    {-1, -1, -1, +1, -1, +1, +1, +1, -1, +1} 
};
double aprendiz[4][4];
double lembranca[4][10];
double cossenoN[10];
double cossenoD[10];
double cossenoD2[10];
double qualidade[10];
double soma = 0;

void ensinarostos();
void lembrarostos();
void calculacossenoN();
void calculacossenoD();
void imprimirrostos();
void imprimiraprendiz();
void imprimirl();
void imprimircosseno();
void qualidaderesposta();

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");
    int escolha = -1;
    ensinarostos();
    lembrarostos();
    calculacossenoN();
    calculacossenoD();


    do{
        cout << "Escolha uma opção:" << endl;
        cout << "1 - Imprime a matriz referente aos rostos" << endl;
        cout << "2 - Imprime a matriz com os rostos armazenados" << endl;
        cout << "3 - Imprime a matriz após ser feita a lembraça dos rostos" << endl;
        cout << "4 - Imprime os vetores responsáveis pelo cálculo do cosseno" << endl;
        cout << "5 - Mostra a qualidade de resposta da rede neural para cada rosto aprendido" << endl;
        cout << "0 - Encerra o programa" << endl;
        cin >> escolha;
        system("cls");

        switch (escolha)
        {
            case 0:
                cout << "Programa encerrado";
                break;

            case 1:
                imprimirrostos();
                system("pause");
                system("cls");
                break;

            case 2:
                imprimiraprendiz();
                system("pause");
                system("cls");
                break;
        
            case 3: 
                imprimirl();
                system("pause");
                system("cls");
                break;

            case 4:
                imprimircosseno();
                system("pause");
                system("cls");
                break;

            case 5:
                qualidaderesposta();
                system("pause");
                system("cls");
                break;

            default:
                cout << "Opção inválida\n";
                system("pause");
                system("cls");
                break;
        }


    }while(escolha != 0);

    

    return 0;
}

void ensinarostos(){

    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++)
        {
            aprendiz[i][j] = 0;
            for(int k = 0; k < 10; k++){
                aprendiz[i][j] += rostos[i][k] * rostos[j][k];
            }
        }
        
    }
}

void lembrarostos(){
    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 10; j++)
        {
            lembranca[i][j] = 0;
            for(int k = 0; k < 4; k++){
                lembranca[i][j] += aprendiz[i][k] * rostos[k][j];
            }
        }
        
    }
   
}

void calculacossenoN(){
    for(int i = 0 ; i < 10; i++){
        cossenoN[i] = 0;
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 10; j++){
            cossenoN[j] += lembranca[i][j]*rostos[i][j];
        }
    }
}

void calculacossenoD(){
    for(int i = 0 ; i < 10; i++){
        cossenoD[i] = 0;
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 10; j++){
            cossenoD[j] += lembranca[i][j]*lembranca[i][j];
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 10; j++){
            cossenoD2[j] += rostos[i][j]*rostos[i][j];
        }
    }
    for(int i = 0; i < 10; i++){
        cossenoD[i] = sqrt(cossenoD2[i]) * sqrt(cossenoD[i]);
    }
}

void imprimirrostos(){
    cout << "Matriz referente aos rostos que serão aprendidos:\n";
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 10; j++){
            cout << setw(4) << fixed << setprecision(0) << rostos[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void imprimiraprendiz(){
    cout << "Matriz com os rostos armazenados:\n";

    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cout << setw(5) << fixed << setprecision(0) << aprendiz[i][j];
        }
        cout << endl;
    }        
    cout << endl;
}

void imprimirl(){
    cout << "Matriz após ser feita a lembraça dos rostos:\n";

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 10; j++){
            cout << setw(8) << fixed << setprecision(0) << lembranca[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void imprimircosseno(){
    cout << "Numerador do cálculo do cosseno: \n";

    for(int i = 0; i < 10; i++){
        cout << setw(4) << fixed << setprecision(0)<< cossenoN[i];
    }

    cout << "\n\nDenominador do cálculo do cosseno: \n";

    for(int i = 0; i < 10; i++){
        cout << setw(10) << fixed << setprecision(4) << cossenoD[i];
    }
    cout << endl;

}

void qualidaderesposta(){
    for(int i = 0; i < 10; i++){
        qualidade[i] = cossenoN[i]/cossenoD[i];
        cout << "Qualidade da resposta para o rosto " << i+1 << ": " << fixed << setprecision(4) << qualidade[i] << endl;
        soma += qualidade[i];
    }
    cout << "A média da qualidade de resposta para os 10 rostos é: " << fixed << setprecision(4) << soma/10 << endl;

}