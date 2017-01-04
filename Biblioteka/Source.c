#include <stdio.h>

struct Date
{
	int Year;
	int Month;
	int Day;
};
struct Book
{
	int ID;
	char* Title;
	char* AuthorFirstName;
	char* AuthorLastName;
	char* Category;
	char* FirstName;
	char* LastName;
	struct Date DateOfHire;
	struct Book* next;
	struct Book* previous;

};

struct List
{
	int Count;
	struct Book* FirstElement;
	struct Book* LastElement;
} list;

void Add(struct List* list, struct Book* book)
{
	if(list->FirstElement == NULL)
	{
		list->FirstElement = book;
		list->LastElement = book;
		book->next = NULL;
		book->previous = NULL;
		list->Count++;
		return;
	}
	if(list->FirstElement->next == NULL)
	{
		list->FirstElement->next = book;
		list->LastElement->previous = list->FirstElement;
	}
	book->previous = list->LastElement;
	list->LastElement->next = book;
	list->LastElement = book;
	list->LastElement->previous = book->previous;

	list->FirstElement->previous = list->LastElement;
	book->next = list->FirstElement;
	
	list->Count++;
}

void Print(struct List* list)
{
	struct Book* book = list->FirstElement;
	while (book != list->LastElement->next)
	{
		printf("Book ID: %d, Book name: %s \n",book->ID, book->Title);
		book = book->next;
	}
}

void PrintList(struct List* list)
{
	struct Book* current = list->FirstElement;
	for(int i=0; i< list->Count; i++)
	{
		printf("Book ID: %d, Book name: %s \n", current->ID, current->Title);
		current = current->next;
	}
}
int main()
{
	struct Book firstBook = {
		.ID = 1,
		.Title = "Ogniem i mieczem",
		.AuthorFirstName = "Henryk",
		.AuthorLastName = "Sienkiewicz",
		.Category = "Fantastyka",
		.next = NULL,
		.previous = NULL
	};

	struct Book secondBook = {
		.ID = 2,
		.Title = "Dziady",
		.AuthorFirstName = "Adam ",
		.AuthorLastName = "Mickiewicz",
		.Category = "",
		.next = NULL,
		.previous = NULL
	};

	struct Book thirdBook = {
		.ID = 3,
		.Title = "Programowanie w MVC",
		.AuthorFirstName = "Jamie",
		.AuthorLastName = "Munro",
		.Category = "Programowanie",
		.next = NULL,
		.previous = NULL
	};
	
	Add(&list, &firstBook);
	Add(&list, &secondBook);
	Add(&list, &thirdBook);
	Add(&list, &thirdBook);
	Add(&list, &thirdBook);
	Add(&list, &thirdBook);
	Add(&list, &thirdBook);
	Add(&list, &thirdBook);
	Add(&list, &thirdBook);

	PrintList(&list);

	getchar();
	return 0;
}