class Atoi
{
   int atoi(String str) 
   {
      char ch[]=str.toCharArray();
      for(char i=0;i<str.length();i++)
      {
          if(Character.isLetter(ch[i]))
           return -1;
      }
    return  Integer.parseInt(str);
   }
  
  public static void main(String args[]){
    System.out.println(atoi("1234"));
  }
}
