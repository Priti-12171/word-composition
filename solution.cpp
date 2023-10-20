#include<iostream>
#include <vector>
using namespace std;
struct Node {
    bool is_end = false;
    Node* next[26] = { NULL };
};

Node* root;

void add_word_to_trie(string s, Node* root){
    Node* current_node = root;
    for(int i = 0; i<s.length(); i++){
        if(current_node->next[s[i]-'a']== NULL){
            current_node->next[s[i]-'a'] = new Node();
        }
        
        current_node = current_node->next[s[i]-'a'];

    }
    current_node->is_end = true;
}

bool dfs(int i, int cnt, int n, string s){
        if(i == n) {
        	bool temp = cnt>1;
        	//cout<<s<<"Finla "<<temp<<endl;
        	return cnt > 1;
        	
        }
        Node* cur = root;
        
        while(i<n && cur->next[s[i]-'a'] != NULL) {
            cur = cur->next[s[i] - 'a'];
            i++;
            if(cur->is_end) {
                if(dfs(i, cnt+1, n, s)) return true;
            }
        }
        return false;
    }

int main(){
  clock_t start, end;
 
    start = clock();

    // taking input from file and attaching to stdin
    freopen("input1.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    root = new Node();
    string s;
    vector<string> input_strings; 

    while(cin>>s){
        input_strings.push_back(s);
        //cout<<s<<endl;
        // adding all the words to trie data structure which is of node type containing two attribute is_end and array of 26 alphabet pointers
        add_word_to_trie(s, root);
    }

    
    string max_string, second_max;
    int max_length_string = 0, second_max_string = 0;

    for(int i = 0; i < input_strings.size(); i++){
    	//cout<<input_strings[i]<<endl;
        // DFS to check if the string is compunded or not
       if(dfs(0, 0, input_strings[i].length(), input_strings[i])){
              
                if(input_strings[i].length() > max_length_string){
                    second_max_string = max_length_string;
                    second_max = max_string;
                    max_length_string = input_strings[i].length();
                    max_string = input_strings[i];
                }else{
                    if(input_strings[i].length() > second_max_string){
                        second_max_string = input_strings[i].length();
                        second_max = input_strings[i];
                    }
                }
       }

      
                
    }


     cout<<"Longest Compound Word "<<max_string<<endl;
     cout<<"Second Longest Compound Word "<<second_max<<endl;
    end = clock();
    double time_taken = double(end - start)/1000;
    cout << "Time taken to process file Input_02.txt " << time_taken << " milli seconds";

}
