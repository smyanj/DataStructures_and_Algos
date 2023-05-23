#include <iostream>
#include <limits>
using namespace std;
//Quick note: In the project description it said maiden household income which is why my variables say maiden instead of median 
//This is the basic structure of what we want each node to look like with our city name, population, and income
//It also will contain the details to the next node
struct City{
    string cityN; int population; int maidenHouseIncome; City* next;
};
//This is initializing the head and tail to null, but we don't do 'NULL' instead nullptr to refer the zero address
City* head = nullptr;
City* tail = nullptr;
void addToTail(){
    City* tail_City = new City;
    //the tail should be pointing at null
    tail_City->next = nullptr;
    cout<<"City name: ";
    //cin >> tail_City->cityN;
    //Can't use standard cin to account for spaces in between characters so use cin.ignore followed by getline
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, tail_City->cityN);

    cout << "City Population: ";
    cin >> tail_City->population;

    cout << "City Median income: ";
    cin >> tail_City->maidenHouseIncome;

    if(head == nullptr){
        head = tail_City;
        tail = tail_City;
    }else{
        tail->next = tail_City;
        tail = tail_City;
    }
}
void addToHead(){
    City* front = new City;
    front->next = nullptr;

    cout<<"City name: ";
    //cin >> front->cityN;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, front->cityN);

    cout << "City Population: ";
    cin >> front->population;

    cout << "City Median income: ";
    cin >> front->maidenHouseIncome;
    if(head == nullptr){
        head = front;
        tail = front;
    }else{
        front->next = head;
        head = front;
    }

}
void largestPop(){
    City* curr = head;
    if(head == nullptr){
        cout << "No city records.\n";
        return;
    }
    City* largest_population = curr;
    while(curr != nullptr){
        if(curr->population > largest_population->population){
            largest_population = curr;
        }
        curr = curr->next;
    }
    cout << "City with largest population: \n";
    cout << "City Name: " << largest_population->cityN << endl;
    cout << "Population: " << largest_population->population << endl;
    cout << "Median household income: " << largest_population->maidenHouseIncome << endl;
}
void displayAllRecords(){
    if(head == nullptr){
        cout << "No city records.\n";
        return;
    }
    cout << "All City Records\n";
    City* curr = head;

    while(curr != nullptr){
        cout << "City Name: " << curr->cityN << endl;
        cout << "Population: " << curr->population << endl;
        cout << "Median household income: " << curr->maidenHouseIncome << endl;
        cout << "------------------------\n";
        curr = curr->next;
    }

}

int main(){
    int selectOp;
    while(true){
        cout << "\nOptions:\n";
        cout << "1. Add city record at the tail\n";
        cout << "2. Add city record to the head\n";
        cout << "3. Display the city with the largest population\n";
        cout << "4. Display all the city records\n";
        cout << "5. Exit\n";
        cin >> selectOp;
    switch(selectOp){
        case 1:
            addToTail();
            break;
        case 2:
            addToHead();
            break;
        case 3:
            largestPop();
            break;
        case 4:
            displayAllRecords();
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}
