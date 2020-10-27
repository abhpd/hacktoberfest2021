
import java.util.Collections;
/**
 * 
 *
 * @author Gustav Sejr Rasmussen
 * @version 11-10-2020
 */
public class Train implements Comparable<Train>
{
    private String departure;
    private String destination;
    private int price;

    public Train(String departure, String destination, int price)
    {
        this.departure = departure;
        this.destination = destination;
        this.price = price;
    }

    /**
     * A method to get the departure
     */
    public String getDeparture() {
        return departure;
    }

    /**
     * A method to get the destiantion
     */
    public String getDestiantion() {
        return destination;
    }

    /**
     * A method to get grice
     */
    public int getPrice() {
        return price;
    }

    /**
     * This method will format a String of the given way
     */
    public String toString() {
        return "From " + departure + " to " + destination + " for " + price + " DKK";
    }

    /**
     * This method sorts departures alphabeticly, if they have the same 
     * departures then it wil sort after price from lovest til highest
     */
    public int compareTo(Train other) {
        if(!departure.equals(other.departure)) {
            return departure.compareTo(other.departure);
        } else 
        {
            return price - other.price;
        }
    }
}
