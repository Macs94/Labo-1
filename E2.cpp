/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: uca
 *
 * Created on 3 de septiembre de 2019, 11:09
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
void raizcuadrada (int,float);
/*
 * 
 */
int main(void) {
    int n;
    float r;
    
    
    cout<<"Digite un número positivo entero del cual desee saber la raiz cuadrada:"<<endl;
    cin>>n;
    cout<<"Digite un número positivo cualquiera "<<endl;
    cin>>r;
    raizcuadrada (n,r);
            

    return 0;
}
void raizcuadrada (int i, float j)
{

     float nj=((i/j)+j)/2;
            if(abs(j-nj)< 0.001){
                cout<<"La raiz cuadrada es "<<nj<<endl;
            }
            else{
                raizcuadrada (i,nj);
                
            }
}
