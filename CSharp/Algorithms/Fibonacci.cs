public class Fibonacci
{
    public int Calculate(int number)
    {
        if (number == 1 || number == 0)
            return number;
        return Calculate(number - 2) + Calculate(number - 1);
    }
}
