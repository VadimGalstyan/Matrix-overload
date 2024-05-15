#include <iostream>

class Matrix
{
public:
	Matrix(int row,int col) : rows(row),cols(col)
	{
		ptr = new int*[rows];
		for(int i = 0;i < rows;++i)
		{
			ptr[i] = new int[cols];
		}
	}

	Matrix(const Matrix& obj)
	{
		rows = obj.rows;
		cols = obj.cols;

                ptr = new int*[rows];
                for(int i = 0;i < rows;++i)
                {
                        ptr[i] = new int[cols];
                }

	        for(int i =0;i < rows;++i)
		{
			for(int j = 0;j < cols;++j)
			{
				ptr[i][j] = obj.ptr[i][j];
			}
		}
	}

	Matrix& operator=(const Matrix& obj)
	{
		if(this != &obj)
		{
			if(rows != obj.rows || cols != obj.cols)
			{
				for(int i = 0;i < rows;++i)
                                {  
                                 delete [] ptr[i];
                                }
                                delete[] ptr;
			}
                        
		rows = obj.rows;
                cols = obj.cols;

                ptr = new int*[rows];
                for(int i = 0;i < rows;++i)
                {
                        ptr[i] = new int[cols];
                }

                for(int i =0;i < rows;++i)
                {
                        for(int j = 0;j < cols;++j)
                        {
                                ptr[i][j] = obj.ptr[i][j];
                        }
                }
		}

		return *this;
	}

	~Matrix()
	{
		for(int i = 0;i < rows;++i)
		{
			delete [] ptr[i];
			ptr[i] = nullptr;
		}
		delete[] ptr;
		ptr = nullptr;
	}
        
	Matrix& operator++()
	{
                for(int i =0;i < rows;++i)
                {
                        for(int j = 0;j < cols;++j)
                        {
                                ptr[i][j] += 3;
                        }
                }
		return *this;
	}

	Matrix operator++(int)
	{
		Matrix tmp = *this;
		++(*this);
		return tmp;
	}

	void print() const
	{
		for(int i =0;i < rows;++i)
                {
                        for(int j = 0;j < cols;++j)
                        {
				std::cout<<ptr[i][j]<<" ";
                        }
			std::cout<<std::endl;
                }
		std::cout<<std::endl;
	}

	void matrixInit()
	{
		for(int i =0;i < rows;++i)
                {
                        for(int j = 0;j < cols;++j)
                        {
                                ptr[i][j] = 0;
                        }
                }
	}



private:
	int rows = 0;
	int cols = 0;
	int** ptr = nullptr;
};


int main()
{
	Matrix m(2,2);
	m.matrixInit();
	m.print();
	++m;
	m.print();
}
