#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book_t;
 

void print_book(struct Books *b) {

	int id = b->book_id;

   printf( "Book %d title : %s\n", id, b->title);
   printf( "Book %d author : %s\n",id,  b->author);
   printf( "Book %d subject : %s\n", id, b->subject);
   printf( "Book %d book_id : %d\n", id, b->book_id);
	printf("\n");

}

typedef int foo_t;

int main( ) {

	// foo_t Will = 100;

	int *p = (int*) malloc(1*sizeof(int));

	*p = 5;
	


   struct Books Book1;        /* Declare Book1 of type Book */
   struct Books Book2;        /* Declare Book2 of type Book */

	book_t *Book3 = malloc(1*sizeof(book_t));

	Book3->book_id = 42;

	print_book(Book3);
	
	// struct Books *Book3 = malloc(1*sizeof(struct Books));
   /* book 1 specification */
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali"); 
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   /* book 2 specification */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
 
   /* print Book1 info */
	print_book(&Book1);

	/* print Book2 info */
	print_book(&Book2);

   return 0;
}
