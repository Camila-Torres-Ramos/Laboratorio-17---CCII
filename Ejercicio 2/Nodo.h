#if !defined(_NODO_H_)
#define _NODO_H_

template<typename T>       
class Nodo        
{
private:
    T dato;         
    Nodo<T>* HijoI;    
    Nodo<T>* HijoD;     
public:
    Nodo();  
    ~Nodo();     

    void set_dato(T _dato)   
    {
        this->dato = _dato;
    }
    void set_HijoI()     
    {
        this->HijoI = new Nodo<T>;
    }
    void set_HijoD()       
    {
        this->HijoD = new Nodo<T>;
    }
    T get_dato()       
    {
        return this->dato;
    }
    Nodo* get_HijoI()      
    {
        return this->HijoI;
    }
    Nodo* get_HijoD()      
    {
        return this->HijoD;
    }
};

template<typename T>      
Nodo<T>::Nodo()    
    this->dato = NULL;
    this->HijoD = NULL;
    this->HijoI = NULL;
}

template<typename T>        
Nodo<T>::~Nodo()      
{
}

#endif
