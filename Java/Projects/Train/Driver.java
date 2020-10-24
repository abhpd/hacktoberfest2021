
/**
 * 
 *
 * @author Gustav Sejr Rasmussen
 * @version 11-10-2020
 */
public class Driver
{
    public static void test() {
        Train t1 = new Train("Aarhus", "Berlin", 999);
        Train t2 = new Train("Herning", "Copenhagen", 42);
        Train t3 = new Train("Aarhus", "Herning", 66);
        Train t4 = new Train("Odense", "Herning", 177);
        Train t5 = new Train("Aarhus", "Copenhagen", 122);
        
        System.out.println("Opgave 3:");
        System.out.println("*******************");
        System.out.println(t1);
        System.out.println(t2);
        System.out.println(t3);
        System.out.println(t4);
        System.out.println(t5);
        System.out.println("*******************");
        System.out.println("");
        
        TrainStation ts = new TrainStation("Herning");
        ts.addTrain(t1);
        ts.addTrain(t2);
        ts.addTrain(t3);
        ts.addTrain(t4);
        ts.addTrain(t5);
        
        System.out.println("Opgave 8:");
        System.out.println("*******************");
        System.out.println("No. of trains going from or to Herning:");
        System.out.println(ts.connectingTrains());
        System.out.println("*******************");
        System.out.println("");
        
        System.out.println("Opgave 9:");
        System.out.println("*******************");
        System.out.println("The cheapest train going to Copenhagen is going:");
        System.out.println(ts.cheapTrainTo("Copenhagen"));
        System.out.println("*******************");
        System.out.println("");
        
        System.out.println("Opgave 10:");
        System.out.println("*******************");
        ts.printTrainStation();
        System.out.println("*******************");
        System.out.println("");
        
        System.out.println("Opgave 11:");
        System.out.println("*******************");
        System.out.println("Trains going from Aarhus to Herning:");
        for(Train t : ts.trainsFrom("Aarhus")) {
        System.out.println(t);
        }
        System.out.println("*******************");
        System.out.println("");
        
        System.out.println("Opgave 12:");
        System.out.println("*******************");
        System.out.println("The cheapest train going from herning to Copenhagen:");
        System.out.println(ts.cheapTrain("Copenhagen"));
        System.out.println("*******************");
        System.out.println("");
    }
}
