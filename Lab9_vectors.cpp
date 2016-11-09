// Lab9_vectors.cpp
// This program shows some simple vector examples, and asks for simple tasks.
// Reference: Lippman, section 3.3

// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
// Example: g++ Lab9_vectors.cpp -o Lab9_vectors -std=c++11
// Some initialization methods and other things are not supported by the old standard.

#include <iostream>
#include <vector>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	vector<int> ivec1(5), ivec2;
	vector<double> dvec1{5.1}, dvec2(5,1.5);
	vector<string> svec1 = {"hello", "world"};
	// vector<myClass> myCvec;	// you can have vectors of objects
	// in general: vector<Type> vec;	// vector is a template

	for(int i = 0; i < ivec1.size(); i++)
		cout << ivec1[i] << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:ivec1)	// This is equivalent to the above for loop
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:dvec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:dvec2)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:svec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
		
	cout << "Original size: " << ivec2.size() << endl;
	ivec2.push_back(50);
	cout << "New size: " << ivec2.size() << "\nAdded element: " << ivec2[0] << endl;
	cout << "\n------------------------------------------------------------------" << endl;

	//initializing vectors all the ways shown in Table 3.4
	vector<double> v1;
	vector<double> v2(dvec1);
	vector<double> v3=v2;
	vector<float> v4(3,2.3);
	vector<double> v5(2);
	vector<float> v6{3,5,87,2.7,3};
	vector<int> v7={3,5,87,2,3};
	
	//Trying all the vector operations shown in Table 3.5
	cout<<endl<<"Is the vector v1 empty? "<<v1.empty();
	cout<<endl<<"Is the vector v2 empty? "<<v2.empty();
	cout<<endl<<"Number of elements in v4 is: "<<v4.size();
	v4.push_back(5);
	cout<<endl<<"Number of elements in v4 after the push_back is: "<<v4.size();
	cout<<endl<<"The number that is at position 4 of v4 is: "<<v4[3];
	v1=v2;
	cout<<endl<<"The empty vector v1 now has the value of: "<<v1[0];
	v3={5.4,3.2,5.3};
	cout<<endl<<"Vector v3 now contains the following values:"<<endl;
	for(auto i:v3)
		cout << i << endl;
	cout<<endl<<"Does v1 have the same number of elements as v2? "<<(v1 == v2);
	cout<<endl<<"Does v1 not have the same number of elements as v2? "<<(v1 != v2);
	
	
	
	//exercise 3.14 read a sequence of ints from cin into a vector
	int numb[5];//array to hold my input numbers
	
	for(int i=0;i<5;i++){
		cout<<endl<<"Enter a number of integer type: ";
		cin>>numb[i];
	}
	vector<int> v8{numb[0],numb[1],numb[2],numb[3],numb[4]};
	
	for(auto i:v8)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;

	//exercise 3.15 read a sequence of strings from cin into a vector
	string str1[5];//array to hold my input numbers
	
	for(int i=0;i<5;i++){
		cout<<endl<<"Enter a string: ";
		cin>>str1[i];
	}
	vector<string> v9{str1[0],str1[1],str1[2],str1[3],str1[4]};
	
	for(auto i:v9)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
// ***********************************************************************
// Try all the wasy to initializa a vector shown in Table 3.4. Use the
// vectors above and/or declare new vectors.
// Some of those operations have already been used, but write your
// own examples.

// Do exercises 3.14 and 3.15 from Lippman (page 102)

// Try all the vector operations shown in table 3.5. Use the vectors above
// or define new ones. Try different types.
// ***********************************************************************

	return 0;
}