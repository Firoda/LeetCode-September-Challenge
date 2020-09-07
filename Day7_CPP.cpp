class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;

        int i=0;
        while(i<str.length())
        {
            while(i<str.length() and !isalpha(str[i]))
                i++;

            string currWord="";
            while(i<str.length() and isalpha(str[i]))
                currWord+=str[i++];
            if(currWord.length() > 0)
                words.push_back(currWord);
        }
        if(pattern.length() != words.size())
            return false;


        unordered_map<char, string> charToS;
        unordered_map<string, char> strToC;

        for(int i=0;i<pattern.length(); i++)
        {
            if(charToS.find(pattern[i]) == charToS.end())
            {
                if(strToC.find(words[i]) != strToC.end())   return false;

                //Mapping
                charToS[pattern[i]] = words[i];
                strToC[words[i]] = pattern[i];
            }
            else
            {
                if(charToS[pattern[i]] != words[i])
                    return false;
            }
        }
        return true;

    }
};
