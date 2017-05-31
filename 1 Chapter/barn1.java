/*
ID: haroons1
LANG: JAVA
TASK: barn1
*/

   import java.io.*;
   import java.util.*;

   class Gap implements Comparable<Gap> {
      int start, end;

      Gap (int s, int e) {
         start = s;
         end = e;
      }

      public int compareTo (Gap o) {
         return getSize() - o.getSize();
      }

      public int getSize () {
         return end - start - 1;
      }

   } //Gap class

   public class barn1 {

      public static void main (String [] args) throws IOException {

         BufferedReader f = new BufferedReader(new FileReader("barn1.in"));
         PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("barn1.out")));

         StringTokenizer st = new StringTokenizer (f.readLine());
         Gap g;

         int m = Integer.parseInt (st.nextToken());
         int s = Integer.parseInt (st.nextToken());
         int c = Integer.parseInt (st.nextToken());
         int boards, stallsCovered = c;

         int [] stalls = new int [c];
         ArrayList<Gap> gaps = new ArrayList<Gap>();

         for (int i = 0; i < c; i++)
            stalls[i] = Integer.parseInt (f.readLine());

			//sort stalls

         Arrays.sort (stalls);

			//determine gaps

         for (int i = 1; i < c; i++) {
            if (stalls[i] - stalls[i - 1] > 1) {
               gaps.add (new Gap (stalls[i - 1], stalls[i]));
            }
         }

			//sort gaps

         Collections.sort (gaps);

			//number of boards needed is # of gaps + 1

         boards = gaps.size() + 1;

         while (boards > m) {
				//remove smallest gap
            g = gaps.remove(0);
				//add its size to stallsCovered
            stallsCovered += g.getSize();
				//remove a board
            boards--;
         }

         out.println (stallsCovered);

         out.close();
         System.exit(0);
      } //main method
   } //barn1 class