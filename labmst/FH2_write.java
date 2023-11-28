package labmst;

// import java.util.*;
// import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

class FH2_write {
    public static void main(String args[]) {
        // File obj = new File("test.txt");

        try 
        {
            FileWriter file = new FileWriter("test.txt");
            file.write("hello this is a java text file by user!");
            file.close();
        }
        
        catch (IOException e) 
        {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}