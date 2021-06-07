#include "earley_state.h"
#include "lectura_grammar.h"
int main(){
    char word[50];
    char *ptr = word;
    vector<Production*> todos;

    while(cin.getline(word,50,'\n')){
        lectura(ptr, todos);
    }

    /*for(int i=0; i<todos.size(); i++){
        for(int j=0; j<todos[i]->getCantProductions(); j++){
            for(int k=0; k<todos[i][j].getProductions().size(); k++){
                vector<Production> total = todos[i][j].getProductions();
                cout<<total[k]<<"  ";
            }
            cout<<endl;
        }
    }*/


    return 0;
}