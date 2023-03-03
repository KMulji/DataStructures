
struct ArrayADT{
    int* A;
    int length;
    int size;
};
struct ArrayADT* Init(int size);
void Display(struct ArrayADT* x);
void Append(struct ArrayADT* x,int element);
void Insert(struct ArrayADT* x,int element,int index);
int Delete(struct ArrayADT* x, int index);
int LinearSearch(struct ArrayADT* x, int key);
int BinarySearch(struct ArrayADT *x, int key);

