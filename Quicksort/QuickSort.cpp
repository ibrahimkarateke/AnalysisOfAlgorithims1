
/* @Author
 * Student Name: ibrahim karateke
 * Student ID : 150210705
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>

/***
 *      _____               _____    _______            __       __      _   _              _____  __      __  ______      ____    _    _   _____    _____   _  __   _____    ____    _____    _______ 
 *     |  __ \      /\     |  __ \  |__   __|          /_ |     /_ |    | \ | |     /\     |_   _| \ \    / / |  ____|    / __ \  | |  | | |_   _|  / ____| | |/ /  / ____|  / __ \  |  __ \  |__   __|
 *     | |__) |    /  \    | |__) |    | |     ______   | |      | |    |  \| |    /  \      | |    \ \  / /  | |__      | |  | | | |  | |   | |   | |      | ' /  | (___   | |  | | | |__) |    | |   
 *     |  ___/    / /\ \   |  _  /     | |    |______|  | |      | |    | . ` |   / /\ \     | |     \ \/ /   |  __|     | |  | | | |  | |   | |   | |      |  <    \___ \  | |  | | |  _  /     | |   
 *     | |       / ____ \  | | \ \     | |              | |  _   | |    | |\  |  / ____ \   _| |_     \  /    | |____    | |__| | | |__| |  _| |_  | |____  | . \   ____) | | |__| | | | \ \     | |   
 *     |_|      /_/    \_\ |_|  \_\    |_|              |_| (_)  |_|    |_| \_| /_/    \_\ |_____|     \/     |______|    \___\_\  \____/  |_____|  \_____| |_|\_\ |_____/   \____/  |_|  \_\    |_|   
 *                                                                                                                                                                                                     
 *                                                                                                                                                                                                     
 */

/*
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int part1_Partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void part1_QuickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = part1_Partition(arr, low, high);

        part1_QuickSort(arr, low, pivotIndex - 1);
        part1_QuickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(const std::vector<int>& arr) {
    std::cout<<"[ ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout<<"]";
    std::cout << std::endl;
}

int main() {
std::cout<<"Initial Array: "<<std::endl;
std::vector<int> arr = {5,2,1,9,3,10,6,8,7,0,4};
printArray(arr);
std::cout<<"Sorted Array: "<<std::endl;

const auto start{std::chrono::steady_clock::now()};
part1_QuickSort(arr,0,arr.size()-1);
const auto end{std::chrono::steady_clock::now()};

printArray(arr);

const std::chrono::duration<double> elapsed_seconds{end - start};
std::cout << elapsed_seconds.count()*1000000000 << " ns"<< std::endl;
return 0;
}
*/

/***
 *      _____               _____    _______            __       ___        ____    _    _   _____    _____   _  __   _____    ____    _____    _______     
 *     |  __ \      /\     |  __ \  |__   __|          /_ |     |__ \      / __ \  | |  | | |_   _|  / ____| | |/ /  / ____|  / __ \  |  __ \  |__   __|    
 *     | |__) |    /  \    | |__) |    | |     ______   | |        ) |    | |  | | | |  | |   | |   | |      | ' /  | (___   | |  | | | |__) |    | |       
 *     |  ___/    / /\ \   |  _  /     | |    |______|  | |       / /     | |  | | | |  | |   | |   | |      |  <    \___ \  | |  | | |  _  /     | |       
 *     | |       / ____ \  | | \ \     | |              | |  _   / /_     | |__| | | |__| |  _| |_  | |____  | . \   ____) | | |__| | | | \ \     | |       
 *     |_|      /_/__  \_\_|_| _\_\___ |_|    _      ___|_| (_)_|____|_____\___\_\__\____/__|_____|__\_____|_|_|\_\_|_____/___\____/  |_|  \_\    |_|       
 *     \ \        / / |_   _| |__   __| | |  | |    |  __ \  |_   _| |  ____| |  ____| |  ____| |  __ \  |  ____| | \ | | |__   __|                         
 *      \ \  /\  / /    | |      | |    | |__| |    | |  | |   | |   | |__    | |__    | |__    | |__) | | |__    |  \| |    | |                            
 *       \ \/  \/ /     | |      | |    |  __  |    | |  | |   | |   |  __|   |  __|   |  __|   |  _  /  |  __|   | . ` |    | |                            
 *        \  /\  /     _| |_     | |    | |  | |    | |__| |  _| |_  | |      | |      | |____  | | \ \  | |____  | |\  |    | |                            
 *       __\/_ \/_____|_____|___ |_|    |_|  |_|____|_____/__|_____|_|_|   ___|_|  ____|______|_|_|  \_\ |______| |_| \_|    |_|                            
 *      / ____| |__   __| |  __ \      /\     |__   __| |  ____|  / ____| |_   _| |  ____|  / ____|                                                         
 *     | (___      | |    | |__) |    /  \       | |    | |__    | |  __    | |   | |__    | (___                                                           
 *      \___ \     | |    |  _  /    / /\ \      | |    |  __|   | | |_ |   | |   |  __|    \___ \                                                          
 *      ____) |    | |    | | \ \   / ____ \     | |    | |____  | |__| |  _| |_  | |____   ____) |                                                         
 *     |_____/     |_|    |_|  \_\ /_/    \_\    |_|    |______|  \_____| |_____| |______| |_____/                                                          
 *                                                                                                                                                          
 *                                                                                                                                                          
 */

