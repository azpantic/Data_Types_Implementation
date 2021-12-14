#pragma once

#include"Ienumerable.h"
#include"Array.h"

template<typename T>
bool IsSort(Ienumerable<T>& sequence) {

	for (int i = 0; i < sequence.GetSize() - 1; i++)
	{
		if (sequence[i + 1] < sequence[i])
			return false;
	}

	return true;

};

template<typename T>
void Sort(Ienumerable<T>& sequence) {

	auto swap = [](T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	};

	for (int i = 0; i < sequence.GetSize(); i++)
	{
		for (int g = i + 1; g < sequence.GetSize(); g++)
		{
			if (sequence[i] > sequence[g])
				swap(sequence[g], sequence[i]);
		}
	}

}

template<typename T>
void QSort(Ienumerable<T>& sequence) {

};


template<typename T>
int LinearSearch(Ienumerable<T>& sequence, T elem, int start = 0, int end = -1) {

	if (end == -1)
		end = sequence.GetSize();

	for (int i = start; i < end; i++)
	{
		if (sequence[i] == elem)
			return i;
	}

	return -1;
}

template<typename T>
int BinarySearch(Ienumerable<T>& sequence, T elem, int start = 0, int end = -1) {

	if (end == -1)
		end = sequence.GetSize() - 1;

	int left = start, right = end;
	int mid;

	while (left <= right) {

		mid = (left + right) / 2;

		if (sequence[mid] == elem)
			return mid;

		if (sequence[mid] > elem)
			right = mid - 1;
		else
			left = mid + 1;

	}

	return -1;

}


template<typename T>
void Reverse(Ienumerable<T>& sequence, int start = 0, int end = -1) {

	if (end == -1)
		end = sequence.GetSize() - 1;

	auto swap = [](T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	};

	int mid = (end - start) / 2;

	for (int i = 0; i <= mid; i++) {
		swap(sequence[start + i], sequence[end - i]);
	}

};

template<typename T>
void Copy(Ienumerable<T>& source, Ienumerable<T>& destination, int start = 0, int len = -1) {
	if (len == -1)
		len = source.GetSize();

	for (int i = start; i < start + len; i++)
	{
		destination[i] = source[i];
	}
}

/// <summary>
///	�������� �������� source � ������� start �� ������ end � destination � �������� �������, 
/// destination ������ ������� ���� ��� ���������� ������
/// </summary>
/// <param name="source">������������������ ������ �������� ������</param>
/// <param name="destination">������������������ ���� �������� ������</param>
/// <param name="start">������ source � �������� ���������� �����������</param>
/// <param name="end">������ source �� ������� ����������� ����������</param>
template<typename T>
void ReverseCopy( Ienumerable<T>& source, Ienumerable<T>& destination, int start = 0, int end = -1) {

	GetSubsequence(source,destination ,  start, end);

	Reverse(destination);
	
}


/// <summary>
///	�������� �������� source � ������� start �� ������ end � destination, 
/// destination ������ ������� ���� ��� ���������� ������
/// </summary>
/// <param name="source">������������������ ������ �������� ������</param>
/// <param name="destination">������������������ ���� �������� ������</param>
/// <param name="start">������ source � �������� ���������� �����������</param>
/// <param name="end">������ source �� ������� ����������� ����������</param>
template<typename T> 
void GetSubsequence(Ienumerable<T>& source, Ienumerable<T>& destination, int start = 0, int end = -1) {
	if (end == -1)
		end = source.GetSize();

	for (int i = start; i < end; i++)
	{
		destination[i] = source[i];
	}

	
}

