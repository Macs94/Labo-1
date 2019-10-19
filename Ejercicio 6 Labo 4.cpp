#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;






struct Lista
{
    int Dato;
    Lista *sig;
}*Inicio=nullptr,*InicioI = nullptr,*InicioP=nullptr;

void llenar(int dato, Lista *&p)
{
if(p==nullptr)
{
    Lista *nuevo = new Lista();
    nuevo->Dato=dato;
    nuevo->sig= nullptr;
    p=nuevo;
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
void mostrarP (Lista *&q)
{
if(q->sig==nullptr)
{
 cout<<q->Dato<<endl;
 return;
}
else
{
 cout<< q->Dato<<" ";
 mostrarP(q->sig);
 
}    
}
void mostrarI(Lista *&r)
{
if(r->sig==nullptr)
{
 cout<<r->Dato<<endl;
 return;
}
else
{
 cout<< r->Dato<<" ";
 mostrarI(r->sig);
 
}
}
void llenarIyP(Lista*&p,Lista *&q, Lista *&r)
{
   
    
    if (p != nullptr)
    {
        if (p->Dato % 2 == 0)
        {
            llenar(p->Dato, q);
            
            llenarIyP(p->sig, q->sig, r);
        }
        else
        {
            llenar(p->Dato, r);
            
            llenarIyP(p->sig, q, r->sig);
        }
     while(p!=nullptr)
     {
      Lista *temp=p;
      p=temp->sig;
      delete p;
              
     }   
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
    llenar(random,Inicio);    
    }
    cout<<"La lista es: "<<endl;
    mostrar(Inicio);
    llenarIyP(Inicio,InicioP,InicioI);
    cout<<"La lista de pares es: "<<endl;
    mostrarP(InicioP);
    cout<<"La lista de impares es: "<<endl;
    mostrarI(InicioI);
    cout<<"La lista inicial es: "<<endl;
    mostrar(Inicio);
            

    return 0;
}