#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <fstream>

void insertion_sort(int arr[], int length);

using namespace std;
using namespace std::chrono;

int main() {
    srand(time(nullptr));
    const int length = 1000;
    int arr[length];
    int iterations = 1001;
    int counter = 1;
    double time[1001][101];
    int column_counter = 1;
    int length_counter = 10;
    int papu = 0;

    // Abre un archivo para escribir los tiempos
    ofstream outFile("1Ordenamiento_Insercion_tiempos.csv");
    if (!outFile.is_open()) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1; // Exit the program if the file cannot be opened
    }
    // Inicia ciclo para contar tiempo
    for (int j = 1; j < 101; j++) {
        // Se repite mil veces el proceso para un mismo length_counter
        for (int i = 1; i < iterations; i++) {

            // Genera un arreglo de numeros aleatoreos del 1 al 1000 de longitud lenght
            for (int k = 0; k < length_counter; k++) {
                arr[k] = 1 + rand() % 1000;
            }

            // Inicia el timer
            auto start = high_resolution_clock::now();

            insertion_sort(arr, length_counter);

            // Termina el timer
            auto end = high_resolution_clock::now();

            duration<double> duration = end - start;

            time[i][column_counter] = duration.count() * 1000;

            //cout << length_counter << " Run " << counter << ": " << fixed << setprecision(6) << time[i][column_counter] << " milisegundos" << endl;

            counter++;
        }
        counter = 1;
        column_counter++;
        length_counter+=10;
        //cout << papu++ << endl;;
    }

    length_counter = 0;
    for (int i = 0; i < 101; i++) {
        outFile << "Tama\361o " << length_counter << ",";
        length_counter+=10;
    }

    for (int i = 0; i < iterations; i++){
        outFile << i << ",";
        for (int j = 1; j < 101; j++){
            outFile <<  time[i][j] << ",";
        }
        outFile << endl;
    }

    outFile.close();

    return 0;
}

void insertion_sort(int arr[], int length) {
    /*
    for (int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
    */

    for (int i = 1; i < length; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j]) {
           arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
    /*
    cout << endl;

    for (int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
    cout << endl;
    */
}