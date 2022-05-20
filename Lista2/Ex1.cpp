#include <iostream>

using namespace std;

struct Valores{
    char x;
    char y;
};

void montaStruct(struct Valores *valores)
{
    FILE *arq;
    char linha[100], ch;
    char *result;
    int i=1, vlinha=0;

    arq = fopen("C:\\Projetos\\Arquivos\\g1.txt", "rt");

    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
    }
    else
    {
        cout << "Arquivo aberto!" << endl;
    }

    
    while( (ch=fgetc(arq)) !=  EOF )
    {
        
        if(ch != '\n' && ch != ';')
        {
            if (i%2 != 0)
            {
                valores[vlinha].x = ch;
                cout << valores[vlinha].x;
                i++;
            }else{
                valores[vlinha].y = ch;
                i++;
                cout << valores[vlinha].y;
            }
        }else if(ch == '\n'){
            cout << endl;
            vlinha++;
        }
    }   

    cout << "saiu";
   
    

    fclose(arq);
}

int main()
{
    struct Valores valores[21];

    montaStruct(valores);
    

     int j;
    for (j = 0; j <= 21; j++)
    {
        cout << "Linha " << j << ":" << valores[j].x << "," << valores[j].y << endl;;
    }


    return 0;
}