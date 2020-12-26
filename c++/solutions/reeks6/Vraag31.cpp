
template <typename T>
class Doos {
    public:
        Doos();
        Doos(const Doos<T> &);
        Doos<T>& operator=(const Doos<T> &);
        virtual ~Doos(); //destructor steeds virtual maken!!
     //extra
        Doos(Doos<T>&&); //move constructor
        Doos<T>& operator=(Doos<T>&&); //move operator 
   private:
        vector<T> b;
        int n;
        Doos<T> *c;
        unique_ptr<string> *d;
        void copy(const Doos<T> &); //vermijd duplicated code
        
};

template <typename T>
class Schijf {
    public:
        Schijf();
        Schijf(const Schijf<T> &);
        Schijf<T>& operator=(const Schijf<T> &);
        virtual ~Schijf<T>(); //destructor steeds virtual maken!!
     //extra
        Schijf(Schijf<T>&&); //move constructor
        Schijf<T>& operator=(Schijf<T>&&); //move operator

    private:
        Doos<T> *a;
};   

/******************************* SCHIJF *****************************/
//extra
//move constructor
template<typename T>
Schijf<T> :: Schijf(Schijf<T>&& schijf) : a(schijf.a) {
    schijf.a = nullptr; 
}

//move operator
template <typename T>
Schijf<T>& Schijf<T> :: operator=(Schijf<T>&& schijf){
     if (this != &schijf) {
           delete a;
          a = schijf.a;
          schijf.a = nullptr;
     }
     return *this;            
}

/********************************* DOOS **************************/
//extra: move constructor
template<typename T>
Doos<T>::Doos(Doos<T>&& doos) :
         b(move(doos.b)), c(doos.c), n(doos.n), d(doos.d) {
   doos.c = nullptr;
   doos.n = 0;
   doos.d = nullptr;
}
 
template<typename T>
Doos<T>& Doos<T>::operator=(Doos<T> &&doos) {
   if (this != &doos) {
      b = move(doos.b);
      
      delete c;
      c = doos.c;
      
      n = doos.n;        

      delete[] d;      
      d = doos.d;
      
      doos.n = 0;
      doos.c = nullptr;  
      doos.d = nullptr;
   }
   return *this;
}
 
