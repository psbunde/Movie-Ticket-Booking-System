#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
//Function declaration
int display_seats(int seats[]);
void book_seat(int seats[]);
void cancel_seat(int seats[]);
char moviechoice(char movie1[], char movie2[]);

void main()
{
	char ch,choice;
	int i,seatno,price1=100,price2=200;
	int seats1[10]={0};
	int seats2[10]={0};
	char movie1[25]="AVENGERS";
	char movie2[25]="ENDGAME";
	clrscr();
	while(1)
	{
		clrscr();
		printf("\n\t\tMOVIES AVAILABLE:\n"
			   "\t\t\t%s\tRs.%d\n\t\t\t%s\t\tRs.%d\n",movie1,price1,movie2,price2);
		printf("\n\t\t\t-----------------------\n"
			   "\t\t\t  TICKET BOOKING MENU"
			   "\n\t\t\t-----------------------\n"
			   "\t\t1. EDIT PRICE AND MOVIE\n\n"
			   "\t\t2. AVAILABLE SEATS\n\n"
			   "\t\t3. PURCHASE TICKETS\n\n"
			   "\t\t4. CANCEL SEATS\n\n"
			   "\t\t0. EXIT\n\n"
			   "\t\tEnter Your Choice : ");
		fflush(stdin);
		ch=getche();

		switch(ch)
		{
			case '1': clrscr();
					  printf("\nScreen 1 Movie: %s",movie1);
					  printf("\nScreen 1 Price: %d\n",price1);
					  printf("\nScreen 2 Movie: %s",movie2);
					  printf("\nScreen 2 Price: %d",price2);
					  printf("\nEnter Your Choice : ");
					  choice=getche();

					  if(choice=='1')
					  {
						printf("\nMovie : %s\n",&movie1);
						printf("\n\nEnter Screen 1 Movie Name: ");
						fflush(stdin);
						gets(movie1);

						printf("\nEnter Screen 1 Movie Price: ");
						fflush(stdin);
						scanf("%d",&price1);

						printf("\nNew Movie Name: %s",movie1);
						printf("\nNew Price: %d",price1);
						getch();
					  }
					  else if(choice=='2')
					  {
						printf("Movie : %s",&movie2);

						printf("\n\nEnter Screen 2 Movie Name: ");
						fflush(stdin);
						gets(movie2);

						printf("\nEnter Screen 2 Movie Price: ");
						fflush(stdin);
						scanf("%d",&price2);

						printf("\nNew Movie Name: %s",movie2);
						printf("\nNew Price: %d",price2);
						getch();
					  }
						break;

			case '2': choice=moviechoice(movie1,movie2);
					  if(choice=='1')
					  {
						  display_seats(seats1);
					  }
					  else if(choice=='2')
					  {
						  display_seats(seats2);
					  }
					  getch();
					  break;

			case '3':  choice=moviechoice(movie1,movie2);
					   if(choice=='1')
					   {
						   book_seat(seats1);
					   }
					   else if(choice=='2')
					   {
						   book_seat(seats2);
					   }
					   getch();
					   break;

			case '4':  choice=moviechoice(movie1,movie2);
					   if(choice=='1')
					   {
						   cancel_seat(seats1);
					   }
					   else if(choice=='2')
					   {
						   cancel_seat(seats2);
					   }
					   getch();
					   break;

			case '0':
					   break;


			default:
					   break;

		}

			if(ch=='0')
		{
			break;
		}



	}


}

int display_seats(int seats[])
{
	int i,sum=10;
	printf("\n\n Empty seats are : ");
	for(i=0;i<10;i++)
	{
		if(seats[i]==0)
		{
			printf("%d  ",i+1);
			sum=sum-1;
		}
	}
	return sum;
}

void book_seat(int seats[])
{
	 int seatno,avail;
	 clrscr();
	 avail=display_seats(seats);
	 if(avail==10)
	 {
		printf("All Seats are Booked!");
		return;
	 }
	 printf("\n\n Enter the Seat No. To Book: ");
	 scanf("%d",&seatno);
	 if(seats[seatno-1]==1)
	 {
		printf("\nSeat is Already Booked!");
		return;
	 }
	 else if(seatno>10 || seatno<1)
	 {
		printf("\nInvalid Seat No.");
		return;
	 }
	 seats[seatno-1]=1;
	 printf("\n Seat no. %d is booked Successfully!",seatno);
	 display_seats(seats);
}

void cancel_seat(int seats[])
{
	 int seatno;
	 clrscr();
	 display_seats(seats);
	 printf("\n\n Enter the Seat No. To Cancel: ");
	 scanf("%d",&seatno);
	 if(seatno>10 || seatno<1)
	 {
		printf("\nInvalid Seat No.");
		return;
	 }
	 else if(seats[seatno-1]==0)
	 {
		printf("\nSeat is Already Empty!");
		return;
	 }

	 seats[seatno-1]=0;
	 printf("\n Seat no. %d is Cancelled Successfully!",seatno);
	 display_seats(seats);
}

char moviechoice(char movie1[], char movie2[])
{
	clrscr();
	printf("\n1. %s\n"
		   "\n2. %s\n"
		   "\nEnter Movie Choice: ",movie1,movie2);
	return getche();
}
