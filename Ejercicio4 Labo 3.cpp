/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio4.cpp
 * Author: uca
 *
 * Created on 8 de octubre de 2019, 11:53
 */

#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

/*
 * 
 */
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
int sumaPares(Lista *&p)
{
   
    if(p->sig==nullptr)
    {
     if(p->Dato%2==0)
     {
     return p->Dato;    
     } 
     else return 0;
    }
    else
    {
        if(p->Dato%2==0)
        {
        return p->Dato+sumaPares(p->sig);    
        }
        else
        {
         return sumaPares(p->sig);   
        }
    }
}
int sumaImpares(Lista *&p)
{
   
    if(p->sig==nullptr)
    {
     if(p->Dato%2!=0)
     {
     return p->Dato;    
     } 
     else return 0;
    }
    else
    {
        if(p->Dato%2!=0)
        {
        return p->Dato+sumaImpares(p->sig);    
        }
        else
        {
         return sumaImpares(p->sig);   
        }
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
    cout<<"La suma de los pares es: "<<endl;
    cout<<sumaPares(Inicio)<<endl;
    cout<<"La suma de los impares es: "<<endl;
    cout<<sumaImpares(Inicio)<<endl;
           

    return 0;
}

