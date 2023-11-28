package labmst;
import java.util.*;
import java.lang.Math;

class quadratic_eq {
    public static void main(String[] args) {
        int a, b, c, d;
        Scanner obj = new Scanner(System.in);
        System.out.println("enter value of  a b c");
        a = obj.nextInt();
        b = obj.nextInt();
        c = obj.nextInt();
        d = (b * b - (4 * a * c));

        if (d == 0) {
            double root = (-b + Math.sqrt((b * b - (4 * a * c)))) / 2 * a;
            System.out.println("real and unique root \n Roots is=" + root);
        } else if (d < 0) {
            int Pov_d = -d;
            double img_root1 = (-b + Math.sqrt(Pov_d)) / 2 * a;
            double img_root2 = (-b - Math.sqrt(Pov_d)) / 2 * a;

            System.out.println("non real root \n imagernary Roots are " + img_root1 + "i " + img_root2 + "i ");

        } else {
            double root1 = (-b + Math.sqrt(d)) / 2 * a;
            double root2 = (-b - Math.sqrt(d)) / 2 * a;
            System.out.println("real and distinct root  \n Roots are=" + root1 + "," + root2);
        }

        obj.close();
    }
}