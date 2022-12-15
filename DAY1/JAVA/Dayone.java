
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;
 
public class Dayone {

	public static void main(String[] args) {
		BufferedReader reader;
		int count = 0;
		int index = 0;
        List<Integer> elves = new ArrayList<Integer>();

		try {
			reader = new BufferedReader(new FileReader("DAY1/input.txt"));
			String line = reader.readLine();

			while (line != null) {
				if (line.matches("-?(0|[1-9]\\d*)"))
				{
					count = count + Integer.parseInt(line);
				} else {
					elves.add(count);
					count = 0;
				}
				
				line = reader.readLine();
			}
			// sort the list of elves calories from smallest to largest
			Collections.sort(elves);
			// print the elf with the maximum number of calories
			System.out.println(elves.get(elves.size()-1));
			int val = 0;
			count = 0;
			// find the top three max calories (since the list is sorted just pull the last three)
			for(index=1;index<=3;index++){
				val = elves.get(elves.size()-index);
				count = count + val;
				System.out.println(val);
			}
			System.out.println(count);
			reader.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}