#include<bits/stdc++.h>

using namespace std;

void uva146(){  
    ifstream file_read;
    string letter;
    file_read.open("uva146.txt",ios::in);
    if(file_read.is_open()){
        string line;
        istringstream i;
        
        while(getline(file_read,line,'\n')){
            i >> letter;
        }   
        file_read.close();  
    }
    while((cin>>letter) && (letter!="#"))
    {
        if(next_permutation(letter.begin(),letter.end())){
            cout<<letter<<endl;
        }else{
            cout<<"No Successor"<<endl;
        }
    }
    cout<<endl;
}

int uva299(vector<int>vec){
    int p = 0;
    for(auto i = vec.begin(); i != vec.end(); ++i ){
        for (auto j = vec.begin() ; j != i ;++j){
            if( *i < *j ){
                auto aux = *i;
                *i = *j;
                *j = aux;
                p++;
            }
        }
    }
    return p;    
}

template <typename value_type>
void uva482(){
    vector<unsigned>array_position;
    vector<value_type>array_data;
    ifstream file_read_uva482;
    string size;
    string vector_position;
    string vector_data;
    int number_pos;
    float number_data;

    file_read_uva482.open("uva482.txt");
    if(!file_read_uva482.is_open()){
        cout<<"El archivo no esta abierto"<<endl;
    }
    else{
        getline(file_read_uva482,size);
        getline(file_read_uva482,vector_position);
        istringstream i_(vector_position);
        while(i_ >> number_pos){
            array_position.push_back(number_pos);
        }
        getline(file_read_uva482,vector_data);
        istringstream i__(vector_data);
        while(i__ >> number_data){
            array_data.push_back(number_data);
        }
    }

    // for(const auto&item_position:array_position)cout<<item_position<<" ";
    // cout<<endl;
    // for(const auto&item_data:array_data)cout<<item_data<<" ";
    // cout<<endl;
    vector<value_type>array_result(array_position.size());
    for(size_t i = 0; i < array_position.size(); ++i ){
        array_result[array_position[i] - 1] = array_data[i];
    }
    cout<<endl;
    for(int i = 0 ; i <array_result.size();++i){
        cout<< array_result[i]<<endl;
    }
}


void uva11340(){
    ifstream file_read;
    string line_char;
    char pal;
    size_t size_char,size_text,count_char = 0,count_text=0;
    unordered_map<char,float> table;
    vector<char>palabras;
    float price_total;
    int test,price;
    char car;
    const float cents = 100.0;
    file_read.open("uva11340.txt");
    if(!file_read.is_open()){
        cout<<"El archivo no se pudo abrir"<<endl;
    }else{
        file_read >> test;
        file_read >> size_char;
        file_read.get();
        while(count_char < size_char){
            getline(file_read,line_char);
            istringstream i__(line_char);
            i__ >> car >> price;
            table[car] = price / cents;
            ++count_char;
        }
        file_read >> size_text;
        while(count_text < size_text){
            while(file_read >> pal){
                palabras.push_back(pal);
            }
            ++count_text;
        }
    }

    for(int i = 0; i < palabras.size(); ++i){
        for(auto &item:table){
            if(palabras[i] == item.first){
                price_total += item.second;
            }
        }
    }
    cout<<"\n"<<price_total<<"$"<<endl;
}

//Cual es el siguiente una vez que este ordenado
int main(){
    
    uva146();
    vector<int>uv1{1,3,2};
    vector<int>uv2{4,3,2,1};
    vector<int>uv3{2,1};
    int in1 = uva299(uv1);
    int in2 = uva299(uv2);
    int in3 = uva299(uv3);
    cout<<in1<<endl;
    cout<<in2<<endl;
    cout<<in3<<endl;

    uva482<float>();
    uva11340();

    return 0;
}