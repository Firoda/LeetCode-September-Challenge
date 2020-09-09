class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1Num;
        vector<int> ver2Num;

       getNumbers(version1, ver1Num);
       getNumbers(version2, ver2Num);

        int minNum = min(ver1Num.size(), ver2Num.size());
        int i=0;
        for(i;i<minNum;i++)
        {
            if(ver1Num[i] > ver2Num[i])
                return 1;
            else if(ver1Num[i] < ver2Num[i])
                return -1;
        }
        if(i<ver1Num.size())
        {
            for(i; i<ver1Num.size(); i++)
            {
                if(ver1Num[i] != 0)
                    return 1;
            }
        }

        if(i<ver2Num.size())
        {
            for(i; i<ver2Num.size(); i++)
            {
                if(ver2Num[i] != 0)
                    return -1;
            }
        }


        return 0;
    }

      void getNumbers(string version, vector<int>& verNum)
    {
        int i=0;
        while(i<version.length())
        {
            int num = 0;
            while(i<version.length() and version[i]!='.')
            {
                num = num*10 + (version[i] - '0');
                i++;
            }
            // cout << num << " " << version << endl;
            verNum.push_back(num);
            i++;
        }
        //cout << version.length() << endl;
    }
};
