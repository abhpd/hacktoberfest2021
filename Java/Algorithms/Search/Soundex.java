public class Soundex {
    
    public static String getSoundexCode(String input) 
    {
        //We will check if the input length is 0.
        //If it is, we return an empty string.
        if(input.length() == 0){
            return "";
        }
        
        //Now we split the input string into an array of each individual character.
        char[] inputCharacters = input.toUpperCase().toCharArray();
        
        //We get the firstLetter of our input string.
        char firstLetter = inputCharacters[0];
 
        //Now we convert input characters to their associated number.
        for (int i = 0; i < inputCharacters.length; i++) {
            
            //We use a switch statement because it is slightly more performant than 
            //an if-else if-else chain in this scenario.
            switch (inputCharacters[i]) {
                case 'B':
                case 'F':
                case 'P':
                case 'V': {
                    inputCharacters[i] = '1';
                    break;
                }
 
                case 'C':
                case 'G':
                case 'J':
                case 'K':
                case 'Q':
                case 'S':
                case 'X':
                case 'Z': {
                    inputCharacters[i] = '2';
                    break;
                }
 
                case 'D':
                case 'T': {
                    inputCharacters[i] = '3';
                    break;
                }
 
                case 'L': {
                    inputCharacters[i] = '4';
                    break;
                }
 
                case 'M':
                case 'N': {
                    inputCharacters[i] = '5';
                    break;
                }
 
                case 'R': {
                    inputCharacters[i] = '6';
                    break;
                }
 
                default: {
                    inputCharacters[i] = '0';
                    break;
                }
            }
        }
 
        //Now we begin to build our soundexCode string.
        String soundexCode = "" + firstLetter;
        
        //Now we are ensuring that two of the same number are not beside eachother unless
        //they are separated by a vowel.
        for (int i = 1; i < inputCharacters.length; i++)
            if (inputCharacters[i] != inputCharacters[i - 1] && inputCharacters[i] != '0')
                soundexCode += inputCharacters[i];
 
        //To format to the expected length, we add 0s as padding.
        soundexCode += "0000";
        //We then truncate the soundexCode to match the expected length.
        return soundexCode.substring(0, 4);
    }
    
}

