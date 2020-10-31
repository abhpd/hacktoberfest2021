using System;
using System.Collections.Generic;

public static class SortExtensions
{
    /// <summary>
    /// Sort a collection of values, using selection sort.
    /// </summary>
    /// <remarks>
    /// Values are compared by using their <seealso cref="IComparable"/> implementation.
    /// </remarks>
    /// <typeparam name="TSource">The value's type.</typeparam>
    /// <param name="collection">The collection of values to sort.</param>
    public static void SelectionSort<TSource>(this IList<TSource> collection)
        where TSource : struct, IComparable, IComparable<TSource>, IEquatable<TSource>, IConvertible, IFormattable
    {
        TSource temp;
        int indexToSwapWith;

        // Declare count to save accessing the variable in the selection sort algorithm
        int count = collection.Count;

        // Beginning of Bubble sort algorithm
        for (int i = 0; i < count - 1; i++)
        {
            indexToSwapWith = i;
            for (int j = i + 1; j < count; j++)
            {
                if (collection[j].IsLessThan(collection[indexToSwapWith]))
                {
                    indexToSwapWith = j;
                }
            }

            temp = collection[indexToSwapWith];
            collection[indexToSwapWith] = collection[i];
            collection[i] = temp;
        }
    }

    private static bool IsLessThan<T>(this T value, T other) where T : IComparable
    {
        return value.CompareTo(other) < 0;
    }
}
