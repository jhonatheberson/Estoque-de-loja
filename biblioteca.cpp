#include <iostream>
#include <string>
#include <limits>
#include "biblioteca.h"
#include <stdint.h>
#include <fstream>
#include <cmath>

using namespace std;

istream &Produto::digitar(istream &I)
{
    I.ignore(numeric_limits<streamsize>::max(), '\n');
    double prov;
    cout << "Digite o nome do produto: ";
    getline(I,nome,'\n'); //  getline(cin, nome, '\n')
    cout << "Digite o valor do preço do produto em R$: ";
    I >> prov;
    preco = prov*100;
    return I;
}

ostream &Produto::imprimir(ostream &O) const
{
    double prov;
    prov = preco/100.00;
    O << '"' << nome <<'"' << ";$" << prov;
    return O;
}

istream &Produto::ler(istream &I)
{
    double prov;
    I.ignore(numeric_limits<streamsize>::max(), '"');
    getline(I, nome,'"');
    I.ignore(numeric_limits<streamsize>::max(), '$');
    I >> prov;
    preco = (int)(prov*100);
    return I;
}

istream &Livro::digitar(istream &I)
{
    Produto::digitar(I);
    I.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Autor: ";
    getline(I,autor,'\n');
    return I;
}

ostream &Livro::imprimir(ostream &O) const
{
    O << "L: ";
    Produto::imprimir(O);
    O << ';' << '"' << autor <<'"' << endl;
    return O;
}

istream &Livro::ler(istream &I)
{
    Produto::ler(I);
    I.ignore(numeric_limits<streamsize>::max(), '"');
    getline(I,autor,'"');
    return I;
}

istream &CD::digitar(istream &I)
{
    Produto::digitar(I);
    I.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Faixa: ";
    I >> Nfaixa;
    I.ignore(numeric_limits<streamsize>::max(), '\n');
    return I;
}

ostream &CD::imprimir(ostream &O) const
{
    O << "C: ";
    Produto::imprimir(O);
    O << ';' << Nfaixa << endl;
    return O;
}

istream &CD::ler(istream &I)
{
    Produto::ler(I);
    I.ignore(numeric_limits<streamsize>::max(), ';');
    I >> Nfaixa;
    return I;
}

istream &DVD::digitar(istream &I)
{
    Produto::digitar(I);
    I.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Duração: ";
    I >> Duracao;
    return I;
}

ostream &DVD::imprimir(ostream &O) const
{
    O << "D: ";
    Produto::imprimir(O);
    O << ';' << Duracao << endl;
    return O;
}

istream &DVD::ler(istream &I)
{
    Produto::ler(I);
    I.ignore(numeric_limits<streamsize>::max(), ';');
    I >> Duracao;
    return I;
}

void ListaLivro::criar(unsigned L)
{
    // Essa funcao soh deve ser chamada sozinha se vc tiver certeza que o objeto estah vazio
    // Por exemplo, em um construtor.
    // Caso nao tenha certeza, deve ser chamada primeiro a funcao limpar
    if (L == 0)
    {
            L = 0;
            x = NULL;
            return;
    }
    x = new Livro [L];
}

void ListaLivro::copiar(const ListaLivro &L)
{
    // Essa funcao soh deve ser chamada sozinha se vc tiver certeza que o objeto estah vazio
    // Por exemplo, em um construtor.
    // Caso nao tenha certeza, deve ser chamada primeiro a funcao limpar
    criar(L.N);
    for (unsigned i=0; i<N; i++)
    {
            x[i] = L.x[i];
    }
}

void ListaLivro::limpar()
{
    if (x!=NULL)
    {
            delete[] x;
    }
    N = 0;
    x = NULL;
}

void ListaCD::criar(unsigned C)
{
    // Essa funcao soh deve ser chamada sozinha se vc tiver certeza que o objeto estah vazio
    // Por exemplo, em um construtor.
    // Caso nao tenha certeza, deve ser chamada primeiro a funcao limpar
    if (C == 0)
    {
            C = 0;
            x = NULL;
            return;
    }
    x = new CD [C];
}

