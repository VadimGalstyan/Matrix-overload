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

    Matrix(Matrix&& obj) : rows(obj.rows),cols(obj.cols),ptr(obj.ptr)
	{
		std::cout<<"Move ctor"<<std::endl;
		obj.ptr = nullptr;
		obj.cols = 0;
		obj.rows = 0;

	}

	Matrix& operator=(Matrix&& obj)
	{
		std::cout <<"Assignment move " << __FUNCTION__ << std::endl;

		if(this != &obj)
		{
        for(int i = 0;i < rows;++i)
		{
			delete [] ptr[i];
		}
		    delete[] ptr;

		        rows = obj.rows;
                cols = obj.cols;
				ptr = obj.ptr;

				obj.ptr = nullptr;
		        obj.cols = 0;
		        obj.rows = 0;

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

public:

    void printSize()const
	{
		std::cout<<"Rows: "<<rows<<std::endl;
		std::cout<<"Cols: "<<cols<<std::endl;

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

Matrix f(int x,int y)
{
	Matrix m(x,y);

	return m;
}

int main()
{
	Matrix m(2,2);
	Matrix m1 = std::move(m);
	

	m.printSize();
	m1.printSize();
}