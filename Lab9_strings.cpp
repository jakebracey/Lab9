// Lab9_strings.cpp
// This program shows some simple string examples, and asks for simple tasks.
// Reference: Lippman, section 3.2

// Author: Luis Rivera

#include <iostream>
#include <string>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	string s1;
	cout << "\nEnter a word:" << endl;
	cin >> s1;
	
	string s2("Hey Guys!!");
	string s3 = "Whats up???";
	string s4(s1);
	string s5=s2;
	string s6(5,'a');
	
	
	cout << s1 << endl
		 << s2 << endl
		 << s3 << endl
		 << s4 << endl
		 << s5 << endl
		 << s6 << endl<<endl;
		 
		string os;
		//os<<s1; //mention this in report
		//is>>s1; //mention this in report
		//getline(is,os);//mention this in report
		cout<<"Is the string os empty? "<<os.empty()<<endl<<"How long is string s1? "<<s1.size()<<endl;
		 
		cout<<"First character of string s2: "<<s2[0]<<endl;
		cout<<s1+s2<<endl;
		
		cout<<"Is s5 the same as s2? "<<(s5==s2)<<endl;
		cout<<"Is s5 NOT the same as s2? "<<(s5!=s2)<<endl;
		cout<<"Is s5 > s4? "<<(s5>s4)<<endl;
		cout<<"Is s5 >= s4? "<<(s5>=s4)<<endl;
		cout<<"Is s5 < s4? "<<(s5<s4)<<endl;
		cout<<"Is s5 <= s4? "<<(s5<=s4)<<endl;
		

		
		
		
	s1 = s2 + s3;
	cout << s1 << endl;

// ***********************************************************************
// Try all the operations in Table 3.2 using the strings above and
// using new strings that you may declare.
// Some of those operations have already been used, but write your
// own examples.
// ***********************************************************************

// -----------------------------------------------------------------------
	string line;
	cout << "\nEnter some text, finish it with an &" << endl;
	getline(cin, line, '&');
	cout << line << endl;
	
	//converting the string to uppercase
	for (auto &c : line)
		c= toupper(c);
	cout<<line<<endl;
	
	//converting the string to lowercase
	for (auto &c : line)
		c= tolower(c);
	cout<<line<<endl;
	
	//converting any spaces to '.'
	for (auto &c : line){
		if(isspace(c))
			c='.';	
	}
	cout<<line<<endl;

// ***********************************************************************
// Use a "Range for" (Lippman, page 93) and operations in table 3.3 to:
// 1) change the case of the letters in your input line above (upper to
//    lowercase and vice-versa).
// 2) Replace any whitespace with a dot ('.').
// Print the converted text.
// ***********************************************************************

	return 0;
}