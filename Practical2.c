#include <stdio.h>

int main()
{
    int a[100], n, i, pos, item, choice, found;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    do
    {
        printf("\n\n1. Traversal");
        printf("\n2. Insertion");
        printf("\n3. Deletion");
        printf("\n4. Searching");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Array elements are: ");
                for (i = 0; i < n; i++)
                    printf("%d ", a[i]);
                break;

            case 2:
                printf("Enter position and element: ");
                scanf("%d %d", &pos, &item);

                if (pos < 1 || pos > n + 1 || n >= 100)
                {
                    printf("Invalid position or array is full!");
                    break;
                }

                for (i = n; i >= pos; i--)
                    a[i] = a[i - 1];

                a[pos - 1] = item;
                n++;

                printf("Element inserted successfully.");
                break;

            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);

                if (pos < 1 || pos > n)
                {
                    printf("Invalid position!");
                    break;
                }

                for (i = pos - 1; i < n - 1; i++)
                    a[i] = a[i + 1];

                n--;

                printf("Element deleted successfully.");
                break;

            case 4:
                printf("Enter element to search: ");
                scanf("%d", &item);

                found = 0;

                for (i = 0; i < n; i++)
                {
                    if (a[i] == item)
                    {
                        printf("Element found at position %d", i + 1);
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                    printf("Element not found.");

                break;

            case 5:
                printf("Exiting program.");
                break;

            default:
                printf("Invalid choice!");
        }

    } while (choice != 5);

    return 0;
}
