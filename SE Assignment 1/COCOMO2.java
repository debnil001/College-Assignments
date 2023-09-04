import java.util.Scanner;

class COCOMOII {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("COCOMO II Calculator Menu:");
            System.out.println("1. Calculate Object Points (OP)");
            System.out.println("2. Calculate New Object Points (NOP)");
            System.out.println("3. Calculate Effort");
            System.out.println("4. Calculate Number of People (for 5 years duration)");
            System.out.println("5. Exit");
            System.out.print("Enter your choice (1/2/3/4/5): ");

            int choice = scanner.nextInt();

            if (choice == 5) {
                System.out.println("Exiting COCOMO II Calculator. Goodbye!");
                break;
            }

            if (choice < 1 || choice > 5) {
                System.out.println("Invalid choice. Please enter 1, 2, 3, 4, or 5.");
                continue;
            }

            switch (choice) {
                case 1:
                    calculateObjectPoints();
                    break;
                case 2:
                    calculateNewObjectPoints();
                    break;
                case 3:
                    calculateEffort();
                    break;
                case 4:
                    calculateNumberOfPeople();
                    break;
            }
        }

        scanner.close();
    }

    private static void calculateObjectPoints() {
        int screens = 10;
        int reports = 4;
        int components = 15;

        double objectPoints = screens + reports + (components * 2.4);
        System.out.println("Object Points (OP) for the software: " + objectPoints);
    }

    private static void calculateNewObjectPoints() {
        // Assuming 60% reuse
        int screens = 10;
        int reports = 4;
        int components = 15;

        double newObjectPoints = (screens + reports + (components * 2.4)) * 0.4;
        System.out.println("New Object Points (NOP) for the software: " + newObjectPoints);
    }

    private static void calculateEffort() {
        // Assuming effort = 2.94 * NOP^1.14 (COCOMO II model)
        double newObjectPoints = ((10 + 4 + (15 * 2.4)) * 0.4);
        double effort = 2.94 * Math.pow(newObjectPoints, 1.14);
        System.out.println("Effort required to develop the software: " + effort + " person-months");
    }

    private static void calculateNumberOfPeople() {
        // Assuming 5 years duration and effort = 2.94 * NOP^1.14
        double newObjectPoints = ((10 + 4 + (15 * 2.4)) * 0.4);
        double effort = 2.94 * Math.pow(newObjectPoints, 1.14);
        int durationInMonths = 5 * 12;
        double numberOfPeople = effort / durationInMonths;
        System.out.println("Number of people required for 5 years duration: " + numberOfPeople);
    }
}