/*
typedef std::pair<std::string, long long> CityPair;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void output(std::vector<CityPair>& data, std::string outputFileName){
    remove(outputFileName.c_str());
    std::ofstream myfile;
    myfile.open(outputFileName, std::ios_base::app);
    for (const auto &city : data) {
    myfile<<city.first <<";"<<  city.second<<std::endl;
    }
    myfile<<std::endl;
    myfile.close();
}

int part2_Partition(std::vector<CityPair> &data, int low, int high, char selection) {
long long pivot;
    if (selection=='l')
    {
        pivot = data[high].second;
    }

    else if(selection=='r')
    {
        int randomNumber = std::rand() % (high - low + 1) + low;
        int pivotIndex= randomNumber;
        swap(data[pivotIndex], data[high]);
        pivot = data[high].second; 
    }
    else if (selection=='m')
    {
        if (high - low + 1 < 3) {
            // If subarray size is less than 3, select the middle or the only element as pivot
            int pivotIndex = (low + high) / 2;
            swap(data[pivotIndex], data[high]);
            pivot = data[high].second;
        } 
        else {
            // Randomly select three indices within the subarray
            int pivotIndex1 = std::rand() % (high - low + 1) + low;
            int pivotIndex2 = std::rand() % (high - low + 1) + low;
            int pivotIndex3 = std::rand() % (high - low + 1) + low;

            // Retrieve corresponding values
            long long pivot1 = data[pivotIndex1].second;
            long long pivot2 = data[pivotIndex2].second;
            long long pivot3 = data[pivotIndex3].second;

            // Find the median among the three random elements
            if ((pivot1 <= pivot2 && pivot2 <= pivot3) || (pivot3 <= pivot2 && pivot2 <= pivot1)) {
                pivot = pivot2;
                swap(data[pivotIndex2], data[high]);
            } else if ((pivot2 <= pivot1 && pivot1 <= pivot3) || (pivot3 <= pivot1 && pivot1 <= pivot2)) {
                pivot = pivot1;
                swap(data[pivotIndex1], data[high]);
            } else {
                pivot = pivot3;
                swap(data[pivotIndex3], data[high]);
            }
        }

    }

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) 
    {
        if (data[j].second < pivot) {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[high]);
    return (i + 1);
}

void part2_QuickSort(std::vector<CityPair> &data, int low, int high,char selection) {
    if (low < high) {
        int pivotIndex = part2_Partition(data, low, high,selection);

        part2_QuickSort(data, low, pivotIndex - 1,selection);
        part2_QuickSort(data, pivotIndex + 1, high,selection);
    }
}


void csvToVector(std::string filename,std::vector<CityPair> &data){
    std::ifstream file(filename); // CSV file name

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row = split(line, ';'); // CSV data is semicolon-separated
        if (row.size() == 2) {
            std::string city = row[0];
            long long population = std::stoll(row[1]);
            CityPair cityData = std::make_pair(city, population);
            data.push_back(cityData);
        }
    }

    file.close();
}

int main() {
 
    std::vector<CityPair> data; // Vector of pairs to store CSV data
    csvToVector("dummyData.csv",data);
    
    const auto start{std::chrono::steady_clock::now()};
    part2_QuickSort(data, 0, data.size() - 1, 'l');
    const auto end{std::chrono::steady_clock::now()};
    const std::chrono::duration<long long, std::nano> elapsed_seconds{end - start};
    std::cout << "Time Taken: "<<elapsed_seconds.count() << " ns"<< std::endl;  

    output(data, "out.csv");
    
return 0;
}
*/

