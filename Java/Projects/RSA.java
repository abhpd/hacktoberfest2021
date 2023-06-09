
import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.Scanner;
  
// RSA is an asymmetric cryptographic algorithm, i.e., it uses 2 different keys for encryption and decryption
// Among the keys, one is called the public key, which is the key used for encryption which could be given to anyone
// while the key for decryption is called the private key which is available only to the particular receiver 
// who is supposed to receive the encrypted message. The basic idea of RSA technique is the fact that it is 
// difficult to factorize a very large integer. 

public class RSA {
   private final static BigInteger one      = new BigInteger("1");
   private final static SecureRandom random = new SecureRandom();
private static Scanner in;
 
   public static void main(String[] args) {
	  // Taking key length as 2048 bits
      int N = 2048;
      
      // Taking two random prime numbers, p and q of size N
      BigInteger p = BigInteger.probablePrime(N, random);
      BigInteger q = BigInteger.probablePrime(N, random);
      
      // Computing phi of product of p and q as (p-1)*(q-1) 
      BigInteger phi = (p.subtract(one)).multiply(q.subtract(one));

      // Here n variable is used to store the product of p and q
      BigInteger n = p.multiply(q);     
      
      // Taking public key as 66537 which is a very commonly used value for RSA encryption
      BigInteger publicKey  = new BigInteger("65537");
      
      // Computing the respective private key which is obtained by computing the number by which 
      // when we multiply public key such that the particular product gives a remainder of 1
      // when divided by phi
      BigInteger privateKey = publicKey.modInverse(phi);
 
      // Taking input from user which is to be encrypted
      in = new Scanner(System.in);
      System.out.print("Enter plaintext to be encrypted: ");
      String message = in.nextLine();
      
      // Converting the string to array of bytes and then to a BigInteger variable
      byte[] bytes = message.getBytes();
      BigInteger messageBytes = new BigInteger(bytes);

      // Encrypting the plaintext to cipher by computing plaintext^publicKey mod n
      BigInteger encrypt = messageBytes.modPow(publicKey, n);
      
      // Decrypting the above encrypted cipher using the formula cipher^privateKey mod n
      BigInteger decrypt = encrypt.modPow(privateKey, n);
      
      // Converting the decrypted message from BigInteger to byte array and finally to String
      byte[] decryptBytes = decrypt.toByteArray();
      String decryptMessage = new String(decryptBytes);
      
      // Printing the computed Cipher and the final plaintext retained through decryption
      System.out.println("Cipher: " + encrypt);
      System.out.println("Retained plaintext = " + decryptMessage);
   }
}