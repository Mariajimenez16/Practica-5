#include <iostream>
#include <thread>
#include <unistd.h>   // para getpid()
using namespace std;

void acumulada(int n) {
    int suma = 0;
    for(int i = 1; i <= n; i++) {
        suma += i;
    }
    cout << "Hilo Acumulada - Resultado: " << suma << endl;
}

void productoria(int n) {
    int producto = 1;
    for(int i = 1; i <= n; i++) {
        producto *= i;
    }
    cout << "Hilo Productoria - Resultado: " << producto << endl;
}

void potencia(int n) {
    int resultado = 1;
    for(int i = 0; i < n; i++) {
        resultado *= 2;
    }
    cout << "Hilo 2^n - Resultado: " << resultado << endl;
}

void fibonacci(int n) {
    int a = 0, b = 1, c;
    cout << "Hilo Fibonacci: ";
    for(int i = 0; i < n; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;

    cout << "PID del proceso principal: " << getpid() << endl;

    thread t1(acumulada, n);
    thread t2(productoria, n);
    thread t3(potencia, n);
    thread t4(fibonacci, n);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}