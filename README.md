Scrivere un programma che implementi una funzione del tipo

    void mul (int *v1, int *v2, int n, int *v3);
        
che moltiplica due numeri interi di n cifre, il primo memorizzato nel vettore v1, il secondo nel vettore v2. La funzione restituisce il risultato della moltiplicazione nel vettore v3. In numeri sono memorizzati nei vettori in ragione di una cifra decimale per ciascun elemento. La funzione implementa l’algoritmo classico di moltiplicazione, operando per somma e scalamento e tenendo conto dei riporti, come illustrato dal seguente esempio:

    0 3 2 x
    2 4 3 =
    ------------
    0 0 0 0 9 6 +
    0 0 1 2 8 =
    0 0 6 4
    -----------
    0 0 7 7 7 6

Si osservi che, per evitare overflow, il prodotto dovrà essere rappresentato su 2*n cifre. Si suppone quindi che v3 abbia dimensione >= 2*n.
