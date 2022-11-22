// gcc -Wall -o structEx -Wpedantic ./structEx.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Books {
   char  title[50]; // don't do this, do something like char* title here; and then later in the code (when you have size) do book1.title = malloc()
   char  author[50];
   char  subject[100];
   int   book_id;
} book_t; // declares the type stuct book as now book_t instead of struct Books

void print_book(struct Books *b) {

	int id = b->book_id;

	printf( "Book %d title : %s\n", id, b->title);
   	printf( "Book %d author : %s\n", id, b->author);
   	printf( "Book %d subject : %s\n", id, b->subject); // when using a pointer to a struct, has to do -> instead of a . as shown in book 2
   	printf( "Book %d book_id : %d\n", id, b->book_id);
   	printf("\n");
}

typedef int foo_t; // declares the type in as whatever you want (here its "foo_t")
 
int main( ) {

	foo_t Will = 100; // can use new type declared above instead of int
	printf("%d\n\n", Will);

   struct Books Book1;        /* Declare Book1 of type Book */
   struct Books Book2;        /* Declare Book2 of type Book */
   
   book_t Book3;
   
   book_t *Book4 = malloc(1*sizeof(book_t));
   // same as "struct Books *book4 = malloc(1*sizeof(struct Books));" see how its shorter the other way?
 
   /* book 1 specification */
   strcpy( Book1.title, "C Programming"); // you have to copy strings into the variable/array because strings suck in C
   strcpy( Book1.author, "Nuha Ali"); // strncpy will check and won't copy string if it can't fit in the assigned array
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   /* book 2 specification */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
   
   /* book 3 specification */
   strcpy( Book3.title, "My Life");
   strcpy( Book3.author, "Bob Marley");
   strcpy( Book3.subject, "Music and me: the life of Bob Marley");
   Book3.book_id = 6495565;
   
   /* book 4 specification */
   strcpy( Book4->title, "Brains and Their Pain");
   strcpy( Book4->author, "Snoop Dog");
   strcpy( Book4->subject, "How my brain was saved by music, drugs and cali");
   Book4->book_id = 6495062;
 
   /* print Book1 info */
   print_book(&Book1); // cleaner way to write a main file

   /* print Book2 info */
   printf( "Book 2 title : %s\n", Book2.title);
   printf( "Book 2 author : %s\n", Book2.author);
   printf( "Book 2 subject : %s\n", Book2.subject); // one other way to print but is messier for a main file
   printf( "Book 2 book_id : %d\n", Book2.book_id);
   printf("\n");
   
   /* print Book3 info */
   print_book(&Book3); // cleaner way to write a main file
  
   /* print Book4 info */
   print_book(Book4); // Book4 is already a pointer, so you just need to pass in Book4 here instead of an address

   return 0;
}
