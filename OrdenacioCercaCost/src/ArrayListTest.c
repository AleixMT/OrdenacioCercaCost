//
// Created by Sergi Vives on 21/5/2020.
//
#include "ArrayList.h"

const unsigned int sizes[] = {10, 50, 100, 1000, 2000, 5000, 10000};
const unsigned int number_sizes = 7, number_samples = 10, number_tests = 3, number_parameters = 3;

int sum(int array[], unsigned int num_elements)
{
    int sum = 0;
    for (int i = 0; i < num_elements; i++)
    {
        sum += array[i];
    }
    return sum;
}

double* calculateMetrix(int array[number_sizes][number_samples])
{
    double result[7][3];
    int sum = 0;
    for (int i = 0; i < number_sizes; i++)
    {
        result[i][0] = sizes[i];
    }
    for (int i = 0; i < number_sizes; i++)
    {
        result[i][1] = sum(array[i]) / number_samples;
    }
    for (int i = 0; i < number_sizes; i++)
    {
        array[i][2] = 0;
        for (int j = 0; j < number_samples; j++)
        {
            result[i][2] += (array[i][j] - result[i][1]) * (array[i][j] - result[i][1]);
        }
        result[i][2] = math.sqrt(result[i][2] / number_samples);

    }
    return result;
}

void printResults(double results[number_sizes][number_parameters])
{
    printf("\n Mida   Mitjana   Desviació\n");
    for (int i = 0; i < number_sizes; i++)
    {
        for (int j = 0; j < number_parameters; j++)
        {
            printf(" %d ", results[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {

    srand(time(NULL));

    // Populate
    ArrayList *arrayList;
	create(&arrayList);
    populate(arrayList, 100);
    printf("%s", toString(*arrayList));
    destroy(&arrayList);

    // Bubble Sort
    create(&arrayList);
    populate(arrayList, 100);
    sortBubble(&arrayList);
    printf("%s", toString(*arrayList));
    destroy(&arrayList);

    // Dicotomic Search
    create(&arrayList);
    populate(arrayList, 1000);
    sortBubble(&arrayList);
    printf("%s", toString(*arrayList));
    destroy(&arrayList);

    // Binary search
    create(&arrayList);
    populate(arrayList, 1000);
    sortBubble(&arrayList);
    searchBinary(*arrayList, )
    printf("%s", toString(*arrayList));
    destroy(&arrayList);

    // Results
    unsigned int results_present_element[7][10];
    unsigned int results_random_element[7][10];
    unsigned int results_not_present_element[7][10];
    double parameters_present_element[7][3];
    double parameters_random_element[7][3];
    double parameters_not_present_element[7][3];

    for (int i = 0; i < number_sizes; i++)
    {
        for (int num_testing = 0; num_testing < number_tests; num_testing++)
        {
            for (int j = 0; j < number_samples; j++)
            {
                create(&arrayList);
                populate(arrayList, sizes[i]);
                sortBubble(arrayList);
                int counter;
                switch (num_testing)
                {
                    case 0:
                    {
                        searchBinary(*arrayList, get(*arrayList, rand() % arrayList->num_elements), &counter);
                        results_present_element[i][j] = counter;
                        break;
                    }
                    case 1:
                    {
                        searchBinary(*arrayList, rand(), &counter);
                        results_random_element[i][j] = counter;
                        break;
                    }
                    case 2:
                    {
                        unsigned int random_not_present;
                        while (searchBinary(*arrayList, random_not_present = rand(), &counter) {}
                        results_not_present_element[i][j] = counter;
                        break;
                    }
                }
                destroy(&arrayList);
            }
        }
    }
    parameters_present_element = calculateMetrix(results_present_element);
    parameters_random_element = calculateMetrix(results_random_element)
    parameters_not_present_element = calculateMetrix(results_not_present_element);



	printf("Get 0, 4, ultim llista: %u %u %u\n", get(*arrayList, 0), get(*arrayList, 4), get(*arrayList, arrayList->num_elements - 1));
	printf("%s", toString(*arrayList));

}