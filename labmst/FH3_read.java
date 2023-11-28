package labmst;
import java.util.*;
import java.io.File;
import java.io.FileNotFoundException;


class FH3_read {
    public static void main(String args[]) {

      try{
        File f = new File("test1.txt");
        Scanner obj = new Scanner(f);


        String s = "";
        while (obj.hasNextLine()) {
            String data = obj.nextLine();
            s = s + data;
        }
        System.out.println("content of the file: \n" + s);

        obj.close();
    }
    catch (FileNotFoundException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
}
}