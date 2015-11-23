import java.util.Scanner;


public class ReadWriteCLI {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Input a string: ");
		String inputString = scanner.nextLine();
		System.out.println(inputString);
		
		System.out.print("Input a integer: ");
		int inputInteger = scanner.nextInt();
		System.out.println(inputInteger);
		
		System.out.print("Input another integer: ");
		int anotherInteger = scanner.nextInt();
		System.out.println(anotherInteger);
		
		int sumOfTwoInteger = inputInteger + anotherInteger;
		System.out.println("The sum of two integers is: " + sumOfTwoInteger);
		
		scanner.close();
		
	}

}
