public abstract class Alien 
{

   protected int height;
   protected int numLegs;
   protected int numEyes;
   public Alien(int ht, int legs, int eyes)
   {
      height = ht; 
      numLegs = legs; 
      numEyes = eyes; 
   }
   
   public String toString()
   {
      String message;
      message = "Alien height is " + height + " feet." + "\n It has " + numLegs + " legs and " + numEyes + " eyes.";
      return message; 
   }
   

}