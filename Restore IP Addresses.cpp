class Solution {
public:

    bool isValIP(string str){
        int n=str.length();int val;
        string s="";
        if(str[n-1]=='.')return 0;
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(ch!='.'){
                s.push_back(ch);
            }
            else{
                s="";
            }
            cout<<s<<endl;
            if(s.length()>3)return 0;
            if(s!=""){
            val=stoi(s);
            if(val==0 && s.length()>1 ||val<0 || val>255)return 0;
            if(val==0 && i<n-1  && str[i+1]!='.')return 0;
            }
            
        }
        return 1;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        int n=s.length();
        if(n<4 || n>12)return ans;

        for(int i=0;i<3;i++){
            for(int j=i+1;j<i+4;j++){
                for(int k=j+1;k<j+4;k++){
                    if(i>=n || j>=n ||k>=n)continue;
                    string str="";
                    int ind=0;
                    while(ind<n){
                        str.push_back(s[ind]);
                        if(ind==i || ind==j || ind==k){
                            str.push_back('.');
                        }                            
                        ind++;
                    }
                    cout<<str<<endl;
                    if(isValIP(str)){
                        ans.push_back(str);
                    }
                }
            }
        }
        return ans;
    }
};