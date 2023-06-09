using System;

namespace QuickSort
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] x = new long[10];
            long i;
            for (i = 0; i <= 9; i++)
            {
                Console.WriteLine("o "+(i+1)+"º number: ");
                x[i] = Convert.ToInt64(Console.ReadLine());
            }
            
            QuickSort(x, 0, 9);

            long j = 8;
            for (i = 9; i >= 0; i--)
            {
                Console.WriteLine(i-j+"º number: "+x[i]);
                j-=2;
            }

            
        }

        public static long[] change(long[] x, long i, long j){
            var aux = x[i];
            x[i] = x[j];
            x[j] = aux;
            return x;
        }

        public static long partition(long[] x, long p, long r)
        {
            var pivo = x[(p + r) / 2];
            var i = p - 1;
            var j = r + 1;
            
            while (i < j)
            {
                do
                {
                    j -= 1;

                } while (x[j] < pivo);
                
                do
                {
                    i += 1;

                } while (x[i] > pivo);

                if (i<j)
                {
                    Troca(x, i, j);
                }
            }
            return j;
        }

        public static long[] QuickSort(long[] x, long p, long r)
        {
            if (p < r)
            {
                var q = Particao(x, p, r);
                QuickSort(x, p, q);
                QuickSort(x, q + 1, r);
            }
            return x;
        }
 
    }
}
