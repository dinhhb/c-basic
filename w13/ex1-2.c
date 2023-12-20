#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    char dob[11];
} EmployeeProfile;

void generateRandomProfiles(int n) {
    FILE *file;
    file = fopen("profile-n.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    srand(time(0)); // Seed for randomization

    for (int i = 0; i < n; i++) {
        EmployeeProfile profile;
        // Generate random name
        char firstNames[10][10] = {"John", "Emma", "Michael", "Sophia", "William", "Olivia", "James", "Ava", "Alexander", "Isabella"};
        char lastNames[10][10] = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};
        sprintf(profile.name, "%s %s", firstNames[rand() % 10], lastNames[rand() % 10]);
        // Generate random date of birth
        int year = 1950 + rand() % 50;
        int month = 1 + rand() % 12;
        int day = 1 + rand() % 28; // Assuming all months have 28 days for simplicity
        sprintf(profile.dob, "%04d-%02d-%02d", year, month, day);
        // Write to file
        fprintf(file, "%s\n%s\n", profile.name, profile.dob);
    }

    fprintf(file, "#"); // End of file marker
    fclose(file);
}

int main() {
    int n;
    printf("Enter the number of profiles to generate: ");
    scanf("%d", &n);
    generateRandomProfiles(n);
    printf("Profiles generated and written to file profile-n.txt\n");
    return 0;
}