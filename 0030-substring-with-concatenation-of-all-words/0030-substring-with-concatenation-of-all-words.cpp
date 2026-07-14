class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int n = s.size();
        int numWords = words.size();
        if (numWords == 0) return result;
        int wordLen = words[0].size();
        int totalLen = numWords * wordLen;
        if (n < totalLen) return result;
        
        unordered_map<string, int> wordCount;
        for (const string& w : words) wordCount[w]++;
        
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int count = 0;
            unordered_map<string, int> windowCount;
            
            for (int right = offset; right + wordLen <= n; right += wordLen) {
                string word = s.substr(right, wordLen);
                
                if (wordCount.find(word) != wordCount.end()) {
                    windowCount[word]++;
                    count++;
                    
                    while (windowCount[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowCount[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                    
                    if (count == numWords) {
                        result.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        windowCount[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    windowCount.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        
        return result;
    }
};