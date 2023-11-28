package labmst;
import java.util.*;

class array_out_of_bound

{
    public static void main(String args[]) {
        Scanner obj = new Scanner(System.in);
        System.out.println("Enter the number of students");
        int n = obj.nextInt();
        int arr[] = new int[n];
        System.out.println("enter the element of the array");
        for (int i = 0; i < n; i++) {
            arr[i] = obj.nextInt();
        }

        // displaying the values on command of the user

        for (int i = 0; i < 10; i++) {

            try {
                int ans = arr[i];
                System.out.println("output : " + ans);
            } catch (Exception e) {
                // TODO: handle exception
                System.out.println("Something went gone");
                break;
            }
            obj.close();

        }

    }
}