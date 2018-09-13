#ifndef _LOJA_H_
#define _LOJA_H_

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Produto
{
private:
    string nome;
    double preco;
public:
    inline Produto(const char *N="", unsigned P=0): nome(N), preco(P) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
};
inline istream &operator>>(istream &I, Produto &X) {return X.digitar(I);}
inline ostream &operator<<(ostream &O, Produto &X) {return X.imprimir(O);}

// =========================================
// Inclua aqui as classes Livro, CD e DVD
class Livro: public Produto
{
private:
    string autor;
public:
    inline Livro(const char *N="", unsigned P=0, const char *A=""): Produto (N,P), autor(A) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
};
inline istream &operator>>(istream &I, Livro &X) {return X.digitar(I);}
inline ostream &operator<<(ostream &O, Livro &X) {return X.imprimir(O);}

class CD: public Produto
{
private:
    unsigned Nfaixa;
public:
    inline CD(const char *N="", unsigned P=0, unsigned F=0): Produto (N,P), Nfaixa(F) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
};
inline istream &operator>>(istream &I, CD &X) {return X.digitar(I);}
inline ostream &operator<<(ostream &O, CD &X) {return X.imprimir(O);}

class DVD: public Produto
{
private:
    unsigned Duracao;
public:
    inline DVD(const char *N="", unsigned P=0, unsigned D=0): Produto (N,P), Duracao(D) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
};

inline istream &operator>>(istream &I, DVD &X) {return X.digitar(I);}
inline ostream &operator<<(ostream &O, DVD &X) {return X.imprimir(O);}
// =========================================

class ListaLivro
{
private:
    Livro *x;
    unsigned N;
    void criar(unsigned L);
    void copiar(const ListaLivro &L);
    void limpar();
public:
    // Inclua os construtores, destrutor e operadores necessarios
    inline unsigned getsize() const{ return N;}
    inline ListaLivro():x(nullptr), N(0){}
    inline ListaLivro(const ListaLivro &L){copiar(L);}
    ~ListaLivro(){limpar();}
    inline void operator=(const ListaLivro &L){if (this!=&L) {limpar(); copiar(L);}}
    void incluir(const Livro &L);
    void excluir(unsigned id);
    ostream &imprimir(ostream &O) const;
    void ler(istream &I);
    void salvar(ostream &O) const;
};

// =========================================
// Inclua aqui as classes ListaCD e ListaDVD

class ListaCD
{
private:
    CD *x;
    unsigned N;
    void criar(unsigned C);
    void copiar(const ListaCD &C);
    void limpar();
public:
    inline unsigned getsize() const{ return N;}
    inline ListaCD():x(nullptr), N(0){}
    inline ListaCD(const ListaCD &L){copiar(L);}
    ~ListaCD(){limpar();}
    inline void operator=(const ListaCD &L){if (this!=&L) {limpar(); copiar(L);}}
    void incluir(const CD &L);
    void excluir(unsigned id);
    ostream &imprimir(ostream &O) const;
    void ler(istream &I);
    void  salvar(ostream &O) const;
};

class ListaDVD
{
private:
    DVD *x;
    unsigned N;
    void criar(unsigned D);
    void copiar(const ListaDVD &D);
    void limpar();
public:
    inline unsigned getsize() const{ return N;}
    inline ListaDVD():x(nullptr), N(0){}
    inline ListaDVD(const ListaDVD &L){copiar(L);}
    ~ListaDVD(){limpar();}
    inline void operator=(const ListaDVD &L){if (this!=&L) {limpar(); copiar(L);}}
    void incluir(const DVD &L);
    void excluir(unsigned id);
    ostream &imprimir(ostream &O) const;
    void ler(istream &I);
    void  salvar(ostream &O) const;
};
// =========================================

class Loja
{
private:
    ListaLivro LL;
    ListaCD LC;
    ListaDVD LD;
public:
    inline Loja(): LL(), LC(), LD() {}
    inline void incluirLivro(const Livro &X) {LL.incluir(X);}
    inline void excluirLivro(unsigned id) {LL.excluir(id);}
    inline void incluirDVD(const DVD &X) {LD.incluir(X);}
    inline void excluirDVD(unsigned id) {LD.excluir(id);}
    inline void incluirCD(const CD &X) {LC.incluir(X);}
    inline void excluirCD(unsigned id) {LC.excluir(id);}
    void imprimir(ostream &O) const;
    void ler(const char* arq);
    void salvar(const char* arq) const;
};
#endif // _LOJA_H_

