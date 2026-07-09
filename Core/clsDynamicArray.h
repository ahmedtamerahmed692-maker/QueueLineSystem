#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
protected:
	int _Size = 0;
	T* _TempArray = nullptr;

public:
	T* OriginalArray = nullptr;

	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
			Size = 0;

		_Size = Size;

		if (_Size > 0)
		{
			OriginalArray = new T[_Size];
		}
		else
		{
			OriginalArray = nullptr;
		}
	}

	~clsDynamicArray()
	{
		if (OriginalArray != nullptr)
		{
			delete[] OriginalArray;
		}
	}

	bool SetItem(int index, T Value)
	{
		if (index < 0 || index >= _Size)
		{
			return false;
		}

		OriginalArray[index] = Value;
		return true;
	}

	T GetItem(int index)
	{
		if (index < 0 || index >= _Size)
		{
			return T();
		}
		return OriginalArray[index];
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	void PrintList()
	{
		if (_Size == 0) return;

		for (int i = 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << " ";
		}
		cout << "\n";
	}

	void Resize(int NewSize)
	{
		if (NewSize < 0)
		{
			NewSize = 0;
		}

		_TempArray = new T[NewSize];

		if (NewSize < _Size)
		{
			_Size = NewSize;
		}

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_Size = NewSize;

		if (OriginalArray != nullptr)
		{
			delete[] OriginalArray;
		}

		OriginalArray = _TempArray;
	}
	void Reverse()
	{
		int left = 0;
		int right = _Size - 1;

		while (left < right)
		{
			T temp = OriginalArray[left];
			OriginalArray[left] = OriginalArray[right];
			OriginalArray[right] = temp;
			left++;
			right--;
		}
	}
	/*void  Reverse()
	{

		_TempArray = new T[_Size];

		int counter = 0;

		for (int i = _Size - 1; i >= 0; i--)
		{
			_TempArray[counter] = OriginalArray[i];
			counter++;
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;

	}*/

	void Clear()
	{
		if (OriginalArray != nullptr)
		{
			delete[] OriginalArray;
			OriginalArray = nullptr;
		}
		_Size = 0;
	}
	/*void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}*/
	/*T DeleteItemAt(int Index)
	{
		if (Index < 0 || Index >= _Size)
			return T();
		T DeletedItem = OriginalArray[Index];

		for (int i = Index; i < _Size - 1; i++)
		{
			OriginalArray[i] = OriginalArray[i + 1];
		}

		_Size--;
		Resize(_Size);

		return DeletedItem;
	}*/

	bool DeleteItemAt(int index)
	{

		if (index >= _Size || index < 0)
		{
			return false;
		}

		_Size--;

		_TempArray = new T[_Size];

		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		for (int i = index + 1; i < _Size + 1; i++)
		{
			_TempArray[i - 1] = OriginalArray[i];
		}

		delete[] OriginalArray; 
		OriginalArray = _TempArray;
		return true;

	}

	void DeleteFirstItem()
	{

		DeleteItemAt(0);

	}
	void DeleteLastItem()
	{

		DeleteItemAt(_Size - 1);
	}

	int Find(T Value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == Value) 
				return i;
		}
		return -1;
	}
	bool DeleteItem(T Value) {

		int index = Find(Value);

		if (index == -1)
		{
			return false;
		}

		DeleteItemAt(index);
		return true;

	}

	bool InsertAt(int index, T Value)
	{
		if (index > _Size || index < 0)
		{
			return false;
		}

		_Size++;

		_TempArray = new T[_Size];

		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_TempArray[index] = Value;

		for (int i = index; i < _Size - 1; i++)
		{
			_TempArray[i + 1] = OriginalArray[i];
		}

		if (OriginalArray != nullptr)
		{
			delete[] OriginalArray;
		}

		OriginalArray = _TempArray;
		return true;
	}
	void InsertAtBeginning(T value)
	{
		InsertAt(0, value);
	}

	bool InsertAtEnd(T value)
	{
		return InsertAt(_Size, value);
	}

	bool InsertBefore(int index, T value)
	{
		return InsertAt(index, value);
	}

	bool InsertAfter(int index, T value)
	{
		return InsertAt(index + 1, value);
	}

};
