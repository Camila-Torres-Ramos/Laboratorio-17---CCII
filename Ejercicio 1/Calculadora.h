#if !defined(_CALCULADORA_H_)
#define _CALCULADORA_H_

#include <iostream>        

template<typename T,typename N>    
class Calculadora     
{
private:
    T date1;        
    N date2;      
public:
    Calculadora(T _date1,N _date2);   
    ~Calculadora();     

    void Elegir_opcion();      
    auto Suma();          
    auto Resta();        
    auto Multiplicacion();    
    auto Division();          
};

template<typename T,typename N>   
Calculadora<T,N>::Calculadora(T _date1,N _date2)     
{
    this->date1 = _date1;
    this->date2 = _date2;
    this->Elegir_opcion();
}

template<typename T,typename N>    
Calculadora<T,N>::~Calculadora()        
{
}

template<typename T,typename N>    
void Calculadora<T,N>::Elegir_opcion()   
{
    std::cout<<"Numero1: "<<this->date1<<"\nNumero2: "<<
    this->date2<<"\n";
    int opcion{0};
    while (opcion<1 || opcion >4)
    {
        std::cout<<"Opciones:\n\t1) Suma."<<
        "\n\t2) Resta.\n\t3) Multiplicacion.\n\t4) Division."<<
        "\nIngrese opcion: ";
        std::cin>>opcion;
    }
    if (opcion == 1)
    {
        std::cout<<"\t-> Respuesta: "<<this->Suma()<<"\n\n";
    }else if (opcion == 2)
    {
        std::cout<<"\t-> Respuesta: "<<this->Resta()<<"\n\n";
    }else if (opcion == 3)
    {
        std::cout<<"\t-> Respuesta: "<<this->Multiplicacion()<<"\n\n";
    }else
    {
        std::cout<<"\t-> Respuesta: "<<this->Division()<<"\n\n";
    }
    this->~Calculadora();
}

template<typename T,typename N>     
auto Calculadora<T,N>::Suma()      
{
    return this->date1+this->date2;
}

template<typename T,typename N>     
auto Calculadora<T,N>::Resta()      
{
    return this->date1-this->date2;
}

template<typename T,typename N>     
auto Calculadora<T,N>::Multiplicacion()     
{
    return this->date1*this->date2;
}

template<typename T,typename N>     
auto Calculadora<T,N>::Division()      
{
    return this->date1/this->date2;
}

#endif 
