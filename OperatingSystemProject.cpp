
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <unordered_set>
#include <unordered_map>

using namespace std;
void FIFO( int PAGES,int FRAMES)
{
    int  PageFaults = 0, similar;
    
    int* processes = new int(PAGES);
    cout << " Please enter the processes  " << endl;
    for (int i = 0; i < PAGES; i++)
    {
        cin >> processes[i];
    }
  

    int* temp = new int(FRAMES);
    for (int i = 0; i < FRAMES; i++)
    {
        temp[i] = -1;
    }
    for (int i = 0; i < PAGES; i++)
    {
        similar = 0;
        for (int j = 0; j < FRAMES; j++)
        {
            if (processes[i] == temp[j])
            {
                similar++;
                PageFaults--;
            }
        }
        PageFaults++;
        if ((PageFaults <= FRAMES) && (similar == 0))
        {
            temp[i] = processes[i];
        }
        else if (similar == 0)
        {
            temp[(PageFaults - 1) % FRAMES] = processes[i];
        }
        cout << endl;
        for (int j = 0; j < FRAMES; j++)
        {
            cout <<  temp[j];
        }
    }
    cout << "\n total page faults " << PageFaults << endl;
    
}
void LRU(int PAGES, int FRAMES)
{
    int  PageFaults = 0, similar;

    int* processes = new int(PAGES);
    cout << " Please enter the processes  " << endl;
    for (int i = 0; i < PAGES; i++)
    {
        cin >> processes[i];
    }
   
    // if a page is present in set or not
    unordered_set<int> setProcess;

    // To store least recently used indexes
    // of processes.
    unordered_map<int, int> indexes;

    // Start from initial page
    int Faults = 0;
    
    for (int i = 0; i < PAGES; i++)
    {
        // Check if the set can hold more processes
        if (setProcess.size() < FRAMES)
        {
            // Insert j into set if not present
            // already which represents page fault
            if (setProcess.find(processes[i]) == setProcess.end())
            {
                setProcess.insert(processes[i]);

                // increment page fault
                Faults++;
            }

            // Store the recently used index of
            // each page
            indexes[processes[i]] = i;
        }

        // If the set is full then need to perform lru
        // i.e. remove the least recently used page
        // and insert the current page
        cout << Faults << endl;
        else
        {
            // Check if current page is not already
            // present in the set
            if (setProcess.find(processes[i]) == setProcess.end())
            {
                // Find the least recently used processes
                // that is present in the set
                int lru = INT_MAX, val;

                for (auto j = setProcess.begin(); j != setProcess.end(); j++)
                {
                    if (indexes[*j] < lru)
                    {
                        lru = indexes[*j];

                        val = *j;
                    }
                }

                // Remove the indexes page
                setProcess.erase(val);

                // insert the current page
                setProcess.insert(processes[i]);

                // Increment page faults
                Faults++;
                cout << Faults << endl;
            }

            // Update the current page index
            indexes[processes[i]] = i;
        }
    }

    cout << endl << Faults << endl;

}
//void LRU(int pages[],  int Size)
//{
//    int* processes = new int(Size);
//    for (int i = 0; i < Size; i++)
//    {
//        cin >> processes[i];
//    }
//    int n;
//
//    //bn3mel set msh ordered 4al4an el pages 
//    unordered_set<int> process;
//
//    // el map 3al4an el LRU  indexes bt3thom 
//    unordered_map<int, int> indexes;
//
//    // Start from initial page
//    int Faults = 0;
//    for (int i = 0; i < n; i++)
//    {
//        // Check if the set can hold more pages
//        if (process.size() < Size)
//        {
//            // Insert it into set if not present
//            // already which represents page fault
//            if (process.find(pages[i]) == process.end())
//            {
//                process.insert(pages[i]);
//
//                // increment page fault
//                Faults++;
//            }
//
//            // Store the recently used index of
//            // each page
//            indexes[pages[i]] = i;
//        }
//
//        // If the set is full then need to perform lru
//        // i.e. remove the least recently used page
//        // and insert the current page
//        else
//        {
//            // Check if current page is not already
//            // present in the set
//            if (process.find(pages[i]) == process.end())
//            {
//                // Find the least recently used pages
//                // that is present in the set
//                int lru = INT_MAX, val;
//                for (auto it = process.begin(); it != process.end(); it++)
//                {
//                    if (indexes[*it] < lru)
//                    {
//                        lru = indexes[*it];
//                        val = *it;
//                    }
//                }
//
//                // Remove the indexes page
//                process.erase(val);
//
//                // insert the current page
//                process.insert(pages[i]);
//
//                // Increment page faults
//                Faults++;
//            }
//
//            // Update the current page index
//            indexes[pages[i]] = i;
//        }
//    }
//
//    cout << Faults << endl;
//}
int main()
{
    int pagees, Framees,WhichMethod ;
    cout << " Choose the method you want to apply FIFO:1 LRU:2 Optimal:3 " << endl;
    cin >> WhichMethod;
    system("CLS");
    if (WhichMethod == 1)
    {
        cout << "Please insert number of pages " << endl; ;
        cin >> pagees;
        cout << "How many frames do you need?" << endl;
        cin >> Framees;
        FIFO(pagees, Framees);
    }
    else if (WhichMethod == 2) 
    {
        
        cout << "how many page do you want ?" << endl;
        cin >> pagees;
        cout << "How many frames do you need?" << endl;
        cin >> Framees;
        LRU(pagees, Framees);
    }
    else
    {

    }
     return 0;
}