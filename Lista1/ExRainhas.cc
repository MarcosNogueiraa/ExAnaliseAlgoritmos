#include <iostream>
#include <stdlib.h>

using namespace std;



void imprimeTabuleiro(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << " -";

        cout << endl;
    }
}

void insereRainhas(int **tabuleiro)
{
    cout << "Entrou" << endl;
}

int main()
{
    int i, j, m, n, x, y;
    int tabuleiro[i][j];
    int rainhas[m][n];
    int alcanceRainha[x][y];

    cout << "Insira o seu N" << endl;
    cin >> n;
    i = n;
    j = n;

    insereRainhas(tabuleiro);

    imprimeTabuleiro(n);
    cout << "Finalizando" << endl;

    return 0;
}

