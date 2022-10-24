using namespace std;



#include <iostream>

#include <iomanip>



#include <ctype.h>

#include <stdlib.h>

#include <string.h>



//**** PRICES ARE SUBJECT TO CHANGE AS ARE MENU ITEMS !!!! *****//



#define BEVERAGE_NAME_LENGTH

typedef struct _TBeverage

{

char beverageName[55];

float priceSmall;

float priceMedium;

float priceLarge;

} * TBeverage;

#define BEVERAGE_SIZE (sizeof(struct _TBeverage))



typedef struct _TOrderItem

{

struct _TBeverage bevItem;

char size;

int qty;

} *TOrderItem;



#define ORDER_ITEM_SIZE (sizeof(struct _TOrderItem))





#define MAX_NUM_ITEMS_PER_ORDER (12)

#define TAX_PERCENT (0.0000) //ex. 6.5



void DisplayMenu(TBeverage menuArray, int N)

{



cout << "********************************************************************" << endl;

cout << " Item # Beverage Small Medium Large " << endl;

cout << "*******************************************************************" << endl;



struct _TBeverage curBev;





for (int iLoop=0; iLoop<N; iLoop++)

{

curBev = menuArray[iLoop];



cout << " " << (iLoop+1) << " "

<< curBev.beverageName

<< " " << " $" <<fixed << setprecision(2)

<< curBev.priceSmall << " $" <<fixed << setprecision(2)

<< curBev.priceMedium << " $" <<fixed << setprecision(2)

<< curBev.priceLarge << endl;



}

cout << "**********************************************************************" << endl;



}





void InputOrder(TBeverage beverages,int N, TOrderItem order, int * numItems)

{



bool done_flag = false;

(*numItems)=0;



while (!done_flag)

{

int itemNum = 0;



while ((itemNum<1) || (itemNum>N))

{



DisplayMenu(beverages,N);



cout << "\n Please Enter Item # :>";

cin >> itemNum;

}



char itemSize='?';

while ((itemSize !='S') && (itemSize!='M') && (itemSize!='L'))

{

cout << "Please Enter size :>";

cin >> itemSize;

itemSize = toupper(itemSize);

}



int qty=0;

while (qty<=0)

{

cout << "Please Enter the quantity :>";

cin >> qty;

}



struct _TOrderItem curOrderItem;

curOrderItem.bevItem = beverages[itemNum-1];

curOrderItem.size = itemSize;

curOrderItem.qty = qty;



order[(*numItems)]=curOrderItem;

(*numItems)++;



char chResponse='?';

while ((chResponse !='Y') && (chResponse !='N'))

{

cout << "Another Item ??? Y = YES N=No :>";

cin >>chResponse;

chResponse = toupper(chResponse);

}



done_flag = ((*numItems>=MAX_NUM_ITEMS_PER_ORDER) || (chResponse=='N'));

// cout << " # of items ordered =" << *numItems << endl;



}



}



float CalculateOrder(TOrderItem order,int numItems)

{



float subtotal=0;

float finalAmt=0;

//cout << " # of items ordered =" << numItems << endl;



cout << " ITEM SIZE QTY PRICE SUBTOTAL "<< endl;





for (int iLoop=0; iLoop<numItems; iLoop++)

{

float price = 0;

struct _TOrderItem curOrderItem = order[iLoop];



cout << curOrderItem.bevItem.beverageName << " " << curOrderItem.size << " " << curOrderItem.qty;



switch (curOrderItem.size)

{

case 'S':

{

price = curOrderItem.bevItem.priceSmall;

break;

}

case 'M':

{

price = curOrderItem.bevItem.priceMedium;

break;

}

case 'L':

{

price = curOrderItem.bevItem.priceLarge;

break;

}





}

subtotal = price * curOrderItem.qty;

cout << " " << fixed << setprecision(2) << price

<< " " << fixed << setprecision(2) << subtotal << endl;



finalAmt += subtotal;





}



return(finalAmt);

}



void PaymentOrder(TOrderItem order, int numItems, float amt)

{

cout << endl;



cout << " Grand Sub-Total is $" << fixed << setprecision(2) << amt << endl;



float taxAmt = amt*(TAX_PERCENT/100.00f);

cout << " Tax at " << TAX_PERCENT << " = " << fixed << setprecision(2) << taxAmt << endl;



float finalAmount = amt + taxAmt;



cout << " THE FINAL AMOUNT IS " << fixed << setprecision(2) << finalAmount << endl;



float amtTendered=0;



while (amtTendered<finalAmount)

{

cout << " Please Enter amount Tendered :> ";

cin >> amtTendered;

}



float changeAmt = amtTendered - finalAmount + 0.005;





cout << "Change due to customer = " << fixed << setprecision(2) <<changeAmt << endl;



long longIntNumAmt = (long) (changeAmt*100.00);

cout << "amount in pennies = " << longIntNumAmt << endl;





cout << longIntNumAmt/10000 << " x $100 bills " << endl; longIntNumAmt %= 10000;

cout << longIntNumAmt/5000 << " x $50 bills " << endl; longIntNumAmt %=5000;

cout << longIntNumAmt/2000 << " x $20 bills " << endl; longIntNumAmt %=2000;

cout << longIntNumAmt/1000 << " x $10 bills " << endl; longIntNumAmt %=1000;

cout << longIntNumAmt/500 << " x $5 bills " << endl; longIntNumAmt %=500;

cout << longIntNumAmt/100 << " x $1 bills " << endl; longIntNumAmt %=100;

cout << longIntNumAmt/25 << " x quarters " << endl; longIntNumAmt %=25;

cout << longIntNumAmt/10 << " x dimes " << endl; longIntNumAmt %=10;

cout << longIntNumAmt/5 << " x nickels " << endl; longIntNumAmt %=5;

cout << longIntNumAmt << " x pennies " << endl;







}





int main( int argc, char * argv[])

{



struct _TBeverage beverages[] = { {"Long Black",3.50,3.70,4.00} ,

{"Flat White",3.80,4.20,4.50},

{" Cappucino",4.00,4.30,5.00},

{" Tea",3.00,3.20,3.50}

};



struct _TOrderItem order[MAX_NUM_ITEMS_PER_ORDER ]; //there are currently 12 items on the menu





int numItems=0;

memset(order,0,MAX_NUM_ITEMS_PER_ORDER*ORDER_ITEM_SIZE );



InputOrder(beverages,4,order,&numItems);



float amount = CalculateOrder(order,numItems);



PaymentOrder(order,numItems,amount);







}

