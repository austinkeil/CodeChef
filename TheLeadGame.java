import java.lang.*;
import java.util.*;

class TheLeadGame {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int leader = 1, maxDiff = 0, p1_total = 0, p2_total = 0;
    for (int i = 0; i < n; ++i) {
      int s1 = sc.nextInt();
      int s2 = sc.nextInt();
      p1_total += s1;
      p2_total += s2;
      int diff = p1_total - p2_total;
      if (Math.abs(diff) > maxDiff) {
        maxDiff = Math.abs(diff);
        if (diff >= 0) {
          leader = 1;
        } else {
          leader = 2;
        }
      }
    }
    System.out.println(leader + " " + maxDiff);
  }
}

