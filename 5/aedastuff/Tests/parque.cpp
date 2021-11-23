#include "parque.h"
#include <vector>
#include <iostream>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot,unsigned int nMaxCli): lotacao(lot),numMaximoClientes(nMaxCli)
{
    vector<InfoCartao> b;
    this-> clientes = b;
    vagas = lot;
}
unsigned ParqueEstacionamento::getNumLugares() const{
    return lotacao;
}
unsigned ParqueEstacionamento::getNumMaximoClientes() const{
    return numMaximoClientes;
}
int ParqueEstacionamento::posicaoCliente(const string & nome) const{
    for(auto it = clientes.begin();it != clientes.end() ; it++){
        if(it->nome == nome){
            return it - clientes.begin();
        }
    }
    return -1;

}
bool ParqueEstacionamento::adicionaCliente(const string & nome){
    if(numMaximoClientes == clientes.size()){
        return false;
    }

    if(posicaoCliente(nome) != -1){
        return false;
    }

    InfoCartao p;
    p.nome = nome;
    p.presente = false;
    clientes.push_back(p);
    return true;
}
bool ParqueEstacionamento::entrar(const string & nome){
    const int p = posicaoCliente(nome);
    if( p == -1){
        return false;
    }
    else if(clientes[p].presente == true){
        return false;
    }
    else if(vagas == 0){
        return false;
    }
    else{
        clientes[p].presente = true;
        vagas--;
        return true;
    }
}
bool ParqueEstacionamento::retiraCliente(const string & nome){
    const int p = posicaoCliente(nome);
    if( p == -1){
        return false;
    }
    else if(clientes[p].presente == true){
        return false;
    }
    clientes.erase(clientes.begin()+p);
    return true;
}
bool ParqueEstacionamento::sair(const string & nome){
    const int p = posicaoCliente(nome);
    if( p == -1){
        return false;
    }
    else if(clientes[p].presente == false){
        return false;
    }
    clientes[p].presente =false;
    vagas++;
    return true;
}
unsigned ParqueEstacionamento::getNumLugaresOcupados() const{
    return lotacao-vagas;
}
unsigned ParqueEstacionamento::getNumClientesAtuais() const{
    return clientes.size();
}