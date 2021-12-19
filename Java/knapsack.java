import java.util.*;
import java.util.Comparator;
import java.util.Arrays;
public class fracknapsack {
    double fknap(int val[], int w[], int capacity) {
        ItemValue[] iVal = new ItemValue[w.length];

        for (int i = 0; i < w.length; i++) {
            iVal[i] = new ItemValue(w[i], val[i], i);
        }

        Arrays.sort(iVal, new Comparator<ItemValue>() {
            public int compare(ItemValue o1, ItemValue o2) {
                return o2.cost.compareTo(o1.cost);
            }
        });
        double totalValue = 0d;
        for (ItemValue i : iVal) {
            int curWt = (int) i.wt;
            int curVal = (int) i.val;
            if (capacity - curWt >= 0) {
                capacity = capacity - curWt;
                totalValue += curVal;
            } else {
                double fraction
                        = ((double) capacity / (double) curWt);
                totalValue += (curVal * fraction);
                capacity = (int) (capacity - (curWt * fraction));
                break;
            }
        }
        return totalValue;
    }

    static class ItemValue {
        Double cost;
        double wt, val, ind;

        public ItemValue(int wt, int val, int ind) {
            this.wt = wt;
            this.val = val;
            this.ind = ind;
            cost = new Double((double) val / (double) wt);
        }
    }


    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        fracknapsack ob=new fracknapsack();
        System.out.println("Enter the number of weights and values to be inserted:");
        int n=sc.nextInt();
        int v[]=new int[n];
        int w[]=new int[n];
        System.out.println("Enter the Values:");
        for(int i=0;i<n;i++){
            v[i]=sc.nextInt();
        }
        System.out.println("Enter the Weights:");
        for(int j=0;j<n;j++){
            w[j]=sc.nextInt();
        }
        System.out.println("Enter the capacity of the knapsack:");
        int c=sc.nextInt();
        double max=ob.fknap(v,w,c);
        System.out.println("The values are:");
        System.out.print("{ ");
        for(int i=0;i<n;i++){
            System.out.print(v[i]+" ");
        }
        System.out.print("}");
        System.out.println();
        System.out.println("The weights are:");
        System.out.print("{ ");
        for(int i=0;i<n;i++){
            System.out.print(w[i]+" ");
        }
        System.out.print("}");
        System.out.println();
        System.out.println("Capacity of the knapsack: "+c);
        System.out.println("Maximum value="+max);
    }
    }

