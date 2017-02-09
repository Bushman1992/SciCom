#include <stdio.h>

struct particle {
	int id;
	double radius;
	double x;
	double y;
	double v;
};

struct cell {
	double xMin, xMax;
	double yMin, yMax;
	struct node * head;
};

struct node {
	struct particle * data;
	struct node * next;
};

void ll_InsertFront(struct node ** head_in, struct particle ** part_in)
{
	struct node * newNode = (struct node *) malloc(sizeof(struct node));
	// Assign previous node to new node.
	newNode->next = * head_in;
	newNode->data = * part_in;
	// Assign new node to head.
	* head_in = newNode;
}

void ll_PrintParticleIds(struct node ** head_in)
{
	struct node * ptr = * head_in;
	while (ptr != NULL) {
		printf("(%d) ", ptr->data->id);
		ptr = ptr->next;
	}
	printf("\n");
}

int main(void) 
{
	// Create cell
	struct cell * cell1 = (struct cell *) malloc(sizeof(struct cell));
	cell1->head = NULL;
	cell1->xMin = 0.0;
	cell1->xMax = 0.5;
	cell1->yMin = 0.0;
	cell1->xMax = 0.5;

	// Create particle 1
	struct particle * part1 = (struct particle *) malloc(sizeof(struct particle));
	part1->id = 1;
	// Create particle 2
	struct particle * part2 = (struct particle *) malloc(sizeof(struct particle));
	part2->id = 2;

	// Insert particles in cell
	ll_InsertFront(&cell1->head, &part1);
	ll_InsertFront(&cell1->head, &part2);

	ll_PrintParticleIds(&cell1->head);
	getchar();

	return 0;
}