int main(){
//	Student s(20,180);

//eager mode  也可以main()刚开始就getInstance(), 创建线程之前即可
	Student * pSudent =	Singleton<Student>::getInstance(18,200);
	Student * pSudent1 =	Singleton<Student>::getInstance(23,32);
	vector<int> * pVector=	Singleton<vector<int>>::getInstance();
	vector<int> * pVector1=	Singleton<vector<int>>::getInstance();

	printf("pSudent:%p\n",pSudent);
	printf("pSudent->age:%d\n",pSudent->_age);
	printf("pSudent->_height:%d\n",pSudent->_height);

	printf("pSudent1:%p\n",pSudent1);
	printf("pSudent1->_height:%d\n",pSudent1->_height);
	printf("pSudent1->age:%d\n",pSudent1->_age);

	printf("pVector:%p\n",pVector);
	printf("pVector1:%p\n",pVector1);

//	Singleton<Student>::destory();
	return 0;

}

