
#include<iostream>
using namespace std;

class Tree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :
			Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class Tree;
	}*Root;
public:
	Element* getRoot()
	{
		return Root;
	}
	Tree()
	{
		Root = nullptr;
		cout << "TConstructor:\t" << this << endl;
	}
	Tree(const initializer_list<int>& il) :Tree()
	{
		for (const int* it = il.begin(); it != il.end(); it++)
		{
			insert(*it);
		}
	}
	~Tree()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void insert(int Data)
	{
		insert(Data, this->Root);
	}
	void erase(int Data)
	{
		erase(Data, this->Root);
		erase(Data, this->Root);
	}
	int minValue()
	{
		if (!this->Root)throw std::exception("Tree is empty");
		return minValue(this->Root);
	}
	int maxValue()
	{
		return maxValue(Root);
	}
	int count()
	{
		return count(Root);
	}
	int sum()
	{
		return sum(Root);
	}
	void print()
	{
		print(this->Root);
		cout << endl;
	}
private:
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)
		{
			this->Root = new Element(Data);
			return;
		}
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			/*if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);*/

			if (Root->pLeft)insert(Data, Root->pLeft);
			else Root->pLeft = new Element(Data);
		}
		else
		{
			/*if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);*/

			if (Root->pRight)insert(Data, Root->pRight);
			else Root->pRight = new Element(Data);
		}
	}

	int minValue(Element* Root)
	{
		if (Root == nullptr) return int();
		if (Root->pLeft == nullptr) return Root->Data;
		return minValue(Root->pLeft);
	}

	int maxValue(Element* Root)
	{
		return Root == nullptr ? int() : Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}

	int count(Element* Root)
	{
		if (Root == nullptr) return 0;
		if (Root->pLeft == Root->pRight) return 1;
		return 1 + count(Root->pLeft) + count(Root->pRight);
	}

	int sum(Element* Root)
	{
		if (Root == nullptr) return 0;
		if (Root->pLeft == Root->pRight) return Root->Data;
		return Root->Data + sum(Root->pLeft) + sum(Root->pRight);
	}

	void erase(int Data, Element* &Root)
	{
		if (Root == nullptr) return;
		if (Data == Root->Data) 
		{
			if (Root->pLeft == Root->pRight)
			{
				delete Root;
				Root = nullptr;
				return;
			}
			else
			{
				if (Root->pLeft)
				{
					Root->Data = maxValue(Root->pLeft);
					erase(maxValue(Root->pLeft), Root->pLeft);
				}
				else if (Root->pRight)
				{
					Root->Data = minValue(Root->pRight);
					erase(minValue(Root->pRight), Root->pRight);
				}
				//if (Root->Data == Data) erase(Data, Root);
			}
		}
		erase(Data, Root->pLeft);
		erase(Data, Root->pRight);
	}
	
	void print(Element* Root)
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
};

#define BaseCheck
//#define ideal

int main() 
{
	setlocale(LC_ALL, "");
#ifdef BaseCheck
	int n;
	cout << "Type tree size: "; cin >> n;
	Tree T800;
	for (int i = 0; i < n; i++)
	{
		T800.insert(rand() % 100);
	}
	T800.print();
	cout << "MIN: " << T800.minValue() << endl;
	cout << "MAX: " << T800.maxValue() << endl;
	cout << "How much: " << T800.count() << endl;
	cout << "SUM of all elements: " << T800.sum() << endl;
	int value;
	cout << "Type value you wanna delete: "; cin >> value;
	T800.erase(value);
	T800.print();
#endif // BaseCheck

#ifdef ideal
	Tree tree = { 50,25,20,35,75,45,80 };
	tree.print();
	tree.erase(75);
	tree.print();
#endif // ideal

	return 0;
}