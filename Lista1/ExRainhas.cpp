#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;


bool seguro(vector<vector<int> > & tabuleiro, int n, int lin, int col)
{
	int i, j;

	// verifica se ocorre ataque na linha
	for(i = 0; i < n; i++)
	{
		if(tabuleiro[lin][i] == 1)
			return false;
	}

	//verifica se ocorre ataque na coluna
	for(i = 0; i < n; i++)
	{
		if(tabuleiro[i][col] == 1)
			return false;
	}

	// verifica se ocorre ataque na diagonal principal
	// acima e abaixo
	for(i = lin, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if(tabuleiro[i][j] == 1)
			return false;
	}
	for(i = lin, j = col; i < n && j < n; i++, j++)
	{
		if(tabuleiro[i][j] == 1)
			return false;
	}

	// verifica se ocorre ataque na diagonal secundária
	// acima e abaixo
	for(i = lin, j = col; i >= 0 && j < n; i--, j++)
	{
		if(tabuleiro[i][j] == 1)
			return false;
	}
	for(i = lin, j = col; i < n && j >= 0; i++, j--)
	{
		if(tabuleiro[i][j] == 1)
			return false;
	}

	// se chegou aqui, então está seguro (retorna true)
	return true;
}



void imprimeTabuleiro(vector<vector<int> > & tabuleiro, int n)
{
    for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(tabuleiro[i][j] == 1)
				cout << "O\t";
			else
				cout << "-\t";
		}
		cout << "\n\n";
	}
	cout << "\n";
}

void executar(vector<vector<int> > & tabuleiro, int n, int col)
{
	if(col == n)
	{
		//cout << "Solucao " << col + 1 << ":\n\n";
		imprimeTabuleiro(tabuleiro, n);
		//sol++;
		return;
	}

	for(int i = 0; i < n; i++)
	{
		// verifica se é seguro colocar a rainha naquela coluna
		if(seguro(tabuleiro, n, i, col))
		{
			// insere a rainha (marca com 1)
			tabuleiro[i][col] = 1;

			// chamada recursiva
			executar(tabuleiro, n, col + 1);

			// remove a rainha (backtracking)
			tabuleiro[i][col] = 0;
		}
	}
}

int main()
{
    int i, j, m, n, x, y;

	vector<vector<int> > tabuleiro;
    

    cout << "Insira o seu N" << endl;
    cin >> n;
    i = n;
    j = n;

    for(int i = 0; i < n; i++)
	{
		vector<int> linha(n);
		tabuleiro.push_back(linha);
	}
    executar(tabuleiro, n, 0);

    
    
    cout << "Finalizando" << endl;

    return 0;
}

