// Формат записи:Фамилия,должность, дата рождения, стаж работы, заплата.
//пример:
//Иванов,электрик,  30-04-1990, 5, 28000.

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include <string>
using namespace std;
int countString(ifstream& is) {
	string tmp;
	int numbeString = 0;
	while (getline(is, tmp)){
		numbeString++;
	}
	is.clear();
	is.seekg(0, ios::beg);
	return numbeString;

}
//Первая задача
void countingSort(string *arrayString,int lengthArray){
	int maxAge=0, minAge= atoi(arrayString[0].substr(arrayString[0].rfind('-') + 1, 4).c_str());
	for (int i = 0; i < lengthArray; i++) {
		int age = atoi(arrayString[i].substr(arrayString[i].rfind('-') + 1, 4).c_str());
		if (maxAge < age)
			maxAge = age;
		if (minAge > age)
			minAge = age;
	}
	int lengthNewArray = maxAge - minAge + 1;
	string **bufArray = new string *[lengthNewArray];
	for (int i = 0; i<lengthNewArray; i++)
		bufArray[i] = new string[lengthArray];
	for (int i = 0; i <lengthNewArray; i++){
		for (int j = 0; j < lengthArray; j++) {
			bufArray[i][j] = "0";
		}
	}
	for (int i = 0; i < lengthNewArray-1;i++) {
		bufArray[atoi(arrayString[i].substr(arrayString[i].rfind('-') + 1, 4).c_str()) - minAge][0] = to_string(atoi(bufArray[atoi(arrayString[i].substr(arrayString[i].rfind('-') + 1, 4).c_str()) - minAge][0].c_str())+1);
		bufArray[atoi(arrayString[i].substr(arrayString[i].rfind('-') + 1, 4).c_str()) - minAge][0 + atoi(bufArray[atoi(arrayString[i].substr(arrayString[i].rfind('-') + 1, 4).c_str()) - minAge][0].c_str())] = arrayString[i];
	}
	int k = 0;
	for (int i = 0; i < lengthNewArray-1; i++) {
		for (int j = 1; j < lengthArray; j++) {
			if (bufArray[i][j] != "0") {
				arrayString[k] = bufArray[i][j];
				k++;
			}
		}
	}
	cout << endl << "Сортировка подсчетом по году рождения" << endl << endl;
	for (int i = 0; i < 9; i++) {
		cout << arrayString[i]<<endl;
	}
	cout << endl;
	ofstream fout;
	fout.open("countingSort.txt", ios_base::out);
	for (int i = 0; i < lengthArray; i++) {
		fout << arrayString[i]+'\n';
	}
	fout.close();
	for(int count = 0; count <(maxAge - minAge + 1); count++)
		delete[]bufArray[count];
}

//второя задача
void gnomeSort(string *arrayString, int lengthArray) {
	int i = 0, j = 0;
	while (i < lengthArray) {
		if (i == 0 || atoi(arrayString[i].substr(arrayString[i].rfind(',')+1 ,(arrayString[i].find('.') - arrayString[i].rfind(','))-1).c_str()) > atoi(arrayString[i-1].substr(arrayString[i-1].rfind(',')+1 ,(arrayString[i-1].find('.') - arrayString[i-1].rfind(','))-1).c_str()) ) {
			if (j > i)
				i = j;
			i++;
		}
		else {
			string tmp = arrayString[i - 1];
			arrayString[i - 1] = arrayString[i];
			arrayString[i] = tmp;
			if (i > j)
				j = i;
			i--;
		}
	}
	cout << "Гномья сортировка  по зарплате" << endl;
	for (int i = 0; i < 9; i++) {
		cout << arrayString[i] << endl;
	}
	cout << endl;
	ofstream fout;
	fout.open("gnomeSort.txt", ios_base::out);
	for (int i = 0; i < lengthArray; i++) {
		fout << arrayString[i] + '\n';
	}
	fout.close();
}
void insertingSort(string arrayString[], int lengthArray){
	string  tmp;
	int item;
	for (int i = 0; i < lengthArray; i++) {
		tmp = arrayString[i];
		item = i - 1;
		while (item >= 0 && (_stricmp(arrayString[item].substr(0, arrayString[item].find(',')).c_str(), tmp.substr(0, tmp.find(',')).c_str())) >= 0 ) {
			if ((_stricmp(arrayString[item].substr(0, arrayString[item].find(',')).c_str(), tmp.substr(0, tmp.find(',')).c_str())) == 0) {
				if (atoi(arrayString[item].substr(arrayString[item].rfind(',')-2,2).c_str()) < atoi(tmp.substr(tmp.rfind(',')-2,2).c_str())) {
					arrayString[item + 1] = arrayString[item];;
					arrayString[item] = tmp;
				}
				else {
					if (atoi(arrayString[item].substr(arrayString[item].rfind('-') + 1, 4).c_str()) < atoi(tmp.substr(tmp.rfind('-') + 1, 4).c_str())) {
						arrayString[item + 1] = arrayString[item];;
						arrayString[item] = tmp;
					}
				}
				break;
			}
			else {
				arrayString[item + 1] = arrayString[item];;
				arrayString[item] = tmp;
				item--;
			}
		}
	}
	cout <<endl<< "Сортировка с вставкой по фамилии, стаж работы и году рождения" << endl<<endl;
	for (int i = 0; i < 9; i++) {
		cout << arrayString[i] << endl;
	}
	cout << endl;
	ofstream fout;
	fout.open("insertingSort.txt", ios_base::out);
	for (int i = 0; i < lengthArray; i++) {
		fout << arrayString[i] + '\n';
	}
	fout.close();
}
int main()
{
	setlocale(LC_ALL, "rus");
	int numbeString;
	ifstream file("C:\\Users\\Nursultan\\Desktop\\list.txt");
	if (!file.is_open()) // если файл не открыт
	{
		cout << "Файл не может быть открыт!\n"; // сообщить об этом
	}
	else {
		int numbeString = countString(file);
		string *arrayString=new string[numbeString];
		cout << endl<<"Не сортированный массив"<<endl <<"----------------------------------------------------------------------"<<endl;
		for (int i = 0; i < numbeString; i++){
			getline(file, arrayString[i]);
			cout << arrayString[i] << endl;
		}
		cout <<"--------------------------------------------------------------------"<< endl;
		//первая задача
		countingSort(arrayString, numbeString);
		
		//второя задача
		gnomeSort(arrayString, numbeString);

		//третья задача
		insertingSort(arrayString, numbeString);
		delete[] arrayString;
	}
	file.close();
	system("pause");
	
    return 0;
}