import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

/*
 * Idea:
 * Maintain two sets: Candidate set and Matched set
 * Initially add all numbers into Candidate set
 * Initialize a Matched Pairs hash map HashMap<List<Integer>, Integer>
 * For each number in Candidate set:
 * 		For each pair in Matched Pairs:
 * 			If a three sum appears:
 * 				Add it into results
 * 		For each number in Matched set:
 * 			Create a pair, add it into Matched Pairs hash map
 * 		Remove this number from Candidate set
 * 		Add this number into Matched set
 */
public class ThreeSum {
    public ArrayList<ArrayList<Integer>> threeSum(int[] nums) {
    	Arrays.sort(nums);
    	for (int i = 0 ; i < nums.length; i++) {
    		System.out.print(nums[i]);
    		System.out.print(" ");
    	}
    	System.out.print("\n");
    	
    	ArrayList<ArrayList<Integer>> results = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < nums.length; i++) {
        	for (int j = i + 1; j < nums.length; j++) {
        		for (int k = j + 1; k < nums.length; k++) {
        			if (nums[i] + nums[j] + nums[k] == 0)
        			{
        				ArrayList<Integer> result = new ArrayList();
        			}
        		}
        	}
        }
        return results;
    }
	public static void main(String[] args) {
		int[] nums = new int[] {-1, 0, 1, 2, -1, 4};
		ThreeSum solution = new ThreeSum();
		ArrayList<ArrayList<Integer>> results = solution.threeSum(nums);
	}

}
