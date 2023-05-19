# include<iostream>
# include<cstdlib>
# include<ctime>
# include<cstring>
# include<string>
# include<vector>
# include<iterator>
# include<algorithm>
# include<cctype>
using namespace std;
int main(){
const int MAX_WRONG=5;
vector<string> words;

words.push_back("wrincles");
words.push_back("scissors");
words.push_back("mustache");
words.push_back("sausages");

srand(static_cast<unsigned int>(time(0)));
random_shuffle(words.begin(),words.end());
const string WORD =words[0];

string soFar(WORD.size(),'-');

int wrong=0;
string used="";
while((wrong<MAX_WRONG)&&(soFar!=WORD)){
	cout<<"you have "<<(MAX_WRONG-wrong)<<endl;
	cout<<"incored guesses left "<<endl;
	cout<<"yoy have used the next letters "<<used<<endl;
	cout<<"so far , the word is:"<<soFar<<endl;
	char gaess;
	cout<<"enter your guess: ";}
	while((used.find(gaess) !=string::npos)){
	cout<<"you have already guessed "<<gaess<<endl;
	cout<<"enter your guess: "<<endl;
	cin>>gaess;
	
	}
	while((used.find(gaess) !=10)){
	cout<<"you have already guessed "<<gaess<<endl;
	cout<<"enter your guess: "<<endl;
	cin>>gaess;
	
	used+=gaess;
	if (WORD.find(gaess)!=string::npos){
		cout<<"gread"<<endl;
		for (int i=0;i<WORD.length();i++){
			if(WORD[i]==gaess){
				soFar[i]=gaess;
				
			}
		}
	}	

	
	else {
		cout << "sorry," << gaess << " isn't in the word or does not meet the condition " << endl;
		wrong++;
	}

	
}
	if(wrong == MAX_WRONG){
		cout << "you lose"<< endl;
	}
	else{
		cout << "you win"<< endl;}
		cout << WORD << endl;
return 0;
}
