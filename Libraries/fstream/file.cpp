#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(){
  // ------------------- Working With Files ------------------ //
  // // Step 1 - Open //
  // // with fstream
  // fstream file_in("./file.in", ios::in); // opening input file in binary
  // fstream file_out("./file.out", ios::out); // opening input file
  // fstream file_in_binary("./file.in", ios::in | ios::binary); // opening input file in binary

  // // with ifstream/ofstream
  // ifstream file_in_alt("./file.in"); // opening input file
  // ofstream file_out_alt("./file.out"); // opening output file

  // // with .open() method
  // ifstream file_in_not_open; // opening input file
  // file_in_not_open.open("./file.in");

  // // Step 2 - Check if open //
  // if(!file_in.is_open() || !file_out){
  //   cout << "Failed to open files";
  //   return 404;
  // }
  // // Step 3 - Work with files
  // // ....................

  // // Step 4 -  Close all opened files
  // file_in.close();
  // file_out.close();
  // file_in_binary.close();
  // file_in_alt.close();
  // file_out_alt.close();
  // file_in_not_open.close();

  // ------------------ Reading files ------------------- //
  // ifstream fin("./file.in");
  // if(!fin) return 404;
  
  // int n_numbers;
  // fin >> n_numbers; // reading to next white space using >> operator
  // vector<int> vec;
  // for(int i {0}; i < n_numbers; i++){
  //   int temp; fin >> temp;
  //   vec.push_back(temp); // reading into a vec
  // }
  // string text; 
  // char temp; fin.get(temp); // last character of line is '\n'.
  // getline(fin, text); // reading line
  // cout << text;
  // while(fin.get(temp)){
  //   cout << temp; //do something with remaining text  
  // }

  // fin.close(); // close file;
  
  // ------------------ Writing files ------------------- //
  // ofstream fout("file.out", ios::trunc); // open file and delete all previous text. Default
  // // ofstream fout("file.out", ios::app); // open file and append to it (no text is deleted)
  // // ofstream fout("file.out", ios::ate); // open file with the cursor at the end of the file
  // if(!fout) return 404;

  // int output1 = 12345;
  // double output2 = 1.1;
  // string output3 = "Hello!";

  // fout << output1 << endl;
  // fout << output2 << endl;
  // fout << output3 << endl;

  // for(char& c: output3){
  //   fout.put(c); // alternative way to write to files
  // }

  // fout.close();

  return 0;
}