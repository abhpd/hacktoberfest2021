import java.util.ArrayList;


public class Lab20 {
    public static void main(String[] args) {
        final java.util.Scanner input = new java.util.Scanner(System.in);

    System.out.print("Enter the number of objects: ");
    double[] items = new double[input.nextInt()];
    System.out.print("Enter the weight of the objects: ");
    for (int i = 0; i < items.length; i++) {
        items[i] = input.nextDouble();
    }

    ArrayList<Bin> containers = firstFit(items);

    //Display results
    for (int i = 0; i < containers.size(); i++) {
        System.out.println("Container " + (i + 1)
                + " contains objects with weight " + containers.get(i));
    }
    input.close();
}

//Greedy Algorithm??
public static ArrayList<Bin> firstFit(double[] items) {
    ArrayList<Bin> list = new ArrayList<>();
    Bin bin = new Bin();

    list.add(bin);

    for (int i = 0; i < items.length; i++) {
        if (!bin.addItem(items[i])) {
            Bin bin2 = new Bin();
            list.add(bin2);
            bin2.addItem(items[i]);
            }
        }
        return list;
    }
}

//Bin Class
class Bin {
    private ArrayList<Double> objects = new ArrayList<>();
    private double maxWeight = 10;
    private double totalWeight = 0;

    public Bin() {
    }

    public Bin(double maxWeight) {
        this.maxWeight = maxWeight;
    }

    //Or is this supposed to be the Greedy algorithm??
    public boolean addItem(double weight) {
        if ((totalWeight+weight) <= maxWeight) {
            objects.add(weight);
            totalWeight += weight;
            return true;
        }
        else {
            return false;
        }
    }

    public int getNumberOfObjects() {
        return objects.size();
    }

    @Override
    public String toString() {
        return objects.toString();
    }
}
