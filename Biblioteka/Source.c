#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	struct Date* DateOfHire;
	struct Book* next;
	struct Book* previous;

};

struct List
{
	int Count;
	struct Book* FirstElement;
	struct Book* LastElement;
} list;

struct Book* InitBook()
{
	struct Book* book = malloc(sizeof(struct Book));
	book->ID = 0;
	book->Title = NULL;
	book->AuthorFirstName = NULL;
	book->AuthorLastName = NULL;
	book->Category = NULL;
	book->FirstName = NULL;
	book->LastName = NULL;
	book->DateOfHire = NULL;
	book->next = NULL;
	book->previous = NULL;
	
	return book;
}

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
	printf("\n Liczba wszystkich ksiazek %d", list->Count);

	struct Book* current = list->FirstElement;
	for(int i=0; i< list->Count; i++)
	{
		printf("\n\tKsiazka nr %d", i+1);
		printf("\n{\n");
		printf(" Id Ksiazki: %d \n", current->ID);
		printf(" Nazwa ksiazki: %s", current->Title);
		printf(" Kategoria: %s", current->Category);
		printf(" Imie autora: %s", current->AuthorFirstName);
		printf(" Nazwisko autora: %s", current->AuthorLastName);
		printf("}\n");
		current = current->next;
	}
	printf("\n");
}

void test()
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

	PrintList(&list);

	getchar();
}

void AddStringToStructure(char*field, char buffer[])
{
	fgets(buffer, 100, stdin);
	field = (char*)malloc(strlen(buffer) + 1);

	strcpy(field, buffer);

	for(int i = 0; i< strlen(buffer)+1; i++)
	{
		buffer[i] = 0;
	}

}

void AddNewBook()
{
	struct Book* book = InitBook();

	printf("Podaj tytul ksiazki\n");
	char temp[20] = { 0 };
	fgets(temp, 100, stdin);
	book->Title = (char*)malloc(strlen(temp) + 1);
	strcpy(book->Title, temp);
	memset(temp, 0, strlen(temp));


	printf("Podaj kategoriê\n");
	fgets(temp, 100, stdin);
	book->Category = (char*)malloc(strlen(temp) + 1);
	strcpy(book->Category, temp);
	memset(temp, 0, strlen(temp));

	printf("Podaj imiê autora\n");
	fgets(temp, 100, stdin);
	book->AuthorFirstName = (char*)malloc(strlen(temp) + 1);
	strcpy(book->AuthorFirstName, temp);
	memset(temp, 0, strlen(temp));

	printf("Podaj nazwisko autora\n");
	fgets(temp, 100, stdin);
	book->AuthorLastName = (char*)malloc(strlen(temp) + 1);
	strcpy(book->AuthorLastName, temp);
	memset(temp, 0, strlen(temp));


	Add(&list, book);
	PrintList(&list);

}

int main()
{
	printf("BIBLIOTEKA \n");
	
	AddNewBook();
	AddNewBook();
	AddNewBook();

	getchar();
	return 0;
}