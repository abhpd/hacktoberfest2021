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

    public String getDeparture() {
        return departure;
    }

    public String getDestiantion() {
        return destination;
    }

    public int getPrice() {
        return price;
    }

    public String toString() {
        return "From " + departure + " to " + destination + " for " + price + " DKK";
    }

    public int compareTo(Train other) {
        if(!departure.equals(other.departure)) {
            return departure.compareTo(other.departure);
        } else 
        {
            return price - other.price;
        }
        }
}
