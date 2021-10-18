package Practise_problems;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.List;
import java.util.Map.Entry;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;

public class Permutations {
	 static List<List<Integer>> list=new ArrayList<>();
	public static void main(String args[]) {
		FastScanner fs=new FastScanner();
		System.out.println("Size of Array is :");
		Random r=new Random();
		int n=r.nextInt(8);
		System.out.println(n);
		int []nums=new int[n];
		for(int i=0;i<n;i++)
			nums[i]=r.nextInt(10);
		System.out.println("Elements of Array");
		for(int i=0;i<n;i++)
			System.out.print(nums[i]+" ");
		System.out.println();
		list=permuteUnique(nums);
		System.out.println(list);
	}
	public static  List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();

        // count the occurrence of each number
        HashMap<Integer, Integer> counter = new HashMap<>();
        for (int num : nums) {
            if (!counter.containsKey(num))
                counter.put(num, 0);
            counter.put(num, counter.get(num) + 1);
        }

        LinkedList<Integer> comb = new LinkedList<>();
        backtrack(comb, nums.length, counter, results);
        return results;
    }

    public static void backtrack(
            LinkedList<Integer> comb,
            Integer N,
            HashMap<Integer, Integer> counter,
            List<List<Integer>> results) {

        if (comb.size() == N) {
            results.add(new ArrayList<Integer>(comb));
            return;
        }

        for (Entry<Integer, Integer> entry : counter.entrySet()) {
            Integer num = entry.getKey();
            Integer count = entry.getValue();
            if (count == 0)
                continue;
            comb.addLast(num);
            counter.put(num, count - 1);
            backtrack(comb, N, counter, results);
            comb.removeLast();
            counter.put(num, count);
        }
    }
	static final Random random=new Random();	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
}
