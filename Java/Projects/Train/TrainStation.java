import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.Comparator;
/**
 * 
 *
 * @author Gustav Sejr Rasmussen
 * @version 11-10-2020
 */
public class TrainStation
{
    private String city;
    private ArrayList<Train> trains;

    public TrainStation(String city)
    {
        this.city = city;
        trains = new ArrayList<Train>();
    }

    /**
     * this method adds trains tot the ArrayList trains
     */
    public void addTrain(Train t) {
        trains.add(t);
    }

    /**
     * Method will return the number of trains that starts or ends in the
     * city of the Trainstation
     */
    public int connectingTrains() {
        int result = 0;
        for(Train t : trains) {
            if(city.equals(t.getDeparture()) || city.equals(t.getDestiantion())) {
                result ++;
            }
        }
        return result;
    }

    /**
     * This method returns the chepest train go to a spesific destination
     */
    public Train cheapTrainTo(String destination) {
        Train result = null;
        for(Train t : trains) {
            if(destination.equals(t.getDestiantion())) {
                if(result == null || result.getPrice() > t.getPrice()) {
                    result = t;
                }
            }
        }
        return result;
    }

    /**
     * This method prints out all trains in the ArrayList trains
     * in sorted order after the departurs in alphabeticly order
     * if they have the same departures then it wil sort after price 
     * from lovest til highest
     */
    public void printTrainStation() {
        Collections.sort(trains);
        System.out.println("The trainstaion in " + city + " has following trains:");
        for(Train t : trains) {
            System.out.println(t);
        }
    }

    /**
     * This method will return all trains that starts in a given place
     * going to the Trainstations city.
     */
    public List<Train> trainsFrom(String departure) {
        return trains.stream()
        .filter(t -> t.getDeparture().equals(departure) && t.getDestiantion().equals(city))
        .collect(Collectors.toList());
    }

    /**
     * This method returns the cheapest train strating in the Trainstations 
     * city, and ends in a given destination
     */
    public Train cheapTrain(String destination) {
        return trains.stream()
        .filter(t -> t.getDeparture().equals(city) && t.getDestiantion().equals(destination))
        .min(Comparator.comparing(t -> t.getPrice()))
        .orElse(null);
    }
}
