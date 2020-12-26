#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
using namespace std;


void vul_in_i_de_map_stack_bij_sleutel_aan_met_set_van_drie_strings(vector<map<string, stack<set<string>>>> & , int, string, string , string, string);
bool i_de_map_beeldt_woord_af_op_stack_waarvan_bovenste_set_dit_element_bevat(vector<map<string, stack<set<string>>>> & ,int, string, string);

int main(){
    vector<map<string, stack<set<string>>>> v(5);
    vul_in_i_de_map_stack_bij_sleutel_aan_met_set_van_drie_strings(v, 1, "noot", "do", "re", "mi");

    cout << i_de_map_beeldt_woord_af_op_stack_waarvan_bovenste_set_dit_element_bevat(v, 1, "noot", "re"); // (should be true)
    cout << i_de_map_beeldt_woord_af_op_stack_waarvan_bovenste_set_dit_element_bevat(v, 1, "noot", "miet"); // should be false
}

void vul_in_i_de_map_stack_bij_sleutel_aan_met_set_van_drie_strings(vector<map<string, stack<set<string>>>> &v, int i, string sleutel, string str1, string str2, string str3){

    // FOUT (zie uitleg md)
    set<string> s;
    s.insert(str1);
    s.insert(str2);
    s.insert(str3);
    stack<set<string>> st;
    st.push(s);
    v[i].insert(pair<string, stack<set<string>>>(sleutel, st));

    // correct
    v[i][sleutel].push({str1,str2,str3});
}


bool i_de_map_beeldt_woord_af_op_stack_waarvan_bovenste_set_dit_element_bevat(vector<map<string,stack<set<string>>>> &v ,int i , string woord, string element){
    if(v[i].count(woord) == 1){ // er is een stack die als key het meegegeven woord heeft.
        set<string> s = v[i][woord].top(); // enkel bovenste van de stack.

        set<string>::const_iterator it = s.begin();

        while(it != s.end()){
            if(*it == element){
                return true;
            }
            it++;
        }
    }
    return false;
}

