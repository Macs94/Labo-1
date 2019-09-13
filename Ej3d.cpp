/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: uca
 *
 * Created on 10 de septiembre de 2019, 12:00
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

/*
 * 
 */
long long factorial(int k){
    if(k==0){
        return 1;
    }
    else{
        return k*(factorial(k-1));
    }
       
}
long long potencia(int x,int k){
    if(k==0){
        return 1;
    }
    else{
        return (x*potencia(x,k-1));
    }
}

float aproximarE(int x,int k, float acumulador){
    long long  factoK=factorial(k);
    long long  potenX=potencia(x,k);
    
    
    float acumulador2=((float)potenX/(float)factoK);
    
    /*if(abs(acumulador-acumulador2)<=0.01){
        return acumulador2;
    }*/
    
    if(k==21){
        return acumulador;
    }
    
    k++;
    acumulador2+=acumulador;
    
    return aproximarE(x,k,acumulador2);
    
    
}
int main(void) {
    int x,k;
    //cout<<"Ingrese la variable independiente"<<endl;
    //cin>>x;
    cout<<"e^x = "<<aproximarE(5,0,0);

    return 0;
}

