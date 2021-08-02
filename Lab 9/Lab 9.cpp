#include <iostream>
#include <list>
#include <string>
#include <chrono>
using namespace std;


int sumAscii(string x) {
    int sum = 0;
    for (int i = 0; i < x.size(); i++) {
        sum += int(x[i]);
    }
    // cout << "Sum of '" << x << "': " << sum << endl;
    return sum;
}

class MachinePart {      
  private:             
    int SKU, QOH, LT;       
    string description, UOM;
    double price;
  public:
    MachinePart(int sku, string uom, int qoh, double prc, string desc)
    {
       this->SKU = sku;
       this->UOM = uom;
       this->QOH = qoh;
       this->price = prc;
       this->description = desc;
    }
    int getSKU() {
        return SKU;
    }
    string getPartInfo()
    { 
        return "SKU: " + to_string(SKU) + " Description: " + description;
    }
    double GetPrice()
    {
        return price;
    }
    bool inStock()
    {
        return (QOH > 0);
    }
    void displayPart()
    {
        cout << "SKU: " << SKU << ". Description: " << description << ". Price: "; printf("%0.2f", price);
        cout << ". Unit of measure: " << UOM << ". Quantity: " << QOH <<endl;
    }

    friend bool operator == (MachinePart &p1, MachinePart &p2)
    {
        return (p1.SKU == p2.SKU);
    };
    
};


class Hash {
    private:
        int BUCKET;
        list<MachinePart>* bucketList;
        int length;
    public:
        Hash (int V);
        void insertItem(MachinePart x);
        void deleteItem (MachinePart x);
        MachinePart* searchItem(MachinePart x);
        int hashFunction(string s) {
            return (sumAscii(s) % BUCKET);
        }
        void displayHashTable();
};


Hash::Hash(int numberOfBuckets){
    cout << "Generating hash table with " << numberOfBuckets << " bucket(s)..." << endl;
    this->BUCKET = numberOfBuckets;
    this->length = 0;
    bucketList = new list<MachinePart>[numberOfBuckets];
}


// Insert
// 1st check if already full -> If full, cout error, do not insert
// 2nd -> increase hashNumber until empty space (remember to wrap around the table)
// 3 -> insert

void Hash::insertItem(MachinePart p) {
    if (length == BUCKET) {
        cout << "Hash Table is full. Cannot insert" << endl;
        return;
    }

    int sku = p.getSKU();
    int hashNumber = hashFunction(p.getPartInfo());

    // Loop until find some place with size() == 0
    while (bucketList[hashNumber].size() > 0) {
        hashNumber++;
        // Wrap around the table
        hashNumber = hashNumber % BUCKET;
    }
    // Push the item and increase size
    bucketList[hashNumber].push_back(p);
    length++;

    
}

// Delete
// 1st - check Length - If empty cannot delete
// 2nd - Get hash Number from skuToDelete
// 3rd - Loop the bucketList to find any item with SKU == skuToDelete
// 4td - Delete and decrease size

void Hash::deleteItem(MachinePart toDelete) {
    if (length == 0) {
        cout << "Empty hash table! Cannot delete!" << endl;
        return;
    }
    int hashNumber = hashFunction(toDelete.getPartInfo());
    int i = hashNumber;
    // Loop over the bucket list to see if any bucket has skuToDelete
    while (i < BUCKET) {
        if (bucketList[i].size() > 0) {
            // Can safely get the item now since bucket is not empty
            MachinePart item = bucketList[i].front();
            if (item == toDelete) {
                // Perform delete action
                bucketList[i].clear();
                length--;
                cout << "Deleted item with SKU: " << item.getSKU() << " at index " << i << endl;
                break;
            }
        }
        // At the end of while loop, increase i and wrap around table
        i++;
        i = i & BUCKET;
        // If in the end, i get back to hashNumber
        // means that the entire bucketList has been traversed
        // thus no item was found
        if (i == hashNumber) {
            cout << "Cannot find SKU: " << toDelete.getSKU() << ". Cannot delete!" << endl;
            break;
        }
    }
    return;
}

MachinePart* Hash::searchItem(MachinePart toSearch) {
    if (length == 0) {
        cout << "Empty hash table! Cannot find!" << endl;
        return nullptr;
    }
    int hashNumber = hashFunction(toSearch.getPartInfo());
    int i = hashNumber;
    // Loop over the bucket list to see if any bucket has skuToDelete
    while (i < BUCKET) {
        if (bucketList[i].size() > 0) {
            // Can safely get the item now since bucket is not empty
            MachinePart item = bucketList[i].front();
            if (item == toSearch) {
                return &(bucketList[i].front());
            }
        }
        
        // At the end of while loop, increase i and wrap around table
        i++;
        i = i & BUCKET;
        // If in the end, i get back to hashNumber
        // means that the entire bucketList has been traversed
        // thus no item was found
        if (i == hashNumber) {
            cout << "Cannot find item with SKU: " << toSearch.getSKU() << endl;
            return nullptr;
        }
    }
    return 0;
}


void Hash::displayHashTable(){
   for (int i = 0; i < BUCKET; i++) {
        cout << "Index " << i << ": ";
        if (bucketList[i].size() == 0) {
            cout << "Empty bucket!" << endl;
            continue;
        }
        // Get the MachinePart since bucket is not empty
        MachinePart item = bucketList[i].front();
        // Print the actual MachinePart
        item.displayPart();
    }
}

int main () {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    int i = 1;
    int n;

    MachinePart p1 = MachinePart(1, "pound", 3, 4.5,"Main part");
    
    cout << "Enter the number of item(s): " <<  endl;
    cin >> n;

    Hash hashTable = Hash(n);
    
    // Test insert
    cout << "-----INSERT-----\n";
    
    auto t1 = high_resolution_clock::now();
    
    hashTable.insertItem(p1);
    while (i < n){
      hashTable.insertItem(MachinePart(rand(), "foot", 0 + (rand() % ( 1 - 0 + 1 ) ), rand(), "Spare part"));
      i++;
    }   
    hashTable.displayHashTable();
    
    auto t2 = high_resolution_clock::now();

     cout << "\n" << endl; 
    cout<<"The insertion time of "<< n << " item(s) is: ";
          duration<double, std::milli> ms_double = t2 - t1;
          std::cout << ms_double.count() << "ms";
          cout << "\n" << endl;
    
    // Test delete element
    cout << "-----DELETE-----\n";
    hashTable.deleteItem(p1);
    hashTable.displayHashTable();
  
    // Test search
    cout << "-----SEARCH-----\n";
    MachinePart* p1_found = hashTable.searchItem(p1);
    if (p1_found) {
        cout<< "Found ";
        p1_found->displayPart();
    }
}
