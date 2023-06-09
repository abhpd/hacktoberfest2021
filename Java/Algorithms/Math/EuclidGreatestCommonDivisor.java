public class EuclidGreatestCommonDivisor {

  public static void main(String args[]) {
    System.out.println(getEuclidGCD(12, 6));
  }

  static int getEuclidGCD(int a, int b) {
    if (a == 0) {
      return b;
    }
    return getEuclidGCD(b % a, a);
  }
}
