#include <iostream> 
#include "OrderedList.h"
#include "OrderedList_Task2.h"
#include "OrderedList_Task3.h"
#include "custom_exceptions.h"
#include "Auto.h"
#include "OrderedList.cpp"
#include "OrderedList_Task2.cpp"
#include "OrderedList_task3.cpp"

int random(){
	int temp;
	temp = rand() % 1;
	return temp;
}
int random_r(int num){
	int temp;
	temp = rand() % num;
	return temp;
}
int list(int num){
	int templist[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
	int temp;
	temp = templist[num];
	return temp;
}

int main(){
	const int Max_num = 10;
	const int LOOP = 1; // change this wale for task four to loop the code 100 times
	int op1 = 0;
	int op2 = 0;
	int op3 = 0;
	int totalloop = 0;
	Auto automation;
	OrderedList<int> Task1list;
	OrderedList_Task2<int> Tasklist2;
	OrderedList_Task3<int> Tasklist3;

	while (totalloop < LOOP){
		int print1 = 0;
		int autorun = 0;
		int ADD = 0;
		int REMOVE = 0;
		int Counter1 = 0;
		int list[Max_num]{};

		while (ADD < Max_num){
			automation.autogen();
			autorun = automation.getstorage();
			list[ADD] = autorun;
			try{
				Task1list.AddItem(&autorun);
			}catch (ListFull exp){
				std::cout << exp.what() << std::endl;
			}
			ADD++;
		}
		while (print1 < (sizeof(list) / 4)){
			std::cout << list[print1] << " ";
			print1++;
		}
		std::cout << std::endl;
		while (REMOVE < Max_num) {
			Counter1 = random_r((sizeof(list) / 4));
			autorun = list[Counter1];
			if (autorun != -1){
				try {
					Task1list.RemoveItem(&autorun);
				}catch (ListEmpty exp){
					std::cout << exp.what() << std::endl;
				}
			}else{
				while (autorun == -1){
					Counter1 = random_r((sizeof(list) / 4));
					autorun = list[Counter1];
				}try{
					Task1list.RemoveItem(&autorun);
				}catch (ListEmpty exp){
					std::cout << exp.what() << std::endl;
				}
			}
			std::cout << autorun << " ";
			list[Counter1] = -1;
			REMOVE++;
		}
		op1 += Task1list.get_op_count();
		std::cout << Task1list.get_num_items() << " " << Task1list.get_op_count() << " op count task 1" << std::endl;

		int print2 = 0;
		int autorun2 = 0;
		int ADD2 = 0;
		int REMOVE2 = 0;
		int Counter2 = 0;
		int list2[Max_num]{};

		while (ADD2 < Max_num){
			automation.autogen();
			autorun2 = automation.getstorage();
			list2[ADD2] = autorun2;
			try{
				Tasklist2.AddItem(&autorun2);
			}catch (ListFull exp){
				std::cout << exp.what() << std::endl;
			}
			ADD2++;
		}

		while (print2 < (sizeof(list2) / 4)){
			std::cout << list2[print2] << " ";
			print2++;
		}
		std::cout << std::endl;

		while (REMOVE2 < Max_num){
			Counter2 = random_r((sizeof(list2) / 4));
			autorun2 = list2[Counter2];
			if (autorun2 != -1){
				try{
					Tasklist2.RemoveItem(&autorun2);
				}catch (ListEmpty exp){
					std::cout << exp.what() << std::endl;
				}
			}else{
				while (autorun2 == -1){
					Counter2 = random_r((sizeof(list2) / 4));
					autorun2 = list2[Counter2];
				}try{
					Tasklist2.RemoveItem(&autorun2);
				}catch (ListEmpty exp){
					std::cout << exp.what() << std::endl;
				}
			}
			std::cout << autorun2 << " ";
			list2[Counter2] = -1;
			REMOVE2++;
		}
		op2 += Tasklist2.get_op_count();
		std::cout << Tasklist2.get_num_items() << " " << Tasklist2.get_op_count() << " op count task 2" << std::endl;

		int print3 = 0;
		int autorun3 = 0;
		int ADD3 = 0;
		int REMOVE3 = 0;
		int Counter3 = 0;
		int list3[Max_num]{};

		while (ADD3 < Max_num){
			automation.autogen();
			autorun3 = automation.getstorage();
			list3[ADD3] = autorun3;
			try{
				Tasklist3.AddItem(&autorun3);
			}catch (ListFull exp){
				std::cout << exp.what() << std::endl;
			}
			ADD3++;
		}

		while (print3 < (sizeof(list3) / 4)){
			std::cout << list3[print3] << " ";
			print3++;
		}
		std::cout << std::endl;

		while (REMOVE3 < Max_num) {
			Counter3 = random_r((sizeof(list3) / 4));
			autorun3 = list3[Counter3];
			if (autorun3 != -1){
				try{
					Task1list.RemoveItem(&autorun3);
				}catch (ListEmpty exp){
				}
			}else{
				while (autorun3 == -1){
					Counter3 = random_r((sizeof(list3) / 4));
					autorun3 = list3[Counter3];
				}try{
					Tasklist3.RemoveItem(&autorun3);
				}catch (ListEmpty exp){
					break;
				}
			}
			std::cout << autorun3 << " ";
			list3[Counter3] = -1;
			REMOVE3++;
		}
		op3 += Tasklist3.get_op_count();
		std::cout << Tasklist3.get_num_items() << " " << Tasklist3.get_op_count() << " op count task 3" << std::endl << std::endl;
		totalloop++;
	}

	std::cout << "The total oprations for task1:" << op1 << std::endl;
	std::cout << "The total oprations for task2:" << op2 << std::endl;
	std::cout << "The total oprations for task3:" << op3 << std::endl;

	return 0;
}
