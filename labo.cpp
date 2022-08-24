#include <iostream>

using namespace std;
//EJERCICIO 1
int f1(int x){
    return x+1;
}
//EJERCICIO 2
int f2(int x, int y){
    return x + y;
}
//EJERCICIO 3
int f3(int x, int y){
    if(x>y){
        return f2(x,y);
    }else{
        return x*y;
    }
}

//EJERCICIO 4
//esPrimo

bool tieneMasDeDosDivisores(int n){
    int suma = 0;
    int i = 2;
    while(i<n){
        if(n % i == 0){
            suma = suma + 1;
        }
        if(suma != 0){
            return true;
        }
        i=i+1;
    }
    return false;
}

bool esPrimo(int n){
    if(n == 0 || n == 1){
        return false ;
    }else{
        return !(tieneMasDeDosDivisores(n));
    }
}

//EJERCICIO 5
//Fibonacci

int fiboRec(int n){
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else{
        return fiboRec(n-1) + fiboRec(n-2);
    }
}



int fiboFor(int n){

    int a = 0;
    int b = 1;
    int c = 0;

    for (int i = 0; i < (n-1) ; ++i) {

        c = a+b;
        a = b;
        b = c;

    }
    if(n == 1){
        return b;
    }else{
        return c;
    }


}

int fiboWhile(int n){
    int a = 0;
    int b = 1;
    int c = 0;

    int i = 0;

    while (i < (n-1)){
        c = a + b;
        a = b;
        b = c;

        i++;
    }
    if(n == 1){
        return b;
    }else{
        return c;
    }
}

//EJERCICIO 6
//Escribir la funcion que dado n  devuelve la suma de todos los numeros impares menores que n
//numerosImpares

int numerosImparesRec(int n){

    if(n == 0 || n == 1){
        return 0;
    }else if( (n-1) % 2 != 0){
        return numerosImparesRec(n-1) + (n-1);
    }else{
        return numerosImparesRec(n-1);
    }
}

int numerosImparesFor(int n){

    int sum = 0;

    for (int i = 1; i < n; ++i) {

        if(i % 2 == 1){
            sum = sum + i;
        }

    }

    return sum;
}

int numerosImparesWhile(int n){
    int sum = 0;
    int i  = 0;

    while (i < n){
        if(i % 2 == 1){
            sum = sum + i;
        }
        i++;
    }

    return sum;

}

//EJERCICIO 7
//Escribir la funcion sumaDivisores que dado n, devuelve la suma de todos sus divisores entre [1, n]. Para
//la version recursiva, es conveniente utilizar una funcion divisoresHasta.

int sumaDivisoresHasta(int n, int i){

    if(n < i){
        return 0;
    }

    if(n % i == 0){
        return sumaDivisoresHasta(n,(i+1)) + i;
    }else{
        return sumaDivisoresHasta(n,(i+1));
    }

}

int sumaDivisoresRec(int n){
    return sumaDivisoresHasta(n,1);
}

bool divide(int n, int m){
    return (n % m == 0);
}

int sumaDivisoresFor(int n){

    int sum = 0;

    for (int i = 1; i <= n ; ++i) {
        if(divide(n, i)){
            sum = sum + i;
        }
    }

    return sum;
}

int sumaDivisoresWhile(int n){

    int sum = 0;
    int i = 1;

    while (i<=n){
        if(divide(n,i)){
            sum = sum + i;
        }
        i++;
    }

    return sum;
}

//EJERCICIO 8
//numeroCombinatorio

int numeroCombinatorio(int n, int k){
    if(k == 0){
        return 1;
    }else if(n == 0){
        return 0;
    }
    else{
        return(numeroCombinatorio((n-1),k)) + numeroCombinatorio((n-1),(k-1));
    }
}



int main(){
    //Pruebo ej 1
    cout << "El resultado es: " << f1(10) << endl;
    //Pruebo ej 2
    cout << "El resultado es: " << f2(10,20) << endl;
    //Pruebo ej 3
    cout << "El resultado es: " << f3(3,12) << endl;
    //Pruebo ej 4
    int n;
    cin>>n;
    cout << "El numero "<< n <<" es Primo?: " << (esPrimo(n) ?"true":"false")<< endl;
    //Pruebo ej 5
    cout <<fiboRec(8) << endl;
    cout <<fiboFor(8) << endl;
    cout <<fiboWhile(8) << endl;
    //Pruebo ej 6
    cout << numerosImparesRec(6) << endl;
    cout << numerosImparesFor(6) << endl;
    cout << numerosImparesWhile(6) << endl;
    //Pruebo ej 7
    cout << sumaDivisoresHasta(5,1) << endl;
    cout << sumaDivisoresRec(8) << endl;
    cout << sumaDivisoresFor(8) << endl;
    cout << sumaDivisoresWhile(8) << endl;

    //Pruebo ej 8
    cout << numeroCombinatorio(15,3) << endl;
    return 0;
}