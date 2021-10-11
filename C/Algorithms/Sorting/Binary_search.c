//Implementação Iterativa:

int PesquisaBinaria (int vet[], int chave, int Tam)
{
     int inf = 0;     // limite inferior (o primeiro índice de vetor em C é zero          )
     int sup = Tam-1; // limite superior (termina em um número a menos. 0 a 9 são 10 números)
     int meio;
     while (inf <= sup)
     {
          meio = (inf + sup)/2;
          if (chave == vet[meio])
               return meio;
          if (chave < vet[meio])
               sup = meio-1;
          else
               inf = meio+1;
     }
     return -1;   // não encontrado
}

//Implementação Recursiva:

// x => chave | v[] => vetor ordenado | e => limite inferior (esquerda) | d => limite superior (direita)
int PesquisaBinaria (int x, int v[], int e, int d)
{
 int meio = (e + d)/2;
 if (v[meio] == x)
    return meio;
 if (e >= d)
    return -1; // não encontrado
 else
     if (v[meio] < x)
        return PesquisaBinaria(x, v, meio+1,      d);
     else
        return PesquisaBinaria(x, v,      e, meio-1);
}