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

   void setStoreName(string name);
   void setStoreID(int ID);
   void setItemCount(int count);
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
   Product(string name, int quantity, double price, char condition);
   ~Product();

   int generateProductID();
   T_ProductCondition conditionChecker(char condition);

   void setProductID(int ID);
   void setPrice(double price);
   void setCondition(T_ProductCondition condition);

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
   string buffer;
   ifstream fin("input.txt");
   Product x = Product();

   string productName;
   int productQuantity;
   double productPrice;
   char productQuanlity;

   if (!fin)
   {
        cout << "ERROR: Failed to open input file\n";

        exit(-1);
   }


   while(getline(fin, buffer, ';'))
   {
      productName = buffer;
      int i = 0;

      getline(fin, buffer, ';');
      productQuantity = stoi(buffer);

      getline(fin, buffer, ';');
      productPrice = stof(buffer);

      getline(fin, buffer, ';');
      productQuanlity = buffer.at(0);

      itemList[i] = new Product(productName, productQuanlity, productPrice, productQuantity);
      i++;
      itemCount++;
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


void InventorySystem::setStoreName(string name)
{
   this->storeName = name;
}


void InventorySystem::setStoreID(int ID)
{
   this->storeID = ID;
}


void InventorySystem::setItemCount(int count)
{
   this->itemCount = count;
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
   cout << "Product Name: " << name << endl;
   cout << "Product Quantity: " << quantity << endl;
}



//----------------Product Definition------------------

Product::Product():InventoryItem(), productID(0), price(0.0), condition(pcNew){}

Product::Product(string name, int quantity, double price, char condition)
:InventoryItem(name, quantity), price(price)
{
   productID = generateProductID();
   condition = conditionChecker(condition);

}


Product::~Product()
{
   cout << "Product: " << productID << " Price: " << price << " Condition: "
   << condition << " destroyed" << endl;
}

int Product::generateProductID()
{
   int id = 0;
   id = rand() % 10000;

   productID = id;

   return id;
}


T_ProductCondition Product::conditionChecker(char condition)
{
   T_ProductCondition productCondition;
   switch (condition) {
      case 'N':
         productCondition = pcNew;
         break;
      case 'R':
         productCondition = pcRefurbished;
         break;
      case 'U':
         productCondition = pcUsed;
         break;
      case 'D':
         productCondition = pcDefective;
         break;
      default:
         break;
   }
}

void Product::setProductID(int ID)
{
   this->productID = ID;
}

void Product::setPrice(double price)
{
   this->price = price;
}

void Product::setCondition(T_ProductCondition condition)
{
   this->condition = condition;
}

int Product::getProductID()
{
   return productID;
}

double Product::getPrice()
{
   return price;
}

T_ProductCondition Product::getCondition()
{
   return condition;
}

void Product::Display()
{
   InventoryItem::display();

   cout << "Product ID: " << productID << endl;
   cout << "Product Price: " << price << endl;
   cout << "Product Condition " << condition << endl;

}