void ListaCD::copiar(const ListaCD &C)
{
    // Essa funcao soh deve ser chamada sozinha se vc tiver certeza que o objeto estah vazio
    // Por exemplo, em um construtor.
    // Caso nao tenha certeza, deve ser chamada primeiro a funcao limpar
    criar(C.N);
    for (unsigned i=0; i<N; i++)
    {
            x[i] = C.x[i];
    }
}

void ListaCD::limpar()
{
    if (x!=NULL)
    {
            delete[] x;
    }
    N = 0;
    x = NULL;
}

void ListaDVD::criar(unsigned D)
{
    // Essa funcao soh deve ser chamada sozinha se vc tiver certeza que o objeto estah vazio
    // Por exemplo, em um construtor.
    // Caso nao tenha certeza, deve ser chamada primeiro a funcao limpar
    if (D == 0)
    {
            D = 0;
            x = NULL;
            return;
    }
    x = new DVD [D];
}
void ListaDVD::copiar(const ListaDVD &D)
{
    // Essa funcao soh deve ser chamada sozinha se vc tiver certeza que o objeto estah vazio
    // Por exemplo, em um construtor.
    // Caso nao tenha certeza, deve ser chamada primeiro a funcao limpar
    criar(D.N);
    for (unsigned i=0; i<N; i++)
    {
            x[i] = D.x[i];
    }
}

void ListaDVD::limpar()
{
    if (x!=NULL)
    {
            delete[] x;
    }
    N = 0;
    x = NULL;
}

void ListaLivro::incluir(const Livro &L)
{
    Livro *prov;
    prov = new Livro [N+1];
    for (unsigned i=0; i<N; i++)
    {
            prov[i] = x[i];
    }
    prov[N] = L;
    if(x!= NULL)
    {
            delete [] x;
    }
    N++;
    x = prov;
    cout << endl;
}

void ListaLivro::excluir(unsigned id)
{
    if(id >= N || id < 0)
    {
        cerr << "Indice invalido" << endl;
    }
    else
    {
        Livro *prov;
        prov = new Livro[N-1];
        for (unsigned i=0; i<id; i++)
        {
                 prov[i] = x[i];
        }
        for (unsigned i=id; i<N-1; i++)
        {
                prov[i] = x[i+1];
        }
        if(x != NULL) delete [] x;
        N--;
        x = prov;
    }
    cout << endl;
}

ostream &ListaLivro::imprimir(ostream &O) const
{
    O  << "LISTALIVRO " << N << endl;
    for(unsigned i = 0; i < N; i++)
    {
        O << i << ") ";
        x[i].imprimir(O);
    }
    return O;
}

void ListaLivro::ler(istream &I)
{
    I >> N;
    x = (N ==0? NULL : new Livro[N]);
    for (unsigned i=0; i<N; i++)
    {
        x[i].ler(I);
    }
}

void  ListaLivro::salvar(ostream &O) const
{
    O << "LISTALIVRO " << N << endl;
    for (unsigned i=0; i<N; i++)
    {
            x[i].salvar(O);
    }
}

void ListaCD::incluir(const CD &L)
{
    CD *prov;
    prov = new CD [N+1];
    for (unsigned i=0; i<N; i++)
    {
            prov[i] = x[i];
    }
    prov[N] = L;
    delete [] x;
    N++;
    x = prov;
    cout << endl;
}

void ListaCD::excluir(unsigned id)
{
    if(id >= N || id < 0)
    {
        cerr << "Indice invalido" << endl;
    }
    else
    {
        CD *prov;
        prov = new CD[N-1];
        for (unsigned i=0; i<id; i++)
        {
                 prov[i] = x[i];
        }
        for (unsigned i=id; i<N-1; i++)
        {
                prov[i] = x[i+1];
        }
        if(x != NULL) delete [] x;
        N--;
        x = prov;
    }
    cout << endl;

}

