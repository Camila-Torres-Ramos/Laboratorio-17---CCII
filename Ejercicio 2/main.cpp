#include "ArbolBinario.h"  

#include <random>   
#include <chrono>          

template<typename T>
void agregando_100_datos(std::vector<T> &_vector)    
{
    auto num_base = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generador(num_base);
    std::uniform_int_distribution<int>distrib(-100,100);
    int num_aleatorio=distrib(generador);
    _vector.push_back(num_aleatorio);

    int opcion{0};
    for (int i = 1; i < 100; i++)
    {
        num_aleatorio=distrib(generador);
        for (int j = 0; j < _vector.size(); j++)
        {
            if (num_aleatorio == _vector[j])
            {
                opcion = 1;
                break;
            }
        }
        if (opcion == 0)
        {
            _vector.push_back(num_aleatorio);
        }else if (opcion == 1)
        {
            i--;
            opcion = 0;
        }
    }
}

int main()    
{

    std::vector<int> vector1 = {8,3,1,6,4,7,10,14,13};
    std::vector<int> vector2 = {50,17,12,9,14,23,19,72,54,67,76};
    std::vector<char> vector3 = {'D','B','A','C','F','E','G'};
    ArbolBinario<int> A,B;
    ArbolBinario<char>C;
    std::cout<<"Arbol 1:\n\t";
    A.Insertar_Datos(vector1);
    std::cout<<"\nArbol 2:\n\t";
    B.Insertar_Datos(vector2);
    std::cout<<"\nArbol 3:\n\t";
    C.Insertar_Datos(vector3);
    A.~ArbolBinario();
    B.~ArbolBinario();
    C.~ArbolBinario();


    std::vector<int> vector4;
    ArbolBinario<int> D;
    agregando_100_datos(vector4);
    std::cout<<"\nArbol 4:\n\t";
    D.Insertar_Datos(vector4);
    D.~ArbolBinario();

    return 0;
}
