class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character,Character> hm = new HashMap<Character,Character>();
        HashSet<Character> hs=new HashSet<Character>();
        for(int i=0;i<s.length();i++)
        {
          char ch1=s.charAt(i);
          char ch2=t.charAt(i);
          if(!hm.containsKey(ch1) && hs.contains(ch2))
              return false;
            else if(!hm.containsKey(ch1))
          {
             
              hm.put(ch1,ch2);
              hs.add(ch2);
          }
            else
            {
                
                if(hm.get(ch1) != ch2)
                    return false;
            }
        }
        return true;
    }
}
