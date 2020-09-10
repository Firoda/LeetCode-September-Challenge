class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int cow = 0;
        int len = secret.length();
        for(int i=0;i<len; i++)
        {
            if(secret[i] == guess[i])
            {
                bull++;
                secret[i] = guess[i] = '.';
            }
        }

        unordered_map<char, int> umap;
        for(int i=0;i<len;i++)
        {
            if(secret[i]!='.')
                umap[secret[i]]++;
        }

        for(int i=0;i<len;i++)
        {
            if(guess[i]!='.')
            {
                if(umap.find(guess[i]) != umap.end() and umap[guess[i]] != 0)
                {
                    cow++;
                    umap[guess[i]]--;
                }
            }
        }

        string res = "";
        res = to_string(bull)+"A"+to_string(cow)+"B";
        return res;

    }
};
