/*
 ============================================================================
 Name        : L7.cpp
 Author      : Jacob Bracey
 Description : ECE 3220: Lab 7
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include <io.h>
//#include <conio.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


//result is used to determine if files and memory allocation behaved correctly
int result=0;

class Signal{
	private:
			double max;
			vector<double> data;
			double mean;
			
			
	public:
			Signal();
			Signal(int);
			Signal(const char*);
			~Signal();
			Signal& builder();
			Signal& builder(int file_sel);
			Signal& builder(const char* file_name);
			void offset(double num);
			void scale(double num);
			void center();
			void normal();
			void stats();
			void Sig_info();
			void Print_signal();
			void Save_file(const char*);
			void operator+(double);
			void operator*(double);
			int get_length();
			vector<double> get_a_copy();
			void update_data(vector<double>);
			void update_max(double);
			void update_mean(double);
			double get_max();
			double get_mean();
};

Signal::~Signal(){
	cout << "Signal Destructed" << endl;
}

Signal::Signal(){
	//default constructor
	data={0};
	max=0;
	mean=0;
}

Signal& Signal::builder(){
	//default constructor
	data={0};
	max=0;
	mean=0;
}

Signal& Signal::builder(int file_sel){
	char file_name[66];
	int length;
	if ( file_sel< 10)//makes the file names
		sprintf(file_name, "Raw_data_0%d.txt", file_sel);
	else
		sprintf(file_name, "Raw_data_%d.txt", file_sel);

	FILE* fp = fopen(file_name, "r");
	//opens the given input file for reading

	if (fp == NULL) { //making sure the default input file opens correctly
		cout<<"Error opening the default input file "<<file_name<<endl;
		result=0;
	}
	else{
	result=1;

	fscanf(fp, "%d %lf", &length, &max);
	vector<double> temp(length);

	int i = 0;
	for (i = 0; i < length; i++) {
		//for loop to put the values into the array
		fscanf(fp, "%lf", (&temp[i]));
	}
	data=temp;
	fclose(fp);
	}
	return *this;
}

Signal& Signal::builder(const char* file_name){
		//method if a filename is given by the user
		FILE* fp = fopen(file_name, "r");
		int length;
		//opens the given input file for reading
		if (fp == NULL) { //making sure the default input file opens correctly
			cout<<"Error opening the default input file "<<file_name<<endl;

			//sets result to 0 that way main will know that this was unsuccessful
			result=0;

		}
		else{
		//this happens if file opening was successful

		//sets result to 1 that way main will know that this was successful
		result=1;
		fscanf(fp, "%d %lf", &length, &max);
		vector<double> temp(length);

		int i = 0;
		for (i = 0; i < length; i++) {
			//for loop to put the values into the array
			fscanf(fp, "%lf", (&temp[i]));
		}
		data=temp;
		fclose(fp);
		}
		return *this;
}

Signal::Signal(int file_sel){
	//this constructor calls the method that gets all data when given a file number
	builder(file_sel);
	stats();
}

Signal::Signal(const char* file_name){
	//this constructor calls the method that gets all data when given a filename
	builder(file_name);
	stats();
}

void Signal::operator +(double num){
	int i=0;
	for(i=0; i<data.size(); i++){ //multiplies the scaling factor to all data values
		data[i]+=num;
	}
}

void Signal::operator *(double num){
	int i=0;
	for(i=0; i<data.size(); i++){ //multiplies the scaling factor to all data values
		data[i]=data[i]*num;
	}
}

void Signal::offset(double num){
	//this method offsets the given input string
	int i=0;
	operator+(num);
	stats(); //Updates stats after operation
}

void Signal::scale(double num){
	int i=0;
	operator*(num);
	stats(); //updates stats after operation
}

void Signal::stats(){ //updates mean and max
	int i=0;
	double add=0;
	max=0;
	for (i = 0; i<data.size(); i++){
		if (data[i] > max)
		max = data[i];
	}
	
	for (i = 0; i < data.size(); i++){
		add += data[i];
	}
	mean = (double)add/data.size();
}

void Signal::center(){
	double temp=-1*mean;
	operator+(temp);
	stats(); //Updates stats after operation
}

void Signal::normal(){
	double temp;
	temp=(double)(1/max);
	printf("%lf", max);
	operator*(temp);
	stats(); //updates stats after operation
}

void Signal::Sig_info(){
	cout << "Length: " << data.size() << endl << "Max: " << max << endl << "Average: " << mean << endl<<endl; //prints out signal info
}

void Signal::Print_signal(){
	int i;
	for(i = 0; i<data.size(); i++) //prints new array values to file
	{
		cout<<data[i]<<endl;
	}
}

void Signal::Save_file(const char* file_name){
	FILE* fp = fopen(file_name, "w");
	int i;
	//opens the given output file for write

	if (fp == NULL) //making sure the output file exists and creates a new one if it doesn't
	{
		freopen(file_name, "w", fp);
	}

	fprintf(fp, "%d %lf", data.size(), max);
	for(i = 0; i<data.size(); i++) //prints new array values to file
	{
		fprintf(fp, "%.4f\n", data[i]);
	}
	fclose(fp); //closes file
}

int Signal::get_length(){
	
	return data.size();
	
}

vector<double> Signal::get_a_copy(){
	vector<double> temp_vec;
	temp_vec=data;
	return temp_vec;
}

void Signal::update_data(vector<double> temp){
	data=temp;
	
}

double Signal::get_max(){
	return max;
}

double Signal::get_mean(){
	return mean;
}

void Signal::update_mean(double temp){
	mean=temp;
}

void Signal::update_max(double temp){
	max=temp;
}

//non-member function operator that takes 2 signals and returns a new signal
Signal operator+(Signal s1, Signal s2){
	
	Signal temp;
	vector<double> vec1;
	vector<double> vec2;
	vector<double> vectemp;
	
	
	if(s1.get_length()!=s2.get_length()){
		cout<<"The Signals are not of the same length, they cannot be added\n";
		return temp;
	}
	vec1=s1.get_a_copy();
	vec2=s2.get_a_copy();
	
	int i;
	//double te;
	
	for(i=0; i<s1.get_length(); i++){ //multiplies the scaling factor to all data values
		//te=(vec1[i])+(vec2[i]);
		vectemp.push_back((vec1[i])+(vec2[i]));
	}
	
	temp.update_data(vectemp);
	temp.stats();
	cout<<s1.get_mean()<<" "<<s2.get_mean()<<" "<<s1.get_max()<<" "<<s2.get_max();
	temp.update_mean(((s1.get_mean())+(s2.get_mean()))/2);
	if (s1.get_max()>s2.get_max())
		temp.update_max(s1.get_max());
	else
		temp.update_max(s2.get_max());
	
	return temp;
	
}


int main(int argc, char *argv[]) {
	
	//ints to hold user inputs
	int file_sel=0;
	int choice=0;
	int choice_input_type=0;

	
	//defines all of our file name strings
	char file_name[66];
	char new_file_name[66];
	
	//defines the signal for us to use
	Signal sig1;
	Signal sig2;
	
	double offset_val,scale_val;//vlaues to store scale and offsets	
	
	if (argc==3){
		//if argc=3 then we have one tag and then 1 user input
		//this is the only way this runs
		
		if(argv[1][0]=='-' && argv[1][1]=='n'){
			file_sel=atoi(argv[2]);//happens if user gives a valid input
			sig1.builder(file_sel);	
		}
		
		else if(argv[1][0]=='-' && argv[1][1]=='f'){
			sprintf(new_file_name,"%s",argv[2]);
			sig1.builder(new_file_name);
		}
		else	
				cout<<endl<<"The formatting of the command line arguments is incorrect\nYou can only have one tag, either '-f or '-n'.\n";
		
	}//end of case where user enters a tag and then 1 input


	else if(argc==1){
		//if the user leaves the command line blank then this part is executed and input is received from the user
		
		
		//lets the user decide if they want to enter a filename or file number or do the default which is to open data file 1
		cout<<endl<<"Would you like to\n(1) Enter a filename\n(2) Enter a file number\n(3) Select the default case"<<endl;
		cin>>choice_input_type;
		
		//if user wants to enter a full filename
		if(choice_input_type==1){
			cout<<endl<<"Please enter a valid filename\n";
			cin>>file_name;
			sig1.builder(file_name);
		}
		
		//if user wants to enter a file number
		else if(choice_input_type==2){
			cout<<endl<<"Please enter a valid file number\n";
			cin>>file_sel;
			sig1.builder(file_sel);
		}
		
		//if user wants to perform the default case which is to open text file 1
		else{
			sig1.builder();
		}
		
	}//end of case where user leaves command line empty


	else{
		//if the user enters an incorrect number of command line arguments then an error message is displayed an the program is terminated
		cout<<endl<<"You entered an incorrect number of command line arguments\nYou may either have no command line arguements or you may have 1 tag ('-f'or '-n') followed by the filename or file number, respectively\n";
	}
		
	if(result==0){
		//if no files are read then result will equal 0
		//if there is no data there is no need to get user input
		//ending program if this is the case
		return 0;
	}
	
	
	
	while(choice!=8){
		cout << endl << "Please select an option"<<endl<<"(1):offset signal\n(2):scale signal\n(3):center signal\n(4):normalize signal\n(5):Display Statistics\n(6):Print Signal\n(7):Save Signal\n(8):Exit\n";
		cin>>choice;
		cout<<endl;
		
		switch(choice){
			case 1:
					cout<<"Please enter an offset value:";
					cin>>offset_val;
					sig1.offset(offset_val);
					cout<<"Signal has been offset"<<endl;
					break;
			case 2:
					cout<<"Please enter a scale value:";
					cin>>scale_val;
					sig1.scale(scale_val);
					cout<<"Signal has been scaled"<<endl;
					break;
			
			case 3:
					sig1.center();
					cout<<"Signal has been centered"<<endl;
					break;
			case 4:
					sig1.normal();
					cout<<"Signal has been normalized"<<endl;
					break;
			case 5:
					sig1.Sig_info();
					cout<<"Signal Statistics have been printed out"<<endl;
					break;
			case 6:
					sig1.Print_signal();
					cout<<"The signal has been printed out"<<endl;
					break;
					
			case 7:
					cout<<"Please enter a file name to save the signal to:";
					cin>>new_file_name;
					sig1.Save_file(new_file_name);
					break;
			case 8:
					//exits out of the switch
					break;
					
			default:
					cout<<"Invalid number entered\nPlease try again\n";
			
		
		}//end of switch statement		
		
	}//end of while
	
	//lets the user decide if they want to enter a filename or file number or do the default which is to open data file 1
		cout<<endl<<"Would you like to\n(1) Enter a filename\n(2) Enter a file number\n(3) Select the default case"<<endl;
		cin>>choice_input_type;
		
		//if user wants to enter a full filename
		if(choice_input_type==1){
			cout<<endl<<"Please enter a valid filename\n";
			cin>>file_name;
			sig2.builder(file_name);
		}
		
		//if user wants to enter a file number
		else if(choice_input_type==2){
			cout<<endl<<"Please enter a valid file number\n";
			cin>>file_sel;
			sig2.builder(file_sel);
		}
		
		Signal sig3;
		
		sig3 = operator+(sig1,sig2);
		
		sig3.Print_signal();
		sig3.Sig_info();
		

return 0;

} //end of main

