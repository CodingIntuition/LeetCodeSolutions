class Solution {
public:
    
    int strStr(string haystack, string needle) {        
        int haystackSize = haystack.size(),  needleSize = needle.size();

        for (int i = 0 ; i<haystackSize ; ) {
            int j = 0;
           
            while (j < needleSize && haystack[i] == needle[j] ){
                i++;
                j++;
            }
            if (j == 0) i++;
            else if (j == needleSize ) return i - needleSize;
            else i = (i - j +1);
        }
        return -1;
        
    }
};