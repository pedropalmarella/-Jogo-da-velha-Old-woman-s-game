#include<iostream>
using namespace std;

int main()
{	
	int linha, coluna;
	linha = coluna = 3;
	char tab[linha][coluna];
	
	//Atribui * a mat
	for (int i = 0; i < linha; i++)
	{
		for (int j = 0; j < coluna; j++)
		{
			tab[i][j] = '*';
		}	
	}
	
	//Imprime a tabela modelo
	cout << "   0    1    2	   <--Y\n";
	for (int i = 0; i < 3; i++)
	{
		cout << i;
		for (int j = 0; j < 3; j++)
		{
			cout << " [" << tab[i][j] << "] ";		
		}
		cout << endl;
	}
	cout <<"\n^\n" << "| X\n\n";
	
	//Código das jogadas do X e O
	int x, y, erroP1, erroP2, vitoria, vitoriaP2, entradaX, entradaY;
	x = y = vitoria = vitoriaP2 = 0;
	erroP1 = erroP2 = entradaX = entradaY = 1;
	
	for (int i = 1; i < 11; i ++)
	{
		if (i%2 != 0)
		{
			while (erroP1 == 1)
			{
				entradaX = entradaY = 1;
				while (entradaX == 1)
				{
					erroP2 = 1;
					cout << "Player 1: Insira a coordenada que deseja preencher com o X. \nEx: para a primeira casa deve-se escolher x = 0 e y = 0\n" 
					<< "Selecione o X da posicao: ";
					cin >> x;
					if (x != 0 && x != 1 && x != 2)
					{
						cout << "-------Erro! Posicao invalida, tente novamente com uma valida.-------\n";
					}
					else
					{
						entradaX--;
					}
				}
				while (entradaY == 1)
				{
					cout << "Player 1: Insira a coordenada que deseja preencher com o X. \nEx: para a primeira casa deve-se escolher x = 0 e y = 0\n" 
					<< "Selecione o Y da posicao: ";
					cin >> y;
					if (y != 0 && y != 1 && y != 2)
					{
						cout << "-------Erro! Posicao invalida, tente novamente com uma valida.-------\n";
					}
					else
					{
						entradaY--;
					}
				}
				if (tab[x][y] == '*')
				{
					tab[x][y] = 'X';
						
					system("cls"); 
					//Imprime Tabela
					cout << "   0    1    2	   <--Y\n";
					for (int i = 0; i < 3; i++)
					{
						cout << i;
						for (int j = 0; j < 3; j++)
						{
							cout << " [" << tab[i][j] << "] ";		
						}
						cout << endl;
					}
					cout <<"\n^\n" << "| X\n\n";
					erroP1--;
				}
				else 
				{
					cout << "\n-------Erro! A posicao ja foi escolhinda, selecione outra.-------\n\n";
				}
			}
		}
		
		//Vitoria vertical
		for (int i = 0; i < coluna; i++)
		{
			vitoria = 0;
			for (int j = 0; j < linha; j++)
			{
				if (tab[j][i] == 'X')
				{
					vitoria++;
				}
				if (vitoria == 3)
				{
					cout << "Vitoria do player 1 do X!";
					return 1;
				}
			}	
		}	
		//Vitoria horizontal
		for (int i = 0; i < linha; i++)
		{
			vitoria = 0;
			for (int j = 0; j < coluna; j++)
			{
				if (tab[i][j] == 'X')
				{
					vitoria++;
				}
				if (vitoria == 3)
				{
					cout << "Vitoria do player 1 do X!";
					return 1;
				}
			}	
		}	
		//Vitoria diagonal 1
		vitoria = 0;
		for (int i = 0; i < coluna; i++)
		{
			for (int j = 0; j < coluna; j++)
			{
				if (i == j)
				{
					if (tab[i][j] == 'X')
					{
						vitoria++;
					}
					if (vitoria == 3)
					{
						cout << "Vitoria do player 1 do X!";
						return 1;
					}
				}
			}	
		}	
		//Vitoria diagonal 2
		for (int i = 0; i < coluna; i++)
		{
			for (int j = 0; j < coluna; j++)
			{
				if (tab[0][2] == 'X' && tab[1][1] == 'X' && tab[2][0] == 'X')
				{
					cout << "Vitoria do player 1 do X!";
					return 1;
					
				}
			}	
		}
		
		//EMPATE
		if (i == 9)
		{
			cout << "Deu velha! (empate)\n";
			return 1;
		}

		//Codigos do jogador 2
		if (i%2 == 0)
		{
			while (erroP2 == 1)
			{
				entradaX = entradaY = 1;
				while (entradaX == 1)
				{
					erroP1 = 1;
					cout << "Player 2: Insira a coordenada que deseja preencher com o O. \nEx: para a primeira casa deve-se escolher x = 0 e y = 0\n" 
					<< "Selecione o X da posicao: ";
					cin >> x;
					if (x != 0 && x != 1 && x != 2)
					{
						cout << "-------Erro! Posicao invalida, tente novamente com uma valida.-------\n";
					}
					else
					{
						entradaX--;
					}
				}		
				while (entradaY == 1)
				{
					cout << "Player 2: Insira a coordenada que deseja preencher com o O. \nEx: para a primeira casa deve-se escolher x = 0 e y = 0\n" 
					<< "Selecione o Y da posicao: ";
					cin >> y;
					if (y != 0 && y != 1 && y != 2)
					{
						cout << "-------Erro! Posicao invalida, tente novamente com uma valida.-------\n";
					}
					else
					{
						entradaY--;
					}
				}
				if (tab[x][y] == '*')
				{
					tab[x][y] = 'O';
						
					system("cls"); 
					//Imprime Tabela
					cout << "   0    1    2	   <--Y\n";
					for (int i = 0; i < 3; i++)
					{
						cout << i;
						for (int j = 0; j < 3; j++)
						{
							cout << " [" << tab[i][j] << "] ";		
						}
						cout << endl;
					}
					cout <<"\n^\n" << "| X\n\n";
					erroP2--;
				}
				else 
				{
					cout << "\n-------Erro! A posicao ja foi escolhinda, selecione outra.-------\n\n";
				}
			}
		}	
		
		//Vitoria vertical
		for (int i = 0; i < coluna; i++)
		{
			vitoriaP2 = 0;
			for (int j = 0; j < linha; j++)
			{
				if (tab[j][i] == 'O')
				{
					vitoriaP2++;
				}
				if (vitoriaP2 == 3)
				{
					cout << "Vitoria do player 2 do O!";
					return 1;
				}
			}	
		}		
		//Vitoria horizontal
		for (int i = 0; i < linha; i++)
		{
			vitoriaP2 = 0;
			for (int j = 0; j < coluna; j++)
			{
				if (tab[i][j] == 'O')
				{
					vitoriaP2++;
				}
				if (vitoriaP2 == 3)
				{
					cout << "Vitoria do player 2 do O!";
					return 1;
				}
			}	
		}	
		//Vitoria diagonal 1
		vitoriaP2 = 0;
		for (int i = 0; i < coluna; i++)
		{
			for (int j = 0; j < coluna; j++)
			{
				if (i == j)
				{
					if (tab[i][j] == 'O')
					{
						vitoriaP2++;
					}
					if (vitoriaP2 == 3)
					{
						cout << "Vitoria do player 2 do O!";
						return 1;
					}
				}
			}	
		}
		//Vitoria diagonal 2
		for (int i = 0; i < coluna; i++)
		{
			for (int j = 0; j < coluna; j++)
			{
				if (tab[0][2] == 'O' && tab[1][1] == 'O' && tab[2][0] == 'O')
				{
					cout << "Vitoria do player 2 do O!";
					return 1;
					
				}
			}	
		}		
	}
	return 0;	
}