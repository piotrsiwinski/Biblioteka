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

	list->LastElement->next = book; 
	book->previous = list->LastElement;
	list->LastElement = book;
	list->Count++;
}

void PrintList(struct List* list)
{
	printf("\n Liczba wszystkich ksiazek %d", list->Count);

	struct Book* current = list->FirstElement;
	while (current)
	{
		printf("\n\tKsiazka ");
		printf("\n{\n");
		printf(" Id_Ksiazki: %d \n", current->ID);
		printf(" Nazwa_ksiazki: %s \n", current->Title);
		printf(" Kategoria: %s \n", current->Category);
		printf(" Imie_autora: %s \n", current->AuthorFirstName);
		printf(" Nazwisko_autora: %s \n", current->AuthorLastName);
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
	char temp[100] = { 0 };
	scanf("%s", temp);
	book->Title = (char*) malloc(strlen(temp) + 1);
	strcpy(book->Title, temp);
	memset(temp, 0, strlen(temp));


	printf("Podaj kategoriê\n");
	scanf("%s", temp);
	book->Category = (char*)malloc(strlen(temp) + 1);
	strcpy(book->Category, temp);
	memset(temp, 0, strlen(temp));

	printf("Podaj imiê autora\n");
	scanf("%s", temp);
	book->AuthorFirstName = (char*)malloc(strlen(temp) + 1);
	strcpy(book->AuthorFirstName, temp);
	memset(temp, 0, strlen(temp));

	printf("Podaj nazwisko autora\n");
	scanf("%s", temp);
	book->AuthorLastName = (char*)malloc(strlen(temp) + 1);
	strcpy(book->AuthorLastName, temp);
	memset(temp, 0, strlen(temp));


	Add(&list, book);
	PrintList(&list);

}

void DeleteBook()
{
	//TODO Dodaj usuwanie ksiazki
	printf("TODO");
}

void EditBook()
{
	//TODO Dodaj edycje ksiazki
	printf("TODO");
}

int main()
{
	printf("BIBLIOTEKA \n");

	printf("1) Dodaj now¹ ksi¹¿kê \n2) Usuñ ksi¹¿kê \n3) Edytuj dane ksi¹¿ki\n4) Zmieñ status ksi¹¿ki\n5) Wyszukaj ksi¹¿kê\n6) Wyœwietl bazê po tytu³ach\n7) Wyœwietl ksi¹¿ki wypo¿yczone\n8) Zapisz do pliku\n9) Odczytaj z pliku\nX) Koniec pracy\n");
	printf("Wybierz: ");
	int optionNumber = 0;
	scanf("%d", &optionNumber);


	switch (optionNumber)
	{
		case 1:
		{
			AddNewBook();
			AddNewBook();
			AddNewBook();
			break;
		}
		case 2:
		{
			DeleteBook();
			break;
		}
		case 3:
		{
			EditBook();
			break;
		}



		default: break;
	}

	getchar();
	getchar();
	return 0;
}
