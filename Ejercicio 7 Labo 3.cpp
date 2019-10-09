/* File:   Ejercicio 7.cpp
 * Author: funda
 *
 */// Created on 8 de octubre de 2019, 06:13 PM
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;


struct Lista
{
    int Dato;
    Lista *sig;
}*Inicio=nullptr;

void llenar(int dato, Lista *&p)
{
if(Inicio==nullptr)
{
    Lista *nuevo = new Lista();
    nuevo->Dato=dato;
    nuevo->sig= nullptr;
    Inicio=nuevo;
}
else
{
    if(p->sig==nullptr)
    {
        Lista *nuevo = new Lista();
        nuevo->Dato= dato;
        nuevo->sig= nullptr;
        p->sig = nuevo;
        return;
    }
    else
     {
    llenar(dato,p->sig);
     }
}
}
void mostrar(Lista *&p)
{
if(p->sig==nullptr)
{
 cout<<p->Dato<<endl;
 return;
}
else
{
 cout<< p->Dato<<" ";
 mostrar(p->sig);
 
}
}
void eliminar (Lista *&p, int elim)
{   
    Lista *temp;
    Lista *q = nullptr;
    temp = p;
    while((temp!=nullptr) && (temp->Dato != elim))
    {
        q = temp;
        temp = temp->sig;
    }
    if(temp== nullptr)
    {
    cout<<"El elemento no esta en la lista."<<endl;
    
    }
    else if(q== nullptr)
    {
        p=p->sig;
        delete temp;
    }
    else
    {
    q->sig = temp->sig;
    delete temp;
    }
    
 }




int main() 
{
    int n;
    cout<<"Cuantos elementos en la lista? "<<endl;
    cin>>n;
    int random;
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
    random=rand()%100+1;
    llenar(random,Inicio);    
    }
    cout<<"La lista es: "<<endl;
    mostrar(Inicio);
    int elim;
    cout<<"Que elemento desea eliminar ?"<<endl;
    cin>>elim;
    eliminar(Inicio,elim);
    cout<<"La lista es: "<<endl;
    mostrar(Inicio);

    return 0;
}