import java.io.*;
import java.util.*;

public class SimpleDictionary {
    public static void main(String[] args) {
        HashMap<String, String> map = new HashMap<>();
        // Read from the input file
        try
        {
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));
            String line;
            while ((line = br.readLine()) != null)
            {
                String[] s = line.split(" = ");
                map.put(s[0], s[1]);
            }
            br.close();
        }
        catch (IOException e) {
            System.out.println("Exception");
        }

        // Take input from user
        System.out.println("Enter a Word: ");
        Scanner sc = new Scanner(System.in);
        String word = sc.nextLine();

        // Write to to output file
        try 
        {
            BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));

            if (map.containsKey(word))
            {
                System.out.println("Meaning: " + map.get(word));
                //bw.write(word + " = " + map.get(word) + '\n');
            }
            else 
            {   // if word doesn't esits in map then we ad it to map and write on output 
                System.out.println("No word fond. Make an entry: ");
                String meaning = sc.nextLine();
                map.put(word, meaning);
            }
            // write all entry to the output
            for (String k: map.keySet())
            {
                bw.write(k + " = " + map.get(k) + '\n');
                // bw.write(word + " = " + meaning);
            }
            bw.close();
        }
        catch (IOException e)
        {
            System.out.println("Exception");
        }
        sc.close();
    }
}
