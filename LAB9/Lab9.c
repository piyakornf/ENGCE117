#include <stdio.h>
#include <string.h>

struct studentNode {
	char name[ 20 ] ;
	int age ;
	char sex ;
	float gpa ;
	struct studentNode *next ;
} ;

class LinkedList {
	protected :
		struct studentNode *start, **now ;
	public :
		LinkedList() ;
		~LinkedList() ;
		void InsNode( char n[], int a, char s, float g ) ;
		void DelNode() ;
		void GoNext() ;
		void GoFirst() ;
		void GoLast() ;
		void ShowAll() ;
		int FindNode( char n[] ) ;
		struct studentNode *NowNode() ;
		void EditNode( char n[], int a, char s, float g ) ;
} ; 

void EditData( LinkedList *ll ) ;
void AddData( LinkedList *ll ) ;
void FindData( LinkedList *ll ) ;
void readfile( LinkedList *ll ) ;
void writefile( LinkedList *ll ) ;

int main() {
    LinkedList listA;
    int menu;

    readfile(&listA);
    printf("\nMenu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit: ");
    scanf("%d", &menu);

    while(menu != 0) {
        switch(menu) {
            case 1: AddData(&listA); break;
            case 2: EditData(&listA); break;
            case 3: listA.DelNode(); break;
            case 4: FindData(&listA); break;
            case 5: listA.ShowAll(); break;
        }
        printf("\nMenu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit: ");
        scanf("%d", &menu);
    }
    writefile(&listA);
    return 0;
}

LinkedList::LinkedList() {
    start = NULL;
    now = &start;
}

LinkedList::~LinkedList() {
    struct studentNode *temp;
    while (start != NULL) {
        temp = start;
        start = start->next;
        delete temp;
    }
}

void LinkedList::InsNode(char n[], int a, char s, float g) {
    struct studentNode *newNode = new struct studentNode;
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = *now;
    *now = newNode;
}

void LinkedList::DelNode() {
    if (*now != NULL) {
        struct studentNode *temp = *now;
        *now = (*now)->next;
        delete temp;
        printf("Deleted successfully.\n");
    } else {
        printf("No node to delete.\n");
    }
}

void LinkedList::GoFirst() {
    now = &start;
}

void LinkedList::GoNext() {
    if (*now != NULL) {
        now = &((*now)->next);
    }
}

void LinkedList::ShowAll() {
    struct studentNode *temp = start;
    printf("\n--- Student List ---\n");
    while (temp != NULL) {
        printf("Name: %-15s | Age: %d | Sex: %c | GPA: %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
        temp = temp->next;
    }
    printf("--------------------\n");
}

int LinkedList::FindNode(char n[]) {
    GoFirst();
    while (*now != NULL) {
        if (strcmp((*now)->name, n) == 0) return 1;
        GoNext();
    }
    return 0;
}

struct studentNode* LinkedList::NowNode() {
    return *now;
}

void LinkedList::EditNode(char n[], int a, char s, float g) {
    if (*now != NULL) {
        strcpy((*now)->name, n);
        (*now)->age = a;
        (*now)->sex = s;
        (*now)->gpa = g;
    }
}

void AddData(LinkedList *ll) {
    char n[20], s;
    int a;
    float g;
    printf("Enter Name: "); scanf("%s", n);
    printf("Enter Age: "); scanf("%d", &a);
    printf("Enter Sex (M/F): "); scanf(" %c", &s);
    printf("Enter GPA: "); scanf("%f", &g);
    ll->GoFirst(); // เพิ่มไว้หน้าสุด หรือจะใช้ GoLast ก็ได้
    ll->InsNode(n, a, s, g);
}

void EditData(LinkedList *ll) {
    char n[20], newN[20], s;
    int a;
    float g;
    printf("Enter Name to Edit: "); scanf("%s", n);
    if (ll->FindNode(n)) {
        printf("Enter New Name: "); scanf("%s", newN);
        printf("Enter New Age: "); scanf("%d", &a);
        printf("Enter New Sex: "); scanf(" %c", &s);
        printf("Enter New GPA: "); scanf("%f", &g);
        ll->EditNode(newN, a, s, g);
        printf("Updated!\n");
    } else {
        printf("Student not found.\n");
    }
}

void FindData(LinkedList *ll) {
    char n[20];
    printf("Enter Name to Find: "); scanf("%s", n);
    if (ll->FindNode(n)) {
        struct studentNode *node = ll->NowNode();
        printf("Found: %s, Age: %d, GPA: %.2f\n", node->name, node->age, node->gpa);
    } else {
        printf("Student not found.\n");
    }
}

void readfile(LinkedList *ll) {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) return;
    struct studentNode temp;
    while (fread(&temp, sizeof(struct studentNode) - sizeof(struct studentNode*), 1, fp)) {
        ll->GoFirst();
        ll->InsNode(temp.name, temp.age, temp.sex, temp.gpa);
    }
    fclose(fp);
}

void writefile(LinkedList *ll) {
    FILE *fp = fopen("students.dat", "wb");
    if (fp == NULL) return;
    ll->GoFirst();
    struct studentNode *curr;
    while ((curr = ll->NowNode()) != NULL) {
        fwrite(curr, sizeof(struct studentNode) - sizeof(struct studentNode*), 1, fp);
        ll->GoNext();
    }
    fclose(fp);
    printf("Data saved to students.dat\n");
}