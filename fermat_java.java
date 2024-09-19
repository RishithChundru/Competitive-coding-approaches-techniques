import java.util.Scanner;

public class fermat_java {

    public static Double isPrime(Double n, Double a) {
        Double org = n - 1;
        Double b = (Double) Math.pow(a, org); // Casting result to long to avoid overflow
        return b % n;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input
        System.out.print("Enter a prime number to check whether it is prime or not (n): ");
        Double n = scanner.nextDouble();
        System.out.print("Enter any positive number (a): ");
        Double a = scanner.nextDouble();

        // Check prime
        Double res = isPrime(n, a);
        if (res == 1) {
            System.out.println("It is a prime number.");
        } else {
            System.out.println("It is not a prime number.");
        }

        scanner.close();
    }
}
