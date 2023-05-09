
int iter = 0;
void quicksort(int vector[20], int start, int end){
    if(start >= end)
    {
        return;
    }
    int pivot;
    pivot = particion(vector, start, end);
    printf("\nSortarea dupa %d iteratie:\n", ++iter);
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n----------------------------------------------\n");
    quicksort(vector, start, pivot-1);
    quicksort(vector, pivot+1,end);
}

int particion(int *vector, int start, int end )
{
    int value = vector[end], pos = start;

    for (int i = start; i < end; i++)
    {
        if (vector[i] <= value)
        {
            int temp;
            temp = vector[i];
            vector[i] = vector[pos];
            vector[pos] = temp;
            pos++;
        }
    }
    vector[end] = vector[pos];
    vector[pos] = value;
    return pos;
}

void quicksortvector(int n, int vector[n], int start, int end){
    if(start >= end)
    {
        return;
    }
    int pivot;
    pivot = particion(vector, start, end);
    quicksortvector(n, vector, start, pivot-1);
    quicksortvector(n, vector, pivot+1,end);
}

void menu_quick_sort(){
    system("cls");
    int vector[20];
    generator(20,vector);
    iter = 0;
    quicksort(vector, 0, 19);
    printf("\nApasati orice tasta pentru a prelungi...\n");
    system("pause");
    system("cls");
}