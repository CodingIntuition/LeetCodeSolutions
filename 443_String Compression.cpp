class Solution {
public:
    // O(N) time |  O(1) space
    int compress(vector<char>& chars) { //1000
        int newIndex =  0; 
        int currentCount = 1, size = chars.size();
        for (int i = 1 ; i<size; i++ ) { 
            if (chars[i] == chars[i-1]) 
            {
                currentCount++;
            }
            else {
                if (currentCount > 1) {
                    string currentCountStr =  to_string(currentCount); //12 
                    chars[newIndex] = chars[i-1];
                    newIndex++;
                    for (int j = 0 ; j<currentCountStr.length(); j++, newIndex++ )
                    {
                        chars[newIndex]  =  currentCountStr[j];
                    }
                }
                else {
                    chars[newIndex] = chars[i-1];
                    newIndex++;
                }
                currentCount=1;
            }
        }
        if (currentCount >  1 ) {
            string currentCountStr =  to_string(currentCount);
            chars[newIndex] = chars[size-1];
            newIndex++;
            for (int j = 0 ; j<currentCountStr.length(); j++, newIndex++ )
            {
                chars[newIndex]  =  currentCountStr[j];
            }
        }
        else {
            chars[newIndex] = chars[size-1];
            newIndex++;
        }
        return newIndex;
    }
};