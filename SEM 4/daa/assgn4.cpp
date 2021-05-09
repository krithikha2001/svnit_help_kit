#include <iostream> 
using namespace std; 
  
struct  Building{ 
    int l; 
    int h; 
    int r; 
}; 
  
class Strip { 
    int l; 
    int h; 
  
public: 
    Strip(int l = 0, int h = 0) 	//constructor function
    { 
        left = l; 
        ht = h; 
    } 
    friend class SkyLine; 
}; 
  
class SkyLine { 
    Strip* res; 	
    int c;	//denoting capacity 
    int n; 
  
public: 
    //~SkyLine() { delete[] arr; } 		//to free up memory
    int count() { return n; } 
  

    SkyLine* Merge(SkyLine* other); 
  
    // Constructor 
    SkyLine(int cap) 
    { 
        c = cap; 
        res = new Strip[cap]; 
        n = 0; 
    } 
  
    void add(Strip* s) 
    { 
        if (n > 0 && res[n - 1].h == s->h) 
            return; 													//same height as prev so ignore
        if (n > 0 && res[n - 1].l == s->l) { 
            res[n - 1].h = max(res[n - 1].h, s->h); 
            return; 
        } 
  
        res[n] = s; 
        n++; 
    } 
  
    void print() 
    { 
        for (int i = 0; i < n; i++) { 
            cout << " (" << res[i].l << ", "
                 << res[i].h << ")  "; 
        } 
    } 
}; 
  
SkyLine* find(Building res[], int left, int right) 
{ 
    if (left == right) { 
        SkyLine* sky = new SkyLine(2); 
        sky->append( 
            new Strip( 
                res[l].l, res[l].h)); 
        sky->append( 
            new Strip( 
                res[l].r, 0)); 
        return res; 
    } 
  
    int mid = (left + right) / 2; 
  
    SkyLine* sl = findSkyline( arr, left, mid); 
    SkyLine* sr = findSkyline(  arr, mid + 1, right); 
    SkyLine* res = sl->Merge(sr); 
  
   // delete sl; 
    //delete sr; 
  
    return sky; 
} 
  
// Similar to merge() in MergeSort 
// This function merges another skyline 
// 'other' to the skyline for which it is called. 
// The function returns pointer to the 
// resultant skyline 
SkyLine* SkyLine::Merge(SkyLine* other) 
{ 
     SkyLine* res = new SkyLine( this->n + other->n); 
  
    // To store current heights of two skylines 
    int h1 = 0, h2 = 0; 
  
    // Indexes of strips in two skylines 
    int i = 0, j = 0; 
    while (i < this->n && j < other->n) { 
       
        if (this->arr[i].left < other->arr[j].left) { 
            int x1 = this->arr[i].left; 
            h1 = this->arr[i].ht; 
  
            // Choose height as max of two heights 
            int maxh = max(h1, h2); 
  
            res->append(new Strip(x1, maxh)); 
            i++; 
        } 
        else { 
            int x2 = other->arr[j].left; 
            h2 = other->arr[j].ht; 
            int maxh = max(h1, h2); 
            res->append(new Strip(x2, maxh)); 
            j++; 
        } 
    } 
  
    // If there are strips left in this 
    // skyline or other skyline 
    while (i < this->n) { 
        res->append(&arr[i]); 
        i++; 
    } 
    while (j < other->n) { 
        res->append(&other->arr[j]); 
        j++; 
    } 
    return res; 
} 
  
// Driver Function 
int main() 
{ 
    Building arr[] = { 
        { 1, 11, 5 }, { 2, 6, 7 }, { 3, 13, 9 }, { 12, 7, 16 }, { 14, 3, 25 }, { 19, 18, 22 }, { 23, 13, 29 }, { 24, 4, 28 } 
    }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Find skyline for given buildings 
    // and print the skyline 
    SkyLine* ptr = findSkyline(arr, 0, n - 1); 
    cout << " Skyline for given buildings is \n"; 
    ptr->print(); 
    return 0; 
} 
