import java.util.Scanner;

class COCOMOCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("COCOMO I Calculator Menu:");
            System.out.println("1. Calculate Effort");
            System.out.println("2. Calculate Duration");
            System.out.println("3. Calculate Number of People");
            System.out.println("4. Exit");
            System.out.print("Enter your choice (1/2/3/4): ");

            int choice = scanner.nextInt();

            if (choice == 4) {
                System.out.println("Exiting COCOMO I Calculator. Goodbye!");
                break;
            }

            if (choice < 1 || choice > 3) {
                System.out.println("Invalid choice. Please enter 1, 2, 3, or 4.");
                continue;
            }

            System.out.print("Enter Lines of Code (LOC): ");
            double loc = scanner.nextDouble();

            System.out.print("Enter Effort Adjustment Factor (EAF): ");
            double eaf = scanner.nextDouble();

            switch (choice) {
                case 1:
                    calculateEffort(loc, eaf);
                    break;
                case 2:
                    calculateDuration(loc, eaf);
                    break;
                case 3:
                    calculateNumberOfPeople(loc, eaf);
                    break;
            }
        }

        scanner.close();
    }

    private static void calculateEffort(double loc, double eaf) {
        double a = 2.4;
        double b = 1.05;
        double effort = a * Math.pow(loc, b) * eaf;
        System.out.println("Effort required to develop the software: " + effort + " person-months");
    }

    private static void calculateDuration(double loc, double eaf) {
        double a = 2.4;
        double b = 1.05;
        double effort = a * Math.pow(loc, b) * eaf;
        System.out.println("Enter the type of project:");
        System.out.println("1. Organic");
        System.out.println("2. Semi-detached");
        System.out.println("3. Embedded");
        System.out.print("Enter project type (1/2/3): ");
        Scanner scanner = new Scanner(System.in);
        int projectType = scanner.nextInt();

        double duration;
        if (projectType == 1) {
            duration = 2.5 * Math.pow(effort, 0.38);
        } else if (projectType == 2) {
            duration = 2.5 * Math.pow(effort, 0.35);
        } else if (projectType == 3) {
            duration = 2.5 * Math.pow(effort, 0.32);
        } else {
            System.out.println("Invalid project type.");
            return;
        }
        System.out.println("Duration required to develop the software: " + duration + " months");
    }

    private static void calculateNumberOfPeople(double loc, double eaf) {
        double a = 2.4;
        double b = 1.05;
        double effort = a * Math.pow(loc, b) * eaf;
        System.out.print("Enter the expected productivity (person-months per person): ");
        Scanner scanner = new Scanner(System.in);
        double productivity = scanner.nextDouble();
        double numberOfPeople = effort / (productivity * 12); // Assuming 12 months in a year
        System.out.println("Number of people required to develop the software: " + numberOfPeople);
    }
}
