#include<bits/stdc++.h>
using namespace std;

template<typename DataType>
class MyVector
{
public:
    //构造空MyVector
	MyVector()
        //初始化列表
		: _array(new DataType[3])
		, _Capacity(3)
		, _size(0)
	{}
    //带参数的构造函数
	MyVector(DataType* array, size_t size)
        //初始化列表
		: _array(new DataType[size])
		, _Capacity(size)
		, _size(size)
	{
		for (size_t i = 0; i < size; ++i)
			_array[i] = array[i];
	}
	//参数为两个区间的构造函数，用[first，last]区间构造MyVector
	MyVector(DataType* first, DataType* last)
	{
		size_t size = last - first;
		_array = new DataType(size);
		_Capacity = size;
		_size = size;
 
		for (size_t i = 0; i < size; ++i){
			_array[i] = first[i];
		}
	}
    //拷贝构造函数
	MyVector(const MyVector& v)
	{
		_array = new DataType[v._size];
		_Capacity = v._size;
		_size = v._size;
		for (size_t i = 0; i < v._size; ++i)
			_array[i] = v._array[i];
	}
    //赋值运算符重载
	MyVector operator=(const MyVector& v)
	{
		if (this != &v){
			DataType *Tmp = _array;
			_array = new DataType(v._Capacity);
			_size = v._size;
			_Capacity = v._Capacity;
 
			delete[] Tmp;
			size_t i = 0;
			for (i = 0; i < v._size; ++i){
				_array[i] = v._array[i];
			}
		}
		return *this;
	}
    //析构函数
	~MyVector()
	{
		if (_array){
			delete[] _array;
			_array = NULL;
			_Capacity = 0;
			_size = 0;
		}
	}
    //运算符重载
	DataType& operator[](size_t index)const
	{
		assert(index < _size);
		return _array[index];
	}
    //获取MyVector中的第一个元素
	DataType& Front()
	{
		return _array[0];
	}
 
	const DataType& Front()const
	{
		return _array[0];
	}
    //获取MyVector中的最后一个元素
	DataType& Back()
	{
		return _array[_size - 1];
	}
 
	const DataType& Back()const
	{
		return _array[_size - 1];
	}
    //获取MyVector的大小
	size_t Size()const
	{
		return _size;
	}
    //获取MyVector的容量
	size_t Capacity()const
	{
		return _Capacity;
	}
    //重置MyVector的大小
	void ReSize(size_t newSize, const DataType& data = DataType())
	{
		size_t oldSize = Size();
		if (newSize <= oldSize)
			_size = newSize;
		else{
			if (newSize <= _Capacity){
				for (size_t i = oldSize; i < newSize; ++i)
					_array[i] = data;
			}
			else{
				DataType* pTemp = new DataType[newSize];
				for (size_t i = 0; i < oldSize; ++i)
					pTemp[i] = data;
				delete[] _array;
				_array = pTemp;
				_Capacity = newSize;
				_size = newSize;
			}
		}
	}
 
	void Reserve(size_t newCapacity)
	{
		size_t oldCapacity = Capacity();
		if (newCapacity > oldCapacity){
			DataType* pTemp = new DataType[newCapacity];
			for (size_t i = 0; i < Size(); ++i)
				pTemp[i] = _array[i];
			delete[] _array;
			_array = pTemp;
			_Capacity = newCapacity;
		}
	}
    //尾插
	void PushBack(const DataType& data)
	{
		_CheckCapacity();
		_array[_size++] = data;
	}
    //尾删
	void PopBack()
	{
		--_size;
	}
    //按下标插入
	void Insert(size_t pos, const DataType& data)
	{
		if (pos > _size){
			return;
		}
		_CheckCapacity();
		for (size_t i = _size - 1; i >= pos; i--)
			_array[pos] = data;
		
		++_size;
	}
    //按下标删除
	void Erase(size_t pos)
	{
		if (pos >= _size){
			return;
		}
		for (size_t i = pos; i < _size - 1; ++i)
			_array[i] = _array[i + 1];
 
		--_size;
	}
    //清空
	void Clear()
	{
		_size = 0;
	}
private:
    
	friend ostream& operator<<(ostream& _cout, const MyVector& v)
	{
		for (size_t i = 0; i < v._size; ++i){
			cout << v._array[i] << " ";
		}
		return _cout;
	}
 
private:
    //检查是否需要扩容
	void _CheckCapacity()
	{
		if (_size == _Capacity){
			Reserve(_Capacity * 2);
		}
	}
	
 
	DataType* _array;
	size_t _size;
	size_t _Capacity;
 
};
 
int main()
{
    giraffe<int> a;
    a[0] = 1;
    cout << a[0];
    return 0;
}