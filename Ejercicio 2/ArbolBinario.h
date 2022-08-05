#if !defined(_ARBOLBINARIO_H_)
#define _ARBOLBINARIO_H_

#include <iostream>         
#include <vector>           
#include "Nodo.h"          

template<typename T>          
class ArbolBinario     
{
private:
    int num_nodos;      
    Nodo<T>* Raiz;     
public:
    ArbolBinario();     
    ~ArbolBinario();       

    void Insertar_Datos(std::vector<T>& _vector);         
    Nodo<T>* buscar_nodo_accesible(T _dato);     
    void Imprimir_Arbol(Nodo<T> *nodo);   
};

template<typename T>         
ArbolBinario<T>::ArbolBinario()    
{
    this->Raiz = new Nodo<T>;
}

template<typename T>           
ArbolBinario<T>::~ArbolBinario()      
{
}

template<typename T>     
Nodo<T>* ArbolBinario<T>::buscar_nodo_accesible(T _dato)      
{
    Nodo<T>* aux = Raiz;
    while ((aux->get_HijoD()!=NULL) || (aux->get_HijoI()!=NULL))
    {
        if (_dato > aux->get_dato())
        {
            if (aux->get_HijoD()==NULL)
            {
                break;
            }else
            {
                aux = aux->get_HijoD();
            }
        }else if (_dato < aux->get_dato())
        {
            if (aux->get_HijoI()==NULL)
            {
                break;
            }else
            {
                aux = aux->get_HijoI();
            }
        }
    }
    return aux;
}

template<typename T>         
void ArbolBinario<T>::Insertar_Datos(std::vector<T>& _vector)      
{
    if (_vector.size() == 0)
    {
        return;
    }else
    {
        this->Raiz->set_dato(_vector[0]);
        this->num_nodos = 1;
        Nodo<T> *aux;
        for (int i = 1; i < _vector.size(); i++)
        {
            aux = this->buscar_nodo_accesible(_vector[i]);
            if (_vector[i]<aux->get_dato())
            {
                aux->set_HijoI();
                aux->get_HijoI()->set_dato(_vector[i]);
            }else if (_vector[i]>aux->get_dato())
            {
                aux->set_HijoD();
                aux->get_HijoD()->set_dato(_vector[i]);
            }
            (this->num_nodos)++;
        }
        aux->~Nodo();
    }
    this->Imprimir_Arbol(this->Raiz);
}

template<typename T>          
void ArbolBinario<T>::Imprimir_Arbol(Nodo<T> *nodo)    
{
    std::cout<<nodo->get_dato();
    if (nodo->get_HijoI() != NULL)
    {
        std::cout<<"(";
        this->Imprimir_Arbol(nodo->get_HijoI());
        std::cout<<",";
    }else if (nodo->get_HijoD() != NULL)
    {
        std::cout<<"(~,";  
    }else
    {
        return;
    }
    if (nodo->get_HijoD() != NULL)
    {
        this->Imprimir_Arbol(nodo->get_HijoD());
        std::cout<<")";
    }else if (nodo->get_HijoI() != NULL)
    {
        std::cout<<"~)";
    }
}

#endif 
