#pragma once
#include <iostream>
#include "Header.h"
void add(int num, int value, dmassiv* q) {
	bool is_full(int, dmassiv*);
	if (!is_full(num, q)) {
		q->massiv[q->end[num - 1]] = value;
		q->end[num - 1]++;
		return;
	}
	else {
		cout << "stack" << num << " is full \n";
		return;
	}
};

void print(int num, dmassiv* q) {
	if (q->start[num - 1] != q->end[num - 1]) {
		cout << "stack " << num << ": ";
		for (int i = q->start[num - 1]; i < q->end[num - 1]; i++)	cout << q->massiv[i] << " ";
		cout << "\n";
	}
	else cout << "stack " << num << " is empty\n";
	return;
};
void pop(int num, dmassiv* q) {

	if (q->start[num - 1] == q->end[num - 1]) { cout << "stack " << num << " is empty\n"; return; }
	else {
		q->massiv[q->end[num - 1]] = NULL;
		q->end[num - 1]--;

	}
}
bool is_empty(int num, dmassiv* q) {
	return q->start[num - 1] == q->end[num - 1];
}
bool is_full(int num, dmassiv* q) {
	int lenth(int, dmassiv*);
	return (q->sizes_of_stacks[num - 1] == lenth(num, q)) || (q->start[num] == q->end[num - 1]);
}
int lenth(int num_queue, dmassiv* q) {
	return q->end[num_queue - 1] - q->start[num_queue - 1];
}
void alloc(dmassiv* q)
{
	try {
		int count = 0;
		for (int i = 0; i < q->Size; i++)
			count += q->sizes_of_stacks[i];
		q->massiv = new int[count];
		for (int i = 1; i < q->Size; i++)
		{
			q->end[i] = q->sizes_of_stacks[i - 1] + q->end[i - 1];
			q->start[i] = q->sizes_of_stacks[i - 1] + q->start[i - 1];
		}

	}
	catch (bad_alloc e)
	{
		cout << "can't give memory\n";
	}
}
void del(dmassiv* q)
{
	delete[]q->massiv;
	q->end[0] = 0;
	q->start[0] = 0;
	for (int i = 1; i < q->Size; i++)
	{
		q->end[i] = q->sizes_of_stacks[i - 1] + q->end[i - 1];
		q->start[i] = q->sizes_of_stacks[i - 1] + q->start[i - 1];

	}

}




/*void del_start(int num_queue, queues* q) {

	if (q->start[num_queue - 1] == q->end[num_queue - 1]) { cout << "queue is empty\n"; return; }
	else {

		int* old_values;
		old_values = q->queue;
		try
		{
		q->queue = new int[q->end[q->Size - 1]-1 ];
		for (int i = 0; i < q->start[num_queue - 1]; i++)
				{//???????? ?? 1 ?? ?????? ???????
					q->queue[i] = old_values[i];
				}

		for (int i = q->start[num_queue - 1]; i < q->end[q->Size - 1]-1; i++)
				{//???????? ????? 1 ?? ?????? ???????
					q->queue[i] = old_values[i+1];
				}

		q->end[num_queue - 1]--;
		for (int i = num_queue; i < q->Size; i++) {
			q->start[i]--;
			q->end[i]--;
		}

		delete[]old_values;

		}
		catch (bad_alloc e)
		{
		cout << "can't give memory\n";
		}


	}
}*/


/*void add_end(int num_queue, int value, queues* q) {

	if (q->sizes_of_queues[num_queue - 1] != lenth(num_queue, q))
	{//?????? ??? ??????? ?? ????????
	  int* old_values;
	  old_values = q->queue;
	  try {
		  q->queue = new int[q->end[q->Size - 1] + 2];
		  for (int ii = 0; ii < q->end[num_queue - 1]; ii++)
		  {//???????? ?? ???? ?? ?????? ???????
			  q->queue[ii] = old_values[ii];
		  }
		  q->queue[q->end[num_queue - 1]] = value;
		  for (int i = q->end[num_queue - 1]+1; i < q->end[q->Size - 1]; i++)
		  {//???????? ????? ???? ?? ?????? ???????
			  q->queue[i] = old_values[i-1];
		  }
		  q->end[num_queue - 1]++;
		  for (int i = num_queue; i < q->Size; i++) {
			  q->start[i]++;
			  q->end[i]++;
		  }
		  delete[]old_values;
		  return;
	  }
	  catch (bad_alloc e) {
		  cout << "can't give memory\n";
	  }
  }

	else {
		cout << "queue is full \n";
		return;
	}
};*/