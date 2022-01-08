class Solution {
public:
    string capitalizeTitle(string title) {
        transform(title.begin(), title.end(), title.begin(), ::tolower);
        int count = 0;
        int start = 0;
        int check = 0;
        while(check <= title.length()){
            if(check == title.length()){
                if(count > 2){
                title[start] = title[start] - 32;
                check += 1;
                }
                else{
                    check++;
                }
            }
            else if(title[check] != ' '){
                count++;
                check++;
            }
            else if(count > 2){
                title[start] = title[start] - 32;
                start = check + 1;
                count = 0;
                check++;
            }
            else{
               start = check + 1;
               count = 0; 
               check++;;
            }
        }
        return title;
    }
};