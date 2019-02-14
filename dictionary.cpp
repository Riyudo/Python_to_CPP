#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

//Header
class Dictionary
{
	public:
		class Pair
		{
			public:
				string key[50];
				int value;
				Pair assign(string s, int n);
		};

		friend Dictionary operator+(Dictionary first, Dictionary second);

		Dictionary();
		~Dictionary();
		bool add(string s, int n);
		bool del(string s);
		bool in (string s);
		int get(string s);
		void keys();
		void values();
		void items();
		
		
	private:
		int size;
		vector<int> test;
		vector<Pair> dictionary;
		queue <Pair> queueData;
		
		vector<string> pairKey;
		vector<int> pairInt;
};



Dictionary::Dictionary()
{
	int size = 0;
	
	
}

Dictionary::~Dictionary()
{


}

Dictionary::Pair Dictionary::Pair::assign(string s, int n)
{
	key->assign(s);
	value = n;
	return *this;
}

bool Dictionary::add(string s, int n)
{
	//Initializes pair set between two vectors
	if (pairKey.empty())
	{ 
		pairKey.insert(pairKey.begin(), s);
		pairInt.insert(pairInt.begin(), n);
		++size;
	}

	else if (find(pairKey.begin(), pairKey.end(), s) != pairKey.end() )
	{
		cout << "DUPLICATE KEY!";
		return false;
		
	}

	else
	{
		pairKey.insert(pairKey.begin(), s);
		pairInt.insert(pairInt.begin(), n);
		++size;
	}


	
	return true;
}

bool Dictionary::del(string s)
{
	
	if (find(pairKey.begin(), pairKey.end(), s) != pairKey.end())
	{
		//Checks if the element exists + gets index of element from iterator
		vector<string>::iterator it = std::find(pairKey.begin(), pairKey.end(), s);
		int index = distance(pairKey.begin(), it);

		//Removes the pair from memory
		pairKey.erase(pairKey.begin() + index);
		pairInt.erase(pairInt.begin() + index);
		--size;
		cout << "DELETED KEY" << endl;
		return true;
	}
	cout << "DELETING KEY UNSUCCESSFUL" << endl;
	return false;
}

bool Dictionary::in(string s)
{
	if (find(pairKey.begin(), pairKey.end(), s) != pairKey.end())
	{
		//Checks if the element exists
		vector<string>::iterator it = std::find(pairKey.begin(), pairKey.end(), s);
		return true;
	}
	return false;

}

int Dictionary::get(string s)
{

	if (find(pairKey.begin(), pairKey.end(), s) != pairKey.end())
	{
		//Checks if the element exists + gets index of element from iterator
		vector<string>::iterator it = std::find(pairKey.begin(), pairKey.end(), s);
		int index = distance(pairKey.begin(), it);

		
		return pairInt.at(index);
	}
	return 0;
}

void Dictionary::keys()
{
	cout << "[";
	for (int i = 0; i < pairKey.size();i++)
	{
		if (i == 0)
		{
			cout << "(" << pairKey.at(i) << ")";
			continue;
		}
		cout << ", (" << pairKey.at(i) << ")";
	}
	cout << "]" << endl;

}

void Dictionary::values()
{
	cout << "[";
	for (int i = 0; i < pairKey.size(); i++)
	{
		if (i == 0)
		{
			cout << pairInt.at(i);
			continue;
		}
		cout << ", "<< pairInt.at(i);
	}
	cout << "]" << endl;
}

void Dictionary::items()
{
	cout << "[";
	for (int i = 0; i < pairKey.size(); i++)
	{
		if (i == 0)
		{
			cout << "(" << pairKey.at(i) << ", " << pairInt.at(i) << ")";
			continue;
		}
		cout << ", (" << pairKey.at(i) << ", " << pairInt.at(i) << ")";
	}
	cout << "]" << endl;
}

Dictionary operator+(Dictionary first, Dictionary second)
{
	for (string s1 : first.pairKey)
	{
		for (string s2 : second.pairKey)
		{
			if (s1 == s2)
			{
				cout << "FOUND DUPLICATE KEYS" << endl;
				return first;
			}


		}
	}

	Dictionary temp = second;
	for (string s : first.pairKey)
		temp.add(s, first.get(s));
	return temp;
}

//Driver
int main()
{
	cout << "Nicolas Gonzales, cssc1833, nkgonzales@sdsu.edu/karushko@gmail.com";
	//First Dictionary 
	Dictionary d;

	d.add("steven", 5);
	d.del("steven");
	d.add("Jerry", 22);
	d.add("Ellie", 16);

	cout << "Getting Jerry's info: " << d.get("Jerry") << endl;
	d.in("Jerry");
	d.in("steven");
	d.keys();
	d.values();
	d.items();

	//Testing a second dictionary + operator override test
	Dictionary d2;
	d2.add("Heye", 9000);

	Dictionary d3;
	d3 = d + d2;

	cout << "D3's items" << endl;
	d3.items();

	system("pause");
	return 0;
}


