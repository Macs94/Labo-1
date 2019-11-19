#include <cstdlib>
#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;


void ShellSort(int arr[], int n) 
{ 
     
    int intercambios=0;
    int compar=0;
    clock_t tempsExecutionSS = clock();
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        
        for (int i = gap; i < n; i += 1) 
        { 
            int temp= arr[i];
            int j = i - gap;
            while (j >= 0)
            {
                  compar++;
                  if (arr[j]>(arr[j+gap]))
                  {
                       temp = arr[j];
                       arr[j] = arr[j + gap];
                       arr[j + gap] = temp;
                       j = j - gap;
                       intercambios++;
                  }
                  else j = -1;
            }
        }
    }
    tempsExecutionSS = clock() - tempsExecutionSS;
    
    cout << "\nEjecucion en " << ((float)tempsExecutionSS)/CLOCKS_PER_SEC << " segundos.\n";
    
    cout<<"\nSe efectuaron "<<intercambios<<" intercambios\n";
    
    cout<<"Se efectuaron "<<compar<<" comparaciones\n";
    
    cout<<endl<<"El arreglo despues de Shell Sort es: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
} 

void ShellSort2( int arr[], int n)
{
    
    int intercambios=0;
    int compar=0;
    
    clock_t tempsExecutionSS = clock();
    for (int gap = 2*(n/4)+1; gap > 0; (gap/=2)+1) 
    { 
        
        for (int i = gap; i < n; i += 1) 
        { 
            int temp= arr[i];
            int j = i - gap;
            while (j >= 0)
            {
                  compar++;
                  if (arr[j]>(arr[j+gap]))
                  {
                       temp = arr[j];
                       arr[j] = arr[j + gap];
                       arr[j + gap] = temp;
                       j = j - gap;
                       intercambios++;
                  }
                  else j = -1;
            }
        }
    }
    tempsExecutionSS = clock() - tempsExecutionSS;
    
    cout << "\nEjecucion en " << ((float)tempsExecutionSS)/CLOCKS_PER_SEC << " segundos.\n";
    
    cout<<"\nSe efectuaron "<<intercambios<<" intercambios\n";
    
    cout<<"Se efectuaron "<<compar<<" comparaciones\n";
    
    cout<<endl<<"El arreglo despues de Shell Sort es: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}

int main(){
    
    int n;
    
    cout<<"Cuantos elementos en el arreglo? "<<endl;
    cin>>n;
    int arr[n];
    int random;
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
    random=rand()%500+1;
    arr[i]=random;    
    }
    cout<<"El arreglo es: "<<endl;
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    int opcion;
    cout<<"\nCual ShellSort vas a usar?"<<endl;
    
        cout<<"\n 1.Shell Sort 1";
        cout<<"\n 2.Shell Sort 2";
        cout<<"\n 3.SALIR\n";
        cin>>opcion;
        if(opcion==1)
        {
            ShellSort(arr,n);
        }
        else if(opcion==2)
        {
            ShellSort2(arr,n);
        }
        else
        {
        cout<<"FIN";    
        }
    
            

    return 0;
}