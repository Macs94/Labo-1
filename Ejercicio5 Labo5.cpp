#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;






struct Arbol
{
    int Dato;
    Arbol *izq;
    Arbol *der;
}*Inicio=nullptr;

void llenar(int dato, Arbol *&p)
{
if(p==nullptr)
{
    Arbol *nuevo = new Arbol();
    nuevo->Dato=dato;
    nuevo->izq= nullptr;
    nuevo->der= nullptr;
    p=nuevo;
}
else 
{
    
    if(p->Dato<dato){
        if(p->der==nullptr)
    {
        Arbol *nuevo = new Arbol();
        nuevo->Dato= dato;
        nuevo->der= nullptr;
        p->der = nuevo;
        return;
    }
    else
     {
    llenar(dato,p->der);
     }
    }
    

else
{
   if(p->Dato>=dato)
   {
            
    if(p->izq==nullptr)
       {
        Arbol *nuevo = new Arbol();
        nuevo->Dato= dato;
        nuevo->izq= nullptr;
        p->izq = nuevo;
        return;
       }
    else
     {
    llenar(dato,p->izq);
     }
    }
}
}
}
void mostrarPre(Arbol *&a){
    if(a != nullptr){
        cout << " " << a->Dato;
        mostrarPre(a->izq);
        mostrarPre(a->der);
    }
}
void mostrarIn(Arbol *&a){
    if(a != nullptr){
        mostrarIn(a->izq);
        cout << " " << a->Dato;
        mostrarIn(a->der);
    }
}
void mostrarPost(Arbol *&a){
    if(a != NULL){
        mostrarPost(a->izq);
        mostrarPost(a->der);
        cout << " " << a->Dato;
    }
}


struct Lista {
    int num;
    Lista *sig;
    
}*pInicio=nullptr;

void llenarLista(Lista *&p,int dato)
{
{
if(p==nullptr)
{
    Lista *nuevo = new Lista();
    nuevo->num=dato;
    nuevo->sig= nullptr;
    p=nuevo;
}
else
{
    if(p->sig==nullptr)
    {
        Lista *nuevo = new Lista();
        nuevo->num= dato;
        nuevo->sig= nullptr;
        p->sig = nuevo;
        return;
    }
    else
     {
    llenarLista(p->sig,dato);
     }
}
}    
}
void buscar(Arbol *&p , int num)
{
if(p->Dato==num)
{
llenarLista(pInicio, num);
}
else
{
    if(num<p->Dato)
    {
        buscar(p->izq,num);
    }
    else if(num>p->Dato)
    {
        buscar(p->der,num);
    }
}
}

int main(){
    
    int n;
    cout<<"Cuantos elementos en el Arbol? "<<endl;
    cin>>n;
    int random;
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
    random=rand()%100+1;
    llenar(random,Inicio);    
    }
    cout<<"El ABB es el siguiente en postorden: "<<endl;
    mostrarPost(Inicio);
    cout<<"\nEl ABB es el siguiente en preorden: "<<endl;
    mostrarPre(Inicio);
    cout<<"\nEl ABB es el siguiente en inorden: "<<endl;
    mostrarIn(Inicio);
    int numero;
    cout<<"\nIngresa números a buscar y ingresa -1 para terminar: "<<endl;
    while(cin>>numero)
    {
        if(numero==-1){
            
            break;
        }
        else{
            buscar(Inicio,numero);
        }
            
    }
    
    
            

    return 0;
}
