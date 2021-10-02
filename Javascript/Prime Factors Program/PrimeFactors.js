/**
 * Finds prime factors of a number.
 *Prime factors are those prime numbers which multiply together to give the original number.
 * For example 39 will have prime factors of 3 and 13 which are also prime numbers. 
 * Another example is 15 whose prime factors are 3 and 5.
 * @param {number} n - the number that is going to be split into prime factors.
 * @returns {number[]} - array of prime factors.
 */
 export function primeFactors(n) {
    // Clone n to avoid function arguments override.
    let nn = n;
  
    // Array that stores the all the prime factors.
    const factors = [];
  
    // Running the loop till sqrt(n) instead of n to optimise time complexity from O(n) to O(sqrt(n)).
    for (let factor = 2; factor <= Math.sqrt(nn); factor += 1) {
      // Check that factor divides n without a reminder.
      while (nn % factor === 0) {
        // Overriding the value of n.
        nn /= factor;
        // Saving the factor.
        factors.push(factor);
      }
    }
  
    // The ultimate reminder should be a last prime factor,
    // unless it is not 1 (since 1 is not a prime number).
    if (nn !== 1) {
      factors.push(nn);
    }
  
    return factors;
  }
// sample input - 39
// sample Output - [3,13]