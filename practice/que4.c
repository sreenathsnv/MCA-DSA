//Create a menu driven program using functions for a book management store having
//book id, book name ,author, price of the book to perform the following operations.
//Read and display the details for 5 books using functions read() and display(). Using
//maximum() function ,display the details of the book having maximum price. Using
//count() function , count the books having the same author name and display.



#include<stdio.h>
#include<conio.h>
#include<string.h>


struct book{
	
	unsigned int id;
	char name[20];
	char author[20];
	float price;
};

void read(struct book books[])
{
	short i;
	printf("Enter the Book Details\n");
	for(i=0;i<5;i++)
	{
		printf("\tBook - %d\n",i+1);
		printf("Book id : ");
		scanf("%u",&books[i].id);
		fflush(stdin);
		printf("Book Name : ");
		gets(books[i].name);
		fflush(stdin);
		printf("Author : ");
		gets(books[i].author);
		printf("Price : ");
		scanf("%f",&books[i].price);
	}
}
void display(struct book books[])
{
	short i;
		for(i=0;i<5;i++)
	{
		printf("\n\t\tBook - %d\n",i+1);
		printf("Book id : %u\n",books[i].id);
		printf("Book Name : %s\n",books[i].name);
		printf("Author : %s\n",books[i].author);
		printf("Price : %.2f\n"),books[i].price;
	}
}



struct book maximum(struct book books[]){
	
	short i,index;
	float maximum = 0;
		for(i=0;i<5;i++)
	{
		if(books[i].price>maximum)
		{
			index = i;
			maximum = books[i].price;
		}
	}
	return books[index];
	
}

void countBook(struct book books[])
{
	short i,j,count=0;
	char author[20];
	printf("Enter author name");
	gets(author);
	
	for(i=0;i<5;i++)
	{
		
		if(strcmp(books[i].author,author)==0)
		{
			count++;
		}
		
		printf("%s by %s : %u\n",books[i].name,books[i].author,count);
	}

}

void main()
{
	struct book books[5],max_book;
	int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Read book details\n");
        printf("2. Display book details\n");
        printf("3. Find book with maximum price\n");
        printf("4. Count books by author\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                read(books);
                break;
            case 2:
                display(books);
                break;
            case 3:
                maximum(books);
                break;
            case 4:
                count(books);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}
