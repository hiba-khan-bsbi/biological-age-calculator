#include <stdio.h>
#include <string.h>

#define MAX_DISEASES 10
#define TOTAL_OPTIONS 7

struct Person {
    char name[50];
    int age;
    int smoker;
    int exercise;
    float sleep;
    float weight;
    float height;
    int diseaseCount;
    char diseases[MAX_DISEASES][30];
};

// BMI
float calculateBMI(float w, float h) {
    return w / (h * h);
}

// Telomere
float calculateTelomere(struct Person p) {
    float sleep_deficit = 8 - p.sleep;
    if (sleep_deficit < 0) sleep_deficit = 0;

    return 8000
           - (p.age * 25)
           - (p.smoker * 600)
           - (sleep_deficit * 150)
           + (p.exercise * 40)
           - (p.diseaseCount * 500);
}

// DNA
float calculateDNA(struct Person p, float bmi) {
    float sleep_deficit = 8 - p.sleep;
    if (sleep_deficit < 0) sleep_deficit = 0;

    return (p.diseaseCount * 600)
           + (bmi * 4)
           + (sleep_deficit * 40);
}

// BCI
float calculateBCI(struct Person p, float bmi) {
    return (p.exercise * 10)
           + (p.sleep * 5)
           - (bmi * 2);
}

// Biological Age
int calculateBioAge(struct Person p) {
    float bmi, TL, DD, BCI;
    float diseasePenalty;
    int bioAge;

    bmi = calculateBMI(p.weight, p.height);
    TL = calculateTelomere(p);
    DD = calculateDNA(p, bmi);
    BCI = calculateBCI(p, bmi);

    diseasePenalty = p.diseaseCount * 3.5;

    bioAge = p.age
             + (DD / 180)
             + diseasePenalty
             + ((8000 - TL) / 1500)
             - (BCI / 90);

    if (bioAge < p.age)
        bioAge = p.age;

    return bioAge;
}

// Disease input
void inputDiseases(struct Person *p) {
    int choice, option, i;

    char *diseaseOptions[TOTAL_OPTIONS] = {
        "Diabetes",
        "Hypertension",
        "Heart Disease",
        "Obesity",
        "Anemia",
        "Thyroid",
        "Kidney Disease"
    };

    int selected[TOTAL_OPTIONS];

    p->diseaseCount = 0;

    for (i = 0; i < TOTAL_OPTIONS; i++)
        selected[i] = 0;

    do {
        printf("\nSelect disease:\n");

        for (i = 0; i < TOTAL_OPTIONS; i++) {
            printf("%d. %s\n", i + 1, diseaseOptions[i]);
        }

        printf("Enter choice (1-7): ");
        scanf("%d", &option);

        if (option < 1 || option > 7) {
            printf("Invalid choice!\n");
            continue;
        }

        if (selected[option - 1] == 0) {
            strcpy(p->diseases[p->diseaseCount], diseaseOptions[option - 1]);
            selected[option - 1] = 1;
            p->diseaseCount++;
        } else {
            printf("Already selected!\n");
        }

        printf("Add more? (1=Yes, 0=No): ");
        scanf("%d", &choice);

    } while (choice == 1);
}


void showDiet(struct Person p) {
    int i;

    printf("\n===== DIET PLAN BASED ON DISEASES =====\n");

    for (i = 0; i < p.diseaseCount; i++) {

        printf("\nFor %s, take:\n", p.diseases[i]);

        if (strcmp(p.diseases[i], "Diabetes") == 0) {
            printf("- Low sugar diet\n- Whole grains\n- Avoid sweets\n");
        }

        else if (strcmp(p.diseases[i], "Hypertension") == 0) {
            printf("- Low salt diet\n- Fresh vegetables\n- Avoid processed food\n");
        }

        else if (strcmp(p.diseases[i], "Heart Disease") == 0) {
            printf("- Low fat diet\n- Omega 3 foods\n- Avoid fried items\n");
        }

        else if (strcmp(p.diseases[i], "Obesity") == 0) {
            printf("- High protein diet\n- Low calorie food\n- No junk food\n");
        }

        else if (strcmp(p.diseases[i], "Anemia") == 0) {
            printf("- Iron rich foods\n- Spinach, liver\n- Vitamin C foods\n");
        }

        else if (strcmp(p.diseases[i], "Thyroid") == 0) {
            printf("- Balanced iodine diet\n- Regular meals\n- Avoid excess soy\n");
        }

        else if (strcmp(p.diseases[i], "Kidney Disease") == 0) {
            printf("- Low protein diet\n- Low salt\n- Controlled fluids\n");
        }
    }

    printf("\n===== FINAL GENERAL DIET =====\n");

    if (p.diseaseCount > 0) {
        printf("- Follow all disease-specific diets strictly\n");
        printf("- Avoid sugar, salt, and fried food\n");
        printf("- Eat natural foods and stay hydrated\n");
    } else {
        printf("- Maintain balanced healthy diet\n");
    }
}

// Main process
void processPerson() {
    struct Person p;
    int hasDisease, bio_age, diff;
    float bmi;

    getchar();

    printf("Enter name: ");
    fgets(p.name, sizeof(p.name), stdin);

    printf("Enter age: ");
    scanf("%d", &p.age);

    printf("Smoker? (1/0): ");
    scanf("%d", &p.smoker);

    printf("Exercise hours/week: ");
    scanf("%d", &p.exercise);

    printf("Sleep hours: ");
    scanf("%f", &p.sleep);

    printf("Weight: ");
    scanf("%f", &p.weight);

    printf("Height: ");
    scanf("%f", &p.height);

    printf("Do you have diseases? (1/0): ");
    scanf("%d", &hasDisease);

    if (hasDisease == 1)
        inputDiseases(&p);
    else
        p.diseaseCount = 0;

    bmi = calculateBMI(p.weight, p.height);
    bio_age = calculateBioAge(p);
    diff = bio_age - p.age;

    printf("\n===== HEALTH REPORT =====\n");
    printf("Name: %s", p.name);
    printf("Actual Age: %d\n", p.age);
    printf("Biological Age: %d\n", bio_age);

    if (diff > 0)
        printf("Aging faster by %d years\n", diff);
    else
        printf("Normal aging pattern\n");

    if (p.diseaseCount > 0) {
        printf("\nDiseases:\n");
        int i;
        for (i = 0; i < p.diseaseCount; i++) {
            printf("- %s\n", p.diseases[i]);
        }
    }

    showDiet(p);
}

// Menu
int main() {
    int choice;

    do {
        printf("\n==== BIOLOGICAL AGE SYSTEM ====\n");
        printf("1. New Assessment\n");
        printf("2. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            processPerson();
        else if (choice == 2)
            printf("Exiting...\n");
        else
            printf("Invalid choice\n");

    } while (choice != 2);

    return 0;
}
