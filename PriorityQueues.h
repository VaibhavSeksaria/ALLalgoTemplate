#include<vector>
/// @brief 
class PriorityQueue{
    std::vector<int>pq;
    public:
    bool isempty(){
        return pq.size()==0;
    }
    // return the size of priorityqueue -no of elemebts present
    int getsize(){
        return pq.size();
    }
    int getmin(){
        if(isempty()){
            return 0;
        }
        return pq[0];
    }
    void insert(int data){
        pq.push_back(data);
        int childindex=pq.size()-1;
        while(childindex>0){
            int parentindex=(childindex-1)/2;
            if(pq[childindex]<pq[parentindex]){
                int temp=pq[childindex];
                pq[childindex]=pq[parentindex];
                pq[parentindex]=temp;
            }
            else{
                break;
            }
            childindex=parentindex;
        }
    }
    int remove(){
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parentindex=0;
        int leftchildindex=2*parentindex+1;
        int rightchildindex=2*parentindex+2;
        while(leftchildindex<pq.size()){
            int minindex=parentindex;
             if(pq[leftchildindex]<pq[minindex]){
                minindex=leftchildindex;
            }
            if(rightchildindex<pq.size() && pq[rightchildindex]<pq[minindex]){
                minindex=rightchildindex;
            }
            if(minindex==parentindex){
                break;
            }
                int temp=pq[parentindex];
                pq[parentindex]=pq[minindex];
                pq[minindex]=temp;
                parentindex=minindex;
                leftchildindex=2*parentindex+1;
                rightchildindex=2*parentindex+2;
        }
        return ans;
    }

};