#include <stdio.h>

float calculateCharges(float hours);

int main() {
    float hours1, hours2, hours3;
    float charge1, charge2, charge3, totalHours, totalCharge;

    // Enter hours for each customer
    printf("Enter hours parked for car 1: ");
    scanf("%f", &hours1);
    printf("Enter hours parked for car 2: ");
    scanf("%f", &hours2);
    printf("Enter hours parked for car 3: ");
    scanf("%f", &hours3);

    // Calculate charges for each customer
    charge1 = calculateCharges(hours1);
    charge2 = calculateCharges(hours2);
    charge3 = calculateCharges(hours3);

    // Calculate total hours and total charges
    totalHours = hours1 + hours2 + hours3;
    totalCharge = charge1 + charge2 + charge3;

    // Print results in tabular format
    printf("Car\tHours\tCharge\n");
    printf("1\t%.1f\t%.2f\n", hours1, charge1);
    printf("2\t%.1f\t%.2f\n", hours2, charge2);
    printf("3\t%.1f\t%.2f\n", hours3, charge3);
    printf("TOTAL\t%.1f\t%.2f\n", totalHours, totalCharge);
    
}

// Function to calculate parking charges based on the number of hours
float calculateCharges(float hours) {
    float charge = 2.0; // Minimum charge for up to 3 hours

    if (hours <= 3.0) {
        return charge;
    } else if (hours > 3.0 && hours <= 24.0) {
        // Additional $0.50 for each hour or part thereof over 3 hours
        charge += 0.5 * (hours - 3.0);
    }
    // Maximum charge for any 24-hour period is $10.00
    if (charge > 10.0) {
        charge = 10.0;
    }
    
    return charge;
}
