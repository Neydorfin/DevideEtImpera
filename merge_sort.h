
int x = 0;
void merge(int vector[100], int leftarr[100], int rightarr[100], int sizeleft, int sizeright)
{
    int arrind = 0, lind = 0, rind = 0;

    while(lind < sizeleft && rind < sizeright)
    {
        if(leftarr[lind] <= rightarr[rind])
        {
            vector[arrind] = leftarr[lind];
            lind++;
        }
        else
        {
            vector[arrind] = rightarr[rind];
            rind++;
        }
        arrind++;
    }

    while (lind < sizeleft)
    {
        vector[arrind] = leftarr[lind];
        lind++;
        arrind++;
    }
    while (rind < sizeright)
    {
        vector[arrind] = rightarr[rind];
        rind++;
        arrind++;
    }
    printf("\nPartea dupa sortare :\t ");
    for (int i = 0; i < arrind; i++)
    {
        printf("%d ", vector[i]);
    }
}


void mergesort(int vector[100], int n)
{
    if(n < 2)
    {
        return;
    }
    int mid = n/2;
    int leftarr[mid], rightarr[n-mid];

    for(int i = 0; i < mid; i++)
    {
        leftarr[i] = vector[i];
    }
    for(int i = mid; i < n; i++)
    {
        rightarr[i-mid] = vector[i];
    }
    printf("\n-----------Sortarea dupa %d iteratie:---------\n", ++x);
    printf("\nPartea de stanga :\t ");
    for (int i = 0; i < mid; i++)
    {
        printf("%d ", leftarr[i]);
    }
    printf("\nPartea de drepta :\t ");
    for (int i = 0; i < n-mid; i++)
    {
        printf("%d ", rightarr[i]);
    }
    mergesort(leftarr , mid);
    mergesort(rightarr, n-mid);
    merge(vector, leftarr, rightarr, mid, n-mid);
}

void menu_merge_sort(){
    system("cls");
    int vector[20];
    generator(20,vector);
    x = 0;
    mergesort(vector, 20);
    printf("\nApasati orice tasta pentru a prelungi...\n");
    system("pause");
    system("cls");
}