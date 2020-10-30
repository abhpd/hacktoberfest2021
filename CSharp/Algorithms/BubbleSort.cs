using System;
using System.Collections.Generic;

namespace BubbleSort
{
    public static class BubbleSort
    {
        /// <summary>
        /// Sort a collection of values, using bubble sort.
        /// </summary>
        /// <remarks>
        /// Values are compared by using their <seealso cref="IComparable"/> implementation.
        /// </remarks>
        /// <typeparam name="TSource">The value's type.</typeparam>
        /// <param name="collection">The collection of values to sort.</param>
        public static void Sort<TSource>(IList<TSource> collection)
            where TSource : struct, IComparable, IComparable<TSource>, IEquatable<TSource>, IConvertible, IFormattable
        {
            TSource temp;

            // Declare count, to save accessing the variable in the bubble sort algorithm
            int count = collection.Count - 1;
            
            // Beginning of Bubble sort algorithm
            for (int i = 0; i < count; i++)
            {
                for (int j = 0; j < count - i; j++)
                {
                    // Compares the adjacent elements
                    if (collection[j].IsGreaterThan(collection[j+1]))
                    {
                        // Swaps them by using a temporary variable
                        temp = collection[j];
                        collection[j] = collection[j+1];
                        collection[j+1] = temp;
                    }
                }
            }
        }

        private static bool IsGreaterThan<T>(this T value, T other) where T : IComparable
        {
            return value.CompareTo(other) > 0;
        }
    }
}