ostream &ListaCD::imprimir(ostream &O) const
{
    O  << "LISTALCD " << N << endl;
    for(unsigned i = 0; i < N; i++){
            O << i << ") ";
            x[i].imprimir(O);
    }
    return O;
}

void ListaCD::ler(istream &I)
{
    I >> N;
    x = (N ==0? NULL : new CD[N]);
    for (unsigned i=0; i<N; i++)
    {
            x[i].ler(I);
    }
}

void  ListaCD::salvar(ostream &O) const
 {
    O << "LISTACD " << N << endl;
    for (unsigned i=0; i<N; i++)
    {
            x[i].salvar(O);
    }
}

void ListaDVD::incluir(const DVD &L)
{
    DVD *prov;
    prov = new DVD [N+1];
    for (unsigned i=0; i<N; i++)
    {
       prov[i] = x[i];
    }
    prov[N] = L;
    delete [] x;
    N++;
    x = prov;
    cout << endl;
}

void ListaDVD::excluir(unsigned id)
{
    if(id >= N || id < 0)
    {
        cerr << "Indice invalido" << endl;
    }
    else
    {
        DVD *prov;
        prov = new DVD[N-1];
        for (unsigned i=0; i<id; i++)
        {
                 prov[i] = x[i];
        }
        for (unsigned i=id; i<N-1; i++)
        {
                prov[i] = x[i+1];
        }
        if(x != NULL) delete [] x;
        N--;
        x = prov;
    }
    cout << endl;
}

ostream &ListaDVD::imprimir(ostream &O) const
{
    O  << "LISTALDVD " << N << endl;
    for(unsigned i = 0; i < N; i++)
    {
            O << i << ") ";
            x[i].imprimir(O);

    }
}

void ListaDVD::ler(istream &I)
{
    I >> N;
    x = (N ==0? NULL : new DVD[N]);
    for (unsigned i=0; i<N; i++)
    {
            x[i].ler(I);
    }
}

void  ListaDVD::salvar(ostream &O) const
 {
    O << "LISTADVD " << N << endl;
    for (unsigned i=0; i<N; i++)
    {
            x[i].salvar(O);
    }
}

void Loja::imprimir(ostream &O) const
{
   LL.imprimir(O);
   LC.imprimir(O);
   LD.imprimir(O);
   cout << endl;
}

void Loja::ler(const char* arq)
{
    unsigned N;
    ifstream I(arq);
    if (I.is_open())
    {
        string prov;
        I >> prov;
        if(prov != "LISTALIVRO")
        {
            cerr << "Arquivo invalido(listaLIVRO)\n";
            return;
        }
        else
        {
            LL.ler(I);
            I >> prov;
            if(prov != "LISTACD")
            {
                cerr << "Arquivo invalido(listaCD)\n";
                N = LL.getsize();
                for(unsigned i =0; i<N; i++) excluirLivro(0);
                return;
            }
            else
            {
                LC.ler(I);
                I >> prov;
                if(prov != "LISTADVD")
                {
                    cerr << "Arquivo invalido(listaDVD)\n";
                    N = LL.getsize();
                    for(unsigned i = 0; i < N; i++) excluirLivro(0);
                    N = LC.getsize();
                    for(unsigned i = 0; i < N; i++) excluirCD(0);
                    return;

                }
                else
                {
                    LD.ler(I);
                    cout << "Arquivo lido com sucesso.\n";
                }
            }
        }
        I.close();


    }
    else
    {
        cerr << "Arquivo invalido";
    }
    cout << endl;
}
void Loja::salvar(const char* arq) const
{
    ofstream O(arq);
    if(O.is_open())
    {
        LL.salvar(O);
        LC.salvar(O);
        LD.salvar(O);
    }
    cout << "arquivo salvado com sucesso\n" << endl;
}




