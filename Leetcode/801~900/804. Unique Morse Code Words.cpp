class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		map<string, string> dic;
		string s;
		int i, j, size = words.size();
		char *lut[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
		".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
		
		for(i = 0;i < size;i++){
			int strSize = words[i].size();
			s = "";
			for(j = 0;j < strSize;j++){
				s += lut[words[i][j] - 'a']; 
			}
			dic[s] = 1;
		}
		
		return dic.size();
	}
};