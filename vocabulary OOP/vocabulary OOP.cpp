#include <iostream>
#include <string>
#include <locale>
#include <thread>

using namespace std;

struct DictionaryEntry 
{
	string key;
	string value;
};

void printDictionary(const DictionaryEntry* dictionary, int size) 
{
	cout << "Словарь:" << endl;
	for (int i = 0; i < size; i++) 
	{
		cout << dictionary[i].key << ": " << dictionary[i].value << endl;
	}
}

int findEntryIndex(const DictionaryEntry* dictionary, int size, const string& key) 
{
	for (int i = 0; i < size; i++) 
	{
		if (dictionary[i].key == key) 
		{
			return i;
		}
	}
	return -1;
}

void addEntry(DictionaryEntry*& dictionary, int& size) 
{
	string key, value;
	cout << "Введите ключ: ";
	cin >> key;
	cout << "Введите значение: ";
	cin >> value;

	int newSize = size + 1;

	DictionaryEntry* newDictionary = new DictionaryEntry[newSize];

	for (int i = 0; i < size; i++) 
	{
		newDictionary[i] = dictionary[i];
	}

	DictionaryEntry newEntry;
	newEntry.key = key;
	newEntry.value = value;
	newDictionary[newSize - 1] = newEntry;

	delete[] dictionary;

	dictionary = newDictionary;
	size = newSize;

	cout << "Запись добавлена!" << endl;
	cout << "-----------------------" << endl;
}

void deleteEntry(DictionaryEntry*& dictionary, int& size) 
{
	string key;
	cout << "Введите ключ для удаления: ";
	cin >> key;

	int index = findEntryIndex(dictionary, size, key);

	if (index != -1) 
	{
		int newSize = size - 1;
		DictionaryEntry* newDictionary = new DictionaryEntry[newSize];
		int j = 0;
		for (int i = 0; i < size; i++) 
		{
			if (i != index) 
			{
				newDictionary[j] = dictionary[i];
				j++;
			}
		}
		delete[] dictionary;
		dictionary = newDictionary;
		size = newSize;
		cout << "Запись удалена!" << endl;
	}
	else {
		cout << "Запись не найдена!" << endl;
	}
	cout << "-----------------------" << endl;
}

int main() 
{
	setlocale(LC_ALL, "");

	char x = 219;
	for (size_t i = 1; i < 11; i++) 
	{
		cout << "\n\n\n\n\n\n\n\t\t\t\tWelcome to the Dictionary!";
		cout << "\n\n\t\t\t\tLoading.......";
		cout << "\n\t\t\t\t";
		for (size_t y = 0; y < i * 2; y++) 
		{
			cout << x;
		}
		cout << i * 10 << "%\n";
		this_thread::sleep_for(chrono::milliseconds(500));
		system("cls");
	}

	int dictionarySize = 3;

	DictionaryEntry* dictionary = new DictionaryEntry[dictionarySize];

	dictionary[0].key = "apple";
	dictionary[0].value = "яблоко";

	dictionary[1].key = "banana";
	dictionary[1].value = "банан";

	dictionary[2].key = "orange";
	dictionary[2].value = "апельсин";

	printDictionary(dictionary, dictionarySize);

	int choice;
	while (true) 
	{
		cout << endl;
		cout << "Меню:" << endl;
		cout << "1. Добавить запись" << endl;
		cout << "2. Удалить запись" << endl;
		cout << "3. Выйти" << endl;
		cout << "Выберите действие: ";
		cin >> choice;

		switch (choice) {
		case 1:
			addEntry(dictionary, dictionarySize);
			printDictionary(dictionary, dictionarySize);
			break;

		case 2:
			deleteEntry(dictionary, dictionarySize);
			printDictionary(dictionary, dictionarySize);
			break;

		case 3:
			delete[] dictionary;
			return 0;
		}
	}
}