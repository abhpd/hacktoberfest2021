# Generating Strong Password using Python

Having a weak password is not good for a system that demands high confidentiality and security of user credentials. It turns out that people find it difficult to make up a strong password that is strong enough to prevent unauthorized users from memorizing it. 
 

This article uses a mixture of numbers, alphabets, and other symbols found on the computer keyboard to form a 12-character password which is unpredictable and cannot easily be memorized. 
 

The components of the password are represented in the form of arrays.
Use the random method to select at least one character from each array of characters.
Since the 12-character password is required, so fill the rest of the length of the password left with randomly selected characters from an array formed from the combination of all the characters needed in the final password. Anytime the password is generated, shuffle the password using random.shuffle() to ensure that the final password does not follow a particular pattern.