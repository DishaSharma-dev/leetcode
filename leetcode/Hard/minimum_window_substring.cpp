class Solution {
public:
    string minWindow(string s, string t) {
         string ans="";

        unordered_map<char,int> map2;

        for(auto &a: t)

            map2[a]++;

        int mct=0;

        int dmct=t.length();

        unordered_map<char,int> map1;

       int i=0,j=0;
        while(true)

        {

            bool f1=false;

            bool f2=false;
         

            while(i<s.length() and mct<dmct)

            {
                map1[s[i]]++;

                if(map1[s[i]]<=map2[s[i]])

                    mct++;

                f1=true;
                i++;

            }
            while(j<i and mct==dmct)

            {

                string pans=s.substr(j,i-j);

                if(ans.length()==0 or pans.length()<ans.length())

                    ans=pans;

                

                if(map1[s[j]]==1)

                    map1.erase(s[j]);

                else

                    map1[s[j]]--;

                if(map1[s[j]]<map2[s[j]])

                    mct--;

                f2=true;
                j++;

            }

            if(f1==false and f2==false)

                break;

        }

        return ans;
    }
};