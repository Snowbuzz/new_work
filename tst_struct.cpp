
/**
 * @file test_struct.c
 * @brief Linux (3.18.x+) Тест списка.
 * @author Logachev Dmitriy
 */

#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;

struct Test
{
    int a;
    double b;
    string c;
};

struct Node {   char  word[40];  // область данных      
		int   count;       
		Node  *next;     // ссылка на следующий узел     
	    }; 

typedef Node *PNode;  // типданных: указатель на Node

int sum(int a, int b)

{
 return a + b;
}


int (*functionFactory(int n))(int, int) {
    printf("Got parameter %d ", n);
    int (*functionPtr)(int,int) = &sum;
    return functionPtr;
}

PNode Find (PNode Head, char NewWord[]) 
{
   PNode q = Head;
   while (q && strcmp(q->word, NewWord)) 
      q = q->next;
   return q; 
}

PNode CreateNode ( char NewWord[] ) 
{
   PNode NewNode = new Node; 		// указатель на новый список
   strcpy(NewNode->word, NewWord); 	// записать слово
   NewNode->count = 1;             	// счетчик слов = 1
   NewNode->next = NULL;           	// следующего узла нет
   return NewNode;  			// результат функции – адрес Node 
}



void AddFirst (PNode &Head, PNode NewNode) 
{
  NewNode->next = Head;
  Head = NewNode; 
}


void AddAfter (PNode p, PNode NewNode) 
{
   NewNode->next = p->next;
   p->next = NewNode; 
}


void AddLast(PNode &Head, PNode NewNode) 
{
PNode q = Head;
if (Head == NULL) {         // если список пуст,
 
	cout << "insert 1 node\n";
   AddFirst(Head, NewNode); // вставляем первый элемент
   return;
   } 
while (q->next) q = q->next; // ищем последний элемент 
AddAfter(q, NewNode);
}


int main(int argc, char **argv)
{

	int (*funcPtr)(int , int);

	funcPtr = &sum;

        PNode Head = NULL, p, where;

        char word[80]= {8,3,4,5,6};

        p = Find ( Head, word ); // ищем слово в списке

        if(p != NULL) p->count++;
        else
      	{
	
		p = CreateNode ( word );  // создаем новый узел

	}


        AddLast(Head, p); // вставка перед первым узлом

        //   word = 'p242gfewrg'; //{7,3,4,5,6,8,9};


        sprintf(word, "%s", "p242gfewrg");

        p = CreateNode ( word );

        AddLast(Head, p);
        

        p = Head;       
  while ( p ) {  // проход по списку и вывод на экран
     
	printf (  "CODE(0)-%02X %d\n", p->word[0], p->count );
	p = p->next;
     }
	p = Head;
	while (p->next) p = p->next;

       int length = strlen(p->word);

     printf (  "%-20s\t%d\n", p->word, length);

     // переворачиваем
    for(int i = 0,  j = length - 1; i < j; ++i, --j) {
 
        int t = word[i];
        word[i] = word[j];
        word[j] = t;
    }
 
    // выводим элементы массива на экран
    cout << "result:\n";
    
    for(int i = 0; i < length; ++i)
        cout << " " << word[i];
 
    cout << "\n"; 

    strcpy(p->word,word);

    printf (  "%-20s\t%d\n", p->word, length);        

    std::cout << "Hello, World!" << std::endl;
    std::cout << "x + y = " << (*funcPtr)(3 , 2) << std::endl;
    std::cout << "x + y = " << (*functionFactory)(10)( 7, 3) << std::endl;

    return 0;
}