/***
 *      _____               _____    _______            __       ____       _    _  __     __  ____    _____    _____   _____        ____    _    _   _____    _____   _  __   _____    ____    _____    _______ 
 *     |  __ \      /\     |  __ \  |__   __|          /_ |     |___ \     | |  | | \ \   / / |  _ \  |  __ \  |_   _| |  __ \      / __ \  | |  | | |_   _|  / ____| | |/ /  / ____|  / __ \  |  __ \  |__   __|
 *     | |__) |    /  \    | |__) |    | |     ______   | |       __) |    | |__| |  \ \_/ /  | |_) | | |__) |   | |   | |  | |    | |  | | | |  | |   | |   | |      | ' /  | (___   | |  | | | |__) |    | |   
 *     |  ___/    / /\ \   |  _  /     | |    |______|  | |      |__ <     |  __  |   \   /   |  _ <  |  _  /    | |   | |  | |    | |  | | | |  | |   | |   | |      |  <    \___ \  | |  | | |  _  /     | |   
 *     | |       / ____ \  | | \ \     | |              | |  _   ___) |    | |  | |    | |    | |_) | | | \ \   _| |_  | |__| |    | |__| | | |__| |  _| |_  | |____  | . \   ____) | | |__| | | | \ \     | |   
 *     |_|      /_/    \_\ |_|  \_\    |_|              |_| (_) |____/     |_|  |_|    |_|    |____/  |_|  \_\ |_____| |_____/      \___\_\  \____/  |_____|  \_____| |_|\_\ |_____/   \____/  |_|  \_\    |_|   
 *                                                                                                                                                                                                               
 *                                                                                                                                                                                                               
 */

// Datatype to keep city names and populations in vector of pairs
typedef std::pair<std::string, long long> CityPair;

// Swap function to change value of two instances
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Split function helps us to seperate the population and city names, which are in csv file, using delimeter 
std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

//After calling quicksort this function will be invoked.
// 1. Determines what elemenet will be the pivot.
// 2. Divides the whole collection into (elemets that are greater than pivot and elements that are less than the pivot) 
// 3. Returns the index of the pivot
int partition(std::vector<CityPair> &data, int low, int high, char firstArgument) {
    long long pivot;
    //naive quicksort or last element pivoting
    if (firstArgument=='l')
    {
        pivot = data[high].second;
    }
    //selecting a randomized element as a pivot
    else if(firstArgument=='r')
    {
        int randomNumber = std::rand() % (high - low + 1) + low;
        int pivotIndex= randomNumber;
        swap(data[pivotIndex], data[high]);
        pivot = data[high].second; 
    }
    //selecting median of three random elements as a pivot
    else if (firstArgument=='m')
    {
        if (high - low + 1 < 3) {
            // If subarray size is less than 3, select the middle or the only element as pivot
            int pivotIndex = (low + high) / 2;
            swap(data[pivotIndex], data[high]);
            pivot = data[high].second;
        } 
        else {
            // Randomly select three indices within the subarray
            int pivotIndex1 = std::rand() % (high - low + 1) + low;
            int pivotIndex2 = std::rand() % (high - low + 1) + low;
            int pivotIndex3 = std::rand() % (high - low + 1) + low;

            // Retrieve corresponding values
            long long pivot1 = data[pivotIndex1].second;
            long long pivot2 = data[pivotIndex2].second;
            long long pivot3 = data[pivotIndex3].second;

            // Find the median among the three random elements
            if ((pivot1 <= pivot2 && pivot2 <= pivot3) || (pivot3 <= pivot2 && pivot2 <= pivot1)) {
                pivot = pivot2;
                swap(data[pivotIndex2], data[high]);
            } else if ((pivot2 <= pivot1 && pivot1 <= pivot3) || (pivot3 <= pivot1 && pivot1 <= pivot2)) {
                pivot = pivot1;
                swap(data[pivotIndex1], data[high]);
            } else {
                pivot = pivot3;
                swap(data[pivotIndex3], data[high]);
            }
        }

    }

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) 
    {
        if (data[j].second < pivot) {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[high]);
    return (i + 1);

}

