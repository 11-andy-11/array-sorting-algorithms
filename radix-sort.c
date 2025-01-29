#include <stdio.h>

// Funcție pentru a găsi valoarea maximă dintr-un array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Funcție de sortare Counting Sort utilizată pentru fiecare cifră
void countingSort(int arr[], int n, int exp) {
    int output[n]; 
    int count[10] = {0}; 

    // Contorizează aparițiile fiecărei cifre
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Modifică count[i] astfel încât să conțină poziția finală a cifrei în output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Construiește array-ul sortat
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copiază output[] înapoi în arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Funcția principală Radix Sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Aplică Counting Sort pentru fiecare cifră (unități, zeci, sute etc.)
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}


// Funcția main
int main() {

    return 0;
}
