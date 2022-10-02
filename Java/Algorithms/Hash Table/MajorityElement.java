class MajorityElement{
    public static int majorityElement(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();

        for(int j : nums){
            if(map.containsKey(j)){
                 map.put(j, map.get(j)+1);}
            else{
                map.put(j, 1);
                }
        }

        int max = 0;
        int k=0;
        Set<Integer> set = map.keySet();
        for(int i : set){
            if(map.get(i) > max){
                max = map.get(i);
                k=i;
            }
        }
        return k;
    }
public static void main(String[] args)
{
    int a[] = {2, 2, 1, 1, 1, 2, 2};
    System.out.println(majorityNumber(a));
}
}
}