//inseriton sort
void insertionSort(std::vector<CityPair>& vec, int left, int right, bool verbose) {
    for (int i = left + 1; i <= right; i++) {
        CityPair key = vec[i];
        int j = i - 1;
        
        while (j >= left && vec[j].second > key.second) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }
    // Logs a message if verbose is 'true'.
    if(verbose){
        std::ofstream myfile;
        myfile.open("log.txt", std::ios_base::app);
        myfile<<"INSERTION SORT IS APPLIED"<<std::endl<<std::endl;
        myfile.close();
    }

}

//Hybrid quickSort function: with respect to the threshold value it is going to determine which sorting will be applied.
void quickSort(std::vector<CityPair>& data, int low, int high, int threshold,char firstArgument,bool verbose) {
    //Base condition in order to be able to leave from recursion
    if (low < high) {
        //If threshold value is entered as '1' naive quicksort (last element pivoting) will be applied.
        if(threshold==1){
            int pi = partition(data, low, high, 'l');
            // Logging sub-collections.
            if(verbose)
            {   
                std::ofstream myfile;
                myfile.open("log.txt", std::ios_base::app);
                myfile<<"Pivot: " << "("<<data[pi].first <<","<<  data[pi].second<<")"<<" Array: "<<std::endl;

                for (int i=low; i<=high; i++) {
                myfile<<data[i].first <<";"<<  data[i].second<<std::endl;
                }
                myfile<<std::endl;
                myfile.close();
            }
            //Sending partitions again into the hybrid quicksort function --recursion
            quickSort(data, low, pi - 1, threshold,'l',verbose);
            quickSort(data, pi + 1, high, threshold,'l',verbose);
        }
        //If the size of the sub-collection less than the threshold insertion sort will be applied.  
        else if (high - low + 1 <= threshold) {
            insertionSort(data, low, high,verbose);
        } 
        // If any of previous condition is no satisfied hybrid quicksort will be applied regularly.
        else {
            int pi = partition(data, low, high, firstArgument);
            // Logging sub-collections.
            if(verbose)
            {   
                std::ofstream myfile;
                myfile.open("log.txt", std::ios_base::app);
                myfile<<"Pivot: " << "("<<data[pi].first <<","<<  data[pi].second<<")"<<" Array: "<<std::endl;

                for (int i=low; i<=high; i++) {
                myfile<<data[i].first <<";"<<  data[i].second<<std::endl;
                }
                myfile<<std::endl;
                myfile.close();
            }
            //Sending partitions again into the hybrid quicksort function --recursion
            quickSort(data, low, pi - 1, threshold,firstArgument,verbose);
            quickSort(data, pi + 1, high, threshold,firstArgument,verbose);
        }
    }
}

//Output function is usedd to write sorted collection into a '.csv' file
void output(std::vector<CityPair>& data, std::string outputFileName){
    //deleting the same named file if it exists.
    remove(outputFileName.c_str());
    std::ofstream myfile;
    myfile.open(outputFileName, std::ios_base::app);
    for (const auto &city : data) {
    myfile<<city.first <<";"<<  city.second<<std::endl;
    }
    myfile<<std::endl;
    myfile.close();
}

//Moves the data in the csv file to a vector of pairs.
void csvToVector(std::string filename,std::vector<CityPair> &data){
    std::ifstream file(filename); // CSV file name

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row = split(line, ';'); // CSV data is semicolon-separated
        if (row.size() == 2) {
            std::string city = row[0];
            long long population = std::stoll(row[1]);
            CityPair cityData = std::make_pair(city, population);
            data.push_back(cityData);
        }
    }

    file.close();
}

int main(int argc, char* argv[]) {
    //Assigning arguments into variable by changing they types appropriately
    char firstArgument=*argv[2];
    int threshold= atoi(argv[3]);
    std::string filename= argv[1];
    std::string outfilename=argv[4];
    bool verbose=false;

    //deleting previous log file
    remove("log.txt");

    if (argc==6 && (*argv[5])=='v'){
         verbose=true;
    }
    
    std::vector<CityPair> data; // Vector of pairs to store CSV data
    csvToVector(filename, data);


    const auto start{std::chrono::steady_clock::now()}; // starting time
    quickSort(data, 0, data.size() - 1,threshold, firstArgument,verbose);
    const auto end{std::chrono::steady_clock::now()};  // ending time
       
    output(data, outfilename);
    
    const std::chrono::duration<long long,std::nano> elapsed_seconds{end - start};

    //console output
    std::cout << "Time taken by QuickSort with pivot strategy \'"<< firstArgument<<"\' and threshold "
    <<threshold<<": " <<elapsed_seconds.count() << " ns"<< std::endl;
    return 0;
}