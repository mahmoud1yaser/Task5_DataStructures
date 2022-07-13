#include<iostream>
#include"my_pq.h"
#include <vector>
using namespace std;

int main(int argc, char **argv)
{

    int numb_of_operations;
    int heap_size;
    int elmnt;
    int index;
    vector<int> vec;
    cin>>heap_size>>numb_of_operations;
    for(int i=0;i<heap_size;i++)
    {
        cin>>elmnt;
        vec.push_back(elmnt);
    }
    My_PQ *pq= new My_PQ(vec);



    int operation;
    for(int j=0;j<numb_of_operations;j++)
    {
        //int operation;
        cin>>operation;
        switch(operation)
        {
            case 1:
                cin>>index;
                pq->insert(index);
                break;
            case 2:
                int new_priority;
                cin>>index>>new_priority;
                pq->change_priority(index, new_priority);
                break;
            case 3:
                int index;
                cin>>index;
                pq->remove(index);
                break;
            case 4:
                pq->extract_max();
                break;
            case 5:
                cout<<pq->peek()<<" ";
                cout<<endl;
                break;
            case 6:

                for(int i=0;i<=pq->size_()+4;i++)
                {
                    cout<<pq->peek()<<" ";
                    pq->extract_max();
                }

                break;
            case 7:
                cout<<pq->size_()<<" ";
                cout<<endl;
                break;

            default:
                break;
        }
    }
    return 0;
}