
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
struct nodo{
    float dato;
    nodo *sig;
}*Inicio=nullptr;

void Insertar(float binario,nodo *&p){
    if(Inicio==nullptr)
{
    nodo *nuevo = new nodo();
    nuevo->dato=binario;
    nuevo->sig= nullptr;
    Inicio=nuevo;
}
else
{
    if(p->sig==nullptr)
    {
        nodo *nuevo = new nodo();
        nuevo->dato= binario;
        nuevo->sig= nullptr;
        p->sig = nuevo;
        return;
    }
    else
     {
    Insertar(binario,p->sig);
     }
}
}
void transformar(void){
   int numero;
   cout << "Introduce numeros y presiona Ctrl+D para terminar"<<endl;
   while(cin >> numero)
   {
   int digito;
   int exp=0;
   float binario=0;
   while(numero/2!=0)
   {
           digito = numero % 2;
           binario = binario + digito * pow(10.0,exp);
           exp++;
           numero=numero/2;
   }
   binario = binario + numero * pow(10.0,exp);
   Insertar(binario,Inicio);
   }
   return;
}
void mostrar(nodo *&p)
{
if(p->sig==nullptr)
{
 cout << fixed << setprecision(0);
 cout<<p->dato<<endl;
 return;
}
else
{
 cout << fixed << setprecision(0);
 cout<< p->dato<<" ";
 mostrar(p->sig);
 
}
}
int main()
{
    char resp;
    cout<<"Deseas insertar numeros?(s/n)"<<endl;
    cin>>resp;
            
    if(resp=='s'){
        transformar();
    }
    cout<<endl<<"Los números que insertaste en base diez son los siguientes en base binaria"<<endl;
    mostrar(Inicio);
        
}