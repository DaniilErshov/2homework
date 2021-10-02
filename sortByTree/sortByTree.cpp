// ConsoleApplication14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <ctime>

struct treeNode {
  int field;           
  struct treeNode *leftPtr;  
  struct treeNode *rightPtr; 
};

int checkNumber(std::string str)
{
	int n;
	int i = 0;

	while (i < str.length())
	{
		if (!isdigit(str[i]))
        {
			if (str[i] == '.')
			{
				std::cout << " ne celoe chislo\n";
				if (i > 0)
				{
					if (str[0] == '0')
					{
						std::cout << " < 1\n";
					}
				}
			}

			if (isalpha(str[i]))
			{
				std::cout << "bukva founded\n";
			}

			if ((!isalpha(str[i])) && (str[i] != '.'))
			{
				std::cout << "other problem\n";
			}
			str = "";
			std::cout << "vvedite chislo\n";
	        std::cin >> str;
			i = 0;
         } else {
			i++;
			if (i == str.length())
			{
				n = stoi(str);
				if (n > 100)	
	            {
                  std::cout << "mnogo\n";
	              std::cout << "vvedite chislo\n";
	              std::cin >> str;
                  n = 0;
	              i = 0;
	            }
			}
		}
	}
	return n;
}

void treePrint(treeNode *&tree) {
    if (tree != NULL)
	{
      treePrint(tree->leftPtr); 
      std::cout << tree->field << " "; 
      treePrint(tree->rightPtr); 
	}
}

void addNode(treeNode *&tree,int n){
  if (tree == NULL) { 
    tree = new treeNode;
	tree -> field = n;
	tree->leftPtr =  NULL;
    tree->rightPtr = NULL;
  } else {
	  if (n < tree-> field)
	  {
		 addNode(tree->leftPtr ,n);
	  } else {
	     addNode(tree->rightPtr ,n);
	  }
  }
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<int> array;
	int i = 0;
	int n = 0;
	struct treeNode *root = NULL;
	std::string str;
	srand(time(0));
	std::cout << "vvedite chislo\n";
	std::cin >> str;
	n = checkNumber(str);
	array.resize(n);
	for (i=0; i < n; i++)
	{
		array[i] = rand() % 100;
		std::cout << array[i] << " ";
		addNode(root,array[i]);
	}
	std::cout << "\n";
	treePrint(root);
	return 0;
}

