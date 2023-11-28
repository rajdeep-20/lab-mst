package labmst;
// import java.util.*;
import java.io.File;

class FH1 
{
    public static void main(String args[]) {
        // Scanner obj = new Scanner(System.in);

        File obj = new File("first.txt");
        // System.out.println("file created" + obj.getAbsolutePath());
        System.out.println("file created:   " + obj.getName());

    }
}