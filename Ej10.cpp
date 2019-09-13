/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: uca
 *
 * Created on 10 de septiembre de 2019, 11:43
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

/*
 * 
 */
int elevar(int x, int y){
    
    if(y==0){
        return 1;
    }
    else{
        return (x*elevar(x,y-1));
    }
}
int main(void) {
    int x,y,z;
    cout<<"Ingrese un numero entero"<<endl;
    cin>>x;
    cout<<"Ingrese a que potencia desea elevarlo"<<endl;
    cin>>y;
    z= elevar(x,y);
    cout<<"La respuesta es: "<<x<<"^"<<y<<" = "<<z;
    return 0;
}

