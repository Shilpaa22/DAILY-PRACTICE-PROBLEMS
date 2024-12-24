class SnapshotArray {
public:
vector<vector<pair<int,int>>> v;
int id;
    SnapshotArray(int length) {
        v=vector<vector<pair<int,int>>>(length,vector<pair<int,int>>(1,{0,0}));
        id=0;

    }
    void set(int index, int val) {
        if( v[index][v[index].size()-1].first<id)
        v[index].push_back({id,val});
        else{
            v[index][v[index].size()-1].second=val;
        }
    }
    
    int snap() {
        int turn=id;
        id++;
        return turn;
    }
    
    int get(int index, int snap_id) {
        int low=0,high=v[index].size()-1;
        if(v[index][v[index].size()-1].first<=snap_id)return v[index][v[index].size()-1].second;
        while(low<=high){
            int mid=(low+high)/2;
            if(v[index][mid].first<=snap_id && v[index][mid+1].first>snap_id)return v[index][mid].second;
            if(v[index][mid].first<snap_id)low=mid+1;
            else
            high=mid-1;
        }
        return -1;
    }
};

