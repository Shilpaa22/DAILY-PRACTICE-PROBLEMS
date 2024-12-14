class MapSum {
public:
map<string,int> mp;
class trie{
    
    public:
    trie * a[27];
    int end;
    void init(){
        for(int i=0;i<26;i++) a[i]=NULL;
        end =0;
    }
};
trie *tr;
    MapSum() {
        tr=new trie();
        tr->init();
    }
    
    void insert(string words, int val) {
        trie *temp=tr;
        int val1=val;
        val=val-mp[words];
        mp[words]=val1;
         for(int j=0;j<words.size();j++){
                    if(temp->a[words[j]-'a']!=NULL){
                        temp=temp->a[words[j]-'a'];
                        (temp->end)+=val;
                      
                    }
                    else{
                        trie *temp1=new trie();
                        temp1->init();
                        temp->a[words[j]-'a']=temp1;
                         temp=temp->a[words[j]-'a'];
                        (temp->end)+=val;

                    }
           }
    }
    
    int sum(string words) {
         int c=0;
             trie *temp=tr;
           for(int j=0;j<words.size();j++){
                  
                        temp=temp->a[words[j]-'a'];
                       if(temp==NULL) break;
                       
                      
                    
           }
           if(temp==NULL) return 0;
           c+= (temp->end);
           return c;
        

    }
};

