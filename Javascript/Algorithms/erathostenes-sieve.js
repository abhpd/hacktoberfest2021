/*
Erathostenes sieve consist of one function that takes one argument n and returns an array of prime numbers between 2 and n.
Erathostenes was a Greek mathematician who was known for his work on prime numbers.
This problem is commonly used in interviews to help you get a good idea of the limits of your problem.
*/

const sieve = (n) => {
  const primes = [];

  for (let i = 0; i <= n; i++) primes[i] = true;

  primes[0] = primes[1] = false;

  let limit = ~~Math.sqrt(n);

  for (let i = 2; i <= limit; i++) {
    if (primes[i]) {
      for (let j = i * i; j <= n; j += i) primes[j] = false;
    }
  }

  return primes;
};

const log = sieve(20)
  .map((v, i) => `${i} = ${v}`)
  .join(", ");

console.log(log);
