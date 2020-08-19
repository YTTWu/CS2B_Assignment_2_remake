//
//  main.cpp
//  CS2B-Assignment 2_Remake
//
//  Created by yuteng Wu on 8/18/20.
//  Copyright © 2020 Yuteng Wu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


typedef enum {pcNew, pcUsed, pcRefurbished, pcDefective} T_ProductCondition;


class InventoryItem
{

protected:
   string name;
   int quantity;

public:
   InventoryItem();
   InventoryItem(string name, int quantity);
   ~InventoryItem();

   void setName(string name);
   void setQuantity(int quantity);
   string getName()const;
   int getQuantity()const;

   void display()const;
};


const int k_maxNum = 512;

class InventorySystem
{
private:
   string storeName;
   int storeID;
   InventoryItem *itemList[k_maxNum];
   int itemCount;

public:
   InventorySystem();
   InventorySystem(string storeName, int storeID);
   ~InventorySystem();

   void setStoreName();
   void setStoreID();
   void setItemCount();
   string getStoreName();
   int getStoreID();
   int getItemCount();

   void buildInventory();
   void showInventory();
   void showDefectInventory();
   void terminate();



};



class Product : public InventoryItem
{
private:
   int productID;
   double price;
   T_ProductCondition condition;

public:
   Product();
   Product(int randomProducID, double price, T_ProductCondition condition);
   ~Product();

   void setProductID();
   void setPrice();
   void setCondition();

   int getProductID();
   double getPrice();
   T_ProductCondition getCondition();

   void Display();






};








int main()
{
   cout << "Hello World" << endl;

   

}



//-----------------class InventorySystem--------------------------

InventorySystem::InventorySystem():storeName(0), storeID(0), itemList{NULL}, itemCount(0)
{
   srand(time(NULL));
}

InventorySystem::InventorySystem(string storeName, int storeID )
{
   srand(time(NULL));
}

InventorySystem::~InventorySystem()
{
   for(int i = 0; i < itemCount; i++)
   {
      delete itemList[i];
   }
}

void InventorySystem::buildInventory()
{
   ifstream fin("input.txt");

   if (!fin) {

        cout << "ERROR: Failed to open input file\n";

        exit(-1);

   }

}


void InventorySystem::showInventory()
{

}


void InventorySystem::showDefectInventory()
{

}


void InventorySystem::terminate()
{

}


void InventorySystem::setStoreName()
{

}


void InventorySystem::setStoreID()
{

}


void InventorySystem::setItemCount()
{

}


string InventorySystem::getStoreName()
{
   return storeName;
}


int InventorySystem::getStoreID()
{
   return storeID;
}


int InventorySystem::getItemCount()
{
   return itemCount;
}



//------------------class InventoryItem definition-------------

InventoryItem::InventoryItem():name(NULL),quantity(0){}
InventoryItem::InventoryItem(string name, int quantity):name(name), quantity(quantity){}
InventoryItem::~InventoryItem()
{
   cout << "IventoryItem " << name << " with " << quantity << " items destroyed" << endl;
}


void InventoryItem::setName(string name)
{
   this->name = name;
}

void InventoryItem::setQuantity(int quantity)
{
   this->quantity = quantity;
}

string InventoryItem::getName()const
{
   return name;
}

int InventoryItem::getQuantity()const
{
   return quantity;
}

void InventoryItem::display()const
{
   cout << "Item Name: " << name << endl;
   cout << "Item Quantity: " << quantity << endl;
}



