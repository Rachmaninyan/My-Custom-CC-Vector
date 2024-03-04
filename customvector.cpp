#include <iostream>

using namespace std;


class myvect{
    private:
        int capacity = 8;
        int *arr = new int[capacity];
        int siz = 0;
        
    public:
        //myvect(): *arr(new int[8]), siz(0), capacity(8){}
        int size();
        void assign(int,int);
        void insert(int,int);
        void push_back(int);
        void pop_back();
        void erase(int);
        int at(int);
        void delvec();
        
    ~myvect(){delvec();}
};


int myvect::size(){ //done
    return siz;
}


void myvect::assign(int index, int value){ //done
    arr[index] = value;
}


void myvect::insert(int index, int value){ //done
    int next = arr[index];
    //cout<<arr[index]<<endl; 0
    arr[index] = value;
    int next2 = arr[index+1];
    arr[index+1] = next;
    //cout<<arr[index+1]<<endl; 
    siz++;
    if (siz == capacity){
        int *arra = new int[capacity*2];
        for (int x = 0; x < siz; x++){
            arra[x] = arr[x];
        }
        delete[] arr;
        arr = arra;
    }
    for (int x = index+1; x < siz; x++){
        arr[x] = next;
        next = next2;
        next2 = arr[x+1];
        if (x == siz){
            break;
        }
    }
}


void myvect::push_back(int value){ //done
    if (siz == capacity){
        int *arra = new int[capacity*2];
        for (int x = 0; x < siz; x++){
            arra[x] = arr[x];
        }
        delete[] arr;
        arr = arra;
    }
    arr[siz] = value;
    siz++;

}


void myvect::pop_back(){ //done
    siz--;
}


void myvect::erase(int index){ //done
    for (int x = index; x < siz; x++){
        arr[x] = arr[x+1];
    }
    siz--;
}


int myvect::at(int index){ //done
    if (index>=siz){
        cout<<"Accessing value out of bounds"<<endl;
        return 0;
    }
    return arr[index];
}


void myvect::delvec(){ //done
    delete[] arr;
}

ostream& operator<< (ostream &o, myvect &p){ //done
    for (int x = 0; x < p.size(); x++){
        o<<p.at(x)<<" ";
    }
    return o;
}

int main(){
    myvect x;
    for (int y = 0; y <= 12; y++){
        x.push_back(y);
    }
    cout<<x<<endl;
    x.insert(0,69);
    cout<<x<<endl;
    return 0;
} 
