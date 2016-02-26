#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum CARDS {ace,ten,king,queen,jack,nine};
enum SUIT  {spade,diamond,club,heart};    

struct CARD {
  enum CARDS card;
  enum SUIT suit;
};

struct CARD Deck[48];
struct CARD Hand[4][12];
void Init(struct CARD*);
void Print(struct CARD*);
char *GetSuit(enum SUIT);
char *GetCard(enum CARDS);
void Shuffle(struct CARD*);
void Deal(struct CARD*,struct CARD Hand[4][12]);
void PrintHand(struct CARD Hand[4][12], int);

int  main(void)
{
	Init(Deck);
Print(Deck);
printf("==========================================\n");
	Shuffle(Deck);
Print(Deck);
	Deal(Deck,Hand);
	PrintHand(Hand,0);
	PrintHand(Hand,1);
	PrintHand(Hand,2);
	PrintHand(Hand,3);
	
}               

void Deal(struct CARD* Deck,struct CARD Hand[4][12])
{                 
  int i,h1,h2,h3,h4;
  
  h1=h2=h3=h4=0;
  
  for (i=0;i<48;i++)
  {
    switch (i)
    {
    // First Hand
      case 0: ;
      case 1: ;
      case 2: ;
      case 3: ;
      case 16:;
      case 17: ;
      case 18:  ;
      case 19: ;
      case 32: ;
      case 33: ;
      case 34: ;
      case 35:{
        Hand[0][h1].suit=Deck[i].suit;
        Hand[0][h1++].card=Deck[i].card;        
        break;
      }
    // Second Hand
      case 4:  ;
      case 5:  ;
      case 6:  ;
      case 7:  ;
      case 20:  ;
      case 21:  ;
      case 22:  ;
      case 23:  ;
      case 36:  ;
      case 37:  ;
      case 38:  ;
      case 39:{
        Hand[1][h2].suit=Deck[i].suit;
        Hand[1][h2++].card=Deck[i].card;        
        break;
      }
    // Third Hand
      case 8:   ;
      case 9:   ;
      case 10:  ;
      case 11:  ;
      case 24:  ;
      case 25:  ;
      case 26:  ;
      case 27:  ;
      case 40:  ;
      case 41:  ;
      case 42:  ;
      case 43:{
        Hand[2][h3].suit=Deck[i].suit;
        Hand[2][h3++].card=Deck[i].card;        
        break;
      }
    // Fourth Hand
      case 12:  ;
      case 13:  ;
      case 14:  ;
      case 15:  ;
      case 28:  ;
      case 29:  ;
      case 30:  ;
      case 31:  ;
      case 44:  ;
      case 45:  ;
      case 46:  ;
      case 47:{ 
        Hand[3][h4].suit=Deck[i].suit;
        Hand[3][h4++].card=Deck[i].card;        
        break;
      }           
    }
  } 
}
/*
int CompareCards (const void *a, const void *b)
{
    const double *da = (const double *) a;
    const double *db = (const double *) b;
    
    return (*da > *db) - (*da < *db);
}
*/

void SortHand(struct CARD hand[4][12], int h)
{
    int i;
    for(i=0;i<12;i++)
    {
               printf("Hand[%d][%d] is %s of %s.\n",h,i,
               GetCard(hand[h][i].card),
               GetSuit(hand[h][i].suit));
    }
}
void PrintHand(struct CARD hand[4][12],int h)
{
  int i;                  
printf("++ Contents of Hand %d\n",h+1);

  for(i=0;i<12;i++)
  {
           printf("Hand[%d][%d] is %s of %s.\n",h,i,
           GetCard(hand[h][i].card),
           GetSuit(hand[h][i].suit));
  }
}

void Shuffle(struct CARD* deck)
{
 struct CARD temp;
 short i,j;
 
 srand( (unsigned)time( NULL ) );

    
    
 for (i=47;i>=0;i--)
 {                       
   j=rand() % 10;       
   temp.card=deck[j].card;
   temp.suit=deck[j].suit;
   deck[j].card=deck[i].card;
   deck[j].suit=deck[i].suit;
   deck[i].card=temp.card;
   deck[i].suit=temp.suit;
  }
}

void Init(struct CARD* deck)
{
 char i;
 enum CARDS c;
 enum SUIT s;
  

for (i=0;i<48;i++) 
{
  for (s=spade;s<=heart;s++)
  {
    for (c=ace;c<=nine;c++)
    {
      deck[i].suit=s;
      deck[i].card=c;
      i++;
    }
  }
 }
}

void Print(struct CARD *deck)
{
  short i;
  
  for (i=0;i<48;i++)
  {
    //printf("Deck[%d] is the %s of %s\n",i,
    printf("Deck[%d],%s,%s\n",i,
            GetCard(deck[i].card),GetSuit(deck[i].suit));
  }
}
  
char *GetSuit(enum SUIT s)
{
    switch (s)
    {
      case spade:{ return ("Spades"); break;}
      case diamond:{ return ("Diamonds"); break;}
      case club:{ return ("Clubs"); break;}
      case heart:{ return ("Hearts"); break;}
    }
}

char *GetCard(enum CARDS c)
{
    switch (c)
    {
      case ace:{ return ("Ace"); break;}
      case ten:{ return ("Ten"); break;}
      case king:{ return ("King"); break;}
      case queen:{ return ("Queen"); break;}
      case jack:{ return ("Jack"); break;}
      case nine:{ return ("Nine"); break;}
    }
}


