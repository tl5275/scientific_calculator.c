#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);

double sin_func(double);
double cos_func(double);
double tan_func(double);
double cosec_func(double);
double sec_func(double);
double cot_func(double);
double log_func(double);
double exp_func(double);

double power(double, int);
unsigned long long factorial(int);

void displayMenu(void);

// Typedefs for function pointers
typedef double (*UnaryFunc)(double);
typedef double (*BinaryFunc)(double, double);

// Basic operations
double add(double a, double b)     { return a + b; }
double subtract(double a, double b){ return a - b; }
double multiply(double a, double b){ return a * b; }
double divide(double a, double b)  { return (b != 0) ? a / b : NAN; }

// Scientific functions
double sin_func(double x)          { return sin(x); }
double cos_func(double x)          { return cos(x); }
double tan_func(double x)          { return tan(x); }
double cosec_func(double x)        { return sin(x) != 0 ? 1.0 / sin(x) : NAN; }
double sec_func(double x)          { return cos(x) != 0 ? 1.0 / cos(x) : NAN; }
double cot_func(double x)          { return tan(x) != 0 ? 1.0 / tan(x) : NAN; }
double log_func(double x)          { return (x > 0) ? log(x) : NAN; }
double exp_func(double x)          { return exp(x); }

// Recursive functions
double power(double base, int exp) {
    if (exp == 0) return 1;
    return base * power(base, exp - 1);
}

unsigned long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Display menu
void displayMenu() {
    printf("\n--- Scientific Calculator ---\n");
    printf(" 1. Add           2. Subtract\n");
    printf(" 3. Multiply      4. Divide\n");
    printf(" 5. Sine          6. Cosine\n");
    printf(" 7. Tangent       8. Cosec\n");
    printf(" 9. Sec          10. Cot\n");
    printf("11. Log          12. Exp\n");
    printf("13. Power        14. Factorial\n");
    printf(" 0. Exit\n");
    printf("----------------------------\n");
}

int main() {
    int choice;
    double *a = malloc(sizeof(double));
    double *b = malloc(sizeof(double));

    if (!a || !b) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) break;

        // Inputs
        if (choice >= 1 && choice <= 4 || choice == 13) {
            printf("Enter two numbers: ");
            scanf("%lf %lf", a, b);
        } else if ((choice >= 5 && choice <= 12) || choice == 14) {
            printf("Enter one number: ");
            scanf("%lf", a);
        }

        // Operations
        switch (choice) {
            case 1:  printf("Result: %.2lf\n", add(*a, *b)); break;
            case 2:  printf("Result: %.2lf\n", subtract(*a, *b)); break;
            case 3:  printf("Result: %.2lf\n", multiply(*a, *b)); break;
            case 4:  
                if (*b == 0) printf("Error: Division by zero!\n");
                else printf("Result: %.2lf\n", divide(*a, *b));
                break;
            case 5:  printf("Result: %.2lf\n", sin_func(*a)); break;
            case 6:  printf("Result: %.2lf\n", cos_func(*a)); break;
            case 7:  printf("Result: %.2lf\n", tan_func(*a)); break;
            case 8:  
                if (sin(*a) == 0) printf("Error: Cosec undefined!\n");
                else printf("Result: %.2lf\n", cosec_func(*a));
                break;
            case 9:  
                if (cos(*a) == 0) printf("Error: Sec undefined!\n");
                else printf("Result: %.2lf\n", sec_func(*a));
                break;
            case 10: 
                if (tan(*a) == 0) printf("Error: Cot undefined!\n");
                else printf("Result: %.2lf\n", cot_func(*a));
                break;
            case 11: 
                if (*a <= 0) printf("Error: Log domain error!\n");
                else printf("Result: %.2lf\n", log_func(*a));
                break;
            case 12: printf("Result: %.2lf\n", exp_func(*a)); break;
            case 13: printf("Result: %.2lf\n", power(*a, (int)*b)); break;
            case 14: 
                if (*a < 0) printf("Error: Factorial of negative number!\n");
                else printf("Result: %llu\n", factorial((int)*a));
                break;
            default: printf("Invalid choice. Please try again.\n");
        }
    }

    free(a);
    free(b);
    printf("Calculator closed.\n");
    return 0;
}
