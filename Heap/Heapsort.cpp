
/* @Author
 * Student Name: ibrahim karateke
 * Student ID : 150210705
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

//Defining the data type
typedef std::pair<std::string, int> CityPair;

//Swap function
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//split function for splitting attributes according to delimiter (;) in .csv files
std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

//Output function to write the outputs into new .csv file
void output(std::vector<CityPair>& data, std::string outputFileName){
    //removes same named previous output
    remove(outputFileName.c_str());
    std::ofstream myfile;
    myfile.open(outputFileName, std::ios_base::app);
    for (int i = 0; i < data.size(); ++i) {
        //writing first part of the pair (city name), and second part of the pair (population) in desired format
        myfile << data[i].first << ";" << data[i].second;
        // avoiding extra line in last instance
        if (i != data.size() - 1) {
            myfile << "\n";
        }
    }
    myfile.close();
}

void csvToVector(std::string filename,std::vector<CityPair> &data){
    std::ifstream file(filename); // CSV file name

    //checking whether the file can be opened or not.
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    //BOM Handling
    char bom[3] = {0};
    file.read(bom, 3);
    if (bom[0] == '\xEF' && bom[1] == '\xBB' && bom[2] == '\xBF') {
        // BOM detected, adjust file reading
        file.seekg(3);
    } else {
        // No BOM detected, reset file position to start
        file.seekg(0);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row = split(line, ';'); // CSV data is semicolon-separated
        if (row.size() == 2) {
            //reading city name part of the line
            std::string city = row[0];
            //reading population part of the line 
            int population = std::stoi(row[1]);
            //combining those two and pushing them our main vector with correct types
            CityPair cityData = std::make_pair(city, population);
            data.push_back(cityData);
        }
    }

    file.close();
}
//max_heapify
// Function to heapify a subtree rooted at index 'i' in a vector 'data' of size 'n'
void max_heapify(std::vector<CityPair>& data, int n, int i, int d) {
    int largest = i;
    int firstChild = d * i + 1;
    //checking all childs of the current node
    for (int j = 0; j < d; ++j) {
        int child = firstChild + j;
        if (child < n && data[child].second > data[largest].second)
            largest = child;
    }
    // if largest node is not the root continue to calling max_heapify with recursion
    if (largest != i) {
        //swapping or moving larger values to the upwards
        swap(data[i], data[largest]);
        max_heapify(data, n, largest, d);
    }
}

// Function to build a max heap from a given vector 'data' of size 'n'
void build_max_heap(std::vector<CityPair>& data, int d) {
    int n = data.size();
    int lastNonLeaf;
    //calculating the last non leaf node
    if (n % d==0){
        lastNonLeaf=n/d -1;
    }
    else{
        lastNonLeaf=n/d;
    }

    //starting from last non-leaf node traversing them until reaching the root by max-heapifying all visited nodes.
    for (int i = lastNonLeaf; i >= 0; i--)
        max_heapify(data, n, i, d);
}

// Function to perform heap sort on a vector 'data' of size 'n'
void heapsort(std::vector<CityPair>& data, int d) {
    int n = data.size();
    //building max heap in case of data is not given as a heap
    build_max_heap(data, d);


    for (int i = n - 1; i > 0; i--) {
        //sending largest element to the end of the heap
        swap(data[0], data[i]);
        //by decrementing, without values are sent to the end, determining the new maximum
        max_heapify(data, i, 0, d);
        //when this loop is done 'data' will be sorted in ascending order
    }
}

//Function to perform heap increase key on a vector 'data' with selected index 'i' and entered key value 'k'
void heap_increase_key(std::vector<CityPair>& data, int i, int key) {
    build_max_heap(data,2); // default binary heap
    //checking if the new key is larger than the current key or not
    if (key < data[i].second) {
        std::cout << "New population is smaller than the current population. NO INCREASE KEY OPERATION IS PERFORMED." << std::endl;
        return;
    }

    data[i].second = key;

    // Fix the max heap property if necessary
    while (i > 0 && data[(i - 1) / 2].second < data[i].second) {
        swap(data[i], data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

//Function to perform max heap insert on a vector 'data' with new pair
void max_heap_insert(std::vector<CityPair>& data,std::pair<std::string, int> &CityPair) {
    build_max_heap(data,2);  // default binary heap
    //sending the new pair to the end of the heap
    data.push_back(CityPair);
    int index=data.size()-1;
    
    // Fix the max heap property if necessary
    while (index > 0 && data[(index - 1) / 2].second < data[index].second) {
        swap(data[index], data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

std::pair <std::string,int> heap_maximum(std::vector<CityPair>& data){
    build_max_heap(data,2); // default binary heap
    return data[0]; // since root is the maximum it is returned.
}

std::pair <std::string,int> heap_extract_max(std::vector<CityPair>& data){
    build_max_heap(data,2); // default binary heap
    std::pair <std::string,int> ret=data[0]; //assigning the pair that is going to be returned
    swap(data[0], data[data.size() - 1]); // Swap root with last element
    data.pop_back(); //removing maximum element
    max_heapify(data, data.size(),0,2); // maintaining heap structure
    return ret;
}

int dary_calculate_height (int n, int d) {
    int height = 0;
    int nodes_at_current_level = 1;

    // Calculate height by traversing through the levels
    while (n > 0) {
        n =n- nodes_at_current_level;
        nodes_at_current_level = nodes_at_current_level * d;
        height++;
    }

    return height - 1; // Since we count only edges, not nodes.
}
//Function to perform d-ary increase key on a vector 'data' with selected index 'i', entered key value 'k' and degree of the heap 'd'
void dary_increase_key(std::vector<CityPair>& data, int i, int key, int d) {
    build_max_heap(data,d); //building d-ary heap
    //checking if the new key is larger than the current key or not
    if (key < data[i].second) {
        std::cout << "New population is smaller than the current population. NO INCREASE KEY OPERATION IS PERFORMED." << std::endl;
        return;
    }

    data[i].second = key;

    // Fix the max heap property if necessary
    while (i > 0 && data[(i - 1) / d].second < data[i].second) {
        swap(data[i], data[(i - 1) / d]);
        i = (i - 1) / d;
    }
}
//Function to perform d-ary insert element on a vector 'data' with new pair degree of the heap 'd'
void dary_insert_element(std::vector<CityPair>& data,std::pair<std::string, int> &CityPair, int d) {
    build_max_heap(data,d); //building d-ary heap
    //sending the new pair to the end of the heap
    data.push_back(CityPair);
    int index=data.size()-1;

    // Fix the max heap property if necessary
    while (index > 0 && data[(index - 1) / d].second < data[index].second) {
        swap(data[index], data[(index - 1) / d]);
        index = (index - 1) / d;
    }

}


std::pair <std::string,int> dary_extract_max(std::vector<CityPair>& data,int d){
    build_max_heap(data,d); // building d-ary heap
    std::pair <std::string,int> ret=data[0]; //assigning the pair that is going to be returned
    swap(data[0], data[data.size() - 1]); // Swap root with last element
    data.pop_back();//removing maximum element
    max_heapify(data, data.size(),0,d); // maintaining heap structure
    return ret;
}


int main(int argc, char* argv[]) {
    //assigning fixed arguments into corresponding variables
    std::string fileName= argv[1];
    std::string functionName=argv[2];
    std::string outFileName=argv[3];
    int d=2; // in case of d-ary function selected and 'd' is not entered (default 2)
    int i,k; // variables for any insert or increase operation
    int insertArgument; // keeping index of 'k' among other arguments 
    std::vector<CityPair> data; // Vector of pairs to store CSV data
    csvToVector(fileName,data);
    //determining which argument is entered and assigning them to the correct variables via type changing
    for(int j=4; j<argc;j++){
        std::string currentArgument=argv[j];
        if(currentArgument[0]=='d'){
            d=stoi(currentArgument.substr(1));
        }
        if(currentArgument[0]=='i'){
            i=stoi(currentArgument.substr(1))-1; // Since indexing in vectors starts from 0. i.e if 1 is entered it corresponds to root, which is 0.
        }
        //storing 'k' value in case of increase operations
        if(currentArgument[0]=='k' && functionName!="max_heap_insert" && functionName!="dary_insert_element"){
            k=stoi(currentArgument.substr(1));
        }
        //storing index of argument 'k'  in case of insert operations 
        if(currentArgument[0]=='k' && (functionName=="max_heap_insert" || functionName=="dary_insert_element")){
            insertArgument=j;
        }
    }

    if(functionName=="build_max_heap"){
        build_max_heap(data,d);
        output(data,outFileName);
    }
    // **** time measurements are commented **** 
    else if (functionName=="heapsort"){
        //const auto start{std::chrono::steady_clock::now()};
        heapsort(data,d);
        //const auto end{std::chrono::steady_clock::now()};
        //const std::chrono::duration<long long,std::nano> elapsed_seconds{end - start};
        //std::cout<<"Time taken by Heapsort via constructing "<<d<<"-ary heap: "<<elapsed_seconds.count()<<" ns."<<std::endl;
        output(data,outFileName);
    }
    else if(functionName=="max_heap_insert"){
        // if the function is a kind of an "insert" assigning this to a variable 
        //to be splitted into correct variables with respect to underscores 
        std::string currentArgument=argv[insertArgument];        
        currentArgument=currentArgument.substr(1);
            // Find the position of the underscores
        int underscore1 = currentArgument.find('_');
        int underscore2 = currentArgument.find('_', underscore1 + 1);

        // Extract the city name and the number using substr
        std::string city = currentArgument.substr(underscore1 + 1, underscore2 - underscore1 - 1);
        int population=stoi(currentArgument.substr(underscore2 + 1));

        // making pair of those variables to be able to insert them
        CityPair insertedPair = std::make_pair(city, population);   
        max_heap_insert(data,insertedPair);
        output(data,outFileName);
    }
    else if(functionName=="heap_increase_key"){
        heap_increase_key(data,i,k);
        output(data,outFileName);
    }
    else if (functionName=="heap_extract_max"){
        CityPair maximumValue=heap_extract_max(data);
        std::vector<CityPair> onlyMaximumVector;
        onlyMaximumVector.push_back(maximumValue);
        output(onlyMaximumVector,outFileName);
    }
    else if (functionName=="heap_maximum"){
        CityPair maximumValue=heap_maximum(data);
        std::vector<CityPair> onlyMaximumVector;
        onlyMaximumVector.push_back(maximumValue);
        output(onlyMaximumVector,outFileName);
    }
    else if(functionName=="dary_calculate_height"){
        remove(outFileName.c_str());
        std::ofstream myfile;
        myfile.open(outFileName, std::ios_base::app);
        int height =dary_calculate_height(data.size(),d);
        myfile<<"There are "<<data.size()<<" elements in this "<<d<<"-ary heap. Its height is "<<height<<".";
        myfile.close();
        std::cout<<"There are "<<data.size()<<" elements in this "<<d<<"-ary heap. Its height is "<<height<<"."<<std::endl;
    }
    else if(functionName=="dary_extract_max"){
        CityPair maximumValue=dary_extract_max(data,d);
        std::vector<CityPair> onlyMaximumVector;
        onlyMaximumVector.push_back(maximumValue);
        output(onlyMaximumVector,outFileName);
    }
    else if(functionName=="dary_insert_element"){
        // if the function is a kind of an "insert" assigning this to a variable 
        //to be splitted into correct variables with respect to underscores 
        std::string currentArgument=argv[insertArgument];        
        currentArgument=currentArgument.substr(1);
            // Find the position of the underscores
        int underscore1 = currentArgument.find('_');
        int underscore2 = currentArgument.find('_', underscore1 + 1);

        // Extract the city name and the number using substr
        std::string city = currentArgument.substr(underscore1 + 1, underscore2 - underscore1 - 1);
        int population=stoi(currentArgument.substr(underscore2 + 1));
        CityPair insertedPair = std::make_pair(city, population);   
        dary_insert_element(data,insertedPair,d);
        output(data,outFileName);
    }
    else if(functionName=="dary_increase_key"){
        dary_increase_key(data,i,k,d);
        output(data,outFileName);
    }

    return 0;
} 