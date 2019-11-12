#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

struct Lista {
    int num;
    Lista *sig;
    
}*pInicio=nullptr;

struct Arbol
{
    int Dato;
    Arbol *izq;
    Arbol *der;
}*Inicio=nullptr;

void llenarArbol(int dato, Arbol *&p)
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
    llenarArbol(dato,p->der);
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
    llenarArbol(dato,p->izq);
     }
    }
}
}
}

void mostrarIn(Arbol *&a){
    if(a != nullptr){
        mostrarIn(a->izq);
        cout << " " << a->Dato;
        mostrarIn(a->der);
    }
}
void llenarLista(Lista *&p,int dato)
{
{
if(p==nullptr)
{
    Lista *nuevo = new Lista();
    nuevo->num=dato;
    nuevo->sig= nullptr;
    p=nuevo;
    cout<<"El primer dato ha sido ingresado"<<endl;
}
else
{
    if(p->sig==nullptr)
    {
        Lista *nuevo = new Lista();
        nuevo->num= dato;
        nuevo->sig= nullptr;
        p->sig = nuevo;
        cout<<"El dato ha sido ingresado correctamente"<<endl;
        return;
    }
    else
    {
    llenarLista(p->sig,dato);    
    }
}
}    
}



void mostrarLista(Lista *&p)
{

if(p==nullptr)
{
    return;
 
}
else
{
 
 cout<< p->num<<" ";
 llenarArbol(p->num,Inicio);
 Lista *temp=p;
 p=p->sig;
 free(temp);        
 mostrarLista(p);
 

}
}
int main(){
    
    int n;
    cout<<"Cuantos elementos en la lista? "<<endl;
    cin>>n;
    int random;
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
    random=rand()%100+1;
    llenarLista(pInicio,random);    
    }
    cout<<"La lista es: "<<endl;
    mostrarLista(pInicio);
    cout<<"\nEl ABB es el siguiente en inorden: "<<endl;
    mostrarIn(Inicio);
    cout<<endl<<"La lista es: "<<endl;
    mostrarLista(pInicio);
     
            

    return 0;
}

