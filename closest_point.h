
struct point{
    int x, y;
};
typedef struct point Point;

void generator_points(Point *p, int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        p[i].x = rand() % 20;
        p[i].y = rand() % 40;
    }
}

void vizualizare(Point *p, int n){
    for (int i = -4; i < 40; i++)
    {
        printf("=");
    }
    printf("\n");
    for (int i = 0; i < 20; i++)
    {
        printf("| ");
        for (int j = 0; j < 40; j++)
        {   
            for (int k = 0; k < n; k++)
            {
                if (p[k].x == i && p[k].y == j)
                {
                    printf("x");
                    k = 20;
                    j++;
                }
            }
            if (j != 40)
            {
                printf(" ");
            } 
        }
        printf(" %d\n",i+1);
    }
    for (int i = -4; i < 40; i++)
    {
        printf("=");
    }
    printf("\n");
}

void afisare(Point *p, int n){
    printf("Punctele generate:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Punctul x = %d y = %d ;\n", p[i].x+1, p[i].y+1);
    }  
}

int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}

float distance(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) );
}


float findminim(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (distance(P[i], P[j]) < min){
                min = distance(P[i], P[j]);
            }
                
    return min;
}
 
float minim(float x, float y)
{
    return (x < y)? x : y;
}
 
float midpointsClosest(Point midpoints[], int size, float d)
{
    float min = d; 
 
    qsort(midpoints, size, sizeof(Point), compareY);

    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (midpoints[j].y - midpoints[i].y) < min; ++j)
            if (distance(midpoints[i],midpoints[j]) < min){
                min = distance(midpoints[i], midpoints[j]);
            }
                
    return min;
}
 

float closest_point(Point P[], int n)
{
    if (n <= 3)
        return findminim(P, n);
 
    int mid = n/2;
    Point midPoint = P[mid];
 
    float dl = closest_point(P, mid);
    float dr = closest_point(P + mid, n-mid);
 
    float d = minim(dl, dr);

    Point midpoints[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            midpoints[j] = P[i], j++;
 
    return minim(d, midpointsClosest(midpoints, j, d) );
}
 
float closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);

    return closest_point(P, n);
}

void menu_closest_point(){
    Point *p;
    int n = 20;
    p = (Point *) malloc(n*sizeof(Point *));
    loading();
    system("cls"); 
    generator_points(p, n);
    afisare(p, n);
    vizualizare(p, n);
    printf("Distanta cea mai mica: %f ", closest(p, n));

    printf("\nApasati orice tasta pentru a prelungi...\n");
    system("pause");
    system("cls");
}