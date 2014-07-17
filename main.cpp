/*************************
  ASSIGNMENT 2
  OKTAY SANCAK, SAOKD0903
**************************/

#include<iostream>
#include<iomanip>

using namespace std;

const string VOWELS = "AEIOUaeiou";
/* Task Types */
const short int TASK_CONVERT_UPPER_CASE   = 1;
const short int TASK_CONVERT_LOWER_CASE   = 2;
const short int TASK_CONVERT_TITLE_CASE   = 3;
const short int TASK_FLIP_CASE            = 4;
const short int TASK_NUMBER_OF_ALPHABETS  = 5;
const short int TASK_NUMBER_OF_CONSONANTS = 6;
const short int TASK_NUMBER_OF_VOWELS     = 7;
const short int TASK_CHECK_VALID_LITERAL  = 8;
const short int TASK_SHOW_TOKENS          = 9;
const short int TASK_EXIT                 = 10;

/* Custom "islower" Function */
bool isLower(char ch) {
   return ch >= 'a' && ch <= 'z';
}

/* Custom "isupper" Function */
bool isUpper(char ch) {
   return ch >= 'A' && ch <= 'Z';     
}

/* Custom "isalpha" Function */
bool isAlpha(char ch) {
   return isLower(ch) || isUpper(ch);
}

/* Custom "isdigit" function */
bool isDigit(char ch) {
   return ch >= '0' && ch <= '9';     
}

/* Custom "tolower" Function */
char toLower(char ch) {
   if (isUpper(ch))
      return ch + ('a' - 'A');
      
   return ch;    
}

/* Custom "toupper" Function */
char toUpper(char ch) {
   if (isLower(ch))
      return ch - ('a' - 'A');
   
   return ch;   
}

string toLower(string str)
/* returns a string with all letters of input stirng converted to lower case*/
{
   for (int i = 0; i < str.length(); i++)
      str[i] = toLower(str[i]);
   
   return str;
}

string toUpper(string str)
/* returns a string with all letters of input stirng converted to upper case*/
{
   for (int i = 0; i < str.length(); i++)
      str[i] = toUpper(str[i]);
   
   return str;
}

string toTitle(string str)          
/*returns a string with changed to title case where each word begins with an uppercase 
and other letters of each word are in lowercase.*/
{
   bool next_is_first_char = true;
   for (int i = 0; i < str.length(); i++) {
      if (str[i] == ' ') { // ignore spaces
         next_is_first_char = true; // wait for the next character
         continue;
      }
      
      if (next_is_first_char) {
         str[i] = toUpper(str[i]);
         next_is_first_char = false;
      }
      else
         str[i] = toLower(str[i]);
   }
   
   return str;
}

string flipCase(string str)
/* returns a string with each letter's case flipped */
{
   for (int i = 0; i < str.length(); i++) {
      if (isUpper(str[i]))
         str[i] = toLower(str[i]);
      else
         str[i] = toUpper(str[i]);    
   }
   
   return str;
}

int countAlphabets(string str)
//counts the number of alphabets
{
   int result = 0;
   
   for (int i = 0; i < str.length(); i++) {
      if (isAlpha(str[i])) result++;    
   }
   
   return result;
}

int countVowels(string str)
//counts the number of vowels
{
   int result = 0;
   
   for (int i = 0; i < str.length(); i++) {
      if (VOWELS.find(str[i]) != string::npos)
         result++;    
   }
   
   return result;
}

int countConsonants(string str)
//counts the number of consonants as number of alphabets - number of vowels
{
   int result = 0;
   
   for (int i = 0; i < str.length(); i++) {
      // alphanumeric and is not a vowel?
      if (isAlpha(str[i]) && VOWELS.find(str[i]) == string::npos)
         result++;    
   }
   
   return result;
}

bool isValidLiteral(string str)
//check if it's a valid c++ literal name (can begin with '_' or 'a-z, A-Z' 
//and can contain '_', 'a-z', 'A-Z', 0-9'
{
   bool result = true;
   
   // check first character
   if (!(str[0] == '_' || isAlpha(str[0]))) return false;
   
   // check other characters
   for (int i = 1; i < str.length(); i++) {
      if (!(str[i] == '_' || isAlpha(str[i]) || isDigit(str[i])))
         return false;
   }
   
   return result;
}

void showTokens(string str)
//separate all tokens by spaces
{
   if (str == "") return;
   
   string token = "";
   int token_id = 1;
   
   for (int i = 0; i <= str.length(); i++) {
      // token end: is space or last character?
      if (str[i] == ' ' || i == str.length()) {
         if (token.length()) {
            cout << "Token " << token_id << ": " << token << endl;
            token_id++;
            token = "";
         }
         continue;
      }
      
      // update token
      token += str[i];
   }
}

int main()
{
    string input;
    int choice;
    do {
        //menu display - 
        cout<<"1. Convert to upper case"<<endl;
        cout<<"2. Convert to lower case"<<endl;
        cout<<"3. Convert to Title case"<<endl;
        cout<<"4. Flip cases"<<endl;
        cout<<"5. Count number of alphabets"<<endl;
        cout<<"6. Count number of consonants"<<endl;
        cout<<"7. Count number of vowels"<<endl;
        cout<<"8. Check if input is a valid literal"<<endl;
        cout<<"9. Show tokens"<<endl;
        cout<<"10.Exit"<<endl;
        cout<<setw(50)<<setfill('-')<<""<<endl;
        
        do { // get choice
           cout << "Enter choice: ";
           cin >> choice;
        } while (choice < 1 || choice > 10);
        
        if (choice != TASK_EXIT) {
           cin.ignore();
           // get input
           cout << "Enter text: ";
           getline(cin, input);
           cout << endl;
           
           switch (choice) {
              case TASK_CONVERT_UPPER_CASE:
                 cout << toUpper(input) << endl;
                 break;
              
              case TASK_CONVERT_LOWER_CASE:
                 cout << toLower(input) << endl;
                 break;
                 
              case TASK_CONVERT_TITLE_CASE:
                 cout << toTitle(input) << endl;
                 break;
                 
              case TASK_FLIP_CASE:
                 cout << flipCase(input) << endl;
                 break;
                 
              case TASK_NUMBER_OF_ALPHABETS:
                 cout << countAlphabets(input) << " alphabets" << endl;
                 break;
                 
              case TASK_NUMBER_OF_CONSONANTS:
                 cout << countConsonants(input) << " consonants" << endl;
                 break;
                 
              case TASK_NUMBER_OF_VOWELS:
                 cout << countVowels(input) << " vowels" << endl;
                 break;
                 
              case TASK_CHECK_VALID_LITERAL:
                 cout << input << " is ";
                 if (!isValidLiteral(input)) cout << " not ";
                 cout << "a valid literal" << endl;
                 break;
                 
              case TASK_SHOW_TOKENS:
                 showTokens(input);
                 break;
           }
           cout << endl << endl; // to have the same output with the example
        }
    } while(choice != 10); // 10.Exit
}
