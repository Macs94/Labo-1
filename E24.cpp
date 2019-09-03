/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: uca
 *
 * Created on 3 de septiembre de 2019, 11:47
 */

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

/*
 * 
 */

struct complejo
{
    float real;
    float imag;
};

void restacomplejos (complejo,complejo);

int main(void) {
    complejo n,m;
    cout<<"Digite la parte real e imaginaria del primer numero complejo"<<endl;
    cin>>n.real>>n.imag;
    cout<<"Digite la parte real e imaginaria del segundo numero complejo"<<endl;
    cin>>m.real>>m.imag;
    restacomplejos (n,m);

    return 0;
}
void restacomplejos(complejo n,complejo m)
{
    complejo resta;
    resta.real= n.real-m.real;
    resta.imag= n.imag-m.imag;
    if(resta.imag>=0){
        cout<<"La resta es igual a "<<resta.real<<" + "<<resta.imag<<"i"<<endl;
        
    }
    else{
        cout<<"La resta es igual a "<<resta.real<<" - "<<resta.imag<<"i"<<endl;
    }
}
